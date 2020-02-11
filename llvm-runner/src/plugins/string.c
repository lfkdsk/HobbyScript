//
// Created by 刘丰恺 on 7/2/2020.
//

#include "string.h"

HyStringObject *HNI_StringObject_FromString(char *str, uint64_t size) {
    HyStringObject *self;
    size_t len;

    len = size * sizeof(wchar_t);
    self = (HyStringObject *) hyobject_malloc(sizeof(HyStringObject));
    HyObject_INIT_VAR(self, (int32_t) CharactersTyId, size);
    self->length = size;
    self->data = malloc((size + 1) * sizeof(wchar_t));
    memcpy(self->data, str, len + 1);

    if (is_debug) {
        wprintf(L"\r\nCreate String(data, %lld): %.*ls From String\r\n", self->length, (int) self->length, self->data);
    }

    return self;
}

HyVarObject *HNI_StringObject_FromSize(size_t len) {
    HyStringObject *ptr = hyobject_malloc(sizeof(HyStringObject) + len);
    HyObject_INIT_VAR(ptr, (int32_t) CharactersTyId, len);
    return (HyVarObject *) ptr;
}

HyVarObject *HNI_StringObject_FromHyString(HyStringObject *that) {
    HyStringObject *self = hyobject_malloc(sizeof(HyStringObject) + that->length);
    HyObject_INIT_VAR(self, (int32_t) CharactersTyId, that->length);
    memcpy(self->data, that->data, that->length + 1);
    return (HyVarObject *) self;
}

void HNI_StringObject_Init(HyStringObject *self, char *data, uint64_t length) {
    size_t len = length * sizeof(wchar_t);
    HyObject_INIT_VAR(self, (int32_t) CharactersTyId, length);
    self->data = malloc((length + 1) * sizeof(wchar_t));
    memcpy(self->data, data, len + 1);
    self->length = length;
    if (is_debug) {
        wprintf(L"\r\nInit String(data, %lld): %.*ls\r\n", length, (int) length, self->data);
    }
}

void HNI_StringObject_Finalize(HyStringObject *self) {
    if (self && self->data) {
        free(self->data);
    }
    hyobject_free(self);
}

void HNI_StringObject_Print(HyStringObject *self) {
    wchar_t *data = (wchar_t *) self->data;
    uint64_t len = self->length;
    wprintf(L"%.*ls\r\n", (int) len, data);
}