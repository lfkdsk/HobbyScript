package hobbyscript.Exception;

import hobbyscript.Token.HobbyToken;

import java.io.IOException;

/**
 * ParseException 编译错误
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/11.
 */
public class ParseException extends Exception {

    public ParseException(HobbyToken token) {
        this("", token);
    }

    public ParseException(String msg, HobbyToken token) {
        super("syntax error around " + location(token) + " . " + msg);
    }

    /**
     * 获取位置
     * @param token 对应词素
     * @return 返回字符串
     */
    private static String location(HobbyToken token) {
        if (token == HobbyToken.EOF) {
            return " the last of line ";
        } else {
            return "\"" + token.getText() + "\" at line " + token.getLineNumber();
        }
    }

    public ParseException(IOException exc) {
        super(exc);
    }

    public ParseException(String msg) {
        super(msg);
    }
}
