//
// Created by Yuchi Chen on 2017/9/16.
//

#ifndef PROC_LA_AST_NODE_H
#define PROC_LA_AST_NODE_H

#include "mmObj.h"
#include "mmObj_lib.h"

#include "mmObj_unittest.h"

enum {
    AST_NODE     = 0,
    AST_NONE,

    AST_CTRL,
    AST_CTRL_FLOW,

    AST_IDENTIFIER,

    AST_TYPE,
    AST_TYPE_COMBINATION,

    AST_VARIABLE,
    AST_VARIABLE_COMBINATION,
    AST_VARIABLE_LIST,
    AST_VARIABLE_MAP,
    AST_VARIABLE_LA,                    // input + body + output
    AST_VARIABLE_DOMAIN_NAME,

    AST_STATEMENT,
    AST_PACKAGE,
    AST_VAR_DECLARE,
    AST_VAR_INSTANCE,
    AST_VAR_LIST_DECLARATION,
    AST_TYPE_LIST_DECLARATION,
    AST_LA_BODY_DECLARATION,            // only body
    AST_EXTERNAL_DECLARATIONS,

    AST_A_PROC_LA,

    AST_STACK,
    AST_SCOPE,

};

typedef enum {
    ast_type_var             = 0,
    ast_type_int,
    ast_type_long,
    ast_type_float,
    ast_type_double,
    ast_type_number,
    ast_type_string,
    ast_type_raw,
    ast_type_proc,
    ast_type_la,
} ast_type;

typedef enum {
    ast_type_list   = 1,
    ast_type_map    = 2,
} ast_type_combination;


/// ===== Abstract Tree node =====
typedef struct AstNode {

}*AstNode;

plat_inline AstNode initAstNode(AstNode obj, Unpacker unpkr) {
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


/// ===== Identifier =====

typedef struct AstIdentifier {
    MMString name;
}*AstIdentifier;

plat_inline AstIdentifier initAstIdentifier(AstIdentifier obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstIdentifier(AstIdentifier obj) {
    if (obj->name) {
        release_mmobj(obj->name);
        obj->name = null;
    }
}

plat_inline void packAstIdentifier(AstIdentifier obj, Packer pkr) {

}

MMSubObject(AST_IDENTIFIER, AstIdentifier, AstNode, initAstIdentifier, destroyAstIdentifier, packAstIdentifier);

plat_inline AstIdentifier allocAstIdentifierWithName(mgn_memory_pool* pool, MMString name) {
    if (name == null) {
        plat_io_printf_err("Identifier should have a name\n");
        return null;
    }

    AstIdentifier obj = allocAstIdentifier(pool);
    if (obj) {
        obj->name = retain_mmobj(name);
    }
    return obj;
}

plat_inline AstIdentifier allocAstIdentifierWithCStringName(mgn_memory_pool* pool, char* name) {
    if (name == null) {
        plat_io_printf_err("Identifier should have a name\n");
        return null;
    }

    return allocAstIdentifierWithName(pool, autorelease_mmobj(allocMMStringWithCString(pool, name)));
}

#endif //PROC_LA_AST_NODE_H
