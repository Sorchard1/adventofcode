//
// Created by simon on 30/03/23.
//

#ifndef ADVENTOFCODE_DAY_2022_07_H
#define ADVENTOFCODE_DAY_2022_07_H

#include <vector>
#include <string>
#include <algorithm>


namespace day202207 {
    enum Command { ls, cd };
    class Node
            {
            private:
                Node* parent;

            public:
                Node(std::string new_name);
                void add_node(std::string new_name);
                void add_data(int file_size);
                void set_parent(Node *parent);
                Node* get_parent();
                std::unordered_map<std::string, int> subdirectory_map;
                std::vector<Node> subdirectories;
                std::vector<int> directory_sizes;
                std::string name;
                bool calculated_size;
                int directory_size;
                std::vector<int> file_sizes;

    };
    Node* move_directory(std::string new_name, bool to_parent, Node* current_ptr);

    int run(std::filesystem::path data_path);
}

#endif //ADVENTOFCODE_DAY_2022_07_H
