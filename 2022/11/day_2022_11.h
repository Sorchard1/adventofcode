//
// Created by simon on 30/03/23.
//

#ifndef ADVENTOFCODE_DAY_2022_11_H
#define ADVENTOFCODE_DAY_2022_11_H

#include <vector>

namespace day202211 {
    // Interpreter pattern.
    class Expression {
    public:
        // Destructor guaranteed to be called when out of scope
        Expression() {};
        virtual int evaluate(int old) = 0;
    };
    class CombinedExpression : public Expression {
    public:
        // Destructor guaranteed to be called when out of scope
        CombinedExpression(Expression *left, Expression *right);
        virtual int evaluate(int old) = 0;
        Expression* left_;
        Expression* right_;
    };

    class NumericalExpression : public Expression {
        public:
            NumericalExpression(int value);
            int evaluate(int old) override;
            int value_;

    };

    class NullExpression : public Expression {
        public:
            NullExpression();
            int evaluate(int old) override;
    };

    class OldExpression : public Expression {
        public:
            OldExpression();
            int evaluate(int old) override;

    };

    class AdditionExpression : public CombinedExpression {
        public:
            AdditionExpression(Expression *left, Expression *right);
            int evaluate(int old) override;
    };

    class MultiplyExpression : public CombinedExpression {

        public:
            MultiplyExpression(Expression *left, Expression *right);
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
               int monkey_index_false, Expression* expression);
        void inspect_items();
        void set_expression(Expression* expression);
    };
    int run(std::filesystem::path data_path);
}

#endif //ADVENTOFCODE_DAY_2022_11_H
