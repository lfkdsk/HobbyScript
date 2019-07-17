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
import hobbyscript.LLVM.test.TestLLVMVisitor;
import hobbyscript.Lexer.HobbyLexer;
import hobbyscript.Parser.ImportParser;
import hobbyscript.Token.HobbyToken;
import hobbyscript.ast.AstNode;
import hobbyscript.ast.NullStmt;
import org.bytedeco.javacpp.IntPointer;
import org.bytedeco.javacpp.SizeTPointer;
import org.bytedeco.llvm.LLVM.LLVMValueRef;
import org.bytedeco.llvm.global.LLVM;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

import java.io.StringReader;
import java.util.List;

public class LLVMVisitorTest {
    private TestLLVMVisitor visitor;

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

        Assert.assertEquals(1, LLVM.LLVMConstIntGetZExtValue(number));

        List<?> list1 = runExpr("1.1;");
        Assert.assertNotNull(list1.get(0));

        LLVMValueRef number1 = (LLVMValueRef) list1.get(0);

        Assert.assertEquals(1.1, LLVM.LLVMConstRealGetDouble(number1, new IntPointer(1)), 0.001);
    }

    @Test
    public void testStringLiteral() throws ParseException {
        List<?> list1 = runExpr("\"Test String \\\" .\";");
        Assert.assertNotNull(list1.get(0));

        LLVMValueRef string = (LLVMValueRef) list1.get(0);

        final String expect = "Test String \" .";
        Assert.assertEquals(expect, LLVM.LLVMGetAsString(string, new SizeTPointer(expect.length())).getString());
    }

    static List<?> runExpr(String input) throws ParseException {
        final HobbyLexer lexer = new HobbyLexer(new StringReader(input));
        final ImportParser parser = new ImportParser();
        final TestLLVMVisitor visitor = new TestLLVMVisitor(new LLVMVisitor());
        final LLVMEnv env = new LLVMEnv();
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
