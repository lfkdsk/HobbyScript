package hobbyscript.ast;

import hobbyscript.Eval.Env.Environment;
import hobbyscript.Token.HobbyToken;

import java.util.List;

/**
 * Created by liufengkai on 2017/3/12.
 */
public class ReturnStmt extends AstList {

    public ReturnStmt(List<AstNode> children) {
        super(children, HobbyToken.RETURN);
    }

    private Object result;

    public Object getResult() {
        return result;
    }

    public void setResult(Object result) {
        this.result = result;
    }

    @Override
    public Object eval(Environment env) {

        if (result == null)
            this.setResult(child(0).eval(env));

        return this;
    }
}
