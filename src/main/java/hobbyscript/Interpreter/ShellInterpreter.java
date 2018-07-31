package hobbyscript.Interpreter;

import hobbyscript.Ast.AstNode;
import hobbyscript.Ast.NullStmt;
import hobbyscript.Eval.Env.EnvironmentCallBack;
import hobbyscript.Eval.Env.LocalEnvironment;
import hobbyscript.Exception.ParseException;
import hobbyscript.Lexer.HobbyLexer;
import hobbyscript.Native.NativeList;
import hobbyscript.Parser.ArrayParser;
import hobbyscript.Parser.ScriptParser;
import hobbyscript.Token.HobbyToken;

import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 * Created by liufengkai on 2017/3/12.
 */
public class ShellInterpreter extends ImportInterpreter {
    public static final String ANSI_RESET = "\u001B[0m";
    public static final String ANSI_BLACK = "\u001B[30m";
    public static final String ANSI_RED = "\u001B[31m";
    public static final String ANSI_GREEN = "\u001B[32m";
    public static final String ANSI_YELLOW = "\u001B[33m";
    public static final String ANSI_BLUE = "\u001B[34m";
    public static final String ANSI_PURPLE = "\u001B[35m";
    public static final String ANSI_CYAN = "\u001B[36m";
    public static final String ANSI_WHITE = "\u001B[37m";

    public static final String ANSI_BLACK_BACKGROUND = "\u001B[40m";
    public static final String ANSI_RED_BACKGROUND = "\u001B[41m";
    public static final String ANSI_GREEN_BACKGROUND = "\u001B[42m";
    public static final String ANSI_YELLOW_BACKGROUND = "\u001B[43m";
    public static final String ANSI_BLUE_BACKGROUND = "\u001B[44m";
    public static final String ANSI_PURPLE_BACKGROUND = "\u001B[45m";
    public static final String ANSI_CYAN_BACKGROUND = "\u001B[46m";
    public static final String ANSI_WHITE_BACKGROUND = "\u001B[47m";

    public static final String HOBBY_SCRIPT = "HobbyScript > ";

    public static void main(String[] args) {
        parser();
    }

    static void parser() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        HobbyLexer lexer = new HobbyLexer(reader);

        ArrayParser parser = new ArrayParser();

        EnvironmentCallBack env = new NativeList().env(new LocalEnvironment());

        NativeList.print(cyanPrint(HOBBY_SCRIPT));

        Runtime.getRuntime().addShutdownHook(new Thread() {
            public void run() {
                NativeList.println("");
                NativeList.println(ANSI_PURPLE + "Have a nice Day~~" + ANSI_RESET);
                //some cleaning up code...
            }
        });

        catchException(lexer, parser, env);
    }

    static void catchException(HobbyLexer lexer, ScriptParser parser, EnvironmentCallBack env) {
        try {
            parserInner(lexer, parser, env);
        } catch (ParseException e) {
            catchException(lexer, parser, env);
        }
    }

    static void parserInner(HobbyLexer lexer, ScriptParser parser, EnvironmentCallBack env) throws ParseException {
        while (lexer.peek(0) != HobbyToken.EOF) {
            try {
                AstNode node = parser.parse(lexer);
                if (!(node instanceof NullStmt)) {
                    NativeList.println(cyanPrint(String.valueOf(node.getClass())));
                    Object r = node.eval(env);
                    NativeList.println("");
                    NativeList.print(cyanPrint(HOBBY_SCRIPT));
                }
            } catch (Exception e) {
                NativeList.println("");
                System.out.println(cyanPrint(HOBBY_SCRIPT + e.getMessage()));
                System.out.print(cyanPrint(HOBBY_SCRIPT));
            }
        }
    }

    private static String cyanPrint(String msg) {
        return ANSI_CYAN + msg + ANSI_RESET;
    }
}


