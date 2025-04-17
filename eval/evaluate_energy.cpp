/*
* Driver code to evaluate K^{\pm} energies. Check out `Energy.hpp` file.
* 
* Developed by Daniel Ivanov (daniilivanov1606@gmail.com)
*/
#include <vector>
#include <iostream>
#include <chrono>

#include "Energy.hpp"

int evaluate_energy(std::string root_dir)
{
    gROOT->Reset();
    auto start = std::chrono::system_clock::now();
    std::string output_dir = root_dir + "data/Phi2018/";

    std::string input_dir = root_dir + "data/Phi2018/";    
    std::vector<std::string> phi_2018 = {
        "kpkm_scan2018_e501.root",
        "kpkm_scan2018_e503.root",
        "kpkm_scan2018_e505.root",
        "kpkm_scan2018_e508.5.root",
        "kpkm_scan2018_e508.root",
        "kpkm_scan2018_e509.5.root",
        "kpkm_scan2018_e509.root",
        "kpkm_scan2018_e510.5.root",
        "kpkm_scan2018_e510.root",
        "kpkm_scan2018_e511.5.root",
        "kpkm_scan2018_e511.root",
        "kpkm_scan2018_e514.root",
        "kpkm_scan2018_e517.root",
        "kpkm_scan2018_e520.root",
        "kpkm_scan2018_e525.root",
        "kpkm_scan2018_e530.root",
    };
    std::vector<std::string> phi_2024 = {
        "kpkm_scan2024_e500.root",
        "kpkm_scan2024_e501.root",
        "kpkm_scan2024_e503.root",
        "kpkm_scan2024_e505.root",
        "kpkm_scan2024_e506.5.root",
        "kpkm_scan2024_e508.root",
        "kpkm_scan2024_e508.5.root",
        "kpkm_scan2024_e509.root",
        "kpkm_scan2024_e509.5.root",
        "kpkm_scan2024_e510.root",
        "kpkm_scan2024_e510.5.root",
        "kpkm_scan2024_e511.root",
        "kpkm_scan2024_e511.5.root",
        "kpkm_scan2024_e512.5.root",
        "kpkm_scan2024_e512.5.root",
        "kpkm_scan2024_e515.root",
        "kpkm_scan2024_e520.root",
    };
    
    std::string badRuns = "";
    std::map<std::string, Energy*> energies;

    auto get_point_name = [](std::string input) {
        size_t underscore_pos = input.find('_');
        size_t dot_pos = input.find('.');
        std::string scan_id = input.substr(underscore_pos + 1, dot_pos - underscore_pos - 1);
        return scan_id;
    };

    for(const auto& input : phi_2018)
    {
        auto point_name = get_point_name(input);
        auto output_hist_path = output_dir + "hists/" + "tot_hist_" + point_name + ".root";
        auto output_graph_path = output_dir + "graphs/" + "graph_" + point_name + ".root";
        energies[point_name] = new Energy(input_dir + input, badRuns);   
        energies[point_name]->SaveMergedHist(output_hist_path, point_name);
        energies[point_name]->DrawGraph(output_graph_path);
    }

    for(auto &handler : energies)
    { delete handler.second; }

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end - start; 
    std::cout << "exec time = " << diff.count() << std::endl;
    return 0;
}