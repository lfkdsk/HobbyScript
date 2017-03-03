package HobbyScript.Native;

import HobbyScript.Eval.Env.EnvironmentCallBack;
import HobbyScript.Eval.Env.LocalEnvironment;
import HobbyScript.Exception.HobbyException;
import HobbyScript.Literal.HobbyObject;
import HobbyScript.Literal.NaiveFunction;
import HobbyScript.Utils.logger.Logger;

import java.lang.reflect.Method;


/**
 * 原生函数对应列表
 * Created by liufengkai on 16/7/20.
 */
public class NativeList {
    private static LocalEnvironment topFloorEnvironment;

    /**
     * 添加原生函数
     *
     * @param env        环境 
     * @param nativeName 函数名
     * @param clazz      需要反射拿到的类
     * @param params     参数
     */
    public static void addNativeFunction(EnvironmentCallBack env,
                                         String chName,
                                         String nativeName,
                                         Class<?> clazz,
                                         Class<?>... params) {
        Method method;

        try {
            method = clazz.getMethod(nativeName, params);
        } catch (NoSuchMethodException e) {
            throw new HobbyException("can not found native function :" + nativeName);
        }

        env.put(chName, new NaiveFunction(nativeName, method));
    }

    /**
     * Logger打印
     *
     * @param msg 打印message
     */
    public static void logInfo(String msg) {
        Logger.i(msg);
    }

    /**
     * 求数组长度
     *
     * @param objects 数组
     * @return 返回长度
     */
    public static int length(Object[] objects) {
        return objects.length;
    }

    public static int stringLength(String line) {
        return line.length();
    }

    /**
     * 普通日志打印
     *
     * @param msg message
     */
    public static void println(String msg) {
        System.out.println(msg);
    }

    public static void print(String msg) {
        System.out.print(msg);
    }

    /**
     * 创建Array数组
     *
     * @param integer 大小
     * @return 数组大小
     */
    public static Object[] createArray(Integer integer) {
        Object[] array = new Object[integer];
        for (int i = 0; i < integer; i++) {
            array[i] = 0;
        }
        return array;
    }

    public static EnvironmentCallBack getLocalEnv(String name) throws HobbyObject.AssessException {
        EnvironmentCallBack environment = topFloorEnvironment
                .foundEnv(name);

        if (environment == null || environment == topFloorEnvironment) {
            return topFloorEnvironment;
        }

        throw new HobbyObject.AssessException("can not assess member: " + name);
    }


    public EnvironmentCallBack env(EnvironmentCallBack env) {
        topFloorEnvironment = (LocalEnvironment) env;

        addNativeFunction(env, "谈笑风生", "logInfo", NativeList.class, String.class);
        addNativeFunction(env, "输出", "println", NativeList.class, String.class);
//        addNativeFunction(env, "length", NativeList.class, Object[].class);
//        addNativeFunction(env, "stringLength", NativeList.class, String.class);
//        addNativeFunction(env, "print", NativeList.class, String.class);
//        addNativeFunction(env, "createArray", NativeList.class, Integer.class);
//        addNativeFunction(env, "createScanner", InputMethod.class, null);
//        addNativeFunction(env, "getNextLine", InputMethod.class, Scanner.class);
//        addNativeFunction(env, "endScanner", InputMethod.class, Scanner.class);
//        addNativeFunction(env, "hasNext", InputMethod.class, Scanner.class);
//        addNativeFunction(env, "charAtPoint", InputMethod.class, String.class, Integer.class);
//        addNativeFunction(env, "openReader", InputMethod.class, null);
//        addNativeFunction(env, "read", InputMethod.class, BufferedReader.class);
//        addNativeFunction(env, "readNextLine", InputMethod.class, BufferedReader.class);
//        addNativeFunction(env, "closeReader", InputMethod.class, BufferedReader.class);
//        addNativeFunction(env, "parser", InputMethod.class, BufferedReader.class);
//        addNativeFunction(env, "getLocalEnv", NativeList.class, String.class);
        return env;
    }

}
