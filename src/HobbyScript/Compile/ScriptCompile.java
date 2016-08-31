package HobbyScript.Compile;

import HobbyScript.Ast.AstNode;
import HobbyScript.Ast.FuncStmt;
import HobbyScript.Ast.NullStmt;
import HobbyScript.Exception.ParseException;
import HobbyScript.Lexer.HobbyLexer;
import HobbyScript.Parser.ArrayParser;
import HobbyScript.Parser.ScriptParser;
import HobbyScript.Token.HobbyToken;
import HobbyScript.Utils.logger.Logger;

import java.io.FileNotFoundException;
import java.io.FileReader;

/**
 * Created by liufengkai on 16/8/7.
 */
public class ScriptCompile {


    public static void emitjumps(CodeLine line,
                                 String tests,
                                 int t, int f,
                                 int codeLine) {
        if (t != 0 && f != 0) {
            line.addCode("if " + tests + " goto L" + t, codeLine);
            line.addCode("goto L" + f);
        } else if (t != 0)
            line.addCode("if " + tests + " goto L" + t, codeLine);
        else if (f != 0)
            line.addCode("iffalse " + tests + " goto L" + f, codeLine);
    }


    private static void compile(String fileName) throws ParseException, FileNotFoundException {
        HobbyLexer lexer = new HobbyLexer(new FileReader("../hobby_script/midTest/" + fileName));

        Logger.init("ScriptParser");

        ScriptParser parser = new ArrayParser();

        CodeLine line = new CodeLine();

        int begin = line.newLine();
        int end = line.newLine();

        line.addSpecCode("start", begin);

        int saveEnd = end;
        while (lexer.peek(0) != HobbyToken.EOF) {

            AstNode node = parser.parse(lexer);

            if (!(node instanceof NullStmt)) {


                node.compile(line, begin, end);

                if (!(node instanceof FuncStmt)){
                    begin = line.newLine();
                    end = line.newLine();
                }
            }
//            Logger.v(" => " + node.toString() + "  ");
        }

        line.addSpecCode("end", saveEnd);
        line.printList();
    }

    public static void main(String[] args) throws ParseException, FileNotFoundException {
        compile("midTest2");
    }
}
