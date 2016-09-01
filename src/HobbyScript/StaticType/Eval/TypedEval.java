package HobbyScript.StaticType.Eval;

import HobbyScript.Eval.Env.EnvironmentCallBack;
import HobbyScript.Exception.HobbyException;
import HobbyScript.StaticType.Ast.VarStmt;
import HobbyScript.StaticType.Token.TypeToken;

/**
 * Created by liufengkai on 16/8/31.
 */
public class TypedEval {

    ///////////////////////////////////////////////////////////////////////////
    // 处理Var注册的值
    ///////////////////////////////////////////////////////////////////////////
    public static Object varEval(EnvironmentCallBack env,
                                 VarStmt varStmt) {
        Object value = null;

        if (varStmt.hasInitializer()) {
            value = varStmt.initializer().eval(env);

            env.put(varStmt.name(), value);

        } else {
            // 空对象 初值
            switch (varStmt.type()) {
                case TypeToken.STRING:
                    env.put(varStmt.name(), "");
                    value = "";
                    break;
                case TypeToken.INT:
                case TypeToken.FLOAT:
                    env.put(varStmt.name(), 0);
                    value = 0;
                    break;
                case TypeToken.OBJECT:
                    env.put(varStmt.name(), null);
                    value = null;
                    break;
                default:
                    throw new HobbyException("can not found type " + varStmt.type());
            }
        }

        return value;
    }
}
