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
#include "../ast/ast_nodes.h"
#include "../visitor/AstVisitor.h"
#include "spdlog/spdlog.h"

using value = llvm::Value;
using Type = llvm::Type;
using llvm_context = llvm::LLVMContext;
using IRBuilder = llvm::IRBuilder<>;
using Module = llvm::Module;

template<class T, class P>
constexpr auto Cast = std::static_pointer_cast<T, P>;

template<class K, class V>
using Map = std::map<K, V>;

class LLVMCodeGenVisitor : public Visitor<value_pointer, pointer<ast_node>> {
public:
    LLVMCodeGenVisitor(const pointer<ast_node> &root_node);

    virtual ~LLVMCodeGenVisitor();

    pointer<ast_node> get_root_node();

    value_pointer visit_ast_node(pointer<ast_node> node) override;

    value_pointer visit_ast_leaf(pointer<ast_node> node) override;

    value_pointer visit_binary_expr(pointer<ast_node> node) override;

    value_pointer visit_fun_stmt(pointer<ast_node> node) override;

    value_pointer visit_ast_list(pointer<ast_node> node) override;

    value_pointer visit_def_block(pointer<ast_node> node) override;

    value_pointer visit_number(pointer<ast_node> node) override;

    value_pointer visit_string(pointer<ast_node> node) override;

    value_pointer visit(pointer<ast_node> node) override;

    value_pointer visit() override;

private:
    pointer<ast_node> root_node;
    llvm_context the_context;
    IRBuilder builder;
    pointer<Module> the_module;
    Map<string, value_pointer> name_values;
};


#endif //LLVM_RUNNER_LLVMVISITOR_H
