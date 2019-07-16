package hobbyscript.Interpreter;

import hobbyscript.Eval.Env.LocalEnv;
import hobbyscript.Eval.Env.LocalEnvironment;
import hobbyscript.Exception.ParseException;
import hobbyscript.Native.NativeList;
import hobbyscript.Parser.ClosureParser;

import java.io.FileNotFoundException;

/**
 * Created by liufengkai on 16/7/20.
 */
public class NativeInterpreter extends ClosureInterpreter{
    public static void main(String[] args) throws ParseException, FileNotFoundException {
        run("ClosureTest3", new ClosureParser(), new NativeList().env(new LocalEnvironment()));
    }
}
