//
// Created by simon on 02/12/23.
//

#ifndef ADVENTOFCODE_DAY_2023_01_H
#define ADVENTOFCODE_DAY_2023_01_H

namespace day202301 {
    int run(std::filesystem::path data_path);
    int find_substring(int index, std::string& substring, std::unordered_map<int, std::string>& single_number_map, bool reverse, bool part_1);
}

#endif //ADVENTOFCODE_DAY_2023_01_H
