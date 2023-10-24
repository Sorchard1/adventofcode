//
// Created by simon on 30/03/23.
//
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <utility>
#include <vector>
#include <cassert>
#include <algorithm>
#include <day_2022_11.h>
#include <stdexcept>

namespace day202211 {

    int run(std::filesystem::path data_path)
    {

        std::ifstream datafile;
        datafile.open(data_path);
        std::string myline;

        // Store
        unsigned int split_index;
        unsigned int end_index;
        std::string substring;
        int line_count = 0;
        const int line_per_data = 6;
        int lines_left = line_per_data;
        int monkey_index;
        std::vector<int> monkey_items;
        int monkey_test_divisor = 1;
        int monkey_index_true = 1;
        int monkey_index_false = 1;
        std::string operand_1;
        std::string operator_;
        std::string operand_2;
        std::vector<Monkey> monkeys;

        std::unique_ptr<Expression> exp_1;
        std::unique_ptr<Expression> exp_2;
        std::unique_ptr<Expression> total_exp;

        // Read the data file.
        if (datafile.is_open()) {
            while (datafile) {
                std::getline(datafile, myline);

                if (myline.length()!=0) {
                    switch (lines_left) {
                        case (line_per_data): {
                            split_index = myline.find(" ") + 1;
                            end_index = myline.find(":");
                            monkey_index = std::stoi(myline.substr(split_index, end_index - split_index));
                            break;
                        }
                        case (line_per_data - 1): {
                            split_index = myline.find(":") + 1;
                            // Warning this have 1 whitespace at the start extra.
                            substring = myline.substr(split_index);
                            split_index = substring.find(",");

                            while (split_index + 1 < substring.length() and split_index != -1) {
                                // Add all items except the last here
                                monkey_items.push_back(std::stoi(substring.substr(1, split_index + 1)));
                                split_index = substring.find(",");
                                substring = substring.substr(split_index + 1);

                            }
                            // Add the last item to the list
                            monkey_items.push_back(std::stoi(substring));
                            break;
                        }
                        case (line_per_data - 2): {
                            split_index = myline.find("=") + 2;

                            // Get the operations after "new = "
                            substring = myline.substr(split_index);

                            // Get the first piece after the "= " which is the first operand, then remove it.
                            end_index = substring.find(" ");
                            operand_1 = substring.substr(0, end_index);
                            substring = substring.substr(end_index + 1);

                            // Get the next piece after the first operand which is the operator, then remove it.
                            end_index = substring.find(" ");
                            operator_ = substring.substr(0, end_index);

                            // The leftover piece is the final operand.
                            operand_2 = substring.substr(end_index + 1);

                            if (operand_1 == "old") {
                                exp_1 = std::make_unique<OldExpression>();

                            }
                            else {
                                exp_1 = std::make_unique<ValueExpression>(std::stoi(operand_1));
                            }
                            if (operand_2 == "old") {
                                exp_2 = std::make_unique<OldExpression>();

                            }
                            else {
                                exp_2 = std::make_unique<ValueExpression>(std::stoi(operand_2));
                            }
                            if (operator_ == "+") {
                                total_exp = std::make_unique<AdditionExpression>(std::move(exp_1), std::move(exp_2));

                            }
                            else if (operator_ == "*") {
                                total_exp = std::make_unique<MultiplyExpression>(std::move(exp_1), std::move(exp_2));

                            }
                            break;
                        }
                    case (line_per_data - 3): {
                        std::cout << myline << "\n";

                        split_index = myline.find("by ") + 3;
                        monkey_test_divisor = std::stoi(myline.substr(split_index));
                        break;
                        }
                    case (line_per_data - 4): {
                        std::cout << myline << "\n";

                        split_index = myline.find("key ") + 4;
                        monkey_index_true = std::stoi(myline.substr(split_index));
                        break;
                        }
                    case (line_per_data - 5): {
                        std::cout << myline << "\n";

                        split_index = myline.find("key ") + 4;
                        monkey_index_false = std::stoi(myline.substr(split_index));
                        break;
                        }
                    }
                }
                if (lines_left == 0) {
                    lines_left = line_per_data;
                    monkeys.emplace_back(monkey_index, monkey_items, monkey_test_divisor, monkey_index_true, monkey_index_false, std::move(total_exp));
                    monkey_items.clear();
                }
                else {
                    lines_left -= 1;
                }
            }
        }
        else {
            std::cout << "\n File not open!";
        }

        bool part_1 = false;
        if (part_1){
            for (int i = 0; i < 20; i++) {
                std::cout << "Iteration " << i << "\n";
                for (int j = 0; j<monkeys.size(); j++) {
                    monkeys[j].inspect_items(monkeys, 3);

                }
            }
            std::vector<int> top_two = {0, 0};
            for (int j = 0; j < monkeys.size(); j++) {
                std::cout << "Monkey " << monkeys[j].index << " was inspected " << monkeys[j].n_inspections << " time(s) \n";
                if (monkeys[j].n_inspections > top_two[0]){

                    top_two[1] = top_two[0];
                    top_two[0] = monkeys[j].n_inspections;

                }
                else if (monkeys[j].n_inspections > top_two[1]){
                    top_two[1] = monkeys[j].n_inspections;
                }
            }
            std::cout << "Part 1 " << top_two[0]*top_two[1] << "\n";

        }
        else {
            // Now store the data outside the class
            // Store the modulo in a matrix of each item by each monkey
            std::vector<std::vector<int>> item_modulo;
            std::vector<int> item_modulo_row;
            // Store the monkey index for each item
            std::vector<int> monkey_indices;
            int item_index = 0;
            for (int i = 0; i < monkeys.size(); i++) {
                for (int j = 0; j < monkeys[i].items.size(); j++) {
                    for (int k = 0; k < monkeys.size(); k++) {

                        item_modulo_row.push_back(monkeys[i].items[j] % monkeys[k].test_divisor);
                    }
                    item_index += 1;

                    monkey_indices.push_back(i);
                    item_modulo.push_back(item_modulo_row);
                    item_modulo_row.clear();
                }
            }
            for (int i = 0; i < item_modulo.size(); i++) {
//                for (int j = 0; j < item_modulo_row[i].size(); j++) {

                    std::cout << i << " " << item_modulo[i].size() << "\n";
            }
            int index_throw;
            for (int i = 0; i < 10000; i++) {
                std::cout << "Iteration " << i << "\n";
                for (int j = 0; j < monkeys.size(); j++) {
                    // loop over every item
                    for (int k = 0; k < monkey_indices.size(); k++) {
                        if (monkey_indices[k] == j){
                            // The correct monkey, item pair found, now inspect for all
                            // 1.) Apply the operation to the modulo (and all other modulos) to work out new modulo
                            // 2.) Test which operation will be done (if modulo = 0)
                            index_throw = monkeys[j].inspect_items_modulo(item_modulo[k][j]==0, item_modulo[k], monkeys);

                            // 3.) Throw items to other monkeys
                            std:: cout << "\n Round "<< i << " Throw from " << monkey_indices[k] << " to " << index_throw << "\n";
                            monkey_indices[k] = index_throw;
                        }
                    }
                }
                for (int j = 0; j < monkeys.size(); j++) {
                    std::cout << "\n"<< j  << " " << monkeys[j].n_inspections << "\n";
                }
            }
            std::vector<long> top_two = {0, 0};
            for (int j = 0; j < monkeys.size(); j++) {
                std::cout << "Monkey " << monkeys[j].index << " was inspected " << monkeys[j].n_inspections << " time(s) \n";
                if (monkeys[j].n_inspections > top_two[0]){

                    top_two[1] = top_two[0];
                    top_two[0] = monkeys[j].n_inspections;

                }
                else if (monkeys[j].n_inspections > top_two[1]){
                    top_two[1] = monkeys[j].n_inspections;
                }
            }
            std::cout << "Part 1 " << top_two[0]*top_two[1] << "\n";
//            ItemTracker item_tracker = ItemTracker();
//            for (auto &monkey: monkeys) {
//                item_tracker.load_divisor(monkey.test_divisor);
//                item_tracker.load_move_true(monkey.index_true);
//                item_tracker.load_move_false(monkey.index_false);
//            }
//            for (int i = 0; i < monkeys.size(); i++) {
//                for (int j = 0; j < monkeys[i].items.size(); j++) {
//                    item_tracker.monkey_items.emplace_back(monkeys[i].items[j], i);
//                }
//            }
//            item_tracker.setup();
//            std::cout << "Done \n";
//            // Add the pieces of the monkeys to the item tracker
//            for  (const auto & monkey : monkeys) {
//                item_tracker.add_items(monkey);
//            }

//
//            for (int i = 0; i < 10000; i++) {
//                std::cout << "Iteration " << i << "\n";
//
//                for (int j = 0; j<monkeys.size(); j++) {
//                    monkeys[j].inspect_items(monkeys, 1);
//
//                }
//
//                if (i == 1-1){
//                    std::cout << i << "has :\n";
//                }
//                if (i == 20-1){
//                    std::cout << i << "has :\n";
//                }
//                if (i == 1000-1){
//                    std::cout << i << "has :\n";
//                }
//                if (i == 2000-1){
//                    std::cout << i << "has :\n";
//                }
//            }
        }
        return 0;
    }

