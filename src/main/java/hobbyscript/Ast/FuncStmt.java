package hobbyscript.Ast;

import hobbyscript.Compile.CodeLine;
import hobbyscript.Eval.Env.Environment;
import hobbyscript.Eval.FunctionEval;
import hobbyscript.Token.HobbyToken;

import java.util.List;

/**
 * 函数定义
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/15.
 */
public class FuncStmt extends AstList {
    public FuncStmt(List<AstNode> children) {
        super(children, HobbyToken.FUNCTION);
    }

    public String name() {
        return ((AstLeaf) child(0)).token().getText();
    }

    public ParameterList parameters() {
        // 这里在不同情况下的处理是有分歧的
        // 如果无类型的话 记得 child(1)
        // 有类型语言记得 child(2)
        return (ParameterList) child(1);
    }

    public DefBlockStmnt body() {
        // no-type -> 2
        // type    -> 3
        return (DefBlockStmnt) child(2);
    }

    public String toString() {
        return "(func " + name() + " " + parameters() + " "
                + body() + " )";
    }

    @Override
    public String compile(CodeLine line, int th, int nx) {

        CodeLine.FunctionCode code = line.addFunction(name(), parameters().childCount());

        line.startCompileFunction(code);
        int begin = line.newLine();
        int end = line.newLine();
        line.addSpecCode("",begin);

        body().compile(line, begin, end);

        line.addSpecCode("", end);
        line.stopCompileFunction();

        return null;
    }

    @Override
    public Object eval(Environment env) {
        return FunctionEval.functionEval(env, this);
    }
}
