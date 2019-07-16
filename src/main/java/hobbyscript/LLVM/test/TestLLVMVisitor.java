package hobbyscript.LLVM.test;

import hobbyscript.ApplicationTest.CodeDialog;
import hobbyscript.Eval.Env.BasicEnvironment;
import hobbyscript.Eval.Env.Environment;
import hobbyscript.Exception.ParseException;
import hobbyscript.LLVM.generator.LLVMVisitor;
import hobbyscript.LLVM.visitor.AstVisitor;
import hobbyscript.Lexer.HobbyLexer;
import hobbyscript.Literal.NumberLiteral;
import hobbyscript.Parser.ImportParser;
import hobbyscript.Token.HobbyToken;
import hobbyscript.Utils.logger.Logger;
import hobbyscript.ast.AstLeaf;
import hobbyscript.ast.AstList;
import hobbyscript.ast.AstNode;
import hobbyscript.ast.NullStmt;

import java.io.FileReader;
import java.io.IOException;

public class TestLLVMVisitor implements AstVisitor {

    private AstVisitor wrapper;

    public TestLLVMVisitor(AstVisitor wrapper) {
        this.wrapper = wrapper;
    }

    @Override
    public Object visitorAstNode(AstNode node) {
        Object result = wrapper.visitorAstNode(node);
        System.out.println(result);
        return result;
    }

    @Override
    public Object visitorAstList(AstList list) {
        Object result = wrapper.visitorAstList(list);
        System.out.println(result);
        return result;
    }

    @Override
    public Object visitorAstLeaf(AstLeaf leaf) {
        Object result = wrapper.visitorAstLeaf(leaf);
        System.out.println(result);
        return result;
    }

    @Override
    public Object visitorNumberLiteral(NumberLiteral literal) {
        Logger.d(literal.toJson());
        return wrapper.visitorNumberLiteral(literal);
    }


    public static void main(String[] args) throws IOException, ParseException {
        HobbyLexer lexer = new HobbyLexer(new FileReader("test/"));
        ImportParser parser = new ImportParser();
        Environment env = new BasicEnvironment();
        TestLLVMVisitor visitor = new TestLLVMVisitor(new LLVMVisitor());

        while (lexer.peek(0) != HobbyToken.EOF) {
            AstNode node = parser.parse(lexer);
            if (node instanceof NullStmt) {
                continue;
            }

            node.accept(visitor);
        }
    }
}