    ValueExpression::ValueExpression(int value)
    {
        _value = value;
    }

    int ValueExpression::evaluate(int old)
    {
        std::cout << _value << " ";
        return _value;
    }
    int ValueExpression::evaluate_modulo(int old_modulo, int divisor)
    {
        std::cout << _value << " ";
        return _value % divisor;
    }
    ValueExpression::ValueExpression(const ValueExpression &t) {
        _value = t._value;
    }

    int OldExpression::evaluate(int old)
    {
        std::cout << old << " ";
        return old;
    }

    int OldExpression::evaluate_modulo(int old_modulo, int divisor)
    {
        std::cout << old_modulo << " ";
        return old_modulo % divisor;
    }

    CombinedExpression::CombinedExpression(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right)
    {
        _left = std::move(left);
        _right = std::move(right);
    }

    AdditionExpression::AdditionExpression(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right)
            :CombinedExpression(std::move(left), std::move(right))
    {

    }

    int AdditionExpression::evaluate(int old)
    {
        std::cout << "Add ";
        return _left->evaluate(old) + _right->evaluate(old);
    }
    int AdditionExpression::evaluate_modulo(int old_modulo, int divisor)
    {
        std::cout << "Add ";
        return (_left->evaluate_modulo(old_modulo, divisor) + _right->evaluate_modulo(old_modulo, divisor)) % divisor;
    }
    MultiplyExpression::MultiplyExpression(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right)
            :CombinedExpression(std::move(left), std::move(right))
    {

    }

