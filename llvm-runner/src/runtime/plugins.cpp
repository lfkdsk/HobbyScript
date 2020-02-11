//
// Created by 刘丰恺 on 4/2/2020.
//

#include "plugins.h"


llvm::Module *Plugins::load_llvm_ir(const QString &ir_file_name) {
    auto iter = loaded_modules.find(ir_file_name);
    if (iter != loaded_modules.end()) {
        return iter->second.get();
    }

    console->info(QString("try to load ir file" + ir_file_name).toUtf8().toStdString());
    llvm::SMDiagnostic error;

    auto load_module = parseIRFile(llvm::StringRef(ir_file_name.toStdString()), error, llvm_global_context);
    if (!load_module) {
        console->error(QString("cannot load ir file " + ir_file_name).toUtf8().toStdString());
        return nullptr;
    }

//    for (auto &i : load_module->getFunctionList()) {
//        std::clog << "\tLoad function: " << i.getName().str() << " in " << ir_file_name.toStdString() << std::endl;
//    }

    for (auto &struct_iter : load_module->getIdentifiedStructTypes()) {
        auto name = QString(struct_iter->getStructName().str().c_str());
        console->debug(QString("load struct " + name + " in ir file ").toUtf8().toStdString());
        loaded_structs[name] = struct_iter;
    }

    loaded_modules.insert(std::make_pair(ir_file_name, std::move(load_module)));
    return load_module.get();
}

llvm::Module *Plugins::load_plugin_core() {
    return Plugins::load_llvm_ir(get_plugin_dir() + separator + "plugin_core.ll");
}

llvm::Function *Plugins::get_function(llvm::Module *module, const QString &name) {
    auto *f = module->getFunction(name.toStdString());
    if (f) {
        return f;
    }

    for (auto &iter : loaded_modules) {
        auto func = iter.second->getFunction(name.toStdString());
        if (func) {
            return func;
        }
    }
    return nullptr;
}

llvm::Function *Plugins::get_function(const QString &name) {
    return Plugins::get_function(llvm_module.get(), name);
}

void Plugins::load_package(const QString &package_name, const QString &package_path) {
    if (global_packages.contains(package_name)) {
        return;
    }

    auto name = QString(package_name).replace('.', separator);
    for (auto &fe : std::__fs::filesystem::directory_iterator((package_path + separator + name).toStdString())) {
        const auto &file_path = fe.path();
        auto file_name = file_path.filename();
        auto file_ext = file_path.extension().string();

        if (file_ext == ".ll") {
            load_llvm_ir(QString(file_path.c_str()));
        }
    }
}

void Plugins::load_plugin_package() {
    load_package("plugins", get_project_dir());
}

void Plugins::link_plugins(llvm::ExecutionEngine *engine) {
    for (auto &i : loaded_modules) {
        auto &v = i.second;
//        std::clog << "Load module:" << v->getName().str() << std::endl;
        engine->addModule(std::move(v));
    }
}

llvm::StructType *Plugins::get_struct(const QString &name) {
    return loaded_structs["struct." + name];
}
