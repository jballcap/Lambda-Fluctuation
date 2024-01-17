#ifndef EVENTLOOP_H
#define EVENTLOOP_H

#include "TObject.h"
#include "InputParameterList.h"
#include <vector>

class TChain;
class CumulantProfileContainer;
class LambdaEfficiency;
class TRandom3;

int EventLoop(
	      TChain * tc,
	      long int nentries,
	      InputParameterList & pl,
	      CumulantProfileContainer * cpc,
	      LambdaEfficiency * eff
	      );


int EventLoopSystematic(
			TChain * tc,
			long int nentries,
			InputParameterList & pl,
			vector<CumulantProfileContainer*> &cpc,
			LambdaEfficiency * eff
			);


int EventLoopBootstrap(
		       TChain * tc,
		       long int nentries,
		       InputParameterList & pl,
		       CumulantProfileContainer* cpc,
		       std::vector<CumulantProfileContainer*> cpc_vec,
		       LambdaEfficiency * eff,
		       TRandom3 * rand
		       );

int EventLoopSimPoisson(
			long int nentries_perCentBin,
			CumulantProfileContainer * cpc,
			TRandom3 * rand,
			int minCent,
			int maxCent,
			double eff
			);


#endif
