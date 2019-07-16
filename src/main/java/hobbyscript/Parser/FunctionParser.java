package hobbyscript.Parser;

import hobbyscript.ApplicationTest.CodeDialog;
import hobbyscript.ast.*;
import hobbyscript.Exception.ParseException;
import hobbyscript.Lexer.HobbyLexer;
import hobbyscript.Token.HobbyToken;
import hobbyscript.Utils.logger.Logger;

/**
 * 修改文法增加函数调用
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/15.
 */
public class FunctionParser extends ScriptParser {

    ///////////////////////////////////////////////////////////////////////////
    // param = x1
    ///////////////////////////////////////////////////////////////////////////

    BnfParser param = BnfParser.rule().identifier(reserved);

    ///////////////////////////////////////////////////////////////////////////
    // params = x1, x2, x3, x4
    ///////////////////////////////////////////////////////////////////////////

    BnfParser params = BnfParser.rule(ParameterList.class)
            .ast(param).repeat(BnfParser.rule().sep(COMMA).ast(param));

    ///////////////////////////////////////////////////////////////////////////
    // paramList = ( params )
    ///////////////////////////////////////////////////////////////////////////
    BnfParser paramList = BnfParser.rule().sep(LP_TOKEN)
            .maybe(params).sep(RP_TOKEN);


    BnfParser defBlock = BnfParser.rule(DefBlockStmnt.class)
            .sep(LC_TOKEN).option(statement0)
            .repeat(BnfParser.rule().sep(SEMICOLON_TOKEN, HobbyToken.EOL)
                    .option(statement0))
            .sep(RC_TOKEN);

    ///////////////////////////////////////////////////////////////////////////
    // def = function xxx paramList { }
    ///////////////////////////////////////////////////////////////////////////
    BnfParser def = BnfParser.rule(FuncStmt.class)
            .sep(FUNCTION_TOKEN).identifier(reserved)
            .ast(paramList).ast(defBlock);


    ///////////////////////////////////////////////////////////////////////////
    // args = expr, expr, expr 这属于调用参数
    ///////////////////////////////////////////////////////////////////////////
    BnfParser args = BnfParser.rule(Arguments.class)
            .ast(expr).repeat(BnfParser.rule().sep(COMMA).ast(expr));

    ///////////////////////////////////////////////////////////////////////////
    // postfix = ( args | null )
    ///////////////////////////////////////////////////////////////////////////
    BnfParser postfix = BnfParser.rule().sep(LP_TOKEN)
            .maybe(args).sep(RP_TOKEN);


    public FunctionParser() {
        reserved.add(FUNCTION_TOKEN);

        // 更换 simple 语句
        // simple = expr ; | expr args ;
        simple = BnfParser.rule(PrimaryExpr.class).ast(expr)
                .option(args).sep(SEMICOLON_TOKEN);

        // primary { postfix } 函数调用后缀
        primary.repeat(postfix);

        // program 插入函数定义选项
        program.insertChoice(def);
    }


    public static void main(String[] args) throws ParseException {
        HobbyLexer lexer = new HobbyLexer(new CodeDialog());

        Logger.init("FunctionParser");

        FunctionParser parser = new FunctionParser();


        while (lexer.peek(0) != HobbyToken.EOF) {
            AstNode node = parser.parse(lexer);

//            if (!(node instanceof NullStmt)){
//                PrintUtils.printAstTreeGraph(node);
//            }

            Logger.v(" => " + node.toString() + "  ");
        }
    }
}
