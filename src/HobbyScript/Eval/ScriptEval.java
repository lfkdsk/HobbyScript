package HobbyScript.Eval;

import HobbyScript.Ast.*;
import HobbyScript.Eval.Env.EnvironmentCallBack;
import HobbyScript.Eval.Env.LocalEnvironment;
import HobbyScript.Exception.HobbyException;
import HobbyScript.Literal.*;
import HobbyScript.Parser.ScriptParser;
import HobbyScript.Token.HobbyToken;
import HobbyScript.Token.NumberToken;

import java.util.Iterator;

/**
 * ScriptEval 表达式求值
 * 只包含基础代码段的求值
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/14.
 */
public class ScriptEval {

    ///////////////////////////////////////////////////////////////////////////
    // 处理基础类型节点
    ///////////////////////////////////////////////////////////////////////////

    /**
     * 字符串求值
     *
     * @param literal stringEval
     * @return 字符串
     */
    public static Object StringEval(StringLiteral literal) {
        return literal.value();
    }

    /**
     * 数字类型求值
     *
     * @param literal NumberEval
     * @return int / double
     */
    public static Object NumberEval(NumberLiteral literal) {
        HobbyToken token = literal.token();
        if (isNum(((NumberToken) token).getNumber())) {
            return ((NumberToken) token).getNumber().intValue();
        } else if (isFloat(((NumberToken) token).getNumber())) {
            return ((NumberToken) token).getNumber().doubleValue();
        }
        throw new HobbyException("the number is no legal type: ", literal);
    }

