package hobbyscript.ast;

import hobbyscript.Eval.Env.Environment;
import hobbyscript.Eval.FunctionEval;
import hobbyscript.Token.HobbyToken;

import java.util.List;

/**
 * 闭包
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/17.
 */
public class Closure extends AstList {

    public Closure(List<AstNode> children) {
        super(children, HobbyToken.CLOSURE);
    }

    public ParameterList parameters() {
        return (ParameterList) child(0);
    }

    public DefBlockStmnt body() {
        return (DefBlockStmnt) child(1);
    }

    @Override
    public String toString() {
        return "(closure " + parameters() + " " + body() + " )";
    }

    @Override
    public Object eval(Environment env) {
        return FunctionEval.closureEval(this, env);
    }
}
