//
// Created by simon on 02/11/23.
//

#ifndef ADVENTOFCODE_DAY_2023_05_H
#define ADVENTOFCODE_DAY_2023_05_H

namespace day202305 {
    int run(std::filesystem::path data_path);

    struct MapEntry{
        long source, destination, length;
    };
    class Map {
    public:
        std::vector<MapEntry> map_entries;
        Map()= default;
        long evaluate_map(long x);
        void add_entry(MapEntry entry);
    };
    void load_lines_to_map(Map& map_object, std::ifstream& datafile);


}

#endif //ADVENTOFCODE_DAY_2023_05_H
