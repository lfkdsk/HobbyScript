package HobbyScript.Eval.Env;

/**
 * 有嵌套逻辑关系的符号表
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/16.
 */
public interface LocalEnvironmentCallBack extends EnvironmentCallBack {

    void setParent(EnvironmentCallBack env);

    EnvironmentCallBack foundEnv(String name);

    void putLocal(String key, Object value);

    EnvironmentCallBack getParent();
}
