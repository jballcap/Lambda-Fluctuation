#include <iostream>
#include <fstream>
#include <iomanip>
#include "TChain.h"
#include "TString.h"
#include "TTree.h"
#include "TH1.h"
#include "TH2.h"
#include "TH3.h"
#include "TProfile.h"
#include "TProfile2D.h"
#include "TProfile3D.h"
#include "TMath.h"
#include "TFile.h"
#include "TObjArray.h"
#include "TList.h"
#include "TString.h"
#include "TVector3.h"
#include "TLorentzVector.h"
#include <TObjArray.h>
#include <TStopwatch.h>
#include <TRandom3.h>
#include <TRandom.h>
#include <map>

#include "Classes/ITrack.h"
#include "Classes/IEvent.h"
#include "Classes/ILambda.h"
#include "Classes/LambdaEfficiency.h"
#include "Classes/MomentFunctions.h"
#include "Classes/CumulantProfileContainer.h"
#include "Classes/FlucContainer.h"
#include "Classes/PileUpCorrection.h"
#include "Classes/analysisUtil.h"

using namespace std;

#ifndef _CINT_

void AnalyzeFemtoDst(TString OutputName, int MaxNumberFemtoDst);

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		std::cerr << "Not enough arguments\n";
		return 1;
	}
	TString outname(argv[1]), int_str(argv[2]);
	int maxdsts = int_str.Atoi();

	AnalyzeFemtoDst(outname, maxdsts);
	return 0;
} // int main
#endif

