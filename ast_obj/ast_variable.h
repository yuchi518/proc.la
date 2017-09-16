//
// Created by Yuchi Chen on 2017/9/16.
//

#ifndef PROC_LA_AST_VARIABLE_H
#define PROC_LA_AST_VARIABLE_H

#include "ast_node.h"

/// ===== Variable =====
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

MMSubObject(AST_VARIABLE, AstVariable, AstNode , initAstVariable, destroyAstVariable, packAstVariable);


/// ===== Variable - Integer =====

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

plat_inline AstVariableInt allocAstVariableIntWithValue(mgn_memory_pool* pool, int32 value)
{
    AstVariableInt obj = allocAstVariableInt(pool);
    if (obj) {
        obj->value = value;
    }
    return obj;
}

plat_inline AstVariableInt allocAstVariableIntWithConstValue(mgn_memory_pool* pool, int32 value)
{
    AstVariableInt obj = allocAstVariableInt(pool);
    if (obj) {
        obj->value = value;
        toAstVariable(obj)->is_const = true;
    }
    return obj;
}


/// ===== Variable - Long =====

typedef struct AstVariableLong {
    int64 value;
}*AstVariableLong;

plat_inline AstVariableLong initAstVariableLong(AstVariableLong obj, Unpacker unpkr) {
    toAstNode(obj)->type = la_ast_inst_long;
    return obj;
}

plat_inline void destroyAstVariableLong(AstVariableLong obj) {

}

plat_inline void packAstVariableLong(AstVariableLong obj, Packer pkr) {

}

MMSubObject(AST_VARIABLE_LONG, AstVariableLong, AstVariable , initAstVariableLong, destroyAstVariableLong, packAstVariableLong);

plat_inline AstVariableLong allocAstVariableLongWithValue(mgn_memory_pool* pool, int64 value)
{
    AstVariableLong obj = allocAstVariableLong(pool);
    if (obj) {
        obj->value = value;
    }
    return obj;
}

plat_inline AstVariableLong allocAstVariableLongWithConstValue(mgn_memory_pool* pool, int64 value)
{
    AstVariableLong obj = allocAstVariableLong(pool);
    if (obj) {
        obj->value = value;
        toAstVariable(obj)->is_const = true;
    }
    return obj;
}

/// ===== Variable - Float =====

typedef struct AstVariableFloat {
    float value;
}*AstVariableFloat;

