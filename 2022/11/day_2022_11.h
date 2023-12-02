//
// Created by simon on 30/03/23.
//

#ifndef ADVENTOFCODE_DAY_2022_11_H
#define ADVENTOFCODE_DAY_2022_11_H

#include <vector>

namespace day202211 {
//    // Interpreter pattern.
//    class Expression {
//    public:
//        // Destructor guaranteed to be called when out of scope
//        virtual ~Expression(){};
//        virtual int evaluate(int old) = 0;
//    };
//    class CombinedExpression : public Expression {
//    public:
//        // Destructor guaranteed to be called when out of scope
//        ~CombinedExpression();
//        CombinedExpression(Expression *left, Expression *right);
//        virtual int evaluate(int old) = 0;
//        Expression* left_;
//        Expression* right_;
//        CombinedExpression(const CombinedExpression &t);  // Copy constuctor
//        CombinedExpression& operator=(const CombinedExpression& other);
//    };
//
//    class NumericalExpression : public Expression {
//        public:
//            ~NumericalExpression();
//            NumericalExpression(int value);
//            int evaluate(int old) override;
//            int value_;
//            NumericalExpression(const NumericalExpression &t);  // Copy constuctor
//
//    };
//
//    class NullExpression : public Expression {
//        public:
//            ~NullExpression();
//            NullExpression();
//            int evaluate(int old) override;
////            NullExpression(const NullExpression &t){};
//        };
//
//    class OldExpression : public Expression {
//        public:
//            ~OldExpression();
//            OldExpression();
//            int evaluate(int old) override;
//            OldExpression(const OldExpression &t){};  // Copy constuctor
//
//    };
//
//    class AdditionExpression : public CombinedExpression {
//        public:
//            ~AdditionExpression();
//            AdditionExpression(Expression *left, Expression *right);
//            int evaluate(int old) override;
//            AdditionExpression(const AdditionExpression &t);  // Copy constuctor
//
//    };
//
//    class MultiplyExpression : public CombinedExpression {
//
//        public:
//            ~MultiplyExpression();
//            MultiplyExpression(Expression *left, Expression *right);
//            int evaluate(int old) override;
//    };
//
//    class Monkey
//    {
//    private:
//        std::vector<int> items;
//        int test_divisor;
//        int index_true;
//        int index_false;
//        int value_;
//
//    public:
//        ~Monkey();
//        int index;
//        Expression* expression_;
//
//        Monkey(int monkey_index, std::vector<int> monkey_items, int monkey_test_divisor, int monkey_index_true,
//               int monkey_index_false, Expression* expression);
//        void inspect_items();
//        void set_expression(Expression* expression);
//        Monkey(const Monkey &t);  // Copy constuctor
//
//    };

    class Expression
    {
    public:
        // Destructor guaranteed to be called when out of scope
        virtual ~Expression()= default;
        virtual int evaluate(int old) = 0;
        virtual int update_modulo(int old, int divisor) = 0;
        auto clone() const { return std::unique_ptr<Expression>(clone_impl()); }
    protected:
        virtual Expression* clone_impl() const = 0;
    };

    class OldExpression : public Expression {
        public:
            ~OldExpression() override= default;
            OldExpression()= default;
            int evaluate(int old) override;
            int update_modulo(int old, int divisor) override;
            OldExpression(const OldExpression &t){};  // Copy constuctor

        protected:
            virtual OldExpression* clone_impl() const override { return new OldExpression(*this); };

    };
    class ValueExpression : public Expression {
        public:
            ~ValueExpression() override= default;
            explicit ValueExpression(int value);
            int evaluate(int old) override;
            int update_modulo(int old, int divisor) override;
            ValueExpression(const ValueExpression &t);  // Copy constuctor

        protected:
            virtual ValueExpression* clone_impl() const override { return new ValueExpression(*this); };
        private:
            int _value;

    };
    class CombinedExpression : public Expression {
        public:
            // Destructor guaranteed to be called when out of scope
            ~CombinedExpression() override= default;
            CombinedExpression(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right);
            CombinedExpression(CombinedExpression const& t) : CombinedExpression(t._left->clone(), t._right->clone()) {}
            CombinedExpression(CombinedExpression && t) = default;
            CombinedExpression& operator=(CombinedExpression const& t) { _left = t._left->clone();_right = t._right->clone(); return *this; }
            CombinedExpression& operator=(CombinedExpression && t) = default;
        protected:
            std::unique_ptr<Expression> _left;
            std::unique_ptr<Expression> _right;
    };
    class AdditionExpression : public CombinedExpression {
        public:
            ~AdditionExpression() override= default;
            AdditionExpression(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right);
            int evaluate(int old) override;
            int update_modulo(int old, int divisor) override;

        protected:
            virtual AdditionExpression* clone_impl() const override { return new AdditionExpression(*this); };

    };
    class MultiplyExpression : public CombinedExpression {
        public:
            ~MultiplyExpression() override= default;
            MultiplyExpression(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right);
            int evaluate(int old) override;
            int update_modulo(int old, int divisor) override;

        protected:
            virtual MultiplyExpression* clone_impl() const override { return new MultiplyExpression(*this); };
    };
    class Monkey
    {
        private:
            int index_true;
            int index_false;
            std::unique_ptr<Expression> expression;
    public:
        int test_divisor;
        ~Monkey() = default;
        Monkey(int monkey_index, std::vector<int> monkey_items, int monkey_test_divisor, int monkey_index_true,
               int monkey_index_false, std::unique_ptr<Expression> monkey_expression);
        Monkey(Monkey const& t) : expression(t.expression->clone()) {}
        Monkey(Monkey && t) = default;
        Monkey& operator=(Monkey const& t) { expression = t.expression->clone(); return *this; }
        Monkey& operator=(Monkey && t) = default;
        void init_modulos(std::vector<int> &monkey_divisors);
        void inspect_items(std::vector<Monkey> &monkeys, std::vector<int> &monkey_divisors);
        int n_inspections;
        int index;
        std::vector<int> items;
        std::vector<std::vector<int>> modulos;

    };

    int run(std::filesystem::path data_path);
}

#endif //ADVENTOFCODE_DAY_2022_11_H
