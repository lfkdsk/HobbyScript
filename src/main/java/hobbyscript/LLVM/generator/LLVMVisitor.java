package hobbyscript.LLVM.generator;

import hobbyscript.LLVM.env.LLVMEnv;
import hobbyscript.LLVM.util.LLVMs;
import hobbyscript.LLVM.visitor.AstVisitor;
import hobbyscript.Literal.NumberLiteral;
import hobbyscript.Literal.StringLiteral;
import hobbyscript.Utils.logger.Logger;
import org.bytedeco.llvm.LLVM.LLVMValueRef;
import org.bytedeco.llvm.global.LLVM;

public class LLVMVisitor implements AstVisitor {

    public LLVMVisitor() {
        Logger.init();
    }

    @Override
    public LLVMValueRef visitorNumberLiteral(NumberLiteral literal, LLVMEnv env) {
        final boolean isInteger = literal.isInteger();
        final Number number = literal.number();
        if (isInteger) {
            return LLVMs.constInt(number.longValue());
        } else {
            return LLVMs.constDouble(number.doubleValue());
        }
    }

    @Override
    public LLVMValueRef visitorStringLiteral(StringLiteral literal, LLVMEnv env) {
        return LLVMs.constString(literal.value());
    }


}
