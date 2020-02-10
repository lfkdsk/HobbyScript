//
// Created by 刘丰恺 on 23/1/2020.
//

#include "type_llvm_visitor.h"
#include "type/ast_types.hpp"

void LLVMTypeVisitor::visit(AstType &gen) {

}

void LLVMTypeVisitor::visit(AutoType &gen) {

}

void LLVMTypeVisitor::visit(ClassType &gen) {

}

void LLVMTypeVisitor::visit(IntegerType &gen) {
    gen.set_codegen_result(llvm::IntegerType::get(this->context, gen.bit_width));
}

void LLVMTypeVisitor::visit(LLVMStructType &gen) {
    gen.set_codegen_result(gen.llvm_type());
}

void LLVMTypeVisitor::visit(StringType &gen) {
    gen.set_codegen_result(Plugins::get_struct("HyStringObject"));
}

