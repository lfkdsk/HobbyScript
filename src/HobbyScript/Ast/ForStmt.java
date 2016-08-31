package HobbyScript.Ast;

import HobbyScript.Compile.CodeLine;
import HobbyScript.Compile.ScriptCompile;
import HobbyScript.Eval.Env.EnvironmentCallBack;
import HobbyScript.Eval.Env.LocalEnvironment;
import HobbyScript.Eval.ScriptEval;
import HobbyScript.Token.HobbyToken;

import java.util.List;

/**
 * For
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/16.
 */
public class ForStmt extends AstList {

    public ForStmt(List<AstNode> children) {
        super(children, HobbyToken.FOR);
    }

    public AstNode initial() {
        return child(0);
    }

    public AstNode condition() {
        return child(1);
    }

    public AstNode step() {
        return child(2);
    }

    public AstNode body() {
        return child(3);
    }

    @Override
    public String compile(CodeLine line, int th, int nx) {
        // 保存状态
        saveList = EnClosingList;
        EnClosingList = this;

        // 保存退出点
        afterPoint = nx;                 // 保存用于跳出的地址

        initial().compile(line, th, nx);

        int initial = line.newLine();

        line.addPrevCode(initial);

        String condition = condition().compile(line, 0, nx);
        ScriptCompile.emitjumps(line, condition, 0, nx, -1);

        int label = line.newLine();
        line.addPrevCode(label);

        body().compile(line, label, initial);

        step().compile(line, label, initial);

        line.addCode("goto L" + initial);        // 打印跳转

        // 恢复状态
        EnClosingList = saveList;
        return null;
    }

    @Override
    public Object eval(EnvironmentCallBack env) {
        return ScriptEval.forEval(env, new LocalEnvironment(), this);
    }
}
