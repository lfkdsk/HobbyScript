package HobbyScript.Token;

import HobbyScript.StaticType.Ast.VarStmt;

/**
 * 静态类型的类型声明
 *
 * @author liufengkai
 *         Created by liufengkai on 16/8/8.
 */
public class TypeToken extends HobbyToken {

    public static final String INT = "Int",
            FLOAT = "Float",
            STRING = "String";

    public TypeToken(int lineNumber, int type) {
        super(lineNumber, type);
    }

    @Override
    public String getText() {
        return VarStmt.convert(tag);
    }

    public boolean isType() {
        return true;
    }
}
