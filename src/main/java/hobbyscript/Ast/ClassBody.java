package hobbyscript.Ast;

import hobbyscript.Eval.ClassEval;
import hobbyscript.Eval.Env.EnvironmentCallBack;
import hobbyscript.Token.HobbyToken;

import java.util.List;

/**
 * 类的定义体
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/20.
 */
public class ClassBody extends AstList {

    public ClassBody(List<AstNode> children) {
        super(children, HobbyToken.CLASS_BODY_TOKEN);
    }

    @Override
    public Object eval(EnvironmentCallBack env) {
        return ClassEval.classBodyEval(env, this);
    }
}
