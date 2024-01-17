//This is a class used to obtain the efficiencies for Lambdas
//Currently only has constant efficiency
//should be updated to have efficiency curves 
#include <vector>
#include <iostream>
#include "LambdaEfficiency.h"
#include "TH2F.h"
#include "TFile.h"
#include "TH2D.h"
#include "TF1.h"

using namespace std;

LambdaEfficiency::LambdaEfficiency()
{
  //by default, a constant efficiency of 1.0
  constantEfficiencySet = true;
  constantEfficiency  = 1.0;  

  SetConstants();
}

LambdaEfficiency::LambdaEfficiency(TString filename)
{

  LoadTPCEff( filename );

  //by default, a constant efficiency of 1.0
  constantEfficiencySet = false;
  
  SetConstants();
}



LambdaEfficiency::LambdaEfficiency(TString filename1,TString filename2)
{

  LoadTPCEff( filename1 );
  LoadTOFEff( filename2 );

  //by default, a constant efficiency of 1.0
  constantEfficiencySet = false;
  
  SetConstants();

} //TOF was not used


LambdaEfficiency::~LambdaEfficiency()
{
}


int LambdaEfficiency::SetConstants()  //Defining parameters like mass and edges of rapidity (?)check
{
  _mass = 1.11568;
//_bin_edges = {-0.70, -0.65, -0.60, -0.55, -0.50, -0.45, -0.40, -0.35, -0.30, -0.25, -0.20, -0.15, -0.10, -0.05, 0.0, 0.05, 0.10, 0.15, 0.20, 0.25, 0.30, 0.35, 0.40, 0.45, 0.50, 0.55, 0.60, 0.65, 0.70, 0.75, 0.80, 0.85, 0.90 };
_bin_edges = {-1.0, -0.9, -0.8, -0.7, -0.6, -0.5, -0.4, -0.3, -0.2, -0.1, 0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.70, 0.8, 0.9, 1.0 };
}



int LambdaEfficiency::LoadTOFEff(TString filename)
{
  cout << "LoadTOFEff() loading histogram..." << endl;
  TFile * f = new TFile(filename,"read");
  h_eff_tof = (TH2F*) f->Get("tpc_tofmatch");
  cout << "             histogram loaded." << endl;

  return 0;
}   //No Time Of Flight information in the Lambda case

int LambdaEfficiency::LoadTPCEff(TString filename) //This is the class member fucntion to load the efficiency files
{

  TFile * f = new TFile(filename,"read");

  cout << "LoadTPCEff() loading histograms and fits ..." << endl;
  //for (int i=17;i<35;i++)  //load the histograms and fits for different rapity bins.
    //for(int i=2; i<10; i++) //With previous lambda efficiency profile
    for(int i=1; i<21; i++)
    {
      _h1d_eff.push_back( (TH1D*) f->Get(TString::Format("projection_%i",i).Data()) );
      _tf1_eff.push_back( (TF1*) f->Get(TString::Format("f_%i",i).Data()) );
    }

  cout << "             hists and fits loaded" << endl;


  return 0;

}



double LambdaEfficiency::GetTPCEfficiency(double y, double pt) //Gets the efficiency for the particular y and pT
{

  y = -1.0*y; // Switch Conventions
  //y=1.0*y; //Keep Convention
  if (y <= _bin_edges[0] || y >= _bin_edges[_bin_edges.size()-1] ) return -1; // if the rapidity is out of the rapidity range, return -1

  //Get the index for the correct histogram and fit
  int index =-1;
  for ( int iBin=0;iBin<_bin_edges.size()-1;iBin++)
    {
      if ( y > _bin_edges[iBin] && y <= _bin_edges[iBin+1] ) index=iBin;
    } 
  if (index<0) return -1;

  TH1D * h = _h1d_eff[index];
  TF1 * f = _tf1_eff[index];
  
  float xMin = h->GetBinLowEdge(h->FindFirstBinAbove(0.01));
  float xMax = 3.0;
  if ( pt <= xMin || pt >= xMax ) return -1;

  double eff = f->Eval( pt );
  //std::cout<< "the eff for the track is: " <<eff<<" with y: "<<y<<" and pT:  "<<pt<<endl; 
  if ( eff > 1.0 || eff < 0.005 ) return -1; //Set to 0.5% cut off
  
  return eff;
}



double LambdaEfficiency::GetTOFEfficiency(double y, double pt)
{
  return h_eff_tof->GetBinContent( h_eff_tof->FindBin(y,pt) );
}  //Gets the value of the efficiency for the TOF efficiency



double LambdaEfficiency::GetConstantEfficiency()  //Return constant efficiency
{
  return constantEfficiency;
}

void LambdaEfficiency::SetConstantEfficiency(double val)  //Set the value of the efficiency
{
  constantEfficiencySet = true;
  constantEfficiency     = val;
}


/*
double LambdaEfficiency::GetEff(int charge, double pt,double pz)
{

  //an empty Lambda efficiency will return 1, no eff correction.  
  if (!constantEfficiencySet)
    {

      double y = Rapidity(pt,pz);
      double eff = GetTPCEfficiency(y,pt);

      if ( eff <= 0 || eff > 1.0 ) return -1;
      return eff;
    }

  return GetConstantEfficiency();
  
}*/



double LambdaEfficiency::GetEff(int charge, double y, double pt)
{

  //an empty Lambda efficiency will return 1, no eff correction.  
  if (!constantEfficiencySet)
    {

      //double y = Rapidity(pt,pz);
      double eff = GetTPCEfficiency(y,pt);

      if ( eff <= 0 || eff > 1.0 ) return -1;
      return eff;
    }

  return GetConstantEfficiency();
  
}

double LambdaEfficiency::GetEff(int charge, double pt,double pz,bool tofmatch)   //Used if I have the tofmatch
{

  //an empty Lambda efficiency will return 1, no eff correction.  
  if (!constantEfficiencySet)
    {
      double y = Rapidity(pt,pz);       
      double eff = GetTPCEfficiency(y,pt);
      
      if (tofmatch)
	{
	  double tofEff = GetTOFEfficiency(y,pt);
	  eff = eff*tofEff;
	}
      
      if ( eff <= 0.01 || eff > 1.0 ) return -1;

      return eff;
    }

  return GetConstantEfficiency();
  
}


double LambdaEfficiency::Rapidity(double pt, double pz)
{
  Double_t energy = sqrt( pow(pt,2) + pow(pz,2) + pow(_mass,2) );
  Double_t rap = 0.5 * log( ( energy + pz) / (energy - pz) );
  rap = fabs(rap);
  
  //return rap - 1.04;  //previously defined in the container
  return 1.04 - rap;
}   //No need to define a rapidity since in I already have the values for the rapidity and pT.
