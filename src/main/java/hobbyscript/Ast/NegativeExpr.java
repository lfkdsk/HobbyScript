package hobbyscript.Ast;

import hobbyscript.Compile.CodeLine;
import hobbyscript.Eval.Env.Environment;
import hobbyscript.Eval.ScriptEval;
import hobbyscript.Token.HobbyToken;

import java.util.List;

/**
 * 正负
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/12.
 */
public class NegativeExpr extends AstList {
    public NegativeExpr(List<AstNode> children) {
        super(children, HobbyToken.NEGATIVE);
    }

    public AstNode operand() {
        return child(0);
    }

    public String toString() {
        return "-" + operand();
    }

    @Override
    public String compile(CodeLine line, int th, int nx) {
        return toString();
    }

    @Override
    public Object eval(Environment env) {
        return ScriptEval.negativeEval(env, this);
    }
}
