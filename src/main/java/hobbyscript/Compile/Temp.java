package hobbyscript.Compile;

import hobbyscript.Token.HobbyToken;

/**
 * Created by liufengkai on 16/8/7.
 */
public class Temp extends HobbyToken {
    public static int count = 0;

    int number;

    public Temp() {
        super(-1, HobbyToken.TEMP);
        number = ++count;
    }

    public String toString() {
        return "t" + number;
    }
}
