package hobbyscript.Compile;

import hobbyscript.Ast.AstNode;
import hobbyscript.Ast.FuncStmt;
import hobbyscript.Ast.NullStmt;
import hobbyscript.Exception.ParseException;
import hobbyscript.Lexer.HobbyLexer;
import hobbyscript.Parser.ArrayParser;
import hobbyscript.Parser.ScriptParser;
import hobbyscript.Token.HobbyToken;
import hobbyscript.Utils.logger.Logger;

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
        HobbyLexer lexer = new HobbyLexer(new FileReader("../HobbyScript/midTest/" + fileName));

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
