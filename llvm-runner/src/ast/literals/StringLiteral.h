//
// Created by 刘丰恺 on 2018/8/8.
//

#ifndef LLVM_RUNNER_STRINGLITERAL_H
#define LLVM_RUNNER_STRINGLITERAL_H

#include "../common/AstNode.h"

using string = std::string;

class StringLiteral : public AstNode {
public:
    StringLiteral(const json &load_json);

    string get_string() {
        return text;
    }

private:
    string text;
};


#endif //LLVM_RUNNER_STRINGLITERAL_H
