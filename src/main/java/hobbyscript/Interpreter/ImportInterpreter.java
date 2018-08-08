package hobbyscript.Interpreter;

import hobbyscript.Eval.Env.LocalEnvironment;
import hobbyscript.Exception.ParseException;
import hobbyscript.Native.NativeList;
import hobbyscript.Parser.ImportParser;

import java.io.FileNotFoundException;

/**
 * Import 语句
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/26.
 */
public class ImportInterpreter extends ArrayInterpreter {

    public static void main(String[] args) throws FileNotFoundException, ParseException {
        run("", new ImportParser(), new NativeList().env(new LocalEnvironment()));
    }

}
