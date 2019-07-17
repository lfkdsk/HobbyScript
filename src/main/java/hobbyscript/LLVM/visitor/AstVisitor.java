package hobbyscript.LLVM.visitor;

import hobbyscript.LLVM.env.LLVMEnv;
import hobbyscript.Literal.BoolLiteral;
import hobbyscript.Literal.IDLiteral;
import hobbyscript.Literal.StringLiteral;
import hobbyscript.Utils.logger.Logger;
import hobbyscript.ast.*;
import hobbyscript.Literal.NumberLiteral;

public interface AstVisitor {
    default Object visitorAstNode(AstNode node, LLVMEnv env) {
        return null;
    }

    default Object visitorAstList(AstList list, LLVMEnv env) {
        return null;
    }

    default Object visitorAstLeaf(AstLeaf leaf, LLVMEnv env) {
        return null;
    }

    Object visitorNumberLiteral(NumberLiteral literal, LLVMEnv env);

    Object visitorStringLiteral(StringLiteral literal, LLVMEnv env);

    Object visitorIDLiteral(IDLiteral literal, LLVMEnv env);

    Object visitorBoolLiteral(BoolLiteral literal, LLVMEnv env);

    Object visitorNegativeExpr(NegativeExpr expr, LLVMEnv env);

    Object visitorNegativeBoolExpr(NegativeBoolExpr expr, LLVMEnv env);

    Object visitorBinaryExpr(BinaryExpr expr, LLVMEnv env);
}