plat_inline AstVariableFloat initAstVariableFloat(AstVariableFloat obj, Unpacker unpkr) {
    toAstNode(obj)->type = la_ast_inst_float;
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

plat_inline AstVariableFloat allocAstVariableFloatWithConstValue(mgn_memory_pool* pool, float value)
{
    AstVariableFloat obj = allocAstVariableFloat(pool);
    if (obj) {
        obj->value = value;
        toAstVariable(obj)->is_const = true;
    }
    return obj;
}

/// ===== Variable - Double =====

typedef struct AstVariableDouble {
    double value;
}*AstVariableDouble;

plat_inline AstVariableDouble initAstVariableDouble(AstVariableDouble obj, Unpacker unpkr) {
    toAstNode(obj)->type = la_ast_inst_double;
    return obj;
}

plat_inline void destroyAstVariableDouble(AstVariableDouble obj) {

}

plat_inline void packAstVariableDouble(AstVariableDouble obj, Packer pkr) {

}

MMSubObject(AST_VARIABLE_DOUBLE, AstVariableDouble, AstVariable , initAstVariableDouble, destroyAstVariableDouble, packAstVariableDouble);

plat_inline AstVariableDouble allocAstVariableDoubleWithValue(mgn_memory_pool* pool, double value)
{
    AstVariableDouble obj = allocAstVariableDouble(pool);
    if (obj) {
        obj->value = value;
    }
    return obj;
}

plat_inline AstVariableDouble allocAstVariableDoubleWithConstValue(mgn_memory_pool* pool, double value)
{
    AstVariableDouble obj = allocAstVariableDouble(pool);
    if (obj) {
        obj->value = value;
        toAstVariable(obj)->is_const = true;
    }
    return obj;
}

/// ===== Variable - Number =====

typedef struct AstVariableNumber {
    /// TODO: implementation
}*AstVariableNumber;

plat_inline AstVariableNumber initAstVariableNumber(AstVariableNumber obj, Unpacker unpkr) {
    toAstNode(obj)->type = la_ast_inst_number;
    return obj;
}

plat_inline void destroyAstVariableNumber(AstVariableNumber obj) {

}

plat_inline void packAstVariableNumber(AstVariableNumber obj, Packer pkr) {

}

MMSubObject(AST_VARIABLE_NUMBER, AstVariableNumber, AstVariable , initAstVariableNumber, destroyAstVariableNumber, packAstVariableNumber);

plat_inline AstVariableNumber allocAstVariableNumberWithDoubleValue(mgn_memory_pool* pool, double value)
{
    AstVariableNumber obj = allocAstVariableNumber(pool);
    if (obj) {
        /// TODO: implementation
    }
    return obj;
}


/// ===== Variable - String =====

typedef struct AstVariableString {
    MMString string;
}*AstVariableString;

plat_inline AstVariableString initAstVariableString(AstVariableString obj, Unpacker unpkr) {
    toAstNode(obj)->type = la_ast_inst_string;
    return obj;
}

plat_inline void destroyAstVariableString(AstVariableString obj) {
    if (obj->string) {
        release_mmobj(obj->string);
    }
}

plat_inline void packAstVariableString(AstVariableString obj, Packer pkr) {

}

MMSubObject(AST_VARIABLE_STRING, AstVariableString, AstVariable , initAstVariableString, destroyAstVariableString, packAstVariableString);

plat_inline AstVariableString allocAstVariableStringWithCString(mgn_memory_pool* pool, char* cstring)
{
    AstVariableString obj = allocAstVariableString(pool);
    if (obj) {
        obj->string = allocMMStringWithCString(pool, cstring);
    }
    return obj;
}

plat_inline AstVariableString allocAstVariableStringWithConstCString(mgn_memory_pool* pool, char* cstring)
{
    AstVariableString obj = allocAstVariableString(pool);
    if (obj) {
        obj->string = allocMMStringWithCString(pool, cstring);
        toAstVariable(obj)->is_const = true;
    }
    return obj;
}

/// ===== Variable - Raw =====

typedef struct AstVariableRaw {
    MMData data;
}*AstVariableRaw;

plat_inline AstVariableRaw initAstVariableRaw(AstVariableRaw obj, Unpacker unpkr) {
    toAstNode(obj)->type = la_ast_inst_raw;
    return obj;
}

plat_inline void destroyAstVariableRaw(AstVariableRaw obj) {
    if (obj->data) {
        release_mmobj(obj->data);
        obj->data = null;
    }
}

plat_inline void packAstVariableRaw(AstVariableRaw obj, Packer pkr) {

}

MMSubObject(AST_VARIABLE_RAW, AstVariableRaw, AstVariable , initAstVariableRaw, destroyAstVariableRaw, packAstVariableRaw);

plat_inline AstVariableRaw allocAstVariableRawWithData(mgn_memory_pool* pool, void* data, uint size) {
    AstVariableRaw obj = allocAstVariableRaw(pool);
    if (obj) {
        obj->data = allocMMDataWithData(pool, data, size);
        if (obj->data == null) {
            release_mmobj(obj);
            return null;
        }
    }
    return obj;
}


/// ===== Variable - List =====

typedef struct AstVariableList {
    MMList list;
}*AstVariableList;

plat_inline AstVariableList initAstVariableList(AstVariableList obj, Unpacker unpkr) {
    toAstNode(obj)->type = la_ast_inst_list;
    mgn_memory_pool* pool = pool_of_mmobj(obj);
    obj->list = allocMMList(pool);
    return obj;
}

plat_inline void destroyAstVariableList(AstVariableList obj) {
    if (obj->list) {
        release_mmobj(obj->list);
        obj->list = null;
    }
}

plat_inline void packAstVariableList(AstVariableList obj, Packer pkr) {

}

MMSubObject(AST_VARIABLE_LIST, AstVariableList, AstVariable , initAstVariableList, destroyAstVariableList, packAstVariableList);

AstVariableList allocAstVariableListWithItems(mgn_memory_pool* pool, AstVariable first_item, ...);


/// ===== Variable - Map  =====

typedef struct AstVariableMap {
    MMMap map;
}*AstVariableMap;

plat_inline AstVariableMap initAstVariableMap(AstVariableMap obj, Unpacker unpkr) {
    toAstNode(obj)->type = la_ast_inst_map;
    mgn_memory_pool* pool = pool_of_mmobj(obj);
    obj->map = allocMMMap(pool);
    return obj;
}

plat_inline void destroyAstVariableMap(AstVariableMap obj) {
    if (obj->map) {
        release_mmobj(obj->map);
        obj->map = null;
    }
}

plat_inline void packAstVariableMap(AstVariableMap obj, Packer pkr) {

}

MMSubObject(AST_VARIABLE_MAP, AstVariableMap, AstVariable , initAstVariableMap, destroyAstVariableMap, packAstVariableMap);

AstVariableMap allocAstVariableMapWithKeyValue(mgn_memory_pool* pool, MMString first_key, .../* AstVariable first_value, and more keys and values */);
void addAstVariableKeyValue(AstVariableMap map, MMString first_key, .../* AstVariable first_value, and more keys and values */);



#endif //PROC_LA_AST_VARIABLE_H