    int MultiplyExpression::evaluate(int old)
    {
        std::cout << "Multiply ";
        return _left->evaluate(old) * _right->evaluate(old);
    }
    int MultiplyExpression::evaluate_modulo(int old_modulo, int divisor)
    {
        std::cout << "Multiply ";
        return (_left->evaluate_modulo(old_modulo, divisor) * _right->evaluate_modulo(old_modulo, divisor)) % divisor;
    }

    Monkey::Monkey(int monkey_index, std::vector<int> monkey_items, int monkey_test_divisor, int monkey_index_true,
            int monkey_index_false, std::unique_ptr<Expression> monkey_expression)
    {
        if (monkey_index_true == monkey_index){
            throw std::invalid_argument("Monkey can't throw to itself");
        }
        if (monkey_index_true == monkey_index){
            throw std::invalid_argument("Monkey can't throw to itself");
        }
        index = monkey_index;
        items = std::move(monkey_items);
        test_divisor = monkey_test_divisor;

        index_true = monkey_index_true;
        index_false = monkey_index_false;
        expression = std::move(monkey_expression);
        n_inspections = 0;
    }

    void Monkey::inspect_items(std::vector<Monkey> &monkeys, int divisor)
    {
        int worry_level;
        for (int i = 0; i < items.size(); i++){
            std::cout << "Monk " << index << " " << items[i] << " " << i << " "  << items.size() << " \n";
            // Find the new worry level of the items.
            worry_level = expression->evaluate(items[i]) / divisor;
            std::cout << "\n";
            if (worry_level % test_divisor==0){
                monkeys[index_true].items.push_back(worry_level);
                std::cout << "to " << index_true << " " << worry_level << " \n";

            }
            else {
                std::cout << "to " << index_false << " " << worry_level << " \n";

                monkeys[index_false].items.push_back(worry_level);
            }

            n_inspections += 1;
        }
        // Empty the item list
        items.clear();

    }

    int Monkey::inspect_items_modulo(bool pass_true, std::vector<int> &modulos, std::vector<Monkey> &monkeys) {
        int index_return;

        // 1.) Apply the operation to the modulo (and all other modulos) to work out new modulo
        for (int i = 0; i < modulos.size(); i++) {
            modulos[i] = expression->evaluate_modulo(modulos[i], monkeys[i].test_divisor);
        }

        // 2.) Test which operation will be done (if modulo = 0)
        if (modulos[index] ==0){
            index_return = index_true;
        }
        else {
            index_return = index_false;
        }
        n_inspections += 1;
        return index_return;
    }

    void ItemTracker::update_all() {
        //loop through each monkey.
        for (int i = 0; i < monkey_divisors.size(); i++) {
            // find all items with that monkey
            for (int j = 0; j < monkey_items.size(); j++) {
                // Check the modulo of the current monkey
                if (monkey_items[j].modulos[j] == 0){
                    // Move the item to a different monkey
                    monkey_items[j].monkey_index = monkey_move_true[i];

                    //update the modulo

                    // change the monkey count

                } else {
                    // Move the item to a different monkey
                    monkey_items[j].monkey_index = monkey_move_false[i];
                    //update the modulo

                    // change the monkey count
                }

            }
        }
    }

    ItemTracker::ItemTracker() {}

    void ItemTracker::load_divisor(int divisor) {
        monkey_divisors.push_back(divisor);
    }

    void ItemTracker::setup()
    {
        // Call after running load divisor.
        for (int i = 0; i < monkey_divisors.size(); i++) {
            monkey_items[i].initialise(monkey_divisors[i]);
        }

    }

    void ItemTracker::load_move_true(int move_true) {
        monkey_move_true.push_back(move_true);
    }

    void ItemTracker::load_move_false(int move_false) {
        monkey_move_false.push_back(move_false);
    }

    Item::Item(int value, int index) {
        initial_items.push_back(value);
        monkey_index = index;

    }

    void Item::initialise(int monkey_divisor) {
        // Make modulo for each divisor, so that it can get tracked later
        for (int j = 0; j < initial_items.size(); j++) {
            modulos.push_back(initial_items[j] % monkey_divisor);
        }
    }
}
