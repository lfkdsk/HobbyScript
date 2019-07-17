package hobbyscript.LLVM.util;
/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

import org.bytedeco.javacpp.*;
import org.bytedeco.llvm.LLVM.*;
import org.bytedeco.llvm.global.LLVM;

import static org.bytedeco.llvm.global.LLVM.LLVMDoubleTypeKind;

public final class LLVMs {
    private LLVMs() throws IllegalAccessException {
        throw new IllegalAccessException("illegal constructor");
    }

    public static LLVMTypeRef intType() {
        return LLVM.LLVMInt64Type();
    }

    public static LLVMTypeRef doubleType() {
        return LLVM.LLVMDoubleType();
    }

    private static LLVMTypeRef stringType;

    public static LLVMTypeRef stringType() {
        if (stringType == null) {
            LLVMTypeRef structure = LLVM.LLVMStructCreateNamed(LLVM.LLVMGetGlobalContext(), "String");
            LLVM.LLVMStructSetBody(
                    structure,
                    new PointerPointer<>(
                            LLVM.LLVMInt32Type(),
                            LLVM.LLVMPointerType(LLVM.LLVMInt8Type(), 0)
                    ),
                    2,
                    0
            );

            stringType = structure;
        }

        return stringType;
    }

    public static LLVMValueRef constInt(long number) {
        return LLVM.LLVMConstInt(intType(), number, 1);
    }

    public static LLVMValueRef constDouble(double number) {
        return LLVM.LLVMConstReal(doubleType(), number);
    }

    public static LLVMValueRef constString(String value) {
        return LLVM.LLVMConstString(value, value.length(), 1);
    }

    public static LLVMValueRef createString(String value) {
        return LLVM.LLVMConstNamedStruct(stringType(), new PointerPointer<>(
                        LLVM.LLVMConstInt(intType(), value.length(), 1),
                        Char
                ),
                2);
    }

    public static LLVMValueRef constBool(boolean bool) {
        return LLVM.LLVMConstInt(LLVM.LLVMInt1Type(), bool ? 1 : 0, 0);
    }

    public static boolean getBool(LLVMValueRef ref) {
        return LLVM.LLVMConstIntGetSExtValue(ref) == 1;
    }

    public static double getDouble(LLVMValueRef ref) {
        return LLVM.LLVMConstRealGetDouble(ref, new int[]{0});
    }

    public static long getInt(LLVMValueRef ref) {
        return LLVM.LLVMConstIntGetZExtValue(ref);
    }

    public static String getString(LLVMValueRef ref, long size) {
        return LLVM.LLVMGetAsString(ref, new SizeTPointer(size)).getString();
    }

    public static boolean isInteger(LLVMValueRef ref) {
        return LLVM.LLVMGetIntTypeWidth(LLVM.LLVMTypeOf(ref)) == 64;
    }

    public static boolean isDouble(LLVMValueRef ref) {
        return LLVM.LLVMGetTypeKind(LLVM.LLVMTypeOf(ref)) == LLVMDoubleTypeKind;
    }

    public static boolean isBool(LLVMValueRef ref) {
        return LLVM.LLVMGetIntTypeWidth(LLVM.LLVMTypeOf(ref)) == 1;
    }

    public static boolean isString(LLVMValueRef ref) {
        return LLVM.LLVMIsConstantString(ref) == 1;
    }


}
