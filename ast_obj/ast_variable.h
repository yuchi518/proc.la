//
// Created by Yuchi Chen on 2017/9/16.
//

#ifndef PROC_LA_AST_VARIABLE_H
#define PROC_LA_AST_VARIABLE_H

#include "ast_node.h"

/// ===== Variable =====
/**
 * One of following variables:
 *  int, long, float, double, number, string, raw
 *  list, map, la
 */

typedef struct AstVariable {
    ast_type type;
    bool is_const;
    MMObject value;
}*AstVariable;

plat_inline AstVariable initAstVariable(AstVariable obj, Unpacker unpkr) {
    obj->type = ast_type_var;
    obj->is_const = false;
    return obj;
}

plat_inline void destroyAstVariable(AstVariable obj) {
    if (obj->value) {
        release_mmobj(obj->value);
    }
}

plat_inline void packAstVariable(AstVariable obj, Packer pkr) {

}

MMSubObject(AST_VARIABLE, AstVariable, AstNode , initAstVariable, destroyAstVariable, packAstVariable);

plat_inline AstVariable allocVariableWithIntValue(mgn_memory_pool* pool, int32 value)
{
    AstVariable obj = allocAstVariable(pool);
    if (obj) {
        obj->type = ast_type_int;
        obj->value = toMMObject(allocMMIntWithValue(pool, value));
        if (obj->value == null) {
            release_mmobj(obj);
            obj = null;
        }
    }
    return obj;
}

plat_inline AstVariable allocVariableWithConstIntValue(mgn_memory_pool* pool, int32 value)
{
    AstVariable obj = allocVariableWithIntValue(pool, value);
    if (obj) {
        obj->is_const = true;
    }
    return obj;
}

plat_inline AstVariable allocVariableWithLongValue(mgn_memory_pool* pool, int64 value)
{
    AstVariable obj = allocAstVariable(pool);
    if (obj) {
        obj->type = ast_type_long;
        obj->value = toMMObject(allocMMLongWithValue(pool, value));
        if (obj->value == null) {
            release_mmobj(obj);
            obj = null;
        }
    }
    return obj;
}

plat_inline AstVariable allocVariableWithConstLongValue(mgn_memory_pool* pool, int64 value)
{
    AstVariable obj = allocVariableWithLongValue(pool, value);
    if (obj) {
        obj->is_const = true;
    }
    return obj;
}

plat_inline AstVariable allocVariableWithFloatValue(mgn_memory_pool* pool, float value)
{
    AstVariable obj = allocAstVariable(pool);
    if (obj) {
        obj->type = ast_type_float;
        obj->value = toMMObject(allocMMFloatWithValue(pool, value));
        if (obj->value == null) {
            release_mmobj(obj);
            obj = null;
        }
    }
    return obj;
}

plat_inline AstVariable allocVariableWithConstFloatValue(mgn_memory_pool* pool, float value)
{
    AstVariable obj = allocVariableWithFloatValue(pool, value);
    if (obj) {
        obj->is_const = true;
    }
    return obj;
}


plat_inline AstVariable allocVariableWithDoubleValue(mgn_memory_pool* pool, double value)
{
    AstVariable obj = allocAstVariable(pool);
    if (obj) {
        obj->type = ast_type_double;
        obj->value = toMMObject(allocMMDoubleWithValue(pool, value));
        if (obj->value == null) {
            release_mmobj(obj);
            obj = null;
        }
    }
    return obj;
}

plat_inline AstVariable allocVariableWithConstDoubleValue(mgn_memory_pool* pool, double value)
{
    AstVariable obj = allocVariableWithDoubleValue(pool, value);
    if (obj) {
        obj->is_const = true;
    }
    return obj;
}

plat_inline AstVariable allocVariableWithNumberValue(mgn_memory_pool* pool, double value)
{
    AstVariable obj = allocAstVariable(pool);
    if (obj) {
        obj->type = ast_type_number;
        /// TODO: implementation
    }
    return obj;
}

