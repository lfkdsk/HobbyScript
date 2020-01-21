//
// Created by 刘丰恺 on 20/1/2020.
//

#include <gtest/gtest.h>
#include "common/common.h"
#include "test_common.h"
#include "common/gen_graph.h"

extern "C" int yyparse(void);

TEST(MY_TEST, ParserConstantTest) {
    auto *context = test_parse(get_test_parse_input() + separator + "constant_value.hobby", llvm_module.get());
    print_llvm_modules(llvm_module.get());
}

TEST(MY_TEST, ParserVarTest) {
    auto *context = test_parse(get_test_parse_input() + separator + "assign_var_simple.hobby", llvm_module.get());
    print_llvm_modules(llvm_module.get());
}

