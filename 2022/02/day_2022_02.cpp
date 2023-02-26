//
// Created by simon on 25/02/23.
//
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>
#include <cassert>

namespace day202202 {

    int their_int(char input){
        // Change A, B, C to 0, 1, 2.
        int theirs;

        if (input == 'A'){
            theirs = 0;
        }
        else if (input == 'B'){
            theirs = 1;
        }
        else if (input == 'C'){
            theirs = 2;
        }
        else {
            //Handle error
            theirs = -1;
        }
        return theirs;
    }

    int my_int(char input){
        // Change X, Y, Z to 0, 1, 2.
        int mine;

        if (input == 'X'){
            mine = 0;
        }
        else if (input == 'Y'){
            mine = 1;
        }
        else if (input == 'Z'){
            mine = 2;
        }
        else {
            //Handle error
            mine = -1;
        }
        return mine;
    }

    int run(std::filesystem::path data_path)
    {

        std::ifstream datafile;
        datafile.open(data_path);
        std::string myline;
        int theirs;
        int mine;
        // Make space for data.
        std::vector<int> strategy_guide_theirs;
        std::vector<int> strategy_guide_mine;

        // Read the data file.
        if (datafile.is_open()) {
            while (datafile) {
                std::getline(datafile, myline);

                // Save to int 0, 1, 2 for A, B, C or X, Y, Z.
                theirs = their_int(myline[0]);
                mine = my_int(myline[2]);

                if (theirs != -1 & mine != -1){
                    strategy_guide_theirs.push_back(theirs);
                    strategy_guide_mine.push_back(mine);
                }

            }
        }
        else {
            std::cout << "\n File not open!";
        }

        int difference;
        int score = 0;
        for (int i = 0; i < strategy_guide_theirs.size(); i++) {
            difference = strategy_guide_theirs[i] - strategy_guide_mine[i];

            if (difference == -1 or difference == 2){
                // Win adds 6, (+1 rock, +2 paper, +3 scissors).
                score += 6 + strategy_guide_mine[i] + 1;
                std::cout << "win " << 6 + strategy_guide_mine[i] + 1 << "\n";
            }
            else if (difference == 1 or difference == -2){
                // Loss adds 0, (+1 rock, +2 paper, +3 scissors).
                score += strategy_guide_mine[i] + 1;
                std::cout << "loss " << strategy_guide_mine[i] + 1 << "\n";

            }
            else {
                // Draw when difference is 0
                assert (difference == 0);

                // Draw adds 3, (+1 rock, +2 paper, +3 scissors).
                score += 3 + strategy_guide_mine[i] + 1;
                std::cout << "draw " << 3 + strategy_guide_mine[i] + 1 << "\n";
            }
        }

        std::cout << "score " << score << "\n";

        return 0;
    }
}
