package HobbyScript.Interpreter;

import HobbyScript.Eval.Env.LocalEnvironment;
import HobbyScript.Exception.ParseException;
import HobbyScript.Native.NativeList;
import HobbyScript.Parser.ImportParser;

import java.io.FileNotFoundException;

/**
 * Import 语句
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/26.
 */
public class ImportInterpreter extends ArrayInterpreter {

    public static void main(String[] args) throws FileNotFoundException, ParseException {
        run("ClassThisPoint", new ImportParser(), new NativeList().env(new LocalEnvironment()));
    }

}
