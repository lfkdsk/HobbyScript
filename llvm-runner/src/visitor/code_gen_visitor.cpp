//
// Created by 刘丰恺 on 19/1/2020.
//

#include "code_gen_visitor.h"

CodeGenVisitor::CodeGenVisitor(AstContext *context) : context(context) {}

CodeGenVisitor::CodeGenVisitor(CodeGenVisitor *parent) : parent_visitor(parent),
                                                         context(new AstContext(parent->context)) {}

void CodeGenVisitor::visit(AstNode &node) {
    set_codegen_result(node, new TypeOnlyGen(nullptr));
}

void CodeGenVisitor::visit(AstValue &node) {
    set_codegen_result(node, node.value ? node.codegen_result() : nullptr);
}

void CodeGenVisitor::visit(AstStringLiteral &node) {
    set_codegen_result(node, new StringLiteGen(context->context(), node.name));
}

void CodeGenVisitor::visit(AstIntegerConstant &node) {
    auto &that = node;
    auto &_llvm_context = context->context();
    auto type = llvm::IntegerType::get(_llvm_context, that._bits);
    auto *value = llvm::ConstantInt::get(type, that._value);
    set_codegen_result(node, new ValueGen(value));
}

void CodeGenVisitor::visit(AstBoolConstant &node) {

}

void CodeGenVisitor::visit(AstFloatConstant &node) {

}

void CodeGenVisitor::visit(AstLet &node) {
    if (!context) {
        return;
    }

    auto *value = context->find_symbol_value(node.name);
    if (!value) {
        throw create_runtime_error("could not find var: " + node.name);
    }

    if (!node.var_expr) {
        throw create_runtime_error("could not create var, because node's right expr is null.");
    }

    // code gen for right expr.
    auto *right = node.var_expr;
    this->visit(*right);
    auto *right_expr_gen = right->codegen_result();

    if (!right_expr_gen) {
        throw create_runtime_error("could not eval right expr " + node.name + " expr: ");
    }

    // trans right expr type to left type.
    if (!value->type) {
        value->type = right_expr_gen->type;
    }

    auto *let = context->find_symbol_value(node.name, true);
    // TODO: cal escape value.
    set_codegen_result(node, new LetGen(let, right_expr_gen));
}

void CodeGenVisitor::visit(AstList &node) {

}

void CodeGenVisitor::visit(AstPackage &node) {

}

void CodeGenVisitor::visit(AstDef &node) {
//    CodeGen * AstDef::makeGen(AstContext * parent)
//    {
//        AstType* p = AutoType::isAuto(type) ? nullptr : type;
//
//        if (vars.size() == 1) {
//            auto x=vars.at(0);
//            auto gen= makeDefGen(parent, p, x.first, x.second);
//            if (!gen)
//                throw std::runtime_error("Can't def " + x.first);
//            parent->setSymbolValue(x.first, gen );
//            return gen;
//        }
//
//        auto list = new GenList();
//        for (auto &i : vars) {
//            auto gen = makeDefGen(parent, p, i.first, i.second);
//            list->generates.push_back(gen);
//            parent->setSymbolValue(i.first, gen);
//        }
//
//        return list;
//    }
    auto *type = AutoType::is_auto_type(node.type) ? nullptr : node.type;
    auto vars = node.vars;
    if (vars.length() == 1) {
        auto pair = vars.at(0);
        auto code_gen = node.make_def_gen(context, type, pair.first, pair.second);
        if (!code_gen) {
            throw create_runtime_error("couldn't def " + pair.first);
        }

        context->set_symbol_value(pair.first, code_gen);
        set_codegen_result(node, code_gen);
    }

//    auto list = new
}

void CodeGenVisitor::visit(AstDefClass &node) {

}
