package hobbyscript.Ast;

import hobbyscript.Compile.CodeLine;
import hobbyscript.Eval.Env.EnvironmentCallBack;
import hobbyscript.Eval.ScriptEval;
import hobbyscript.Token.HobbyToken;

import java.util.List;

/**
 * 代码块
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/12.
 */
public class BlockStmnt extends AstList {

    public BlockStmnt(List<AstNode> children) {
        super(children, HobbyToken.BLOCK);
    }

    @Override
    public String compile(CodeLine line, int th, int nx) {
        return super.compile(line, th, nx);
    }

    @Override
    public Object eval(EnvironmentCallBack env) {
        return ScriptEval.blockEval(env, this);
    }
}
