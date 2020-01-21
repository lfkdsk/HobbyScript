//
// Created by 刘丰恺 on 20/1/2020.
//

#ifndef LLVM_RUNNER_TEST_COMMON_H
#define LLVM_RUNNER_TEST_COMMON_H

#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>
#include "common/common.h"
#include "ast/ast_nodes.hpp"
#include "parser/hobby.tab.hpp"
#include "runtime/runtime.h"
#include "test_config.h"

extern "C" FILE *yyin;
extern "C" int yyparse(void);
const QString TAG = "[Test Common]: ";
const constexpr auto separator = std::filesystem::path::preferred_separator;

static AstContext *test_parse(const QString &fileName, llvm::Module *module) {
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
    return global_packages_contexts[fileName] = now_package->compile(module);
}

static std::ofstream create_test_output(const QString &fileName) {
    return std::ofstream(fileName.toStdString());
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
