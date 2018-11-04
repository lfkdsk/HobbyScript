//
// Created by 刘丰恺 on 2018/11/4.
//

#ifndef LLVM_RUNNER_GENERATOR_LITERALS_H
#define LLVM_RUNNER_GENERATOR_LITERALS_H


#include <vector>
#include <map>
#include <llvm/IR/Value.h>

class generator_id_context {
public:
    llvm::Value *get_id(const std::string &id) const;

    void set_id(const std::string &id, llvm::Value *alloca);

    void push();

    void pop();

private:
    std::vector<std::map<std::string, llvm::Value *>> env;
};


namespace gen {
    llvm::Value *get_id(const std::string &id);
}

#endif //LLVM_RUNNER_GENERATOR_LITERALS_H
