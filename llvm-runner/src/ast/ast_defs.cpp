//
// Created by 刘丰恺 on 23/1/2020.
//

#include "ast_defs.h"
#include "ast/ast_class.h"
#include "visitor/visitors.hpp"
#include "type/ast_types.hpp"

static QString emptyString;

CodeGen *AstDef::make_def_gen(
        AstContext *parent,
        AstType *ast_type,
        const QString &n,
        AstNode *var
) {
    if (var != nullptr) {
        CODEGEN_VISITOR(parent).visit(*var);
    }

    CodeGen *v = var ? var->codegen_result() : nullptr;
    if (v && !ast_type && v->type->isStructTy()) {
        return v;
    }

    llvm::Type *t = nullptr;
    llvm::LLVMContext &c = parent->context();

    auto *ast_type_gen = dynamic_cast<ClassType *>(ast_type);
    if (ast_type_gen) {
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
    } else if (ast_type) {
        LLVMTypeVisitor(parent->context()).visit(*ast_type);
        t = ast_type->codegen_result();
    } else if (v)
        t = v->type;

    return new DefGen(n, t, v);
}
