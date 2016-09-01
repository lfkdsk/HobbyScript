package HobbyScript.StaticType.Ast;

import HobbyScript.Ast.AstLeaf;
import HobbyScript.Ast.AstList;
import HobbyScript.Ast.AstNode;
import HobbyScript.Ast.BlockStmnt;
import HobbyScript.Compile.CodeLine;
import HobbyScript.Eval.Env.EnvironmentCallBack;
import HobbyScript.Eval.FunctionEval;
import HobbyScript.Literal.IdLiteral;
import HobbyScript.StaticType.Literal.ObjectType;
import HobbyScript.Token.HobbyToken;

import java.util.List;

import static HobbyScript.StaticType.Literal.Type.isInnerType;

/**
 * 函数定义
 * <p>
 * Typed修改版本
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/15.
 */
public class FuncStmt extends AstList {

    public FuncStmt(List<AstNode> children) {
        super(children, HobbyToken.FUNCTION);

        IdLiteral id = id();
        TypeLiteral type = ty();

        // 根据是内部提供的数据类型 还是注册的Object类型进行设定类型
        if (isInnerType(type.getType())) {
            id.setType(type.getType());
        } else {
            id.setType(new ObjectType(type.name(), type.hashCode()));
        }
        // 在生成的过程中就自动设定了类型
    }

    public IdLiteral id() {
        return (IdLiteral) child(1);
    }

    public String name() {
        return ((AstLeaf) child(1)).token().getText();
    }

    public TypeLiteral ty() {
        return (TypeLiteral) child(0);
    }

    public ParameterList parameters() {
        // 这里在不同情况下的处理是有分歧的
        // 如果无类型的话 记得 child(1)
        // 有类型语言记得 child(2)
        return (ParameterList) child(2);
    }

    public BlockStmnt body() {
        // no-type -> 2
        // type    -> 3
        return (BlockStmnt) child(3);
    }

    public String toString() {
        return "(func " + ty() + " " + name() + " " + parameters() + " "
                + body() + " )";
    }

    @Override
    public String compile(CodeLine line, int th, int nx) {

        CodeLine.FunctionCode code = line.addFunction(name(), parameters().childCount());

        line.startCompileFunction(code);
        int begin = line.newLine();
        int end = line.newLine();
        line.addSpecCode("", begin);

        body().compile(line, begin, end);

        line.addSpecCode("", end);
        line.stopCompileFunction();

        return null;
    }

    @Override
    public Object eval(EnvironmentCallBack env) {
        return FunctionEval.functionEval(env, this);
    }
}
