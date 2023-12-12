//
// Created by simon on 02/11/23.
//
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>
#include <algorithm>
#include <day_2023_05.h>

namespace day202305 {
    void load_lines_to_map(Map& map_object, std::ifstream& datafile){
        std::string substring;
        std::string line_string;
        int line_length, current_index, last_index;

        // Move to next line
        std::getline(datafile, line_string);
        line_length = line_string.length();

        MapEntry new_map_entry;
        while (line_length !=0) {
            last_index = 0;
            current_index = line_string.find(" ");

            // 3 times
            substring = line_string.substr(0,  current_index);
            line_string = line_string.substr(current_index + 1);
            new_map_entry.destination = std::stol(substring);
            last_index = current_index;
            current_index = line_string.find(" ");

            std::cout << "destination " << substring << "\n";

            substring = line_string.substr(0,  current_index);
            std::cout << "source "<< substring << "\n";
            line_string = line_string.substr(current_index + 1);
            new_map_entry.source = std::stol(substring);

            // remainder of the string is the range
            new_map_entry.length = std::stol(line_string);
            std::cout << "length " << line_string << "\n";

            // Add the last item to the list
            map_object.add_entry(new_map_entry);

            // Move to next line
            std::getline(datafile, line_string);
            line_length = line_string.length();

        }
    }
    int run(std::filesystem::path data_path)
    {

        std::ifstream datafile;
        datafile.open(data_path);
        std::string myline;
        int line_length;
        std::unordered_map<std::string, int> map_identifier = {
                {"seeds: ", 1},
                {"seed-to", 2},
                {"soil-to", 3},
                {"fertili", 4},
                {"water-t", 5},
                {"light-t", 6},
                {"tempera", 7},
                {"humidit", 8}
        };

        std::vector<long long> seed_numbers;
        std::vector<long long> locations;
        Map seed_to_soil_map = Map();
        Map soil_to_fertiliser_map;
        Map fertiliser_to_water_map;
        Map water_to_light_map;
        Map light_to_temperature_map;
        Map temperature_to_humidity_map;
        Map humidity_to_location_map;
        std::string map_key;
        int split_index;
        std::string substring;

        // Read the data file.
        if (datafile.is_open()) {
            while (datafile) {
                std::getline(datafile, myline);
                line_length = myline.length();
                if (line_length !=0) {

                    map_key = myline.substr(0, 7);

                    switch (map_identifier[map_key]) {
                    case (1): {
                        split_index = myline.find(" ");
                        myline = myline.substr(split_index + 1);
                        std::cout << myline << "\n";
                        split_index = myline.find(" ");
                        while (split_index + 1 < myline.length() and split_index != -1) {

                            substring = myline.substr(0, split_index);
                            std::cout << substring << "\n";

                            // Add all items except the last here, then reduce the line
                            seed_numbers.push_back(std::stol(substring));
                            std::cout << substring << "\n";

                            myline = myline.substr(split_index + 1);
                            split_index = myline.find(" ");

                        }

                        std::cout << "end " <<myline << "\n";
                        seed_numbers.push_back(std::stol(myline));

                        break;
                    }
                    case (2): {
                        std::cout << "line "<< myline <<"\n";

                        load_lines_to_map(seed_to_soil_map, datafile);
                        break;
                    }
                    case (3): {
                        std::cout << "line "<< myline <<"\n";

                        load_lines_to_map(soil_to_fertiliser_map, datafile);

                        break;
                    }
                    case (4): {
                        std::cout << "line "<< myline <<"\n";

                        load_lines_to_map(fertiliser_to_water_map, datafile);
                        break;
                    }
                    case (5): {
                        std::cout << "line "<< myline <<"\n";

                        load_lines_to_map(water_to_light_map, datafile);
                        break;
                    }
                    case (6): {
                        std::cout << "line "<< myline <<"\n";

                        load_lines_to_map(light_to_temperature_map, datafile);
                        break;
                    }
                    case (7): {
                        std::cout << "line "<< myline <<"\n";

                        load_lines_to_map(temperature_to_humidity_map, datafile);
                        break;
                    }
                    case (8): {
                        std::cout << "line "<< myline <<"\n";

                        load_lines_to_map(humidity_to_location_map, datafile);
                        break;
                    }
                    }
                }
            }
        }
        long current_number;
        long lowest_number;
        for (int i = 0; i<seed_numbers.size(); i++) {
            current_number = seed_numbers[i];
            current_number = seed_to_soil_map.evaluate_map(current_number);
            current_number = soil_to_fertiliser_map.evaluate_map(current_number);
            current_number =  fertiliser_to_water_map.evaluate_map(current_number);
            current_number =  water_to_light_map.evaluate_map(current_number);
            current_number =  light_to_temperature_map.evaluate_map(current_number);
            current_number =  temperature_to_humidity_map.evaluate_map(current_number);
            current_number =  humidity_to_location_map.evaluate_map(current_number);
            std::cout << "current_number:" << current_number << "\n";
            locations.push_back(current_number);
        }
        lowest_number = locations[0];
        for (int i = 1; i<locations.size(); i++) {
            if (locations[i] < lowest_number){
                lowest_number = locations[i];
            }
        }
        std::cout << "Part 1 answer:" << lowest_number << "\n";

        return 0;
    }

    long Map::evaluate_map(long x)
    {
        // Check if the data is in any of the maps.
        for (int i = 0; i<this->map_entries.size(); i++) {
            if (x >= this->map_entries[i].source & x < this->map_entries[i].source + this->map_entries[i].length) {
                return this->map_entries[i].destination + (x - this->map_entries[i].source);
            }
        }

        // If not in the map, then return the source
        return x;
    }

    void Map::add_entry(MapEntry entry)
    {
        map_entries.push_back(entry);
    }
}

