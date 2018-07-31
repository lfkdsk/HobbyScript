package hobbyscript.Interpreter;

import hobbyscript.Eval.Env.LocalEnvironment;
import hobbyscript.Exception.ParseException;
import hobbyscript.Parser.FunctionParser;

import java.io.FileNotFoundException;

/**
 * function解释器
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/16.
 */
public class FunctionInterpreter extends ScriptInterpreter {
    public static void main(String[] args) throws ParseException, FileNotFoundException {
        run("",new FunctionParser(), new LocalEnvironment());
    }
}
