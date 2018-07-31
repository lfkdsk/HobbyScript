package hobbyscript.Ast;

import hobbyscript.Eval.Env.EnvironmentCallBack;
import hobbyscript.Eval.ScriptEval;
import hobbyscript.Token.HobbyToken;

import java.util.List;

/**
 * expr,expr,
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/25.
 */
public class OptionStmt extends AstList {
    public OptionStmt(List<AstNode> children) {
        super(children, HobbyToken.OPTION);
    }

    @Override
    public Object eval(EnvironmentCallBack env) {
        return ScriptEval.optionEval(env, this);
    }
}
