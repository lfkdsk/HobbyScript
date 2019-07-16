package hobbyscript.Eval.Env;

import java.util.HashMap;

/**
 * 嵌套字符表
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/16.
 */
public class LocalEnvironment implements LocalEnv {

    protected HashMap<String, Object> values;

    /**
     * 外层符号表
     */
    protected Environment parentEnv;

    public LocalEnvironment() {
        this(null);
    }

    public LocalEnvironment(Environment parentEnv) {
        this.parentEnv = parentEnv;
        this.values = new HashMap<>();
    }

    @Override
    public void put(String name, Object value) {
        Environment env = foundEnv(name);

        if (env == null) {
            env = this;
        }

        ((LocalEnv) env).putLocal(name, value);
    }

    @Override
    public boolean contains(String name) {
        return get(name) != null;
    }

    @Override
    public Object get(String name) {
        Object value = values.get(name);

        if (value == null && parentEnv != null) {
            return parentEnv.get(name);
        } else {
            return value;
        }
    }

    @Override
    public void putAll(Environment env) {
        values.putAll(env.getMap());
    }

    @Override
    public HashMap<? extends String, ?> getMap() {
        return values;
    }

    @Override
    public void setParent(Environment env) {
        this.parentEnv = env;
    }

    @Override
    public Environment foundEnv(String name) {
        if (values.get(name) != null) {
            return this;
        } else if (parentEnv == null) {
            return null;
        } else {
            // 向上递归查找
            // 排除基础类型的困扰
            if (parentEnv instanceof BasicEnvironment) return null;
            return ((LocalEnv) parentEnv).foundEnv(name);
        }
    }

    @Override
    public void putLocal(String key, Object value) {
        this.values.put(key, value);
    }

    @Override
    public Environment getParent() {
        return parentEnv;
    }
}
