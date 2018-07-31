package hobbyscript.LLVM.visitor;

import hobbyscript.Ast.AstLeaf;
import hobbyscript.Ast.AstList;
import hobbyscript.Ast.AstNode;

public interface AstVisitor {
    void visitorAstNode(AstNode node);
    void visitorAstList(AstList list);
    void visitorAstLeaf(AstLeaf leaf);
}
