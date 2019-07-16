package hobbyscript.Literal;

import hobbyscript.ast.DefBlockStmnt;
import hobbyscript.ast.ParameterList;
import hobbyscript.Eval.Env.Environment;

/**
 * 闭包函数
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/23.
 */
public class ClosureFunction extends Function {

    public ClosureFunction(ParameterList parameters,
                           DefBlockStmnt body,
                           Environment env) {
        super(parameters, body, env);
    }

}
