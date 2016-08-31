package HobbyScript.Literal;

import HobbyScript.Ast.BlockStmnt;
import HobbyScript.Ast.ParameterList;
import HobbyScript.Eval.Env.EnvironmentCallBack;

/**
 * 类函数
 * 只有在处理作用域的时候有区别
 * @author liufengkai
 *         Created by liufengkai on 16/7/22.
 */
public class ClassFunction extends Function {

    public ClassFunction(ParameterList parameters,
                         BlockStmnt body,
                         EnvironmentCallBack env) {
        super(parameters, body, env);
    }
}
