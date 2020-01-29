//
// Created by 刘丰恺 on 23/1/2020.
//

#ifndef LLVM_RUNNER_TYPE_LLVM_VISITOR_H
#define LLVM_RUNNER_TYPE_LLVM_VISITOR_H

#include "common/common.h"
#include "visitor_base.h"

class LLVMTypeVisitor : public TypeBaseVisitor {
public:
    explicit LLVMTypeVisitor(llvm::LLVMContext &context) : context(context) {}
public:
    void visit(AstType &gen) override;

    void visit(AutoType &gen) override;

    void visit(ClassType &gen) override;

    void visit(IntegerType &gen) override;

private:
    llvm::LLVMContext &context;
};


#endif //LLVM_RUNNER_TYPE_LLVM_VISITOR_H
