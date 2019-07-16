package hobbyscript.Eval;

import hobbyscript.ast.AstNode;
import hobbyscript.ast.Import;
import hobbyscript.ast.NullStmt;
import hobbyscript.Eval.Env.Environment;
import hobbyscript.Eval.Env.LocalEnv;
import hobbyscript.Eval.Env.LocalEnvironment;
import hobbyscript.Exception.HobbyException;
import hobbyscript.Exception.ParseException;
import hobbyscript.Lexer.HobbyLexer;
import hobbyscript.Native.NativeList;
import hobbyscript.Parser.ArrayParser;
import hobbyscript.Token.HobbyToken;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;

/**
 * Created by liufengkai on 16/7/26.
 */
public class ImportEval {

    public static void importEval(Environment env,
                                  Import importLib) {

        if (((LocalEnv) env).getParent() == null) {
            File file = new File(importLib.importLib().toString());
            if (file.exists()) {
                env.putAll(parseLib(file));
            } else {
                File libFile = new File("../HobbyScript/src/Library/" + importLib.importLib().toString());
                if (libFile.exists()) {
                    env.putAll(parseLib(libFile));
                    return;
                }
                throw new HobbyException("can not get the lib " + importLib.importLib().toString(), importLib);
            }
        } else {
            throw new HobbyException("please import lib at the start of file ", importLib);
        }

    }

    private static Environment parseLib(File file) {

        try {
            HobbyLexer lexer = new HobbyLexer(new FileReader(file));
            ArrayParser parser = new ArrayParser();
            Environment env = new NativeList().env(new LocalEnvironment());
            while (lexer.peek(0) != HobbyToken.EOF) {
                AstNode node = parser.parse(lexer);
                if (!(node instanceof NullStmt)) {
                    Object r = node.eval(env);
                }
            }
            return env;
        } catch (ParseException | FileNotFoundException e) {
            e.printStackTrace();
        }
        throw new HobbyException("parse lib file error");
    }
}
