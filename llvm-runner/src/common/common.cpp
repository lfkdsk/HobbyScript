//
// Created by 刘丰恺 on 19/1/2020.
//

#include "common.h"

RuntimeError create_runtime_error(const QString &message) {
    return RuntimeError(message.toUtf8().toStdString());
}

QString point_to_str(void *p) {
    static const char *hex = "0123456789abcdef";
    auto v = (int32_t) (intptr_t) p;
    QString x = "dot";
    for (int i = 28; i > 0; i -= 4) {
        x.append(hex[(v >> i) & 0xf]);
    }
    return x;
}
