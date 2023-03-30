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

namespace day202203 {
    int char_to_priority(char input)
    {
        int input_int = (int) input-64;
        if (input_int>32) {
            assert (input_int<59);
            return input_int-32;
        }
        else {
            assert (input_int>0);
            assert (input_int<27);
            return input_int+26;
        }
    }

    int run(std::filesystem::path data_path)
    {

        std::ifstream datafile;
        datafile.open(data_path);
        std::string myline;

        // Make space for data.
        std::vector<std::vector<int>> compartment_array_1;
        std::vector<std::vector<int>> compartment_array_2;
        std::vector<std::vector<int>> rucksack_array;
        unsigned int rucksack_size;
        unsigned int half_rucksack_size;
        std::vector<int> compartment1;
        std::vector<int> compartment2;
        std::vector<int> rucksack;

        // Read the data file.
        if (datafile.is_open()) {
            while (datafile) {
                std::getline(datafile, myline);
                if (myline.length()!=0) {
                    rucksack_size = myline.length();
                    half_rucksack_size = rucksack_size/2;
                    for (int i = 0; i<half_rucksack_size; i++) {
                        compartment1.push_back(char_to_priority(myline[i]));
                        compartment2.push_back(char_to_priority(myline[i+half_rucksack_size]));

                    }
                    for (int i = 0; i<rucksack_size; i++) {
                        rucksack.push_back(char_to_priority(myline[i]));
                    }
                    compartment_array_1.push_back(compartment1);
                    compartment_array_2.push_back(compartment2);
                    rucksack_array.push_back(rucksack);
                    compartment1.clear();
                    compartment2.clear();
                    rucksack.clear();

                }
            }
        }
        else {
            std::cout << "\n File not open!";
        }

        // Search for repeated values in each vector. If there is one repeat, then add it to the priority score.
        int priority_sum = 0;
        for (int i = 0; i<compartment_array_1.size(); i++) {
            for (int j = 0; j<compartment_array_1[i].size(); j++) {
                if (std::find(compartment_array_2[i].begin(), compartment_array_2[i].end(), compartment_array_1[i][j])
                        !=compartment_array_2[i].end()) {
                    // found the repeated value
                    priority_sum += compartment_array_1[i][j];

                    // only check the value is in the other case once.
                    break;
                }
            }

        }
        //
        std::cout << "part 1 " << priority_sum << " \n ";

        unsigned int n_groups = compartment_array_1.size()/3;
        int badge_priority_sum = 0;

        for (int i = 0; i<n_groups; i++) {
            for (int j = 0; j<rucksack_array[i*3].size(); j++) {
                if (std::find(rucksack_array[i*3+1].begin(), rucksack_array[i*3+1].end(), rucksack_array[i*3][j])
                        !=rucksack_array[i*3+1].end()) {

                    if (std::find(rucksack_array[i*3+2].begin(), rucksack_array[i*3+2].end(), rucksack_array[i*3][j])
                            !=rucksack_array[i*3+2].end()) {
                        badge_priority_sum += rucksack_array[i*3][j];
                        break;
                    }
                }
            }
        }
        std::cout << "part 2 " << badge_priority_sum << " ";

        return 0;
    }
}
