package HobbyScript.StaticType.Ast;

import HobbyScript.Ast.AstLeaf;
import HobbyScript.StaticType.Literal.Type;
import HobbyScript.StaticType.Token.TypeToken;
import HobbyScript.Token.HobbyToken;

import static HobbyScript.StaticType.Literal.Type.convert;
import static HobbyScript.StaticType.Literal.Type.convertToType;

/**
 * 类型Tag
 *
 * @author liufengkai
 *         Created by liufengkai on 16/8/8.
 */
public class TypeLiteral extends AstLeaf {

    private Type type;

    public TypeLiteral(HobbyToken token) {
        super(token);
        type = convertToType(tag);
    }

    public Type getType() {
        return type;
    }

    public void setType(Type type) {
        this.type = type;
    }

    public String type() {
        String ty = convert(tag);

        if (token().getTag() == HobbyToken.OBJECT) {
            return ((TypeToken) token()).getName();
        }

        return ty;
    }

    @Override
    public String toString() {
        return type();
    }

    public String name() {
        return ((TypeToken) token()).getName();
    }

    @Override
    public int hashCode() {
        return ((TypeToken) token()).getHashCode();
    }
}
