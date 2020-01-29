//
// Created by 刘丰恺 on 22/1/2020.
//

#ifndef LLVM_RUNNER_AST_TYPE_H
#define LLVM_RUNNER_AST_TYPE_H


#include "common/common.h"
#include "runtime/runtime.h"
#include "common/type_common.h"

static uint32_t type_id_cal = 0;

class AstType {

public:
    explicit AstType(VMTypeID type = AutoTyId) : _type_id(type), id(type_id_cal++), name(type_name(type)) {}

    virtual ~AstType() {}

public:
    virtual VMTypeID type() {
        return _type_id;
    }

    virtual bool is_instance_of(AstType *type);

    virtual QString unique_name();

    virtual size_t hash_code();

    virtual llvm::Type *llvm_type(llvm::LLVMContext &context);

    [[nodiscard]] uint32_t type_id() const;

    virtual CodeGen *malloc(AstContext *context);

    template<typename Iterator>
    static QString unique_name(Iterator begin, Iterator end) {
        QString name;
        for (auto i = begin; i != end; i++) {
            AstType *type = *i;
            name.append(type->unique_name());
        }
        return name;
    }

public:
    QString name;
    bool nullable = false;
    AstType *inherit = nullptr;

    // result value.
private:
    llvm::Type *code_gen_result = nullptr;

public:
    inline void set_codegen_result(llvm::Type *result) {
        this->code_gen_result = result;
    }

    inline llvm::Type *codegen_result() {
        return code_gen_result;
    }

protected:
    size_t hash(size_t o, size_t v);

    const VMTypeID _type_id;
    uint32_t id;

public:
    inline bool is_auto() const { return _type_id == AutoTyId; }

    inline bool is_integer() const { return _type_id == IntegerTyID; }

    inline bool is_float_or_double() const { return _type_id == FloatTyID || _type_id == DoubleTyID; }

    inline bool is_class() const { return _type_id == StructTyID || _type_id == TupleTyId; }

    inline bool is_number() const { return is_integer() || is_float_or_double(); }

    inline bool is_float() const { return _type_id == FloatTyID; }

    inline bool is_double() const { return _type_id == DoubleTyID; }

    inline bool is_string() const { return _type_id == CharactersTyId; }

    [[nodiscard]] VMTypeID get_type_id() const;

    static QString type_name(VMTypeID type) {
        QString name;
        switch (type) {
            case FloatTyID:
                name = "float";
                break;
            case DoubleTyID:
                name = "double";
                break;
            case CharactersTyId:
                name = "characters";
                break;
            case AnyTyId:
                name = "any";
                break;
            case VoidTyID:
                name = "void";
                break;
            case InterfaceTyId:
                name = "interface";
                break;
            case AutoTyId:
                name = "var";
                break;
            case StaticTrueTyId:
                name = "True";
                break;
            case StaticFalseTyId:
                name = "False";
                break;
            default:
                break;
        }
        return name;
    }
};

static AstType *static_true;
static AstType *static_false;
static AstType *string_type;
static AstType *any_type;
static AstType *void_type;
static AstType *float_type;
static AstType *double_type;
static AstType *null_type;

#endif //LLVM_RUNNER_AST_TYPE_H
