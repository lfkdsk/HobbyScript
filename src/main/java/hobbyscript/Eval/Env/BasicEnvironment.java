package hobbyscript.Eval.Env;

import java.util.HashMap;

/**
 * 一般会翻译成环境
 * 最好理解成局部数据区的运行栈/字母表
 * 一般的实现也都是靠哈希表
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/14.
 */
public class BasicEnvironment implements Environment {

    private HashMap<String, Object> env;

    public BasicEnvironment() {
        this.env = new HashMap<>();
    }

    public BasicEnvironment(HashMap<String, Object> env) {
        this.env = env;
    }

    @Override
    public void put(String name, Object value) {
        env.put(name, value);
    }

    @Override
    public boolean contains(String name) {
        return get(name) != null;
    }

    @Override
    public Object get(String name) {
        return env.get(name);
    }

    @Override
    public void putAll(Environment env) {
        this.env.putAll(env.getMap());
    }

    @Override
    public HashMap<? extends String, ?> getMap() {
        return env;
    }
}
