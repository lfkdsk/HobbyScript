package hobbyscript.Literal;

import hobbyscript.ast.AstLeaf;
import hobbyscript.Compile.CodeLine;
import hobbyscript.Eval.Env.Environment;
import hobbyscript.Eval.ScriptEval;
import hobbyscript.Token.HobbyToken;
import hobbyscript.Token.NumberToken;

import static hobbyscript.Eval.ScriptEval.isNum;

/**
 * Number字面量
 *
 * @author liufengkai
 * Created by liufengkai on 16/7/11.
 */
public class NumberLiteral extends AstLeaf {
    private final boolean isInteger;

    public NumberLiteral(HobbyToken token) {
        super(token);
        this.isInteger = isNum(((NumberToken) token).getNumber());
    }

    public int getTag() {
        return token.getTag();
    }

    @Override
    public Object eval(Environment env) {
        return ScriptEval.NumberEval(this);
    }

    public boolean isInteger() {
        return isInteger;
    }

    public Number number() {
        return ((NumberToken) token()).getNumber();
    }

    @Override
    public String compile(CodeLine line, int th, int nx) {
        return String.valueOf(((NumberToken) token).getNumber());
    }
}
