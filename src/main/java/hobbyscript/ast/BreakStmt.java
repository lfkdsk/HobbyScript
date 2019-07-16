package hobbyscript.ast;

import hobbyscript.Compile.CodeLine;
import hobbyscript.Eval.Env.Environment;
import hobbyscript.Token.HobbyToken;

import java.util.List;

/**
 * Break 语句
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/16.
 */
public class BreakStmt extends AstList {

    public BreakStmt(List<AstNode> children) {
        super(children, HobbyToken.BREAK);
    }

    // 携带的返回值
    protected Object result;

    protected AstList outList;

    public Object getResult() {
        return result;
    }

    public Object setResult(Object result) {
        this.result = result;
        return this;
    }

    @Override
    public String compile(CodeLine line, int th, int nx) {

        if (EnClosingList == NullList)
            throw new Error("unenclosed break");

        outList = EnClosingList;

        line.addCode("goto L" + outList.afterPoint);
        return null;
    }

    @Override
    public Object eval(Environment env) {
        return new Object();
    }
}
