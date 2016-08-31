package HobbyScript.Interpreter;

import HobbyScript.Eval.Env.LocalEnvironment;
import HobbyScript.Exception.ParseException;
import HobbyScript.Native.NativeList;
import HobbyScript.Parser.ArrayParser;

import java.io.FileNotFoundException;

/**
 * 支持数组
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/23.
 */
public class ArrayInterpreter extends ClassInterpreter {
    public static void main(String[] args) throws FileNotFoundException, ParseException {
        run("", new ArrayParser(), new NativeList().env(new LocalEnvironment()));
    }
}
