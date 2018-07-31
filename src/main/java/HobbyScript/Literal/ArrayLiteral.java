package HobbyScript.Literal;

import HobbyScript.Ast.AstList;
import HobbyScript.Ast.AstNode;
import HobbyScript.Eval.ArrayEval;
import HobbyScript.Eval.Env.EnvironmentCallBack;
import HobbyScript.Token.HobbyToken;

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
    public Object eval(EnvironmentCallBack env) {
        return ArrayEval.arrayLiteralEval(env, this);
    }
}
