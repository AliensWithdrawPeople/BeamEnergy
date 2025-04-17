//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Jan 27 09:48:42 2023 by ROOT version 6.22/08
// from TTree tr_ph/Tree with the non-collinear events
// found on file: root://cmd//scan2018_omphi/scan2018_omphi_tr_ph_fc_e509_v9.root
//////////////////////////////////////////////////////////

#ifndef kpkmExp_hpp
#define kpkmExp_hpp

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class kpkmExp {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Float_t         ebeam;
   Float_t         emeas;
   Float_t         demeas;
   Float_t         emeas0;
   Float_t         demeas0;
   Float_t         xbeam;
   Float_t         ybeam;
   Int_t           runnum;
   Int_t           finalstate_id;
   Int_t           evnum;
   Int_t           trigbits;
   Int_t           trigmchs;
   Float_t         trigtime;
   Float_t         time;
   Float_t         dcfittime;
   Float_t         anttime;
   Float_t         mutime;
   Int_t           is_coll;
   Int_t           is_bhabha;
   Int_t           nt_total;
   Float_t         ecaltot;
   Float_t         ecalneu;
   Float_t         z0;
   Float_t         psumch;
   Float_t         psumnu;
   Float_t         lumoff;
   Float_t         lumofferr;
   Int_t           nv_total;
   Int_t           nv;
   Int_t           vtrk[5];   //[nv]
   Int_t           vind[5][10];   //[nv]
   Float_t         vchi[5];   //[nv]
   Float_t         vxyz[5][3];   //[nv]
   Int_t           nt;
   Int_t           it[2];
   Int_t           tnhit[10];   //[nt]
   Float_t         tlength[10];   //[nt]
   Float_t         tphi[10];   //[nt]
   Float_t         tth[10];   //[nt]
   Float_t         tptot[10];   //[nt]
   Float_t         tphiv[10];   //[nt]
   Float_t         tthv[10];   //[nt]
   Float_t         tptotv[10];   //[nt]
   Float_t         trho[10];   //[nt]
   Float_t         tdedx[10];   //[nt]
   Float_t         tz[10];   //[nt]
   Float_t         tt0[10];   //[nt]
   Float_t         tant[10];   //[nt]
   Float_t         tchi2r[10];   //[nt]
   Float_t         tchi2z[10];   //[nt]
   Float_t         tchi2ndf[10];   //[nt]
   Int_t           tcharge[10];   //[nt]
   Float_t         ten[10];   //[nt]
   Float_t         tfc[10];   //[nt]
   Float_t         tenlxe[10];   //[nt]
   Float_t         tlengthlxe[10];   //[nt]
   Float_t         tenslxe_layers[10][14];   //[nt]
   Float_t         tencsi[10];   //[nt]
   Float_t         tenbgo[10];   //[nt]
   Float_t         tclth[10];   //[nt]
   Float_t         tclphi[10];   //[nt]
   Float_t         terr[10][3][3];   //[nt]
   Float_t         terr0[10][6][6];   //[nt]
   Int_t           tindlxe[10];   //[nt]
   Float_t         tzcc[10][2];   //[nt]
   Float_t         txyzatcl[10][3];   //[nt]
   Float_t         txyzatlxe[10][3];   //[nt]
   Int_t           tenconv[10];   //[nt]
   Int_t           nks_total;
   Int_t           nks;
   Int_t           ksvind[6][2];   //[nks]
   Int_t           kstype[6];   //[nks]
   Int_t           ksfstatus[6];   //[nks]
   Float_t         ksvchi[6];   //[nks]
   Float_t         ksvxyz[6][3];   //[nks]
   Float_t         ksminv[6];   //[nks]
   Float_t         ksalign[6];   //[nks]
   Float_t         kstlen[6];   //[nks]
   Float_t         ksdpsi[6];   //[nks]
   Float_t         kslen[6];   //[nks]
   Float_t         ksz0[6];   //[nks]
   Float_t         ksphi[6];   //[nks]
   Float_t         ksth[6];   //[nks]
   Float_t         ksptot[6];   //[nks]
   Float_t         kspiphi[6][2];   //[nks]
   Float_t         kspith[6][2];   //[nks]
   Float_t         kspipt[6][2];   //[nks]
   Float_t         kserr[6][3][3];   //[nks]
   Int_t           ntlxe_total;
   Int_t           ntlxe;
   Int_t           ntlxelayers[10];   //[ntlxe]
   Int_t           tlxenhit[10];   //[ntlxe]
   Float_t         tlxelength[10];   //[ntlxe]
   Float_t         tlxededx[10];   //[ntlxe]
   Float_t         tlxeir[10];   //[ntlxe]
   Float_t         tlxeitheta[10];   //[ntlxe]
   Float_t         tlxeiphi[10];   //[ntlxe]
   Float_t         tlxevtheta[10];   //[ntlxe]
   Float_t         tlxevphi[10];   //[ntlxe]
   Float_t         tlxechi2[10];   //[ntlxe]
   Float_t         tlxesen[10];   //[ntlxe]
   Float_t         tlxesen_layers[10][14];   //[ntlxe]
   Int_t           nph_total;
   Int_t           nph;
   Float_t         phen[34];   //[nph]
   Float_t         phth[34];   //[nph]
   Float_t         phphi[34];   //[nph]
   Float_t         phrho[34];   //[nph]
   Float_t         phrad[34];   //[nph]
   Float_t         phen0[34];   //[nph]
   Float_t         phth0[34];   //[nph]
   Float_t         phphi0[34];   //[nph]
   Float_t         phlxe[34];   //[nph]
   Float_t         phslxe_layers[34][14];   //[nph]
   Float_t         pherr[34][3];   //[nph]
   Float_t         phcsi[34];   //[nph]
   Float_t         phbgo[34];   //[nph]
   Int_t           phflag[34];   //[nph]
   Int_t           phconv[34];   //[nph]
   Int_t           phfc[34];   //[nph]
   Int_t           nzcs_total;
   Int_t           nzcs;
   Int_t           zcsch[1];   //[nzcs]
   Int_t           zcsstat[1];   //[nzcs]
   Float_t         zcsamp[1];   //[nzcs]
   Float_t         zcstime[1];   //[nzcs]
   Float_t         zcsphi[1];   //[nzcs]
   Int_t           nzcc_total;
   Int_t           nzcc;
   Int_t           zccl[1];   //[nzcc]
   Int_t           zccns[1];   //[nzcc]
   Float_t         zccamp[1];   //[nzcc]
   Int_t           zcct[1];   //[nzcc]
   Float_t         zccz[1];   //[nzcc]
   Int_t           zccvalid[1];   //[nzcc]
   Int_t           nant;
   Int_t           antch[175];   //[nant]
   Float_t         antt0[175];   //[nant]
   Float_t         antt1[175];   //[nant]
   Float_t         anta0[175];   //[nant]
   Float_t         anta1[175];   //[nant]
   Float_t         antphi[175];   //[nant]
   Int_t           antst[175];   //[nant]
   Int_t           nmu;
   Int_t           much[48];   //[nmu]
   Float_t         mut0[48];   //[nmu]
   Float_t         mut1[48];   //[nmu]
   Float_t         mut2[48];   //[nmu]
   Float_t         mut3[48];   //[nmu]
   Float_t         mua0[48];   //[nmu]
   Float_t         mua1[48];   //[nmu]
   Float_t         mua2[48];   //[nmu]
   Float_t         mua3[48];   //[nmu]
   Int_t           must[48];   //[nmu]
   Int_t           nsim;
   Int_t           simtype[1];   //[nsim]
   Int_t           simorig[1];   //[nsim]
   Float_t         simmom[1];   //[nsim]
   Float_t         simphi[1];   //[nsim]
   Float_t         simtheta[1];   //[nsim]
   Float_t         simvtx[1];   //[nsim]
   Float_t         simvty[1];   //[nsim]
   Float_t         simvtz[1];   //[nsim]
   Int_t           ncorr;
   Int_t           idcorr[6];   //[ncorr]
   Int_t           bitcorr[6];   //[ncorr]
   Int_t           nbadbank;
   Int_t           nbadbankg;
   Int_t           nbadbanks[60];   //[nbadbankg]
   Int_t           nlostbanks;
   Int_t           ncorruptedbanks;
   Int_t           has_frontend[3];

   // List of branches
   TBranch        *b_ebeam;   //!
   TBranch        *b_emeas;   //!
   TBranch        *b_demeas;   //!
   TBranch        *b_emeas0;   //!
   TBranch        *b_demeas0;   //!
   TBranch        *b_xbeam;   //!
   TBranch        *b_ybeam;   //!
   TBranch        *b_runnum;   //!
   TBranch        *b_finalstate_id;   //!
   TBranch        *b_evnum;   //!
   TBranch        *b_trigbits;   //!
   TBranch        *b_trigmchs;   //!
   TBranch        *b_trigtime;   //!
   TBranch        *b_time;   //!
   TBranch        *b_dcfittime;   //!
   TBranch        *b_anttime;   //!
   TBranch        *b_mutime;   //!
   TBranch        *b_is_coll;   //!
   TBranch        *b_is_bhabha;   //!
   TBranch        *b_nt_total;   //!
   TBranch        *b_ecaltot;   //!
   TBranch        *b_ecalneu;   //!
   TBranch        *b_z0;   //!
   TBranch        *b_psumch;   //!
   TBranch        *b_psumnu;   //!
   TBranch        *b_lumoff;   //!
   TBranch        *b_lumofferr;   //!
   TBranch        *b_nv_total;   //!
   TBranch        *b_nv;   //!
   TBranch        *b_vtrk;   //!
   TBranch        *b_vind;   //!
   TBranch        *b_vchi;   //!
   TBranch        *b_vxyz;   //!
   TBranch        *b_nt;   //!
   TBranch        *b_it;   //!
   TBranch        *b_tnhit;   //!
   TBranch        *b_tlength;   //!
   TBranch        *b_tphi;   //!
   TBranch        *b_tth;   //!
   TBranch        *b_tptot;   //!
   TBranch        *b_tphiv;   //!
   TBranch        *b_tthv;   //!
   TBranch        *b_tptotv;   //!
   TBranch        *b_trho;   //!
   TBranch        *b_tdedx;   //!
   TBranch        *b_tz;   //!
   TBranch        *b_tt0;   //!
   TBranch        *b_tant;   //!
   TBranch        *b_tchi2r;   //!
   TBranch        *b_tchi2z;   //!
   TBranch        *b_tchi2ndf;   //!
   TBranch        *b_tcharge;   //!
   TBranch        *b_ten;   //!
   TBranch        *b_tfc;   //!
   TBranch        *b_tenlxe;   //!
   TBranch        *b_tlengthlxe;   //!
   TBranch        *b_tenslxe_layers;   //!
   TBranch        *b_tencsi;   //!
   TBranch        *b_tenbgo;   //!
   TBranch        *b_tclth;   //!
   TBranch        *b_tclphi;   //!
   TBranch        *b_terr;   //!
   TBranch        *b_terr0;   //!
   TBranch        *b_tindlxe;   //!
   TBranch        *b_tzcc;   //!
   TBranch        *b_txyzatcl;   //!
   TBranch        *b_txyzatlxe;   //!
   TBranch        *b_tenconv;   //!
   TBranch        *b_nks_total;   //!
   TBranch        *b_nks;   //!
   TBranch        *b_ksvind;   //!
   TBranch        *b_kstype;   //!
   TBranch        *b_ksfstatus;   //!
   TBranch        *b_ksvchi;   //!
   TBranch        *b_ksvxyz;   //!
   TBranch        *b_ksminv;   //!
   TBranch        *b_ksalign;   //!
   TBranch        *b_kstlen;   //!
   TBranch        *b_ksdpsi;   //!
   TBranch        *b_kslen;   //!
   TBranch        *b_ksz0;   //!
   TBranch        *b_ksphi;   //!
   TBranch        *b_ksth;   //!
   TBranch        *b_ksptot;   //!
   TBranch        *b_kspiphi;   //!
   TBranch        *b_kspith;   //!
   TBranch        *b_kspipt;   //!
   TBranch        *b_kserr;   //!
   TBranch        *b_ntlxe_total;   //!
   TBranch        *b_ntlxe;   //!
   TBranch        *b_ntlxelayers;   //!
   TBranch        *b_tlxenhit;   //!
   TBranch        *b_tlxelength;   //!
   TBranch        *b_tlxededx;   //!
   TBranch        *b_tlxeir;   //!
   TBranch        *b_tlxeitheta;   //!
   TBranch        *b_tlxeiphi;   //!
   TBranch        *b_tlxevtheta;   //!
   TBranch        *b_tlxevphi;   //!
   TBranch        *b_tlxechi2;   //!
   TBranch        *b_tlxesen;   //!
   TBranch        *b_tlxesen_layers;   //!
   TBranch        *b_nph_total;   //!
   TBranch        *b_nph;   //!
   TBranch        *b_phen;   //!
   TBranch        *b_phth;   //!
   TBranch        *b_phphi;   //!
   TBranch        *b_phrho;   //!
   TBranch        *b_phrad;   //!
   TBranch        *b_phen0;   //!
   TBranch        *b_phth0;   //!
   TBranch        *b_phphi0;   //!
   TBranch        *b_phlxe;   //!
   TBranch        *b_phslxe_layers;   //!
   TBranch        *b_pherr;   //!
   TBranch        *b_phcsi;   //!
   TBranch        *b_phbgo;   //!
   TBranch        *b_phflag;   //!
   TBranch        *b_phconv;   //!
   TBranch        *b_phfc;   //!
   TBranch        *b_nzcs_total;   //!
   TBranch        *b_nzcs;   //!
   TBranch        *b_zcsch;   //!
   TBranch        *b_zcsstat;   //!
   TBranch        *b_zcsamp;   //!
   TBranch        *b_zcstime;   //!
   TBranch        *b_zcsphi;   //!
   TBranch        *b_nzcc_total;   //!
   TBranch        *b_nzcc;   //!
   TBranch        *b_zccl;   //!
   TBranch        *b_zccns;   //!
   TBranch        *b_zccamp;   //!
   TBranch        *b_zcct;   //!
   TBranch        *b_zccz;   //!
   TBranch        *b_zccvalid;   //!
   TBranch        *b_nant;   //!
   TBranch        *b_antch;   //!
   TBranch        *b_antt0;   //!
   TBranch        *b_antt1;   //!
   TBranch        *b_anta0;   //!
   TBranch        *b_anta1;   //!
   TBranch        *b_antphi;   //!
   TBranch        *b_antst;   //!
   TBranch        *b_nmu;   //!
   TBranch        *b_much;   //!
   TBranch        *b_mut0;   //!
   TBranch        *b_mut1;   //!
   TBranch        *b_mut2;   //!
   TBranch        *b_mut3;   //!
   TBranch        *b_mua0;   //!
   TBranch        *b_mua1;   //!
   TBranch        *b_mua2;   //!
   TBranch        *b_mua3;   //!
   TBranch        *b_must;   //!
   TBranch        *b_nsim;   //!
   TBranch        *b_simtype;   //!
   TBranch        *b_simorig;   //!
   TBranch        *b_simmom;   //!
   TBranch        *b_simphi;   //!
   TBranch        *b_simtheta;   //!
   TBranch        *b_simvtx;   //!
   TBranch        *b_simvty;   //!
   TBranch        *b_simvtz;   //!
   TBranch        *b_ncorr;   //!
   TBranch        *b_idcorr;   //!
   TBranch        *b_bitcorr;   //!
   TBranch        *b_nbadbank;   //!
   TBranch        *b_nbadbankg;   //!
   TBranch        *b_nbadbanks;   //!
   TBranch        *b_nlostbanks;   //!
   TBranch        *b_ncorruptedbanks;   //!
   TBranch        *b_has_frontend;   //!

   kpkmExp(TTree *tree=0);
   virtual ~kpkmExp();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(std::string histFileName);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef kpkmExp_cxx
kpkmExp::kpkmExp(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      std::string fname = "";
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(fname.c_str());
      if (!f || !f->IsOpen()) {
         f = new TFile(fname.c_str());
      }
      f->GetObject("tr_ph",tree);
   }
   Init(tree);
}

