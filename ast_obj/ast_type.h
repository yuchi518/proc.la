//
// Created by Yuchi Chen on 2017/9/16.
//

#ifndef PROC_LA_AST_TYPE_H
#define PROC_LA_AST_TYPE_H

#include "ast_node.h"


/// ===== Ast Type =====
/*
 * One of followings types:
 *  var, int, long, float, double, number, string, raw
 *  proc, la, la_ast_type_combination (sub type)
 */
typedef struct AstType {
    ast_type type;
}*AstType;

plat_inline int compareForAstType(void*, void*);
plat_inline AstType initAstType(AstType obj, Unpacker unpkr) {
    set_compare_for_mmobj(obj, compareForAstType);
    if (is_unpacker_v1(unpkr)) {
        obj->type = (ast_type)unpack_varint(0, unpkr);
    } else {
        obj->type = ast_type_var;
    }
    return obj;
}

/*plat_inline void destroyAstType(AstType obj) {

}*/

plat_inline void packAstType(AstType obj, Packer pkr) {
    if (is_packer_v1(pkr)) {
        pack_varint(0, obj->type, pkr);
    }
}

MMSubObject(AstType, AstNode , initAstType, null/*destroyAstType*/, packAstType);

plat_inline int compareForAstType(void* this_stru, void* that_stru) {
    int r = compareForAstNode(this_stru, that_stru);
    if (r) return r;
    AstType type1 = toAstType(this_stru);
    AstType type2 = toAstType(that_stru);
    return (int)type1->type - (int)type2->type;
}

plat_inline AstType allocAstTypeWithType(mgn_memory_pool* pool, ast_type type)
{
    switch(type) {
        case ast_type_int:
        case ast_type_long:
        case ast_type_float:
        case ast_type_double:
        case ast_type_number:
        case ast_type_string:
        case ast_type_raw:
        case ast_type_var:
        case ast_type_proc:
        case ast_type_la:
            break;
        default:
        {
            plat_io_printf_err("Not a correct type %d\n", type);
            return null;
        }
    }
    AstType obj = allocAstType(pool);
    if (obj)
    {
        obj->type = type;
    }
    return obj;
}


/// ===== AstTypeCombination =====

typedef struct AstTypeCombination {
    /**
     * combined_type = base_type | ([1 or 2] << (16+0)) | ([1 or 2] << (16+2)) | ... | ([1 or 2] << (16+N))
     * base_type = la_ast_type_int | la_ast_type_long | ... etc.
     * [1 or 2], 1 = list [], 2 = map {}
     * 16 + (0~14), the maximum level of combined type is 8, use 2 bits to maintain each level.
     */
    int32 combined_type;
}*AstTypeCombination;

plat_inline int compareForAstTypeCombination(void*, void*);
plat_inline AstTypeCombination initAstTypeCombination(AstTypeCombination obj, Unpacker unpkr) {
    set_compare_for_mmobj(obj, compareForAstTypeCombination);
    if (is_unpacker_v1(unpkr)) {
        obj->combined_type = (int32)unpack_varint(0, unpkr);
    } else {
        toAstType(obj)->type = ast_type_var;        // base type
    }
    return obj;
}

/*plat_inline void destroyAstTypeCombination(AstTypeCombination obj) {

}*/

plat_inline void packAstTypeCombination(AstTypeCombination obj, Packer pkr) {
    if (is_packer_v1(pkr)) {
        pack_varint(0, obj->combined_type, pkr);
    }
}

MMSubObject(AstTypeCombination, AstType , initAstTypeCombination, null/*destroyAstTypeCombination*/, packAstTypeCombination);

plat_inline int compareForAstTypeCombination(void* this_stru, void* that_stru) {
    int r = compareForAstType(this_stru, that_stru);
    if (r) return r;
    AstTypeCombination typeCombination1 = toAstTypeCombination(this_stru);
    AstTypeCombination typeCombination2 = toAstTypeCombination(that_stru);
    AstType type1 = toAstType(typeCombination1);
    AstType type2 = toAstType(typeCombination2);
    return FIRST_Of_2RESULTS((int)type1->type - (int)type2->type,
                             (int)typeCombination1->combined_type - (int)typeCombination2->combined_type);
}

plat_inline AstTypeCombination allocAstTypeCombinationWithCombinedType(mgn_memory_pool* pool, ast_type type, int32 combined_type) {
    AstTypeCombination obj = allocAstTypeCombination(pool);
    if (obj) {
        toAstType(obj)->type = type;            // base type
        obj->combined_type = combined_type;
    }
    return obj;
}

plat_inline int appendCombinationType(AstTypeCombination typeCombination, ast_type_combination combination) {
    int i=0;
    for (i=0;i<16;i+=2)
    {
        if ((typeCombination->combined_type & (0x03<<i)) == 0)
        {
            // empty slot
            typeCombination->combined_type |= (0x03 & combination) << i;
            break;
        }
    }
    return i;
}

plat_inline ast_type_combination getCombinationType(AstTypeCombination typeCombination, uint index) {
    if (index >= 16) return (ast_type_combination)0;
    return (ast_type_combination)((typeCombination->combined_type >> index) & 0x03);
}


#endif //PROC_LA_AST_TYPE_H
