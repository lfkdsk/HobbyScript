package HobbyScript.Token;

/**
 * Created by liufengkai on 16/7/27.
 */
public class BoolToken extends HobbyToken {

    public final static String TRUE = "true",
            FALSE = "false";

    public enum BoolType {
        TRUE("true"), FALSE("false");

        String typeString;

        BoolType(String type) {
            this.typeString = type;
        }
    }

    private BoolType type = null;

    public BoolToken(int lineNumber, BoolType type) {
        super(lineNumber, HobbyToken.BOOL);

        setType(type);
    }

    public void setType(BoolType type) {
        this.type = type;

        if (type == BoolType.TRUE) {
            this.tag = HobbyToken.TRUE;
        } else {
            this.tag = HobbyToken.FALSE;
        }
    }

    @Override
    public String toString() {
        return type.typeString;
    }


    public BoolType getType() {
        return type;
    }

    @Override
    public String getText() {
        return toString();
    }

    @Override
    public boolean isBool() {
        return true;
    }
}
