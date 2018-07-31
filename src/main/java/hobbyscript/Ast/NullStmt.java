package hobbyscript.Ast;

import hobbyscript.Eval.Env.EnvironmentCallBack;
import hobbyscript.Token.HobbyToken;

import java.util.List;

/**
 * 空
 * Created by liufengkai on 16/7/12.
 */
public class NullStmt extends AstList {
    public NullStmt(List<AstNode> children) {
        super(children, HobbyToken.NULL);
    }

    @Override
    public Object eval(EnvironmentCallBack env) {
        return null;
    }
}
