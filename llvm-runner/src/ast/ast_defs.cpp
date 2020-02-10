//
// Created by 刘丰恺 on 23/1/2020.
//

#include "ast_defs.h"
#include "visitor/visitors.hpp"
#include "type/ast_types.hpp"
#include "common/ast_common.h"

static QString emptyString;

CodeGen *AstDef::make_def_gen(
        AstContext *parent,
        AstType *ast_type,
        const QString &n,
        AstNode *var
) {
    if (var != nullptr) {
        auto visitor = new CODEGEN_VISITOR(parent);
        AST_TYPE_AUTO_DOWNCAST(var, visitor);
    }

    CodeGen *v = var ? var->codegen_result() : nullptr;
    if (v && !ast_type && v->type->isStructTy()) {
        return v;
    }

    llvm::Type *t = nullptr;
    llvm::LLVMContext &c = parent->context();

    if (auto *ast_type_gen = dynamic_cast<ClassType *>(ast_type)) {
        ast_type_gen->context = parent;
        auto *get_class_def = parent->find_class(ast_type_gen->name);
        if (get_class_def) {
            // TODO: check get class def == v type.
            if (v) {
                return v;
            }

            QVector<QPair<QString, CodeGen *>> args;
            return get_class_def->make_new_class(parent, args);
        }
    } else if (dynamic_cast<StringType *>(ast_type) && v) {
//        v = new NewGen(str_type->llvm_type(parent->context()));
        ((StringLiteGen *) v)->name = n;
        t = v->type;
    } else if (ast_type) {
        auto visitor = new LLVM_TYPE_VISITOR(parent->context());
        TYPE_TYPE_AUTO_DOWNCAST(ast_type, visitor);
        t = ast_type->codegen_result();
    } else if (v) {
        t = v->type;
    }

    return new DefGen(n, t, v);
}

AstDef::AstDef() {
    this->runtime_type = AstDefTy;
}
