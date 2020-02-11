//
// Created by 刘丰恺 on 11/2/2020.
//

#include "gtest/gtest.h"
#include "test_common.h"

TEST(MY_TEST, CODEGENCPP) {
    gen_cpp_from_ir(get_test_project_dir() + separator + "test.ll");
}