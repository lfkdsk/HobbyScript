//
// Created by 刘丰恺 on 4/2/2020.
//

#ifndef LLVM_RUNNER_PLUGINS_H
#define LLVM_RUNNER_PLUGINS_H


#include "common/common.h"
#include "runtime.h"

class Plugins {
public:
    static llvm::Module *load_llvm_ir(const QString &ir_file_name);

    static llvm::Module *load_plugin_core();

    static void load_package(const QString &package_name, const QString &package_path = nullptr);

    static void load_plugin_package();

    static void link_plugins(llvm::ExecutionEngine * engine);

    static llvm::Function *get_function(const QString &name);

    static llvm::Function *get_function(llvm::Module *module, const QString &name);

    static llvm::StructType *get_struct(const QString &name);
};

#endif //LLVM_RUNNER_PLUGINS_H
