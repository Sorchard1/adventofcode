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
#include <set>

namespace day202209 {

    int sign(int input){
        if (input > 0) {
            return 1;
        }
        else if (input < 0) {
            return -1;
        }
        else {
            return 0;
        }
    }
    int run(std::filesystem::path data_path)
    {

        std::ifstream datafile;
        datafile.open(data_path);
        std::string myline;
        unsigned int line_length;
        std::vector<std::vector<int>> head_position;
        std::vector<std::vector<int>> tail_position;
        std::vector<int> position = {0, 0};
        head_position.push_back(position);

        int n_steps;
        unsigned int split_index;
        // Read the data file.
        if (datafile.is_open()) {
            while (datafile) {
                std::getline(datafile, myline);
                line_length = myline.length();
                if (line_length!=0) {
                    // Move through the line
                    split_index =  myline.find(" ") + 1;
                    n_steps = std::stoi(myline.substr(split_index));
                    for (int i = 0; i < n_steps; i++) {

                        switch (myline[0]) {
                            case ('R'): {
                                position[0] += 1;
                                break;
                            }
                            case ('L'): {
                                position[0] -= 1;
                                break;
                            }
                            case ('U'): {
                                position[1] += 1;
                                break;
                            }
                            case ('D'): {
                                position[1] -= 1;
                                break;
                            }
                        }
                        head_position.push_back(position);
                    }
                }
            }
        }
        else {
            std::cout << "\n File not open!";
        }

        position = {0, 0};
        tail_position.push_back(position);
        int x_diff;
        int y_diff;
        int x_abs_diff;
        int y_abs_diff;
        for (int i = 1; i < head_position.size(); i++) {
            x_diff = head_position[i][0] - position[0];
            y_diff = head_position[i][1] - position[1];
            x_abs_diff = std::abs(x_diff);
            y_abs_diff = std::abs(y_diff);
            if (x_abs_diff > 1 or y_abs_diff > 1) {
                // Movement
                if (x_abs_diff == 0) {
                    // Grid aligned movement
                    position[1] += y_diff - sign(y_diff);
                }
                else if (y_abs_diff == 0) {
                    // Grid aligned movement
                    position[0] += x_diff - sign(x_diff);

                } else {
                    // Diagonal movement
                    position[0] += sign(x_diff);
                    position[1] += sign(y_diff);

                }
            } else {

            }
            tail_position.push_back(position);
        }

        std::unordered_map<int, std::set<int>> tail_visits;
        std::set<int> tail_visits_y;
        for (int i = 0; i < tail_position.size(); i++) {
            std::cout << "Head " << head_position[i][0] << " " << head_position[i][1] << " Tail " << tail_position[i][0] << " " << tail_position[i][1] << "\n";
            if (tail_visits.find(tail_position[i][0]) == tail_visits.end()){
                // If key doesn't exist
                tail_visits_y.clear();
                tail_visits_y.insert(tail_position[i][1]);
                tail_visits[tail_position[i][0]] = tail_visits_y;
            }
            else {
                tail_visits[tail_position[i][0]].insert(tail_position[i][1]);
            }
        }
        int n_sets = 0;
        for (auto i = tail_visits.begin(); i != tail_visits.end(); i++) {
            for (auto itr : i->second) {
                std::cout << i->first << " " << itr << "\n";
                n_sets += 1;
            }
        }
        std::cout << "Part 1 " << n_sets << "\n";

        return 0;
    }
}
