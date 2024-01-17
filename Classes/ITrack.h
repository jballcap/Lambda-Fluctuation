// Tiny DST class for 27GeV run

#ifndef ITRACK_H
#define ITRACK_H

#include "TLorentzVector.h"
class IEvent;

class ITrack : public TObject {

 protected:

  Int_t mTrackID;
  TLorentzVector mMomentum; //use momentum at the decay point of the Lambda, not the track momentum

 public:

  ITrack();
  ~ITrack();

  void ClearTrack();

  //  void SetParentEvent(DEvent* p){mParentEvent=p;}
  void SetTrackID(Int_t id){mTrackID=id;}
  void SetMomentum(TLorentzVector a){mMomentum = a;}

  Int_t TrackID(){return mTrackID;}
  TLorentzVector Momentum(){return mMomentum;}

  //ClassDef(ITrack,1)  // my track
  ClassDef(ITrack, 2)
};

#endif
