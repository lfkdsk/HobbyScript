package hobbyscript.Ast;

import hobbyscript.Eval.Env.Environment;
import hobbyscript.Eval.ScriptEval;
import hobbyscript.Token.HobbyToken;

import java.util.List;

/**
 * !
 * Created by liufengkai on 2017/3/12.
 */
public class NegativeBoolExpr extends AstList {

    public NegativeBoolExpr(List<AstNode> children) {
        super(children, HobbyToken.NEGATIVEBOOL);
    }

    public AstNode operand() {
        return child(0);
    }

    @Override
    public String toString() {
        return "!" + operand();
    }

    @Override
    public Object eval(Environment env) {
        return ScriptEval.negativeBoolEval(env, this);
    }
}
