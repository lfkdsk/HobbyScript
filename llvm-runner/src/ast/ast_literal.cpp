//
// Created by 刘丰恺 on 20/1/2020.
//

#include "ast_literal.h"

AstStringLiteral::AstStringLiteral(const QString& value) {
    if (value.startsWith('"')) {
        this->name = value.mid(1, value.length() - 2);
    } else {
        this->name = value;
    }
    // TODO: escape string.
}
