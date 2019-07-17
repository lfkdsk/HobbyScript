package hobbyscript.LLVM.util;

import org.bytedeco.llvm.LLVM.LLVMValueRef;
import org.junit.Test;

import static org.junit.Assert.assertTrue;

public class LLVMsTest {

    @Test
    public void testLLVMTypeCheck() {
        LLVMValueRef value = LLVMs.constString("lfkdsk");
        assertTrue(LLVMs.isString(value));
    }
}