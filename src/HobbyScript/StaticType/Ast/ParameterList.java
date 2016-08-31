package HobbyScript.StaticType.Ast;

import HobbyScript.Ast.AstLeaf;
import HobbyScript.Ast.AstList;
import HobbyScript.Ast.AstNode;
import HobbyScript.Eval.Env.EnvironmentCallBack;
import HobbyScript.Eval.Env.LocalEnvironment;
import HobbyScript.Token.HobbyToken;

import java.util.List;

/**
 * 定义参数段
 * <p>
 * Typed修改版
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/15.
 */
public class ParameterList extends AstList {
    public ParameterList(List<AstNode> children) {
        super(children, HobbyToken.PARALIST);
    }

    public int size() {
        return childCount();
    }

    /**
     * 获取对应参数的名字
     *
     * @param i index
     * @return name
     */
    public String name(int i) {
        // 拿Typed的ID
        return ((AstLeaf) children.get(i).child(1)).token().getText();
    }

    public void eval(EnvironmentCallBack env, int index, Object value) {
        ((LocalEnvironment) env).putLocal(name(index), value);
    }
}
