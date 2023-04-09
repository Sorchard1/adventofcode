//
// Created by simon on 30/03/23.
//
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <cassert>

#include <day_2022_07.h>
#include <map>

namespace day202207 {

    Node::Node(std::string new_name) {
        std::cout << "init";
        name = new_name;
        parent = NULL;
        calculated_size = false;
        directory_size = 0;
    };

    void Node::add_node(std::string new_name){
        Node new_node = Node(new_name);
        new_node.set_parent(this);
        subdirectory_map.insert({new_name, subdirectories.size()});
        subdirectories.push_back(new_node);
    };

    void Node::add_data(int file_size){
        file_sizes.push_back(file_size);
    };

    void Node::set_parent(Node *parent_node){
        this->parent = parent_node;
    }

    Node* Node::get_parent(){
        return parent;
    }

    Node* move_directory(std::string name, bool to_parent, Node* current_ptr){
        if (to_parent) {
            current_ptr = current_ptr->get_parent();
        }
        else {
            current_ptr = &current_ptr->subdirectories[current_ptr->subdirectory_map[name]];
        }
        return current_ptr;
    }

    int run(std::filesystem::path data_path)
    {
        std::ifstream datafile;
        datafile.open(data_path);
        std::string myline;

        Node root_node = Node("root");
        Node* current_node_ptr = &root_node;
        int split_index;
        std::string command;
        std::string argument_substring;

        // Read the data file.
        if (datafile.is_open()) {
            while (datafile) {
                std::getline(datafile, myline);
                if (myline.length() != 0) {
                    if (myline[0] == '$') {
                        std::cout << "command " << myline << "\n";
                        split_index =  myline.find(" ") + 1;
                        command = myline.substr(split_index);

                        if (myline[2] == 'c') {
                            // cd command
                            split_index =  command.find(" ") + 1;
                            argument_substring = command.substr(split_index);
                            std::cout << "before cd " <<current_node_ptr->name << "\n";
                            if (argument_substring[0] == '/') {
                                //do nothing
                                std::cout << "did nothing cd / " << "\n";
                            }
                            else if (argument_substring[0] == '.' and argument_substring[1] == '.'){
                                current_node_ptr = move_directory(command.substr(split_index), true, current_node_ptr);
                                std::cout << "moved up cd .. " << "\n";

                            }
                            else {
                                std::cout << "moved down cd " << argument_substring << "\n";
                                current_node_ptr = move_directory(command.substr(split_index), false, current_node_ptr);

                            }
                        }
                        else if (myline[2] == 'l') {
                            // ls command, do nothing but move to response.
                        }
                    }
                    else {
                        split_index =  myline.find(" ") + 1;
                        if (myline[0] == 'd') {
                            // Add a directory
                            current_node_ptr->add_node(myline.substr(split_index));
                        }
                        else {
                            current_node_ptr->add_data(std::stoi(myline.substr(0, split_index)));

                        }

                    }
                }
                    std::cout << myline << "\n";
                }
            }
        else {
            std::cout << "\n File not open!";
        }

        Node* node_ptr = &root_node;
        int sum_small_directories = 0;
        const int directory_max_sum = 100000;
        int subdir_index;
        bool calculated_subdirs;

        // Find the size of each directory
        // until the root node size is calculated.
        while (not root_node.calculated_size) {
            if (node_ptr->calculated_size) {
                // If calculated go up.
                if (node_ptr->name == "root") {
                    break;
                }
                std::cout << "About to go up directory from " << node_ptr->name << "\n";
                node_ptr = node_ptr->get_parent();
                std::cout << "Gone up directory to " << node_ptr->name << "\n";

            }
            else if (node_ptr->subdirectories.empty()) {
                // If at a leaf, calculate the size.
                for (int i = 0; i < node_ptr->file_sizes.size(); i++) {
                    node_ptr->directory_size += node_ptr->file_sizes[i];

                }
                node_ptr->calculated_size = true;
                if (node_ptr->directory_size <= directory_max_sum) {
                    sum_small_directories += node_ptr->directory_size;
                }
                std::cout << "leaf calculated in " << node_ptr->name << "\n";

            }
            else {
                calculated_subdirs = true;
                for (int i = 0; i < node_ptr->subdirectories.size(); i++) {
                    if (not node_ptr->subdirectories[i].calculated_size) {
                        calculated_subdirs = false;
                        subdir_index = i;
                    }
                }

                if (calculated_subdirs) {
                    // There are no directories that haven't been calculated, so calculate the total size
                    for (int i = 0; i < node_ptr->file_sizes.size(); i++) {
                        node_ptr->directory_size += node_ptr->file_sizes[i];

                    }
                    for (int i = 0; i < node_ptr->subdirectories.size(); i++) {
                        node_ptr->directory_size += node_ptr->subdirectories[i].directory_size;

                    }
                    node_ptr->calculated_size = true;

                    if (node_ptr->directory_size <= directory_max_sum) {
                        sum_small_directories += node_ptr->directory_size;
                    }
                    std::cout << "calculated in directory " << node_ptr->name << "\n";
                }
                else {
                    // Go into the directory not calculated
                    std::cout << "About to move from directory " << node_ptr->name << "\n";
                    node_ptr = &node_ptr->subdirectories[subdir_index];
                    std::cout << "Go into directory " << node_ptr->name << "\n";
                }
            }

        }
        std::cout << "Part 1 " << sum_small_directories << "\n";
        return 0;
    }
}
