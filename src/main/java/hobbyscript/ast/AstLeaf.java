package hobbyscript.ast;

import hobbyscript.Eval.Env.Environment;
import hobbyscript.Exception.HobbyException;
import hobbyscript.Token.HobbyToken;

import java.util.ArrayList;
import java.util.Iterator;

/**
 * AST 页节点
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/11.
 */
public class AstLeaf extends AstNode {

    private static ArrayList<AstNode> empty = new ArrayList<>();

    protected HobbyToken token;

    public AstLeaf(HobbyToken token) {
        super(token.getTag());
        this.token = token;
    }

    @Override
    public AstNode child(int index) {
        throw new IndexOutOfBoundsException();
    }

    @Override
    public Iterator<AstNode> children() {
        return empty.iterator();
    }

    @Override
    public int childCount() {
        return 0;
    }

    @Override
    public String location() {
        return "at line " + token.getLineNumber();
    }

    public HobbyToken token() {
        return token;
    }

    @Override
    public String toString() {
        return token.getText();
    }

    @Override
    public Object eval(Environment env) {
        throw new HobbyException("can not eval : " + toString(), this);
    }
}
