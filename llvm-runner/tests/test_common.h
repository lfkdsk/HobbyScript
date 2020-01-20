//
// Created by 刘丰恺 on 20/1/2020.
//

#ifndef LLVM_RUNNER_TEST_COMMON_H
#define LLVM_RUNNER_TEST_COMMON_H

#include "utils/common.h"
#include "ast/ast_nodes.hpp"
#include "parser/hobby.tab.hpp"
#include "runtime/runtime.h"

AstContext *parse(const QString &fileName, llvm::Module *module);


#endif //LLVM_RUNNER_TEST_COMMON_H
