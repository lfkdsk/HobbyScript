package HobbyScript.Parser;

import HobbyScript.ApplicationTest.CodeDialog;
import HobbyScript.Ast.*;
import HobbyScript.Exception.ParseException;
import HobbyScript.Lexer.HobbyLexer;
import HobbyScript.Literal.BoolLiteral;
import HobbyScript.Literal.IdLiteral;
import HobbyScript.Literal.NumberLiteral;
import HobbyScript.Literal.StringLiteral;
import HobbyScript.Token.HobbyToken;
import HobbyScript.Utils.logger.Logger;

import java.util.HashSet;

/**
 * 构建语法树
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/12.
 */
public class ScriptParser {

    public static final String IF_TOKEN = "if";

    public static final String ELSE_TOKEN = "else";

    public static final String WHILE_TOKEN = "while";

    public static final String FUNCTION_TOKEN = "function";

    public static final String TRUE_TOKEN = "true",
            FALSE_TOKEN = "false";

    public static final String SEMICOLON_TOKEN = ";";

    public static final String LP_TOKEN = "(", RP_TOKEN = ")";

    public static final String LC_TOKEN = "{", RC_TOKEN = "}";

    public static final String LK_TOKEN = "\'";

    public static final String ASSIGN_TOKEN = "=";

    public static final String EQ_TOKEN = "==",
            UQ_TOKEN = "!=", GEQ_TOKEN = ">=", LE_TOKEN = "<=";

    public static final String LOGICAL_AND_TOKEN = "&&",
            LOGICAL_OR_TOKEN = "||", LOGICAL_F_TOKEN = "!";

    public static final String GT_TOKEN = "<", GE_TOKEN = ">";

    public static final String ADD = "+", SUB = "-",
            MUL = "*", DIV = "/", MOD = "%";

    public static final String COMMA = ",";

    public static final String FOR_TOKEN = "for";

    public static final String BREAK_TOKEN = "break";

    public static final String CLOSURE_TOKEN = "closure";

    public static final String CLASS_TOKEN = "class";

    public static final String EXTEND_TOKEN = "extend";

    public static final String DOT_TOKEN = ".",
            INITIAL = "Initial", THIS_POINT = "this",
            SUPER_TOKEN = "super";

    public static final String LM_TOKEN = "[", RM_TOKEN = "]";

    public static final String LS_TOKEN = "<", RS_TOKEN = ">";

    public static final String IMPORT_TOKEN = "import", NULL_TOKEN = "null";

    /**
     * 保留关键字
     */
    HashSet<String> reserved = new HashSet<>();

    ///////////////////////////////////////////////////////////////////////////
    // 书写 BNF 范式
    ///////////////////////////////////////////////////////////////////////////

    BnfParser.Operators operators = new BnfParser.Operators();

    BnfParser expr0 = BnfParser.rule();


    BnfParser number = BnfParser.rule().number(NumberLiteral.class);

    BnfParser id = BnfParser.rule().identifier(IdLiteral.class, reserved);

    BnfParser string = BnfParser.rule().string(StringLiteral.class);

    BnfParser bool = BnfParser.rule().bool(BoolLiteral.class);

    BnfParser Null = BnfParser.rule().Null(NumberLiteral.class);

    ///////////////////////////////////////////////////////////////////////////
    // primary = ( expr ) | number | id | string |bool | null
    ///////////////////////////////////////////////////////////////////////////

    BnfParser primary = BnfParser.rule(PrimaryExpr.class)
            .or(BnfParser.rule().sep(LP_TOKEN).ast(expr0).sep(RP_TOKEN),
                    number,
                    id,
                    string,
                    bool,
                    Null
            );

    ///////////////////////////////////////////////////////////////////////////
    // factor = primary | - primary
    ///////////////////////////////////////////////////////////////////////////

    BnfParser factor = BnfParser.rule()
            .or(BnfParser.rule(NegativeExpr.class).sep(SUB).ast(primary), primary);

    ///////////////////////////////////////////////////////////////////////////
    // expr = factor { OP factor }
    ///////////////////////////////////////////////////////////////////////////

    BnfParser expr = expr0.expression(BinaryExpr.class, factor, operators);

    BnfParser statement0 = BnfParser.rule();

    ///////////////////////////////////////////////////////////////////////////
    // ImportLib = import " "
    ///////////////////////////////////////////////////////////////////////////
    BnfParser importLib = BnfParser.rule(Import.class)
            .sep(IMPORT_TOKEN)
            .ast(string);

    ///////////////////////////////////////////////////////////////////////////
    // simple = expr ;
    ///////////////////////////////////////////////////////////////////////////
    BnfParser simple = BnfParser.rule().or(expr, importLib).sep(SEMICOLON_TOKEN);

    ///////////////////////////////////////////////////////////////////////////
    // block = { statement; * }
    ///////////////////////////////////////////////////////////////////////////

    BnfParser block = BnfParser.rule(BlockStmnt.class)
            .sep(LC_TOKEN).option(statement0)
            .repeat(BnfParser.rule().sep(SEMICOLON_TOKEN, HobbyToken.EOL)
                    .option(statement0))
            .sep(RC_TOKEN);

