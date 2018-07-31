package hobbyscript.LLVM.visitor;

import hobbyscript.Ast.AstLeaf;
import hobbyscript.Ast.AstList;
import hobbyscript.Ast.AstNode;
import hobbyscript.Literal.IdLiteral;
import hobbyscript.Literal.NumberLiteral;

public interface AstVisitor<T> {
    default T visitorAstNode(AstNode node) {
        return null;
    }

    default T visitorAstList(AstList list) {
        return null;
    }

    default T visitorAstLeaf(AstLeaf leaf) {
        return null;
    }

    T visitorNumberLiteral(NumberLiteral numberLiteral);

    T visitorIdLiteral(IdLiteral idLiteral);
}
