package HobbyScript.Ast;

import HobbyScript.Eval.Env.EnvironmentCallBack;
import HobbyScript.Eval.FunctionEval;
import HobbyScript.StaticType.Ast.ParameterList;
import HobbyScript.Token.HobbyToken;

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

    public BlockStmnt body() {
        return (BlockStmnt) child(1);
    }

    @Override
    public String toString() {
        return "(closure " + parameters() + " " + body() + " )";
    }

    @Override
    public Object eval(EnvironmentCallBack env) {
        return FunctionEval.closureEval(this, env);
    }
}