void AnalyzeFemtoDst(TString OutputName, int MaxNumberFemtoDst)
{
	//------------------------------------------- Check and use the arguments -------------------------------------------//
	OutputName.Prepend("/home/jonathan/Documents/LambdaFluctuationAnalyses/3GeV/FluctuationLambdaEbE_FxtMult3/Output/");
	OutputName.Append(".histograms.root");

	// ifstream inputStream("/media/jonathan/Extreme/DataFxtMult3_Loose_Cuts_DCA_Cut/Loose_Cuts_DCA_Cut.list"); //Supposed to be same as Run7 but using Yu List Jan 2023
	// ifstream inputStream("/media/jonathan/Extreme/DataFxtMult3_Loose_Cuts_DCA_Cut_Good_Runs/Good_Runs.list");
	//ifstream inputStream("/media/jonathan/Extreme/DataFxtMult3_Loose_Cuts_DCA_Cut/DataFxtMult3_Loose_Cut/DCA_Good_Tracks.list");
	//ifstream inputStream("/media/jonathan/Extreme/DataFxtMult3_Cuts_Yield/Cuts_Yield.list");
	//ifstream inputStream("/media/jonathan/Extreme/DataFxtMult3_Loose_Cut_Good_Tracks_May_23/DataFxtMult3_Loose_Cut/Good_Tracks.list");
		ifstream inputStream("/media/jonathan/Extreme/DataFxtMult3_Cut_Yield/Cut_Yield.list");



	if (!inputStream.good())
	{
		std::cerr << "Error opening input file list. Aborting.\n";
		exit(1);
	}

	unique_ptr<TChain> theChain(new TChain("LambdaTree", "LambdaChain"));
	char fileName[500];
	if (MaxNumberFemtoDst == 0)
		MaxNumberFemtoDst = 999999999;
	for (int i = 0; i < MaxNumberFemtoDst; i++)
	{
		inputStream.getline(fileName, 500);
		if (!inputStream.good())
			continue;
		// cout << "Adding file # " << i << ", "<< fileName << " to the Chain\n";
		theChain->AddFile(fileName);
	}

	//--------------------------------------------- Initialize some consts ----------------------------------------------//
	const double MinPtLambda = 0.5, MaxPtLambda = 2.0;
	// const double MinPtLambda = 0.0, MaxPtLambda = 3.0;
	const double MinPtProton = 0.4, MinPtPion = 0.15;
	// const double MinPtLambda = 0.2, MaxPtLambda = 5.;
	// const double MinPtProton = 0.5, MinPtPion = 0.3;
	// const double MinComRapidityLambda  = -1., MaxComRapidityLambda = 1.;
	const double MinComRapidityLambda = 0.0, MaxComRapidityLambda = 0.5; // change in rapidity
	// const double MinComRapidityLambda  = -1.0, MaxComRapidityLambda = 1.0; //rapidity for Embedded
	// const double LambdaMassCut = 0.0005; // Half width, in GeV as In Joey's Code
	const double LambdaMassCut = 0.003; // Including 2sigma
	// const double LambdaMassCut = 0.006;  //In order to select approx 1.11<M<1.12
	const double LambdaPdgMass = 1.11568;
	const double DecayParameter = 3.395; // 8/(pi*alpha)
	const double pi = TMath::Pi();
	const double ProtonPdgMass = 0.938272;
	const double PionPdgMass = 0.139570;
	const double MaxLambdaDcaToPv = 1.0;
	TRandom3 *rand = new TRandom3();

	CumulantProfileContainer *cpc = new CumulantProfileContainer();

	//-------------------------------------------- Initialize the histograms --------------------------------------------//

	TFile *HistogramOutput = new TFile(OutputName.Data(), "RECREATE"); // guideline: don't pass smart pointers as function arguments (?)

	int NLambdas;
	int Centrality;
	TTree *T = new TTree("T", "LambdaTree");
	T->Branch("NLambdas", &NLambdas, "NLambdas/I");
	T->Branch("Centrality", &Centrality, "Centrality/I");

	unique_ptr<TH1F> h1f_InvMass_NumLambdas_[1];
	unique_ptr<TH1F> h1f_Phi_NumLambdas_OnMassPeak[1];
	unique_ptr<TH1F> h1f_ComEtaDaughter_NumLambdas_[2][2];
	unique_ptr<TH1F> h1f_SumDaughterMomentumInLambdaFrame_NumLambdas_[1];
	unique_ptr<TH1F> h1f_EfficiencyvsMomentum[1]; // Histogram of Efficiency vs Momentum for a particular rapidity window
	unique_ptr<TH2F> h2f_ComRapidity_Pt_NumLambdas_OnMassPeak[1];
	unique_ptr<TH2F> h2f_Efficiency_Lambdas[1]; // Efficiency Histogram
	unique_ptr<TH2F> h2f_ComEta_Pt_NumLambdas_OnMassPeak[1];
	unique_ptr<TH1F> h1f_EbE_Lambda_[1]; // Including a histogram that counts how many times I found certain number of lambdas
	// unique_ptr<TH1F> h1f_Dist_Cent[8];  //use 7 when using Heppel centrality
	// Vectors for Cumulant profiles

	vector<TGraphErrors *> gr;	// Graph for Q1 - Q4
	vector<TGraphErrors *> gr1; // Graph for Q1 - Q4
	vector<TGraphErrors *> gr2; // Graph for Q1 - Q4   Seems that the gr1 and gr2 are related with bootstrap, no need now.
	vector<TProfile *> prof_vec;
	TGraphErrors *CompareGraph = new TGraphErrors();
	CompareGraph->SetName("CompareGraph");

	// Defining the Edges for 5% centrality
	// std::vector<double> binLabels = {12.79, 17.38, 24.80, 33.44, 44.61, 57.96, 72.46, 89.48, 110.39, 133.27, 160.07, 191.41, 228.03, 268.99, 318.49, 356.00}; //NPART
	// std::vector<int> binEdges = {4, 5, 8, 11, 15, 20, 26, 32, 40, 49, 59, 71, 85, 101, 119, 141, 195}; //FXTMULT

	// Defining the Edges for 5% centrality up to 70%
	// std::vector<double> binLabels = { 24.80, 33.44, 44.61, 57.96, 72.46, 89.48, 110.39, 133.27, 160.07, 191.41, 228.03, 268.99, 318.49, 356.00}; //NPART
	// std::vector<int> binEdges = {8, 11, 15, 20, 26, 32, 40, 49, 59, 71, 85, 101, 119, 141, 195}; //FXTMULT

	// Centrality definition excluding protons (FXTMult3)(0-5%, 5-10%, 10-20%,...,50-60%)
	std::vector<double> binLabels = {47, 70, 106, 155, 220, 283, 328};
	std::vector<int> binEdges = {4, 6, 10, 16, 26, 38, 48, 80};

	// Defining the Edges for 10% centrality (FXTMULT)
	// std::vector<double> binLabels = {(12.79 + 17.38)/2, (24.80 + 33.44)/2, (44.61+ 57.96)/2, (72.46 + 89.48)/2, (110.39 + 133.27)/2, (160.07+191.41)/2, (228.03+ 268.99)/2 , (318.49 + 356.00)/2}; //NPART
	// std::vector<int> binEdges = {4, 8, 15, 26, 40, 59, 85, 119, 195}; //FXTMULT

	std::vector<CumulantProfileContainer *> cpc_vec; // This cpc_vect might be useful when including bootstrap CHECK LATER
	for (int i = 0; i < 50; i++)
	{
		cpc_vec.push_back(new CumulantProfileContainer(i));
	}

	TString LambdaName[2] = {"Lambda", "AntiLambda"}, LambdaTitle[2] = {"#Lambda", "#bar{#Lambda}"}, DaughterName[2] = {"Proton", "Pion"}, DaughterTitle[2] = {"p", "#pi"};

	for (int eLambda = 0; eLambda < 1; eLambda++)
	{
		// Here I define the histogram for counting event by event Lambdas
		h1f_EbE_Lambda_[eLambda].reset(new TH1F(Form("Counts %ss", LambdaName[eLambda].Data()),
												Form(";Number of %ss; Counts", LambdaName[eLambda].Data()), 16, 0, 16));
		h1f_InvMass_NumLambdas_[eLambda].reset(new TH1F(Form("InvMass_Num%ss_", LambdaName[eLambda].Data()),
														Form(";m_{%s} (GeV);# %ss", LambdaTitle[eLambda].Data(), LambdaName[eLambda].Data()),
														256, 1.08, 1.20));
		h1f_Phi_NumLambdas_OnMassPeak[eLambda].reset(new TH1F(Form("Phi_Num%ss_OnMassPeak", LambdaName[eLambda].Data()),
															  Form("On mass peak;#phi_{%s};%s yield", LambdaName[eLambda].Data(), LambdaTitle[eLambda].Data()),
															  128, -pi, pi));
		h1f_SumDaughterMomentumInLambdaFrame_NumLambdas_[eLambda].reset(new TH1F(Form("SumDaughterMomentumIn%sFrame_Num%ss_", LambdaName[eLambda].Data(), LambdaName[eLambda].Data()),
																				 Form("Daughters in %s frame;|#vec{#it{p}}_{#it{p}} + #vec{#it{p}}_{#it{#pi}}| (GeV));# %ss", LambdaTitle[eLambda].Data(), LambdaTitle[eLambda].Data()),
																				 512, -2.5, 2.5));
		h2f_ComRapidity_Pt_NumLambdas_OnMassPeak[eLambda].reset(new TH2F(Form("ComRapidity_Pt_Num%ss_OnMassPeak", LambdaName[eLambda].Data()),
																		 Form("On mass peak;y_{COM};p_{T} (GeV);%s yield", LambdaTitle[eLambda].Data()),
																		 160, -1.0, 1.0, 128, MinPtLambda, MaxPtLambda)); // 2D histogram for pT vs y_{CM}
		h2f_ComEta_Pt_NumLambdas_OnMassPeak[eLambda].reset(new TH2F(Form("ComEta_Pt_Num%ss_OnMassPeak", LambdaName[eLambda].Data()),
																	Form("On mass peak;#eta+|y_{beam}|;p_{T} (GeV);%s yield", LambdaTitle[eLambda].Data()),
																	160, -1., 1., 128, MinPtLambda, MaxPtLambda));

		for (int eDaughter = 0; eDaughter < 2; eDaughter++)
		{
			h1f_ComEtaDaughter_NumLambdas_[eLambda][eDaughter].reset(new TH1F(Form("ComEta%s_Num%ss_", DaughterName[eDaughter].Data(), LambdaName[eLambda].Data()),
																			  Form(";#eta_{%s} + |y_{beam}|;%s yield", DaughterTitle[eDaughter].Data(), LambdaTitle[eLambda].Data()),
																			  128, -1., 1.));
		} // eDaughter

		if (eLambda == 0)
			unique_ptr<TH1F> h1f___LambdaAntiLambdaDivider(new TH1F("--------------------- ^ Lambdas ^ ----- v AntiLambdas v --------------------", "", 1, 0, 1)); // Keep here at bottom of loop
	}																																							   // eLambda

	// Multiplicity distribution for each centrality bin
	/*
	for(int i=0; i<8; i++){
	h1f_Dist_Cent[i].reset(new TH1F(Form("Dist_Cent_%d", i) , Form("Counts; NLambda; Centrality Bin %d", i ) , 8,0,8  ));   //TH1(name, title, range & bin in x)
	}*/

	//----------------------------------------- Declare relevant "I" variables ------------------------------------------//
	IEvent *theEvent = 0;
	ILambda *theLambda = 0;
	ITrack theProton, thePion;

	int nEventZeroLambda = 0; // A counter for the number of events that have zero lambdas

	//---------------------------Make Lambda Efficiency Object---------------------------//
	// LambdaEfficiency * eff = new LambdaEfficiency("/home/jonathan/Documents/LambdaFluctuationAnalyses/FitEff/fitEmbeddingLambda.root");  //Old Efficiencies
	// LambdaEfficiency * eff = new LambdaEfficiency("/home/jonathan/Documents/LambdaFluctuationAnalyses/FitEff/Eff_Lambda_Zhou_Cent0.root");
	//LambdaEfficiency *eff = new LambdaEfficiency("/media/jonathan/Extreme/JBall/LambdaFluctuationAnalyses/FitEff/Eff_Lambda_Run_No_Cuts.root");
	LambdaEfficiency *eff = new LambdaEfficiency("/media/jonathan/Extreme/JBall/LambdaFluctuationAnalyses/FitEff/Eff_Lambda_Run_FxtMult3.root");

	// LambdaEfficiency * eff =  new LambdaEfficiency();
	// eff->SetConstantEfficiency(1.0);

	theChain->SetBranchAddress("LambdaEvent", &theEvent);

	//------------------------------------------ Load some "global" variables -------------------------------------------//
	// int BadRunListFromQAStudy[] = {19151029, 19152001, 19152078, 19153023, 19153032, 19153065, 19154012, 19154013, 19154014, 19154015, 19154016, 19154017, 19154018,
	//                               19154019, 19154020, 19154021, 19154022, 19154023, 19154024, 19154026, 19154051};  // For Robust Analyses

	int BadRunListFromQAStudy[] = {19151029, 19151031, 19151034, 19151036, 19151039, 19151041, 19151043,
								   19151044, 19151045, 19151046, 19151047, 19151048, 19151049, 19151050,
								   19151052, 19151053, 19151054, 19151055, 19151056, 19151066, 19151067,
								   19151068, 19151069, 19151070, 19151071, 19151072, 19151082, 19151083,
								   19151084, 19152001, 19152002, 19152003, 19152008, 19152009, 19152010,
								   19152014, 19152016, 19152021, 19152023, 19152024, 19152025, 19152027,
								   19152028, 19152029, 19152030, 19152031, 19152032, 19152033, 19152034,
								   19152035, 19152036, 19152037, 19152038, 19152039, 19152040, 19152041,
								   19152042, 19152043, 19152044, 19152045, 19152046, 19152048, 19152051,
								   19152052, 19152053, 19152054, 19152055, 19152071, 19152073, 19152074,
								   19152075, 19152076, 19152078, 19152081, 19153001, 19153002, 19153003,
								   19153004, 19153007, 19153009, 19153010, 19153011, 19153012, 19153013,
								   19153014, 19153015, 19153016, 19153017, 19153018, 19153019, 19153020,
								   19153021, 19153022, 19153023, 19153024, 19153025, 19153027, 19153028,
								   19153029, 19153031, 19153032, 19153065, 19154012, 19154013, 19154014,
								   19154015, 19154016, 19154017, 19154018, 19154019, 19154020, 19154021,
								   19154022, 19154023, 19154024, 19154026, 19154046, 19154051, 19154056}; // For Sensitive Analyses

	//------------------------------------------------ Loop over events -------------------------------------------------//
	TStopwatch timer;
	timer.Start();
	int nEvents = theChain->GetEntries(), previousCompletionFraction = -1;

	cout << "\nLooping initially over " << theChain->GetEntries() << endl;

	int CounterEvents = 0; // Counting Total number of events after excluding Bad Runs and Wrong Triggers

	for (int iEvent = 0; iEvent < theChain->GetEntries(); iEvent++)
	{
		theChain->GetEntry(iEvent);

		// if( theEvent->NLambda()==0 ) continue; // This avoids looping over events that have zero lambdas

		//----------------------------- Output the completion status ----------------------------//
		int completionFraction = iEvent * 100.0 / nEvents;
		if (completionFraction % 1 == 0 && completionFraction != previousCompletionFraction)
		{
			double timeNow = timer.RealTime() / 60.;
			timer.Continue();
			double endTime = timeNow / ((double)completionFraction / 100.);
			cout << completionFraction << "\% finished. Finishing in appx. " << endTime - timeNow << " minutes." << endl;
			previousCompletionFraction = completionFraction;
		}

		//--------------------------- Load the event quantities and make some cuts --------------------------//
		int RunNumber = theEvent->GetRunNumber();
		for (int BadRunNumber : BadRunListFromQAStudy)
			if (RunNumber == BadRunNumber)
				continue;

		// double Centrality;
		int CentralityBin;
		// int RefMult = theEvent->GetRefMult();  //Using all charged particles between eta:[-2,0]
		int RefMult = theEvent->GetRefMult3(); //" "  but excluding protons
											   // Centrality definition from original Joey's code

		/*if(      RefMult>195 ) continue;
		else if( RefMult>140 ){ Centrality = 2; CentralityBin = 8;}  //originaly 2.5
		else if( RefMult>117 ){ Centrality = 7; CentralityBin = 7;}  //originaly 7.5
		else if( RefMult>82  ){ Centrality = 15;  CentralityBin = 6;}
		else if( RefMult>56  ){ Centrality = 25;  CentralityBin = 5;}
		else if( RefMult>37  ){ Centrality = 35;  CentralityBin = 4;}
		else if( RefMult>23  ){ Centrality = 45;  CentralityBin = 3;}
		else if( RefMult>13  ){ Centrality = 55;  CentralityBin = 2;}
		else if( RefMult>6   ){ Centrality = 65;  CentralityBin = 1;}
		else if( RefMult>2   ){ Centrality = 75;  CentralityBin = 0;}
		else continue;
		*/

		// Centrality definition from Cebra's presentation September 2020
		/*
		 if(      RefMult>195 ) continue;
		else if( RefMult>141 ){ Centrality = 5; CentralityBin = 15;}
		else if( RefMult>118 ){ Centrality = 10; CentralityBin = 14;}
		else if( RefMult>99  ){ Centrality = 15;  CentralityBin = 13;}
		else if( RefMult>83  ){ Centrality = 20;  CentralityBin = 12;}
		else if( RefMult>70  ){ Centrality = 25;  CentralityBin = 11;}
		else if( RefMult>58  ){ Centrality = 30;  CentralityBin = 10;}
		else if( RefMult>47  ){ Centrality = 35;  CentralityBin = 9;}
		else if( RefMult>38   ){ Centrality = 40;  CentralityBin = 8;}
		else if( RefMult>31   ){ Centrality = 45;  CentralityBin = 7;}
		else if( RefMult>24   ){ Centrality = 50;  CentralityBin = 6;}
		else if( RefMult>19   ){ Centrality = 55;  CentralityBin = 5;}
		else if( RefMult>15   ){ Centrality = 60;  CentralityBin = 4;}
		else if( RefMult>11   ){ Centrality = 65;  CentralityBin = 3;}
		else if( RefMult>8   ){ Centrality = 70;  CentralityBin = 2;}
		else if( RefMult>6  ){ Centrality = 75;  CentralityBin = 1;}
		else if( RefMult>4  ){ Centrality = 80;  CentralityBin = 0;}
		else continue; */

		//----------Using only every 10% cent
		// if(      RefMult>196 ) continue;  //change 196 to 195
		// else if( RefMult>141 ){ Centrality = 5; CentralityBin = 15;}
		// else if( RefMult>118 ){ Centrality = 10; CentralityBin = 7;}
		// else if( RefMult>99  ){ Centrality = 15;  CentralityBin = 13;}
		// else if( RefMult>83  ){ Centrality = 20;  CentralityBin = 6;}
		// else if( RefMult>70  ){ Centrality = 25;  CentralityBin = 11;}
		// else if( RefMult>58  ){ Centrality = 30;  CentralityBin = 5;}
		// else if( RefMult>47  ){ Centrality = 35;  CentralityBin = 9;}
		// else if( RefMult>38   ){ Centrality = 40;  CentralityBin = 4;}
		// else if( RefMult>31   ){ Centrality = 45;  CentralityBin = 7;}
		// else if( RefMult>24   ){ Centrality = 50;  CentralityBin = 3;}
		// else if( RefMult>19   ){ Centrality = 55;  CentralityBin = 5;}
		// else if( RefMult>15   ){ Centrality = 60;  CentralityBin = 2;}
		// else if( RefMult>11   ){ Centrality = 65;  CentralityBin = 3;}
		// else if( RefMult>8   ){ Centrality = 70;  CentralityBin = 1;}
		// else if( RefMult>6  ){ Centrality = 75;  CentralityBin = 1;}
		// else if( RefMult>3  ){ Centrality = 80;  CentralityBin = 0;}  //change 3 to 4
		// else continue;

		//--------Updated Centrality definition Heppelmann FxtMult3

		      if(      RefMult>80 ) continue;
		/*	else if( RefMult>48 ){ Centrality = 5; CentralityBin = 6;}
			else if( RefMult>38 ){ Centrality = 10; CentralityBin = 5;}
			else if( RefMult>26  ){ Centrality = 20;  CentralityBin = 4;}
			else if( RefMult>16  ){ Centrality = 30;  CentralityBin = 3;}
			else if( RefMult>10  ){ Centrality = 40;  CentralityBin = 2;}
			else if( RefMult>6  ){ Centrality = 50;  CentralityBin = 1;}
			else if( RefMult>4  ){ Centrality = 60;  CentralityBin = 0;}
			else continue;
			*/

		TVector3 PrimaryVertex = theEvent->PrimaryVertex();
		double Vz = PrimaryVertex.Z();
		vector<unsigned int> TriggerIDs = theEvent->GetTriggers();
		bool TriggerIsGood = false;
		for (unsigned int TriggerID : TriggerIDs)
		{
			if (TriggerID == 620052 || TriggerID == 620053)
				TriggerIsGood = true;
			break;
		} // This uses the bbce_tofMult1 and epde_tofMult1
		if (!TriggerIsGood)
			continue;

		// if( theEvent->GetNumHitsEpdSmallAbsEta()==0 ) continue;
		// if( theEvent->GetNumHitsEpdLargeAbsEta()==0 ) continue;
		// if( theEvent->GetNumHitsTpcMidAbsEta()==0 ) continue;

		CounterEvents = CounterEvents + 1;

		

			 vector<pair<int,double>>  track_eff_pair_vec;          //Defining the track efficiency pair vector ---------------


			 int NLambdasInAccept = 0;



			 int NLambda[1];
			 //--------------------------------------- Loop over Lambda types ------------------------------------//
			 for( int eLambda=0; eLambda<1; eLambda++ ){

				//--------------- Start looping over the Lambdas and load the Lambda and Daughters ---------//
				int NumLambdasInEvent = 0; NumLambdasInEvent = (eLambda == 0)?theEvent->NLambda():theEvent->NAntiLambda();
				NLambdas=0;
				NLambda[eLambda]=0;

				// if(NumLambdasInEvent == 0) continue;  //Avoiding events that have zero Lambdas from the beginning
				for( int iLambda=0; iLambda<NumLambdasInEvent; iLambda++ ){
					theLambda = (eLambda==0)?theEvent->GetLambda(iLambda):theEvent->GetAntiLambda(iLambda);
					theProton = (eLambda==0)?theLambda->PosDaughter():theLambda->NegDaughter();
					thePion = (eLambda==0)?theLambda->NegDaughter():theLambda->PosDaughter();



					//------------------- Load and initialize Lambda and Daughter variables ------------//
					TLorentzVector Lambda4Momentum = theLambda->CalcMomentum();
					TLorentzVector BoostedProton4Momentum = theProton.Momentum();
					TLorentzVector BoostedPion4Momentum = thePion.Momentum();
					TLorentzVector Proton4Momentum = BoostedProton4Momentum; Proton4Momentum.Boost(Lambda4Momentum.BoostVector());
					TLorentzVector Pion4Momentum = BoostedPion4Momentum; Pion4Momentum.Boost(Lambda4Momentum.BoostVector());
					TVector3 DecayPoint = theLambda->DecayPoint();
					TVector3 DecayPointRelativeToPv = DecayPoint - PrimaryVertex;
					TVector3 Lambda3Momentum = Lambda4Momentum.Vect();
					double DecayLength = DecayPointRelativeToPv.Mag();
					double PointingAngle = Lambda3Momentum.Angle(DecayPointRelativeToPv);
					double LambdaDcaToPv = DecayLength*sin(PointingAngle);
					double PhiLambda = Lambda4Momentum.Phi();
					double PtLambda = Lambda4Momentum.Pt();
					double Pz = Lambda4Momentum.Pz();
					double ComEtaLambda = Lambda4Momentum.PseudoRapidity()+1.045;
					double ComRapidityLambda = Lambda4Momentum.Rapidity()+1.045;
					double LambdaCalcMass = theLambda->CalcMass();
					double ExpectedDecayLength = Lambda4Momentum.Beta()*7.89*Lambda4Momentum.Gamma();






					//-------------------------------- Cut on Lambda values ----------------------------//
					if( LambdaDcaToPv>MaxLambdaDcaToPv ) continue;
					if( Proton4Momentum.Pt()<MinPtProton || Pion4Momentum.Pt()<MinPtPion ) continue;
					if( PtLambda<MinPtLambda || PtLambda>MaxPtLambda ) continue;
					if( ComRapidityLambda<MinComRapidityLambda || ComRapidityLambda>MaxComRapidityLambda ) continue;


					h1f_InvMass_NumLambdas_[eLambda]->Fill(Lambda4Momentum.M());

					//----------------------------------- Make the mass cut ----------------------------//
					if( fabs(LambdaCalcMass-LambdaPdgMass)>LambdaMassCut ) continue;





					for( int eDaughter=0; eDaughter<2; eDaughter++ ){
						ITrack Daughter = (eDaughter==0)?theProton:thePion;
						TLorentzVector Daughter4Momentum = Daughter.Momentum();
						TLorentzVector BoostedDaughter4Momentum = Daughter4Momentum; BoostedDaughter4Momentum.Boost(-Lambda4Momentum.BoostVector());
						h1f_ComEtaDaughter_NumLambdas_[eLambda][eDaughter]->Fill(Daughter4Momentum.PseudoRapidity()+1.045);
					} // eDaughter


					//double TrackEff = -1;
					double TrackEff = 1.0;  //Used this one to set a constant efficiency of 1
					int charge = 1;
					//TrackEff = eff->GetEff(charge,ComRapidityLambda,PtLambda);  //used when I directly used the rapidity
					//TrackEff = eff->GetEff(charge,PtLambda, Pz );
					if (TrackEff<0) continue;

					pair<int,double> track_eff_pair = make_pair(charge,TrackEff);

					//push the pair to the track_eff array

					track_eff_pair_vec.push_back(track_eff_pair);


					h1f_SumDaughterMomentumInLambdaFrame_NumLambdas_[eLambda]->Fill((BoostedProton4Momentum.Vect()+BoostedPion4Momentum.Vect()).Mag());
					h1f_Phi_NumLambdas_OnMassPeak[eLambda]->Fill(PhiLambda);
					h2f_ComRapidity_Pt_NumLambdas_OnMassPeak[eLambda]->Fill(ComRapidityLambda,PtLambda);
					h2f_ComEta_Pt_NumLambdas_OnMassPeak[eLambda]->Fill(ComEtaLambda,PtLambda);



					NLambda[eLambda]=NLambda[eLambda]+1;  //Lambda Counter


				} // iLambda

				//---------------------Here I count the number of Lambdas in the event ALSO check if multiplicity is zero in the acceptance, do not count---------//
				NLambdas=NLambda[0];
				//if(NLambdas==0) continue;

				//T->Fill();
				//cout<<"\n Number of Lambdas in this event is: "<<NLambda[eLambda]<< endl;
				h1f_EbE_Lambda_[eLambda]->Fill(NLambda[eLambda]);


				//Filling distributions for every centrality
				// h1f_Dist_Cent[CentralityBin]->Fill(NLambda[eLambda]);



			 } // eLambda


		
		// NLambdas=NLambda[0];
		// T->Fill();

		
			 vector<vector<double>> qrs = make_all_q_s( track_eff_pair_vec, 4, 4);
			 cpc -> FillProfile(RefMult, qrs);




			 int nFill = 0;

			//----Including the bootstrap part-----//
			  for( auto &c : cpc_vec )
			{
			  nFill = rand-> Poisson(1);
			  for (int iFill=0;iFill<nFill;iFill++)
				{
				  c->FillProfile(RefMult,qrs);
				}
			}
		

	} // iEvent

	// Output cumulant profiles

	

		cpc->FactorialCumulantsToNormalCumulants();

		//----converting fc to nc in the containers-----//
		for (auto &c : cpc_vec )
		{
		  c->FactorialCumulantsToNormalCumulants();
		}

		cpc -> ReBinAllGraphs(binEdges, binLabels);

		for (auto &c : cpc_vec)
		{
		  c->ReBinAllGraphs(binEdges,binLabels);
		}

	  ComputeBootstrapErrors(cpc,cpc_vec);


		prof_vec = cpc->GetProfileVec();
		gr = cpc->GetGraphVec();

		gr1 = cpc_vec[0]->GetGraphVec();
		gr2 = cpc_vec[1]->GetGraphVec();


		TFile * outfile = new TFile("cumulants_outfile_WithOutEff_Cut_Yields_50Files.root","recreate");
		outfile->cd();

		for (auto &g : gr)
		{
		  g->Write();
		}

		for (auto &p :prof_vec)
		{
		  p->Write();
		}


		for (auto &g : gr1)
		{
		  g->Write();
		}

		for (auto &g : gr2)
		{
		  g->Write();
		}



		HistogramOutput->cd();
		HistogramOutput->Write();
		//T->Print();
		//T->Write("", TObject::kOverwrite);
	

	cout << "The total processed number of events: " << CounterEvents << endl;

	double time = timer.RealTime();
	cout << "\nLooping over " << theChain->GetEntries() << " events took " << time << "s (" << time * 1000.0 / theChain->GetEntries() << " ms/ev)\n\n";

} // void AnalyzeFemtoDst
