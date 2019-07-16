package hobbyscript.Literal;

import hobbyscript.ast.DefBlockStmnt;
import hobbyscript.ast.ParameterList;
import hobbyscript.Eval.Env.Environment;
import hobbyscript.Eval.Env.LocalEnvironment;

/**
 * 函数定义
 * Created by liufengkai on 16/7/16.
 */
public class Function {
    protected ParameterList parameters;

    protected DefBlockStmnt body;

    protected Environment env;

    public Function(ParameterList parameters, DefBlockStmnt body, Environment env) {
        this.parameters = parameters;
        this.body = body;
        this.env = env;
    }

    public ParameterList parameters() {
        return parameters;
    }

    public DefBlockStmnt body() {
        return body;
    }


    public Environment getEnv() {
        return env;
    }

    public Environment makeNewEnv() {
        return new LocalEnvironment();
    }

    @Override
    public String toString() {
        return "< function : " + hashCode() + " >; ";
    }
}
