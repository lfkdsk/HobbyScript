package HobbyScript.Ast;

import HobbyScript.Compile.CodeLine;
import HobbyScript.Compile.CompileCallBack;
import HobbyScript.Eval.Env.EnvironmentCallBack;
import HobbyScript.Eval.Env.EvalCallBack;
import HobbyScript.StaticType.Exception.TypeException;
import HobbyScript.StaticType.Literal.Type;
import HobbyScript.StaticType.Typed.CheckCallBack;

import java.util.Iterator;
import java.util.Objects;
import java.util.function.Consumer;

/**
 * AST TREE NODE 抽象语法树的通用接口
 * Created by liufengkai on 16/7/11.
 */
public abstract class AstNode implements Iterable<AstNode>,
        EvalCallBack, CompileCallBack, CheckCallBack {
    protected final int tag;

    protected AstNode(int tag) {
        this.tag = tag;
    }

    /**
     * 获取指定子节点
     *
     * @param index 索引
     * @return 子节点
     */
    public abstract AstNode child(int index);

    /**
     * 返回子节点迭代器
     *
     * @return 迭代器
     */
    public abstract Iterator<AstNode> children();

    /**
     * 子节点数目
     *
     * @return count
     */
    public abstract int childCount();

    /**
     * 位置描述
     *
     * @return location
     */
    public abstract String location();

    @Override
    public Iterator<AstNode> iterator() {
        return children();
    }

    @Override
    public void forEach(Consumer<? super AstNode> action) {
        Objects.requireNonNull(action);
        for (AstNode t : this) {
            action.accept(t);
        }
    }

    @Override
    public Type check(EnvironmentCallBack env) throws TypeException {
        return null;
    }

    @Override
    public Object eval(EnvironmentCallBack env) {
        return this;
    }

    @Override
    public String compile(CodeLine line, int th, int nx) {
        return null;
    }
}