    /**
     * Id
     *
     * @param env     字符表
     * @param literal id
     * @return id-value
     */
    public static Object IdEval(EnvironmentCallBack env, IdLiteral literal) {
        Object value = env.get(literal.name());

        if (value == null) {
            throw new HobbyException("undefined name: " + literal.name(), literal);
        } else {
            return value;
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    // 取反节点
    ///////////////////////////////////////////////////////////////////////////

    /**
     * 求负数
     *
     * @param expr 求负节点
     * @return 负数
     */
    public static Object negativeEval(EnvironmentCallBack env, NegativeExpr expr) {
        Object value = expr.operand().eval(env);

        if (isNum(value)) {
            return -(Integer) value;
        } else if (isFloat(value)) {
            return -(Double) value;
        }

        throw new HobbyException("bad type for -" + value.toString(), expr);
    }

    public static Object negativeBoolEval(EnvironmentCallBack env, NegativeBoolExpr expr) {
        Object value = expr.operand().eval(env);

        if (isBool(value)) {
            return !(Boolean) value;
        }

        throw new HobbyException("bad type for -" + value.toString(), expr);
    }

    ///////////////////////////////////////////////////////////////////////////
    // 布尔表达式节点
    ///////////////////////////////////////////////////////////////////////////

    /**
     * 布尔表达式
     *
     * @param env  字符表
     * @param expr binary
     * @return 返回值
     */
    public static Object binaryEval(EnvironmentCallBack env, BinaryExpr expr) {
        String op = expr.operator();

        // 赋值
        if (ScriptParser.ASSIGN_TOKEN.equals(op)) {
            Object right = expr.right().eval(env);
            if (expr.left() instanceof PrimaryExpr) {
                return ClassEval.computeAssignForClass(env, expr.left(), right);
            }
            return computeAssign(env, expr, right);
        } else {
            // 多元运算
            Object left = expr.left().eval(env);
            Object right = expr.right().eval(env);
            return computeOp(left, right, op, expr);
        }
    }

    /**
     * 处理赋值语句
     *
     * @param env   字符表
     * @param expr  布尔表达式
     * @param value 右值
     * @return 右值
     */
    private static Object computeAssign(EnvironmentCallBack env,
                                        BinaryExpr expr,
                                        Object value) {
        AstLeaf node = (AstLeaf) expr.left();
        int tag = node.token().getTag();
        if (tag == HobbyToken.ID) {
            if (value instanceof ReturnStmt) {
                value = ((ReturnStmt) value).getResult();
            }
            // 重设值
            env.put(((IdLiteral) node).name(), value);
            return value;
        } else {
            throw new HobbyException("bad assign ", expr);
        }
    }

    /**
     * 两个操作数之间的计算
     *
     * @param left
     * @param right
     * @param op
     * @param expr
     * @return
     */
    private static Object computeOp(Object left, Object right,
                                    String op, BinaryExpr expr) {

        // 判断都是数值
        if (isNumber(left) && isNumber(right)) {
            Object temp = computeNumber(left, right, op, expr);

            // 如果都是int类型就不要进行数据转换了
            if (isNum(left) && isNum(right) && isNumber(temp)) {
                return ((Number) temp).intValue();
            } else {
                return temp;
            }
        }

        // string + string
        if (op.equals(ScriptParser.ADD) && ((left instanceof String)
                || (right instanceof String))) {
            return String.valueOf(left) + String.valueOf(right);
        }

        switch (op) {
            case ScriptParser.EQ_TOKEN:
                if (left == null) {
                    return right == null || right instanceof NullLiteral;
                } else {
                    return left.equals(right);
                }
            case ScriptParser.UQ_TOKEN:
                if (left == null) {
                    return right != null;
                } else {
                    return !left.equals(right);
                }
            case ScriptParser.LOGICAL_AND_TOKEN:
                return left == Boolean.TRUE &&
                        right == Boolean.TRUE;
            case ScriptParser.LOGICAL_OR_TOKEN:
                return left == Boolean.TRUE ||
                        right == Boolean.TRUE;
            case ScriptParser.IS_A:
                if (!(left instanceof HobbyObject && right instanceof ClassInfo)) {
                    break;
                }

                ClassInfo leftInfo = ((HobbyObject) left).getClassInfoMsg();
                while (leftInfo != null) {
                    if (leftInfo.name().equals(((ClassInfo) right).name())) {
                        return true;
                    }
                    leftInfo = leftInfo.getSuperClass();
                }

                return false;
            default:
                break;
        }
        throw new HobbyException("bad type when eval with op", expr);
    }

    /**
     * 计算两个数值的问题
     * 这里使用了并不优雅的方式进行两种数据类型的
     * 的计算
     *
     * @param left  左值
     * @param right 右值
     * @param op    符号
     * @param expr  expr
     * @return value
     */

    private static Object computeNumber(Object left, Object right,
                                        String op, BinaryExpr expr) {
        // 此时 left 至少肯定是数字了
        switch (op) {
            case ScriptParser.ADD:
                return (computeIntValue(left) + computeFloatValue(left)) +
                        (computeIntValue(right) + computeFloatValue(right));
            case ScriptParser.SUB:
                return (computeIntValue(left) + computeFloatValue(left)) -
                        (computeIntValue(right) + computeFloatValue(right));
            case ScriptParser.MUL:
                return (computeIntValue(left) + computeFloatValue(left)) *
                        (computeIntValue(right) + computeFloatValue(right));
            case ScriptParser.DIV:
                return (computeIntValue(left) + computeFloatValue(left)) /
                        (computeIntValue(right) + computeFloatValue(right));
            case ScriptParser.MOD:
                return (computeIntValue(left) + computeFloatValue(left)) %
                        (computeIntValue(right) + computeFloatValue(right));
            case ScriptParser.EQ_TOKEN:
                return (computeIntValue(left) + computeFloatValue(left)) ==
                        (computeIntValue(right) + computeFloatValue(right))
                        ? Boolean.TRUE : Boolean.FALSE;
            case ScriptParser.GE_TOKEN:
                return (computeIntValue(left) + computeFloatValue(left)) >
                        (computeIntValue(right) + computeFloatValue(right))
                        ? Boolean.TRUE : Boolean.FALSE;
            case ScriptParser.GT_TOKEN:
                return (computeIntValue(left) + computeFloatValue(left)) <
                        (computeIntValue(right) + computeFloatValue(right))
                        ? Boolean.TRUE : Boolean.FALSE;
            case ScriptParser.UQ_TOKEN:
                return (computeIntValue(left) + computeFloatValue(left)) !=
                        (computeIntValue(right) + computeFloatValue(right))
                        ? Boolean.TRUE : Boolean.FALSE;
            case ScriptParser.GEQ_TOKEN:
                return (computeIntValue(left) + computeFloatValue(left)) >=
                        (computeIntValue(right) + computeFloatValue(right))
                        ? Boolean.TRUE : Boolean.FALSE;
            case ScriptParser.LE_TOKEN:
                return (computeIntValue(left) + computeFloatValue(left)) <=
                        (computeIntValue(right) + computeFloatValue(right))
                        ? Boolean.TRUE : Boolean.FALSE;
            default:
                break;
        }

        throw new HobbyException("bad operator", expr);
    }

    private static int computeIntValue(Object v) {
        return v instanceof Integer ? (Integer) v : 0;
    }

    private static double computeFloatValue(Object v) {
        return v instanceof Double ? (Double) v : (int) 0;
    }

    private static boolean isNumber(Object v) {
        return (v instanceof Integer || v instanceof Double);
    }

    private static boolean isString(int tag) {
        return tag == HobbyToken.STRING;
    }

    private static boolean isNum(Object v) {
        return v instanceof Integer;
    }

    private static boolean isFloat(Object v) {
        return v instanceof Double;
    }

    private static boolean isBool(Object v) {
        return v instanceof Boolean;
    }

    ///////////////////////////////////////////////////////////////////////////
    // Block 节点
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Block 计算
     *
     * @param env  table
     * @param expr expr
     * @return value
     */
    public static Object blockEval(EnvironmentCallBack env, BlockStmnt expr) {
        Object result = 0;
        Iterator<AstNode> iterator = expr.iterator();
        // 一句一句运行
        while (iterator.hasNext()) {
            AstNode node = iterator.next();

            if (node instanceof BreakStmt) {
                result = ((BreakStmt) node).setResult(result);
                break;
            }

            if (!(node instanceof NullStmt)) {
                result = node.eval(env);

                if (node instanceof ReturnStmt) {
                    break;
                }

                if (result instanceof BreakStmt) {
                    break;
                }
            }
        }

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////
    // If 节点
    ///////////////////////////////////////////////////////////////////////////

    /**
     * If 求值
     *
     * @param env     字符表
     * @param ifStmnt if
     * @return value
     */
    public static Object ifEval(EnvironmentCallBack env,
                                LocalEnvironment newEnv,
                                IfStmnt ifStmnt) {
        newEnv.setParent(env);

        Object c = ifStmnt.condition().eval(env);

        // 判断几种通过的方式 true / value > 0 ( 和C类似的设定 )
        if ((c instanceof Boolean && ((Boolean) c).booleanValue() == Boolean.TRUE)
                || (c instanceof Integer && (Integer) c > 0)
                || (c instanceof Double && (Double) c > 0)) {

            return ifStmnt.thenBlock().eval(newEnv);
        } else {

            AstNode node = ifStmnt.elseBlock();
            if (node == null) {
                return 0;
            } else {
                return node.eval(newEnv);
            }
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    // While节点
    ///////////////////////////////////////////////////////////////////////////

    /**
     * While求值
     *
     * @param env       字符表
     * @param whileStmt while
     * @return value
     */
    public static Object whileEval(EnvironmentCallBack env,
                                   LocalEnvironment newEnv,
                                   WhileStmt whileStmt) {
        Object result = 0;
        newEnv.setParent(env);

        for (; ; ) {
            Object c = whileStmt.condition().eval(newEnv);
            // 判断几种通过的方式 true / value > 0 ( 和C类似的设定 )

            if ((c instanceof Boolean &&
                    ((Boolean) c).booleanValue() == Boolean.TRUE)
                    || (c instanceof Integer && (Integer) c > 0)
                    || (c instanceof Double && (Double) c > 0)) {
                Object temp = whileStmt.body().eval(newEnv);

                if (temp instanceof BreakStmt) {
                    result = ((BreakStmt) temp).getResult();
                    return result;
                }
            } else {
                return result;
            }
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    // for 循环
    ///////////////////////////////////////////////////////////////////////////

    public static Object forEval(EnvironmentCallBack env,
                                 LocalEnvironment newEnv,
                                 ForStmt forStmt) {
        Object result = 0;

        newEnv.setParent(env);

        forStmt.initial().eval(newEnv);

        for (; ; ) {
            Object c = forStmt.condition().eval(newEnv);
            // cache for循环的条件缺省
            if (c != null) {
                // 判断几种通过的方式 true / value > 0 ( 和C类似的设定 )
                if ((c instanceof Boolean &&
                        ((Boolean) c).booleanValue() == Boolean.TRUE)
                        || (c instanceof Integer && (Integer) c > 0)
                        || (c instanceof Double && (Double) c > 0)) {
                    Object temp = forStmt.body().eval(newEnv);

                    if (temp instanceof BreakStmt) {
                        result = ((BreakStmt) temp).getResult();
                        return result;
                    }
                } else {
                    return result;
                }
            } else {
                result = forStmt.body().eval(newEnv);
                if (result instanceof BreakStmt) {
                    result = ((BreakStmt) result).getResult();
                    return result;
                }
            }

            forStmt.step().eval(newEnv);
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    // Option 指 expr,expr
    ///////////////////////////////////////////////////////////////////////////

    public static Object optionEval(EnvironmentCallBack env,
                                    OptionStmt option) {
        Object result = 0;

        for (int i = 0; i < option.childCount(); i++) {
            result = option.child(i).eval(env);
        }

        return result;
    }

    public static Object handleBreak(AstNode node, EnvironmentCallBack newEnv) {
        Object temp = node.eval(newEnv);

        if (temp instanceof BreakStmt) {
            return ((BreakStmt) temp).getResult();
        }

        return temp;
    }
}
