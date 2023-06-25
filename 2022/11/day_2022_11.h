//
// Created by simon on 30/03/23.
//

#ifndef ADVENTOFCODE_DAY_2022_11_H
#define ADVENTOFCODE_DAY_2022_11_H

#include <vector>

namespace day202211 {
    // Interpreter pattern.
    class Expression {
    protected:
        Expression* left_;
        Expression* right_;
        int value_;
    public:
        // Destructor guaranteed to be called when out of scope
        Expression(int value, Expression *left, Expression *right) {};
        virtual int evaluate(int old) = 0;
    };

    class NumericalExpression : public Expression {
        public:
            NumericalExpression(int value, Expression *left, Expression *right);
            int evaluate(int old) override;
            void set_value(int value);
    };

    class OldExpression : public NumericalExpression {
        public:
            OldExpression(int value, Expression *left, Expression *right);
            int evaluate(int old) override;

    };

    class AdditionExpression : public NumericalExpression {
        public:
            AdditionExpression(int value, Expression *left, Expression *right);
            int evaluate(int old) override;
    };

    class MultiplyExpression : public NumericalExpression {

        public:
            MultiplyExpression(int value, Expression *left, Expression *right);
            int evaluate(int old) override;
    };

    class Monkey
    {
    private:
        std::vector<int> items;
        int test_divisor;
        int index_true;
        int index_false;
        int value_;

    public:
        int index;
        Expression* expression_;

        Monkey(int monkey_index, std::vector<int> monkey_items, int monkey_test_divisor, int monkey_index_true,
               int monkey_index_false);
        void inspect_items();
        void set_expression(Expression* expression);
    };
    int run(std::filesystem::path data_path);
}

#endif //ADVENTOFCODE_DAY_2022_11_H
