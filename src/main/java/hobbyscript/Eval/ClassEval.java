package hobbyscript.Eval;

import hobbyscript.Ast.*;
import hobbyscript.Eval.Env.EnvironmentCallBack;
import hobbyscript.Eval.Env.LocalEnvironment;
import hobbyscript.Exception.HobbyException;
import hobbyscript.Literal.ClassInfo;
import hobbyscript.Literal.CreateClassFunction;
import hobbyscript.Literal.Function;
import hobbyscript.Literal.HobbyObject;
import hobbyscript.Parser.ScriptParser;

import static hobbyscript.Parser.ScriptParser.INITIAL;
import static hobbyscript.Parser.ScriptParser.THIS_POINT;

/**
 * Created by liufengkai on 16/7/21.
 */
public class ClassEval {

    ///////////////////////////////////////////////////////////////////////////
    // 类定义
    ///////////////////////////////////////////////////////////////////////////
    public static String classDefineEval(EnvironmentCallBack env,
                                         ClassStmt stmt) {
        ClassInfo info = new ClassInfo(stmt, env);
        env.put(stmt.name(), info);
        return stmt.name();
    }

    ///////////////////////////////////////////////////////////////////////////
    // 类函数体
    ///////////////////////////////////////////////////////////////////////////
    public static Object classBodyEval(EnvironmentCallBack env,
                                       ClassBody body) {
        for (AstNode n : body) {
            n.eval(env);
        }
        return null;
    }


    ///////////////////////////////////////////////////////////////////////////
    // 索引访问
    ///////////////////////////////////////////////////////////////////////////
    public static Object dotEval(EnvironmentCallBack env,
                                 Dot dot, Object value) {
        String member = dot.name();
        if (value instanceof ClassInfo) {
            // xxx.Initial
            if (member.equals(INITIAL)) {
                ClassInfo info = (ClassInfo) value;
                // 注意是从body拿出来的env,classInfo的env用来获取外层的环境
                LocalEnvironment thisEnv = new LocalEnvironment(info.env());
                // 创建this指针指向该对象
                HobbyObject object = new HobbyObject(thisEnv);
                // set class info
                object.setClassInfoMsg(info);
                thisEnv.put(THIS_POINT, object);
                // 实例化
                initialObject(info, thisEnv);

                Function initialFunction;

                try {
                    initialFunction = (Function) object.read(INITIAL);
                } catch (HobbyObject.AssessException e) {
                    throw new HobbyException("can not read initial function ", dot);
                }

                if (initialFunction == null) return object;

                return new CreateClassFunction(initialFunction, object);
            }
        } else if (value instanceof HobbyObject) {

            try {
                return ((HobbyObject) value).read(member);
            } catch (HobbyObject.AssessException e) {
                e.printStackTrace();
                // TODO : 如果想要变成JavaScript那种能给对象添加属性,就在这里write->read
            }
        }

        throw new HobbyException("can not access to :" + member, dot);
    }

    /**
     * 实化类定义
     *
     * @param info 类信息
     * @param env  环境
     */
    public static void initialObject(ClassInfo info,
                                     EnvironmentCallBack env) {
        if (info.getSuperClass() != null) {

            HobbyObject superObject = new HobbyObject(env);
            env.put(ScriptParser.SUPER_TOKEN, superObject);
            initialObject(info.getSuperClass(), env);
        }

        info.body().eval(env);
    }

    ///////////////////////////////////////////////////////////////////////////
    // 为类元素进行赋值
    ///////////////////////////////////////////////////////////////////////////
    public static Object computeAssignForClass(EnvironmentCallBack env,
                                               AstNode left,
                                               Object value) {
        PrimaryExpr expr = (PrimaryExpr) left;

        if (FunctionEval.hasPostfix(expr, 0) &&
                FunctionEval.postfix(expr, 0) instanceof ArrayIndex) {
            return ArrayEval.arrayAccessEval(env, expr, value);
        }

        // 后缀判断、类型为类索引
        if (FunctionEval.hasPostfix(expr, 0) &&
                FunctionEval.postfix(expr, 0) instanceof Dot) {
            Object t = FunctionEval.evalSubExpr(env, expr, 1);
            if (!(t instanceof HobbyObject)) {
                t = new HobbyObject(env);
            }
            return setField((HobbyObject) t,
                    (Dot) FunctionEval.postfix(expr, 0),
                    value);
        }

        throw new HobbyException("is not a assign for class item", left);
    }

    public static Object setField(HobbyObject object,
                                  Dot dot,
                                  Object rValue) {
        String name = dot.name();
        try {
            object.write(name, rValue);
        } catch (HobbyObject.AssessException e) {
            throw new HobbyException("can not write :" + name + " value: "
                    + rValue);
        }
        return rValue;
    }
}
