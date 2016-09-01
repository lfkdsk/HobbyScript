package HobbyScript.StaticType.Token;

import HobbyScript.StaticType.Literal.Type;
import HobbyScript.Token.HobbyToken;

/**
 * 静态类型的类型声明
 *
 * @author liufengkai
 *         Created by liufengkai on 16/8/8.
 */
public class TypeToken extends HobbyToken {
    public static final String INT = "Int",
            FLOAT = "Float",
            STRING = "String",
            OBJECT = "Object";

    /**
     * Object 对应的哈希值
     */
    private int hashCode;

    private String name;

    public TypeToken(int lineNumber, int type) {
        super(lineNumber, type);
    }

    public TypeToken(int lineNumber, int tag, String name, int hashCode) {
        super(lineNumber, tag);
        this.hashCode = hashCode;
        this.name = name;
    }

    public int getHashCode() {
        return hashCode;
    }

    public String getName() {
        return name;
    }

    @Override
    public String getText() {
        return Type.convert(tag);
    }

    public boolean isType() {
        return true;
    }
}
