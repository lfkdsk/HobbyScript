//
// Created by 刘丰恺 on 22/1/2020.
//

#ifndef LLVM_RUNNER_AST_TYPES_H
#define LLVM_RUNNER_AST_TYPES_H

#include "ast_type.h"
#include "auto_type.h"
#include "integer_type.h"
#include "class_type.h"
#include "llvm_struct_type.h"
#include "string_type.h"

static AstType *string_type = new StringType();
static AstType *any_type = new AstType(AutoTyId);
static AstType *void_type = new AstType(VoidTyID);
static AstType *float_type = new AstType(FloatTyID);
static AstType *double_type = new AstType(DoubleTyID);
static AstType *null_type = new AstType(NullTyId);


#endif //LLVM_RUNNER_AST_TYPES_H
