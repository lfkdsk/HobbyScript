package hobbyscript.Eval.Env;

import java.util.HashMap;

/**
 * 嵌套字符表
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/16.
 */
public class LocalEnvironment implements LocalEnvironmentCallBack {

    protected HashMap<String, Object> values;

    /**
     * 外层符号表
     */
    protected EnvironmentCallBack parentEnv;

    public LocalEnvironment() {
        this(null);
    }

    public LocalEnvironment(EnvironmentCallBack parentEnv) {
        this.parentEnv = parentEnv;
        this.values = new HashMap<>();
    }

    @Override
    public void put(String name, Object value) {
        EnvironmentCallBack env = foundEnv(name);

        if (env == null) {
            env = this;
        }

        ((LocalEnvironment) env).putLocal(name, value);
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
    public void putAll(EnvironmentCallBack env) {
        values.putAll(env.getMap());
    }

    @Override
    public HashMap<? extends String, ?> getMap() {
        return values;
    }

    @Override
    public void setParent(EnvironmentCallBack env) {
        this.parentEnv = env;
    }

    @Override
    public EnvironmentCallBack foundEnv(String name) {
        if (values.get(name) != null) {
            return this;
        } else if (parentEnv == null) {
            return null;
        } else {
            // 向上递归查找
            // 排除基础类型的困扰
            if (parentEnv instanceof BasicEnvironment) return null;
            return ((LocalEnvironment) parentEnv).foundEnv(name);
        }
    }

    @Override
    public void putLocal(String key, Object value) {
        this.values.put(key, value);
    }

    @Override
    public EnvironmentCallBack getParent() {
        return parentEnv;
    }
}
