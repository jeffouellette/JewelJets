CXX=g++
#CXXFLAGS=-O3 -g -Wall src/HepMC2TTree.cxx -o bin/HepMC2TTree `root-config --cflags --libs` -I$(HEPMC_INCLUDE_DIR) $(FASTJET_INCLUDE_DIR) 
CXXFLAGS=-O3 -g -Wall src/Pythia_HepMC2TTree.cxx -o bin/Pythia_HepMC2TTree `root-config --cflags --libs` -I$(HEPMC_INCLUDE_DIR) $(FASTJET_INCLUDE_DIR) 


#Pythia_HepMC2TTree.cxx
#LDFLAGS=-Wl,-rpath,`root-config --libdir` `root-config --glibs` -lEG -L$(HEPMC_LIBRARY) -lHepMC -L$(FASTJET_LIBRARY) -lfastjet -lRecursiveTools


FASTJET=`fastjet-config --cxxflags --libs --plugins --runpath`

HepMC2TTree: src/HepMC2TTree.cxx
	$(CXX) $(CXXFLAGS) $(FASTJET) -lRecursiveTools -L/sphenix/user/ahmed51/JEWEL/HepMC-2.06.09-build/lib/ -lHepMC -lEG
clean :
	rm -rf lib/* bin/*
