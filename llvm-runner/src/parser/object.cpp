//
// Created by 刘丰恺 on 16/1/2020.
//

#include "object.h"

template< typename T = AstLet, typename L>
inline bool forEach(AstNode* node, L func, bool autoDelete = false)
{
    if (!node) {
        return false;
    }
    auto* p = dynamic_cast<AstList*>(node);
    if (p) {
        for (auto* i : p->lines) {
            if (auto x = dynamic_cast<T*>(i); x) {
                func(x);
                if (autoDelete) delete x;
            }
        }
        delete p;
        return true;
    }
    else {
        auto x = dynamic_cast<T*>(node);
        if (x) {
            func(x);
            if (autoDelete) delete x;
        }
        return false;
    }
    return false;
}

AstNode *packageName(AstNode *name) {
    return nullptr;
}

void packageImport(AstNode *n) {

}

void setPackageLines(AstNode *n) {

}

AstNode *importName(AstNode *n, char *name, bool isFunc) {
    return nullptr;
}

AstNode *stringCat(AstNode *left, AstNode *right) {
    return nullptr;
}

AstType *getType(int type_id) {
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

AstNode *let(AstType *type, char *name, AstNode *value, int flag) {
    return nullptr;
}

AstNode *let(char *name, AstNode *value, int flag) {
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

AstNode *link(AstNode *left, AstNode *right) {
    return nullptr;
}

AstType *link(AstType *left, AstType *right) {
    return nullptr;
}

AstNode *makeValue(const char *name, int32_t v) {
    return nullptr;
}

AstNode *makeValue(const char *name, int64_t v) {
    return nullptr;
}

AstNode *makeValue(const char *name, float v) {
    return nullptr;
}

AstNode *makeValue(const char *name, double v) {
    return nullptr;
}

AstNode *makeValue(const char *name, bool v) {
    return nullptr;
}

AstNode *makeValue(const char *v) {
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

AstNode *createDef(AstNode *def) {
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

AstNode *createNode(char *name) {
    return nullptr;
}

AstNode *makeArrayCall(AstNode *expr, AstNode *func) {
    return nullptr;
}

AstNode *createNewArray(AstType *type, AstNode *expr) {
    return nullptr;
}
