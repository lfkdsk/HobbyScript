package hobbyscript.Literal;

import hobbyscript.Ast.AstLeaf;
import hobbyscript.Eval.Env.EnvironmentCallBack;
import hobbyscript.Token.HobbyToken;

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
