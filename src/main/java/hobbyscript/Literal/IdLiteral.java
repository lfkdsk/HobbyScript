package hobbyscript.Literal;

import hobbyscript.Ast.AstLeaf;
import hobbyscript.Compile.CodeLine;
import hobbyscript.Eval.Env.Environment;
import hobbyscript.Eval.ScriptEval;
import hobbyscript.Token.HobbyToken;

/**
 * ID 变量
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/11.
 */
public class IdLiteral extends AstLeaf {
    public IdLiteral(HobbyToken token) {
        super(token);
    }

    public String name() {
        return token().getText();
    }

    @Override
    public String compile(CodeLine line, int th, int nx) {
        return token.getText();
    }

    @Override
    public Object eval(Environment env) {
        return ScriptEval.IdEval(env, this);
    }
}
