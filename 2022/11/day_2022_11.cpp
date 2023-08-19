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
        for (int i = 0; i < 20; i++) {
            std::cout << "Iteration " << i << "\n";
            for (int j = 0; j<monkeys.size(); j++) {
                monkeys[j].inspect_items(monkeys);

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
    ValueExpression::ValueExpression(const ValueExpression &t) {
        _value = t._value;
    }

    int OldExpression::evaluate(int old)
    {
        std::cout << old << " ";
        return old;
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
    MultiplyExpression::MultiplyExpression(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right)
            :CombinedExpression(std::move(left), std::move(right))
    {

    }

    int MultiplyExpression::evaluate(int old)
    {
        std::cout << "Multiply ";
        return _left->evaluate(old) * _right->evaluate(old);
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

    void Monkey::inspect_items(std::vector<Monkey> &monkeys)
    {
        int worry_level;
        for (int i = 0; i < items.size(); i++){
            std::cout << "Monk " << index << " " << items[i] << " " << i << " "  << items.size() << " \n";
            // Find the new worry level of the items.
            worry_level = expression->evaluate(items[i]) / 3;
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

}
