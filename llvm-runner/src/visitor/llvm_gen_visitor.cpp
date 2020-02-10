//
// Created by 刘丰恺 on 21/1/2020.
//

#include "runtime/runtime.h"
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
        v = llvm_type_cast(b, that.type, v); // reset llvm type
        // alloca ptr and save store
        that.value = b.CreateAlloca(that.type, nullptr, that.name.toUtf8().toStdString());
        builder.CreateStore(v, that.value);
    }
}

void LLVMCodeGenVisitor::visit(StringLiteGen &gen) {
    auto generator = this->generator();
    auto func = generator.func;
    auto &builder = generator.builder();
    auto &that = gen;

    ulong length = that.str().toStdWString().size() * sizeof(wchar_t);
    auto *string_ptr = builder.CreateGlobalStringPtr(llvm::StringRef(
            (const char *) that.str().toStdWString().c_str(), length
    ));

    auto *finalize = Plugins::get_function("HNI_StringObject_Finalize");
    auto *init = Plugins::get_function("HNI_StringObject_Init");

    auto new_gen = NewGen(that.type);
    new_gen.is_escape = that.is_escape;
    new_gen.finalizer = new ValueGen(finalize);
    auto *new_obj = new_gen.generate(this);
    CallGen::call(builder, init, string_ptr, (uint64_t) that.str().toStdWString().size());
    that.set_codegen_result(new_obj);
}

void LLVMCodeGenVisitor::visit(NewGen &gen) {
    auto generator = this->generator();
    auto func = generator.func;
    auto &builder = generator.builder();
    auto &that = gen;

    auto int_32_type = llvm::Type::getInt32Ty(this->generator().context());
    llvm::Value *type_id = llvm::ConstantInt::get(int_32_type, (uintptr_t) that.type);
    llvm::Constant *alloc_size = llvm::ConstantExpr::getSizeOf(that.type);
    auto *ptr_type = llvm::PointerType::get(that.type, 0);

    if (that.is_escape) {
        that.value = CallGen::call(builder, Plugins::get_function("hyobject_malloc"), alloc_size);
        that.value = builder.CreateBitCast(that.value, ptr_type);
        llvm::IRBuilder<> ib(this->generator().deallocate);
        CallGen::call(ib, Plugins::get_function("hyobject_free"), that.value);
    }
}
