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
    gen.set_codegen_result(gen.value);
}

void LLVMCodeGenVisitor::visit(CodeGen &gen) {

}

void LLVMCodeGenVisitor::visit(DefGen &gen) {
    auto generator = this->generator();
    auto func = generator.func;
    auto &builder = generator.builder();

    auto &that = gen;
    bool is_class = that.is_class = that.type != nullptr ? that.type->isStructTy() : false;
    bool is_seq = that.array_size > 1;

    llvm::LLVMContext &context = builder.getContext();
    auto &block = func->getEntryBlock();

    llvm::IRBuilder<> b(&block);

    if (that.gen_value) { // contains value.
        if (auto *new_gen = dynamic_cast<NewGen *>(that.gen_value)) {
            new_gen->name = that.name;
        }


        llvm::Value *v = that.gen_value->generate(this);

        if (is_seq || is_class) {
            that.value = v;
            return;
        }

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

    int length = (int) that.str().toStdWString().size() * sizeof(wchar_t);
    auto *string_ptr = builder.CreateGlobalStringPtr(llvm::StringRef(
            (const char *) that.str().toStdWString().c_str(), length
    ));

    auto *finalize = Plugins::get_function("HNI_StringObject_Finalize");
    auto *init = Plugins::get_function("HNI_StringObject_Init");
    auto *create = Plugins::get_function("HNI_StringObject_FromString");
    auto *print = Plugins::get_function("HNI_StringObject_Print");

    auto new_gen = NewGen(that.type);
    new_gen.is_escape = false;
    new_gen.name = that.name;
//    new_gen.finalizer = new ValueGen(finalize);
//    auto *new_obj = new_gen.generate(this);
    auto *new_obj = CallGen::call(builder, create, string_ptr, (uint64_t) that.str().toStdWString().size());

//    CallGen::call(builder, init, new_obj, string_ptr, (uint64_t) that.str().toStdWString().size());
//    CallGen::call(builder, print, new_obj);
//    auto *v = CallGen::call(builder, create, string_ptr);
//    builder.CreateStore(v, new_obj);
    that.set_codegen_result(new_obj);
}

void LLVMCodeGenVisitor::visit(NewGen &gen) {
    auto generator = this->generator();
    auto func = generator.func;
    auto &builder = generator.builder();
    auto &that = gen;

    llvm::IRBuilder<> bd(generator.deallocate);

    auto int_32_type = llvm::Type::getInt32Ty(this->generator().context());
    llvm::Value *type_id = llvm::ConstantInt::get(int_32_type, (uintptr_t) that.type);
    llvm::Constant *alloc_size = llvm::ConstantExpr::getSizeOf(that.type);
    auto *ptr_type = llvm::PointerType::get(that.type, 0);

    if (that.is_escape) {
        that.value = CallGen::call(builder, Plugins::get_function("hyobject_malloc"), alloc_size);
        that.value = builder.CreateBitCast(that.value, ptr_type);
        CallGen::call(bd, Plugins::get_function("hyobject_free"), that.value);
    } else {
        auto &alloc_block = func->getBasicBlockList().front();
        llvm::IRBuilder<> alloc(&alloc_block);
        that.value = alloc.CreateAlloca(that.type, nullptr, that.name.toUtf8().toStdString());
        if (that.finalizer) {
            CallGen::call(bd, llvm::dyn_cast<llvm::Function>(that.finalizer->generate(this)), that.value);
        }
    }

    if (that.constructor) {
//        if (auto *str = dynamic_cast<StringLiteGen *>(that.constructor)) {
//            str->generate(this);
//        }
//        auto *call = dynamic_cast<CallGen *>(that.constructor);
//        call->object = new ValueGen(that.value);
//        that.constructor->generate(this);
    }

    that.set_codegen_result(that.value);
}

void LLVMCodeGenVisitor::visit(CallGen &gen) {
    auto generator = this->generator();
    auto func = generator.func;
    auto &builder = generator.builder();
    auto &that = gen;

}
