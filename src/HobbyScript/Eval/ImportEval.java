package HobbyScript.Eval;

import HobbyScript.Ast.AstNode;
import HobbyScript.Ast.Import;
import HobbyScript.Ast.NullStmt;
import HobbyScript.Eval.Env.EnvironmentCallBack;
import HobbyScript.Eval.Env.LocalEnvironment;
import HobbyScript.Exception.HobbyException;
import HobbyScript.Exception.ParseException;
import HobbyScript.Lexer.HobbyLexer;
import HobbyScript.Native.NativeList;
import HobbyScript.Parser.ArrayParser;
import HobbyScript.Token.HobbyToken;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;

/**
 * Created by liufengkai on 16/7/26.
 */
public class ImportEval {

    public static void importEval(EnvironmentCallBack env,
                                  Import importLib) {

        if (((LocalEnvironment) env).getParent() == null) {
            File file = new File(importLib.importLib().toString());
            if (file.exists()) {
                env.putAll(parseLib(file));
            } else {
                File libFile = new File("../hobby_script/src/Library/" + importLib.importLib().toString());
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

    private static EnvironmentCallBack parseLib(File file) {

        try {
            HobbyLexer lexer = new HobbyLexer(new FileReader(file));
            ArrayParser parser = new ArrayParser();
            EnvironmentCallBack env = new NativeList().env(new LocalEnvironment());
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
