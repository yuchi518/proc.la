//
// Created by Yuchi Chen on 2017/8/27.
//

#ifndef PROC_LA_AST_OBJ_H
#define PROC_LA_AST_OBJ_H

#include "mmObj.h"
#include "mmObj_lib.h"

#include "ast.h"

enum {
    AST_NODE     = 0,
    AST_TYPE,
    AST_TYPE_COMBINATION,
    AST_VARABLE,
    AST_VARIABLE_INT,
    AST_VARIABLE_LONG,
    AST_VARIABLE_FLOAT,
    AST_VARIABLE_DOUBLE,
    AST_VARIABLE_NUMBER,
    AST_VARIABLE_STRING,
    AST_VARIABLE_RAW,
    AST_VARIABLE_LIST,
    AST_VARIABLE_MAP,
};


/// ===== Abstract Tree node =====
typedef struct AstNode {
    enum la_ast_typ type;
}*AstNode;

plat_inline AstNode initAstNode(AstNode obj, Unpacker unpkr) {
    obj->type = la_ast_unknown;
    return obj;
}

plat_inline void destroyAstNode(AstNode obj) {

}

plat_inline void packAstNode(AstNode obj, Packer pkr) {

}

MMSubObject(AST_NODE, AstNode, MMObject , initAstNode, destroyAstNode, packAstNode);


/// ===== Ast Type =====
/*
 * One of followings types:
 *  la_ast_type_int
 *  la_ast_type_long
 *  la_ast_type_float
 *  la_ast_type_double
 *  la_ast_type_number
 *  la_ast_type_string
 *  la_ast_type_raw
 *  la_ast_type_var
 *  la_ast_type_proc
 *  la_ast_type_la
 *  la_ast_type_combination (sub type)
 */
typedef struct AstType {

}*AstType;

