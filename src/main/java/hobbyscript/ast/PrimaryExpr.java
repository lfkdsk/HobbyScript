package hobbyscript.ast;

import hobbyscript.Compile.CodeLine;
import hobbyscript.Eval.Env.Environment;
import hobbyscript.Eval.FunctionEval;
import hobbyscript.Token.HobbyToken;

import java.util.List;

/**
 * Primary
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/12.
 */
public class PrimaryExpr extends AstList {

    public PrimaryExpr(List<AstNode> children) {
        super(children, HobbyToken.PRIMARY);
    }

    public static AstNode create(List<AstNode> c) {
        return c.size() == 1 ? c.get(0) : new PrimaryExpr(c);
    }

    @Override
    public String compile(CodeLine line, int th, int nx) {
        if (childCount() >= 2) {
            line.addCode("call " + child(0).toString() + " " + child(1).toString());
        }
        return null;
    }

    @Override
    public Object eval(Environment env) {
        return FunctionEval.evalSubExpr(env, this, 0);
    }
}
