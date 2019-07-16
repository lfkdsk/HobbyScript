package hobbyscript.Eval.Env;

/**
 * 有嵌套逻辑关系的符号表
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/16.
 */
public interface LocalEnv extends Environment {

    void setParent(Environment env);

    Environment foundEnv(String name);

    void putLocal(String key, Object value);

    Environment getParent();
}
