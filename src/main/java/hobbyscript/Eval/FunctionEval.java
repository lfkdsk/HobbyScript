package hobbyscript.Eval;

import hobbyscript.Ast.*;
import hobbyscript.Eval.Env.Environment;
import hobbyscript.Eval.Env.LocalEnv;
import hobbyscript.Exception.HobbyException;
import hobbyscript.Literal.*;
import hobbyscript.Parser.ScriptParser;

import java.util.Iterator;

/**
 * 添加函数方法之后
 * Created by liufengkai on 16/7/16.
 */
public class FunctionEval {

    ///////////////////////////////////////////////////////////////////////////
    // 函数定义
    ///////////////////////////////////////////////////////////////////////////

    /**
     * 创建一个新的函数作用域
     *
     * @param env  环境作用域
     * @param stmt 函数定义
     * @return 函数名
     */
    public static String functionEval(Environment env, FuncStmt stmt) {
        Function function;
        if (env.contains(ScriptParser.THIS_POINT)) {
            function = new ClassFunction(stmt.parameters(), stmt.body(), env);
        } else {
            function = new Function(stmt.parameters(), stmt.body(), env);
        }

        ((LocalEnv) env).putLocal(stmt.name(), function);
        return stmt.name();
    }

    ///////////////////////////////////////////////////////////////////////////
    // 子表达式的增添项目
    ///////////////////////////////////////////////////////////////////////////

    public static Object operand(PrimaryExpr expr) {
        return expr.child(0);
    }

    public static Postfix postfix(PrimaryExpr expr, int nest) {
        return (Postfix) expr.child(expr.childCount() - nest - 1);
    }

    public static boolean hasPostfix(PrimaryExpr expr, int nest) {
        return expr.childCount() - nest > 1;
    }

    public static Object evalSubExpr(Environment env,
                                     PrimaryExpr expr,
                                     int nest) {
        if (hasPostfix(expr, nest)) {
            Object target = evalSubExpr(env, expr, nest + 1);
            return postfix(expr, nest).eval(env, target);
        } else {
            return ((AstNode) operand(expr)).eval(env);
        }

//        int NewNest = nest;
//        while (hasPostfix(expr, NewNest)) {
//            NewNest++;
//        }
//
//        NewNest -= 1;
//
//        Object target = ((AstNode) operand(expr)).eval(env);
//        Object next = null;
//        for (int i = NewNest; i >= nest; i--) {
//
//            next = postfix(expr, nest).eval(env, target);
//        }
//
//        return next;
    }

    ///////////////////////////////////////////////////////////////////////////
    // Arguments 参数
    ///////////////////////////////////////////////////////////////////////////

    public static Object argumentsEval(Environment parentEnv,
                                       Arguments args,
                                       Object value) {
        if (!(value instanceof Function)) {
            throw new HobbyException(" wrong function ", args);
        }

        Function function = (Function) value;

        ParameterList parameters = function.parameters();

        // 判断参数数量
        if (args.size() < parameters.size()) {
            throw new HobbyException("args less than define", args);
        } else if (args.size() > parameters.size()) {
            throw new HobbyException("args more than define", args);
        }

        LocalEnv newEnv = (LocalEnv) function.makeNewEnv();
        // 正常的函数
//        if (parentEnv != function.getEnv()
//                && !(function instanceof ClassFunction)) {
//            newEnv.setParent(parentEnv);
//        } else {
//            // 闭包函数的环境函数本身/类函数
//            newEnv.setParent(function.getEnv());
//            parentEnv = function.getEnv();
//        }

        if (function instanceof ClassFunction
                || function instanceof ClosureFunction) {
            // 闭包函数的环境函数本身/类函数
            newEnv.setParent(function.getEnv());
//            parentEnv = function.getEnv();
        } else {
            newEnv.setParent(parentEnv);
        }

        int num = 0;

        for (AstNode node : args) {
            parameters.eval(newEnv, num++, node.eval(parentEnv));
        }

        // handler 住这个问题 这里加入这句
        // 解决了构造函数的问题
        if (function instanceof CreateClassFunction) {
            function.body().eval(newEnv);
            return ((CreateClassFunction) function).getClassObject();
        }

        return function.body().eval(newEnv);
    }

    ///////////////////////////////////////////////////////////////////////////
    // 闭包函数
    ///////////////////////////////////////////////////////////////////////////

    public static Object closureEval(Closure closure,
                                     Environment env) {

        return new ClosureFunction(closure.parameters(),
                closure.body(), env);
    }

    ///////////////////////////////////////////////////////////////////////////
    // 原生函数
    ///////////////////////////////////////////////////////////////////////////

    /**
     * 调用原生函数/本地函数
     *
     * @param parentEnv 上一层环境
     * @param args      参数表达式列表
     * @param value     调用函数
     * @param node      所在子树
     * @return 调用结果
     */
    public static Object nativeEval(Environment parentEnv,
                                    Arguments args,
                                    Object value,
                                    AstNode node) {
        if (!(value instanceof NaiveFunction)) {
            return argumentsEval(parentEnv, args, value);
        }

        NaiveFunction function = (NaiveFunction) value;

        int paramsCount = function.paramsCount();
        int count = args.childCount();
        // 同上
        if (count < paramsCount) {
            throw new HobbyException("args less than define", args);
        } else if (count > paramsCount) {
            throw new HobbyException("args more than define", args);
        }

        Object[] newArgs = new Object[count];
        for (int i = 0; i < count; i++) {
            // 对参数表达式进行计算
            newArgs[i] = args.child(i).eval(parentEnv);
        }

        return function.invoke(newArgs, node);
    }

    public static Object blockEval(Environment env, DefBlockStmnt expr) {
        Object result = 0;
        Iterator<AstNode> iterator = expr.iterator();
        // 一句一句运行
        while (iterator.hasNext()) {
            AstNode node = iterator.next();

            if (!(node instanceof NullStmt)) {
                result = node.eval(env);

                if (result instanceof ReturnStmt) {
                    result = ((ReturnStmt) result).getResult();
                    break;
                }
            }
        }

        return result;
    }
}
