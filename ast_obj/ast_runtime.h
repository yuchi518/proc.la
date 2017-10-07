//
// Created by Yuchi Chen on 2017/9/22.
//

#ifndef PROC_LA_AST_RUNTIME_H
#define PROC_LA_AST_RUNTIME_H

#include "ast_node.h"

/// ===== Stack =====

typedef struct AstStack {
    MMList nodes;
}*AstStack;

plat_inline AstStack initAstStack(AstStack obj, Unpacker unpkr) {
    obj->nodes = allocMMList(pool_of_mmobj(obj));
    if (obj->nodes == null) return null;
    return obj;
}

plat_inline void destroyAstStack(AstStack obj) {
    release_mmobj(obj->nodes);
}

plat_inline void packAstStack(AstStack obj, Packer pkr) {

}

MMSubObject(AST_STACK, AstStack, AstNode , initAstStack, destroyAstStack, packAstStack);

plat_inline AstStack allocAstStackWithANode(mgn_memory_pool* pool, AstNode node) {
    AstStack obj = allocAstStack(pool);
    if (obj) {
        pushMMListItem(obj->nodes, toMMObject(node));
    }
    return obj;
}

plat_inline uint sizeOfAstStack(AstStack stack) {
    return sizeOfMMList(stack->nodes);
}

plat_inline bool isEmptyAstStack(AstStack stack) {
    return (sizeOfAstStack(stack) == 0)?true:false;
}

plat_inline void pushToAstStack(AstStack stack, AstNode node) {
    pushMMListItem(stack->nodes, toMMObject(node));
}

plat_inline AstNode popFromAstStack(AstStack stack) {
    MMObject obj = popMMListItem(stack->nodes);
    return toAstNode(obj);
}

/// ===== Scope =====

typedef struct AstScope {
    AstNode trigger;
    struct AstScope* last_scope;
}*AstScope;

plat_inline AstScope initAstScope(AstScope obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstScope(AstScope obj) {
    release_mmobj(obj->trigger);
    release_mmobj(obj->last_scope);
}

plat_inline void packAstScope(AstScope obj, Packer pkr) {

}

MMSubObject(AST_SCOPE, AstScope, AstNode, initAstScope, destroyAstScope, packAstScope);

plat_inline AstScope allocAstScopeWithTriggerAndLastScope(mgn_memory_pool* pool, AstNode trigger, AstScope last_scope) {
    AstScope obj = allocAstScope(pool);
    if (obj) {
        obj->trigger = retain_mmobj(trigger);
        obj->last_scope = retain_mmobj(last_scope);
    }
    return obj;
}

#endif //PROC_LA_AST_RUNTIME_H





