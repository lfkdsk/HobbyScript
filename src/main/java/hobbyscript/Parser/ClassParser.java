package hobbyscript.Parser;

import hobbyscript.Ast.ClassBody;
import hobbyscript.Ast.ClassStmt;
import hobbyscript.Ast.Dot;
import hobbyscript.Token.HobbyToken;

/**
 * CLASS PARSER
 *
 * @author liufengkai
 *         Created by liufengkai on 16/7/21.
 */
public class ClassParser extends ClosureParser {
//    BnfParser classLocal = BnfParser.rule().sep("local")
//            .or(simple, def);
//
//    BnfParser classOpen = BnfParser.rule().or();

    ///////////////////////////////////////////////////////////////////////////
    // member = simple | function
    ///////////////////////////////////////////////////////////////////////////
    BnfParser member = BnfParser.rule().or(simple, def);

    ///////////////////////////////////////////////////////////////////////////
    // classBody = { [member] | [member] ; }
    ///////////////////////////////////////////////////////////////////////////
    BnfParser classBody = BnfParser.rule(ClassBody.class)
            .sep(LC_TOKEN)
            .option(member)
            .repeat(BnfParser.rule().sep(SEMICOLON_TOKEN, HobbyToken.EOL).option(member))
            .sep(RC_TOKEN);

    ///////////////////////////////////////////////////////////////////////////
    // classDefine = class xxx [extend xxx] classBody
    ///////////////////////////////////////////////////////////////////////////
    BnfParser classDefine = BnfParser.rule(ClassStmt.class)
            .sep(CLASS_TOKEN).identifier(reserved)
            .option(BnfParser.rule().sep(EXTEND_TOKEN).identifier(reserved))
            .ast(classBody);

    public ClassParser() {
        reserved.add(CLASS_TOKEN);
        reserved.add(EXTEND_TOKEN);
        reserved.add(DOT_TOKEN);
//        reserved.add(INITIAL);
//        reserved.add(THIS_POINT);

        postfix.insertChoice(BnfParser.rule(Dot.class).sep(DOT_TOKEN).identifier(reserved));

        program.insertChoice(classDefine);
    }
}
