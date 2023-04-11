//
// Created by simon on 30/03/23.
//

#ifndef ADVENTOFCODE_DAY_2022_09_H
#define ADVENTOFCODE_DAY_2022_09_H

#include <vector>

namespace day202209 {
    int sign(int input);
    std::vector<int> next_knot_movement(int x_front, int y_front, int x_current, int y_current);
    int run(std::filesystem::path data_path);
}

#endif //ADVENTOFCODE_DAY_2022_09_H
