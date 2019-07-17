package hobbyscript.LLVM.instruction;

import hobbyscript.LLVM.env.LLVMEnv;
import hobbyscript.LLVM.util.BinaryOperator;
import hobbyscript.LLVM.util.ChoiceOps;
import org.bytedeco.llvm.LLVM.LLVMBuilderRef;
import org.bytedeco.llvm.LLVM.LLVMTypeRef;
import org.bytedeco.llvm.LLVM.LLVMValueRef;
import org.bytedeco.llvm.global.LLVM;

public final class IRBuilder {

    private LLVMBuilderRef builderRef;

    private IRBuilder() {
        this.builderRef = LLVM.LLVMCreateBuilder();
    }

    public static IRBuilder of() {
        return new IRBuilder();
    }

    public LLVMValueRef createGlobal(LLVMEnv env, LLVMValueRef value, String name) {
        LLVMValueRef globalVar = LLVM.LLVMAddGlobal(env.getModule(), LLVM.LLVMTypeOf(value), name);
        LLVM.LLVMSetInitializer(globalVar, value);
        return globalVar;
    }

    public LLVMValueRef createAlloca(LLVMEnv env, LLVMValueRef value, String name) {
        return LLVM.LLVMBuildAlloca(builderRef, LLVM.LLVMTypeOf(value), name);
    }

    public LLVMValueRef ops(BinaryOperator op, LLVMValueRef lhs, LLVMValueRef rhs, String name) {
        return op.apply(builderRef, lhs, rhs, name);
    }

}
