//
// Created by simon on 02/12/23.
//
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>

namespace day202301 {
    int run(std::filesystem::path data_path)
    {

        std::ifstream datafile;
        datafile.open(data_path);
        std::string myline;
        int value;
        std::string new_string;
        std::vector<int> first_integer;
        std::vector<int> last_integer;
        unsigned int line_length;
        int part_1_answer;
        // Read the data file.
        if (datafile.is_open()) {
            while (datafile) {
                std::getline(datafile, myline);
                line_length = myline.length();
                for (int i = 0; i<line_length; i++) {
                    value = myline[i]-'0';
                    if (value <= 9) {
                        first_integer.push_back(value);
                        break;

                    }
                }
                // reversed loop from end of line
                for (int i = 0; i<line_length; i++) {
                    value = myline[line_length-i-1]-'0';
                    if (value <= 9) {
                        last_integer.push_back(value);
                        break;
                    }
                }
            }
        }
        // add together the numbers
        for (int i = 0; i<first_integer.size(); i++) {
            part_1_answer += 10*first_integer[i] + last_integer[i];
        }

        std::cout << "Answer to part 1 is: " << part_1_answer << "\n";
        return 0;
    }
}

