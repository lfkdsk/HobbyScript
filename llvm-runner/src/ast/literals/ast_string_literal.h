//
// Created by 刘丰恺 on 2018/8/8.
//

#ifndef LLVM_RUNNER_STRINGLITERAL_H
#define LLVM_RUNNER_STRINGLITERAL_H

#include <ast/common/ast_value_node.h>
#include "ast_literal.h"

using string = std::string;

class ast_string_literal : public ast_literal {
public:
    ast_string_literal(json &load_json);

    const string &get_string() {
        return str;
    }

protected:
    string str;
};


#endif //LLVM_RUNNER_STRINGLITERAL_H
