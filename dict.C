// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dict
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// The generated code does not explicitly qualifies STL entities
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "Classes/IEvent.h"
#include "Classes/ILambda.h"
#include "Classes/ITrack.h"
#include "Classes/LambdaEfficiency.h"
#include "Classes/MomentFunctions.h"
#include "Classes/CumulantProfileContainer.h"
#include "Classes/FlucContainer.h"
#include "Classes/PileUpCorrection.h"
#include "Classes/analysisUtil.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_IEvent(void *p = 0);
   static void *newArray_IEvent(Long_t size, void *p);
   static void delete_IEvent(void *p);
   static void deleteArray_IEvent(void *p);
   static void destruct_IEvent(void *p);
   static void streamer_IEvent(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::IEvent*)
   {
      ::IEvent *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::IEvent >(0);
      static ::ROOT::TGenericClassInfo 
         instance("IEvent", ::IEvent::Class_Version(), "Classes/IEvent.h", 19,
                  typeid(::IEvent), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::IEvent::Dictionary, isa_proxy, 16,
                  sizeof(::IEvent) );
      instance.SetNew(&new_IEvent);
      instance.SetNewArray(&newArray_IEvent);
      instance.SetDelete(&delete_IEvent);
      instance.SetDeleteArray(&deleteArray_IEvent);
      instance.SetDestructor(&destruct_IEvent);
      instance.SetStreamerFunc(&streamer_IEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::IEvent*)
   {
      return GenerateInitInstanceLocal((::IEvent*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::IEvent*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_ITrack(void *p = 0);
   static void *newArray_ITrack(Long_t size, void *p);
   static void delete_ITrack(void *p);
   static void deleteArray_ITrack(void *p);
   static void destruct_ITrack(void *p);
   static void streamer_ITrack(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ITrack*)
   {
      ::ITrack *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::ITrack >(0);
      static ::ROOT::TGenericClassInfo 
         instance("ITrack", ::ITrack::Class_Version(), "Classes/ITrack.h", 9,
                  typeid(::ITrack), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::ITrack::Dictionary, isa_proxy, 16,
                  sizeof(::ITrack) );
      instance.SetNew(&new_ITrack);
      instance.SetNewArray(&newArray_ITrack);
      instance.SetDelete(&delete_ITrack);
      instance.SetDeleteArray(&deleteArray_ITrack);
      instance.SetDestructor(&destruct_ITrack);
      instance.SetStreamerFunc(&streamer_ITrack);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ITrack*)
   {
      return GenerateInitInstanceLocal((::ITrack*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::ITrack*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_ILambda(void *p = 0);
   static void *newArray_ILambda(Long_t size, void *p);
   static void delete_ILambda(void *p);
   static void deleteArray_ILambda(void *p);
   static void destruct_ILambda(void *p);
   static void streamer_ILambda(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ILambda*)
   {
      ::ILambda *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::ILambda >(0);
      static ::ROOT::TGenericClassInfo 
         instance("ILambda", ::ILambda::Class_Version(), "Classes/ILambda.h", 11,
                  typeid(::ILambda), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::ILambda::Dictionary, isa_proxy, 16,
                  sizeof(::ILambda) );
      instance.SetNew(&new_ILambda);
      instance.SetNewArray(&newArray_ILambda);
      instance.SetDelete(&delete_ILambda);
      instance.SetDeleteArray(&deleteArray_ILambda);
      instance.SetDestructor(&destruct_ILambda);
      instance.SetStreamerFunc(&streamer_ILambda);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ILambda*)
   {
      return GenerateInitInstanceLocal((::ILambda*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::ILambda*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_LambdaEfficiency(void *p = 0);
   static void *newArray_LambdaEfficiency(Long_t size, void *p);
   static void delete_LambdaEfficiency(void *p);
   static void deleteArray_LambdaEfficiency(void *p);
   static void destruct_LambdaEfficiency(void *p);
   static void streamer_LambdaEfficiency(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::LambdaEfficiency*)
   {
      ::LambdaEfficiency *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::LambdaEfficiency >(0);
      static ::ROOT::TGenericClassInfo 
         instance("LambdaEfficiency", ::LambdaEfficiency::Class_Version(), "Classes/LambdaEfficiency.h", 10,
                  typeid(::LambdaEfficiency), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::LambdaEfficiency::Dictionary, isa_proxy, 16,
                  sizeof(::LambdaEfficiency) );
      instance.SetNew(&new_LambdaEfficiency);
      instance.SetNewArray(&newArray_LambdaEfficiency);
      instance.SetDelete(&delete_LambdaEfficiency);
      instance.SetDeleteArray(&deleteArray_LambdaEfficiency);
      instance.SetDestructor(&destruct_LambdaEfficiency);
      instance.SetStreamerFunc(&streamer_LambdaEfficiency);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::LambdaEfficiency*)
   {
      return GenerateInitInstanceLocal((::LambdaEfficiency*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::LambdaEfficiency*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CumulantProfileContainer(void *p = 0);
   static void *newArray_CumulantProfileContainer(Long_t size, void *p);
   static void delete_CumulantProfileContainer(void *p);
   static void deleteArray_CumulantProfileContainer(void *p);
   static void destruct_CumulantProfileContainer(void *p);
   static void streamer_CumulantProfileContainer(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CumulantProfileContainer*)
   {
      ::CumulantProfileContainer *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CumulantProfileContainer >(0);
      static ::ROOT::TGenericClassInfo 
         instance("CumulantProfileContainer", ::CumulantProfileContainer::Class_Version(), "Classes/CumulantProfileContainer.h", 13,
                  typeid(::CumulantProfileContainer), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CumulantProfileContainer::Dictionary, isa_proxy, 16,
                  sizeof(::CumulantProfileContainer) );
      instance.SetNew(&new_CumulantProfileContainer);
      instance.SetNewArray(&newArray_CumulantProfileContainer);
      instance.SetDelete(&delete_CumulantProfileContainer);
      instance.SetDeleteArray(&deleteArray_CumulantProfileContainer);
      instance.SetDestructor(&destruct_CumulantProfileContainer);
      instance.SetStreamerFunc(&streamer_CumulantProfileContainer);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CumulantProfileContainer*)
   {
      return GenerateInitInstanceLocal((::CumulantProfileContainer*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::CumulantProfileContainer*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static TClass *FlucContainer_Dictionary();
   static void FlucContainer_TClassManip(TClass*);
   static void *new_FlucContainer(void *p = 0);
   static void *newArray_FlucContainer(Long_t size, void *p);
   static void delete_FlucContainer(void *p);
   static void deleteArray_FlucContainer(void *p);
   static void destruct_FlucContainer(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::FlucContainer*)
   {
      ::FlucContainer *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::FlucContainer));
      static ::ROOT::TGenericClassInfo 
         instance("FlucContainer", "Classes/FlucContainer.h", 11,
                  typeid(::FlucContainer), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &FlucContainer_Dictionary, isa_proxy, 0,
                  sizeof(::FlucContainer) );
      instance.SetNew(&new_FlucContainer);
      instance.SetNewArray(&newArray_FlucContainer);
      instance.SetDelete(&delete_FlucContainer);
      instance.SetDeleteArray(&deleteArray_FlucContainer);
      instance.SetDestructor(&destruct_FlucContainer);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::FlucContainer*)
   {
      return GenerateInitInstanceLocal((::FlucContainer*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::FlucContainer*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *FlucContainer_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::FlucContainer*)0x0)->GetClass();
      FlucContainer_TClassManip(theClass);
   return theClass;
   }

   static void FlucContainer_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static void *new_PileUpCorrection(void *p = 0);
   static void *newArray_PileUpCorrection(Long_t size, void *p);
   static void delete_PileUpCorrection(void *p);
   static void deleteArray_PileUpCorrection(void *p);
   static void destruct_PileUpCorrection(void *p);
   static void streamer_PileUpCorrection(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::PileUpCorrection*)
   {
      ::PileUpCorrection *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::PileUpCorrection >(0);
      static ::ROOT::TGenericClassInfo 
         instance("PileUpCorrection", ::PileUpCorrection::Class_Version(), "Classes/PileUpCorrection.h", 11,
                  typeid(::PileUpCorrection), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::PileUpCorrection::Dictionary, isa_proxy, 16,
                  sizeof(::PileUpCorrection) );
      instance.SetNew(&new_PileUpCorrection);
      instance.SetNewArray(&newArray_PileUpCorrection);
      instance.SetDelete(&delete_PileUpCorrection);
      instance.SetDeleteArray(&deleteArray_PileUpCorrection);
      instance.SetDestructor(&destruct_PileUpCorrection);
      instance.SetStreamerFunc(&streamer_PileUpCorrection);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::PileUpCorrection*)
   {
      return GenerateInitInstanceLocal((::PileUpCorrection*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::PileUpCorrection*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr IEvent::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *IEvent::Class_Name()
{
   return "IEvent";
}

//______________________________________________________________________________
const char *IEvent::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::IEvent*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int IEvent::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::IEvent*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *IEvent::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::IEvent*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *IEvent::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::IEvent*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr ITrack::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *ITrack::Class_Name()
{
   return "ITrack";
}

//______________________________________________________________________________
const char *ITrack::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::ITrack*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int ITrack::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::ITrack*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ITrack::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::ITrack*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ITrack::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::ITrack*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr ILambda::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *ILambda::Class_Name()
{
   return "ILambda";
}

//______________________________________________________________________________
const char *ILambda::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::ILambda*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int ILambda::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::ILambda*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ILambda::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::ILambda*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ILambda::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::ILambda*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr LambdaEfficiency::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *LambdaEfficiency::Class_Name()
{
   return "LambdaEfficiency";
}

//______________________________________________________________________________
const char *LambdaEfficiency::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::LambdaEfficiency*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int LambdaEfficiency::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::LambdaEfficiency*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *LambdaEfficiency::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::LambdaEfficiency*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *LambdaEfficiency::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::LambdaEfficiency*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr CumulantProfileContainer::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *CumulantProfileContainer::Class_Name()
{
   return "CumulantProfileContainer";
}

//______________________________________________________________________________
const char *CumulantProfileContainer::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CumulantProfileContainer*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int CumulantProfileContainer::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CumulantProfileContainer*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *CumulantProfileContainer::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CumulantProfileContainer*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *CumulantProfileContainer::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CumulantProfileContainer*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr PileUpCorrection::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *PileUpCorrection::Class_Name()
{
   return "PileUpCorrection";
}

//______________________________________________________________________________
const char *PileUpCorrection::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::PileUpCorrection*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int PileUpCorrection::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::PileUpCorrection*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *PileUpCorrection::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::PileUpCorrection*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *PileUpCorrection::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::PileUpCorrection*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void IEvent::Streamer(TBuffer &R__b)
{
   // Stream an object of class IEvent.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> mRunNumber;
      R__b >> mChronologicalRunId;
      R__b >> mEventID;
      R__b >> mRefMult;
      R__b >> mRefMult3;
      R__b >> mCentralityID9;
      R__b >> mCentralityID16;
      mPrimaryVertex.Streamer(R__b);
      R__b >> mBfield;
      R__b >> mVpdVz;
      R__b >> mRefMultPos;
      R__b >> mRefMultNeg;
      {
         vector<unsigned int> &R__stl =  mTriggers;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            unsigned int R__t;
            R__b >> R__t;
            R__stl.push_back(R__t);
         }
      }
      R__b >> mPsi1RawEast;
      R__b >> mPsi1RawWest;
      R__b >> mPsi1GainMatchedAndv1weightedEast;
      R__b >> mPsi1GainMatchedAndv1weightedWest;
      R__b >> mPsi1EpdSmallAbsEta;
      R__b >> mPsi1EpdLargeAbsEta;
      R__b >> mPsi1TpcMidAbsEta;
      R__b >> mNumHitsEpdSmallAbsEta;
      R__b >> mNumHitsEpdLargeAbsEta;
      R__b >> mNumHitsTpcMidAbsEta;
      fLambdaCollection->Streamer(R__b);
      fAntiLambdaCollection->Streamer(R__b);
      R__b.CheckByteCount(R__s, R__c, IEvent::IsA());
   } else {
      R__c = R__b.WriteVersion(IEvent::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << mRunNumber;
      R__b << mChronologicalRunId;
      R__b << mEventID;
      R__b << mRefMult;
      R__b << mRefMult3;
      R__b << mCentralityID9;
      R__b << mCentralityID16;
      mPrimaryVertex.Streamer(R__b);
      R__b << mBfield;
      R__b << mVpdVz;
      R__b << mRefMultPos;
      R__b << mRefMultNeg;
      {
         vector<unsigned int> &R__stl =  mTriggers;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<unsigned int>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      R__b << mPsi1RawEast;
      R__b << mPsi1RawWest;
      R__b << mPsi1GainMatchedAndv1weightedEast;
      R__b << mPsi1GainMatchedAndv1weightedWest;
      R__b << mPsi1EpdSmallAbsEta;
      R__b << mPsi1EpdLargeAbsEta;
      R__b << mPsi1TpcMidAbsEta;
      R__b << mNumHitsEpdSmallAbsEta;
      R__b << mNumHitsEpdLargeAbsEta;
      R__b << mNumHitsTpcMidAbsEta;
      fLambdaCollection->Streamer(R__b);
      fAntiLambdaCollection->Streamer(R__b);
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_IEvent(void *p) {
      return  p ? new(p) ::IEvent : new ::IEvent;
   }
   static void *newArray_IEvent(Long_t nElements, void *p) {
      return p ? new(p) ::IEvent[nElements] : new ::IEvent[nElements];
   }
   // Wrapper around operator delete
   static void delete_IEvent(void *p) {
      delete ((::IEvent*)p);
   }
   static void deleteArray_IEvent(void *p) {
      delete [] ((::IEvent*)p);
   }
   static void destruct_IEvent(void *p) {
      typedef ::IEvent current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_IEvent(TBuffer &buf, void *obj) {
      ((::IEvent*)obj)->::IEvent::Streamer(buf);
   }
} // end of namespace ROOT for class ::IEvent

//______________________________________________________________________________
void ITrack::Streamer(TBuffer &R__b)
{
   // Stream an object of class ITrack.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> mTrackID;
      mMomentum.Streamer(R__b);
      R__b.CheckByteCount(R__s, R__c, ITrack::IsA());
   } else {
      R__c = R__b.WriteVersion(ITrack::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << mTrackID;
      mMomentum.Streamer(R__b);
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_ITrack(void *p) {
      return  p ? new(p) ::ITrack : new ::ITrack;
   }
   static void *newArray_ITrack(Long_t nElements, void *p) {
      return p ? new(p) ::ITrack[nElements] : new ::ITrack[nElements];
   }
   // Wrapper around operator delete
   static void delete_ITrack(void *p) {
      delete ((::ITrack*)p);
   }
   static void deleteArray_ITrack(void *p) {
      delete [] ((::ITrack*)p);
   }
   static void destruct_ITrack(void *p) {
      typedef ::ITrack current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_ITrack(TBuffer &buf, void *obj) {
      ((::ITrack*)obj)->::ITrack::Streamer(buf);
   }
} // end of namespace ROOT for class ::ITrack

//______________________________________________________________________________
void ILambda::Streamer(TBuffer &R__b)
{
   // Stream an object of class ILambda.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      mThreeMomentum.Streamer(R__b);
      mDecayPoint.Streamer(R__b);
      R__b >> mCalcMass;
      R__b >> mIndex;
      R__b >> mDaughterDca;
      mPosDaughter.Streamer(R__b);
      mNegDaughter.Streamer(R__b);
      R__b.CheckByteCount(R__s, R__c, ILambda::IsA());
   } else {
      R__c = R__b.WriteVersion(ILambda::IsA(), kTRUE);
      TObject::Streamer(R__b);
      mThreeMomentum.Streamer(R__b);
      mDecayPoint.Streamer(R__b);
      R__b << mCalcMass;
      R__b << mIndex;
      R__b << mDaughterDca;
      mPosDaughter.Streamer(R__b);
      mNegDaughter.Streamer(R__b);
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_ILambda(void *p) {
      return  p ? new(p) ::ILambda : new ::ILambda;
   }
   static void *newArray_ILambda(Long_t nElements, void *p) {
      return p ? new(p) ::ILambda[nElements] : new ::ILambda[nElements];
   }
   // Wrapper around operator delete
   static void delete_ILambda(void *p) {
      delete ((::ILambda*)p);
   }
   static void deleteArray_ILambda(void *p) {
      delete [] ((::ILambda*)p);
   }
   static void destruct_ILambda(void *p) {
      typedef ::ILambda current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_ILambda(TBuffer &buf, void *obj) {
      ((::ILambda*)obj)->::ILambda::Streamer(buf);
   }
} // end of namespace ROOT for class ::ILambda

//______________________________________________________________________________
void LambdaEfficiency::Streamer(TBuffer &R__b)
{
   // Stream an object of class LambdaEfficiency.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      {
         vector<TH1D*> &R__stl =  _h1d_eff;
         R__stl.clear();
         TClass *R__tcl1 = TBuffer::GetClass(typeid(class TH1D *));
         if (R__tcl1==0) {
            Error("_h1d_eff streamer","Missing the TClass object for class TH1D *!");
            return;
         }
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            TH1D* R__t;
            R__t = (TH1D*)R__b.ReadObjectAny(R__tcl1);
            R__stl.push_back(R__t);
         }
      }
      {
         vector<TF1*> &R__stl =  _tf1_eff;
         R__stl.clear();
         TClass *R__tcl1 = TBuffer::GetClass(typeid(class TF1 *));
         if (R__tcl1==0) {
            Error("_tf1_eff streamer","Missing the TClass object for class TF1 *!");
            return;
         }
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            TF1* R__t;
            R__t = (TF1*)R__b.ReadObjectAny(R__tcl1);
            R__stl.push_back(R__t);
         }
      }
      {
         vector<double> &R__stl =  _bin_edges;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            double R__t;
            R__b >> R__t;
            R__stl.push_back(R__t);
         }
      }
      R__b >> constantEfficiencySet;
      R__b >> constantEfficiency;
      R__b >> _mass;
      R__b >> h_eff_tof;
      R__b.CheckByteCount(R__s, R__c, LambdaEfficiency::IsA());
   } else {
      R__c = R__b.WriteVersion(LambdaEfficiency::IsA(), kTRUE);
      TObject::Streamer(R__b);
      {
         vector<TH1D*> &R__stl =  _h1d_eff;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<TH1D*>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      {
         vector<TF1*> &R__stl =  _tf1_eff;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<TF1*>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      {
         vector<double> &R__stl =  _bin_edges;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<double>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      R__b << constantEfficiencySet;
      R__b << constantEfficiency;
      R__b << _mass;
      R__b << (TObject*)h_eff_tof;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_LambdaEfficiency(void *p) {
      return  p ? new(p) ::LambdaEfficiency : new ::LambdaEfficiency;
   }
   static void *newArray_LambdaEfficiency(Long_t nElements, void *p) {
      return p ? new(p) ::LambdaEfficiency[nElements] : new ::LambdaEfficiency[nElements];
   }
   // Wrapper around operator delete
   static void delete_LambdaEfficiency(void *p) {
      delete ((::LambdaEfficiency*)p);
   }
   static void deleteArray_LambdaEfficiency(void *p) {
      delete [] ((::LambdaEfficiency*)p);
   }
   static void destruct_LambdaEfficiency(void *p) {
      typedef ::LambdaEfficiency current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_LambdaEfficiency(TBuffer &buf, void *obj) {
      ((::LambdaEfficiency*)obj)->::LambdaEfficiency::Streamer(buf);
   }
} // end of namespace ROOT for class ::LambdaEfficiency

//______________________________________________________________________________
void CumulantProfileContainer::Streamer(TBuffer &R__b)
{
   // Stream an object of class CumulantProfileContainer.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> _gr_N;
      R__b >> _gr_Q1;
      R__b >> _gr_Q2;
      R__b >> _gr_Q3;
      R__b >> _gr_Q4;
      R__b >> _gr_binned_Q1;
      R__b >> _gr_binned_Q2;
      R__b >> _gr_binned_Q3;
      R__b >> _gr_binned_Q4;
      R__b >> _gr_Q2_Q1;
      R__b >> _gr_Q3_Q2;
      R__b >> _gr_Q4_Q2;
      R__b >> _gr_binned_K1;
      R__b >> _gr_binned_K2;
      R__b >> _gr_binned_K3;
      R__b >> _gr_binned_K4;
      R__b >> _gr_K2_K1;
      R__b >> _gr_K3_K1;
      R__b >> _gr_K4_K1;
      {
         vector<TGraphErrors*> &R__stl =  _gr_vec;
         R__stl.clear();
         TClass *R__tcl1 = TBuffer::GetClass(typeid(class TGraphErrors *));
         if (R__tcl1==0) {
            Error("_gr_vec streamer","Missing the TClass object for class TGraphErrors *!");
            return;
         }
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            TGraphErrors* R__t;
            R__t = (TGraphErrors*)R__b.ReadObjectAny(R__tcl1);
            R__stl.push_back(R__t);
         }
      }
      {
         vector<TProfile*> &R__stl =  _prof_vec;
         R__stl.clear();
         TClass *R__tcl1 = TBuffer::GetClass(typeid(class TProfile *));
         if (R__tcl1==0) {
            Error("_prof_vec streamer","Missing the TClass object for class TProfile *!");
            return;
         }
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            TProfile* R__t;
            R__t = (TProfile*)R__b.ReadObjectAny(R__tcl1);
            R__stl.push_back(R__t);
         }
      }
      R__b.ReadStaticArray((double*)_m);
      R__b >> _qGraphsFilled;
      R__b.CheckByteCount(R__s, R__c, CumulantProfileContainer::IsA());
   } else {
      R__c = R__b.WriteVersion(CumulantProfileContainer::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << _gr_N;
      R__b << _gr_Q1;
      R__b << _gr_Q2;
      R__b << _gr_Q3;
      R__b << _gr_Q4;
      R__b << _gr_binned_Q1;
      R__b << _gr_binned_Q2;
      R__b << _gr_binned_Q3;
      R__b << _gr_binned_Q4;
      R__b << _gr_Q2_Q1;
      R__b << _gr_Q3_Q2;
      R__b << _gr_Q4_Q2;
      R__b << _gr_binned_K1;
      R__b << _gr_binned_K2;
      R__b << _gr_binned_K3;
      R__b << _gr_binned_K4;
      R__b << _gr_K2_K1;
      R__b << _gr_K3_K1;
      R__b << _gr_K4_K1;
      {
         vector<TGraphErrors*> &R__stl =  _gr_vec;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<TGraphErrors*>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      {
         vector<TProfile*> &R__stl =  _prof_vec;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<TProfile*>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      R__b.WriteArray(_m, 23);
      R__b << _qGraphsFilled;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_CumulantProfileContainer(void *p) {
      return  p ? new(p) ::CumulantProfileContainer : new ::CumulantProfileContainer;
   }
   static void *newArray_CumulantProfileContainer(Long_t nElements, void *p) {
      return p ? new(p) ::CumulantProfileContainer[nElements] : new ::CumulantProfileContainer[nElements];
   }
   // Wrapper around operator delete
   static void delete_CumulantProfileContainer(void *p) {
      delete ((::CumulantProfileContainer*)p);
   }
   static void deleteArray_CumulantProfileContainer(void *p) {
      delete [] ((::CumulantProfileContainer*)p);
   }
   static void destruct_CumulantProfileContainer(void *p) {
      typedef ::CumulantProfileContainer current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_CumulantProfileContainer(TBuffer &buf, void *obj) {
      ((::CumulantProfileContainer*)obj)->::CumulantProfileContainer::Streamer(buf);
   }
} // end of namespace ROOT for class ::CumulantProfileContainer

namespace ROOT {
   // Wrappers around operator new
   static void *new_FlucContainer(void *p) {
      return  p ? new(p) ::FlucContainer : new ::FlucContainer;
   }
   static void *newArray_FlucContainer(Long_t nElements, void *p) {
      return p ? new(p) ::FlucContainer[nElements] : new ::FlucContainer[nElements];
   }
   // Wrapper around operator delete
   static void delete_FlucContainer(void *p) {
      delete ((::FlucContainer*)p);
   }
   static void deleteArray_FlucContainer(void *p) {
      delete [] ((::FlucContainer*)p);
   }
   static void destruct_FlucContainer(void *p) {
      typedef ::FlucContainer current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::FlucContainer

//______________________________________________________________________________
void PileUpCorrection::Streamer(TBuffer &R__b)
{
   // Stream an object of class PileUpCorrection.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> hMult_true;
      R__b >> hMult;
      R__b >> inputMult;
      R__b >> hRM;
      R__b.ReadStaticArray((double*)C);
      R__b.ReadStaticArray((double*)cbwcC);
      R__b.ReadStaticArray((double*)mu);
      R__b.ReadStaticArray((double*)C_true);
      R__b.ReadStaticArray((double*)cbwcC_true);
      R__b.ReadStaticArray((double*)mu_true);
      R__b.ReadStaticArray((double*)centevent);
      R__b.ReadStaticArray((double*)C_cor);
      R__b.ReadStaticArray((double*)mu_cor);
      R__b.ReadStaticArray((double*)cbwcC_cor);
      R__b.CheckByteCount(R__s, R__c, PileUpCorrection::IsA());
   } else {
      R__c = R__b.WriteVersion(PileUpCorrection::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << (TObject*)hMult_true;
      R__b << (TObject*)hMult;
      R__b << (TObject*)inputMult;
      R__b << (TObject*)hRM;
      R__b.WriteArray((double*)C, 1500);
      R__b.WriteArray((double*)cbwcC, 45);
      R__b.WriteArray((double*)mu, 1500);
      R__b.WriteArray((double*)C_true, 1500);
      R__b.WriteArray((double*)cbwcC_true, 45);
      R__b.WriteArray((double*)mu_true, 1500);
      R__b.WriteArray(centevent, 9);
      R__b.WriteArray((double*)C_cor, 1500);
      R__b.WriteArray((double*)mu_cor, 1500);
      R__b.WriteArray((double*)cbwcC_cor, 1500);
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_PileUpCorrection(void *p) {
      return  p ? new(p) ::PileUpCorrection : new ::PileUpCorrection;
   }
   static void *newArray_PileUpCorrection(Long_t nElements, void *p) {
      return p ? new(p) ::PileUpCorrection[nElements] : new ::PileUpCorrection[nElements];
   }
   // Wrapper around operator delete
   static void delete_PileUpCorrection(void *p) {
      delete ((::PileUpCorrection*)p);
   }
   static void deleteArray_PileUpCorrection(void *p) {
      delete [] ((::PileUpCorrection*)p);
   }
   static void destruct_PileUpCorrection(void *p) {
      typedef ::PileUpCorrection current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_PileUpCorrection(TBuffer &buf, void *obj) {
      ((::PileUpCorrection*)obj)->::PileUpCorrection::Streamer(buf);
   }
} // end of namespace ROOT for class ::PileUpCorrection

namespace ROOT {
   static TClass *vectorlEunsignedsPintgR_Dictionary();
   static void vectorlEunsignedsPintgR_TClassManip(TClass*);
   static void *new_vectorlEunsignedsPintgR(void *p = 0);
   static void *newArray_vectorlEunsignedsPintgR(Long_t size, void *p);
   static void delete_vectorlEunsignedsPintgR(void *p);
   static void deleteArray_vectorlEunsignedsPintgR(void *p);
   static void destruct_vectorlEunsignedsPintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<unsigned int>*)
   {
      vector<unsigned int> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<unsigned int>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<unsigned int>", -2, "vector", 386,
                  typeid(vector<unsigned int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEunsignedsPintgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<unsigned int>) );
      instance.SetNew(&new_vectorlEunsignedsPintgR);
      instance.SetNewArray(&newArray_vectorlEunsignedsPintgR);
      instance.SetDelete(&delete_vectorlEunsignedsPintgR);
      instance.SetDeleteArray(&deleteArray_vectorlEunsignedsPintgR);
      instance.SetDestructor(&destruct_vectorlEunsignedsPintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<unsigned int> >()));

      ::ROOT::AddClassAlternate("vector<unsigned int>","std::vector<unsigned int, std::allocator<unsigned int> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<unsigned int>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEunsignedsPintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<unsigned int>*)0x0)->GetClass();
      vectorlEunsignedsPintgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEunsignedsPintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEunsignedsPintgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<unsigned int> : new vector<unsigned int>;
   }
   static void *newArray_vectorlEunsignedsPintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<unsigned int>[nElements] : new vector<unsigned int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEunsignedsPintgR(void *p) {
      delete ((vector<unsigned int>*)p);
   }
   static void deleteArray_vectorlEunsignedsPintgR(void *p) {
      delete [] ((vector<unsigned int>*)p);
   }
   static void destruct_vectorlEunsignedsPintgR(void *p) {
      typedef vector<unsigned int> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<unsigned int>

namespace ROOT {
   static TClass *vectorlEdoublegR_Dictionary();
   static void vectorlEdoublegR_TClassManip(TClass*);
   static void *new_vectorlEdoublegR(void *p = 0);
   static void *newArray_vectorlEdoublegR(Long_t size, void *p);
   static void delete_vectorlEdoublegR(void *p);
   static void deleteArray_vectorlEdoublegR(void *p);
   static void destruct_vectorlEdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<double>*)
   {
      vector<double> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<double>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<double>", -2, "vector", 386,
                  typeid(vector<double>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEdoublegR_Dictionary, isa_proxy, 0,
                  sizeof(vector<double>) );
      instance.SetNew(&new_vectorlEdoublegR);
      instance.SetNewArray(&newArray_vectorlEdoublegR);
      instance.SetDelete(&delete_vectorlEdoublegR);
      instance.SetDeleteArray(&deleteArray_vectorlEdoublegR);
      instance.SetDestructor(&destruct_vectorlEdoublegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<double> >()));

      ::ROOT::AddClassAlternate("vector<double>","std::vector<double, std::allocator<double> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<double>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEdoublegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<double>*)0x0)->GetClass();
      vectorlEdoublegR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEdoublegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEdoublegR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<double> : new vector<double>;
   }
   static void *newArray_vectorlEdoublegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<double>[nElements] : new vector<double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEdoublegR(void *p) {
      delete ((vector<double>*)p);
   }
   static void deleteArray_vectorlEdoublegR(void *p) {
      delete [] ((vector<double>*)p);
   }
   static void destruct_vectorlEdoublegR(void *p) {
      typedef vector<double> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<double>

namespace ROOT {
   static TClass *vectorlETProfilemUgR_Dictionary();
   static void vectorlETProfilemUgR_TClassManip(TClass*);
   static void *new_vectorlETProfilemUgR(void *p = 0);
   static void *newArray_vectorlETProfilemUgR(Long_t size, void *p);
   static void delete_vectorlETProfilemUgR(void *p);
   static void deleteArray_vectorlETProfilemUgR(void *p);
   static void destruct_vectorlETProfilemUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TProfile*>*)
   {
      vector<TProfile*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TProfile*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TProfile*>", -2, "vector", 386,
                  typeid(vector<TProfile*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETProfilemUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<TProfile*>) );
      instance.SetNew(&new_vectorlETProfilemUgR);
      instance.SetNewArray(&newArray_vectorlETProfilemUgR);
      instance.SetDelete(&delete_vectorlETProfilemUgR);
      instance.SetDeleteArray(&deleteArray_vectorlETProfilemUgR);
      instance.SetDestructor(&destruct_vectorlETProfilemUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TProfile*> >()));

      ::ROOT::AddClassAlternate("vector<TProfile*>","std::vector<TProfile*, std::allocator<TProfile*> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<TProfile*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETProfilemUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<TProfile*>*)0x0)->GetClass();
      vectorlETProfilemUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETProfilemUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETProfilemUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TProfile*> : new vector<TProfile*>;
   }
   static void *newArray_vectorlETProfilemUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TProfile*>[nElements] : new vector<TProfile*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETProfilemUgR(void *p) {
      delete ((vector<TProfile*>*)p);
   }
   static void deleteArray_vectorlETProfilemUgR(void *p) {
      delete [] ((vector<TProfile*>*)p);
   }
   static void destruct_vectorlETProfilemUgR(void *p) {
      typedef vector<TProfile*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<TProfile*>

namespace ROOT {
   static TClass *vectorlETH1DmUgR_Dictionary();
   static void vectorlETH1DmUgR_TClassManip(TClass*);
   static void *new_vectorlETH1DmUgR(void *p = 0);
   static void *newArray_vectorlETH1DmUgR(Long_t size, void *p);
   static void delete_vectorlETH1DmUgR(void *p);
   static void deleteArray_vectorlETH1DmUgR(void *p);
   static void destruct_vectorlETH1DmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TH1D*>*)
   {
      vector<TH1D*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TH1D*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TH1D*>", -2, "vector", 386,
                  typeid(vector<TH1D*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETH1DmUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<TH1D*>) );
      instance.SetNew(&new_vectorlETH1DmUgR);
      instance.SetNewArray(&newArray_vectorlETH1DmUgR);
      instance.SetDelete(&delete_vectorlETH1DmUgR);
      instance.SetDeleteArray(&deleteArray_vectorlETH1DmUgR);
      instance.SetDestructor(&destruct_vectorlETH1DmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TH1D*> >()));

      ::ROOT::AddClassAlternate("vector<TH1D*>","std::vector<TH1D*, std::allocator<TH1D*> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<TH1D*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETH1DmUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<TH1D*>*)0x0)->GetClass();
      vectorlETH1DmUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETH1DmUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETH1DmUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TH1D*> : new vector<TH1D*>;
   }
   static void *newArray_vectorlETH1DmUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TH1D*>[nElements] : new vector<TH1D*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETH1DmUgR(void *p) {
      delete ((vector<TH1D*>*)p);
   }
   static void deleteArray_vectorlETH1DmUgR(void *p) {
      delete [] ((vector<TH1D*>*)p);
   }
   static void destruct_vectorlETH1DmUgR(void *p) {
      typedef vector<TH1D*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<TH1D*>

namespace ROOT {
   static TClass *vectorlETGraphErrorsmUgR_Dictionary();
   static void vectorlETGraphErrorsmUgR_TClassManip(TClass*);
   static void *new_vectorlETGraphErrorsmUgR(void *p = 0);
   static void *newArray_vectorlETGraphErrorsmUgR(Long_t size, void *p);
   static void delete_vectorlETGraphErrorsmUgR(void *p);
   static void deleteArray_vectorlETGraphErrorsmUgR(void *p);
   static void destruct_vectorlETGraphErrorsmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TGraphErrors*>*)
   {
      vector<TGraphErrors*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TGraphErrors*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TGraphErrors*>", -2, "vector", 386,
                  typeid(vector<TGraphErrors*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETGraphErrorsmUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<TGraphErrors*>) );
      instance.SetNew(&new_vectorlETGraphErrorsmUgR);
      instance.SetNewArray(&newArray_vectorlETGraphErrorsmUgR);
      instance.SetDelete(&delete_vectorlETGraphErrorsmUgR);
      instance.SetDeleteArray(&deleteArray_vectorlETGraphErrorsmUgR);
      instance.SetDestructor(&destruct_vectorlETGraphErrorsmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TGraphErrors*> >()));

      ::ROOT::AddClassAlternate("vector<TGraphErrors*>","std::vector<TGraphErrors*, std::allocator<TGraphErrors*> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<TGraphErrors*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETGraphErrorsmUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<TGraphErrors*>*)0x0)->GetClass();
      vectorlETGraphErrorsmUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETGraphErrorsmUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETGraphErrorsmUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TGraphErrors*> : new vector<TGraphErrors*>;
   }
   static void *newArray_vectorlETGraphErrorsmUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TGraphErrors*>[nElements] : new vector<TGraphErrors*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETGraphErrorsmUgR(void *p) {
      delete ((vector<TGraphErrors*>*)p);
   }
   static void deleteArray_vectorlETGraphErrorsmUgR(void *p) {
      delete [] ((vector<TGraphErrors*>*)p);
   }
   static void destruct_vectorlETGraphErrorsmUgR(void *p) {
      typedef vector<TGraphErrors*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<TGraphErrors*>

namespace ROOT {
   static TClass *vectorlETF1mUgR_Dictionary();
   static void vectorlETF1mUgR_TClassManip(TClass*);
   static void *new_vectorlETF1mUgR(void *p = 0);
   static void *newArray_vectorlETF1mUgR(Long_t size, void *p);
   static void delete_vectorlETF1mUgR(void *p);
   static void deleteArray_vectorlETF1mUgR(void *p);
   static void destruct_vectorlETF1mUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TF1*>*)
   {
      vector<TF1*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TF1*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TF1*>", -2, "vector", 386,
                  typeid(vector<TF1*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETF1mUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<TF1*>) );
      instance.SetNew(&new_vectorlETF1mUgR);
      instance.SetNewArray(&newArray_vectorlETF1mUgR);
      instance.SetDelete(&delete_vectorlETF1mUgR);
      instance.SetDeleteArray(&deleteArray_vectorlETF1mUgR);
      instance.SetDestructor(&destruct_vectorlETF1mUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TF1*> >()));

      ::ROOT::AddClassAlternate("vector<TF1*>","std::vector<TF1*, std::allocator<TF1*> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<TF1*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETF1mUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<TF1*>*)0x0)->GetClass();
      vectorlETF1mUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETF1mUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETF1mUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TF1*> : new vector<TF1*>;
   }
   static void *newArray_vectorlETF1mUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TF1*>[nElements] : new vector<TF1*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETF1mUgR(void *p) {
      delete ((vector<TF1*>*)p);
   }
   static void deleteArray_vectorlETF1mUgR(void *p) {
      delete [] ((vector<TF1*>*)p);
   }
   static void destruct_vectorlETF1mUgR(void *p) {
      typedef vector<TF1*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<TF1*>

namespace {
  void TriggerDictionaryInitialization_dict_Impl() {
    static const char* headers[] = {
"Classes/IEvent.h",
"Classes/ILambda.h",
"Classes/ITrack.h",
"Classes/LambdaEfficiency.h",
"Classes/MomentFunctions.h",
"Classes/CumulantProfileContainer.h",
"Classes/FlucContainer.h",
"Classes/PileUpCorrection.h",
"Classes/analysisUtil.h",
0
    };
    static const char* includePaths[] = {
"/home/jonathan/Products/root/include/",
"/home/jonathan/Documents/LambdaFluctuationAnalyses/3GeV/FluctuationLambdaEbE_FxtMult3/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "dict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(my event)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$Classes/IEvent.h")))  IEvent;
class __attribute__((annotate("$clingAutoload$Classes/ILambda.h")))  ITrack;
class __attribute__((annotate("$clingAutoload$Classes/ILambda.h")))  ILambda;
class __attribute__((annotate("$clingAutoload$Classes/LambdaEfficiency.h")))  LambdaEfficiency;
class __attribute__((annotate("$clingAutoload$Classes/CumulantProfileContainer.h")))  CumulantProfileContainer;
class __attribute__((annotate("$clingAutoload$Classes/FlucContainer.h")))  FlucContainer;
class __attribute__((annotate("$clingAutoload$Classes/PileUpCorrection.h")))  PileUpCorrection;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "dict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "Classes/IEvent.h"
#include "Classes/ILambda.h"
#include "Classes/ITrack.h"
#include "Classes/LambdaEfficiency.h"
#include "Classes/MomentFunctions.h"
#include "Classes/CumulantProfileContainer.h"
#include "Classes/FlucContainer.h"
#include "Classes/PileUpCorrection.h"
#include "Classes/analysisUtil.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"CumulantProfileContainer", payloadCode, "@",
"FlucContainer", payloadCode, "@",
"IEvent", payloadCode, "@",
"ILambda", payloadCode, "@",
"ITrack", payloadCode, "@",
"LambdaEfficiency", payloadCode, "@",
"PileUpCorrection", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("dict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_dict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_dict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_dict() {
  TriggerDictionaryInitialization_dict_Impl();
}
