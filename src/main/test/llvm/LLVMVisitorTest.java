package llvm;/*
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

import com.google.common.collect.Lists;
import hobbyscript.Exception.ParseException;
import hobbyscript.LLVM.env.LLVMEnv;
import hobbyscript.LLVM.generator.LLVMVisitor;
import hobbyscript.LLVM.util.LLVMs;
import hobbyscript.Lexer.HobbyLexer;
import hobbyscript.Parser.ImportParser;
import hobbyscript.Token.HobbyToken;
import hobbyscript.ast.AstNode;
import hobbyscript.ast.NullStmt;
import org.bytedeco.javacpp.IntPointer;
import org.bytedeco.javacpp.SizeTPointer;
import org.bytedeco.llvm.LLVM.LLVMTypeRef;
import org.bytedeco.llvm.LLVM.LLVMValueRef;
import org.bytedeco.llvm.global.LLVM;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

import java.io.StringReader;
import java.util.List;

public class LLVMVisitorTest {

    @Before
    public void setUp() {

    }

    @Test
    public void testNumberLiteral() throws ParseException {
        LLVMValueRef value = LLVM.LLVMConstReal(LLVM.LLVMDoubleType(), 10);
        double d = LLVM.LLVMConstRealGetDouble(value, new IntPointer(1));
        Assert.assertEquals(10, d, 0.0001);

        List<?> list = runExpr("1;");
        Assert.assertNotNull(list.get(0));

        LLVMValueRef number = (LLVMValueRef) list.get(0);

        Assert.assertEquals(1, LLVM.LLVMConstIntGetSExtValue(number));

        List<?> list1 = runExpr("1.1;");
        Assert.assertNotNull(list1.get(0));

        LLVMValueRef number1 = (LLVMValueRef) list1.get(0);

        Assert.assertEquals(1.1, LLVMs.getDouble(number1), 0.001);
    }

    @Test
    public void testStringLiteral() throws ParseException {
        List<?> list1 = runExpr("\"Test String \\\" .\";");
        Assert.assertNotNull(list1.get(0));

        LLVMValueRef string = (LLVMValueRef) list1.get(0);

        final String expect = "Test String \" .";
//        Assert.assertEquals(expect, LLVM.LLVMGetAsString(string, new SizeTPointer(expect.length())).getString());
    }

    @Test
    public void testIDLiteral() throws ParseException {
        LLVMEnv env = new LLVMEnv() {{
            put("lfkdsk", LLVMs.constString("123321"));
        }};
        List<?> list1 = runExpr("lfkdsk;", env);

        Assert.assertNotNull(list1.get(0));
        LLVMValueRef string = (LLVMValueRef) list1.get(0);

        Assert.assertEquals("123321", LLVM.LLVMGetAsString(string, new SizeTPointer(6)).getString());

        LLVMTypeRef type = LLVMs.stringType();
        LLVM.LLVMDumpModule(env.getModule());
    }

    @Test
    public void testBoolLiteral() throws ParseException {
        List<?> list1 = runExpr("true;");
        Assert.assertNotNull(list1.get(0));

        LLVMValueRef bool = (LLVMValueRef) list1.get(0);

        Assert.assertEquals(1, LLVM.LLVMConstIntGetZExtValue(bool));
    }

    @Test
    public void testNegativeExpr() throws ParseException {
        List<?> list1 = runExpr("-1080;");
        Assert.assertNotNull(list1.get(0));

        LLVMValueRef expr = (LLVMValueRef) list1.get(0);

        Assert.assertEquals(-1080, LLVM.LLVMConstIntGetSExtValue(expr));

        List<?> list2 = runExpr("-1080.1024;");
        LLVMValueRef expr2 = (LLVMValueRef) list2.get(0);
        Assert.assertEquals(-1080.1024, LLVMs.getDouble(expr2), 0.0001);
    }

    @Test
    public void testNegativeBoolExpr() throws ParseException {
        List<?> list1 = runExpr("!true;");
        Assert.assertNotNull(list1.get(0));

        LLVMValueRef expr = (LLVMValueRef) list1.get(0);

        Assert.assertEquals(0, LLVM.LLVMConstIntGetZExtValue(expr));
    }

    @Test
    public void testBinaryExprAssign() throws ParseException {
        LLVMEnv env = new LLVMEnv();
        List<?> list1 = runExpr("lfkdsk = 123321;", env);
        Assert.assertNotNull(list1.get(0));
        LLVMValueRef var = LLVM.LLVMGetNamedGlobal(env.getModule(), "lfkdsk");
        Assert.assertEquals(123321, LLVMs.getInt(LLVM.LLVMGetInitializer(var)));
        LLVM.LLVMDumpModule(env.getModule());
    }

    @Test
    public void testBinaryAddDel() throws ParseException {
        LLVMEnv env = new LLVMEnv();
        List<?> list1 = runExpr("123.00 + 1.0000;", env);
        LLVM.LLVMDumpModule(env.getModule());
        LLVM.LLVMDumpValue((LLVMValueRef) list1.get(0));
    }

    static List<?> runExpr(String input) throws ParseException {
        return runExpr(input, new LLVMEnv());
    }

    static List<?> runExpr(String input, LLVMEnv env) throws ParseException {
        final HobbyLexer lexer = new HobbyLexer(new StringReader(input));
        final ImportParser parser = new ImportParser();
        final LLVMVisitor visitor = new LLVMVisitor();
        final List<Object> result = Lists.newArrayList();

        while (lexer.peek(0) != HobbyToken.EOF) {
            AstNode node = parser.parse(lexer);
            if (node instanceof NullStmt) {
                continue;
            }

            Object value = node.accept(visitor, env);
            result.add(value);
        }

        return result;
    }
}
