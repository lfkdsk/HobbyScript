package HobbyScript.Ast;

import HobbyScript.Compile.CodeLine;
import HobbyScript.Eval.Env.EnvironmentCallBack;
import HobbyScript.Eval.FunctionEval;
import HobbyScript.Token.HobbyToken;

import java.util.List;

/**
 * Created by liufengkai on 2017/3/12.
 */
public class DefBlockStmnt extends AstList {

    public DefBlockStmnt(List<AstNode> children) {
        super(children, HobbyToken.BLOCK);
    }

    @Override
    public String compile(CodeLine line, int th, int nx) {
        return super.compile(line, th, nx);
    }

    @Override
    public Object eval(EnvironmentCallBack env) {
        return FunctionEval.blockEval(env, this);
    }
}