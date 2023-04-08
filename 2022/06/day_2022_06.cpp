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

namespace day202206 {
    int get_first_unique_end_index(std::string& input_string, int unique_length, unsigned int line_length) {
        // Get the index of the first unique string of specified length
        int current_index = 0;
        std::string substring;
        std::unordered_map<char, int> string_map;

        while (current_index < line_length - unique_length){
            string_map.clear();
            substring = input_string.substr(current_index, unique_length);
            for (int i = 0; i < unique_length; i++) {
                string_map[substring[i]] = 1;
            }

            if (string_map.size() == unique_length){
                break;
            }
            current_index += 1;
        }
        return current_index + unique_length;
    }

    int run(std::filesystem::path data_path)
    {

        std::ifstream datafile;
        datafile.open(data_path);
        std::string myline;
        unsigned int line_length;
        int part_1;
        int part_2;

        // Read the data file.
        if (datafile.is_open()) {
            while (datafile) {
                std::getline(datafile, myline);
                line_length = myline.length();
                if (line_length!=0) {
                    // Move through the line
                    part_1 = get_first_unique_end_index(myline, 4, line_length);
                    part_2 = get_first_unique_end_index(myline, 14, line_length);

                    std::cout << "Part 1 " << part_1 << "\n";
                    std::cout << "Part 2 " << part_2 << "\n";
                }
            }
        }
        else {
            std::cout << "\n File not open!";
        }
        return 0;
    }
}
