//
// Created by 刘丰恺 on 2018/8/8.
//

#include "FuncStmt.h"

FuncStmt::FuncStmt(const json &load_json, pointer<AstNodeList> children)
        : AstList(load_json, children) {
    
}
