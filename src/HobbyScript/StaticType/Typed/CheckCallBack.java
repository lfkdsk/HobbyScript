package HobbyScript.StaticType.Typed;

import HobbyScript.Eval.Env.EnvironmentCallBack;
import HobbyScript.StaticType.Exception.TypeException;
import HobbyScript.StaticType.Literal.Type;

/**
 * 类型检查
 *
 * @author liufengkai
 *         Created by liufengkai on 16/8/31.
 */
public interface CheckCallBack {
    Type check(EnvironmentCallBack env) throws TypeException;
}
