package hobbyscript.Ast;

import hobbyscript.Compile.CodeLine;
import hobbyscript.Eval.Env.EnvironmentCallBack;
import hobbyscript.Eval.FunctionEval;

import java.util.List;

/**
 * 调用参数段
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/15.
 */
public class Arguments extends Postfix {
    public Arguments(List<AstNode> children) {
        super(children);
    }

    @Override
    public Object eval(EnvironmentCallBack env, Object value) {
        return FunctionEval.nativeEval(env, this, value, this);
    }

    @Override
    public String compile(CodeLine line, int th, int nx) {
        StringBuilder builder = new StringBuilder();

        for (int i = 0; i < childCount(); i++) {
            builder.append(child(i).toString()).append(" ");
        }

        return builder.toString();
    }

    public int size() {
        return childCount();
    }
}
