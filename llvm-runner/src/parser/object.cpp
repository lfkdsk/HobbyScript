//
// Created by 刘丰恺 on 16/1/2020.
//

#include "object.h"

template<typename T = AstLet, typename L>
inline bool forEach(AstNode *node, L func, bool autoDelete = false) {
    if (!node) {
        return false;
    }
    auto *p = dynamic_cast<AstList *>(node);
    if (p) {
        for (auto *i : p->lines) {
            if (auto x = dynamic_cast<T *>(i); x) {
                func(x);
                if (autoDelete) {
                    delete x;
                }
            }
        }
        delete p;
        return true;
    } else {
        auto x = dynamic_cast<T *>(node);
        if (x) {
            func(x);
            if (autoDelete) {
                delete x;
            }
        }
        return false;
    }
}

/**
 * Trans Lines To Block.
 * @tparam T
 * @param block vector.
 * @param origin node.
 */
template<typename T>
inline void transLinesToBlock(QVector<T *> &block, AstNode *x) {
    forEach(x, [block](T *i) {
        block.push_back(i);
    });
}

/**
 * Trans Lines To Block.
 * @tparam T
 * @param block vector.
 * @param origin node.
 */
inline void transLinesToBlock(QVector<AstNode *> &block, AstNode *x) {
    if (!x) {
        return;
    }

    auto *p = dynamic_cast<AstList *>(x);
    if (p) {
        block = std::move(p->lines);
        delete x;
    } else {
        block.push_back(x);
    }
}

/**
 * Ast create node.
 * @param name str name.
 * @return AstNode.
 */
AstNode *createNode(char *name) {
    return new AstNode(name);
}

/**
 * Ast int Value.
 * @param name value name.
 * @param v int 32 bit value.
 * @return AstIntegerConstant.
 */
AstNode *makeValue(const char *name, int32_t v) {
    auto *a = new AstIntegerConstant(name);
    a->set_value(v);
    return a;
}

/**
 * Ast int Value.
 * @param name value name.
 * @param v int 64 bit value.
 * @return AstIntegerConstant.
 */
AstNode *makeValue(const char *name, int64_t v) {
    auto *constant = new AstIntegerConstant(QString(name));
    constant->set_value(v);
    return constant;
}

/**
 * Ast float Value.
 * @param name value name.
 * @param float value.
 * @return AstFloatConstant.
 */
AstNode *makeValue(const char *name, float v) {
    auto *constant = new AstFloatConstant(QString(name), v, false);
    return constant;
}

/**
 * Ast double Value.
 * @param name value name.
 * @param double value.
 * @return AstFloatConstant.
 */
AstNode *makeValue(const char *name, double v) {
    auto *constant = new AstFloatConstant(QString(name), v, true);
    return constant;
}

/**
 * Ast double Value.
 * @param name value name.
 * @param bool value.
 * @return AstBoolConstant.
 */
AstNode *makeValue(const char *name, bool v) {
    auto *constant = new AstBoolConstant(QString(name), v);
    return constant;
}

/**
 * Ast string Value.
 * @param name value name.
 * @param string value.
 * @return AstStringLiteral.
 */
AstNode *makeValue(const char *v) {
    return new AstStringLiteral(v);
}

/**
 * Insert AstNode Into
 * @param names
 * @return
 */
AstNode *packageName(AstNode *names) {
    forEach(names, [](AstNode *item) {
        ast_current_package->names.push_back(std::move(item->name));
    }, true);
    return nullptr;
}

/**
 * Create Lexical Var
 * @param type AstType
 * @param name Var Name
 * @param value Value
 * @param flag
 * @return AstLet
 */
AstNode *let(AstType *type, char *name, AstNode *value, int flag) {
    auto *let = new AstLet();
    let->var_type = type;
    let->var_expr = value;
    let->name = QString(name);
    let->flag = flag;
    return let;
}

AstNode *let(char *name, AstNode *value, int flag) {
    return let(nullptr, name, value, flag);
}

void packageImport(AstNode *n) {

}

void setPackageLines(AstNode *n) {
    transLinesToBlock(ast_current_package->lines, n);
}

AstNode *link(AstNode *left, AstNode *right) {
    auto *p = dynamic_cast<AstList *>(left);
    if (!p) {
        p = new AstList();
        p->lines.push_back(left);
    }
    p->lines.push_back(right);
    return p;
}

AstType *link(AstType *left, AstType *right) {
    return nullptr;
}

AstType *getType(int type_id) {
    //"var"	        yylval.type = 0;	return ITYPE;
    //"bool"		yylval.type = 1;	return ITYPE;
    //"byte"		yylval.type = 2;	return ITYPE;
    //"char"		yylval.type = 3;	return ITYPE;
    //"short"		yylval.type = 4;	return ITYPE;
    //"int"		    yylval.type = 5;	return ITYPE;
    //"long"		yylval.type = 6;	return ITYPE;
    //"float"		yylval.type = 7;	return ITYPE;
    //"double"	    yylval.type = 8;	return ITYPE;
    //"string"	    yylval.type = 9;	return ITYPE;
    //"any"		    yylval.type = 10;	return ITYPE;

    switch (type_id) {
        case 0:
            return new AutoType();
        case 1:// bool
            return IntegerType::get(1);
        case 2:// byte
            return IntegerType::get(8, true);
        case 3:// char
            return IntegerType::get(8);    // unsigned
        case 4:// short
            return IntegerType::get(16);
        case 5:// int
            return IntegerType::get(32);
        case 6:// long
            return IntegerType::get(64);
        case 7:// float
            return float_type;
        case 8:// double
            return double_type;
        case 9:// string
            return string_type;
        case 10:// any
            return any_type;
        case 11:// ushort
            return IntegerType::get(16, true);
        case 12:// uint
            return IntegerType::get(32, true);
        case 13:// ulong
            return IntegerType::get(64, true);
        default:
            throw create_runtime_error("unknown type: " + QString(type_id));
    }
}

