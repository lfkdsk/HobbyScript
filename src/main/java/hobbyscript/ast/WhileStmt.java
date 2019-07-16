package hobbyscript.ast;

import hobbyscript.Compile.CodeLine;
import hobbyscript.Compile.ScriptCompile;
import hobbyscript.Eval.Env.Environment;
import hobbyscript.Eval.Env.LocalEnvironment;
import hobbyscript.Eval.ScriptEval;
import hobbyscript.Token.HobbyToken;

import java.util.List;

/**
 * While控制块
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/12.
 */
public class WhileStmt extends AstList {
    public WhileStmt(List<AstNode> children) {
        super(children, HobbyToken.WHILE);
    }

    public AstNode condition() {
        return child(0);
    }

    public AstNode body() {
        return child(1);
    }

    public String toString() {
        return "(while " + condition() + " " + body() + ")";
    }

    @Override
    public String compile(CodeLine line, int th, int nx) {
        // 保存状态
        saveList = EnClosingList;
        EnClosingList = this;

        // 保存退出点
        afterPoint = nx;                 // 保存用于跳出的地址

        int conditionLabel = line.newLine();
        line.addPrevCode(conditionLabel);

        String condition = condition().compile(line, 0, nx);
        ScriptCompile.emitjumps(line, condition, 0, nx, -1);

        int label = line.newLine();
        line.addPrevCode(label);

        body().compile(line, label, th);
        line.addCode("goto L" + conditionLabel);        // 打印跳转

        // 恢复状态
        EnClosingList = saveList;
        return null;
    }

    @Override
    public Object eval(Environment env) {
        return ScriptEval.whileEval(env, new LocalEnvironment(), this);
    }
}
