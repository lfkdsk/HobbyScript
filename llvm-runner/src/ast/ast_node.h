//
// Created by 刘丰恺 on 16/1/2020.
//

#ifndef LLVM_RUNNER_AST_NODE_H
#define LLVM_RUNNER_AST_NODE_H

#include <string>
#include <utility>
#include "runtime/ast_context.h"
#include "gen/code_gen.h"
#include "common/common.h"
#include "visitor/visitor.h"
#include "common/ast_common.h"

extern int yylineno;

class AstNode : public AST_BASE(AstNode) {
public:
    AstNode(QString n = QString()) : name(std::move(n)) {
        this->line_num = yylineno;
        this->runtime_type = AstNodeTy;
    };

    virtual ~AstNode() {}

public:
    QString name;
    int line_num;
    AstRuntimeType runtime_type;
    const QString node_id = point_to_str(this);
    const std::string node_id_str = node_id.toUtf8().toStdString();

    inline void set_codegen_result(CodeGen *result) {
        this->code_gen_result = result;
    }

    inline CodeGen *codegen_result() {
        return code_gen_result;
    }

    std::string std_name() {
        return name.toUtf8().toStdString();
    };

protected:
    CodeGen *code_gen_result = nullptr;

};


#endif //LLVM_RUNNER_AST_NODE_H
