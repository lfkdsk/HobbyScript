package hobbyscript.LLVM.generator;

import hobbyscript.LLVM.util.LLVMs;
import hobbyscript.LLVM.visitor.AstVisitor;
import hobbyscript.Literal.NumberLiteral;
import hobbyscript.Utils.logger.Logger;
import org.bytedeco.llvm.LLVM.LLVMValueRef;

public class LLVMVisitor implements AstVisitor {

    public LLVMVisitor() {
        Logger.init();
    }


    @Override
    public LLVMValueRef visitorNumberLiteral(NumberLiteral literal) {
        final boolean isInteger = literal.isInteger();
        final Number number = literal.number();
        if (isInteger) {
            return LLVMs.constInt(number.longValue());
        } else {
            return LLVMs.constDouble(number.doubleValue());
        }
    }
}
