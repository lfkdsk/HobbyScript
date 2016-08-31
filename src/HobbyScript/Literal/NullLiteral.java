package HobbyScript.Literal;

import HobbyScript.Ast.AstLeaf;
import HobbyScript.Eval.Env.EnvironmentCallBack;
import HobbyScript.Token.HobbyToken;

/**
 * Created by liufengkai on 16/8/4.
 */
public class NullLiteral extends AstLeaf {
    public NullLiteral(HobbyToken token) {
        super(token);
    }

    public int tag() {
        return token.getTag();
    }

    @Override
    public Object eval(EnvironmentCallBack env) {
        return token;
    }
}
