//
// Created by simon on 25/02/23.
//

#ifndef ADVENTOFCODE_DAY_2022_02_H
#define ADVENTOFCODE_DAY_2022_02_H

#include <vector>

namespace day202202 {
    int their_int(char input);

    int my_int(char input);

    int get_score(std::vector<int>& strategy_guide_theirs, std::vector<int>& strategy_guide_mine);

    int run(std::filesystem::path data_path);
}

#endif //ADVENTOFCODE_DAY_2022_02_H
