//
// Created by Yuchi Chen on 2017/9/22.
//

#ifndef PROC_LA_AST_RUNTIME_H
#define PROC_LA_AST_RUNTIME_H

#include "ast_node.h"

/// ===== Stack =====

typedef struct AstStack {

}*AstStack;

plat_inline AstStack initAstStack(AstStack obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstStack(AstStack obj) {

}

plat_inline void packAstStack(AstStack obj, Packer pkr) {

}

MMSubObject(AST_STACK, AstStack, AstNode , initAstStack, destroyAstStack, packAstStack);

plat_inline AstStack allocAstStackWith(mgn_memory_pool* pool, ...) {
    AstStack obj = allocAstStack(pool);
    if (obj) {
    }
    return obj;
}


/// ===== Scope =====

typedef struct AstScope {

}*AstScope;

plat_inline AstScope initAstScope(AstScope obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstScope(AstScope obj) {

}

plat_inline void packAstScope(AstScope obj, Packer pkr) {

}

MMSubObject(AST_SCOPE, AstScope, AstNode, initAstScope, destroyAstScope, packAstScope);

plat_inline AstScope allocAstScopeWith(mgn_memory_pool* pool, ...) {
    AstScope obj = allocAstScope(pool);
    if (obj) {
    }
    return obj;
}

#endif //PROC_LA_AST_RUNTIME_H





