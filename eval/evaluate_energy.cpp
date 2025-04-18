/*
 * Driver code to evaluate K^{\pm} energies. Check out `Energy.hpp` file.
 *
 * Developed by Daniel Ivanov (daniilivanov1606@gmail.com)
 */
#include <vector>
#include <iostream>
#include <chrono>
#include <regex>

#include "Energy.hpp"

int evaluate_energy(std::string root_dir = "./")
{
    gROOT->Reset();
    auto start = std::chrono::system_clock::now();

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

    std::map<std::string, std::vector<std::string>> input_files = {{"Phi2018", phi_2018}, {"Phi2024", phi_2024}};

    // *********************** Setup: start ***********************
    auto target_name = "Phi2024";
    auto target = input_files[target_name];
    std::string output_dir = root_dir + "results/" + target_name + "/";
    std::string input_dir = root_dir + "data/" + target_name + "/";
    std::string badRuns = "";
    // *********************** Setup: end ***********************

    std::map<std::string, Energy *> energies;

    auto get_point_name = [](std::string input)
    {
        std::regex pattern(R"(scan(\d{4})_e(\d+)(?:\.(\d+))?)");
        std::smatch matches;

        if (std::regex_search(input, matches, pattern))
        {
            if (matches[3].matched)
            { return matches[0].str(); }
            else
            { return "scan" + matches[1].str() + "_e" + matches[2].str(); }
        }
        return std::string("error_in_pattern_matching");
    };

    auto make_safe_name = [](std::string name){
        for (char& current : name) 
        {
            if(current == '.')
            { current = '_'; }
        }
        return name;
    };

    for (const auto &input : target)
    {
        auto point_name = get_point_name(input);
        std::cout << "Start processing: " << point_name << std::endl;
        auto output_hist_path = output_dir + "hists/" + "tot_hist_" + point_name + ".root";
        auto output_graph_path = output_dir + "graphs/" + "graph_" + point_name + ".root";
        energies[point_name] = new Energy(input_dir + input, badRuns);
        energies[point_name]->SaveMergedHist(output_hist_path, make_safe_name(point_name));
        energies[point_name]->DrawGraph(output_graph_path);
        std::cout << "Finished processing: " << point_name << std::endl;
        std::cout << "Files saved: " << std::endl << "\t *" << output_hist_path << std::endl << "\t *" << output_graph_path << std::endl << std::endl;
    }

    for (auto &handler : energies)
    { delete handler.second; }

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "exec time = " << diff.count() << " s" << std::endl;
    return 0;
}
