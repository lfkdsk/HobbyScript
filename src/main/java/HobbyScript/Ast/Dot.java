package HobbyScript.Ast;

import HobbyScript.Eval.ClassEval;
import HobbyScript.Eval.Env.EnvironmentCallBack;

import java.util.List;

/**
 * 类点号索引
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/20.
 */
public class Dot extends Postfix {

    public Dot(List<AstNode> children) {
        super(children);
    }

    public String name() {
        return ((AstLeaf) child(0)).token().getText();
    }

    @Override
    public String toString() {
        return "." + name();
    }

    @Override
    public Object eval(EnvironmentCallBack env, Object value) {
        return ClassEval.dotEval(env, this, value);
    }
}
