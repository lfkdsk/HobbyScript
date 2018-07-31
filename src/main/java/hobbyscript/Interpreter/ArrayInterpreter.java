package hobbyscript.Interpreter;

import hobbyscript.Eval.Env.LocalEnvironment;
import hobbyscript.Exception.ParseException;
import hobbyscript.Native.NativeList;
import hobbyscript.Parser.ArrayParser;

import java.io.FileNotFoundException;

/**
 * 支持数组
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/23.
 */
public class ArrayInterpreter extends ClassInterpreter {
    public static void main(String[] args) throws FileNotFoundException, ParseException {
        run("ArrayTest1", new ArrayParser(), new NativeList().env(new LocalEnvironment()));
    }
}
