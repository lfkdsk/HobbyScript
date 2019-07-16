package hobbyscript.Eval.Env;

import java.util.HashMap;

/**
 * Created by liufengkai on 16/7/14.
 */
public interface Environment {
    void put(String name, Object value);

    boolean contains(String name);

    Object get(String name);

    void putAll(Environment env);

    HashMap<? extends String,?> getMap();
}
