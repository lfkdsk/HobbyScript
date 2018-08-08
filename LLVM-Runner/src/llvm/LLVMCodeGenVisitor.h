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
#include "../visitor/Visitor.h"
#include "../ast/AstNodes.h"
#include "../visitor/AstVisitor.h"
#include "spdlog/spdlog.h"

using Value = llvm::Value;
using Type = llvm::Type;
using LLVMContext = llvm::LLVMContext;
using IRBuilder = llvm::IRBuilder<>;
using Module = llvm::Module;

template<class T, class P>
constexpr auto Cast = std::static_pointer_cast<T, P>;

template<class K, class V>
using Map = std::map<K, V>;

class LLVMCodeGenVisitor : public Visitor<ValuePointer, Pointer<AstNode>> {
public:
    LLVMCodeGenVisitor(const Pointer<AstNode> &root_node);

    virtual ~LLVMCodeGenVisitor();

    Pointer<AstNode> get_root_node();

    ValuePointer visit_ast_node(Pointer<AstNode> node) override;

    ValuePointer visit_ast_leaf(Pointer<AstNode> node) override;

    ValuePointer visit_binary_expr(Pointer<AstNode> node) override;

    ValuePointer visit_fun_stmt(Pointer<AstNode> node) override;

    ValuePointer visit_ast_list(Pointer<AstNode> node) override;

    ValuePointer visit_def_block(Pointer<AstNode> node) override;

    ValuePointer visit_number(Pointer<AstNode> node) override;

    ValuePointer visit_string(Pointer<AstNode> node) override;

    ValuePointer visit(Pointer<AstNode> node) override;

    ValuePointer visit() override;

private:
    Pointer<AstNode> root_node;
    LLVMContext the_context;
    IRBuilder builder;
    Pointer<Module> the_module;
    Map<string, ValuePointer> name_values;
};


#endif //LLVM_RUNNER_LLVMVISITOR_H
