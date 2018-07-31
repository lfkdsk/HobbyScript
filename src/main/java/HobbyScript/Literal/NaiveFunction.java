package HobbyScript.Literal;

import HobbyScript.Ast.AstNode;
import HobbyScript.Exception.HobbyException;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

/**
 * Created by liufengkai on 16/7/20.
 */
public class NaiveFunction {
    /**
     * 原生方法
     */
    private Method nativeMethod;
    /**
     * 方法名
     */
    private String methodName;
    /**
     * 参数量
     */
    private int paramsNum;

    public NaiveFunction(String methodName, Method nativeMethod) {
        this.nativeMethod = nativeMethod;
        this.methodName = methodName;
        this.paramsNum = nativeMethod.getParameterCount();
    }

    /**
     * 原生函数调用
     *
     * @param args 参数
     * @param tree Ast
     * @return 调用结果
     */
    public Object invoke(Object[] args, AstNode tree) {
        try {
            if (methodName.equals("exp")) {
                args[0] = Double.parseDouble(args[0].toString());
            }
            // static 方法 所以null
            return nativeMethod.invoke(null, args);
        } catch (IllegalArgumentException | IllegalAccessException | InvocationTargetException e) {
            throw new HobbyException(" call native function fail " + methodName, tree);
        }
    }

    public int paramsCount() {
        return paramsNum;
    }
}
