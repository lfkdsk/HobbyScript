package HobbyScript.Ast;

import HobbyScript.Eval.Env.EnvironmentCallBack;
import HobbyScript.Eval.ScriptEval;
import HobbyScript.Token.HobbyToken;

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
    public Object eval(EnvironmentCallBack env) {
        return ScriptEval.negativeBoolEval(env, this);
    }
}
