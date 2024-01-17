
#CXX = g++
CXX = $(shell root-config --cxx)
ROOTFLAGS = $(shell root-config --cflags)


#This is a modification of the previous make file, it includes new classes

CFLAGS = ${ROOTFLAGS} -g -IClasses

ROOTLIBS = $(shell root-config --libs)


all: AnalyzeFemtoDst.bin

AnalyzeFemtoDst.bin: AnalyzeFemtoDst.o dict.o IEvent.o ILambda.o ITrack.o LambdaEfficiency.o  MomentFunctions.o CumulantProfileContainer.o FlucContainer.o PileUpCorrection.o  analysisUtil.o
	${CXX} ${CFLAGS} $^ -o$@ ${ROOTLIBS}

dict.C: Classes/IEvent.h Classes/ILambda.h Classes/ITrack.h Classes/LambdaEfficiency.h  Classes/MomentFunctions.h  Classes/CumulantProfileContainer.h   Classes/FlucContainer.h  Classes/PileUpCorrection.h Classes/analysisUtil.h
	rootcint -f $@ -c -p Classes/IEvent.h Classes/ILambda.h Classes/ITrack.h Classes/LambdaEfficiency.h  Classes/MomentFunctions.h Classes/CumulantProfileContainer.h Classes/FlucContainer.h  Classes/PileUpCorrection.h  Classes/analysisUtil.h

dict.o: dict.C
	${CXX} -fPIC  -c ${CFLAGS} $< -o $@

AnalyzeFemtoDst.o: AnalyzeFemtoDst.cxx
	${CXX} -fPIC  -c ${CFLAGS} $< -o $@

%.o: Classes/%.cxx Classes/%.h
	${CXX} -fPIC -c ${CFLAGS} $< -o $@

%.so: Classes/%.cxx Classes/%.h
	rootcint -f 

clean:
	rm -vf *.so *.o *.d AnalyzeFemtoDst.bin dict.C
