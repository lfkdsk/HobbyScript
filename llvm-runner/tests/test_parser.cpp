//
// Created by 刘丰恺 on 20/1/2020.
//

#include <gtest/gtest.h>
#include "common/common.h"
#include "test_common.h"

extern "C" int yyparse(void);

TEST(MY_TEST, ParserTest) {
    auto *context = test_parse(get_test_parse_input() + separator + "constant_value.hobby", llvm_module.get());
}