package HobbyScript.Token;

/**
 * 变量名Token
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/11.
 */
public class IdToken extends HobbyToken {
    private String text;

    public IdToken(int lineNumber, String text) {
        super(lineNumber, HobbyToken.ID);
        this.text = text;

        if (text.equals(HobbyToken.EOL)) {
            this.tag = HobbyToken.EOL_TAG;
        }
    }

    @Override
    public boolean isIdentifier() {
        return true;
    }

    @Override
    public String getText() {
        return text;
    }
}
