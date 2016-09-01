package HobbyScript.Literal;

import HobbyScript.Ast.AstLeaf;
import HobbyScript.Compile.CodeLine;
import HobbyScript.Eval.Env.EnvironmentCallBack;
import HobbyScript.Eval.ScriptEval;
import HobbyScript.StaticType.Check.TypedCheck;
import HobbyScript.StaticType.Literal.Type;
import HobbyScript.Token.HobbyToken;

/**
 * String
 * Created by liufengkai on 16/7/12.
 */
public class StringLiteral extends AstLeaf {
    public StringLiteral(HobbyToken token) {
        super(token);
    }

    public String value() {
        return token.getText();
    }

    @Override
    public Type check(EnvironmentCallBack env) {
        return TypedCheck.stringCheck(env, this);
    }

    @Override
    public String compile(CodeLine line, int th, int nx) {
        return token.getText();
    }

    @Override
    public Object eval(EnvironmentCallBack env) {
        return ScriptEval.StringEval(this);
    }
}
