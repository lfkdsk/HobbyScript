//
// Created by 刘丰恺 on 2018/11/11.
//

#ifndef LLVM_RUNNER_TEST_MACRO_H
#define LLVM_RUNNER_TEST_MACRO_H

#define CHECK_NON_NULL(value) \
    do { \
        EXPECT_NE(nullptr, value); \
    } while(0);\


#endif //LLVM_RUNNER_TEST_MACRO_H
