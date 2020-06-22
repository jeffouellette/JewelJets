CXX=g++
CXXFLAGS=-O3 -g -Wall `root-config --cflags` -I$(HEPMC_INCLUDE_DIR) -I$(FASTJET_INCLUDE_DIR)
LDFLAGS=-Wl,-rpath,`root-config --libdir` `root-config --glibs` -lEG -L$(HEPMC_LIBRARY) -lHepMC -L$(FASTJET_LIBRARY) -lfastjet

HepMC2TTree: src/HepMC2TTree.cxx
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $< -o bin/HepMC2TTree

clean :
	rm -rf lib/* bin/*
