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

namespace day202210 {

    int run(std::filesystem::path data_path)
    {

        std::ifstream datafile;
        datafile.open(data_path);
        std::string myline;

        std::vector<int> registers;
        int current_register = 1;
        int split_index;
        int counter = 0;

        // Read the data file.
        if (datafile.is_open()) {
            while (datafile) {
                std::getline(datafile, myline);
                if (myline.length()!=0) {
                    if (myline[0] == 'a') {
                        // Extra push back for this command
                        registers.push_back(current_register);
                        counter += 1;

                        // For adding strengths
                        split_index =  myline.find(" ") + 1;
                        current_register += std::stoi(myline.substr(split_index));

                    }
                    counter += 1;

                    if (counter < 221) {
                        std::cout << counter << " " << current_register << " " << myline << "\n";
                    }
                    registers.push_back(current_register);
                }
            }
        }
        else {
            std::cout << "\n File not open!";
        }

        int strength = 0;
        std::vector<int> cycles = {20, 60, 100, 140, 180, 220};
        for (int cycle :cycles){
            // THe -2 is -1 for indexing and -1 because cycle has not completed.
            strength += cycle * registers[cycle - 2];
            std::cout << cycle << " " << registers[cycle - 2] << "\n";

        }

        std::cout << "Part 1 " << strength << "\n";
        return 0;
    }
}
