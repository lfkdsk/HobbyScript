package hobbyscript.ast;

import hobbyscript.Compile.CodeLine;
import hobbyscript.Compile.ScriptCompile;
import hobbyscript.Eval.Env.Environment;
import hobbyscript.Eval.Env.LocalEnvironment;
import hobbyscript.Eval.ScriptEval;
import hobbyscript.Token.HobbyToken;

import java.util.List;

/**
 * IF 控制块
 * Created by liufengkai on 16/7/12.
 */
public class IfStmnt extends AstList {

    public IfStmnt(List<AstNode> children) {
        super(children, HobbyToken.IF);
    }

    public AstNode condition() {
        return child(0);
    }

    public AstNode thenBlock() {
        return child(1);
    }

    public AstNode elseBlock() {
        return childCount() > 2 ? child(2) : null;
    }

    public String toString() {
        return "(if " + condition() + " " +
                thenBlock() + " else " +
                elseBlock() + " )";
    }

    @Override
    public String compile(CodeLine line, int th, int nx) {

        if (elseBlock() == null || thenBlock().childCount() <= 0) {
            // stmt 标号
            int label = line.newLine();

            String condition = condition().compile(line, 0, nx);

            // jump
            ScriptCompile.emitjumps(line, condition, 0, nx, -1);

            line.addPrevCode(label);
            // 为真时控制穿越流,为假时转向nx
            thenBlock().compile(line, label, nx);
        } else {
            int label_1 = line.newLine(); // stmt1
            int label_2 = line.newLine(); // stmt2

            String condition = condition().compile(line, 0, label_2);

            ScriptCompile.emitjumps(line, condition, 0, label_2, label_1); // 为真时1

            thenBlock().compile(line, label_1, nx);

            line.addCode("goto L" + nx);

            line.addPrevCode(label_2);

            elseBlock().compile(line, label_2, nx);
        }

        return null;
    }

    @Override
    public Object eval(Environment env) {
        return ScriptEval.ifEval(env, new LocalEnvironment(), this);
    }
}
