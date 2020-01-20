//
// Created by 刘丰恺 on 19/1/2020.
//

#ifndef LLVM_RUNNER_COMMON_H
#define LLVM_RUNNER_COMMON_H

#include <QString>
#include <QVector>
#include <utility>
#include <llvm/IR/Value.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/ExecutionEngine/JITEventListener.h>
#include <llvm/IR/AssemblyAnnotationWriter.h>
#include <llvm/Support/FormattedStream.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/IR/IRBuilder.h>

using RuntimeError = std::runtime_error;

RuntimeError createRuntimeError(const QString &message);

#endif //LLVM_RUNNER_COMMON_H
