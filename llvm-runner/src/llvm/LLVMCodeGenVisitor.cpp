//
// Created by 刘丰恺 on 2018/8/3.
//

#include "LLVMCodeGenVisitor.h"

LLVMCodeGenVisitor::LLVMCodeGenVisitor(const pointer<ast_node> &root_node) : root_node(root_node),
                                                                             builder(the_context) {
    the_module = llvm::make_unique<Module>("my cool jit", the_context);
}

pointer<ast_node> LLVMCodeGenVisitor::get_root_node() {
    return this->root_node;
}

value_pointer LLVMCodeGenVisitor::visit_ast_node(pointer<ast_node> node) {

}

value_pointer LLVMCodeGenVisitor::visit_ast_leaf(pointer<ast_node> node) {

}

value_pointer LLVMCodeGenVisitor::visit_binary_expr(pointer<ast_node> node) {
    auto binary_expr = Cast<ast_binary_expr, ast_node>(node);
    auto left = visit(binary_expr->get_left_node());
    auto right = visit(binary_expr->get_right_node());
    auto op = Cast<ast_leaf, ast_node>(binary_expr->get_mid_op());
    const char *op_text = op->get_text().c_str();

    if (!left || !right) {
        return nullptr;
    }

    switch (*op_text) {
        case '+': {
            return builder.CreateFAdd(left, right, "addtmp");
        }

        case '-': {
            return builder.CreateFSub(left, right, "subtmp");
        }

        case '*': {
            return builder.CreateFMul(left, right, "multmp");
        }

        case '<': {
            left = builder.CreateFCmpULT(left, right, "cmptmp");
            // Convert bool 0/1 to double 0.0 or 1.0
            return builder.CreateUIToFP(left, Type::getDoubleTy(the_context), "booltmp");
        }

        default: {
            auto err_logger = spdlog::stderr_color_mt("stderr");
            err_logger->error("invalid binary operator");
            return nullptr;
        }
    }
}

value_pointer LLVMCodeGenVisitor::visit_ast_list(pointer<ast_node> node) {
}

value_pointer LLVMCodeGenVisitor::visit_number(pointer<ast_node> node) {

}

value_pointer LLVMCodeGenVisitor::visit(pointer<ast_node> node) {
    value_pointer result = nullptr;
    switch (node->get_tag()) {
        case BINARY_EXPR: {
            result = visit_binary_expr(node);
            break;
        }

        case NUMBER_LITERAL: {
            result = visit_number(node);
            break;
        }

        case AST_LEAF: {
            result = visit_ast_leaf(node);
            break;
        }

        case AST_LIST: {
            result = visit_ast_list(node);
            break;
        }

        default: {
            break;
        }
    }

    return result;
}

value_pointer LLVMCodeGenVisitor::visit() {
    return visit(root_node);
}

LLVMCodeGenVisitor::~LLVMCodeGenVisitor() {

}

value_pointer LLVMCodeGenVisitor::visit_fun_stmt(pointer<ast_node> node) {
    return nullptr;
}

value_pointer LLVMCodeGenVisitor::visit_def_block(pointer<ast_node> node) {
    return nullptr;
}

value_pointer LLVMCodeGenVisitor::visit_string(pointer<ast_node> node) {
    return nullptr;
}
