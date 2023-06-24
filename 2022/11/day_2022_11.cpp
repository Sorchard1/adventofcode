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
#include <day_2022_11.h>

namespace day202211 {
    NumericalExpression::NumericalExpression(int value, Expression *left, Expression *right) : Expression(value, left, right) {
        value_ = value;
    }
    void NumericalExpression::set_value(int value) {
        value_ = value;
    }

    int NumericalExpression::evaluate(int old) {
        std::cout <<"get value " << value_ << "\n";

        return value_;
    }

    OldExpression::OldExpression(int value, Expression *left, Expression *right) : NumericalExpression(value, left, right) {
    }

    int OldExpression::evaluate(int old) {
        std::cout <<"get old "<<old<<"\n";

        return old;
    }

    AdditionExpression::AdditionExpression(int value, Expression *left, Expression *right) : NumericalExpression(value, left, right) {
        left_ = left;
        right_ = right;
    }

    int AdditionExpression::evaluate(int old) {
        std::cout <<"adding "<<old<<"\n";

        return left_->evaluate(old) + right_->evaluate(old);
    }

    MultiplyExpression::MultiplyExpression(int value, Expression *left, Expression *right) : NumericalExpression(value, left, right) {
        left_ = left;
        right_ = right;
    }

    int MultiplyExpression::evaluate(int old) {
        std::cout <<"multiplying "<<old<<"\n";
        std::cout << "f("<<left_<<"):" << typeid(*left_).name() << "\n";
        std::cout << "f("<<right_<<"):" << typeid(*right_).name() << "\n";

        return left_->evaluate(old) * right_->evaluate(old);
    }

    Monkey::Monkey(int monkey_index, std::vector<int> monkey_items, int monkey_test_divisor, int monkey_index_true,
                   int monkey_index_false) {
        index = monkey_index;
        items = monkey_items;
        test_divisor = monkey_test_divisor;
        index_true = monkey_index_true;
        index_false = monkey_index_false;
        expression_ = nullptr;
        value_ = 0;
    }

    void Monkey::inspect_items() {
        int check = 1;
        check = expression_->evaluate(check);
        std::cout << "check " << check << "\n";
        std::cout << "f("<<expression_<<"):" << typeid(*expression_).name() << "\n";
//
//        for (int i = 0; i < items.size(); i++) {
//            std::cout << "before " << items[i] << "\n";
//            items[i] = expression_->evaluate(items[i]);
//            std::cout << "after " << items[i] << "\n";
//        }
    }
    void Monkey::set_expression(Expression *expression) {
        expression_ = expression;
    };


    int run(std::filesystem::path data_path)
    {

        std::ifstream datafile;
        datafile.open(data_path);
        std::string myline;

        unsigned int split_index;
        unsigned int end_index;
        std::string substring;
        int line_count = 0;
        const int line_per_data = 6;
        int lines_left = line_per_data;
        int monkey_index;
        std::vector<int> monkey_items;
        int monkey_test_divisor;
        int monkey_index_true;
        int monkey_index_false;
        std::string operand_1;
        std::string operator_;
        std::string operand_2;
        std::vector<day202211::Monkey> monkeys;
        std::vector<day202211::Expression> monkey_expressions;

        // TODO make a list of each expression that would be stored as a ptr
        std::vector<Expression*> expression_left_list;
        std::vector<Expression*> expression_right_list;
        std::vector<Expression*> expression_total_list;

        Expression* expression;
        Expression* left_ptr;
        Expression* right_ptr;

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
                            std::cout << "Monkey index " << monkey_index << "\n";
                            break;
                        }
                        case (line_per_data - 1): {
                            split_index = myline.find(":") + 1;
                            // Warning this have 1 whitespace at the start extra.
                            substring = myline.substr(split_index);
                            split_index = substring.find(",");

                            std::cout << substring << "\n";
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
                            std::cout << "Expression " << substring << "\n";

                            // Get the first piece after the "= " which is the first operand, then remove it.
                            end_index = substring.find(" ");
                            operand_1 = substring.substr(0, end_index);
                            substring = substring.substr(end_index + 1);

                            // Get the next piece after the first operand which is the operator, then remove it.
                            end_index = substring.find(" ");
                            operator_ = substring.substr(0, end_index);

                            // The leftover piece is the final operand.
                            operand_2 = substring.substr(end_index + 1);
                            std::cout <<"operand_2 " << operand_2 << "\n";

                            if (operand_1 == "old") {

                                day202211::OldExpression left = OldExpression(0, nullptr, nullptr);
                                left_ptr = &left;
//                                expression_left_list.push_back(left_ptr);
                            }
                            else {
                                day202211::NumericalExpression left = NumericalExpression(std::stoi(operand_1), nullptr, nullptr);
                                left_ptr = &left;
//                                expression_left_list.push_back(left_ptr);
                            }
                            if (operand_2 == "old") {
                                day202211::OldExpression right = OldExpression(0, nullptr, nullptr);
                                right_ptr = &right;
//                                expression_right_list.push_back(right_ptr);

                            }
                            else {
                                std::cout <<"made operand 2 " << operand_2 << "\n";
                                day202211::NumericalExpression right = NumericalExpression(std::stoi(operand_2), nullptr, nullptr);
                                right_ptr = &right;
//                                expression_right_list.push_back(right_ptr);

                            }
                            if (operator_ == "+") {
                                day202211::AdditionExpression addition = AdditionExpression(0, left_ptr, right_ptr);
                                expression = &addition;
//                                expression_total_list.push_back(expression);

                            }
                            else if (operator_ == "*") {
                                day202211::MultiplyExpression multiplication = MultiplyExpression(0, left_ptr, right_ptr);
                                expression = &multiplication;
//                                expression_total_list.push_back(expression);

                            }

                            break;
                        }
                    }
                }
                if (lines_left == 0) {
                    lines_left = line_per_data;
                    monkeys.emplace_back(monkey_index, monkey_items, monkey_test_divisor, monkey_index_true, monkey_index_false);
                    monkeys[monkeys.size()-1].set_expression(expression);
                }
                else {
                    lines_left -= 1;
                }
            }
        }
        else {
            std::cout << "\n File not open!";
        }
        std::cout << "Inspect 0" << "\n" ;
        monkeys[0].inspect_items();
        std::cout << "Inspect 1" << "\n" ;
        monkeys[1].inspect_items();
        std::cout << "Inspect 2" << "\n" ;
        monkeys[2].inspect_items();
        std::cout << "Inspect 3" << "\n" ;
        monkeys[3].inspect_items();
        return 0;
    }
}
