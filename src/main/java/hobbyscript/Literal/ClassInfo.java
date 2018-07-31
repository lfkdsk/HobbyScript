package hobbyscript.Literal;

import hobbyscript.Ast.ClassBody;
import hobbyscript.Ast.ClassStmt;
import hobbyscript.Eval.Env.EnvironmentCallBack;
import hobbyscript.Exception.HobbyException;

/**
 * 类运行对象
 * Created by liufengkai on 16/7/21.
 */
public class ClassInfo {
    /**
     * 定义
     */
    private ClassStmt definition;

    /**
     * 运行环境
     * 这个运行环境只是从外部类拿出来而已
     */
    private EnvironmentCallBack env;

    /**
     * 超类
     */
    private ClassInfo superClass = null;

    public ClassInfo(ClassStmt stmt, EnvironmentCallBack env) {
        this.definition = stmt;
        this.env = env;

        Object superClass = env.get(stmt.superClass());

        if (superClass != null) {
            if (superClass instanceof ClassInfo) {
                this.superClass = (ClassInfo) superClass;
            } else {
                throw new HobbyException("unknown super class", stmt);
            }
        }
    }

    public ClassInfo getSuperClass() {
        return superClass;
    }

    public void setSuperClass(ClassInfo superClass) {
        this.superClass = superClass;
    }

    public String name() {
        return definition.name();
    }

    public ClassBody body() {
        return definition.body();
    }

    public EnvironmentCallBack env() {
        return env;
    }

    @Override
    public String toString() {
        return "<classInfo : " + hashCode() + " > ";
    }
}
