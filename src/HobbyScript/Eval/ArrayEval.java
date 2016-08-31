package HobbyScript.Eval;

import HobbyScript.Ast.ArrayIndex;
import HobbyScript.Ast.AstNode;
import HobbyScript.Ast.PrimaryExpr;
import HobbyScript.Eval.Env.EnvironmentCallBack;
import HobbyScript.Exception.HobbyException;
import HobbyScript.Literal.ArrayLiteral;

/**
 * 新增数组功能
 * Created by liufengkai on 16/7/23.
 */
public class ArrayEval {

    ///////////////////////////////////////////////////////////////////////////
    // 数组初始化
    ///////////////////////////////////////////////////////////////////////////
    public static Object arrayLiteralEval(EnvironmentCallBack env,
                                          ArrayLiteral array) {
        int size = array.childCount();

        Object[] objects = new Object[size];

        int i = 0;
        for (AstNode node : array) {
            objects[i++] = node.eval(env);
        }

        return objects;
    }

    ///////////////////////////////////////////////////////////////////////////
    // 数组访问
    ///////////////////////////////////////////////////////////////////////////
    public static Object arrayIndexEval(EnvironmentCallBack env,
                                        ArrayIndex index,
                                        Object value) {
        if (value instanceof Object[]) {
            Object indexPoint = index.index().eval(env);

            if (indexPoint instanceof Integer) {
                return ((Object[]) value)[(int) indexPoint];
            }
        }

        throw new HobbyException("is not a array: ", index);
    }


    public static Object arrayAccessEval(EnvironmentCallBack env,
                                         PrimaryExpr expr,
                                         Object value) {
        Object in = FunctionEval.evalSubExpr(env, expr, 1);
        if (in instanceof Object[]) {
            ArrayIndex array = (ArrayIndex) FunctionEval.postfix(expr, 0);
            Object index = array.index().eval(env);
            if (index instanceof Integer) {
                return ((Object[]) in)[(int) index] = value;
            }
        }
        throw new HobbyException(" can not access to array", expr);
    }
//
//    public static Object createArray(EnvironmentCallBack env,
//                                     )
}
