//
// Created by simon on 02/11/23.
//
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>
#include <unordered_set>
#include <cmath>


namespace day202304 {
    int append_numbers(const std::string& input_string, std::vector<int>& vector_store){
        std::string current_num;

        for (char i : input_string) {
            if (i == ' ' & current_num.length() > 0) {
                vector_store.push_back(std::stoi(current_num));
                //reset string
                current_num = "";
            }
            else if (i == ' '){
                //Do nothing
            }
            else {
                current_num += i;
            }
        }
        // Append the last number
        if (current_num.length() > 0) {
            vector_store.push_back(std::stoi(current_num));
        }

    }
    int append_set(const std::string& input_string, std::unordered_set<int>& wining_set){
        std::string current_num;

        for (char i : input_string) {
            if (i == ' ' & current_num.length() > 0) {
                wining_set.insert(std::stoi(current_num));
                //reset string
                current_num = "";
            }
            else if (i == ' '){
                //Do nothing
            }
            else {
                current_num += i;
            }
        }
        // Append the last number
        if (current_num.length() > 0) {
            wining_set.insert(std::stoi(current_num));
        }

    }

    int run(std::filesystem::path data_path)
    {

        std::ifstream datafile;
        datafile.open(data_path);
        std::string myline;

        std::vector<int> number_line;
        std::vector<std::vector<int>> card_nums;
        std::string wining_string;
        std::string card_string;
        int line_length;
        unsigned long start_wining;
        unsigned long end_wining;
        std::string current_num;
        std::vector<std::unordered_set<int>> wining_set;
        std::unordered_set<int> sub_set;
        int points;
        int n_winners;
        // Read the data file.
        if (datafile.is_open()) {
            while (datafile) {
                std::getline(datafile, myline);
                line_length = myline.length();
                if (line_length!=0) {

                    start_wining = myline.find(": ") + 2;
                    end_wining = myline.find(" |");
                    wining_string = myline.substr(start_wining, end_wining - start_wining);
                    card_string = myline.substr(end_wining + 3, line_length - end_wining);

                    append_set(wining_string, sub_set);
                    wining_set.push_back(sub_set);
                    sub_set.clear();

                    append_numbers(card_string, number_line);
                    card_nums.push_back(number_line);
                    number_line.clear();
                }
            }
        }

        points = 0;
        for (int i = 0; i<card_nums.size(); i++) {
            n_winners = 0;
            for (int j = 0; j<card_nums[i].size(); j++) {
                if(wining_set[i].find(card_nums[i][j]) != wining_set[i].end()){
                    n_winners += 1;
                }

            }
            if (n_winners > 0){
                // Raise to 2 to the power of winners - 1. Could be done without moving from int and back
                points += std::pow(2, n_winners - 1);
            }
        }

        std::cout << "Part 1:" << points << "\n";

        return 0;
    }
}

