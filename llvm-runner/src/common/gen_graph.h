//
// Created by 刘丰恺 on 21/1/2020.
//

#ifndef LLVM_RUNNER_GEN_GRAPH_H
#define LLVM_RUNNER_GEN_GRAPH_H

#include <fstream>
#include "common/visitor_common.h"
#include "visitor/visitors.hpp"
#include <iostream>

static void gen_one_dot_node(std::ofstream &of, AstNode &node, bool with_global_index = false) {
    auto visitor = new GRAPHGEN_VISITOR(of, with_global_index);
    of << "digraph ast {" << std::endl;
    of << "rankdir=LR;" << std::endl;
    visitor->visit(node);
    of << "}";
    of.close();
}

static void print_llvm_modules(llvm::Module *module) {
    std::string str;
    llvm::raw_string_ostream os(str);
    os << *module;
    os.flush();
    std::cout << str << std::endl;
}

static void output_llvm_modules(llvm::Module *module) {
    std::string str;
    llvm::raw_string_ostream os(str);
    os << *module;
    os.flush();

    std::ofstream myfile;
    myfile.open(QString(get_plugin_dir() + separator + "main.ll").toStdString());
    myfile << str << std::endl;
}

#endif //LLVM_RUNNER_GEN_GRAPH_H
