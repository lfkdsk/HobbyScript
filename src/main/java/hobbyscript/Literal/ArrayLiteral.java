package hobbyscript.Literal;

import hobbyscript.Ast.AstList;
import hobbyscript.Ast.AstNode;
import hobbyscript.Eval.ArrayEval;
import hobbyscript.Eval.Env.Environment;
import hobbyscript.Token.HobbyToken;

import java.util.List;

/**
 * 数组
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/23.
 */
public class ArrayLiteral extends AstList {
    public ArrayLiteral(List<AstNode> children) {
        super(children, HobbyToken.ARRAY);
    }

    public int size() {
        return childCount();
    }

    @Override
    public Object eval(Environment env) {
        return ArrayEval.arrayLiteralEval(env, this);
    }
}
