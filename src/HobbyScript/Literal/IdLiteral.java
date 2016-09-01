package HobbyScript.Literal;

import HobbyScript.Ast.AstLeaf;
import HobbyScript.Compile.CodeLine;
import HobbyScript.Eval.Env.EnvironmentCallBack;
import HobbyScript.Eval.ScriptEval;
import HobbyScript.StaticType.Check.TypedCheck;
import HobbyScript.StaticType.Literal.Type;
import HobbyScript.Token.HobbyToken;

/**
 * ID 变量
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/11.
 */
public class IdLiteral extends AstLeaf {

    protected Type type;

    public IdLiteral(HobbyToken token) {
        super(token);
    }

    public Type getType() {
        return type;
    }

    public void setType(Type type) {
        this.type = type;
    }

    public String name() {
        return token().getText();
    }

    @Override
    public HobbyToken token() {
        return token;
    }

    @Override
    public Type check(EnvironmentCallBack env) {
        return TypedCheck.idCheck(env, this);
    }

    @Override
    public String compile(CodeLine line, int th, int nx) {
        return token.getText();
    }

    @Override
    public Object eval(EnvironmentCallBack env) {
        return ScriptEval.IdEval(env, this);
    }
}
