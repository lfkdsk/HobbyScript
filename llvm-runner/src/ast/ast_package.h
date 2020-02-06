//
// Created by 刘丰恺 on 20/1/2020.
//

#ifndef LLVM_RUNNER_AST_PACKAGE_H
#define LLVM_RUNNER_AST_PACKAGE_H

#include "ast_node.h"
#include "common/common.h"
#include "runtime/runtime.h"
#include "common/visitor_common.h"
#include "gen/llvm_generator.h"
#include "runtime/plugins.h"

class AstPackage : public AstNode, public AST_BASE(AstPackage) {
public:
    QVector<QString> names;
    QVector<AstNode *> lines;
public:
    AstContext *compile(llvm::Module *module);

    void codegen(llvm::LLVMContext &llvm_context, llvm::Module *module);

    inline llvm::Function *package_function() {
        return package_func;
    };

private:
    QVector<CodeGen *> code_gens;
    llvm::Function *package_func = nullptr;
    CODEGEN_VISITOR *code_gen_visitor = nullptr;
};


#endif //LLVM_RUNNER_AST_PACKAGE_H
