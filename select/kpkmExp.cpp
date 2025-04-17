/*
* Class to select events of the ^{+}e^{-} -> K^{+}K^{-} process
* in a vicinity of the \phi-meson resonance.
* 
* Developed by Daniel Ivanov (daniilivanov1606@gmail.com)
*/

#define kpkmExp_cxx
#include "kpkmExp.hpp"
#include <TH2.h>
#include <TH1D.h>
#include <TF1.h>
#include <TStyle.h>
#include <TTree.h>
#include <TMath.h>
#include <TCanvas.h>
#include <TVector3.h>

void kpkmExp::Loop(std::string histFileName)
{
   if (fChain == 0)
      return;

   auto output = new TFile(histFileName.c_str(), "recreate");
   auto selected = new TTree("kChargedTree", "Cutted tr_ph (Kch Energy stability important data)");

   auto hKp = new TH2D("hKp", "K+", 5000, 0, 1000, 5000, 0, 40000);
   auto hKm = new TH2D("hKm", "K-", 5000, 0, 1000, 5000, 0, 40000);
   auto hMomentums =  new TH2D("hMoms", "K+ mom vs K- mom", 1000, 0, 1000, 1000, 0, 1000);

   selected->Branch("ebeam", &ebeam, "ebeam/F");
   selected->Branch("emeas", &emeas0, "emeas/F");
   selected->Branch("demeas", &demeas0, "demeas/F");
   selected->Branch("runnum", &runnum, "runnum/I");

   std::vector<double> charge_vec = {};
   std::vector<double> tptot_vec = {};
   std::vector<double> tth_vec = {};
   std::vector<double> tphi_vec = {};
   std::vector<double> tptotv_vec = {};
   std::vector<double> tthv_vec = {};
   std::vector<double> tphiv_vec = {};
   std::vector<double> tdedx_vec = {};

   selected->Branch("charge", &charge_vec);
   selected->Branch("tptot", &tptot_vec);
   selected->Branch("tth", &tth_vec);
   selected->Branch("tphi", &tphi_vec);
   selected->Branch("tptotv", &tptotv_vec);
   selected->Branch("tthv", &tthv_vec);
   selected->Branch("tphiv", &tphiv_vec);
   selected->Branch("tdedx", &tdedx_vec);

   auto fill_vectors = [&](int track_num) {
      charge_vec.push_back(tcharge[track_num]);
      tptot_vec.push_back(tptot[track_num]);
      tth_vec.push_back(tth[track_num]);
      tphi_vec.push_back(tphi[track_num]);
      tptotv_vec.push_back(tptotv[track_num]);
      tthv_vec.push_back(tthv[track_num]);
      tphiv_vec.push_back(tphiv[track_num]);
      tdedx_vec.push_back(tdedx[track_num]);
   };

   auto clear_vectors = [&](){
      charge_vec.clear();
      tptot_vec.clear();
      tth_vec.clear();
      tphi_vec.clear();
      tptotv_vec.clear();
      tthv_vec.clear();
      tphiv_vec.clear();
      tdedx_vec.clear();
   };

   // ********************* Section with cuts *********************
   const double cutChi2r = 15.;
   const double cutChi2z = 10.;
   const int cutNhitMin = 10;
   const double cutZtrack = 10.;
   const double cutPtot = 40;
   double min_theta = 1;
   double max_theta = TMath::Pi() - 1;

   auto is_in_fiducial_volume = [&](int track_num){
      bool is_good = fabs(tz[track_num]) < cutZtrack &&
                     tth[track_num] > min_theta && 
                     tth[track_num] < max_theta;
      return is_good;
   };
   auto check_track_quality = [&](int track_num){
      bool is_good = tptotv[track_num] > cutPtot && 
                     tchi2r[track_num] < cutChi2r && 
                     tchi2z[track_num] < cutChi2z && 
                     tnhit[track_num] >= cutNhitMin &&
                     is_in_fiducial_volume(track_num);
      return is_good;
   };

   auto check_dedx_mom = [&](int track_num) {
      return  tdedx[track_num] > 40 * exp(-(tptotv[track_num] - 60) / 40) + 7000 &&
            tptotv[track_num] > 60 && tptotv[track_num] < 500;
   };
   // ********************* Section with cuts *********************

   Long64_t nentries = fChain->GetEntriesFast();
   int counter = 0;

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry = 0; jentry < nentries; jentry++)
   {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0)
         break;
      nb = fChain->GetEntry(jentry);
      nbytes += nb;

      if(nt !=2)
      { continue; }

      if (tcharge[0]*tcharge[1] < 0 &&
         check_track_quality(0) &&
         check_track_quality(1) &&
         check_dedx_mom(0) && check_dedx_mom(1) &&
         fabs(tptotv[0]-tptotv[1])/(tptotv[0]+tptotv[1]) < 0.3
      )
      {
         counter++;
         int k_plus = 0;
         int k_minus = 1;

         if(tcharge[0] > 0)
         {
            hMomentums->Fill(tptotv[1], tptotv[0]);
            hKp->Fill(tptotv[0],tdedx[0]);
            hKm->Fill(tptotv[1],tdedx[1]);
         }
         else
         {
            k_plus = 1;
            k_minus = 0;
            hMomentums->Fill(tptotv[1], tptotv[0]);
            hKm->Fill(tptotv[0],tdedx[0]);
            hKp->Fill(tptotv[1],tdedx[1]);
         }

         fill_vectors(k_plus);
         fill_vectors(k_minus);
         selected->Fill();
         clear_vectors();
      }
      clear_vectors();
   }
   std::cout << "Number of events in the tree = " << nentries << std::endl;
   std::cout << "N Selected events = " << double(counter) << std::endl;
   output->Write();
   output->Save();
}
