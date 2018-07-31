package hobbyscript.Literal;

import hobbyscript.Ast.DefBlockStmnt;
import hobbyscript.Ast.ParameterList;
import hobbyscript.Eval.Env.EnvironmentCallBack;

/**
 * 类函数
 * 只有在处理作用域的时候有区别
 * @author liufengkai
 *         Created by liufengkai on 16/7/22.
 */
public class ClassFunction extends Function {

    public ClassFunction(ParameterList parameters,
                         DefBlockStmnt body,
                         EnvironmentCallBack env) {
        super(parameters, body, env);
    }
}
