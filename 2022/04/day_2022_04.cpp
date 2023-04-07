//
// Created by simon on 30/03/23.
//
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>
#include <cassert>
#include <algorithm>

namespace day202204 {

    std::vector<std::string> split_string(std::string input_string, std::string delimiter){
        unsigned int split_index;
        std::vector<std::string> split_string;
        split_index =  input_string.find(delimiter);
        split_string.push_back(input_string.substr(0, split_index));
        split_string.push_back(input_string.substr(split_index + 1, input_string.length()));
        return split_string;
    }

    int run(std::filesystem::path data_path)
    {

        std::ifstream datafile;
        datafile.open(data_path);
        std::string myline;

        std::vector<int> pair_1_starts;
        std::vector<int> pair_1_ends;
        std::vector<int> pair_2_starts;
        std::vector<int> pair_2_ends;
        std::vector<std::string> pairs;
        std::vector<std::string> value;

        // Read the data file.
        if (datafile.is_open()) {
            while (datafile) {
                std::getline(datafile, myline);
                if (myline.length()!=0) {
                    pairs = split_string(myline, ",");
                    value = split_string(pairs[0], "-");
                    pair_1_starts.push_back(std::stoi(value[0]));
                    pair_1_ends.push_back(std::stoi(value[1]));
                    value = split_string(pairs[1], "-");
                    pair_2_starts.push_back(std::stoi(value[0]));
                    pair_2_ends.push_back(std::stoi(value[1]));
                }
            }
        }
        else {
            std::cout << "\n File not open!";
        }
        int count = 0;

        for (int i = 0; i<pair_1_starts.size(); i++) {
            if (pair_1_starts[i] >= pair_2_starts[i] and pair_1_ends[i] <= pair_2_ends[i]) {
                count += 1;

            }
            else if ((pair_1_starts[i] <= pair_2_starts[i] and pair_1_ends[i] >= pair_2_ends[i])) {
                count += 1;
            }
        }
        std::cout << "Part 1 " << count << "\n";
        int overlaps = 0;

        for (int i = 0; i<pair_1_starts.size(); i++) {
            if (pair_1_starts[i] > pair_2_ends[i]) {
                continue;
            }
            else if (pair_2_starts[i] > pair_1_ends[i]) {
                continue;
            }
            else {
                std::cout << pair_1_starts[i] << " "<< pair_1_ends[i] << " " << pair_2_starts[i] << " " << pair_2_ends[i] << "\n";
                overlaps += 1;

            }
        }
        std::cout << "Part 2 " << overlaps;
        return 0;
    }

}
