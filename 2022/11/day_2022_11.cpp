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
//    Monkey::~Monkey() {
//        std::cout << "delete monkey \n";
//        delete expression_;
//    };
//    CombinedExpression::~CombinedExpression() {
//        std::cout << "delete combined expression input \n";
//        delete left_;
//        delete right_;
//        std::cout << "delete combined expression \n";
//    };
//    NumericalExpression::~NumericalExpression() {
//        std::cout << "delete numerical expression \n";
//    };
//    NullExpression::~NullExpression() {
//        std::cout << "delete null expression \n";
//    };
//    OldExpression::~OldExpression() {
//        std::cout << "delete old expression \n";
//    };
//    MultiplyExpression::~MultiplyExpression() {
//        std::cout << "delete multiply expression \n";
//    };
//    AdditionExpression::~AdditionExpression() {
//        std::cout << "delete addition expression \n";
//    };
//    CombinedExpression::CombinedExpression(Expression *left, Expression *right) : Expression() {
//        left_ = left;
//        right_ = right;
//    }
//    NumericalExpression::NumericalExpression(int value) : Expression() {
//        value_ = value;
//    }
//    NumericalExpression::NumericalExpression(const NumericalExpression &t) {
//        std::cout << "copy numerical exp \n";
//        value_ = t.value_;
//    }
//
//    CombinedExpression::CombinedExpression(const CombinedExpression &t) {
//        std::cout << "copy Combined exp \n";
//        left_ = t.left_;
//        right_ = t.right_;
//    }
//    CombinedExpression& CombinedExpression::operator=(const CombinedExpression& other){
//        std::cout << "copy assign combined \n";
//
//        left_ = other.left_;
//        right_ = other.right_;
//        return *this;
//    }
//
//    int NumericalExpression::evaluate(int old) {
////        std::cout <<"get value " << value_ << "\n";
//
//        return value_;
//    }
//    NullExpression::NullExpression() : Expression() {
//    }
//
//    int NullExpression::evaluate(int old) {
//        return 0;
//    }
//
//    OldExpression::OldExpression() : Expression() {
//        std::cout << "make old exp \n";
//
//    }
//
//    int OldExpression::evaluate(int old) {
////        std::cout <<"get old "<<old<<"\n";
//
//        return old;
//    }
//
//    AdditionExpression::AdditionExpression(Expression *left, Expression *right) : CombinedExpression(left, right) {}
//
//    int AdditionExpression::evaluate(int old) {
//        std::cout <<"adding "<<old<<"\n";
//
//        return left_->evaluate(old) + right_->evaluate(old);
//    }
//
//    AdditionExpression::AdditionExpression(const AdditionExpression &t) : CombinedExpression(t) {
//        std::cout << "copy addition exp \n";
//    }
//    MultiplyExpression::MultiplyExpression(Expression *left, Expression *right) : CombinedExpression(left, right) {}
//
//    int MultiplyExpression::evaluate(int old) {
////        std::cout <<"multiplying "<<old<<"\n";
////        std::cout << "f("<<left_<<"):" << typeid(*left_).name() << "\n";
////        std::cout << "f("<<right_<<"):" << typeid(*right_).name() << "\n";
//
//        return left_->evaluate(old) * right_->evaluate(old);
//    }
//    Monkey::Monkey(const Monkey &t){
//        std::cout <<"copy monkey \n";
//        index = t.index;
//        items = t.items;
//        test_divisor = t.test_divisor;
//        index_true = t.index_true;
//        index_false = t.index_false;
//        expression_ = t.expression_;
//        std::cout <<"copy monkey exp "<< expression_ << "\n";
//
//    }
//    Monkey::Monkey(int monkey_index, std::vector<int> monkey_items, int monkey_test_divisor, int monkey_index_true,
//                   int monkey_index_false, Expression* expression) {
//        index = monkey_index;
//        items = monkey_items;
//        test_divisor = monkey_test_divisor;
//        index_true = monkey_index_true;
//        index_false = monkey_index_false;
//        expression_ = expression;
//        std::cout << "check exp " << "\n" ;
//
//        std::cout << expression_->evaluate(10) << " checked" << "\n" ;
//
////        value_ = 0;
//    }
//
//    void Monkey::inspect_items() {
//        int check = 1;
//        std::cout << "start " << check << "\n";
//        std::cout << expression_->evaluate(10) << "\n" ;
//
//        check = expression_->evaluate(check);
//        std::cout << "check " << check << "\n";
//        std::cout << "f("<<expression_<<"):" << typeid(*expression_).name() << "\n";
////
////        for (int i = 0; i < items.size(); i++) {
////            std::cout << "before " << items[i] << "\n";
////            items[i] = expression_->evaluate(items[i]);
////            std::cout << "after " << items[i] << "\n";
////        }
//    }
//    void Monkey::set_expression(Expression* expression) {
//        expression_ = expression;
//        std::cout << expression_->evaluate(10) << "\n" ;
//        std::cout << "Expression pntr " << expression_ << "\n" ;
//        std::cout << "f("<<expression_<<"):" << typeid(*expression_).name() << "\n";
//
//    };


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
//
//        // TODO make a list of each expression that would be stored as a ptr
//        std::vector<Expression*> expression_left_list;
//        std::vector<Expression*> expression_right_list;
//        std::vector<Expression*> expression_total_list;
//        std::vector<OldExpression> old_expression_list;
//        std::vector<NumericalExpression> numerical_expression_list;
//        std::vector<MultiplyExpression> multiply_expression_list;
//        std::vector<AdditionExpression> add_expression_list;
//        std::vector<std::unique_ptr<Expression>> expression_left_ptr;
//        std::vector<std::unique_ptr<Expression>> expression_right_ptr;
//        std::vector<std::unique_ptr<Expression>> expression_total_ptr;


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
//                                std::cout << "MAKE EXPRESSION \n";
//                                old_expression_list.emplace_back();
//                                std::cout << "MADE EXPRESSION \n";
//                                expression_left_list.push_back(&old_expression_list[old_expression_list.size()-1]);
//                                std::cout << "STORED PTR EXPRESSION \n";
                                exp_1 = std::make_unique<OldExpression>();

                            }
                            else {
//                                numerical_expression_list.emplace_back(std::stoi(operand_1));
//
//                                expression_left_list.push_back(&numerical_expression_list[numerical_expression_list.size()-1]);
                                exp_1 = std::make_unique<ValueExpression>(10);
                            }
                            if (operand_2 == "old") {
//                                old_expression_list.emplace_back();
//                                expression_right_list.push_back(&old_expression_list[old_expression_list.size()-1]);
                                exp_2 = std::make_unique<OldExpression>();

                            }
                            else {
//                                std::cout <<"made operand 2 " << operand_2 << "\n";
//                                numerical_expression_list.emplace_back(std::stoi(operand_2));
//                                expression_right_list.push_back(&numerical_expression_list[numerical_expression_list.size()-1]);
                                exp_2 = std::make_unique<ValueExpression>(10);
                            }
                            if (operator_ == "+") {
//                                add_expression_list.emplace_back(expression_left_list[expression_left_list.size()-1], expression_right_list[expression_right_list.size()-1]);
//                                expression_total_list.push_back(&add_expression_list[add_expression_list.size()-1]);
////                                std::cout << "add eval" << add_expression_list[0].evaluate(10) <<"\n";
                                total_exp = std::make_unique<AdditionExpression>(std::move(exp_1), std::move(exp_2));

                            }
                            else if (operator_ == "*") {
//                                multiply_expression_list.emplace_back(expression_left_list[expression_left_list.size()-1], expression_right_list[expression_right_list.size()-1]);
//                                expression_total_list.push_back(&multiply_expression_list[multiply_expression_list.size()-1]);
//                                std::cout << "mult eval" << multiply_expression_list[0].evaluate(10) <<"\n";
                                total_exp = std::make_unique<MultiplyExpression>(std::move(exp_1), std::move(exp_2));

                            }
