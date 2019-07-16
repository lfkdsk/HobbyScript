package hobbyscript.Ast;

import hobbyscript.Eval.ClassEval;
import hobbyscript.Eval.Env.Environment;

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
    public Object eval(Environment env, Object value) {
        return ClassEval.dotEval(env, this, value);
    }
}
