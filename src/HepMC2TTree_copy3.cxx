#ifndef __HepMC2TTree_CXX__
#define __HepMC2TTree_CXX__

#include "HepMC/GenEvent.h"
#include "HepMC/IO_GenEvent.h"
#include "HepMC/HeavyIon.h"

#include "TMath.h"
#include "TLorentzVector.h"
#include "TFile.h"
#include "TTree.h"
#include "TDatabasePDG.h"
#include "TParticlePDG.h"


#include "fastjet/ClusterSequence.hh"
#include "fastjet/PseudoJet.hh"
#include "fastjet/contrib/SoftDrop.hh"
#include <iostream>

using namespace std;


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
int part_status[10000];

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
int akt6_jet_n = 0;
float akt6_jet_pt[100];
float akt6_jet_eta[100];
float akt6_jet_phi[100];
float akt6_jet_e[100];
int akt8_jet_n = 0;
float akt8_jet_pt[100];
float akt8_jet_eta[100];
float akt8_jet_phi[100];
float akt8_jet_e[100];
int akt1_jet_n = 0;
float akt1_jet_pt[100];
float akt1_jet_eta[100];
float akt1_jet_phi[100];
float akt1_jet_e[100];

int akt2_jet_n_4MomSub = 0;
float akt2_jet_pt_4MomSub[100];
float akt2_jet_eta_4MomSub[100];
float akt2_jet_phi_4MomSub[100];
float akt2_jet_e_4MomSub[100];
float akt2_jet_zg_4MomSub[100];
float akt2_jet_thetag_4MomSub[100];
float akt2_jet_mu_4MomSub[100];

int akt3_jet_n_4MomSub = 0;
float akt3_jet_pt_4MomSub[100];
float akt3_jet_eta_4MomSub[100];
float akt3_jet_phi_4MomSub[100];
float akt3_jet_e_4MomSub[100];
float akt3_jet_zg_4MomSub[100];
float akt3_jet_thetag_4MomSub[100];
float akt3_jet_mu_4MomSub[100];

int akt4_jet_n_4MomSub = 0;
float akt4_jet_pt_4MomSub[100];
float akt4_jet_eta_4MomSub[100];
float akt4_jet_phi_4MomSub[100];
float akt4_jet_e_4MomSub[100];
float akt4_jet_zg_4MomSub[100];
float akt4_jet_thetag_4MomSub[100];
float akt4_jet_mu_4MomSub[100];

int akt6_jet_n_4MomSub = 0;
float akt6_jet_pt_4MomSub[100];
float akt6_jet_eta_4MomSub[100];
float akt6_jet_phi_4MomSub[100];
float akt6_jet_e_4MomSub[100];
float akt6_jet_zg_4MomSub[100];
float akt6_jet_thetag_4MomSub[100];
float akt6_jet_mu_4MomSub[100];

int akt8_jet_n_4MomSub = 0;
float akt8_jet_pt_4MomSub[100];
float akt8_jet_eta_4MomSub[100];
float akt8_jet_phi_4MomSub[100];
float akt8_jet_e_4MomSub[100];
float akt8_jet_zg_4MomSub[100];
float akt8_jet_thetag_4MomSub[100];
float akt8_jet_mu_4MomSub[100];

int akt1_jet_n_4MomSub = 0;
float akt1_jet_pt_4MomSub[100];
float akt1_jet_eta_4MomSub[100];
float akt1_jet_phi_4MomSub[100];
float akt1_jet_e_4MomSub[100];
float akt1_jet_zg_4MomSub[100];
float akt1_jet_thetag_4MomSub[100];
float akt1_jet_mu_4MomSub[100];
/*
int akt4_jet_n_GridSub1 = 0;
float akt4_jet_pt_GridSub1[100];
float akt4_jet_eta_GridSub1[100];
float akt4_jet_phi_GridSub1[100];
float akt4_jet_e_GridSub1[100];
*/
int akt4_jet_n_GridSub2 = 0;
float akt4_jet_pt_GridSub2[100];
float akt4_jet_eta_GridSub2[100];
float akt4_jet_phi_GridSub2[100];
float akt4_jet_e_GridSub2[100];

outTree->Branch ("part_n",        &part_n,        "part_n/I");
outTree->Branch ("part_pt",       &part_pt,       "part_pt[part_n]/F");
outTree->Branch ("part_eta",      &part_eta,      "part_eta[part_n]/F");
outTree->Branch ("part_phi",      &part_phi,      "part_phi[part_n]/F");
outTree->Branch ("part_e",        &part_e,        "part_e[part_n]/F");
outTree->Branch ("part_pdgid",    &part_pdgid,    "part_pdgid[part_n]/I");
outTree->Branch ("part_barcode",  part_barcode,   "part_barcode[part_n]/I");
outTree->Branch ("part_charge",   &part_charge,   "part_charge[part_n]/I");
outTree->Branch ("part_status",   &part_status,   "part_status[part_n]/I");

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

outTree->Branch ("akt6_jet_n",    &akt6_jet_n,    "akt6_jet_n/I");
outTree->Branch ("akt6_jet_pt",   &akt6_jet_pt,   "akt6_jet_pt[akt6_jet_n]/F");
outTree->Branch ("akt6_jet_eta",  &akt6_jet_eta,  "akt6_jet_eta[akt6_jet_n]/F");
outTree->Branch ("akt6_jet_phi",  &akt6_jet_phi,  "akt6_jet_phi[akt6_jet_n]/F");
outTree->Branch ("akt6_jet_e",    &akt6_jet_e,    "akt6_jet_e[akt6_jet_n]/F");

outTree->Branch ("akt8_jet_n",    &akt8_jet_n,    "akt8_jet_n/I");
outTree->Branch ("akt8_jet_pt",   &akt8_jet_pt,   "akt8_jet_pt[akt8_jet_n]/F");
outTree->Branch ("akt8_jet_eta",  &akt8_jet_eta,  "akt8_jet_eta[akt8_jet_n]/F");
outTree->Branch ("akt8_jet_phi",  &akt8_jet_phi,  "akt8_jet_phi[akt8_jet_n]/F");
outTree->Branch ("akt8_jet_e",    &akt8_jet_e,    "akt8_jet_e[akt8_jet_n]/F");