plat_inline AstVariable allocVariableWithConstNumberValue(mgn_memory_pool* pool, double value)
{
    AstVariable obj = allocVariableWithNumberValue(pool, value);
    if (obj) {
        obj->is_const = true;
    }
    return obj;
}

plat_inline AstVariable allocVariableWithCString(mgn_memory_pool* pool, char* cstring)
{
    AstVariable obj = allocAstVariable(pool);
    if (obj) {
        obj->type = ast_type_string;
        obj->value = toMMObject(allocMMStringWithCString(pool, cstring));
        if (obj->value == null) {
            release_mmobj(obj);
            obj = null;
        }
    }
    return obj;
}

plat_inline AstVariable allocVariableWithConstCString(mgn_memory_pool* pool, char* cstring)
{
    AstVariable obj = allocVariableWithCString(pool, cstring);
    if (obj) {
        obj->is_const = true;
    }
    return obj;
}

plat_inline AstVariable allocVariableWithRawData(mgn_memory_pool* pool, void* data, uint size) {
    AstVariable obj = allocAstVariable(pool);
    if (obj) {
        obj->type = ast_type_raw;
        obj->value = toMMObject(allocMMDataWithData(pool, data, size));
        if (obj->value == null) {
            release_mmobj(obj);
            return null;
        }
    }
    return obj;
}

/// ===== Variable - Combination  =====

typedef struct AstVariableCombination {
    int32 combined_type;
}*AstVariableCombination;

plat_inline AstVariableCombination initAstVariableCombination(AstVariableCombination obj, Unpacker unpkr) {
    toAstVariable(obj)->type = ast_type_var;        // base type
    return obj;
}

plat_inline void destroyAstVariableCombination(AstVariableCombination obj) {

}

plat_inline void packAstVariableCombination(AstVariableCombination obj, Packer pkr) {

}

MMSubObject(AST_VARIABLE_COMBINATION, AstVariableCombination, AstVariable, initAstVariableCombination, destroyAstVariableCombination, packAstVariableCombination);


/// TODO - implement combination type.



#if 0
/// ===== Variable - List =====

typedef struct AstVariableList {
    MMList list;
}*AstVariableList;

plat_inline AstVariableList initAstVariableList(AstVariableList obj, Unpacker unpkr) {
    toAstVariable(obj)->type = ast_type_list;
    obj->list = allocMMList(pool_of_mmobj(obj));
    if (obj->list == null) return null;
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
    toAstVariable(obj)->type = ast_type_map;
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

#endif

/// ===== Domain Name  =====

typedef struct AstDomainName {
    MMString name;
}*AstDomainName;

plat_inline AstDomainName initAstDomainName(AstDomainName obj, Unpacker unpkr) {
    toAstVariable(obj)->type = ast_type_la;
    return obj;
}

plat_inline void destroyAstDomainName(AstDomainName obj) {
    if (obj->name) {
        release_mmobj(obj->name);
        obj->name = null;
    }
}

plat_inline void packAstDomainName(AstDomainName obj, Packer pkr) {

}

MMSubObject(AST_VARIABLE_DOMAIN_NAME, AstDomainName, AstVariable, initAstDomainName, destroyAstDomainName, packAstDomainName);

plat_inline AstDomainName allocAstDomainNameWithName(mgn_memory_pool* pool, MMString name) {
    if (name == null) {
        plat_io_printf_err("DomainName should have a name\n");
        return null;
    }

    AstDomainName obj = allocAstDomainName(pool);
    if (obj) {
        obj->name = retain_mmobj(name);
    }
    return obj;
}

plat_inline AstDomainName allocAstDomainNameWithCStringName(mgn_memory_pool* pool, char* name) {
    if (name == null) {
        plat_io_printf_err("DomainName should have a name\n");
        return null;
    }

    return allocAstDomainNameWithName(pool, autorelease_mmobj(allocMMStringWithCString(pool, name)));
}

#endif //PROC_LA_AST_VARIABLE_H
