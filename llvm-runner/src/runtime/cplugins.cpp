//
// Created by 刘丰恺 on 4/2/2020.
//

#include "cplugins.h"


llvm::Module *CPlugins::load_llvm_ir(const QString &ir_file_name) {
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