outTree->Branch ("akt1_jet_n",    &akt1_jet_n,    "akt1_jet_n/I");
outTree->Branch ("akt1_jet_pt",   &akt1_jet_pt,   "akt1_jet_pt[akt1_jet_n]/F");
outTree->Branch ("akt1_jet_eta",  &akt1_jet_eta,  "akt1_jet_eta[akt1_jet_n]/F");
outTree->Branch ("akt1_jet_phi",  &akt1_jet_phi,  "akt1_jet_phi[akt1_jet_n]/F");
outTree->Branch ("akt1_jet_e",    &akt1_jet_e,    "akt1_jet_e[akt1_jet_n]/F");

outTree->Branch ("akt2_jet_n_4MomSub",       &akt2_jet_n_4MomSub,       "akt2_jet_n_4MomSub/I");
outTree->Branch ("akt2_jet_pt_4MomSub",      &akt2_jet_pt_4MomSub,      "akt2_jet_pt_4MomSub[akt2_jet_n_4MomSub]/F");
outTree->Branch ("akt2_jet_eta_4MomSub",     &akt2_jet_eta_4MomSub,     "akt2_jet_eta_4MomSub[akt2_jet_n_4MomSub]/F");
outTree->Branch ("akt2_jet_phi_4MomSub",     &akt2_jet_phi_4MomSub,     "akt2_jet_phi_4MomSub[akt2_jet_n_4MomSub]/F");
outTree->Branch ("akt2_jet_e_4MomSub",       &akt2_jet_e_4MomSub,       "akt2_jet_e_4MomSub[akt2_jet_n_4MomSub]/F");
outTree->Branch ("akt2_jet_zg_4MomSub",      &akt2_jet_zg_4MomSub,      "akt2_jet_zg_4MomSub[akt2_jet_n_4MomSub]/F");
outTree->Branch ("akt2_jet_thetag_4MomSub",  &akt2_jet_thetag_4MomSub,  "akt2_jet_thetag_4MomSub[akt2_jet_n_4MomSub]/F");
outTree->Branch ("akt2_jet_mu_4MomSub",      &akt2_jet_mu_4MomSub,      "akt2_jet_mu_4MomSub[akt2_jet_n_4MomSub]/F");

outTree->Branch ("akt3_jet_n_4MomSub",       &akt3_jet_n_4MomSub,       "akt3_jet_n_4MomSub/I");
outTree->Branch ("akt3_jet_pt_4MomSub",      &akt3_jet_pt_4MomSub,      "akt3_jet_pt_4MomSub[akt3_jet_n_4MomSub]/F");
outTree->Branch ("akt3_jet_eta_4MomSub",     &akt3_jet_eta_4MomSub,     "akt3_jet_eta_4MomSub[akt3_jet_n_4MomSub]/F");
outTree->Branch ("akt3_jet_phi_4MomSub",     &akt3_jet_phi_4MomSub,     "akt3_jet_phi_4MomSub[akt3_jet_n_4MomSub]/F");
outTree->Branch ("akt3_jet_e_4MomSub",       &akt3_jet_e_4MomSub,       "akt3_jet_e_4MomSub[akt3_jet_n_4MomSub]/F");
outTree->Branch ("akt3_jet_zg_4MomSub",      &akt3_jet_zg_4MomSub,      "akt3_jet_zg_4MomSub[akt3_jet_n_4MomSub]/F");
outTree->Branch ("akt3_jet_thetag_4MomSub",  &akt3_jet_thetag_4MomSub,  "akt3_jet_thetag_4MomSub[akt3_jet_n_4MomSub]/F");
outTree->Branch ("akt3_jet_mu_4MomSub",      &akt3_jet_mu_4MomSub,      "akt3_jet_mu_4MomSub[akt3_jet_n_4MomSub]/F");

outTree->Branch ("akt4_jet_n_4MomSub",       &akt4_jet_n_4MomSub,       "akt4_jet_n_4MomSub/I");
outTree->Branch ("akt4_jet_pt_4MomSub",      &akt4_jet_pt_4MomSub,      "akt4_jet_pt_4MomSub[akt4_jet_n_4MomSub]/F");
outTree->Branch ("akt4_jet_eta_4MomSub",     &akt4_jet_eta_4MomSub,     "akt4_jet_eta_4MomSub[akt4_jet_n_4MomSub]/F");
outTree->Branch ("akt4_jet_phi_4MomSub",     &akt4_jet_phi_4MomSub,     "akt4_jet_phi_4MomSub[akt4_jet_n_4MomSub]/F");
outTree->Branch ("akt4_jet_e_4MomSub",       &akt4_jet_e_4MomSub,       "akt4_jet_e_4MomSub[akt4_jet_n_4MomSub]/F");
outTree->Branch ("akt4_jet_zg_4MomSub",      &akt4_jet_zg_4MomSub,      "akt4_jet_zg_4MomSub[akt4_jet_n_4MomSub]/F");
outTree->Branch ("akt4_jet_thetag_4MomSub",  &akt4_jet_thetag_4MomSub,  "akt4_jet_thetag_4MomSub[akt4_jet_n_4MomSub]/F");
outTree->Branch ("akt4_jet_mu_4MomSub",      &akt4_jet_mu_4MomSub,      "akt4_jet_mu_4MomSub[akt4_jet_n_4MomSub]/F");

