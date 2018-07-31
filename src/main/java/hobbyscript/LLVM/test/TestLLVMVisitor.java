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
import hobbyscript.Parser.ImportParser;
import hobbyscript.Token.HobbyToken;

import java.io.FileNotFoundException;
import java.io.FileReader;

public class TestLLVMVisitor implements AstVisitor {
    @Override
    public void visitorAstNode(AstNode node) {
        System.out.println(node.toString());
    }

    @Override
    public void visitorAstList(AstList list) {
        System.out.println(list.toString());
    }

    @Override
    public void visitorAstLeaf(AstLeaf leaf) {
        System.out.println(leaf.toString());
    }

    public static void main(String[] args) throws FileNotFoundException, ParseException {
        HobbyLexer lexer = new HobbyLexer(new CodeDialog());
        ImportParser parser = new ImportParser();
        EnvironmentCallBack env = new BasicEnvironment();
        TestLLVMVisitor visitor = new TestLLVMVisitor();

        while (lexer.peek(0) != HobbyToken.EOF) {
            AstNode node = parser.parse(lexer);
            node.accept(visitor);
        }
    }
}
