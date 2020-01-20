//
// Created by 刘丰恺 on 20/1/2020.
//

#ifndef LLVM_RUNNER_TEST_COMMON_H
#define LLVM_RUNNER_TEST_COMMON_H

#include <fstream>
#include "common/common.h"
#include "ast/ast_nodes.hpp"
#include "parser/hobby.tab.hpp"
#include "runtime/runtime.h"
#include "test_config.h"

AstContext *test_parse(const QString &fileName, llvm::Module *module);

std::ofstream create_test_output(const QString &fileName);

QString get_graph_gen_path();

QString get_test_parse_input();

const constexpr auto separator = std::filesystem::path::preferred_separator;

#endif //LLVM_RUNNER_TEST_COMMON_H
