/*
* Event selection driver code for the e^{+}e^{-} -> K^{+}K^{-} process.
* Developed by Daniel Ivanov (daniilivanov1606@gmail.com)
*/


#include "TFile.h"
#include "TROOT.h"
#include "TTree.h"
#include <iostream>

int select(std::string macro_file, std::string macro_name, std::string root_filename, std::string output_fname) {
    gROOT->LoadMacro(macro_file.c_str());
    auto file = TFile::Open(root_filename.c_str());
    gROOT->ProcessLine((macro_name + " a(tr_ph)").c_str());
    gROOT->ProcessLine(("a.Loop(\"" + output_fname + "\")").c_str());
    return 0;
}