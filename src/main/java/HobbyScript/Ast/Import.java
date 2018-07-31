package HobbyScript.Ast;

import HobbyScript.Eval.Env.EnvironmentCallBack;
import HobbyScript.Eval.ImportEval;
import HobbyScript.Token.HobbyToken;

import java.util.List;

/**
 * Import
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/26.
 */
public class Import extends AstList {
    public Import(List<AstNode> children) {
        super(children, HobbyToken.IMPORT);
    }

    public AstNode importLib() {
        return child(0);
    }

    @Override
    public Object eval(EnvironmentCallBack env) {
        ImportEval.importEval(env, this);
        return null;
    }
}
