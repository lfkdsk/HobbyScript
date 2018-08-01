#include <utility>

//
// Created by 刘丰恺 on 2018/8/1.
//

#include "AstVisitor.h"
#include <UnitTest++/UnitTest++.h>

AstVisitor::AstVisitor(json load) {
    this->load_json = std::move(load);
}

AstVisitor::~AstVisitor() {
    this->load_json.clear();
}

json AstVisitor::get_json() {
    return load_json;
}

void AstVisitor::visit_number(json json_object) {

}
