package hobbyscript.Literal;

import hobbyscript.Eval.Env.EnvironmentCallBack;
import hobbyscript.Eval.Env.LocalEnvironment;

/**
 * Class类的子对象
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/21.
 */
public class HobbyObject {
    /**
     * 内层环境
     */
    protected EnvironmentCallBack env;

    protected ClassInfo classInfoMsg;

    public ClassInfo getClassInfoMsg() {
        return classInfoMsg;
    }

    public void setClassInfoMsg(ClassInfo classInfoMsg) {
        this.classInfoMsg = classInfoMsg;
    }

    public HobbyObject(EnvironmentCallBack env) {
        this.env = env;
    }

    @Override
    public String toString() {
        return "<object: " + hashCode() + " > ";
    }

    public Object read(String name) throws AssessException {
        if (name.substring(0, 1).toCharArray()[0] >= 'A'
                && name.substring(0, 1).toCharArray()[0] <= 'Z') {
            return getEnvironment(name).get(name);
        }
        throw new AssessException("lower case can not access from a ClassObject :" + name);
    }

    public void write(String name, Object value) throws AssessException {
        ((LocalEnvironment) getEnvironment(name)).putLocal(name, value);
    }

    private EnvironmentCallBack getEnvironment(String member) throws AssessException {
        EnvironmentCallBack environment = ((LocalEnvironment) env).foundEnv(member);

        if (environment == null || environment == env) {
            return env;
        }

        throw new AssessException("can not assess member: " + member);
    }

    /**
     * 无法访问异常
     */
    public static class AssessException extends Exception {
        public AssessException(String msg) {
            super(msg);
        }
    }

}
