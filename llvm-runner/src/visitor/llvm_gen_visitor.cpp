//
// Created by 刘丰恺 on 21/1/2020.
//

#include "llvm_gen_visitor.h"
#include "gen/code_gens.hpp"

void LLVMCodeGenVisitor::visit(TypeOnlyGen &gen) {

}

void LLVMCodeGenVisitor::visit(LetGen &gen) {

}

void LLVMCodeGenVisitor::visit(ValueGen &gen) {

}

void LLVMCodeGenVisitor::visit(CodeGen &gen) {

}

void LLVMCodeGenVisitor::visit(DefGen &gen) {
    auto generator = this->generator();
    auto func = generator.func;
    auto &builder = generator.builder();

    auto &that = gen;
    that.is_class = that.type != nullptr ? that.type->isStructTy() : false;
    bool is_seq = that.array_size > 1;

    llvm::LLVMContext &context = builder.getContext();
    auto &block = func->getEntryBlock();

    llvm::IRBuilder<> b(&block);

    if (that.gen_value) { // contains value.
        llvm::Value *v = that.gen_value->generate(this);
        v = that.load(b, v);
        v = llvm_type_cast(b, that.type, v);

        that.value = b.CreateAlloca(that.type, nullptr, that.name.toUtf8().toStdString());
        builder.CreateStore(v, that.value);
    }
}