outTree->Branch ("akt6_jet_n_4MomSub",       &akt6_jet_n_4MomSub,       "akt6_jet_n_4MomSub/I");
outTree->Branch ("akt6_jet_pt_4MomSub",      &akt6_jet_pt_4MomSub,      "akt6_jet_pt_4MomSub[akt6_jet_n_4MomSub]/F");
outTree->Branch ("akt6_jet_eta_4MomSub",     &akt6_jet_eta_4MomSub,     "akt6_jet_eta_4MomSub[akt6_jet_n_4MomSub]/F");
outTree->Branch ("akt6_jet_phi_4MomSub",     &akt6_jet_phi_4MomSub,     "akt6_jet_phi_4MomSub[akt6_jet_n_4MomSub]/F");
outTree->Branch ("akt6_jet_e_4MomSub",       &akt6_jet_e_4MomSub,       "akt6_jet_e_4MomSub[akt6_jet_n_4MomSub]/F");
outTree->Branch ("akt6_jet_zg_4MomSub",      &akt6_jet_zg_4MomSub,      "akt6_jet_zg_4MomSub[akt6_jet_n_4MomSub]/F");
outTree->Branch ("akt6_jet_thetag_4MomSub",  &akt6_jet_thetag_4MomSub,  "akt6_jet_thetag_4MomSub[akt6_jet_n_4MomSub]/F");
outTree->Branch ("akt6_jet_mu_4MomSub",      &akt6_jet_mu_4MomSub,      "akt6_jet_mu_4MomSub[akt6_jet_n_4MomSub]/F");

outTree->Branch ("akt8_jet_n_4MomSub",       &akt8_jet_n_4MomSub,       "akt8_jet_n_4MomSub/I");
outTree->Branch ("akt8_jet_pt_4MomSub",      &akt8_jet_pt_4MomSub,      "akt8_jet_pt_4MomSub[akt8_jet_n_4MomSub]/F");
outTree->Branch ("akt8_jet_eta_4MomSub",     &akt8_jet_eta_4MomSub,     "akt8_jet_eta_4MomSub[akt8_jet_n_4MomSub]/F");
outTree->Branch ("akt8_jet_phi_4MomSub",     &akt8_jet_phi_4MomSub,     "akt8_jet_phi_4MomSub[akt8_jet_n_4MomSub]/F");
outTree->Branch ("akt8_jet_e_4MomSub",       &akt8_jet_e_4MomSub,       "akt8_jet_e_4MomSub[akt8_jet_n_4MomSub]/F");
outTree->Branch ("akt8_jet_zg_4MomSub",      &akt8_jet_zg_4MomSub,      "akt8_jet_zg_4MomSub[akt8_jet_n_4MomSub]/F");
outTree->Branch ("akt8_jet_thetag_4MomSub",  &akt8_jet_thetag_4MomSub,  "akt8_jet_thetag_4MomSub[akt8_jet_n_4MomSub]/F");
outTree->Branch ("akt8_jet_mu_4MomSub",      &akt8_jet_mu_4MomSub,      "akt8_jet_mu_4MomSub[akt2_jet_n_4MomSub]/F");

outTree->Branch ("akt1_jet_n_4MomSub",       &akt1_jet_n_4MomSub,       "akt1_jet_n_4MomSub/I");
outTree->Branch ("akt1_jet_pt_4MomSub",      &akt1_jet_pt_4MomSub,      "akt1_jet_pt_4MomSub[akt1_jet_n_4MomSub]/F");
outTree->Branch ("akt1_jet_eta_4MomSub",     &akt1_jet_eta_4MomSub,     "akt1_jet_eta_4MomSub[akt1_jet_n_4MomSub]/F");
outTree->Branch ("akt1_jet_phi_4MomSub",     &akt1_jet_phi_4MomSub,     "akt1_jet_phi_4MomSub[akt1_jet_n_4MomSub]/F");
outTree->Branch ("akt1_jet_e_4MomSub",       &akt1_jet_e_4MomSub,       "akt1_jet_e_4MomSub[akt1_jet_n_4MomSub]/F");
outTree->Branch ("akt1_jet_zg_4MomSub",      &akt1_jet_zg_4MomSub,      "akt1_jet_zg_4MomSub[akt1_jet_n_4MomSub]/F");
outTree->Branch ("akt1_jet_thetag_4MomSub",  &akt1_jet_thetag_4MomSub,  "akt1_jet_thetag_4MomSub[akt1_jet_n_4MomSub]/F");
outTree->Branch ("akt1_jet_mu_4MomSub",      &akt1_jet_mu_4MomSub,      "akt1_jet_mu_4MomSub[akt1_jet_n_4MomSub]/F");
/*
outTree->Branch ("akt4_jet_n_GridSub1",    &akt4_jet_n_GridSub1,    "akt4_jet_n_GridSub1/I");
outTree->Branch ("akt4_jet_pt_GridSub1",   &akt4_jet_pt_GridSub1,   "akt4_jet_pt_GridSub1[akt4_jet_n_GridSub1]/F");
outTree->Branch ("akt4_jet_eta_GridSub1",  &akt4_jet_eta_GridSub1,  "akt4_jet_eta_GridSub1[akt4_jet_n_GridSub1]/F");
outTree->Branch ("akt4_jet_phi_GridSub1",  &akt4_jet_phi_GridSub1,  "akt4_jet_phi_GridSub1[akt4_jet_n_GridSub1]/F");
outTree->Branch ("akt4_jet_e_GridSub1",    &akt4_jet_e_GridSub1,    "akt4_jet_e_GridSub1[akt4_jet_n_GridSub1]/F");
*/
outTree->Branch ("akt4_jet_n_GridSub2",    &akt4_jet_n_GridSub2,    "akt4_jet_n_GridSub2/I");
outTree->Branch ("akt4_jet_pt_GridSub2",   &akt4_jet_pt_GridSub2,   "akt4_jet_pt_GridSub2[akt4_jet_n_GridSub2]/F");
outTree->Branch ("akt4_jet_eta_GridSub2",  &akt4_jet_eta_GridSub2,  "akt4_jet_eta_GridSub2[akt4_jet_n_GridSub2]/F");
outTree->Branch ("akt4_jet_phi_GridSub2",  &akt4_jet_phi_GridSub2,  "akt4_jet_phi_GridSub2[akt4_jet_n_GridSub2]/F");
outTree->Branch ("akt4_jet_e_GridSub2",    &akt4_jet_e_GridSub2,    "akt4_jet_e_GridSub2[akt4_jet_n_GridSub2]/F");

const float etaMax   = 4.9;
const float minJetPt = 5;
const float z_cut    = 0.10;
const float beta     = 2.0;

