package HobbyScript.Literal;

import HobbyScript.Ast.BlockStmnt;
import HobbyScript.Ast.ParameterList;
import HobbyScript.Eval.Env.EnvironmentCallBack;
import HobbyScript.Eval.Env.LocalEnvironment;

/**
 * 函数定义
 * Created by liufengkai on 16/7/16.
 */
public class Function {
    protected ParameterList parameters;

    protected BlockStmnt body;

    protected EnvironmentCallBack env;

    public Function(ParameterList parameters, BlockStmnt body, EnvironmentCallBack env) {
        this.parameters = parameters;
        this.body = body;
        this.env = env;
    }

    public ParameterList parameters() {
        return parameters;
    }

    public BlockStmnt body() {
        return body;
    }


    public EnvironmentCallBack getEnv() {
        return env;
    }

    public EnvironmentCallBack makeNewEnv() {
        return new LocalEnvironment();
    }

    @Override
    public String toString() {
        return "< function : " + hashCode() + " >; ";
    }
}
