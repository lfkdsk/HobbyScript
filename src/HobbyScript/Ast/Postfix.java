package HobbyScript.Ast;

import HobbyScript.Eval.Env.EnvironmentCallBack;
import HobbyScript.Token.HobbyToken;

import java.util.List;

/**
 * 后缀 id() 处理调用
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/15.
 */
public abstract class Postfix extends AstList {

    public Postfix(List<AstNode> children) {
        super(children, HobbyToken.POSTFIX);
    }

    public abstract Object eval(EnvironmentCallBack env, Object value);

}
