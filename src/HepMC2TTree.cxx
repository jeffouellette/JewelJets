#ifndef __HepMC2TTree_CXX__
#define __HepMC2TTree_CXX__

#include "HepMC/GenEvent.h"
#include "HepMC/IO_GenEvent.h"
#include "HepMC/HeavyIon.h"

#include "TFile.h"
#include "TTree.h"
#include "TDatabasePDG.h"
#include "TParticlePDG.h"

// FastJet include and namespace.
#include "fastjet/ClusterSequence.hh"

#include <iostream>

using namespace std;
//using namespace HepMC;
//using namespace fastjet;

int main (int argc, char** argv) {

  if (argc < 3) {
    cout << "Must specify in and out files, exiting" << endl;
    return 1;
  }

  const char* inFileName = argv[1];
  cout << "inFileName = " << inFileName << endl;
  const char* outFileName = argv[2];
  cout << "outFileName = " << outFileName << endl;
  

  HepMC::IO_GenEvent* inFile = new HepMC::IO_GenEvent (inFileName, std::ios::in); 

  TFile* outFile = new TFile (outFileName, "recreate");
  TTree* outTree = new TTree ("tree", "JEWELs don't grow on trees :(");

  int part_n = 0;
  float part_pt[10000];
  float part_eta[10000];
  float part_phi[10000];
  float part_e[10000];
  int part_pdgid[10000];
  int part_barcode[10000];
  int part_charge[10000];

  int akt2_jet_n = 0;
  float akt2_jet_pt[100];
  float akt2_jet_eta[100];
  float akt2_jet_phi[100];
  float akt2_jet_e[100];
  int akt3_jet_n = 0;
  float akt3_jet_pt[100];
  float akt3_jet_eta[100];
  float akt3_jet_phi[100];
  float akt3_jet_e[100];
  int akt4_jet_n = 0;
  float akt4_jet_pt[100];
  float akt4_jet_eta[100];
  float akt4_jet_phi[100];
  float akt4_jet_e[100];

  outTree->Branch ("part_n",        &part_n,        "part_n/I");
  outTree->Branch ("part_pt",       &part_pt,       "part_pt[part_n]/F");
  outTree->Branch ("part_eta",      &part_eta,      "part_eta[part_n]/F");
  outTree->Branch ("part_phi",      &part_phi,      "part_phi[part_n]/F");
  outTree->Branch ("part_e",        &part_e,        "part_e[part_n]/F");
  outTree->Branch ("part_pdgid",    &part_pdgid,    "part_pdgid[part_n]/I");
  outTree->Branch ("part_barcode",  part_barcode,   "part_barcode[part_n]/I");
  outTree->Branch ("part_charge",   &part_charge,   "part_charge[part_n]/I");

  outTree->Branch ("akt2_jet_n",    &akt2_jet_n,    "akt2_jet_n/I");
  outTree->Branch ("akt2_jet_pt",   &akt2_jet_pt,   "akt2_jet_pt[akt2_jet_n]/F");
  outTree->Branch ("akt2_jet_eta",  &akt2_jet_eta,  "akt2_jet_eta[akt2_jet_n]/F");
  outTree->Branch ("akt2_jet_phi",  &akt2_jet_phi,  "akt2_jet_phi[akt2_jet_n]/F");
  outTree->Branch ("akt2_jet_e",    &akt2_jet_e,    "akt2_jet_e[akt2_jet_n]/F");
  outTree->Branch ("akt3_jet_n",    &akt3_jet_n,    "akt3_jet_n/I");
  outTree->Branch ("akt3_jet_pt",   &akt3_jet_pt,   "akt3_jet_pt[akt3_jet_n]/F");
  outTree->Branch ("akt3_jet_eta",  &akt3_jet_eta,  "akt3_jet_eta[akt3_jet_n]/F");
  outTree->Branch ("akt3_jet_phi",  &akt3_jet_phi,  "akt3_jet_phi[akt3_jet_n]/F");
  outTree->Branch ("akt3_jet_e",    &akt3_jet_e,    "akt3_jet_e[akt3_jet_n]/F");
  outTree->Branch ("akt4_jet_n",    &akt4_jet_n,    "akt4_jet_n/I");
  outTree->Branch ("akt4_jet_pt",   &akt4_jet_pt,   "akt4_jet_pt[akt4_jet_n]/F");
  outTree->Branch ("akt4_jet_eta",  &akt4_jet_eta,  "akt4_jet_eta[akt4_jet_n]/F");
  outTree->Branch ("akt4_jet_phi",  &akt4_jet_phi,  "akt4_jet_phi[akt4_jet_n]/F");
  outTree->Branch ("akt4_jet_e",    &akt4_jet_e,    "akt4_jet_e[akt4_jet_n]/F");

  const float etaMax = 4.9;
  const float minJetPt = 10;

  fastjet::JetDefinition antiKt2 (fastjet::antikt_algorithm, 0.2);
  fastjet::JetDefinition antiKt3 (fastjet::antikt_algorithm, 0.3);
  fastjet::JetDefinition antiKt4 (fastjet::antikt_algorithm, 0.4);

  TDatabasePDG* pdgData = new TDatabasePDG ();

  int iEvt = 0;
  HepMC::GenEvent* event = inFile->read_next_event ();
  while (event) {

    vector <fastjet::PseudoJet> particles;

    for (HepMC::GenEvent::particle_iterator part_iterator = event->particles_begin (); part_iterator != event->particles_end (); part_iterator++) {
      HepMC::GenParticle* part = *(part_iterator);

      if (part->status () != 1)
        continue;

      HepMC::FourVector mom = part->momentum ();     
      if (fabs (mom.pseudoRapidity ()) > etaMax)
        continue;

      particles.push_back (fastjet::PseudoJet (mom.px (), mom.py (), mom.pz (), mom.e ())); 
    }

    fastjet::ClusterSequence clusterSeqAkt2 (particles, antiKt2);
    vector<fastjet::PseudoJet> sortedAkt2Jets = fastjet::sorted_by_pt (clusterSeqAkt2.inclusive_jets ());
    fastjet::ClusterSequence clusterSeqAkt3 (particles, antiKt3);
    vector<fastjet::PseudoJet> sortedAkt3Jets = fastjet::sorted_by_pt (clusterSeqAkt3.inclusive_jets ());
    fastjet::ClusterSequence clusterSeqAkt4 (particles, antiKt4);
    vector<fastjet::PseudoJet> sortedAkt4Jets = fastjet::sorted_by_pt (clusterSeqAkt4.inclusive_jets ());

    akt2_jet_n = 0;
    for (fastjet::PseudoJet jet : sortedAkt2Jets) {
      if (jet.perp () < minJetPt || fabs (jet.pseudorapidity ()) > etaMax || akt2_jet_n >= 100)
        continue;

      akt2_jet_pt[akt2_jet_n] = jet.perp ();
      akt2_jet_eta[akt2_jet_n] = jet.pseudorapidity ();
      akt2_jet_phi[akt2_jet_n] = jet.phi ();
      akt2_jet_e[akt2_jet_n] = jet.e ();
      akt2_jet_n++;
    }
    akt3_jet_n = 0;
    for (fastjet::PseudoJet jet : sortedAkt3Jets) {
      if (jet.perp () < minJetPt || fabs (jet.pseudorapidity ()) > etaMax || akt3_jet_n >= 100)
        continue;

      akt3_jet_pt[akt3_jet_n] = jet.perp ();
      akt3_jet_eta[akt3_jet_n] = jet.pseudorapidity ();
      akt3_jet_phi[akt3_jet_n] = jet.phi ();
      akt3_jet_e[akt3_jet_n] = jet.e ();
      akt3_jet_n++;
    }
    akt4_jet_n = 0;
    for (fastjet::PseudoJet jet : sortedAkt4Jets) {
      if (jet.perp () < minJetPt || fabs (jet.pseudorapidity ()) > etaMax || akt4_jet_n >= 100)
        continue;

      akt4_jet_pt[akt4_jet_n] = jet.perp ();
      akt4_jet_eta[akt4_jet_n] = jet.pseudorapidity ();
      akt4_jet_phi[akt4_jet_n] = jet.phi ();
      akt4_jet_e[akt4_jet_n] = jet.e ();
      akt4_jet_n++;
    }

    part_n = 0;
    for (HepMC::GenEvent::particle_iterator part_iterator = event->particles_begin (); part_iterator != event->particles_end (); part_iterator++) {
      HepMC::GenParticle* part = *(part_iterator);

      if (part->status () != 1)
        continue;

      HepMC::FourVector mom = part->momentum ();

      part_pt[part_n] = mom.perp ();
      part_eta[part_n] = mom.pseudoRapidity ();
      part_phi[part_n] = mom.phi ();
      part_e[part_n] = mom.e ();
      part_pdgid[part_n] = part->pdg_id ();
      part_barcode[part_n] = part->barcode ();
      part_charge[part_n] = pdgData->GetParticle (part->pdg_id ())->Charge () / 3;
      part_n++;
    }

    outTree->Fill ();

    event = inFile->read_next_event ();
    iEvt++;
  }
  cout << "Events processed: " << iEvt << endl;

  outTree->Write ("", TObject::kOverwrite);
  outFile->Close ();

  return 0;
}

#endif
