package HobbyScript.StaticType.Ast;

import HobbyScript.Ast.AstLeaf;
import HobbyScript.Ast.AstList;
import HobbyScript.Ast.AstNode;
import HobbyScript.Eval.Env.EnvironmentCallBack;
import HobbyScript.Eval.Env.EvalCallBack;
import HobbyScript.Literal.IdLiteral;
import HobbyScript.StaticType.Literal.ObjectType;
import HobbyScript.Token.HobbyToken;

import java.util.List;

import static HobbyScript.StaticType.Literal.Type.convert;
import static HobbyScript.StaticType.Literal.Type.isInnerType;

/**
 * Var 的创建过程
 * 0类型 1Token 2Initial
 *
 * @author liufengkai
 *         Created by liufengkai on 16/8/8.
 */
public class VarStmt extends AstList implements EvalCallBack {

    public VarStmt(List<AstNode> children) {
        super(children, HobbyToken.VAR);

        IdLiteral id = id();
        TypeLiteral type = ty();

        // 根据是内部提供的数据类型 还是注册的Object类型进行设定类型
        if (isInnerType(type.getType())) {
            id.setType(type.getType());
        } else {
            id.setType(new ObjectType(type.name(), type.hashCode()));
        }
        // 在生成的过程中就自动设定了类型
    }

    public String name() {
        return ((AstLeaf) child(1)).token().getText();
    }

    public IdLiteral id() {
        return (IdLiteral) child(1);
    }

    public TypeLiteral ty() {
        return (TypeLiteral) child(0);
    }

    public String type() {
        return convert(((AstLeaf) child(0)).token().getTag());
    }

    public AstNode initializer() {
        return child(2);
    }

    public boolean hasInitializer() {
        return child(2).childCount() > 0;
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
