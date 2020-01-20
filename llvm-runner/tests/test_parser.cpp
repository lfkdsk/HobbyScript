//
// Created by 刘丰恺 on 20/1/2020.
//

#include <gtest/gtest.h>
#include "parser/hobby.tab.hpp"

extern "C" int yyparse(void);

TEST(MY_TEST, ParserTest) {
    yyparse();
}