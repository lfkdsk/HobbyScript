//
// Created by 刘丰恺 on 10/2/2020.
//

#include <gtest/gtest.h>
#include "common/common.h"
#include "test_common.h"
#include "common/gen_graph.h"

extern "C" int yyparse(void);


TEST(MY_TEST, ParseStringASTVar) {
    auto *context = test_ast_parse(get_test_parse_input() + separator + "assign_var_string_literal.hobby");
    ASSERT_EQ(1, context->lines.size());
    ASSERT_TRUE(dynamic_cast<AstDef *>(context->lines.first()));
    ASSERT_EQ("lfkdsk", (dynamic_cast<AstDef *>(context->lines.first()))->vars.first().second->name);
}

TEST(MY_TEST, ParseStringVar) {
    llvm_init();
    auto *m = new llvm::Module("TOP", llvm_global_context);
    llvm_module.reset(m);
    Plugins::load_plugin_package();
    console->info(loaded_structs.size());
    auto *context = test_parse(get_test_parse_input() + separator + "assign_var_string_literal.hobby",
                               llvm_module.get());
    ASSERT_TRUE(!context->symbols.isEmpty());
    ASSERT_TRUE(context->find_symbol_value("test_var"));
}

TEST(MY_TEST, ParseStringVarRunner) {
    llvm_init();
    auto *m = new llvm::Module("TOP", llvm_global_context);
    auto name = get_test_parse_input() + separator + "assign_var_string_literal.hobby";
    llvm_module.reset(m);
    Plugins::load_plugin_package();
    console->info(loaded_structs.size());
    auto *context = test_parse(QString(name), llvm_module.get());
    ASSERT_TRUE(!context->symbols.isEmpty());
    ASSERT_TRUE(context->find_symbol_value("test_var"));
    global_packages[QString(name)]->codegen(llvm_global_context, m);
    test_llvm_run(global_packages[QString(name)], std::move(llvm_module), nullptr);
}


