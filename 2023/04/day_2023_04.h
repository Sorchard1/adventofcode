//
// Created by simon on 02/11/23.
//

#ifndef ADVENTOFCODE_DAY_2023_04_H
#define ADVENTOFCODE_DAY_2023_04_H
#include <unordered_set>

namespace day202304 {
    int append_numbers(const std::string& input_string, std::vector<int>& vector_store);
    int append_set(const std::string& input_string, std::unordered_set<int>& wining_set);
        int run(std::filesystem::path data_path);
}

#endif //ADVENTOFCODE_DAY_2023_04_H
