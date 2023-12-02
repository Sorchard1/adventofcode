//
// Created by simon on 02/12/23.
//
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>

namespace day202302 {
    int count_back_to_space(std::string& substring){
        // count back until a space, then convert to int.
        char value;
        int return_val;
        for (int i = 0; i<substring.length(); i++) {
            value = substring[substring.length()-i-1];

            if (value==' ') {
                return_val = std::stoi(substring.substr(substring.length()-i , substring.length()));;
                return return_val;
            }

            // No space if it is the first colour
            if (i == substring.length() -1){
                return_val = std::stoi(substring.substr(0 , substring.length()));;
                return return_val;
            }
        }

    }

    int get_rgb_count(std::vector<int>& rgb_count, std::string& game_string){
//        std::cout << "game string:" << game_string << "\n";

        int last_index = 0;
        int red_index = 0;
        int blue_index = 0;
        int green_index = 0;
//        bool more_colours = true;

        std::string colour_string;
        std::string game_sub_string;
        red_index = game_string.find(" red");
        green_index = game_string.find(" green");
        blue_index = game_string.find(" blue");
//        std::cout<< game_string << " red_index " << red_index << "\n";
//        std::cout<< game_string << " green_index " << green_index << "\n";
//        std::cout<< game_string << " blue_index " << blue_index << "\n";

        // sort red, green blue
        std::string colour_substring;

        if (red_index <= game_string.length() & red_index >= 0) {
            // There is red
//            std::cout << "count red_substring " << colour_substring << "\n";
            colour_substring = game_string.substr(0, red_index);
            rgb_count[0] = count_back_to_space(colour_substring);
        }
        if (green_index <= game_string.length() & green_index >= 0) {
            // There is green
            colour_substring = game_string.substr(0, green_index);
            rgb_count[1] = count_back_to_space(colour_substring);
        }
        if (blue_index <= game_string.length() & blue_index >= 0) {
            // There is blue
            colour_substring = game_string.substr(0, blue_index);
//            std::cout << "colour_substring" << colour_substring << "\n";
            rgb_count[2] = count_back_to_space(colour_substring);
        }
    }
    int run(std::filesystem::path data_path)
    {
        int red_cubes = 12;
        int green_cubes = 13;
        int blue_cubes = 14;

        std::ifstream datafile;
        datafile.open(data_path);
        std::string myline;

        int index;
        int sub_index;
        std::string substring;
        std::string sub_game_string;
        bool more_sub_games = true;
        std::vector<int> rgb_count = {0, 0, 0};
        std::vector<int> max_colours = {0, 0, 0};
        bool possible_game;
        bool possible_subgame;
        int id_sum = 0;
        int part_2_answer = 0;
        int game_number = 1;
        if (datafile.is_open()) {
            while (datafile) {
                std::getline(datafile, myline);
                std::cout << myline << "\n";
                if (myline.length()!=0) {
                    // remove Game and game number
                    index = myline.find(": ");
                    substring = myline.substr(index + 2, myline.length()+1);
                    std::cout << substring << "\n";
                    possible_game = true;
                    max_colours = {0, 0, 0};
                    while (more_sub_games){
                        rgb_count = {0, 0, 0};
                        sub_index = substring.find("; ");

                        // case for no more sub-games after this one
                        if (sub_index >= myline.length()) {

                            more_sub_games = false;
                        }
                        // get the sub-game
                        sub_game_string = substring.substr(0, sub_index);
                        get_rgb_count(rgb_count, sub_game_string);
                        std::cout << "finally " << rgb_count[0] << " " << rgb_count[1] << " " << rgb_count[2] << " and "  << " " << "\n";

                        // Check if game is impossible
                        possible_subgame = ((rgb_count[0] <= red_cubes) & (rgb_count[1] <= green_cubes) & (rgb_count[2] <= blue_cubes));
                        std::cout << "subgame possible " << possible_subgame  << "\n";
                        possible_game &= possible_subgame;

                        // Cut down the substring to be the games left
                        substring = substring.substr(sub_index + 2, substring.length()+1);

                        // Find the max or each rgb.
                        for (int j = 0; j<3; j++) {
                            if (rgb_count[j] > max_colours[j]){
                                max_colours[j] = rgb_count[j];
                            }

                        }
                    }
                    std::cout << "game possible_game:" << possible_game<< " " << game_number << "\n";
                    if (possible_game){
                        std::cout << "GAME NUM:" <<  game_number << "\n";
                        id_sum += game_number;
                    }
                    more_sub_games = true;

                    sub_game_string = substring.substr(sub_index + 2, myline.length()+1);
                    game_number += 1;

                    // Sum the max rgb values
                    part_2_answer += max_colours[0] * max_colours[1] * max_colours[2];
                }

            }
        }
        std::cout << "part 1 answer is " << id_sum << "\n";
        std::cout << "part 2 answer is " << part_2_answer << "\n";
        return 0;
    }
}

