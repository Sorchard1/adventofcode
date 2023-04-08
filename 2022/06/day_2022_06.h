//
// Created by simon on 30/03/23.
//

#ifndef ADVENTOFCODE_DAY_2022_06_H
#define ADVENTOFCODE_DAY_2022_06_H

#include <vector>

namespace day202206 {
    int get_first_unique_end_index(std::string& input_string, int unique_length, unsigned int line_length);
    int run(std::filesystem::path data_path);
}

#endif //ADVENTOFCODE_DAY_2022_06_H
