//
// Created by 刘丰恺 on 2018/8/1.
//

#ifndef LLVM_RUNNER_ASTVISITOR_H
#define LLVM_RUNNER_ASTVISITOR_H
#include <nlohmann/json.hpp>
#include "../ast/AstNode.h"
using json = nlohmann::json;

class AstVisitor {
public:
    AstVisitor(const json& load_json);
    virtual ~AstVisitor();
    const json& get_json();
    AstNode visit_ast_node(const json& json_object);
    AstNode visit_ast_leaf(const json& json_object);
    AstNode visit_ast_list(const json& json_object);
    AstNode visit_number(const json& json_object);
private:
    json load_json;
};


#endif //LLVM_RUNNER_ASTVISITOR_H