fastjet::contrib::SoftDrop sd(beta, z_cut);

fastjet::JetDefinition antiKt2 (fastjet::antikt_algorithm, 0.2);
fastjet::JetDefinition antiKt3 (fastjet::antikt_algorithm, 0.3);
fastjet::JetDefinition antiKt4 (fastjet::antikt_algorithm, 0.4);
fastjet::JetDefinition antiKt6 (fastjet::antikt_algorithm, 0.6);
fastjet::JetDefinition antiKt8 (fastjet::antikt_algorithm, 0.8);
fastjet::JetDefinition antiKt1 (fastjet::antikt_algorithm, 1);

fastjet::JetDefinition antiKt4_GridSub1 (fastjet::antikt_algorithm, 0.4);
fastjet::JetDefinition antiKt4_GridSub2 (fastjet::antikt_algorithm, 0.4);
TDatabasePDG* pdgData = new TDatabasePDG ();

int iEvt = 0;
HepMC::GenEvent* event = inFile->read_next_event ();
while (event) {

  vector <fastjet::PseudoJet> particles;

  for (HepMC::GenEvent::particle_iterator part_iterator = event->particles_begin (); part_iterator != event->particles_end (); part_iterator++) {
    HepMC::GenParticle* part = *(part_iterator);

    if (part->status () != 1 )
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
  fastjet::ClusterSequence clusterSeqAkt6 (particles, antiKt6);
  vector<fastjet::PseudoJet> sortedAkt6Jets = fastjet::sorted_by_pt (clusterSeqAkt6.inclusive_jets ());
  fastjet::ClusterSequence clusterSeqAkt8 (particles, antiKt8);
  vector<fastjet::PseudoJet> sortedAkt8Jets = fastjet::sorted_by_pt (clusterSeqAkt8.inclusive_jets ());
  fastjet::ClusterSequence clusterSeqAkt1 (particles, antiKt1);
  vector<fastjet::PseudoJet> sortedAkt1Jets = fastjet::sorted_by_pt (clusterSeqAkt1.inclusive_jets ());

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
  akt6_jet_n = 0;
  for (fastjet::PseudoJet jet : sortedAkt6Jets) {
    if (jet.perp () < minJetPt || fabs (jet.pseudorapidity ()) > etaMax || akt6_jet_n >= 100)
      continue;

    akt6_jet_pt[akt6_jet_n] = jet.perp ();
    akt6_jet_eta[akt6_jet_n] = jet.pseudorapidity ();
    akt6_jet_phi[akt6_jet_n] = jet.phi ();
    akt6_jet_e[akt6_jet_n] = jet.e ();
    akt6_jet_n++;
  }
  akt8_jet_n = 0;
  for (fastjet::PseudoJet jet : sortedAkt8Jets) {
    if (jet.perp () < minJetPt || fabs (jet.pseudorapidity ()) > etaMax || akt8_jet_n >= 100)
      continue;

    akt8_jet_pt[akt8_jet_n] = jet.perp ();
    akt8_jet_eta[akt8_jet_n] = jet.pseudorapidity ();
    akt8_jet_phi[akt8_jet_n] = jet.phi ();
    akt8_jet_e[akt8_jet_n] = jet.e ();
    akt8_jet_n++;
  }
  akt1_jet_n = 0;
  for (fastjet::PseudoJet jet : sortedAkt1Jets) {
    if (jet.perp () < minJetPt || fabs (jet.pseudorapidity ()) > etaMax || akt1_jet_n >= 100)
      continue;

    akt1_jet_pt[akt1_jet_n] = jet.perp ();
    akt1_jet_eta[akt1_jet_n] = jet.pseudorapidity ();
    akt1_jet_phi[akt1_jet_n] = jet.phi ();
    akt1_jet_e[akt1_jet_n] = jet.e ();
    akt1_jet_n++;
  }

  part_n = 0;
  for (HepMC::GenEvent::particle_iterator part_iterator = event->particles_begin (); part_iterator != event->particles_end (); part_iterator++) {
    HepMC::GenParticle* part = *(part_iterator);

    if (part->status () != 1 && part->status () != 3 )
      continue;

    HepMC::FourVector mom = part->momentum ();

    part_pt[part_n]      = mom.perp ();
    part_eta[part_n]     = mom.pseudoRapidity ();
    part_phi[part_n]     = mom.phi ();
    part_e[part_n]       = mom.e ();
    part_pdgid[part_n]   = part->pdg_id ();
    part_barcode[part_n] = part->barcode ();
    part_charge[part_n]  = pdgData->GetParticle (part->pdg_id ())->Charge () / 3;
    part_status[part_n]  = part->status ();
    part_n++;
  }

 // 4MomSub (recommended Subtraction) : 
  float dphi;
  float deta;
  float dR;
  TLorentzVector jet_tlv;
  TLorentzVector thermal_tlv;
  TLorentzVector Sum_tlv;
  akt2_jet_n_4MomSub = akt2_jet_n;
  akt3_jet_n_4MomSub = akt3_jet_n;
  akt4_jet_n_4MomSub = akt4_jet_n;
  akt6_jet_n_4MomSub = akt6_jet_n;
  akt8_jet_n_4MomSub = akt8_jet_n;
  akt1_jet_n_4MomSub = akt1_jet_n;
  vector <fastjet::PseudoJet> subtracted_Jets_2;
  vector <fastjet::PseudoJet> subtracted_Jets_3;
  vector <fastjet::PseudoJet> subtracted_Jets_4;
  vector <fastjet::PseudoJet> subtracted_Jets_6;
  vector <fastjet::PseudoJet> subtracted_Jets_8;
  vector <fastjet::PseudoJet> subtracted_Jets_1;
// 4MomSub for anti-kT R = 0.2
// loop over each jet to perform jet-level subtraction : 
  for (int alljets = 0; alljets < akt2_jet_n_4MomSub; alljets ++){
    jet_tlv.SetPtEtaPhiE (akt2_jet_pt[alljets], akt2_jet_eta[alljets], akt2_jet_phi[alljets], akt2_jet_e[alljets]);
    Sum_tlv.SetPtEtaPhiE(0,0,0,0);
// loop over each thermal momentum and check if it's within the jet :
    for (int thermal_m = 0; thermal_m < part_n; thermal_m++){
      if (part_status[thermal_m] != 3) continue;

      dphi = akt2_jet_phi[alljets]- part_phi[thermal_m];
      if (dphi > TMath::Pi())  dphi -= 2*TMath::Pi();
      if (dphi < -TMath::Pi()) dphi += 2*TMath::Pi();
      deta = akt2_jet_eta[alljets]-part_eta[thermal_m];
      dR = sqrt(pow(deta,2) + pow(dphi,2));

      if (dR > 0.2)  continue;
// check if there is any final state particle next to that thermal momentum (dR < 1e-5) (if not, we ignore that thermal momentum for this jet) :
      for (int allparticles = 0 ; allparticles < part_n; allparticles++){
        if (part_status[allparticles] == 3 ) continue;

        dphi = part_phi[thermal_m]-part_phi[allparticles];
        if (dphi > TMath::Pi())  dphi -= 2*TMath::Pi();
        if (dphi < -TMath::Pi()) dphi += 2*TMath::Pi();

        deta = part_eta[allparticles]-part_eta[thermal_m];
        dR = sqrt(pow(deta,2) + pow(dphi,2));

        if (dR > 1e-5) continue;
	// if there is any final state particle next to that thermal momenta, then add it to the sum of all thermal momenta that satisfy previuos conditions 
        thermal_tlv.SetPtEtaPhiE (part_pt[thermal_m], part_eta[thermal_m], part_phi[thermal_m], part_e[thermal_m]);
        Sum_tlv += thermal_tlv;
	break;
      }
    }
// now perform subtraction (new jet = old jet - Sum(thermal momenta)) 
    jet_tlv = jet_tlv - Sum_tlv;
    akt2_jet_pt_4MomSub[alljets]  = jet_tlv.Pt  ();
    akt2_jet_eta_4MomSub[alljets] = jet_tlv.Eta ();
    akt2_jet_phi_4MomSub[alljets] = jet_tlv.Phi ();
    akt2_jet_e_4MomSub[alljets]   = jet_tlv.E   ();
    subtracted_Jets_2.push_back (fastjet::PseudoJet (jet_tlv.Px (), jet_tlv.Py (), jet_tlv.Pz (), jet_tlv.E ()));
  }

//fastjet::contrib::SoftDrop sd(beta, z_cut);
for (int ijet = 0; ijet < akt2_jet_n_4MomSub; ijet++){
fastjet::PseudoJet sd_2 = sd(subtracted_Jets_2[ijet]);
assert(sd_2 !=0);
//cout << "  symmetry measure(z):     " << sd_2.structure_of<fastjet::contrib::SoftDrop>().symmetry() << endl;
akt2_jet_zg_4MomSub[ijet] = sd_2.structure_of<fastjet::contrib::SoftDrop>().zg();
akt2_jet_thetag_4MomSub[ijet] = sd_2.structure_of<fastjet::contrib::SoftDrop>().thetag();
akt2_jet_mu_4MomSub[ijet] = sd_2.structure_of<fastjet::contrib::SoftDrop>().mu();
}

// 4MomSub for anti-kT R = 0.3
  for (int alljets = 0; alljets < akt3_jet_n_4MomSub; alljets ++){
    jet_tlv.SetPtEtaPhiE (akt3_jet_pt[alljets], akt3_jet_eta[alljets], akt3_jet_phi[alljets], akt3_jet_e[alljets]);
    Sum_tlv.SetPtEtaPhiE(0,0,0,0);

    for (int thermal_m = 0; thermal_m < part_n; thermal_m++){
      if (part_status[thermal_m] != 3) continue;

      dphi = akt3_jet_phi[alljets]- part_phi[thermal_m];
      if (dphi > TMath::Pi())  dphi -= 2*TMath::Pi();
      if (dphi < -TMath::Pi()) dphi += 2*TMath::Pi();
      deta = akt3_jet_eta[alljets]-part_eta[thermal_m];
      dR = sqrt(pow(deta,2) + pow(dphi,2));

      if (dR > 0.3)  continue;
      for (int allparticles = 0 ; allparticles < part_n; allparticles++){
        if (part_status[allparticles] == 3 ) continue;

        dphi = part_phi[thermal_m]-part_phi[allparticles];
        if (dphi > TMath::Pi())  dphi -= 2*TMath::Pi();
        if (dphi < -TMath::Pi()) dphi += 2*TMath::Pi();

        deta = part_eta[allparticles]-part_eta[thermal_m];
        dR = sqrt(pow(deta,2) + pow(dphi,2));

        if (dR > 1e-5) continue;
        thermal_tlv.SetPtEtaPhiE (part_pt[thermal_m], part_eta[thermal_m], part_phi[thermal_m], part_e[thermal_m]);
        Sum_tlv += thermal_tlv;
	break;
      }
    }
      jet_tlv = jet_tlv - Sum_tlv;
      akt3_jet_pt_4MomSub[alljets]  = jet_tlv.Pt  ();
      akt3_jet_eta_4MomSub[alljets] = jet_tlv.Eta ();
      akt3_jet_phi_4MomSub[alljets] = jet_tlv.Phi ();
      akt3_jet_e_4MomSub[alljets]   = jet_tlv.E   ();
      subtracted_Jets_3.push_back (fastjet::PseudoJet (jet_tlv.Px (), jet_tlv.Py (), jet_tlv.Pz (), jet_tlv.E ()));
  }

//fastjet::contrib::SoftDrop sd(beta, z_cut);
for (int ijet = 0; ijet < akt3_jet_n_4MomSub; ijet++){
fastjet::PseudoJet sd_3 = sd(subtracted_Jets_3[ijet]);
assert(sd_3 !=0);
//cout << "  symmetry measure(z):     " << sd_3.structure_of<fastjet::contrib::SoftDrop>().symmetry() << endl;
akt3_jet_zg_4MomSub[ijet] = sd_3.structure_of<fastjet::contrib::SoftDrop>().zg();
akt3_jet_thetag_4MomSub[ijet] = sd_3.structure_of<fastjet::contrib::SoftDrop>().thetag();
akt3_jet_mu_4MomSub[ijet] = sd_3.structure_of<fastjet::contrib::SoftDrop>().mu();
}

 // 4MomSub for anti-kT R = 0.4
  for (int alljets = 0; alljets < akt4_jet_n_4MomSub; alljets ++){
    jet_tlv.SetPtEtaPhiE (akt4_jet_pt[alljets], akt4_jet_eta[alljets], akt4_jet_phi[alljets], akt4_jet_e[alljets]);
    Sum_tlv.SetPtEtaPhiE(0,0,0,0);

    for (int thermal_m = 0; thermal_m < part_n; thermal_m++){
      if (part_status[thermal_m] != 3) continue;

      dphi = akt4_jet_phi[alljets]- part_phi[thermal_m];
      if (dphi > TMath::Pi())  dphi -= 2*TMath::Pi();
      if (dphi < -TMath::Pi()) dphi += 2*TMath::Pi();
      deta = akt4_jet_eta[alljets]-part_eta[thermal_m];
      dR = sqrt(pow(deta,2) + pow(dphi,2));

      if (dR > 0.4)  continue;
      for (int allparticles = 0 ; allparticles < part_n; allparticles++){
        if (part_status[allparticles] == 3 ) continue;

          dphi = part_phi[thermal_m]-part_phi[allparticles];
          if (dphi > TMath::Pi())  dphi -= 2*TMath::Pi();
          if (dphi < -TMath::Pi()) dphi += 2*TMath::Pi();

          deta = part_eta[allparticles]-part_eta[thermal_m];
          dR = sqrt(pow(deta,2) + pow(dphi,2));

          if (dR > 1e-5) continue;
          thermal_tlv.SetPtEtaPhiE (part_pt[thermal_m], part_eta[thermal_m], part_phi[thermal_m], part_e[thermal_m]);
          Sum_tlv += thermal_tlv;
	  break; 
      }
    }
        jet_tlv = jet_tlv - Sum_tlv;
        akt4_jet_pt_4MomSub[alljets]  = jet_tlv.Pt  ();
        akt4_jet_eta_4MomSub[alljets] = jet_tlv.Eta ();
        akt4_jet_phi_4MomSub[alljets] = jet_tlv.Phi ();
        akt4_jet_e_4MomSub[alljets]   = jet_tlv.E   ();
        subtracted_Jets_4.push_back (fastjet::PseudoJet (jet_tlv.Px (), jet_tlv.Py (), jet_tlv.Pz (), jet_tlv.E ()));
      }

//fastjet::contrib::SoftDrop sd(beta, z_cut);
for (int ijet = 0; ijet < akt4_jet_n_4MomSub; ijet++){
fastjet::PseudoJet sd_4 = sd(subtracted_Jets_4[ijet]);
assert(sd_4 !=0);
//cout << "  symmetry measure(z):     " << sd_4.structure_of<fastjet::contrib::SoftDrop>().symmetry() << endl;
akt4_jet_zg_4MomSub[ijet] = sd_4.structure_of<fastjet::contrib::SoftDrop>().zg();
akt4_jet_thetag_4MomSub[ijet] = sd_4.structure_of<fastjet::contrib::SoftDrop>().thetag();
akt4_jet_mu_4MomSub[ijet] = sd_4.structure_of<fastjet::contrib::SoftDrop>().mu();
} 

// 4MomSub for anti-kT R = 0.6
  for (int alljets = 0; alljets < akt6_jet_n_4MomSub; alljets ++){
    jet_tlv.SetPtEtaPhiE (akt6_jet_pt[alljets], akt6_jet_eta[alljets], akt6_jet_phi[alljets], akt6_jet_e[alljets]);
    Sum_tlv.SetPtEtaPhiE(0,0,0,0);

    for (int thermal_m = 0; thermal_m < part_n; thermal_m++){
      if (part_status[thermal_m] != 3) continue;

      dphi = akt6_jet_phi[alljets]- part_phi[thermal_m];
      if (dphi > TMath::Pi())  dphi -= 2*TMath::Pi();
      if (dphi < -TMath::Pi()) dphi += 2*TMath::Pi();
      deta = akt6_jet_eta[alljets]-part_eta[thermal_m];
      dR = sqrt(pow(deta,2) + pow(dphi,2));

      if (dR > 0.6)  continue;
      for (int allparticles = 0 ; allparticles < part_n; allparticles++){
        if (part_status[allparticles] == 3 ) continue;

        dphi = part_phi[thermal_m]-part_phi[allparticles];
        if (dphi > TMath::Pi())  dphi -= 2*TMath::Pi();
        if (dphi < -TMath::Pi()) dphi += 2*TMath::Pi();

        deta = part_eta[allparticles]-part_eta[thermal_m];
        dR = sqrt(pow(deta,2) + pow(dphi,2));

        if (dR > 1e-5) continue;
        thermal_tlv.SetPtEtaPhiE (part_pt[thermal_m], part_eta[thermal_m], part_phi[thermal_m], part_e[thermal_m]);
        Sum_tlv += thermal_tlv;
	break;
      }
    }
      jet_tlv = jet_tlv - Sum_tlv;
      akt6_jet_pt_4MomSub[alljets]  = jet_tlv.Pt  ();
      akt6_jet_eta_4MomSub[alljets] = jet_tlv.Eta ();
      akt6_jet_phi_4MomSub[alljets] = jet_tlv.Phi ();
      akt6_jet_e_4MomSub[alljets]   = jet_tlv.E   ();
      subtracted_Jets_6.push_back (fastjet::PseudoJet (jet_tlv.Px (), jet_tlv.Py (), jet_tlv.Pz (), jet_tlv.E ()));
  }
//fastjet::contrib::SoftDrop sd(beta, z_cut);
for (int ijet = 0; ijet < akt6_jet_n_4MomSub; ijet++){
fastjet::PseudoJet sd_6 = sd(subtracted_Jets_6[ijet]);
assert(sd_6 !=0);
//cout << "  symmetry measure(z):     " << sd_6.structure_of<fastjet::contrib::SoftDrop>().symmetry() << endl;
akt6_jet_zg_4MomSub[ijet] = sd_6.structure_of<fastjet::contrib::SoftDrop>().zg();
akt6_jet_thetag_4MomSub[ijet] = sd_6.structure_of<fastjet::contrib::SoftDrop>().thetag();
akt6_jet_mu_4MomSub[ijet] = sd_6.structure_of<fastjet::contrib::SoftDrop>().mu();
} 
// 4MomSub for anti-kT R = 0.8
  for (int alljets = 0; alljets < akt8_jet_n_4MomSub; alljets ++){
    jet_tlv.SetPtEtaPhiE (akt8_jet_pt[alljets], akt8_jet_eta[alljets], akt8_jet_phi[alljets], akt8_jet_e[alljets]);
    Sum_tlv.SetPtEtaPhiE(0,0,0,0);

    for (int thermal_m = 0; thermal_m < part_n; thermal_m++){
      if (part_status[thermal_m] != 3) continue;

      dphi = akt8_jet_phi[alljets]- part_phi[thermal_m];
      if (dphi > TMath::Pi())  dphi -= 2*TMath::Pi();
      if (dphi < -TMath::Pi()) dphi += 2*TMath::Pi();
      deta = akt8_jet_eta[alljets]-part_eta[thermal_m];
      dR = sqrt(pow(deta,2) + pow(dphi,2));

      if (dR > 0.8)  continue;
      for (int allparticles = 0 ; allparticles < part_n; allparticles++){
        if (part_status[allparticles] == 3 ) continue;

        dphi = part_phi[thermal_m]-part_phi[allparticles];
        if (dphi > TMath::Pi())  dphi -= 2*TMath::Pi();
        if (dphi < -TMath::Pi()) dphi += 2*TMath::Pi();

        deta = part_eta[allparticles]-part_eta[thermal_m];
        dR = sqrt(pow(deta,2) + pow(dphi,2));

        if (dR > 1e-5) continue;
        thermal_tlv.SetPtEtaPhiE (part_pt[thermal_m], part_eta[thermal_m], part_phi[thermal_m], part_e[thermal_m]);
        Sum_tlv += thermal_tlv;
        break;
      }
    }
          jet_tlv = jet_tlv - Sum_tlv;
          akt8_jet_pt_4MomSub[alljets]  = jet_tlv.Pt  ();
          akt8_jet_eta_4MomSub[alljets] = jet_tlv.Eta ();
          akt8_jet_phi_4MomSub[alljets] = jet_tlv.Phi ();
          akt8_jet_e_4MomSub[alljets]   = jet_tlv.E   ();
          subtracted_Jets_8.push_back (fastjet::PseudoJet (jet_tlv.Px (), jet_tlv.Py (), jet_tlv.Pz (), jet_tlv.E ()));
  }

//fastjet::contrib::SoftDrop sd(beta, z_cut);
for (int ijet = 0; ijet < akt8_jet_n_4MomSub; ijet++){
fastjet::PseudoJet sd_8 = sd(subtracted_Jets_8[ijet]);
assert(sd_8 !=0);
//cout << "  symmetry measure(z):     " << sd_8.structure_of<fastjet::contrib::SoftDrop>().symmetry() << endl;
akt8_jet_zg_4MomSub[ijet] = sd_8.structure_of<fastjet::contrib::SoftDrop>().zg();
akt8_jet_thetag_4MomSub[ijet] = sd_8.structure_of<fastjet::contrib::SoftDrop>().thetag();
akt8_jet_mu_4MomSub[ijet] = sd_8.structure_of<fastjet::contrib::SoftDrop>().mu();
} 

// 4MomSub for anti-kT R = 1
  for (int alljets = 0; alljets < akt1_jet_n_4MomSub; alljets ++){
   jet_tlv.SetPtEtaPhiE (akt1_jet_pt[alljets], akt1_jet_eta[alljets], akt1_jet_phi[alljets], akt1_jet_e[alljets]);
   Sum_tlv.SetPtEtaPhiE(0,0,0,0);

   for (int thermal_m = 0; thermal_m < part_n; thermal_m++){
     if (part_status[thermal_m] != 3) continue;

     dphi = akt1_jet_phi[alljets]- part_phi[thermal_m];
     if (dphi > TMath::Pi())  dphi -= 2*TMath::Pi();
     if (dphi < -TMath::Pi()) dphi += 2*TMath::Pi();
     deta = akt1_jet_eta[alljets]-part_eta[thermal_m];
     dR = sqrt(pow(deta,2) + pow(dphi,2));

     if (dR > 1)  continue;
     for (int allparticles = 0 ; allparticles < part_n; allparticles++){
       if (part_status[allparticles] == 3 ) continue;

       dphi = part_phi[thermal_m]-part_phi[allparticles];
       if (dphi > TMath::Pi())  dphi -= 2*TMath::Pi();
       if (dphi < -TMath::Pi()) dphi += 2*TMath::Pi();

         deta = part_eta[allparticles]-part_eta[thermal_m];
         dR = sqrt(pow(deta,2) + pow(dphi,2));

         if (dR > 1e-5) continue;
         thermal_tlv.SetPtEtaPhiE (part_pt[thermal_m], part_eta[thermal_m], part_phi[thermal_m], part_e[thermal_m]);
         Sum_tlv += thermal_tlv;
         break;
      }
    }
       jet_tlv = jet_tlv - Sum_tlv;
       akt1_jet_pt_4MomSub[alljets]  = jet_tlv.Pt  ();
       akt1_jet_eta_4MomSub[alljets] = jet_tlv.Eta ();
       akt1_jet_phi_4MomSub[alljets] = jet_tlv.Phi ();
       akt1_jet_e_4MomSub[alljets]   = jet_tlv.E   ();
       subtracted_Jets_1.push_back (fastjet::PseudoJet (jet_tlv.Px (), jet_tlv.Py (), jet_tlv.Pz (), jet_tlv.E ()));
  }
//fastjet::contrib::SoftDrop sd(beta, z_cut);
for (int ijet = 0; ijet < akt1_jet_n_4MomSub; ijet++){
fastjet::PseudoJet sd_1 = sd(subtracted_Jets_1[ijet]);
assert(sd_1 !=0);
//cout << "  symmetry measure(z):     " << sd_1.structure_of<fastjet::contrib::SoftDrop>().symmetry() << endl;
akt1_jet_zg_4MomSub[ijet] = sd_1.structure_of<fastjet::contrib::SoftDrop>().zg();
akt1_jet_thetag_4MomSub[ijet] = sd_1.structure_of<fastjet::contrib::SoftDrop>().thetag();
akt1_jet_mu_4MomSub[ijet] = sd_1.structure_of<fastjet::contrib::SoftDrop>().mu();
} 









// GridSub2 :
  float phi_min = -TMath::Pi() - 2*TMath::Pi()/40;
  float phi_max = -TMath::Pi();

  TLorentzVector grid2_tlv[40][40];
  TLorentzVector grid2_thermal_tlv[40][40];
  TLorentzVector grid2_Sum_tlv;
  phi_min = -TMath::Pi() - 2*TMath::Pi()/40;
  phi_max = -TMath::Pi();
  
// divide eta-phi plane into 40x40 grid and sum up 4-mom for final state particles in each cell
  for (int allphi = 0; allphi < 40; allphi ++){
    phi_min += 2*TMath::Pi()/40 ;
    phi_max += 2*TMath::Pi()/40 ;
    float eta_min = -21*0.2;
    float eta_max = -4 ;
    for (int alleta = 0; alleta < 40; alleta ++){
      eta_min += 0.2;
      eta_max += 0.2;
      for (int allparticles = 0 ; allparticles < part_n; allparticles++){
        if (part_phi[allparticles] > phi_max  || part_phi[allparticles] < phi_min ||  part_eta[allparticles] > eta_max || part_eta[allparticles] < eta_min || part_status[allparticles] == 3 )continue;
        grid2_Sum_tlv.SetPtEtaPhiE (part_pt[allparticles], part_eta[allparticles], part_phi[allparticles], part_e[allparticles]);
        grid2_tlv[allphi][alleta] +=grid2_Sum_tlv; 
      }
    }
  }

// divide eta-phi plane into 40x40 grid and sum up 4-mom for thermal momenta in each cell
  phi_min = -TMath::Pi() - 2*TMath::Pi()/40;
  phi_max = -TMath::Pi();

  for (int allphi = 0; allphi < 40; allphi ++){
    phi_min += 2*TMath::Pi()/40 ;
    phi_max += 2*TMath::Pi()/40 ;
    float eta_min = -21*0.2;
    float eta_max = -4 ;
    for (int alleta = 0; alleta < 40; alleta ++){
      eta_min += 0.2;
      eta_max += 0.2;
      for (int allparticles = 0 ; allparticles < part_n; allparticles++){
        if (part_phi[allparticles] > phi_max  || part_phi[allparticles] < phi_min ||  part_eta[allparticles] > eta_max || part_eta[allparticles] < eta_min || part_status[allparticles] != 3 )continue;
        grid2_Sum_tlv.SetPtEtaPhiE (part_pt[allparticles], part_eta[allparticles], part_phi[allparticles], part_e[allparticles]);
        grid2_thermal_tlv[allphi][alleta] +=grid2_Sum_tlv; 
      }
    }
  }


// for each cell:
// if pT Sum(final state particles) < Sum(thermal momenta), then set that cell's 4mom to (0,0,0,0)
// if pT Sum(final state particles) > Sum(thermal momenta), then set that cell's 4mom to : 4-mom(Sum(final state particles)) - 4-mom(Sum(thermal momenta))
  for (int allphi = 0; allphi< 40; allphi++){
    for(int alleta = 0; alleta < 40 ; alleta++){

      if (grid2_tlv[allphi][alleta].Pt() < grid2_thermal_tlv[allphi][alleta].Pt() ) grid2_tlv[allphi][alleta].SetPtEtaPhiE(0,0,0,0);
      else grid2_tlv[allphi][alleta] -= grid2_thermal_tlv[allphi][alleta]; 
    }
  }

// cluster new jets using cells as particles
      vector <fastjet::PseudoJet> grid2;

  for (int allphi = 0; allphi< 40; allphi++){
    for(int alleta = 0; alleta < 40 ; alleta++){
      if (fabs (grid2_tlv[allphi][alleta].Eta ()) > etaMax || grid2_tlv[allphi][alleta].Pt () == 0 ) continue; 

      grid2.push_back (fastjet::PseudoJet (grid2_tlv[allphi][alleta].Px (), grid2_tlv[allphi][alleta].Py (), grid2_tlv[allphi][alleta].Pz (), grid2_tlv[allphi][alleta].E ()));
    }
  }

  fastjet::ClusterSequence clusterSeqAkt4_GridSub2 (grid2, antiKt4_GridSub2);
  vector<fastjet::PseudoJet> sortedAkt4_GridSub2_Jets = fastjet::sorted_by_pt (clusterSeqAkt4_GridSub2.inclusive_jets ());

  akt4_jet_n_GridSub2 = 0;
  for (fastjet::PseudoJet jet : sortedAkt4_GridSub2_Jets) {
    if (jet.perp () < minJetPt || fabs (jet.pseudorapidity ()) > etaMax || akt4_jet_n_GridSub2 >= 100)   continue;

      akt4_jet_pt_GridSub2[akt4_jet_n_GridSub2]  = jet.perp ();
      akt4_jet_eta_GridSub2[akt4_jet_n_GridSub2] = jet.pseudorapidity ();
      akt4_jet_phi_GridSub2[akt4_jet_n_GridSub2] = jet.phi ();
      akt4_jet_e_GridSub2[akt4_jet_n_GridSub2]   = jet.e ();
      akt4_jet_n_GridSub2++;
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
