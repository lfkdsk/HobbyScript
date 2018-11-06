//
// Created by 刘丰恺 on 2018/8/1.
//

#ifndef LLVM_RUNNER_ASTNODE_H
#define LLVM_RUNNER_ASTNODE_H

#include <rapidjson/document.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/LLVMContext.h>

using json = rapidjson::Value;
using document = rapidjson::Document;

template<class T>
using pointer = std::shared_ptr<T>;

using value = llvm::Value;
using string = std::string;
using value_pointer = value *;

struct node_type {

};

class ast_node {
public:
    ast_node(json &load_json);

    virtual ~ast_node() {}

    const json &get_json();

    int get_tag() { return tag; };

    void set_location(int lineno, int colno);

    int get_line_number() { return lineno; }

    int get_column_number() { return colno; }

protected:
    rapidjson::Value &load_json;
private:
    int tag;
    int lineno, colno;
    node_type type;

public:
    virtual void generate_code();
};


#endif //LLVM_RUNNER_ASTNODE_H
