package HobbyScript.Ast;

import HobbyScript.Compile.CodeLine;
import HobbyScript.Eval.Env.EnvironmentCallBack;
import HobbyScript.Eval.ScriptEval;
import HobbyScript.StaticType.Check.TypedCheck;
import HobbyScript.StaticType.Exception.TypeException;
import HobbyScript.StaticType.Literal.Type;
import HobbyScript.Token.HobbyToken;

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
    public Type check(EnvironmentCallBack env) throws TypeException {
        return TypedCheck.negativeExprCheck(env, this);
    }

    @Override
    public Object eval(EnvironmentCallBack env) {
        return ScriptEval.negativeEval(env, this);
    }
}
