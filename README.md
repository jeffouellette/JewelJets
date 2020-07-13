# JewelJets

Steering code + TTree converter for JEWEL jet simulations. Based on most recent JEWEL, 2.2.0, which is publicly available courtesy of the authors at https://jewel.hepforge.org/

TTree converter requires HEPMC (version 2, not 3) and FastJet. fj-contrib is also recommended in case you want to do some constituent subtraction.

The most recent development paper JEWEL at the time of writing can be found at http://arxiv.org/abs/arXiv:1707.01539

To run a JEWEL config, use `jewel-2.2.0-simple parameterFiles/params.jets_in_medium.dat`

To convert the output to a TTree and run jet clustering, make the content in src and run `./bin/HepMC2TTree myfile.hepmc myfile.root`
