package hobbyscript.ast;

import hobbyscript.Compile.CodeLine;
import hobbyscript.Eval.Env.Environment;
import hobbyscript.Eval.FunctionEval;
import hobbyscript.Token.HobbyToken;

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
    public Object eval(Environment env) {
        return FunctionEval.blockEval(env, this);
    }
}