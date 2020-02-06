#include <gtest/gtest.h>
#include "parser/hobby.tab.hpp"

extern "C" int yyparse(void);
extern "C" FILE yyin;


int main(int argc, char **argv) {
//    tgc_start(&gc, &argc);
//    tgc_stop(&gc);
//    return 0;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
