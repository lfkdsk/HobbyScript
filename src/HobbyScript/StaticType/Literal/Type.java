package HobbyScript.StaticType.Literal;

import HobbyScript.Ast.AstNode;
import HobbyScript.StaticType.Exception.TypeException;
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

    /**
     * 判断是否是原生类型
     *
     * @param type 类别
     * @return 是否原生类型
     */
    public static boolean isInnerType(Type type) {
        return type.equals(INT_TYPE) || type.equals(FLOAT_TYPE)
                || type.equals(STRING_TYPE);
    }

    public boolean isObjectType(Type type) {
        return type instanceof ObjectType;
    }

    /**
     * 类型相同?
     *
     * @param type 类别
     * @return ?
     */
    public boolean match(Type type) {
        return type() == type.type();
    }

    public boolean objectTypeMatch(ObjectType type) {
        return ((ObjectType) type()).getClassHashCode()
                == type.getClassHashCode();
    }

    public boolean subTypeOf(Type type) {
        // 是否类型相同
        if (isInnerType(type) && isInnerType(this)) {
            return match(type);
        } else if (isObjectType(this) && isObjectType(type)) {
            return objectTypeMatch((ObjectType) type);
        }
        return false;
    }

    public boolean numTypeOf(Type type) {
        return type.type() == INT_TYPE || type.type() == FLOAT_TYPE;
    }

    public void assertNumTypeOf(Type type, AstNode node) throws TypeException {
        if (!numTypeOf(type)) {
            throw new TypeException("type mismatch: cannot convert num type from "
                    + this + " to " + type, node);
        }
    }

    public void assertNumTypeOf(AstNode node) throws TypeException {
        assertNumTypeOf(this, node);
    }

    /**
     * 断言式 判断类型是否相同
     *
     * @param type 类型
     * @param node 树节点
     * @throws TypeException 类型异常
     */
    public void assertSubtypeOf(Type type, AstNode node) throws TypeException {

        if (!subTypeOf(type)) {

            throw new TypeException("type mismatch: cannot convert from "
                    + this + " to " + type, node);

        }

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
