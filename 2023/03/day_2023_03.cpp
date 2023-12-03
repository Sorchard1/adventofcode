//
// Created by simon on 02/12/23.
//
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>
#include <algorithm>

namespace day202303 {
    int run(std::filesystem::path data_path)
    {

        std::ifstream datafile;
        datafile.open(data_path);
        std::string myline;

        std::vector<std::string> file_content;

        if (datafile.is_open()) {
            while (datafile) {
                std::getline(datafile, myline);
                if (myline.length()!=0) {
                    file_content.push_back(myline);
                }
            }
        }


        int line_length;

        for (int i = 0; i<file_content.size(); i++) {
            std::cout << file_content[i]  << "\n";

        }

        int digit;
        int index_word_start;
        int index_word_end;
        int index_line_before;
        int index_line_after;
        int number_length;
        std::string current_number;
        std::unordered_map<char, bool> symbol_map = {
                {'.', false}, {'0', false}, {'1', false}, {'2', false}, {'3', false},
                {'4', false}, {'5', false}, {'6', false}, {'7', false}, {'8', false},
                {'9', false}, {'*', true}, {'#', true}, {'$', true}, {'+', true},
                {'@', true},  {'%', true},  {'/', true},  {'=', true},  {'&', true},
                {'-', true}
        };

        int n_lines = file_content.size();
        bool is_part_number = false;
        bool number_ended = false;
        int total_sum = 0;

        // Save asterisk location for part 2
        std::unordered_map<int, std::unordered_map<int, int>> asterisk_counts;
        std::unordered_map<int, std::unordered_map<int, int>> asterisk_total;
        std::unordered_map<int, int> asterisk_entry_2;
        std::unordered_map<int, int> asterisk_entry_2_copy;

        int asterisk_count = 0;
        for (int i = 0; i<n_lines; i++) {
            line_length = file_content[i].size();
            // find a number
            for (int j = 0; j<line_length; j++) {
                if (file_content[i][j]=='*') {
                    // The vector is {number of parts, sum of parts}
                    asterisk_entry_2[j] = 0;
                    asterisk_counts.insert({i, asterisk_entry_2});
                    asterisk_entry_2.clear();

                    asterisk_entry_2[j] = 1;
                    asterisk_total[i] = asterisk_entry_2;
                    asterisk_entry_2.clear();
                    asterisk_count += 1;
                }
            }
        }


        for (int i = 0; i<n_lines; i++) {
            line_length = file_content[i].size();
            // find a number
            for (int j = 0; j<line_length; j++) {
                number_ended = false;
                digit = file_content[i][j]-'0';
                if (digit <= 9 & digit >=0) {
                    current_number += file_content[i][j];
                    if (j == line_length - 1){
                        number_ended = true;
                    }
                }
                else if (current_number.length() > 0) {
                    number_ended = true;
                }

                if (number_ended){
                    // The string has ended, check the surroundings for a special character.
                    number_length = current_number.length();
                    index_word_start = j - number_length - 1;
                    index_word_start = std::max(index_word_start, 0);
                    index_word_end = std::min(j + 1, line_length);
                    // Loop over the perimeter of the number. check for true
                    // clamp the boundaries of the previous and next lines.
                    index_line_before = std::max(i - 1, 0);
                    index_line_after =  std::min(i + 2, n_lines);

                    // If a symbol is true then it is a part number.
                    for (int k=index_word_start; k<index_word_end; k++) {
                        for (int l=index_line_before; l<index_line_after; l++) {
                            if (symbol_map.at(file_content[l][k])){
                                is_part_number = true;
                            }
                        }
                    }

                    // If it is a part number, then include it in the sum.
                    if (is_part_number) {
                        total_sum += std::stoi(current_number);
                        // If it is a part number, check the asterisks and add to them
                        for (int k=index_word_start; k<index_word_end; k++) {
                            for (int l=index_line_before; l<index_line_after; l++) {
                                if (file_content[l][k] == '*') {
                                    asterisk_counts[l][k] += 1;
                                    if (asterisk_total[l][k] == 0){
                                        asterisk_total[l][k] = 1;
                                    }


                                    asterisk_total[l][k] *= std::stoi(current_number);
                                }
                            }
                        }
                    }
                    // Reset the string
                    current_number = "";
                    is_part_number = false;

                }
            }
        }
        int part_2_sum = 0;
        // Iterate over unordered map of unordered maps with the iterator,
        for (const auto& it: asterisk_counts) {
            for (const auto& it_2: asterisk_counts[it.first]) {
                if (asterisk_counts[it.first][it_2.first] == 2) {
                    part_2_sum += asterisk_total[it.first][it_2.first];
                }
            }
        }

        std::cout << "part 1 answer is " << total_sum << "\n";
        std::cout << "part 2 answer is " << part_2_sum << "\n";
        return 0;
    }
}

