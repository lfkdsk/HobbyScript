//
// Created by 刘丰恺 on 23/1/2020.
//

#ifndef LLVM_RUNNER_TYPE_COMMON_H
#define LLVM_RUNNER_TYPE_COMMON_H

#include "visitor/visitor.h"

class AstType;

class AutoType;

class ClassType;

class IntegerType;

/**
* LLVM Type
*/
enum VMTypeID {
    VoidTyID = 0,    ///<  0: type with no size
    HalfTyID,        ///<  1: 16-bit floating point type
    FloatTyID,       ///<  2: 32-bit floating point type
    DoubleTyID,      ///<  3: 64-bit floating point type
    X86_FP80TyID,    ///<  4: 80-bit floating point type (X87)
    FP128TyID,       ///<  5: 128-bit floating point type (112-bit mantissa)
    PPC_FP128TyID,   ///<  6: 128-bit floating point type (two 64-bits, PowerPC)
    LabelTyID,       ///<  7: Labels
    MetadataTyID,    ///<  8: Metadata
    X86_MMXTyID,     ///<  9: MMX vectors (64 bits, X86 specific)
    TokenTyID,       ///< 10: Tokens

    // Derived types... see DerivedTypes.h file.
    // Make sure FirstDerivedTyID stays up to date!
            IntegerTyID,     ///< 11: Arbitrary bit width integers
    FunctionTyID,    ///< 12: Functions
    StructTyID,      ///< 13: Structures
    ArrayTyID,       ///< 14: Arrays
    PointerTyID,     ///< 15: Pointers
    VectorTyID,       ///< 16: SIMD 'packed' format, or other vector type

    AutoTyId = 20,
    CharactersTyId,     /// character string
    AnyTyId,
    InterfaceTyId,
    StaticTrueTyId,
    StaticFalseTyId, /// for static get type
    TupleTyId,
    NullTyId
};


#define TYPE_BASE_LIST() \
      AstType, /* AstType Base Node */ \
      AutoType, ClassType, IntegerType \

#define TYPE_BASE(Type) VisitableImpl<Type, TYPE_BASE_LIST()>

#define TYPE_TYPE_AUTO_DOWNCAST(node, visitor) \
    switch (node->get_type_id()) { \
        case IntegerTyID: { \
            visitor->visit(*dynamic_cast<IntegerType *>(node)); \
            break; \
        } \
    } \


#endif //LLVM_RUNNER_TYPE_COMMON_H
