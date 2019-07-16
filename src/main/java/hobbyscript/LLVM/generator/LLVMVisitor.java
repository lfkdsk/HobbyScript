package hobbyscript.LLVM.generator;

import hobbyscript.Eval.Env.Environment;
import hobbyscript.LLVM.visitor.AstVisitor;
import hobbyscript.Literal.IdLiteral;
import hobbyscript.Literal.NumberLiteral;
import hobbyscript.Utils.logger.Logger;
import org.bytedeco.llvm.global.LLVM;

public class LLVMVisitor implements AstVisitor {

    private Environment env;

    public LLVMVisitor(Environment env) {
        this.env = env;
        Logger.init();
    }


    @Override
    public Object visitorNumberLiteral(NumberLiteral literal) {
        return LLVM.LLVMDoubleType();
    }
}
