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
    int unique_visits(std::vector<std::vector<int>> &tail_search) {

        std::unordered_map<int, std::set<int>> tail_visits;
        std::set<int> tail_visits_y;
        for (int i = 0; i < tail_search.size(); i++) {
            if (tail_visits.find(tail_search[i][0]) == tail_visits.end()){
                // If key doesn't exist
                tail_visits_y.clear();
                tail_visits_y.insert(tail_search[i][1]);
                tail_visits[tail_search[i][0]] = tail_visits_y;
            }
            else {
                tail_visits[tail_search[i][0]].insert(tail_search[i][1]);
            }
        }
        int n_sets = 0;
        for (auto i = tail_visits.begin(); i != tail_visits.end(); i++) {
            for (auto itr : i->second) {
                std::cout << i->first << " " << itr << "\n";
                n_sets += 1;
            }
        }
        return n_sets;
    }
    std::vector<int> next_knot_movement(int x_front, int y_front, int x_current, int y_current) {
        int x_diff;
        int y_diff;
        int x_abs_diff;
        int y_abs_diff;
        std::vector<int> position;
        x_diff = x_front - x_current;
        y_diff = y_front - y_current;
        x_abs_diff = std::abs(x_diff);
        y_abs_diff = std::abs(y_diff);
        if (x_abs_diff > 1 or y_abs_diff > 1) {
            // Movement
            if (x_abs_diff == 0) {
                // Grid aligned movement
                y_current += y_diff - sign(y_diff);
            }
            else if (y_abs_diff == 0) {
                // Grid aligned movement
                x_current += x_diff - sign(x_diff);

            } else {
                // Diagonal movement
                x_current += sign(x_diff);
                y_current += sign(y_diff);

            }
        } else {

        }
        position.push_back(x_current);
        position.push_back(y_current);
        return position;
    }
    int run(std::filesystem::path data_path)
    {

        std::ifstream datafile;
        datafile.open(data_path);
        std::string myline;
        unsigned int line_length;
        std::vector<std::vector<int>> head_position;
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

        std::vector<std::vector<std::vector<int>>> knot_positions;
        int n_knots = 9;
        // Init all knots
        for (int i = 0; i < n_knots + 1; i++) {
            knot_positions.push_back({{0, 0}});
        }
        knot_positions[0] = head_position;

        for (int i = 1; i < head_position.size(); i++) {
            for (int j = 1; j < n_knots + 1; j++) {
                if (j == 1) {
                    knot_positions[j].push_back(next_knot_movement(head_position[i][0], head_position[i][1], knot_positions[j][i - 1][0], knot_positions[j][i - 1][1]));

                } else {
                    knot_positions[j].push_back(next_knot_movement(knot_positions[j-1][i][0], knot_positions[j-1][i][1], knot_positions[j][i - 1][0], knot_positions[j][i - 1][1]));

                }

            }
        }

        unsigned int knot_evaluate = 1;
        int n_sets = unique_visits(knot_positions[knot_evaluate]);

        std::cout << "Part 1 " << n_sets << " " << "\n";
        unsigned int knot_evaluate_2 = 9;
        int n_sets_2 = unique_visits(knot_positions[knot_evaluate_2]);
        std::cout << "Part 2 " << n_sets_2 << " " << "\n";

        return 0;
    }
}
