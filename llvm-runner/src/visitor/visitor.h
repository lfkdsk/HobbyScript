//
// Created by 刘丰恺 on 2018/8/3.
//

#ifndef LLVM_RUNNER_VISITOR_H
#define LLVM_RUNNER_VISITOR_H

#include <iostream>
#include <utility>

template <typename ... Types>
class Visitor;

template <typename T>
class Visitor<T> {
public:
    virtual void visit(T & visitable) = 0;
};

template <typename T, typename ... TList>
class Visitor<T, TList ...> : public Visitor<TList ...> {
public:
    using Visitor<TList ...>::visit;

    virtual void visit(T & visitable) = 0;
};

template <typename ... TList>
class Visitable {
public:
    virtual void accept(Visitor<TList ...> & visitor) = 0;
};

template <typename Derived, typename ... TList>
class VisitableImpl : public Visitable<TList ...> {
public:
    virtual void accept(Visitor<TList ...> & visitor) {
        visitor.visit(static_cast<Derived &>(*this));
    }
};

class Expression {
public:
    virtual std::string name() = 0;
};

template <typename T> class Constant;
class Variable;

template <typename T>
class Constant : public Expression, public VisitableImpl<Constant<T>, Constant<T>, Variable> {
public:
    virtual std::string name() {
        return "Constant";
    }
};


class Variable : public Expression, public VisitableImpl<Variable, Constant<double>, Variable> {
public:
    virtual std::string name() {
        return "Variable";
    }
};

template <typename ... TList>
class GenericVisitor;

template <typename U, typename T>
class GenericVisitor<U, T> {
protected:
    U u;

public:
    template <typename ... ParamList>
    GenericVisitor(ParamList && ... plist)
            : u(std::forward<ParamList>(plist) ...) { }

    virtual void visit(T & t) {
        u.visit(t);
    }
};

template <typename U, typename T, typename ... TList>
class GenericVisitor<U, T, TList ...> : public GenericVisitor<U, TList ...> {
public:
    template <typename ... ParamList>
    GenericVisitor(ParamList && ... plist)
            : GenericVisitor<U, TList ...>(
            std::forward<ParamList>(plist) ...
    ) { }

    using GenericVisitor<U, TList ...>::visit;
    using GenericVisitor<U, TList ...>::u;

    virtual void visit(T & t) {
        u.visit(t);
    }
};

#endif //LLVM_RUNNER_VISITOR_H
