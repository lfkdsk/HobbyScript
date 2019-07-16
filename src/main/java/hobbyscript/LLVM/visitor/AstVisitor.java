package hobbyscript.LLVM.visitor;

import hobbyscript.ast.AstLeaf;
import hobbyscript.ast.AstList;
import hobbyscript.ast.AstNode;
import hobbyscript.Literal.NumberLiteral;

public interface AstVisitor {
    default Object visitorAstNode(AstNode node) {
        return null;
    }

    default Object visitorAstList(AstList list) {
        return null;
    }

    default Object visitorAstLeaf(AstLeaf leaf) {
        return null;
    }

    Object visitorNumberLiteral(NumberLiteral literal);
}
