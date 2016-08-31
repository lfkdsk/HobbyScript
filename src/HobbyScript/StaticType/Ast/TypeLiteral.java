package HobbyScript.StaticType.Ast;

import HobbyScript.Ast.AstLeaf;
import HobbyScript.Token.HobbyToken;

/**
 * 类型Tag
 *
 * @author liufengkai
 *         Created by liufengkai on 16/8/8.
 */
public class TypeLiteral extends AstLeaf {

    public TypeLiteral(HobbyToken token) {
        super(token);
    }

    public String type() {
        return VarStmt.convert(tag);
    }

}
