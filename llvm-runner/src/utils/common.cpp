//
// Created by 刘丰恺 on 19/1/2020.
//

#include "common.h"

RuntimeError createRuntimeError(const QString &message) {
    return RuntimeError(message.toStdString());
}