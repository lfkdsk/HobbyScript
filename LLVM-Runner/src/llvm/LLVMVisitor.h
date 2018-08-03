//
// Created by 刘丰恺 on 2018/8/3.
//

#ifndef LLVM_RUNNER_LLVMVISITOR_H
#define LLVM_RUNNER_LLVMVISITOR_H

#include <llvm/ADT/STLExtras.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Verifier.h>
#include "../ast/AstNodes.h"
#include "../visitor/Visitor.h"

using Value = llvm::Value;
using LLVMContext = llvm::LLVMContext;
using IRBuilder = llvm::IRBuilder<>;
using Module = llvm::Module;

template<class K, class V>
using Map = std::map<K, V>;

class LLVMVisitor : public Visitor<Pointer<Value>, Pointer<AstNode>> {
public:
    LLVMVisitor(const Pointer<AstNode> &root_node);

    Pointer<AstNode> get_root_node();

    Pointer<llvm::Value> visit_ast_node(Pointer<AstNode> node) override;

    Pointer<llvm::Value> visit_ast_leaf(Pointer<AstNode> node) override;

    Pointer<llvm::Value> visit_binary_expr(Pointer<AstNode> node) override;

    Pointer<llvm::Value> visit_ast_list(Pointer<AstNode> node) override;

    Pointer<llvm::Value> visit_number(Pointer<AstNode> node) override;

    Pointer<llvm::Value> visit(Pointer<AstNode> node) override;

    Pointer<llvm::Value> visit() override;

private:
    Pointer<AstNode> root_node;
    LLVMContext the_context;
    IRBuilder builder;
    Pointer<Module> the_module;
    Map<string, Pointer<Value>> name_values;
};


#endif //LLVM_RUNNER_LLVMVISITOR_H
