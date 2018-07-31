package hobbyscript.LLVM.test;

import hobbyscript.ApplicationTest.CodeDialog;
import hobbyscript.Ast.AstLeaf;
import hobbyscript.Ast.AstList;
import hobbyscript.Ast.AstNode;
import hobbyscript.Ast.NullStmt;
import hobbyscript.Eval.Env.BasicEnvironment;
import hobbyscript.Eval.Env.EnvironmentCallBack;
import hobbyscript.Exception.ParseException;
import hobbyscript.Interpreter.ImportInterpreter;
import hobbyscript.LLVM.visitor.AstVisitor;
import hobbyscript.Lexer.HobbyLexer;
import hobbyscript.Literal.IdLiteral;
import hobbyscript.Literal.NumberLiteral;
import hobbyscript.Parser.ImportParser;
import hobbyscript.Token.HobbyToken;

import java.io.FileNotFoundException;
import java.io.FileReader;

public class TestLLVMVisitor implements AstVisitor<Object> {
    @Override
    public Object visitorAstNode(AstNode node) {
        System.out.println(node.toJson());
        return null;
    }

    @Override
    public Object visitorAstList(AstList list) {
        System.out.println(list.toJson());
        return null;
    }

    @Override
    public Object visitorAstLeaf(AstLeaf leaf) {
        System.out.println(leaf.toJson());
        return null;
    }

    @Override
    public Object visitorNumberLiteral(NumberLiteral numberLiteral) {
        return null;
    }

    @Override
    public Object visitorIdLiteral(IdLiteral idLiteral) {
        return null;
    }

    public static void main(String[] args) throws FileNotFoundException, ParseException {
        HobbyLexer lexer = new HobbyLexer(new CodeDialog());
        ImportParser parser = new ImportParser();
        EnvironmentCallBack env = new BasicEnvironment();
        TestLLVMVisitor visitor = new TestLLVMVisitor();

        while (lexer.peek(0) != HobbyToken.EOF) {
            AstNode node = parser.parse(lexer);
            if (node instanceof NullStmt) {
                continue;
            }

            node.accept(visitor);
        }
    }
}
