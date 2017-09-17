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

plat_inline AstType initAstType(AstType obj, Unpacker unpkr) {
    obj->type = ast_type_var;
    return obj;
}

plat_inline void destroyAstType(AstType obj) {

}

plat_inline void packAstType(AstType obj, Packer pkr) {

}

MMSubObject(AST_TYPE, AstType, AstNode , initAstType, destroyAstType, packAstType);

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

plat_inline AstTypeCombination initAstTypeCombination(AstTypeCombination obj, Unpacker unpkr) {
    toAstType(obj)->type = ast_type_var;        // base type
    return obj;
}

plat_inline void destroyAstTypeCombination(AstTypeCombination obj) {

}

plat_inline void packAstTypeCombination(AstTypeCombination obj, Packer pkr) {

}

MMSubObject(AST_TYPE_COMBINATION, AstTypeCombination, AstType , initAstTypeCombination, destroyAstTypeCombination, packAstTypeCombination);

plat_inline AstTypeCombination allocAstTypeCombinationWithCombinedType(mgn_memory_pool* pool, ast_type type, int32 combined_type) {
    AstTypeCombination obj = allocAstTypeCombination(pool);
    if (obj) {
        toAstType(obj)->type = type;            // base type
        obj->combined_type = combined_type;
    }
    return obj;
}




#endif //PROC_LA_AST_TYPE_H
