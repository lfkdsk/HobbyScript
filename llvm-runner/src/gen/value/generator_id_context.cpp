//
// Created by 刘丰恺 on 2018/11/4.
//

#include "generator_id_context.h"

void generator_id_context::set_id(const std::string &id, llvm::Value *alloca) {
    (*env.rbegin())[id] = alloca;
}

llvm::Value *generator_id_context::get_id(const std::string &id) const {
    for (auto it = env.rbegin(); it != env.rend(); it++) {
        if ((*it).find(id) != (*it).end()) {
            return (*it).at(id);
        }
    }
    throw std::invalid_argument("[gen_id_context::get_llvm_mem] Unknown identifier");
}

void generator_id_context::push() {

}

void generator_id_context::pop() {

}