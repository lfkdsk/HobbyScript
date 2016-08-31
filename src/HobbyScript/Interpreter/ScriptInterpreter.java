package HobbyScript.Interpreter;

import HobbyScript.ApplicationTest.CodeDialog;
import HobbyScript.Ast.AstNode;
import HobbyScript.Ast.NullStmt;
import HobbyScript.Eval.Env.BasicEnvironment;
import HobbyScript.Eval.Env.EnvironmentCallBack;
import HobbyScript.Exception.ParseException;
import HobbyScript.Lexer.HobbyLexer;
import HobbyScript.Parser.ScriptParser;
import HobbyScript.Token.HobbyToken;
import HobbyScript.Utils.logger.Logger;

import java.io.FileNotFoundException;
import java.io.FileReader;

/**
 * Script解释器
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/15.
 */
public class ScriptInterpreter {

    static void run(String fileName, ScriptParser parser, EnvironmentCallBack env) throws ParseException, FileNotFoundException {

        HobbyLexer lexer;
        if (fileName.equals("")) {
            lexer = new HobbyLexer(new CodeDialog());
        } else {
            lexer = new HobbyLexer(new FileReader("Test/" + fileName));
        }

        Logger.init("Interpreter");

//        PrintUtils.startPrint();

        while (lexer.peek(0) != HobbyToken.EOF) {
            AstNode node = parser.parse(lexer);

            if (!(node instanceof NullStmt)) {
                Object r = node.eval(env);
//                PrintUtils.printAstTree(node);
                Logger.v(" => " + r);
//                PrintUtils.printAstTreeGraph(node);
            }
        }

//        PrintUtils.endPrint();
    }


    public static void main(String[] args) throws ParseException, FileNotFoundException {
        run("", new ScriptParser(), new BasicEnvironment());
    }
}
