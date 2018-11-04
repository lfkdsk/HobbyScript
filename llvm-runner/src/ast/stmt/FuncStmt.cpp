//
// Created by 刘丰恺 on 2018/8/8.
//

#include "FuncStmt.h"

FuncStmt::FuncStmt(const json &load_json, pointer<ast_node_list> children)
        : ast_list(load_json, children) {
    
}
