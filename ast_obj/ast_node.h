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

    AST_CTRL,
    AST_CTRL_FLOW,

    AST_IDENTIFIER,

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
    AST_VARIABLE_LA,
    AST_VARIABLE_DOMAIN_NAME,

    AST_STATEMENT,
    AST_PACKAGE,
    AST_VAR_DECLARE,
    AST_VAR_INSTANCE,
    AST_VAR_LIST_DECLARATION,
    AST_TYPE_LIST_DECLARATION,
    AST_LA_BODY_DECLARATION,
    AST_EXTERNAL_DECLARATIONS,

    AST_A_PROC_LA,

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


/// ===== Identifier =====

typedef struct AstIdentifier {
    MMString name;
}*AstIdentifier;

plat_inline AstIdentifier initAstIdentifier(AstIdentifier obj, Unpacker unpkr) {
    toAstNode(obj)->type = la_ast_identifier;
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


#endif //PROC_LA_AST_NODE_H
