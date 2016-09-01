package HobbyScript.StaticType.Check;

import HobbyScript.Ast.AstNode;
import HobbyScript.Ast.BinaryExpr;
import HobbyScript.Ast.NegativeExpr;
import HobbyScript.Eval.Env.EnvironmentCallBack;
import HobbyScript.Literal.IdLiteral;
import HobbyScript.Literal.NumberLiteral;
import HobbyScript.Literal.StringLiteral;
import HobbyScript.StaticType.Exception.TypeException;
import HobbyScript.StaticType.Literal.Type;
import HobbyScript.Token.HobbyToken;

import static HobbyScript.StaticType.Literal.Type.*;

/**
 * Created by liufengkai on 16/8/31.
 */
public class TypedCheck {

    public static Type numCheck(EnvironmentCallBack env,
                                NumberLiteral num) {
        if (num.getTag() == HobbyToken.FLOAT) {
            return FLOAT_TYPE;
        } else if (num.getTag() == HobbyToken.INT) {
            return INT_TYPE;
        }

        return ERROR_TYPE;
    }

    public static Type stringCheck(EnvironmentCallBack env,
                                   StringLiteral string) {
        return STRING_TYPE;
    }

    public static Type idCheck(EnvironmentCallBack env,
                               IdLiteral id) {
        // type的生成在生成树之后 所以这里已经能拿到Type 了
        return id.getType();
    }

    private static Type idTypeCheckForAssign(IdLiteral id,
                                             Type type,
                                             AstNode node) throws TypeException {
        Type idType = id.getType();

        if (idType == null) {
            throw new TypeException("cannot found type for " + id, node);
        } else {
            type.assertSubtypeOf(idType, node);
            return idType;
        }
    }

    public static Type negativeExprCheck(EnvironmentCallBack env,
                                         NegativeExpr expr)
            throws TypeException {
        Type type = expr.operand().check(env);
        // 检测是否是数字类型
        type.assertNumTypeOf(expr);
        return type;
    }

    public static Type binaryExprCheck(EnvironmentCallBack env,
                                       BinaryExpr expr) {

    }


    private static Type typeCheckForAssign(EnvironmentCallBack env,
                                           BinaryExpr expr)
            throws TypeException {

        Type right = expr.right().check(env);

        expr.setRightType(right);

        AstNode node = expr.left();

        if (node instanceof IdLiteral) {
            return idTypeCheckForAssign((IdLiteral) node, right, expr);
        } else {
            throw new TypeException("bad assignment ", expr);
        }
    }
}
