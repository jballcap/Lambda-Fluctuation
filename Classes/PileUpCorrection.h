#ifndef PILE_UP_CORRECTION_H
#define PILE_UP_CORRECTION_H

#include <TMath.h>
#include "TH1F.h"
#include "TH2.h"
//class TH1F;
//class TH2F;
class CumulantProfileContainer;

class PileUpCorrection : public TObject
{

 public:

  PileUpCorrection();
  virtual ~PileUpCorrection();

  void CorrectionZero( Double_t *mucor,Double_t *musub, const Double_t alpha, const Double_t beta );
  void Correction( Double_t *mucor,Double_t *musub, Double_t  *muzero, const Double_t alpha, const Double_t beta );
  CumulantProfileContainer * CorrectionForMultRange(int iName,int trgMult, int maxMult);

  bool LoadPileUpHistograms(TString filename);
  bool LoadURQMDHistograms(TString filename);
  CumulantProfileContainer * LoadCumulant(TString filename,int iContainer);
  CumulantProfileContainer * LoadURQMDCumulant(TString filename);
  CumulantProfileContainer * GetURQMDTrueCumulant(TString filename);

 private:

  TH1F *hMult_true;
  TH1F *hMult;
  TH1F *inputMult;
  TH2F *hRM;

  //  const int NCENT = 9;
  //  const int ORDER = 4;
  //  const int NMULT = 9;

  enum{NMULT = 300, ORDER =4, NCENT= 9};

  // measured cumulants and moments
  Double_t C[NMULT][ORDER+1];
  Double_t cbwcC[NCENT][ORDER+1];
  Double_t mu[NMULT][ORDER+1];

  // true cumulants and moments
  Double_t C_true[NMULT][ORDER+1];
  Double_t cbwcC_true[NCENT][ORDER+1];
  Double_t mu_true[NMULT][ORDER+1];
  Double_t centevent[NCENT];
  
  Double_t C_cor[NMULT][ORDER+1];
  Double_t mu_cor[NMULT][ORDER+1];
  Double_t cbwcC_cor[NMULT][ORDER+1];

  ClassDef(PileUpCorrection,1)

};

#endif
