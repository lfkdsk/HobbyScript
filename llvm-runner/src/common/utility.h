//
// Created by 刘丰恺 on 21/1/2020.
//

#ifndef LLVM_RUNNER_UTILITY_H
#define LLVM_RUNNER_UTILITY_H

#include "common.h"

template<typename T, typename K>
inline static T *get_map_value(const QMap<K, T *> &map, const K &name) {
    auto has = map.contains(name);
    return has ? map.find(name).value() : nullptr;
}

template<typename T>
inline static T *get_map_value(const QHash<QString, T *> &map, const QString &name) {
    auto has = map.contains(name);
    return has ? map.find(name).value() : nullptr;
}

template<typename T>
inline llvm::Value *to_llvm_value(llvm::LLVMContext &context, T v);

template<typename T>
inline llvm::Value *to_llvm_value(llvm::LLVMContext &context, T *v) {
    return v;
}

inline llvm::Value *to_llvm_value(llvm::LLVMContext &context, uint64_t v) {
    auto *type = llvm::IntegerType::get(context, 32);
    return llvm::ConstantInt::get(type, v, true);
}

#endif //LLVM_RUNNER_UTILITY_H
