package hobbyscript.Token;

/**
 * 字符串Token
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/11.
 */
public class StringToken extends HobbyToken {

    public String literal;

    public StringToken(int lineNumber, String literal) {
        super(lineNumber, HobbyToken.STRING);
        this.literal = literal;
    }

    @Override
    public boolean isString() {
        return true;
    }

    @Override
    public String getText() {
        return literal;
    }


}
