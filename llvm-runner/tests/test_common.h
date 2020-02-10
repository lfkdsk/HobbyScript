//
// Created by 刘丰恺 on 20/1/2020.
//

#ifndef LLVM_RUNNER_TEST_COMMON_H
#define LLVM_RUNNER_TEST_COMMON_H

#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include "common/common.h"
#include "ast/ast_nodes.hpp"
#include "parser/hobby.tab.hpp"
#include "runtime/runtime.h"
#include "test_config.h"
#include "common/gen_graph.h"

extern "C" FILE *yyin;
extern "C" int yyparse(void);
const QString TAG = "[Test Common]: ";
//const constexpr auto separator = std::filesystem::path::preferred_separator;

static void llvm_init() {
    llvm::InitializeNativeTarget();
    llvm::InitializeNativeTargetAsmPrinter();
    llvm::InitializeNativeTargetAsmParser();
}

static AstPackage *test_ast_parse(const QString &fileName) {
    // save context.
    auto *old_package = ast_current_package;
    ast_current_package = new AstPackage();
    auto old_line_num = yylineno;
    yylineno = 0;

    // set open file.
    yyin = fopen(fileName.toUtf8().constData(), "r");
    if (!yyin) {
        throw create_runtime_error(TAG + "could not open file name: " + fileName);
    }
    if (0 != yyparse()) {
        throw create_runtime_error(TAG + "parse " + fileName + "error");
    }

    fclose(yyin);

    // restore context;
    auto *now_package = ast_current_package;
    ast_current_package = old_package;
    // save package message.
    global_packages[fileName] = now_package;
    return now_package;
}

static AstContext *test_parse(const QString &fileName, llvm::Module *module) {
    return global_packages_contexts[fileName] = test_ast_parse(fileName)->compile(module);
}

static void test_llvm_run(AstPackage *package, std::unique_ptr<llvm::Module> module, char *const *envp) {
    atexit(llvm::llvm_shutdown); // Call llvm_shutdown() on exit.

    print_llvm_modules(module.get());

    if (!package) {
        console->error(QString(TAG + " package is null.").toStdString());
        return;
    }

    llvm::Function *package_func = package->package_function();
    llvm::ExecutionEngine *engine = build_llvm_engine(std::move(module));
    if (!engine) {
        console->error(QString(TAG + " build execute engine is null.").toStdString());
        return;
    }

    Plugins::link_plugins(engine);

    engine->RegisterJITEventListener(llvm::JITEventListener::createOProfileJITEventListener());
    engine->RegisterJITEventListener(llvm::JITEventListener::createIntelJITEventListener());

    std::vector<std::string> noargs = {};
    engine->runFunctionAsMain(package_func, noargs, envp);
}

static std::ofstream create_test_output(const QString &fileName) {
    return std::ofstream(fileName.toUtf8().toStdString());
}

static QString get_graph_gen_path() {
    return get_test_project_dir() + separator + "test_graph_gen";
}

static QString get_test_parse_input() {
    return get_test_project_dir() + separator + "test_parse_input";
}

static QString get_test_graph_gen_validate() {
    return get_test_project_dir() + separator + "validate_graph_gen";
}

static bool compare_file(const std::string &p1, const std::string &p2) {
    std::ifstream f1(p1, std::ifstream::binary | std::ifstream::ate);
    std::ifstream f2(p2, std::ifstream::binary | std::ifstream::ate);

    if (f1.fail() || f2.fail()) {
        return false; //file problem
    }

    if (f1.tellg() != f2.tellg()) {
        return false; //size mismatch
    }

    //seek back to beginning and use std::equal to compare contents
    f1.seekg(0, std::ifstream::beg);
    f2.seekg(0, std::ifstream::beg);
    return std::equal(std::istreambuf_iterator<char>(f1.rdbuf()),
                      std::istreambuf_iterator<char>(),
                      std::istreambuf_iterator<char>(f2.rdbuf()));
}

#endif //LLVM_RUNNER_TEST_COMMON_H
