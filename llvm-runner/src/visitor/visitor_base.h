//
// Created by 刘丰恺 on 20/1/2020.
//

#ifndef LLVM_RUNNER_BASE_VISITOR_H
#define LLVM_RUNNER_BASE_VISITOR_H

#include "common/ast_common.h"
#include "common/gen_common.h"
#include "common/type_common.h"
#include "visitor.h"

class AstBaseVisitor {
public:
    // base
    virtual void visit(AstNode &node) = 0;

    // constant value.
    virtual void visit(AstValue &node) = 0;

    virtual void visit(AstStringLiteral &node) = 0;

    virtual void visit(AstIntegerConstant &node) = 0;

    virtual void visit(AstBoolConstant &node) = 0;

    virtual void visit(AstFloatConstant &node) = 0;

    // package.
    virtual void visit(AstLet &node) = 0;

    virtual void visit(AstDef &node) = 0;

    virtual void visit(AstDefClass &node) = 0;

    virtual void visit(AstList &node) = 0;

    virtual void visit(AstPackage &node) = 0;
};

class GenBaseVisitor {
public:
    virtual void visit(CodeGen &gen) = 0;

    virtual void visit(TypeOnlyGen &gen) = 0;

    virtual void visit(LetGen &gen) = 0;

    virtual void visit(ValueGen &gen) = 0;

    virtual void visit(DefGen &gen) = 0;

    virtual void visit(StringLiteGen &gen) = 0;
};

class TypeBaseVisitor {
public:
    virtual void visit(AstType &gen) = 0;

    virtual void visit(AutoType &gen) = 0;

    virtual void visit(IntegerType &gen) = 0;

    virtual void visit(ClassType &gen) = 0;
};

#endif //LLVM_RUNNER_BASE_VISITOR_H
