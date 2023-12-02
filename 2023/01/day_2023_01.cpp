//
// Created by simon on 02/12/23.
//
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>
#include <algorithm>

int find_substring(int index, std::string& full_line, std::unordered_map<int, std::string>& single_number_map, bool reverse, bool part_1){
    unsigned int found_substring_index;
    std::string substring;
    int value;

    // Make the substring
    if (reverse){
        substring = full_line.substr(index, full_line.length() + 1);
    }
    else {
        substring = full_line.substr(0, index+1);
    }

    value = full_line[index]-'0';
    if (value <= 9) {
        return value;
    }

    // Terminate early for part 1
    if (part_1){
        return -1;

    }

    for (int i = 0; i < single_number_map.size(); i++) {
        found_substring_index = substring.find(single_number_map[i]);

        if (found_substring_index<=full_line.length()) {
            return i;
        }

    }
    return -1;
}


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
        std::string sanitised_line;
        int found_substring_index;
        std::vector<std::string> number_strings = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        std::vector<std::string> number_values = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
        std::unordered_map<int, std::string> single_number_map = {
                {0, "zero"}, {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"},
                {5, "five"}, {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"}
        };
        bool is_part_1 = true;
        int part_answer = 0;
        // Read the data file.
        if (datafile.is_open()) {
            while (datafile) {
                std::getline(datafile, myline);
                sanitised_line = myline;
                // santitise the first found number from the left then stop
                std::cout << "line at:" << myline << "\n";
                for (int i = 0; i<myline.length(); i++) {
                    value = find_substring(i, myline, single_number_map, false, is_part_1);
                    if (value != -1){
                        std::cout << "substrval at:" << value << " For the line " << myline << "\n";
                        first_integer.push_back(value);
                        break;
                    }
                }

                // reversed loop from end of line
                for (int i = 0; i<myline.length(); i++) {
                    value = find_substring(myline.length()-i-1, myline, single_number_map, true, is_part_1);
                    if (value != -1){
                        std::cout << "substrval at:" << value << " For the line " << myline << "\n";
                        last_integer.push_back(value);
                        break;
                    }
                }
            }
        }

        // add together the numbers
        for (int i = 0; i<first_integer.size(); i++) {
            part_answer += 10*first_integer[i] + last_integer[i];
        }

        if (is_part_1){
            std::cout << "Answer to part 1 is: " << part_answer << "\n";

        }
        else {
            std::cout << "Answer to part 2 is: " << part_answer << "\n";

        }
        return 0;
    }
}

