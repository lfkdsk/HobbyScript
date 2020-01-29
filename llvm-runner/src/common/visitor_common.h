//
// Created by 刘丰恺 on 20/1/2020.
//

#ifndef LLVM_RUNNER_VISITOR_COMMON_H
#define LLVM_RUNNER_VISITOR_COMMON_H

#include "common/ast_common.h"
#include "visitor/visitor.h"
#include "common/type_common.h"

class CodeGenVisitor;

class GraphGenVisitor;

class LLVMCodeGenVisitor;

class LLVMTypeVisitor;

#define CODEGEN_VISITOR GenericVisitor<CodeGenVisitor, AST_BASE_LIST()>

#define GRAPHGEN_VISITOR GenericVisitor<GraphGenVisitor, AST_BASE_LIST()>

#define LLVM_CODEGEN_VISITOR GenericVisitor<LLVMCodeGenVisitor, TYPE_BASE_LIST()>

#define LLVM_TYPE_VISITOR GenericVisitor<LLVMTypeVisitor, TYPE_BASE_LIST()>

#endif //LLVM_RUNNER_VISITOR_COMMON_H
