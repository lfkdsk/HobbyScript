//
// Created by 刘丰恺 on 19/1/2020.
//

#include "common.h"

RuntimeError create_runtime_error(const QString &message) {
    return RuntimeError(message.toStdString());
}