package hobbyscript.Ast;

import hobbyscript.Eval.ClassEval;
import hobbyscript.Eval.Env.EnvironmentCallBack;
import hobbyscript.Token.HobbyToken;

import java.util.List;

/**
 * 类定义
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/20.
 */
public class ClassStmt extends AstList {

    public ClassStmt(List<AstNode> children) {
        super(children, HobbyToken.CLASS_TOKEN);
    }

    public String name() {
        return ((AstLeaf) child(0)).token().getText();
    }

    public ClassBody body() {
        return (ClassBody) this.child(childCount() - 1);
    }

    /**
     * 获取超类
     *
     * @return 名称
     */
    public String superClass() {
        if (childCount() < 3) {
            return null;
        } else {
            return ((AstLeaf) child(1)).token().getText();
        }
    }

    @Override
    public Object eval(EnvironmentCallBack env) {
        return ClassEval.classDefineEval(env, this);
    }

    @Override
    public String toString() {
        String parent = superClass();
        if (parent == null) {
            parent = "*";
        }
        return "(class " + name() + " parent " + parent + " " + body() + ")";
    }
}
