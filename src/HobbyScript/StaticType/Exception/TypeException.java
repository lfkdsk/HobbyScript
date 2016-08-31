package HobbyScript.StaticType.Exception;

import HobbyScript.Ast.AstNode;

/**
 * 类型错误异常
 *
 * @author liufengkai
 *         Created by liufengkai on 16/8/31.
 */
public class TypeException extends Exception {

    public TypeException(String msg, AstNode tree) {
        super(msg + " " + tree.location());
    }

}
