package hobbyscript.LLVM.util;

import org.bytedeco.llvm.LLVM.LLVMBuilderRef;
import org.bytedeco.llvm.LLVM.LLVMValueRef;
import org.bytedeco.llvm.global.LLVM;

@FunctionalInterface
public interface BinaryOperator {
    LLVMValueRef apply(LLVMBuilderRef builder, LLVMValueRef lhs, LLVMValueRef rhs, String name);

    static BinaryOperator combine(BinaryOperator integer, BinaryOperator real, boolean isInt) {
        if (isInt) {
            return real;
        } else {
            return integer;
        }
    }
}
