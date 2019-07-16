package hobbyscript.Literal;

import hobbyscript.ast.AstList;
import hobbyscript.ast.AstNode;
import hobbyscript.Eval.Env.Environment;
import hobbyscript.Token.HobbyToken;

import java.util.List;

/**
 * 创建指定大小的数组
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/23.
 */
public class CreateArray extends AstList {

    public CreateArray(List<AstNode> children) {
        super(children, HobbyToken.CREATE_ARRAY);
    }

    @Override
    public Object eval(Environment env) {

        Object sizeO = child(0).eval(env);
        int size = 0;
        if (sizeO instanceof Integer) {
            size = (int) sizeO;
        } else if (sizeO instanceof Double) {
            size = ((Double) sizeO).intValue();
        }

        if (size >= 0) {
            Object[] objects = new Object[size];
            for (int i = 0; i < size; i++) {
                objects[i] = 0;
            }
            return objects;
        }

        return super.eval(env);
    }
}
