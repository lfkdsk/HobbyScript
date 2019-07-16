package hobbyscript.LLVM.test;

import com.google.common.collect.Lists;
import hobbyscript.ApplicationTest.CodeDialog;
import hobbyscript.Ast.AstLeaf;
import hobbyscript.Ast.AstList;
import hobbyscript.Ast.AstNode;
import hobbyscript.Ast.NullStmt;
import hobbyscript.Eval.Env.BasicEnvironment;
import hobbyscript.Eval.Env.Environment;
import hobbyscript.Exception.ParseException;
import hobbyscript.LLVM.visitor.AstVisitor;
import hobbyscript.Lexer.HobbyLexer;
import hobbyscript.Literal.IdLiteral;
import hobbyscript.Literal.NumberLiteral;
import hobbyscript.Parser.ImportParser;
import hobbyscript.Token.HobbyToken;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.List;

public class TestLLVMVisitor implements AstVisitor<Object> {
    private static List<String> lines = Lists.newArrayList();

    @Override
    public Object visitorAstNode(AstNode node) {
        String result = node.toJson();
        System.out.println(result);
        return result;
    }

    @Override
    public Object visitorAstList(AstList list) {
        String result = list.toJson();
        System.out.println(result);
        return result;
    }

    @Override
    public Object visitorAstLeaf(AstLeaf leaf) {
        String result = leaf.toJson();
        System.out.println(result);
        return result;
    }

    @Override
    public Object visitorNumberLiteral(NumberLiteral numberLiteral) {
        return null;
    }

    @Override
    public Object visitorIdLiteral(IdLiteral idLiteral) {
        return null;
    }

    public static void main(String[] args) throws IOException, ParseException {
        HobbyLexer lexer = new HobbyLexer(new CodeDialog());
        ImportParser parser = new ImportParser();
        Environment env = new BasicEnvironment();
        TestLLVMVisitor visitor = new TestLLVMVisitor();


        while (lexer.peek(0) != HobbyToken.EOF) {
            AstNode node = parser.parse(lexer);
            if (node instanceof NullStmt) {
                continue;
            }

            lines.add(node.accept(visitor).toString());
        }

        Path file = Paths.get("./LLVM-Runner/result.ast");
        Files.write(file, lines, StandardCharsets.UTF_8,
                StandardOpenOption.APPEND, StandardOpenOption.CREATE);
    }
}
