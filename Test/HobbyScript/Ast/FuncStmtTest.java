package HobbyScript.Ast;

import HobbyScript.Eval.Env.EnvironmentCallBack;
import HobbyScript.Eval.Env.LocalEnvironment;
import HobbyScript.Exception.ParseException;
import HobbyScript.Lexer.HobbyLexer;
import HobbyScript.Parser.ClassParser;
import HobbyScript.Parser.ImportParser;
import HobbyScript.Token.HobbyToken;
import org.junit.jupiter.api.Test;

import java.io.StringReader;

class FuncStmtTest {

    @Test
    void testCompute() throws ParseException {
        HobbyLexer lexer = new HobbyLexer(new StringReader("class lfkdsk {\n" +
                "    Ss = 100;\n" +
                "\n" +
                "    function Initial(x){\n" +
                "        this.Ss = x;\n" +
                "    }\n" +
                "\n" +
                "    Ssdut = closure(){\n" +
                "        this.Ss = 1000;\n" +
                "    };\n" +
                "}\n" +
                "\n" +
                "lfk = \"\";\n" +
                "lfi = lfkdsk.Initial(200);\n" +
                "\n" +
                "lfi.Ssdut();\n" +
                "\n" +
                "\n" +
                "\n" +
                "logInfo(lfi.Ss + lfk);"));
        ImportParser parser = new ImportParser();
        EnvironmentCallBack env = new LocalEnvironment();
        AstNode node = null;
        while (lexer.peek(0) != HobbyToken.EOF) {
            node = parser.parse(lexer);
        }

        ClassStmt stmt = (ClassStmt) getClassNode(node);
    }

    private AstNode getClassNode(AstNode node) {
        for (AstNode astNode : node) {
            if (astNode instanceof ClassStmt) {
                return astNode;
            }

            AstNode child = getClassNode(node);

            if (child != null) {
                return child;
            }
        }

        return null;
    }
}