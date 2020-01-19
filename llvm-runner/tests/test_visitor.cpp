//
// Created by 刘丰恺 on 19/1/2020.
//

#include <gtest/gtest.h>
#include <numeric>
#include <utility>
#include "visitor/visitor.h"
#include "ast/ast_nodes.hpp"

class Expression {
public:
    virtual std::string name() = 0;

    virtual void printData() = 0;
};

template<typename T>
class Constant;

class Variable;

template<typename T>
class Constant : public Expression, public VisitableImpl<Constant<T>, Constant<T>, Variable> {
public:

    Constant(T data) : data(data) {}

    T data;

    virtual std::string name() {
        return "Constant";
    }

    void printData() override {
        std::cout << ((double) data);
    }
};


class Variable : public Expression, public VisitableImpl<Variable, Constant<double>, Variable> {
public:
    Variable(Constant<int> data) : data(std::move(data)) {}

    Constant<int> data;

    virtual std::string name() {
        return "Variable";
    }

    void printData() override {
        std::cout << data.data;
    }
};

class WtfVisitor {
public:
    WtfVisitor(int i = -1, int j = -1, int k = -1) {
        std::cout << "WtfVisitor(" << i << ", " << j << ", " << k << ")\n";
    }

    template<typename T>
    void visit(Constant<T> c) {
        std::cout << "VISITED: Constant \r";
        c.printData();
    }

    void visit(Variable c) {
        std::cout << "VISITED: Variable \r";
        c.printData();
    }
};

TEST(MY_TEST, VISITOR) {
    Variable var = Variable(Constant(200));
    Constant<double> con = Constant(100.0);
    GenericVisitor<WtfVisitor, Constant<double>, Variable> v(5, 6);
    v.visit(con);
}

class AstVisitor {
public:
    void visit(const AstNode& node) {
        std::cout << "node \n ";
    }

    void visit(const AstLet& node) {
        std::cout << "let \n ";
    }

    void visit(const AstValue& value) {
        std::cout << "value \n ";
    }
};

TEST(MY_TEST, AST_VISITOR) {
    AstNode node = AstNode();
    AstLet let = AstLet();
    GenericVisitor<AstVisitor, AstNode, AstLet, AstValue> v;
    v.visit(node);
}


