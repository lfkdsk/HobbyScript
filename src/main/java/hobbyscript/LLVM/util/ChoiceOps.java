package hobbyscript.LLVM.util;

import org.bytedeco.llvm.global.LLVM;

import static hobbyscript.LLVM.util.BinaryOperator.combine;

@FunctionalInterface
public interface ChoiceOps {
    BinaryOperator apply(boolean isInt);

    static BinaryOperator add(boolean isInt) {
        return combine(LLVM::LLVMBuildAdd, LLVM::LLVMBuildFAdd, isInt);
    }

    static BinaryOperator empty(boolean isInt) {
        throw new UnsupportedOperationException("un-support binary type.");
    }
}
