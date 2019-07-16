package hobbyscript.Parser;

import hobbyscript.ast.ArrayIndex;
import hobbyscript.Literal.ArrayLiteral;
import hobbyscript.Literal.CreateArray;

/**
 * 支持数组
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/23.
 */
public class ArrayParser extends ClassParser {

    ///////////////////////////////////////////////////////////////////////////
    // element = expr { , expr } 数组元素
    ///////////////////////////////////////////////////////////////////////////
    BnfParser element = BnfParser.rule(ArrayLiteral.class)
            .ast(expr).repeat(BnfParser.rule().sep(COMMA).ast(expr));

    ///////////////////////////////////////////////////////////////////////////
    // createArray = < xxx , 100 > 使用数字或者id创建指定大小数组 不支持表达式
    ///////////////////////////////////////////////////////////////////////////
    BnfParser createArray = BnfParser.rule(CreateArray.class)
            .or(number, id);

    public ArrayParser() {
        reserved.add(LM_TOKEN);
        reserved.add(RM_TOKEN);

        // primary = [ [ element ] ];
        primary.insertChoice(BnfParser.rule().sep(LM_TOKEN).maybe(element)
                .sep(RM_TOKEN));

        primary.insertChoice(BnfParser.rule().sep(LS_TOKEN).ast(createArray)
                .sep(RS_TOKEN));

        // postfix = [ expr ];
        postfix.insertChoice(BnfParser.rule(ArrayIndex.class)
                .sep(LM_TOKEN).ast(expr).sep(RM_TOKEN));
    }
}
