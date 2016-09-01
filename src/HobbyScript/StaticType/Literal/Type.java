package HobbyScript.StaticType.Literal;

import HobbyScript.Token.HobbyToken;

import static HobbyScript.StaticType.Token.TypeToken.*;

/**
 * 类型
 *
 * @author liufengkai
 *         Created by liufengkai on 16/8/31.
 */
public class Type {

    public static Type INT_TYPE = new Type() {
        @Override
        public String toString() {
            return INT;
        }
    },
            FLOAT_TYPE = new Type() {
                @Override
                public String toString() {
                    return FLOAT;
                }
            },
            STRING_TYPE = new Type() {
                @Override
                public String toString() {
                    return STRING;
                }
            },
            OBJECT_TYPE = new Type() {
                @Override
                public String toString() {
                    return OBJECT;
                }
            },
            ERROR_TYPE = new Type() {
                @Override
                public String toString() {
                    return "type is error";
                }
            };

    public Type type() {
        return this;
    }

    public static boolean isInnerType(Type type) {
        return type.equals(INT_TYPE) || type.equals(FLOAT_TYPE)
                || type.equals(STRING_TYPE);
    }

    /**
     * 类型转换
     *
     * @param tag HobbyTag
     * @return 类型Token
     */
    public static String convert(int tag) {
        switch (tag) {
            case HobbyToken.FLOAT:
                return FLOAT;
            case HobbyToken.INT:
                return INT;
            case HobbyToken.STRING:
                return STRING;
            case HobbyToken.OBJECT:
                return OBJECT;
            default:
                return null;
        }
    }

    public static Type convertToType(int tag) {
        switch (tag) {
            case HobbyToken.FLOAT:
                return FLOAT_TYPE;
            case HobbyToken.INT:
                return INT_TYPE;
            case HobbyToken.STRING:
                return STRING_TYPE;
            case HobbyToken.OBJECT:
                return OBJECT_TYPE;
            default:
                return null;
        }
    }
}