kpkmExp::~kpkmExp()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t kpkmExp::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t kpkmExp::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void kpkmExp::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("ebeam", &ebeam, &b_ebeam);
   fChain->SetBranchAddress("emeas", &emeas, &b_emeas);
   fChain->SetBranchAddress("demeas", &demeas, &b_demeas);
   fChain->SetBranchAddress("emeas0", &emeas0, &b_emeas0);
   fChain->SetBranchAddress("demeas0", &demeas0, &b_demeas0);
   fChain->SetBranchAddress("xbeam", &xbeam, &b_xbeam);
   fChain->SetBranchAddress("ybeam", &ybeam, &b_ybeam);
   fChain->SetBranchAddress("runnum", &runnum, &b_runnum);
   fChain->SetBranchAddress("finalstate_id", &finalstate_id, &b_finalstate_id);
   fChain->SetBranchAddress("evnum", &evnum, &b_evnum);
   fChain->SetBranchAddress("trigbits", &trigbits, &b_trigbits);
   fChain->SetBranchAddress("trigmchs", &trigmchs, &b_trigmchs);
   fChain->SetBranchAddress("trigtime", &trigtime, &b_trigtime);
   fChain->SetBranchAddress("time", &time, &b_time);
   fChain->SetBranchAddress("dcfittime", &dcfittime, &b_dcfittime);
   fChain->SetBranchAddress("anttime", &anttime, &b_anttime);
   fChain->SetBranchAddress("mutime", &mutime, &b_mutime);
   fChain->SetBranchAddress("is_coll", &is_coll, &b_is_coll);
   fChain->SetBranchAddress("is_bhabha", &is_bhabha, &b_is_bhabha);
   fChain->SetBranchAddress("nt_total", &nt_total, &b_nt_total);
   fChain->SetBranchAddress("ecaltot", &ecaltot, &b_ecaltot);
   fChain->SetBranchAddress("ecalneu", &ecalneu, &b_ecalneu);
   fChain->SetBranchAddress("z0", &z0, &b_z0);
   fChain->SetBranchAddress("psumch", &psumch, &b_psumch);
   fChain->SetBranchAddress("psumnu", &psumnu, &b_psumnu);
   fChain->SetBranchAddress("lumoff", &lumoff, &b_lumoff);
   fChain->SetBranchAddress("lumofferr", &lumofferr, &b_lumofferr);
   fChain->SetBranchAddress("nv_total", &nv_total, &b_nv_total);
   fChain->SetBranchAddress("nv", &nv, &b_nv);
   fChain->SetBranchAddress("vtrk", vtrk, &b_vtrk);
   fChain->SetBranchAddress("vind", vind, &b_vind);
   fChain->SetBranchAddress("vchi", vchi, &b_vchi);
   fChain->SetBranchAddress("vxyz", vxyz, &b_vxyz);
   fChain->SetBranchAddress("nt", &nt, &b_nt);
   fChain->SetBranchAddress("it", it, &b_it);
   fChain->SetBranchAddress("tnhit", tnhit, &b_tnhit);
   fChain->SetBranchAddress("tlength", tlength, &b_tlength);
   fChain->SetBranchAddress("tphi", tphi, &b_tphi);
   fChain->SetBranchAddress("tth", tth, &b_tth);
   fChain->SetBranchAddress("tptot", tptot, &b_tptot);
   fChain->SetBranchAddress("tphiv", tphiv, &b_tphiv);
   fChain->SetBranchAddress("tthv", tthv, &b_tthv);
   fChain->SetBranchAddress("tptotv", tptotv, &b_tptotv);
   fChain->SetBranchAddress("trho", trho, &b_trho);
   fChain->SetBranchAddress("tdedx", tdedx, &b_tdedx);
   fChain->SetBranchAddress("tz", tz, &b_tz);
   fChain->SetBranchAddress("tt0", tt0, &b_tt0);
   fChain->SetBranchAddress("tant", tant, &b_tant);
   fChain->SetBranchAddress("tchi2r", tchi2r, &b_tchi2r);
   fChain->SetBranchAddress("tchi2z", tchi2z, &b_tchi2z);
   fChain->SetBranchAddress("tchi2ndf", tchi2ndf, &b_tchi2ndf);
   fChain->SetBranchAddress("tcharge", tcharge, &b_tcharge);
   fChain->SetBranchAddress("ten", ten, &b_ten);
   fChain->SetBranchAddress("tfc", tfc, &b_tfc);
   fChain->SetBranchAddress("tenlxe", tenlxe, &b_tenlxe);
   fChain->SetBranchAddress("tlengthlxe", tlengthlxe, &b_tlengthlxe);
   fChain->SetBranchAddress("tenslxe_layers", tenslxe_layers, &b_tenslxe_layers);
   fChain->SetBranchAddress("tencsi", tencsi, &b_tencsi);
   fChain->SetBranchAddress("tenbgo", tenbgo, &b_tenbgo);
   fChain->SetBranchAddress("tclth", tclth, &b_tclth);
   fChain->SetBranchAddress("tclphi", tclphi, &b_tclphi);
   fChain->SetBranchAddress("terr", terr, &b_terr);
   fChain->SetBranchAddress("terr0", terr0, &b_terr0);
   fChain->SetBranchAddress("tindlxe", tindlxe, &b_tindlxe);
   fChain->SetBranchAddress("tzcc", tzcc, &b_tzcc);
   fChain->SetBranchAddress("txyzatcl", txyzatcl, &b_txyzatcl);
   fChain->SetBranchAddress("txyzatlxe", txyzatlxe, &b_txyzatlxe);
   fChain->SetBranchAddress("tenconv", tenconv, &b_tenconv);
   fChain->SetBranchAddress("nks_total", &nks_total, &b_nks_total);
   fChain->SetBranchAddress("nks", &nks, &b_nks);
   fChain->SetBranchAddress("ksvind", ksvind, &b_ksvind);
   fChain->SetBranchAddress("kstype", kstype, &b_kstype);
   fChain->SetBranchAddress("ksfstatus", ksfstatus, &b_ksfstatus);
   fChain->SetBranchAddress("ksvchi", ksvchi, &b_ksvchi);
   fChain->SetBranchAddress("ksvxyz", ksvxyz, &b_ksvxyz);
   fChain->SetBranchAddress("ksminv", ksminv, &b_ksminv);
   fChain->SetBranchAddress("ksalign", ksalign, &b_ksalign);
   fChain->SetBranchAddress("kstlen", kstlen, &b_kstlen);
   fChain->SetBranchAddress("ksdpsi", ksdpsi, &b_ksdpsi);
   fChain->SetBranchAddress("kslen", kslen, &b_kslen);
   fChain->SetBranchAddress("ksz0", ksz0, &b_ksz0);
   fChain->SetBranchAddress("ksphi", ksphi, &b_ksphi);
   fChain->SetBranchAddress("ksth", ksth, &b_ksth);
   fChain->SetBranchAddress("ksptot", ksptot, &b_ksptot);
   fChain->SetBranchAddress("kspiphi", kspiphi, &b_kspiphi);
   fChain->SetBranchAddress("kspith", kspith, &b_kspith);
   fChain->SetBranchAddress("kspipt", kspipt, &b_kspipt);
   fChain->SetBranchAddress("kserr", kserr, &b_kserr);
   fChain->SetBranchAddress("ntlxe_total", &ntlxe_total, &b_ntlxe_total);
   fChain->SetBranchAddress("ntlxe", &ntlxe, &b_ntlxe);
   fChain->SetBranchAddress("ntlxelayers", ntlxelayers, &b_ntlxelayers);
   fChain->SetBranchAddress("tlxenhit", tlxenhit, &b_tlxenhit);
   fChain->SetBranchAddress("tlxelength", tlxelength, &b_tlxelength);
   fChain->SetBranchAddress("tlxededx", tlxededx, &b_tlxededx);
   fChain->SetBranchAddress("tlxeir", tlxeir, &b_tlxeir);
   fChain->SetBranchAddress("tlxeitheta", tlxeitheta, &b_tlxeitheta);
   fChain->SetBranchAddress("tlxeiphi", tlxeiphi, &b_tlxeiphi);
   fChain->SetBranchAddress("tlxevtheta", tlxevtheta, &b_tlxevtheta);
   fChain->SetBranchAddress("tlxevphi", tlxevphi, &b_tlxevphi);
   fChain->SetBranchAddress("tlxechi2", tlxechi2, &b_tlxechi2);
   fChain->SetBranchAddress("tlxesen", tlxesen, &b_tlxesen);
   fChain->SetBranchAddress("tlxesen_layers", tlxesen_layers, &b_tlxesen_layers);
   fChain->SetBranchAddress("nph_total", &nph_total, &b_nph_total);
   fChain->SetBranchAddress("nph", &nph, &b_nph);
   fChain->SetBranchAddress("phen", phen, &b_phen);
   fChain->SetBranchAddress("phth", phth, &b_phth);
   fChain->SetBranchAddress("phphi", phphi, &b_phphi);
   fChain->SetBranchAddress("phrho", phrho, &b_phrho);
   fChain->SetBranchAddress("phrad", phrad, &b_phrad);
   fChain->SetBranchAddress("phen0", phen0, &b_phen0);
   fChain->SetBranchAddress("phth0", phth0, &b_phth0);
   fChain->SetBranchAddress("phphi0", phphi0, &b_phphi0);
   fChain->SetBranchAddress("phlxe", phlxe, &b_phlxe);
   fChain->SetBranchAddress("phslxe_layers", phslxe_layers, &b_phslxe_layers);
   fChain->SetBranchAddress("pherr", pherr, &b_pherr);
   fChain->SetBranchAddress("phcsi", phcsi, &b_phcsi);
   fChain->SetBranchAddress("phbgo", phbgo, &b_phbgo);
   fChain->SetBranchAddress("phflag", phflag, &b_phflag);
   fChain->SetBranchAddress("phconv", phconv, &b_phconv);
   fChain->SetBranchAddress("phfc", phfc, &b_phfc);
   fChain->SetBranchAddress("nzcs_total", &nzcs_total, &b_nzcs_total);
   fChain->SetBranchAddress("nzcs", &nzcs, &b_nzcs);
   fChain->SetBranchAddress("zcsch", &zcsch, &b_zcsch);
   fChain->SetBranchAddress("zcsstat", &zcsstat, &b_zcsstat);
   fChain->SetBranchAddress("zcsamp", &zcsamp, &b_zcsamp);
   fChain->SetBranchAddress("zcstime", &zcstime, &b_zcstime);
   fChain->SetBranchAddress("zcsphi", &zcsphi, &b_zcsphi);
   fChain->SetBranchAddress("nzcc_total", &nzcc_total, &b_nzcc_total);
   fChain->SetBranchAddress("nzcc", &nzcc, &b_nzcc);
   fChain->SetBranchAddress("zccl", &zccl, &b_zccl);
   fChain->SetBranchAddress("zccns", &zccns, &b_zccns);
   fChain->SetBranchAddress("zccamp", &zccamp, &b_zccamp);
   fChain->SetBranchAddress("zcct", &zcct, &b_zcct);
   fChain->SetBranchAddress("zccz", &zccz, &b_zccz);
   fChain->SetBranchAddress("zccvalid", &zccvalid, &b_zccvalid);
   fChain->SetBranchAddress("nant", &nant, &b_nant);
   fChain->SetBranchAddress("antch", antch, &b_antch);
   fChain->SetBranchAddress("antt0", antt0, &b_antt0);
   fChain->SetBranchAddress("antt1", antt1, &b_antt1);
   fChain->SetBranchAddress("anta0", anta0, &b_anta0);
   fChain->SetBranchAddress("anta1", anta1, &b_anta1);
   fChain->SetBranchAddress("antphi", antphi, &b_antphi);
   fChain->SetBranchAddress("antst", antst, &b_antst);
   fChain->SetBranchAddress("nmu", &nmu, &b_nmu);
   fChain->SetBranchAddress("much", much, &b_much);
   fChain->SetBranchAddress("mut0", mut0, &b_mut0);
   fChain->SetBranchAddress("mut1", mut1, &b_mut1);
   fChain->SetBranchAddress("mut2", mut2, &b_mut2);
   fChain->SetBranchAddress("mut3", mut3, &b_mut3);
   fChain->SetBranchAddress("mua0", mua0, &b_mua0);
   fChain->SetBranchAddress("mua1", mua1, &b_mua1);
   fChain->SetBranchAddress("mua2", mua2, &b_mua2);
   fChain->SetBranchAddress("mua3", mua3, &b_mua3);
   fChain->SetBranchAddress("must", must, &b_must);
   fChain->SetBranchAddress("nsim", &nsim, &b_nsim);
   fChain->SetBranchAddress("simtype", &simtype, &b_simtype);
   fChain->SetBranchAddress("simorig", &simorig, &b_simorig);
   fChain->SetBranchAddress("simmom", &simmom, &b_simmom);
   fChain->SetBranchAddress("simphi", &simphi, &b_simphi);
   fChain->SetBranchAddress("simtheta", &simtheta, &b_simtheta);
   fChain->SetBranchAddress("simvtx", &simvtx, &b_simvtx);
   fChain->SetBranchAddress("simvty", &simvty, &b_simvty);
   fChain->SetBranchAddress("simvtz", &simvtz, &b_simvtz);
   fChain->SetBranchAddress("ncorr", &ncorr, &b_ncorr);
   fChain->SetBranchAddress("idcorr", idcorr, &b_idcorr);
   fChain->SetBranchAddress("bitcorr", bitcorr, &b_bitcorr);
   fChain->SetBranchAddress("nbadbank", &nbadbank, &b_nbadbank);
   fChain->SetBranchAddress("nbadbankg", &nbadbankg, &b_nbadbankg);
   fChain->SetBranchAddress("nbadbanks", nbadbanks, &b_nbadbanks);
   fChain->SetBranchAddress("nlostbanks", &nlostbanks, &b_nlostbanks);
   fChain->SetBranchAddress("ncorruptedbanks", &ncorruptedbanks, &b_ncorruptedbanks);
   fChain->SetBranchAddress("has_frontend", has_frontend, &b_has_frontend);
   Notify();
}

Bool_t kpkmExp::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void kpkmExp::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t kpkmExp::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef kpkmExp_cxx
