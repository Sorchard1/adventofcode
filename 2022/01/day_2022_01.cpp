//
// Created by simon on 23/02/23.
//
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>

namespace day202201 {
    int run() {
        std::string mystring;

        // Get the data path.
        std::filesystem::path cwd = std::filesystem::current_path();
        std::ifstream datafile;
        datafile.open(cwd / "data.txt");
        std::string myline;

        // Make space for data.
        std::vector<std::vector<int>> elf_calories;
        std::vector<int> calories;

        // Read the data file.
        if (datafile.is_open()) {
            while (datafile) {
                std::getline(datafile, myline);
                if (myline.length() == 0) {
                    // reset the buffer for a new elf.
                    elf_calories.push_back(calories);
                    calories = {};
                } else {
                    // Add a new calories entry for the current elf.
                    calories.push_back(std::stoi(myline));
                }
            }
        } else {
            std::cout << "\n File not open!";
        }

        // Find the calories each elf has.
        std::vector<int> elf_total_calories;
        int total_calories;
        for (auto &elf_calorie: elf_calories) {
            total_calories = 0;
            for (auto &calorie: elf_calorie) {
                // Add calories for the current elf.
                total_calories += calorie;

            }
            // Store the total calories for the current elf in a new vector.
            elf_total_calories.push_back(total_calories);
        }

        // Find the maximum calories.
        double max_calories = *max_element(elf_total_calories.begin(), elf_total_calories.end());

        // Part 1 answer
        std::cout << max_calories << "\n";

        // Make a vector for the top 3 total calories carried by each elf.
        std::vector<int> top_3_totals = {0, 0, 0};

        for (int elf_total_calorie: elf_total_calories) {
            // Replace values that are lower and step them down the vector (0 is maximum).
            if (elf_total_calorie > top_3_totals[0]) {
                top_3_totals[2] = top_3_totals[1];
                top_3_totals[1] = top_3_totals[0];
                top_3_totals[0] = elf_total_calorie;
            } else if (top_3_totals[0] >= elf_total_calorie & elf_total_calorie > top_3_totals[1]) {
                top_3_totals[2] = top_3_totals[1];
                top_3_totals[1] = elf_total_calorie;
            } else if (top_3_totals[1] >= elf_total_calorie & elf_total_calorie > top_3_totals[2]) {
                top_3_totals[2] = elf_total_calorie;
            }
        }

        // Part 2 answer
        std::cout << top_3_totals[0] + top_3_totals[1] + top_3_totals[2] << "\n";

        return 0;
    }
}