plat_inline AstType initAstType(AstType obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstType(AstType obj) {

}

plat_inline void packAstType(AstType obj, Packer pkr) {

}

MMSubObject(AST_TYPE, AstType, AstNode , initAstType, destroyAstType, packAstType);

plat_inline AstType allocAstTypeWithType(mgn_memory_pool* pool, enum la_ast_typ type)
{
    AstType obj = allocAstType(pool);
    if (obj)
    {
        toAstNode(obj)->type = type;
    }
    return obj;
}


/// ===== AstTypeCombination =====

typedef struct AstTypeCombination {
    /**
     * combined_type = base_type | ([1 or 2] << (16+0)) | ([1 or 2] << (16+2)) | ... | ([1 or 2] << (16+N))
     * base_type = la_ast_type_int | la_ast_type_long | ... etc.
     * [1 or 2], 1 = array [], 2 = map {}
     * 16 + (0~14), the maximum level of combined type is 8, use 2 bits to maintain each level.
     */
    int32 combined_type;
}*AstTypeCombination;

plat_inline AstTypeCombination initAstTypeCombination(AstTypeCombination obj, Unpacker unpkr) {
    toAstNode(obj)->type = la_ast_type_combination;
    return obj;
}

plat_inline void destroyAstTypeCombination(AstTypeCombination obj) {

}

plat_inline void packAstTypeCombination(AstTypeCombination obj, Packer pkr) {

}

MMSubObject(AST_TYPE_COMBINATION, AstTypeCombination, AstType , initAstTypeCombination, destroyAstTypeCombination, packAstTypeCombination);

plat_inline AstTypeCombination allocAstTypeCombinationWithCombinedType(mgn_memory_pool* pool, int32 combined_type) {
    AstTypeCombination obj = allocAstTypeCombination(pool);
    if (obj) {
        obj->combined_type = combined_type;
    }
    return obj;
}

/// ===== Ast Variable =====
/**
 * One of following variables:
 *  la_ast_inst_int
 *  la_ast_inst_long
 *  la_ast_inst_float
 *  la_ast_inst_double
 *  la_ast_inst_number
 *  la_ast_inst_string
 *  la_ast_inst_raw
 *  la_ast_inst_list
 *  la_ast_inst_map
 */

typedef struct AstVariable {
    bool is_const;
}*AstVariable;

plat_inline AstVariable initAstVariable(AstVariable obj, Unpacker unpkr) {
    obj->is_const = false;
    return obj;
}

plat_inline void destroyAstVariable(AstVariable obj) {

}

plat_inline void packAstVariable(AstVariable obj, Packer pkr) {

}

MMSubObject(AST_VARABLE, AstVariable, AstNode , initAstVariable, destroyAstVariable, packAstVariable);


/// ===== AstVariableInt =====

typedef struct AstVariableInt {
    int32 value;
}*AstVariableInt;

plat_inline AstVariableInt initAstVariableInt(AstVariableInt obj, Unpacker unpkr) {
    toAstNode(obj)->type = la_ast_inst_int;
    return obj;
}

plat_inline void destroyAstVariableInt(AstVariableInt obj) {

}

plat_inline void packAstVariableInt(AstVariableInt obj, Packer pkr) {

}

MMSubObject(AST_VARIABLE_INT, AstVariableInt, AstVariable , initAstVariableInt, destroyAstVariableInt, packAstVariableInt);

plat_inline AstVariableInt allocAstVariableIntWithInt(mgn_memory_pool* pool, int32 value)
{
    AstVariableInt obj = allocAstVariableInt(pool);
    if (obj) {
        obj->value = value;
    }
    return obj;
}


/// ===== Abstract Long Variable =====

typedef struct AstVariableLong {
    int64 value;
}*AstVariableLong;

plat_inline AstVariableLong initAstVariableLong(AstVariableLong obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstVariableLong(AstVariableLong obj) {

}

plat_inline void packAstVariableLong(AstVariableLong obj, Packer pkr) {

}

MMSubObject(AST_VARIABLE_LONG, AstVariableLong, AstVariable , initAstVariableLong, destroyAstVariableLong, packAstVariableLong);

plat_inline AstVariableLong allocAstVariableLongWithLong(mgn_memory_pool* pool, int64 value)
{
    AstVariableLong obj = allocAstVariableLong(pool);
    if (obj) {
        obj->value = value;
    }
    return obj;
}

/// ===== AstVariableFloat =====

typedef struct AstVariableFloat {
    float value;
}*AstVariableFloat;

plat_inline AstVariableFloat initAstVariableFloat(AstVariableFloat obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstVariableFloat(AstVariableFloat obj) {

}

plat_inline void packAstVariableFloat(AstVariableFloat obj, Packer pkr) {

}

MMSubObject(AST_VARIABLE_FLOAT, AstVariableFloat, AstVariable , initAstVariableFloat, destroyAstVariableFloat, packAstVariableFloat);

plat_inline AstVariableFloat allocAstVariableFloatWithValue(mgn_memory_pool* pool, float value)
{
    AstVariableFloat obj = allocAstVariableFloat(pool);
    if (obj) {
        obj->value = value;
    }
    return obj;
}


/// ===== AstVariableDouble =====

typedef struct AstVariableDouble {
    double value;
}*AstVariableDouble;

plat_inline AstVariableDouble initAstVariableDouble(AstVariableDouble obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstVariableDouble(AstVariableDouble obj) {

}

plat_inline void packAstVariableDouble(AstVariableDouble obj, Packer pkr) {

}

MMSubObject(AST_VARIABLE_FLOAT, AstVariableDouble, AstVariable , initAstVariableDouble, destroyAstVariableDouble, packAstVariableDouble);

plat_inline AstVariableDouble alloc(mgn_memory_pool* pool, double value)
{
    AstVariableDouble obj = allocAstVariableDouble(pool);
    if (obj) {
        obj->value = value;
    }
    return obj;
}


/// ===== unitest =====
void unit_test_mmobj(void);



#endif //PROC_LA_AST_OBJ_H
