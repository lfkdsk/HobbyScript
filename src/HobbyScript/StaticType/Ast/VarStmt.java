package HobbyScript.StaticType.Ast;

import HobbyScript.Ast.AstLeaf;
import HobbyScript.Ast.AstList;
import HobbyScript.Ast.AstNode;
import HobbyScript.Eval.Env.EnvironmentCallBack;
import HobbyScript.Eval.Env.EvalCallBack;
import HobbyScript.Token.HobbyToken;
import HobbyScript.Token.TypeToken;

import java.util.List;

/**
 * Var 的创建过程
 * 0类型 1Token 2Initial
 *
 * @author liufengkai
 *         Created by liufengkai on 16/8/8.
 */
public class VarStmt extends AstList implements EvalCallBack {

    /**
     * 类型转换
     *
     * @param tag HobbyTag
     * @return 类型Token
     */
    public static String convert(int tag) {
        switch (tag) {
            case HobbyToken.FLOAT:
                return TypeToken.FLOAT;
            case HobbyToken.INT:
                return TypeToken.INT;
            case HobbyToken.STRING:
                return TypeToken.STRING;
            default:
                return null;
        }
    }

    public VarStmt(List<AstNode> children) {
        super(children, HobbyToken.VAR);
    }

    public String name() {
        return ((AstLeaf) child(1)).token().getText();
    }

    public String type() {
        return convert(((AstLeaf) child(0)).token().getTag());
    }

    public AstNode initializer() {
        return child(2);
    }

    @Override
    public Object eval(EnvironmentCallBack env) {
        return super.eval(env);
    }

    @Override
    public String toString() {
        return "(var " + type() + " " + name() + " " + initializer().toString() + ")";
    }
}
