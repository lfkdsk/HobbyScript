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
    auto *m = new llvm::Module("TOP", llvm_global_context);
    llvm_module.reset(m);
    auto *context = test_parse(get_test_parse_input() + separator + "assign_var_simple.hobby", llvm_module.get());
    ASSERT_TRUE(!context->symbols.isEmpty());
}

TEST(MY_TEST, ParserVarRunLLVM) {
    llvm_init();
    auto name = get_test_parse_input() + separator + "assign_var_simple.hobby";
    auto *m = new llvm::Module("TOP", llvm_global_context);
    llvm_module.reset(m);
    auto *context = test_parse(QString(name), llvm_module.get());
    ASSERT_TRUE(!context->symbols.isEmpty());
    global_packages[QString(name)]->codegen(llvm_global_context, m);
    test_llvm_run(global_packages[QString(name)], std::move(llvm_module), nullptr);
}