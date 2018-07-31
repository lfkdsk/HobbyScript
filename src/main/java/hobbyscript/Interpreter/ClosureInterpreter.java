package hobbyscript.Interpreter;

import hobbyscript.Eval.Env.LocalEnvironment;
import hobbyscript.Exception.ParseException;
import hobbyscript.Parser.ClosureParser;

import java.io.FileNotFoundException;

/**
 * 闭包测试
 * Created by liufengkai on 16/7/17.
 */
public class ClosureInterpreter extends FunctionInterpreter {
    public static void main(String[] args) throws ParseException, FileNotFoundException {
        run("ClosureTest2", new ClosureParser(), new LocalEnvironment());
    }
}