//                            std::cout << "pnt eval " << expression_total_list[0]->evaluate(10) <<"\n";
                            break;
                        }
                    }
                }
                if (lines_left == 0) {
                    lines_left = line_per_data;
                    Monkey monkey = Monkey(monkey_index, monkey_items, monkey_test_divisor, monkey_index_true, monkey_index_false, std::move(total_exp));
                    monkeys.emplace_back(monkey_index, monkey_items, monkey_test_divisor, monkey_index_true, monkey_index_false, std::move(total_exp));
//                    std::cout << "sizes " << monkeys.size()-1 <<", " << monkeys.size()-1 << expression_total_list[monkeys.size()-1]<< "\n";
////                    monkeys[monkeys.size()-1].set_expression(expression_total_list[monkeys.size()-1]);
//                    std::cout << "still there? 0 " << monkeys[0].expression_ << "or " << expression_total_list[0] << "\n";
////                    std::cout << "still there? 1 " << monkeys[1].expression_ << "or " << expression_total_list[1] << "\n";
////                    std::cout << "still there? 2 " << monkeys[2].expression_ << "or " << expression_total_list[2] << "\n";
////                    std::cout << "still there? 3 " << monkeys[3].expression_ << "or " << expression_total_list[3] << "\n";
//                    std::cout << "each one " << multiply_expression_list[0].evaluate(10) << " end" << "\n";
//                    std::cout << "each one " << monkeys[0].expression_->evaluate(10) << " end" << "\n";
////                    std::cout << "each one " << add_expression_list[0].evaluate(10) << " end" << "\n";
//                    std::cout << "End "<< multiply_expression_list.size() << "\n";
////                    std::cout << "each one " << multiply_expression_list[1].evaluate(10) << " end" << "\n";
////                    std::cout << "each one " << add_expression_list[1].evaluate(10) << " end" << "\n";

                }
                else {
                    lines_left -= 1;
                }
            }
        }
        else {
            std::cout << "\n File not open!";
        }

