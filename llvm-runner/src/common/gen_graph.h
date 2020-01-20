//
// Created by 刘丰恺 on 21/1/2020.
//

#ifndef LLVM_RUNNER_GEN_GRAPH_H
#define LLVM_RUNNER_GEN_GRAPH_H

#include <fstream>
#include "visitor/visitors.hpp"

static void gen_one_dot_node(std::ofstream &of, AstNode &node, bool with_global_index=false) {
    auto visitor = new GraphGenVisitor(of, with_global_index);
    of << "digraph ast {" << std::endl;
    of << "rankdir=LR;" << std::endl;
    visitor->visit(node);
    of << "}";
    of.close();
}

#endif //LLVM_RUNNER_GEN_GRAPH_H
