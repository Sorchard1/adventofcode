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

namespace day202208 {

    int run(std::filesystem::path data_path)
    {

        std::ifstream datafile;
        datafile.open(data_path);
        std::string myline;

        std::vector<std::vector<int>> tree_heights;
        std::vector<int> tree_row;

        std::vector<std::vector<bool>> visible;
        std::vector<bool> visible_row;

        // Read the data file.
        if (datafile.is_open()) {
            while (datafile) {
                std::getline(datafile, myline);
                if (myline.length()!=0) {
                    // Move through the line
                    tree_row.clear();
                    for (char i : myline) {
                        tree_row.push_back(i - '0');
                        visible_row.push_back(false);

                    }
                    tree_heights.push_back(tree_row);
                    visible.push_back(visible_row);
                }
            }
        }
        else {
            std::cout << "\n File not open!";
        }
//        for (int i = 0; i < tree_heights.size(); i++) {
//            for (int j = 0; j < tree_heights[i].size(); j++) {
//                std::cout << tree_heights[i][j] << "\n";
//
//            }
//        }
        std::vector<int> tallest_left;
        std::vector<int> tallest_top = tree_heights[0];
        std::vector<int> tallest_right;
        std::vector<int> tallest_bottom = tree_heights[tree_heights.size() - 1];
        unsigned int row_length = tree_heights[0].size();
        unsigned int col_length = tree_heights.size();
        for (int i = 0; i < col_length; i++) {
            tallest_left.push_back(tree_heights[i][0]);
            tallest_right.push_back(tree_heights[i][col_length - 1]);
            visible[i][0] = true;
            visible[i][col_length - 1] = true;
        }
        for (int j = 1; j < row_length - 1; j++) {
            visible[0][j] = true;
            visible[row_length - 1][j] = true;
        }

        // Find the tallest tree before each tree
        int current_height;
        // [row=i, column=j]
        for (int i = 1; i < col_length - 1; i++) {
            for (int j = 1; j < row_length - 1; j++) {

                current_height = tree_heights[i][j];

                // Check visible from the left
                if (current_height > tallest_left[i]) {
                    std::cout << "Left visible " << i << " " << j << " " << tallest_left[i] << "\n";
                    visible[i][j] = true;
                    tallest_left[i] = current_height;
                }
                // Check visible from the top
                if (current_height > tallest_top[j]) {
                    std::cout << "Top visible " << i << " " << j << " " << tallest_top[j] << "\n";

                    visible[i][j] = true;
                    tallest_top[j] = current_height;
                }
//                std::cout << tree_heights[i + 1][j + 1] << "\n";

            }
        }
        int i_r;
        int j_r;

        // Find the tallest tree after each tree
        for (int i = 1; i < col_length - 1; i++) {
            for (int j = 1; j < row_length - 1; j++) {
                i_r = col_length - i - 1;
                j_r = row_length - j - 1;
                current_height = tree_heights[i_r][j_r];
                if (i == 1 and j == 1){
                    std::cout << i_r << " " << j_r << "\n";
                }
                // Check visible from the right
                if (current_height > tallest_right[i_r]) {
                    std::cout << "Right visible " << i_r << " " << j_r << " " << tallest_right[i_r] << "\n";
                    visible[i_r][j_r] = true;
                    tallest_right[i_r] = current_height;
                }
                // Check visible from the top
                if (current_height > tallest_bottom[j_r]) {
                    std::cout << "Bottom visible " << i_r << " " << j_r << " " << tallest_bottom[j_r] << "\n";
                    visible[i_r][j_r] = true;
                    tallest_bottom[j_r] = current_height;
                }
            }
        }
        int n_visible = 0;
        // Find the highest tree after each tree
        for (int i = 0; i < col_length; i++) {
            for (int j = 0; j < tree_heights[i].size(); j++) {
                if (visible[i][j]) {
                    n_visible += 1;
                }

            }
        }

        std::cout << "Part 1 " << n_visible << "\n";

        return 0;
    }
}
