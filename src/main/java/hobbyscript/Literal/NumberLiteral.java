package hobbyscript.Literal;

import hobbyscript.Ast.AstLeaf;
import hobbyscript.Compile.CodeLine;
import hobbyscript.Eval.Env.EnvironmentCallBack;
import hobbyscript.Eval.ScriptEval;
import hobbyscript.Token.HobbyToken;
import hobbyscript.Token.NumberToken;

import static hobbyscript.Eval.ScriptEval.isNum;

/**
 * Number字面量
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/11.
 */
public class NumberLiteral extends AstLeaf {
    private boolean isInteger;

    public NumberLiteral(HobbyToken token) {
        super(token);
        this.isInteger = isNum(token.isNumber());
    }

    public int getTag() {
        return token.getTag();
    }

    @Override
    public Object eval(EnvironmentCallBack env) {
        return ScriptEval.NumberEval(this);
    }

    @Override
    public String compile(CodeLine line, int th, int nx) {
        return String.valueOf(((NumberToken) token).getNumber());
    }
}
