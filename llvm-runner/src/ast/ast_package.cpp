//
// Created by 刘丰恺 on 20/1/2020.
//

#include "ast_package.h"
#include "visitor/visitors.hpp"

AstContext *AstPackage::compile(llvm::Module *module) {
    // TODO: import names.
    auto *block = new AstContext(module);
    block->module = module;
    block->path_name = name;
    // TODO: solve imports.
    this->code_gen_visitor = new CODEGEN_VISITOR(block);
    for (auto line: lines) {
        AST_TYPE_AUTO_DOWNCAST(line, this->code_gen_visitor);
//        this->code_gen_visitor->visit(*line);
        auto *v = line->codegen_result();
        if (v) {
            this->code_gens.push_back(v);
        }
    }
    return block;
}

void AstPackage::codegen(llvm::LLVMContext &llvm_context, llvm::Module *module) {
    llvm::Type *type = llvm::Type::getVoidTy(llvm_context);
    llvm::Type *argc = llvm::Type::getInt32Ty(llvm_context);
    llvm::FunctionType *function_type = llvm::FunctionType::get(type, argc, true);

    this->package_func = llvm::Function::Create(function_type, llvm::Function::ExternalLinkage, "main", module);

    // set main function params.
    QVector<QString> params_names = {"argc", "argv"};
    auto name_iter = params_names.begin();
    auto type_iter = package_func->arg_begin();
    for (; type_iter != package_func->arg_end(); type_iter++, name_iter++) {
        type_iter->setName(name_iter->toStdString());
    }

    llvm::Module *core = Plugins::load_plugin_core();
    llvm::Function *start_gc = Plugins::get_function("start_gc");

    auto alloc = llvm::BasicBlock::Create(llvm_context, name.toUtf8().toStdString(), package_func);
    auto basic_block = llvm::BasicBlock::Create(llvm_context, name.toUtf8().toStdString(), package_func);
    auto deallocate = llvm::BasicBlock::Create(llvm_context, "dealloc", package_func);

    llvm::IRBuilder<> ir_builder(basic_block);
    auto llvm_generator = LLVMGenContext{module, package_func, &ir_builder, deallocate};
    auto llvm_gen_visitor = new LLVMCodeGenVisitor(&llvm_generator);
    // gen code_gens.
    for (auto gen : code_gens) {
        gen->generate(llvm_gen_visitor);
    }

    // basic block => deallocate
    ir_builder.CreateBr(deallocate);
    // alloca => basic block
    ir_builder.SetInsertPoint(alloc);
    ir_builder.CreateBr(basic_block);
    // return void main.
    ir_builder.SetInsertPoint(deallocate);
    ir_builder.CreateRetVoid();
}
