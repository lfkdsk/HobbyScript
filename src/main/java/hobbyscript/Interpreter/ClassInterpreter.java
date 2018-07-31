package hobbyscript.Interpreter;

import hobbyscript.Eval.Env.LocalEnvironment;
import hobbyscript.Exception.ParseException;
import hobbyscript.Native.NativeList;
import hobbyscript.Parser.ClassParser;

import java.io.FileNotFoundException;

/**
 * Class类运行
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/21.
 */
public class ClassInterpreter extends NativeInterpreter {
    public static void main(String[] args) throws FileNotFoundException, ParseException {
        run("LinkedTest", new ClassParser(), new NativeList().env(new LocalEnvironment()));
    }
}
