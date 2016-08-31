package HobbyScript.StaticType.Ast;

import HobbyScript.Ast.AstLeaf;
import HobbyScript.Ast.AstList;
import HobbyScript.Ast.AstNode;
import HobbyScript.Token.HobbyToken;
import HobbyScript.Token.TypeToken;

import java.util.List;

/**
 * Created by liufengkai on 16/8/8.
 */
public class VarStmt extends AstList {


    public static String convert(int tag) {
        switch (tag) {
            case HobbyToken.FLOAT:
                return TypeToken.FLOAT;
            case HobbyToken.INT:
                return TypeToken.INT;
            case HobbyToken.STRING:
                return TypeToken.STRING;
            default:
                return null;
        }
    }

    public VarStmt(List<AstNode> children) {
        super(children, HobbyToken.VAR);
    }

    public String name() {
        return ((AstLeaf) child(1)).token().getText();
    }

    public String type() {
        return convert(((AstLeaf) child(0)).token().getTag());
    }

    public AstNode initializer() {
        return child(2);
    }

    @Override
    public String toString() {
        return "(var " + type() + " " + name() + " " + initializer().toString() + ")";
    }
}
