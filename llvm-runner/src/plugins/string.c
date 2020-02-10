//
// Created by 刘丰恺 on 7/2/2020.
//

#include "string.h"

HyVarObject *HNI_StringObject_FromString(const char *str) {
    size_t len = strlen(str);
    HyStringObject *this = hyobject_malloc(sizeof(HyStringObject) + len);
    HyObject_INIT_VAR(this, (int32_t) CharactersTyId, len);
    memcpy(this->data, str, len + 1);
    return (HyVarObject *) this;
}

HyVarObject *HNI_StringObject_FromSize(size_t len) {
    HyStringObject *ptr = hyobject_malloc(sizeof(HyStringObject) + len);
    HyObject_INIT_VAR(ptr, (int32_t) CharactersTyId, len);
    return (HyVarObject *) ptr;
}

HyVarObject *HNI_StringObject_FromHyString(HyStringObject *that) {
    HyStringObject *this = hyobject_malloc(sizeof(HyStringObject) + that->length);
    HyObject_INIT_VAR(this, (int32_t) CharactersTyId, that->length);
    memcpy(this->data, that->data, that->length + 1);
    return (HyVarObject *) this;
}

void HNI_StringObject_Init(HyStringObject *this, char *data, uint64_t length) {
    HyObject_INIT_VAR(this, (int32_t) CharactersTyId, length);
    memcpy(this->data, data, length + 1);

    if (is_debug) {
        wprintf(L"\r\nInit String(data, %lld): %.*ls\r\n", length, (int) length, this->data);
    }
}

void HNI_StringObject_Finalize(HyStringObject *this) {
    hyobject_free(this);
}

void HNI_StringObject_Print(HyStringObject *this) {
    if (!this || this->length) {
        return;
    }

    wprintf(L"%.*ls", (int) this->length, this->data);
}