//
// Created by Yuchi Chen on 2017/9/16.
//

#ifndef PROC_LA_AST_NODE_H
#define PROC_LA_AST_NODE_H

#include "mmObj.h"
#include "mmObj_lib.h"

#include "ast_obj.h"

enum {
    AST_NODE     = 0,
    AST_NONE,
    AST_TYPE,
    AST_TYPE_COMBINATION,
    AST_VARIABLE,
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


/// ===== NONE =====

typedef struct AstNone {

}*AstNone;

plat_inline AstNone initAstNone(AstNone obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstNone(AstNone obj) {

}

plat_inline void packAstNone(AstNone obj, Packer pkr) {

}

MMSubObject(AST_NONE, AstNone, AstNode , initAstNone, destroyAstNone, packAstNone);

plat_inline AstNone allocAstNoneWith(mgn_memory_pool* pool, ...) {
    AstNone obj = allocAstNone(pool);
    if (obj) {
    }
    return obj;
}


#endif //PROC_LA_AST_NODE_H
