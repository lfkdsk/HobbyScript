//
// Created by 刘丰恺 on 15/1/2020.
//

#ifndef LLVM_RUNNER_OBJECT_H
#define LLVM_RUNNER_OBJECT_H

#include <cstdint>
#include <string>
#include "ast/ast_let.h"

enum status_t {
    prog,
    def,
    func_def_begin,
    func_def_ret,
    AstCall_func
};

class AstNode;

class AstType;

class TupleType;

AstNode *packageName(AstNode *name);

void packageImport(AstNode *n);

void setPackageLines(AstNode *n);

AstNode *importName(AstNode *n, char *name, bool isFunc = false);

AstNode *stringCat(AstNode *left, AstNode *right);

AstType *getType(int type_id);

AstType *getClassType(char *name, AstType *templateVars = nullptr);

AstType *getFuncType();

AstType *getFuncType(AstType *types, AstType *ret = nullptr);

AstType *makeArray(AstType *type, AstNode *list = nullptr);

AstNode *makeSequence(AstNode *list);

AstNode *makeEmpty();

AstNode *makeNull();

AstLet *let(AstType *type, char *name = nullptr, AstNode *value = nullptr, int flag = 0);

AstLet *let(char *name = nullptr, AstNode *value = nullptr, int flag = 0);

AstNode *unary(int op, AstNode *v);

AstNode *unaryAfter(int op, AstNode *v);

AstNode *binary(int op, AstNode *left, AstNode *right);

AstNode *binaryIs(AstNode *left, AstType *right);

AstNode *link(AstNode *left, AstNode *right);

AstType *link(AstType *left, AstType *right);

AstNode *makeValue(const char *name, int32_t v);

AstNode *makeValue(const char *name, int64_t v);

AstNode *makeValue(const char *name, float v);

AstNode *makeValue(const char *name, double v);

AstNode *makeValue(const char *name, bool v);

AstNode *makeValue(const char *v);

AstNode *getVar(const char *name, bool right = true);

AstNode *makeIf(AstNode *cond, AstNode *block);

AstNode *setElse(AstNode *ifCond, AstNode *elseBlock);

AstNode *makeWhile(AstNode *cond, AstNode *block);

AstNode *makeFor(AstNode *let, AstNode *cond, AstNode *inc, AstNode *block);

AstNode *createFunction(int funcType, const std::string &name, AstNode *parameters, AstNode *ret, AstNode *block);

AstNode *addFunctionBlock(AstNode *, AstNode *block, AstNode *annotation = nullptr);

AstNode *createOperator(int oper, AstNode *variables, AstNode *ret, AstNode *block);

AstType *createInterface(char *name, AstNode *block);

// 返回命令
AstNode *callReturn(AstNode *val = nullptr);

AstNode *makeSplice(AstNode *expr, AstNode *begin, AstNode *end);

AstNode *makeIndex(AstNode *expr, AstNode *index);

// 元组
AstNode *makeTuple(AstNode *elem, AstNode *second);

AstNode *tupleResolve(AstNode *type, AstNode *tuple, bool def = false);

AstNode *makeClass(int type, char *name, AstNode *templateVars, AstType *inherit, AstNode *block);

AstNode *makeConst(char *name, AstNode *value);

AstNode *createSwitch(AstNode *cond, AstNode *lines);

AstNode *createCase(AstNode *cond, AstNode *lines);

/////// try-catch //////////////
AstNode *makeCatch(AstNode *types, char *name, AstNode *lines);

AstNode *createTry(AstNode *block, AstNode *catchs, AstNode *finallyBlock);

/////////// GET, SET ///////////
AstNode *makeGet(char *name, AstNode *block);

AstNode *makeSet(char *name, AstType *type, char *value, AstNode *block);

AstNode *makeBased(AstNode *expr, AstNode *block);

AstNode *setProtected();

AstNode *makeInc(AstNode *expr, bool isInc = true);

AstNode *createEnum(char *name, AstNode *items);

AstNode *makeGetConstValue(char *name, char *value);

AstNode *makeCall(char *name, AstNode *args);

AstNode *makeDelete(AstNode *expr);

AstNode *createNew(AstType *type, char *name, AstNode *block);

AstNode *createDef(AstNode *def);

AstNode *appendDef(AstNode *def, char *name, AstNode *value = nullptr);

AstType *nullAble(AstType *type);

AstNode *annotationdClass(AstNode *annotation, AstNode *cls);

AstNode *makeAnnotation(char *name, AstNode *attrs);

AstNode *makeIsNull(AstNode *value);

AstNode *makeIIF(AstNode *cond, AstNode *thenValue, AstNode *elseValue = nullptr);

AstNode *createGo(AstNode *node);

AstNode *createNode(char *name);

AstNode *makeArrayCall(AstNode *expr, AstNode *func);

AstNode *createNewArray(AstType *type, AstNode *expr);


#endif //LLVM_RUNNER_OBJECT_H
