//
// Created by Yuchi Chen on 2017/9/16.
//

#ifndef PROC_LA_AST_TYPE_H
#define PROC_LA_AST_TYPE_H

#include "ast_node.h"


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
    switch(type) {
        case la_ast_type_int:
        case la_ast_type_long:
        case la_ast_type_float:
        case la_ast_type_double:
        case la_ast_type_number:
        case la_ast_type_string:
        case la_ast_type_raw:
        case la_ast_type_var:
        case la_ast_type_proc:
        case la_ast_type_la:
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




#endif //PROC_LA_AST_TYPE_H
