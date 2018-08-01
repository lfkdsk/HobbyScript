//
// Created by 刘丰恺 on 2018/8/1.
//

#ifndef LLVM_RUNNER_ASTVISITOR_H
#define LLVM_RUNNER_ASTVISITOR_H

#include <nlohmann/json.hpp>
using json = nlohmann::json;

class AstVisitor {
public:
    AstVisitor(json load_json);
    virtual ~AstVisitor();
    json get_json();
    void visit_ast_node(json json_object);
    void visit_ast_leaf(json json_object);
    void visit_ast_list(json json_object);
    void visit_number(json json_object);
private:
    json load_json;
};


#endif //LLVM_RUNNER_ASTVISITOR_H
