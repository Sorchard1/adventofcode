//
// Created by simon on 30/03/23.
//
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>
#include <cassert>
#include <algorithm>
#include <deque>

namespace day202205 {

    int run(std::filesystem::path data_path)
    {

        std::ifstream datafile;
        datafile.open(data_path);
        std::string myline;
        bool header_loaded = false;

        std::unordered_map<int, std::deque<std::string>> crate_stacks;
        std::string letter;
        std::vector<int> n_moving;
        std::vector<int> move_from;
        std::vector<int> move_to;
        std::string new_string;
        bool part_1 = false;
        unsigned int split_index;

        // Read the data file.
        if (datafile.is_open()) {
            while (datafile) {
                std::getline(datafile, myline);
                if (myline.length()!=0 and (not header_loaded)) {
                    // When all the letters are sorted, the number 1 is entered
                    if (myline.substr(1, 1) != "1"){
                        // Read in the header
                        // There are 4 characters per entry "[A] " except no gap on the last
                        for (int i = 0; i<(myline.length() + 1)/4; i++){
                            letter = myline[ i * 4 + 1];
                            // if there is a letter in this column
                            if (letter != " ") {
                                // Make a new stack
                                if (crate_stacks.find(i) != crate_stacks.end()){
                                    crate_stacks.insert({{i}, {}});

                                }
                                // Add to existing stack
                                crate_stacks[i].push_back(letter);

                            }

                        }
                    }

                }
                else if (myline.length()==0 and (not header_loaded)){
                    // Switch to reading in the moving parts
                    header_loaded = true;
                }
                else if (myline.length()!=0) {
                    // Reading in the moving parts
                    std::cout << "Data " << myline << "\n";

                    // Remove the string "move "
                    myline = myline.erase(0, 5);

                    // Find the next space, from 0 to this index is the number of items to move.
                    split_index =  myline.find(" ") + 1;
                    n_moving.push_back(std::stoi(myline.substr(0, split_index)));

                    // Remove the string for the number of items and the space
                    myline = myline.erase(0, split_index);

                    // Remove the string "from "
                    myline = myline.erase(0, 5);

                    // Find the next space, from 0 to this index is the 'from' position.
                    split_index =  myline.find(" ") + 1;
                    move_from.push_back(std::stoi(myline.substr(0, split_index)) - 1);

                    // Remove the string for the 'from' position and the space
                    myline = myline.erase(0, split_index);

                    // Remove the string "to " then add the number for 'to'
                    myline = myline.erase(0, 3);
                    move_to.push_back(std::stoi(myline) - 1);

                }
            }
        }
        else {
            std::cout << "\n File not open!";
        }

        if (part_1){
            // Perform the moving
            for (int i = 0; i < n_moving.size(); i++) {
                for (int j = 0; j < n_moving[i]; j++){
                    crate_stacks[move_to[i]].push_front(crate_stacks[move_from[i]][0]);
                    crate_stacks[move_from[i]].pop_front();

                }
            }

            std::cout << "Part 1 ";
            for (int i = 0; i < crate_stacks.size(); i++) {
                std::cout << crate_stacks[i][0];
            }
            std::cout << "\n";

        } else {

            // Perform the moving
            for (int i = 0; i < n_moving.size(); i++) {

                // Add the new elements
                for (int j = 0; j < n_moving[i]; j++) {
                    crate_stacks[move_to[i]].push_front(crate_stacks[move_from[i]][n_moving[i] - j - 1]);

                }
                // Remove the old elements
                for (int j = 0; j < n_moving[i]; j++) {
                    crate_stacks[move_from[i]].pop_front();

                }
            }

            std::cout << "Part 2 ";
            for (int i = 0; i < crate_stacks.size(); i++) {
                std::cout << crate_stacks[i][0];
            }
            std::cout << "\n";

        }

        return 0;
    }
}
