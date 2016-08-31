package HobbyScript.StaticType.Check;

import HobbyScript.Eval.Env.EnvironmentCallBack;
import HobbyScript.Literal.IdLiteral;
import HobbyScript.Literal.NumberLiteral;
import HobbyScript.Literal.StringLiteral;
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
        return OBJECT_TYPE;
    }
}
