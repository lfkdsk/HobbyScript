//
// Created by 刘丰恺 on 21/1/2020.
//

#ifndef LLVM_RUNNER_LLVM_GEN_VISITOR_H
#define LLVM_RUNNER_LLVM_GEN_VISITOR_H

#include "visitor_base.h"
#include "common/gen_common.h"
#include "gen/llvm_generator.h"
#include "common/llvm_common.h"

/**
 * Convect CodeGen => LLVM Value.
 */
class LLVMCodeGenVisitor : public GenBaseVisitor {
public:
    explicit LLVMCodeGenVisitor(LLVMGenerator *generator) : llvm_gen(generator) {}

public:
    inline LLVMGenerator &generator() {
        return *llvm_gen;
    }

    void visit(TypeOnlyGen &gen) override;

    void visit(LetGen &gen) override;

    void visit(ValueGen &gen) override;

    void visit(CodeGen &gen) override;

    void visit(DefGen &gen) override;

private:
    LLVMGenerator *llvm_gen;
};


#endif //LLVM_RUNNER_LLVM_GEN_VISITOR_H
