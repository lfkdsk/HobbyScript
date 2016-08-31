package HobbyScript.Parser;

import HobbyScript.ApplicationTest.CodeDialog;
import HobbyScript.Ast.AstNode;
import HobbyScript.Ast.Closure;
import HobbyScript.Exception.ParseException;
import HobbyScript.Lexer.HobbyLexer;
import HobbyScript.Token.HobbyToken;
import HobbyScript.Utils.logger.Logger;

/**
 * 加入闭包的Parser
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/17.
 */
public class ClosureParser extends FunctionParser {

    public ClosureParser() {
        reserved.add(CLOSURE_TOKEN);

        primary.insertChoice(BnfParser.rule(Closure.class)
                .sep(CLOSURE_TOKEN).ast(paramList).ast(block));
    }

    public static void main(String[] args) throws ParseException {
        HobbyLexer lexer = new HobbyLexer(new CodeDialog());

        Logger.init("ClosureParser");

        ClosureParser parser = new ClosureParser();

        while (lexer.peek(0) != HobbyToken.EOF) {
            AstNode node = parser.parse(lexer);

//            if (!(node instanceof NullStmt)){
//                PrintUtils.printAstTreeGraph(node);
//            }

            Logger.v(" => " + node.toString() + "  ");
        }
    }
}