    ///////////////////////////////////////////////////////////////////////////
    // if ()
    ///////////////////////////////////////////////////////////////////////////
    BnfParser ifStatement =
            BnfParser.rule(IfStmnt.class).sep(IF_TOKEN).sep(LP_TOKEN)
                    .ast(expr).sep(RP_TOKEN).ast(block)
                    .option(BnfParser.rule().sep(ELSE_TOKEN).ast(block));

    ///////////////////////////////////////////////////////////////////////////
    // while ( condition ) {  }
    ///////////////////////////////////////////////////////////////////////////

    BnfParser whileStatement =
            BnfParser.rule(WhileStmt.class).sep(WHILE_TOKEN).sep(LP_TOKEN)
                    .ast(expr).sep(RP_TOKEN).ast(block);

    ///////////////////////////////////////////////////////////////////////////
    // option = expr, expr, expr
    ///////////////////////////////////////////////////////////////////////////
    BnfParser option = BnfParser.rule(OptionStmt.class).option(expr)
            .repeat(BnfParser.rule().sep(COMMA).option(expr));

    ///////////////////////////////////////////////////////////////////////////
    // for (initial ; condition ; step)
    ///////////////////////////////////////////////////////////////////////////
    BnfParser forStatement =
            BnfParser.rule(ForStmt.class).sep(FOR_TOKEN)
                    .sep(LP_TOKEN)
                    .or(option, BnfParser.rule(NullStmt.class)).sep(SEMICOLON_TOKEN)
                    .or(expr, BnfParser.rule(NullStmt.class)).sep(SEMICOLON_TOKEN)
                    .or(option, BnfParser.rule(NullStmt.class))
                    .sep(RP_TOKEN).ast(block);

    ///////////////////////////////////////////////////////////////////////////
    // break;
    ///////////////////////////////////////////////////////////////////////////

    BnfParser breakStatement = BnfParser.rule(BreakStmt.class)
            .sep(BREAK_TOKEN);

    ///////////////////////////////////////////////////////////////////////////
    // statement = if (expr) block else block | while (expr) block
    ///////////////////////////////////////////////////////////////////////////

    BnfParser statement = statement0
            .or(ifStatement, whileStatement, forStatement, breakStatement, simple);

    ///////////////////////////////////////////////////////////////////////////
    // program = statement | (; , end of line)
    ///////////////////////////////////////////////////////////////////////////

    BnfParser program = BnfParser.rule().or(statement,
            BnfParser.rule(NullStmt.class).sep(SEMICOLON_TOKEN, HobbyToken.EOL));

    ///////////////////////////////////////////////////////////////////////////
    // 构造添加
    ///////////////////////////////////////////////////////////////////////////

    public ScriptParser() {
        reserved.add(SEMICOLON_TOKEN);
        reserved.add(RC_TOKEN);
        reserved.add(IF_TOKEN);
        reserved.add(WHILE_TOKEN);
        reserved.add(FOR_TOKEN);
        reserved.add(RP_TOKEN);
        reserved.add(BREAK_TOKEN);
        reserved.add(ELSE_TOKEN);
        reserved.add(IMPORT_TOKEN);
        reserved.add(LOGICAL_AND_TOKEN);
        reserved.add(TRUE_TOKEN);
        reserved.add(FALSE_TOKEN);
//        reserved.add(LOGICAL_F_TOKEN);
        reserved.add(HobbyToken.EOL);

        operators.add(ASSIGN_TOKEN, 14, BnfParser.Operators.RIGHT);
//        operators.add(LOGICAL_F_TOKEN, 1, BnfParser.Operators.RIGHT);


        operators.add(EQ_TOKEN, 7, BnfParser.Operators.LEFT);
        operators.add(UQ_TOKEN, 7, BnfParser.Operators.LEFT);

        operators.add(LOGICAL_AND_TOKEN, 11, BnfParser.Operators.LEFT);
        operators.add(LOGICAL_OR_TOKEN, 12, BnfParser.Operators.LEFT);

        operators.add(GE_TOKEN, 6, BnfParser.Operators.LEFT);
        operators.add(LE_TOKEN, 6, BnfParser.Operators.LEFT);
        operators.add(GEQ_TOKEN, 6, BnfParser.Operators.LEFT);
        operators.add(GT_TOKEN, 6, BnfParser.Operators.LEFT);

        operators.add(ADD, 4, BnfParser.Operators.LEFT);
        operators.add(SUB, 4, BnfParser.Operators.LEFT);

        operators.add(MUL, 3, BnfParser.Operators.LEFT);
        operators.add(DIV, 3, BnfParser.Operators.LEFT);
        operators.add(MOD, 3, BnfParser.Operators.LEFT);
    }

    public AstNode parse(HobbyLexer lexer) throws ParseException {
        return program.parse(lexer);
    }

    public static void main(String[] args) throws ParseException {
        HobbyLexer lexer = new HobbyLexer(new CodeDialog());

        Logger.init("ScriptParser");

        ScriptParser parser = new ScriptParser();


        while (lexer.peek(0) != HobbyToken.EOF) {
            AstNode node = parser.parse(lexer);

//            if (!(node instanceof NullStmt)) {
//                PrintUtils.printAstTreeGraph(node);
//            }

            Logger.v(" => " + node.toString() + "  ");
        }
    }
}
