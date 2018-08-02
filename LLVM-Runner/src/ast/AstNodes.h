//
// Created by 刘丰恺 on 2018/8/2.
//

#ifndef LLVM_RUNNER_ASTNODES_H
#define LLVM_RUNNER_ASTNODES_H

#include "AstNode.h"
#include "NumberLiteral.h"

using AstNodePointer = std::shared_ptr<AstNode>;
using NumberLiteralPointer = std::shared_ptr<NumberLiteral>;
using AstLeafPointer = std::shared_ptr<AstLeaf>;

#endif //LLVM_RUNNER_ASTNODES_H
