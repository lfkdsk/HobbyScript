//
// Created by 刘丰恺 on 22/1/2020.
//

#include "integer_type.h"

IntegerType *sBoolean = nullptr;
IntegerType *sByte = nullptr;
IntegerType *sShort = nullptr;
IntegerType *uShort = nullptr;
IntegerType *sInteger = nullptr;
IntegerType *uInteger = nullptr;
IntegerType *sLong = nullptr;
IntegerType *uLong = nullptr;

IntegerType::IntegerType(int bit_width, bool is_unsigned) : AstType(IntegerTyID) {
    switch (bit_width) {
        case 1:
            name = "boolean";
            this->is_unsigned = true;
            break;
        case 8:
            name = "byte";
            this->is_unsigned = true;
            break;
        case 16:
            name = is_unsigned ? "ushort" : "short";
            break;
        case 32:
            name = is_unsigned ? "uint" : "int";
            break;
        case 64:
            name = is_unsigned ? "ulong" : "long";
            break;
        default:
            name = "unknown";
            break;
    }
}

IntegerType *IntegerType::get(int bit_width, bool is_unsigned) {
    switch (bit_width) {
        case 1:
            if (!sBoolean) sBoolean = new IntegerType(1, true);
            return sBoolean;
        case 8:
            if (!sByte) sByte = new IntegerType(8, true);
            return sByte;
        case 16:
            if (is_unsigned) {
                if (!uShort) uShort = new IntegerType(16, true);
                return uShort;
            } else {
                if (!sShort) sShort = new IntegerType(16, false);
                return sShort;
            }
        case 32:
            if (is_unsigned) {
                if (!uInteger) uInteger = new IntegerType(32, true);
                return uInteger;
            } else {
                if (!sInteger) sInteger = new IntegerType(32, false);
                return sInteger;
            }
        case 64:
            if (is_unsigned) {
                if (!uLong) uLong = new IntegerType(64, true);
                return uLong;
            } else {
                if (!sLong) sLong = new IntegerType(64, false);
                return sLong;
            }
        default:
            return nullptr;
    }
}

QString IntegerType::unique_name() {
    switch (bit_width) {
        case 1:
            return "_N"; // bool
        case 8:
            return is_unsigned ? "E" : "D";
        case 16:
            return is_unsigned ? "G" : "F";
        case 32:
            return is_unsigned ? "I" : "H";
        case 64:
            return is_unsigned ? "K" : "J";
        default:
            break;
    }
    return name;
}
