//
// Created by 刘丰恺 on 4/2/2020.
//

#include "plugins.h"


llvm::Module *Plugins::load_llvm_ir(const QString &ir_file_name) {
    auto iter = loaded_modules.find(ir_file_name);
    if (iter != loaded_modules.end()) {
        return iter.value();
    }

    console->info(QString("try to load ir file" + ir_file_name).toUtf8().toStdString());
    llvm::SMDiagnostic error;

    auto load_module = parseIRFile(llvm::StringRef(ir_file_name.toStdString()), error, llvm_global_context);
    if (!load_module) {
        console->error(QString("cannot load ir file " + ir_file_name).toUtf8().toStdString());
        return nullptr;
    }

    for (auto &struct_iter : load_module->getIdentifiedStructTypes()) {
        auto name = QString(struct_iter->getStructName().str().c_str());
        console->debug(QString("load struct " + name + " in ir file ").toUtf8().toStdString());
        loaded_structs[name] = struct_iter;
    }

    loaded_modules.insert(ir_file_name, load_module.get());
    return load_module.get();
}

llvm::Module *Plugins::load_plugin_core() {
    return Plugins::load_llvm_ir(get_plugin_dir() + separator + "plugin_include.ll");
}

llvm::Function *Plugins::get_function(llvm::Module *module, const QString &name) {
    auto *f = module->getFunction(name.toStdString());
    if (f) {
        return f;
    }

    for (auto &iter : loaded_modules) {
        auto func = iter->getFunction(name.toStdString());
        if (func) {
            return llvm::Function::Create(
                    func->getFunctionType(),
                    llvm::Function::ExternalLinkage, func->getName(),
                    llvm_module.get()
            );
        }
    }
    return nullptr;
}

llvm::Function *Plugins::get_function(const QString &name) {
    return Plugins::get_function(llvm_module.get(), name);
}
