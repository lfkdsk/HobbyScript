//
// Created by 刘丰恺 on 2018/8/3.
//

#ifndef LLVM_RUNNER_VISITOR_H
#define LLVM_RUNNER_VISITOR_H

template <class R, class I>
class Visitor {
public:
    virtual R visit_ast_node(I node);

    virtual R visit_ast_leaf(I node);

    virtual R visit_binary_expr(I node);

    virtual R visit_ast_list(I node);

    virtual R visit_number(I node);

    virtual R visit(I node);

    virtual R visit();
};

#endif //LLVM_RUNNER_VISITOR_H
