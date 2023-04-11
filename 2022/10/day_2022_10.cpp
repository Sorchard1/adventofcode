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

        const int screen_x = 40;
        const int screen_y = 6;
        std::vector<bool> line_lit;
        std::vector<std::vector<bool>> screen_lit;
        for (int i = 0; i < screen_x; i++) {
            line_lit.push_back(false);
        }
        for (int j = 0; j < screen_y; j++) {
            screen_lit.push_back(line_lit);
        }

        int index = 0;
        int reg_index;

        for (int j = 0; j < screen_y; j++) {
            for (int i = 0; i < screen_x; i++) {
                if (index == 0) {
                    reg_index = 0;
                }
                else {
                    reg_index = index - 1;
                }
                if (std::abs(registers[reg_index] - i) <= 1) {

                    screen_lit[j][i] = true;
                }
                index += 1;
            }
        }

        for (int j = 0; j < screen_y; j++) {
            for (int i = 0; i < screen_x; i++) {
                if (screen_lit[j][i]) {
                    std::cout << "#";
                } else {
                    std::cout << ".";
                }
            }
            std::cout << "\n";

        }

        std::cout << "Part 2 manually read off as: RZEKEFHA\n";
        return 0;
    }
}
