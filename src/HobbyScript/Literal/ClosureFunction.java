package HobbyScript.Literal;

import HobbyScript.Ast.BlockStmnt;
import HobbyScript.StaticType.Ast.ParameterList;
import HobbyScript.Eval.Env.EnvironmentCallBack;

/**
 * 闭包函数
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/23.
 */
public class ClosureFunction extends Function {

    public ClosureFunction(ParameterList parameters,
                           BlockStmnt body,
                           EnvironmentCallBack env) {
        super(parameters, body, env);
    }

}