AstNode *createDef(AstNode *def) {
    auto *let = dynamic_cast<AstLet *>(def);
    auto *p = new AstDef();
    p->type = let->var_type;
    p->vars.append(qMakePair(let->name, let->var_expr));
    delete def; // remove origin let node.
    return p;
}

AstNode *importName(AstNode *n, char *name, bool isFunc) {
    return nullptr;
}

AstNode *stringCat(AstNode *left, AstNode *right) {
    return nullptr;
}

AstType *getClassType(char *name, AstType *templateVars) {
    return nullptr;
}

AstType *getFuncType() {
    return nullptr;
}

AstType *getFuncType(AstType *types, AstType *ret) {
    return nullptr;
}

AstType *makeArray(AstType *type, AstNode *list) {
    return nullptr;
}

AstNode *makeSequence(AstNode *list) {
    return nullptr;
}

AstNode *makeEmpty() {
    return nullptr;
}

AstNode *makeNull() {
    return nullptr;
}

AstNode *unary(int op, AstNode *v) {
    return nullptr;
}

AstNode *unaryAfter(int op, AstNode *v) {
    return nullptr;
}

AstNode *binary(int op, AstNode *left, AstNode *right) {
    return nullptr;
}

AstNode *binaryIs(AstNode *left, AstType *right) {
    return nullptr;
}

AstNode *getVar(const char *name, bool right) {
    return nullptr;
}

AstNode *makeIf(AstNode *cond, AstNode *block) {
    return nullptr;
}

AstNode *setElse(AstNode *ifCond, AstNode *elseBlock) {
    return nullptr;
}

AstNode *makeWhile(AstNode *cond, AstNode *block) {
    return nullptr;
}

AstNode *makeFor(AstNode *let, AstNode *cond, AstNode *inc, AstNode *block) {
    return nullptr;
}

AstNode *createFunction(int funcType, const std::string &name, AstNode *parameters, AstNode *ret, AstNode *block) {
    return nullptr;
}

AstNode *addFunctionBlock(AstNode *, AstNode *block, AstNode *annotation) {
    return nullptr;
}

AstNode *createOperator(int oper, AstNode *variables, AstNode *ret, AstNode *block) {
    return nullptr;
}

AstType *createInterface(char *name, AstNode *block) {
    return nullptr;
}

AstNode *callReturn(AstNode *val) {
    return nullptr;
}

AstNode *makeSplice(AstNode *expr, AstNode *begin, AstNode *end) {
    return nullptr;
}

AstNode *makeIndex(AstNode *expr, AstNode *index) {
    return nullptr;
}

AstNode *makeTuple(AstNode *elem, AstNode *second) {
    return nullptr;
}

AstNode *tupleResolve(AstNode *type, AstNode *tuple, bool def) {
    return nullptr;
}

AstNode *makeClass(int type, char *name, AstNode *templateVars, AstType *inherit, AstNode *block) {
    return nullptr;
}

AstNode *makeConst(char *name, AstNode *value) {
    return nullptr;
}

AstNode *createSwitch(AstNode *cond, AstNode *lines) {
    return nullptr;
}

AstNode *createCase(AstNode *cond, AstNode *lines) {
    return nullptr;
}

AstNode *makeCatch(AstNode *types, char *name, AstNode *lines) {
    return nullptr;
}

AstNode *createTry(AstNode *block, AstNode *catchs, AstNode *finallyBlock) {
    return nullptr;
}

AstNode *makeGet(char *name, AstNode *block) {
    return nullptr;
}

AstNode *makeSet(char *name, AstType *type, char *value, AstNode *block) {
    return nullptr;
}

AstNode *makeBased(AstNode *expr, AstNode *block) {
    return nullptr;
}

AstNode *setProtected() {
    return nullptr;
}

AstNode *makeInc(AstNode *expr, bool isInc) {
    return nullptr;
}

AstNode *createEnum(char *name, AstNode *items) {
    return nullptr;
}

AstNode *makeGetConstValue(char *name, char *value) {
    return nullptr;
}

AstNode *makeCall(char *name, AstNode *args) {
    return nullptr;
}

AstNode *makeDelete(AstNode *expr) {
    return nullptr;
}

AstNode *createNew(AstType *type, char *name, AstNode *block) {
    return nullptr;
}

AstNode *appendDef(AstNode *def, char *name, AstNode *value) {
    return nullptr;
}

AstType *nullAble(AstType *type) {
    return nullptr;
}

AstNode *annotationdClass(AstNode *annotation, AstNode *cls) {
    return nullptr;
}

AstNode *makeAnnotation(char *name, AstNode *attrs) {
    return nullptr;
}

AstNode *makeIsNull(AstNode *value) {
    return nullptr;
}

AstNode *makeIIF(AstNode *cond, AstNode *thenValue, AstNode *elseValue) {
    return nullptr;
}

AstNode *createGo(AstNode *node) {
    return nullptr;
}

AstNode *makeArrayCall(AstNode *expr, AstNode *func) {
    return nullptr;
}

AstNode *createNewArray(AstType *type, AstNode *expr) {
    return nullptr;
}