//        for (int i = 0; i < add_expression_list.size(); i++) {
//            std::cout << "test " << i << " " << add_expression_list[i].evaluate(10)<< "\n";
//        }
//        std::cout << "Inspect 0" << "\n" ;
//        monkeys[0].inspect_items();
//        std::cout << "Inspect 1" << "\n" ;
//        monkeys[1].inspect_items();
//        std::cout << "Inspect 2" << "\n" ;
//        monkeys[2].inspect_items();
//        std::cout << "Inspect 3" << "\n" ;
//        monkeys[3].inspect_items();

        auto v_exp_1 = std::make_unique<ValueExpression>(10);
        auto v_exp_2 = std::make_unique<ValueExpression>(10);
        std::cout << v_exp_1->evaluate(0) << '\n';
        auto add_exp =  std::make_unique<AdditionExpression>(std::move(v_exp_1), std::move(v_exp_2));
//        auto add_exp = std::make_unique<AdditionExpression>(v_exp_1, v_exp_2);
        std::cout << add_exp->evaluate(0) << '\n';

        return 0;
    }

    ValueExpression::ValueExpression(int value)
    {
        _value = value;
    }

    int ValueExpression::evaluate(int old)
    {
        return _value;
    }
    ValueExpression::ValueExpression(const ValueExpression &t) {
        std::cout << "copy value exp \n";
        _value = t._value;
    }

    int OldExpression::evaluate(int old)
    {
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
        return _left->evaluate(old) + _right->evaluate(old);
    }
    MultiplyExpression::MultiplyExpression(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right)
            :CombinedExpression(std::move(left), std::move(right))
    {

    }

    int MultiplyExpression::evaluate(int old)
    {
        return _left->evaluate(old) * _right->evaluate(old);
    }

    Monkey::Monkey(int monkey_index, std::vector<int> monkey_items, int monkey_test_divisor, int monkey_index_true,
            int monkey_index_false, std::unique_ptr<Expression> expression)
    {

    }
//    Monkey& Monkey::operator=( const Monkey &t )
//    {
//        expression.reset( new Expression( *t.expression ) );
//        return *this,
//    }
//    Monkey& Monkey::operator=(const Monkey& t)
//    {
//        return <#initializer#>;
//    }

//    Monkey::Monkey(const Monkey& t)
//    {
//        std::cout << "copy monkey exp \n";
//        expression = std::move(t.expression);
//    }
}
