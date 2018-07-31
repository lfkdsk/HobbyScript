package HobbyScript.Interpreter;

import HobbyScript.Eval.Env.LocalEnvironment;
import HobbyScript.Exception.ParseException;
import HobbyScript.Native.NativeList;
import HobbyScript.Parser.ClosureParser;

import java.io.FileNotFoundException;

/**
 * Created by liufengkai on 16/7/20.
 */
public class NativeInterpreter extends ClosureInterpreter{
    public static void main(String[] args) throws ParseException, FileNotFoundException {
        run("ClosureTest3", new ClosureParser(), new NativeList().env(new LocalEnvironment()));
    }
}
