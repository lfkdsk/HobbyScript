package hobbyscript.Literal;

import hobbyscript.Ast.DefBlockStmnt;
import hobbyscript.Ast.ParameterList;
import hobbyscript.Eval.Env.EnvironmentCallBack;

/**
 * 闭包函数
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/23.
 */
public class ClosureFunction extends Function {

    public ClosureFunction(ParameterList parameters,
                           DefBlockStmnt body,
                           EnvironmentCallBack env) {
        super(parameters, body, env);
    }

}
