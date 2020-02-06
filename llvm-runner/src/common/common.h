//
// Created by 刘丰恺 on 19/1/2020.
//

#ifndef LLVM_RUNNER_COMMON_H
#define LLVM_RUNNER_COMMON_H

#include <QString>
#include <QVector>
#include <QMap>
#include <QHash>
#include <QPair>
#include <utility>
#include <ostream>
#include <llvm/IR/Value.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/ExecutionEngine/JITEventListener.h>
#include <llvm/IR/AssemblyAnnotationWriter.h>
#include <llvm/Support/FormattedStream.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/ExecutionEngine/Interpreter.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/Support/CommandLine.h>
#include <iostream>
#include <spdlog/common.h>
#include <filesystem>
#include "config.h"

using RuntimeError = std::runtime_error;
const constexpr auto separator = std::__fs::filesystem::path::preferred_separator;

RuntimeError create_runtime_error(const QString &message);

QString point_to_str(void *p);

static QString get_plugin_dir() {
    return get_project_dir() + separator + "plugins";
}

#endif //LLVM_RUNNER_COMMON_H
