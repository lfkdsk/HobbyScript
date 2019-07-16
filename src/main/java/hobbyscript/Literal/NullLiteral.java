package hobbyscript.Literal;

import hobbyscript.ast.AstLeaf;
import hobbyscript.Eval.Env.Environment;
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
    public Object eval(Environment env) {
        return token;
    }
}
