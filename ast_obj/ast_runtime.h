//
// Created by Yuchi Chen on 2017/9/22.
//

#ifndef PROC_LA_AST_RUNTIME_H
#define PROC_LA_AST_RUNTIME_H

#include "ast_node.h"

/// ===== NONE =====

typedef struct AstErrorRecovery {

}*AstErrorRecovery;

plat_inline AstErrorRecovery initAstErrorRecovery(AstErrorRecovery obj, Unpacker unpkr) {
    (void) unpkr;
    set_single_instance_comparison_for_mmobj(obj);
    return obj;
}

/*plat_inline void destroyAstErrorRecovery(AstErrorRecovery obj) {

}*/

plat_inline void packAstErrorRecovery(AstErrorRecovery obj, Packer pkr) {

}

MMSubObject(AstErrorRecovery, AstExpression, initAstErrorRecovery, null/*destroyAstErrorRecovery*/, packAstErrorRecovery);

/// ===== Stack =====

typedef struct AstStack {
    MMList nodes;
}*AstStack;

plat_inline int compareForAstStack(void*, void*);
plat_inline AstStack initAstStack(AstStack obj, Unpacker unpkr) {
    set_compare_for_mmobj(obj, compareForAstStack);
    if (is_unpacker_v1(unpkr)) {
        obj->nodes = toMMList(unpack_mmobj_retained(0, unpkr));
    } else {
        obj->nodes = allocMMList(pool_of_mmobj(obj));
        if (obj->nodes == null) return null;
    }
    return obj;
}

plat_inline void destroyAstStack(AstStack obj) {
    release_mmobj(obj->nodes);
}

plat_inline void packAstStack(AstStack obj, Packer pkr) {
    if (is_packer_v1(pkr)) {
        pack_mmobj(0, obj->nodes, pkr);
    }
}

MMSubObject(AstStack, AstNode , initAstStack, destroyAstStack, packAstStack);

plat_inline int compareForAstStack(void* this_stru, void* that_stru) {
    AstStack stack1 = toAstStack(this_stru);
    AstStack stack2 = toAstStack(that_stru);
    return compare_mmobjs(stack1->nodes, stack2->nodes);
}

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
    MMMap variables;
}*AstScope;

plat_inline AstScope initAstScope(AstScope obj, Unpacker unpkr);

plat_inline void destroyAstScope(AstScope obj) {
    release_mmobj(obj->trigger);
    release_mmobj(obj->last_scope);
    release_mmobj(obj->variables);
}

plat_inline void packAstScope(AstScope obj, Packer pkr) {
    if (is_packer_v1(pkr)) {
        pack_mmobj(0, obj->trigger, pkr);
        pack_mmobj(1, obj->last_scope, pkr);
        pack_mmobj(2, obj->variables, pkr);
    }
}

MMSubObject(AstScope, AstNode, initAstScope, destroyAstScope, packAstScope);

plat_inline int compareForAstScope(void*, void*);
plat_inline AstScope initAstScope(AstScope obj, Unpacker unpkr) {
    set_compare_for_mmobj(obj, compareForAstScope);
    if (is_unpacker_v1(unpkr)) {
        obj->trigger = toAstNode(unpack_mmobj_retained(0, unpkr));
        obj->last_scope = toAstScope(unpack_mmobj_retained(1, unpkr));
        obj->variables = toMMMap(unpack_mmobj_retained(2, unpkr));
    } else {
        obj->variables = allocMMMap(pool_of_mmobj(obj));
    }
    return obj;
}

plat_inline int compareForAstScope(void* this_stru, void* that_stru) {
    AstScope scope1 = toAstScope(this_stru);
    AstScope scope2 = toAstScope(that_stru);
    return FIRST_Of_3RESULTS(compare_mmobjs(scope1->trigger, scope2->trigger),
                             compare_mmobjs(scope1->last_scope, scope2->last_scope),
                             compare_mmobjs(scope1->variables, scope2->variables));
}

plat_inline AstScope allocAstScopeWithTriggerAndLastScope(mgn_memory_pool* pool, AstNode trigger, AstScope last_scope) {
    AstScope obj = allocAstScope(pool);
    if (obj) {
        obj->trigger = retain_mmobj(trigger);
        obj->last_scope = retain_mmobj(last_scope);
    }
    return obj;
}

plat_inline void pushVarInstanceIntoScope(AstScope scope, AstVarInstance varInstance) {
    addMMMapItem(scope->variables, toMMPrimary(varInstance->declare->identifier->name), toMMObject(varInstance));
}

plat_inline void pushVarDeclareIntoScope(AstScope scope, AstVarDeclare varDeclare) {
    addMMMapItem(scope->variables, toMMPrimary(varDeclare->identifier->name), toMMObject(varDeclare));
}

#endif //PROC_LA_AST_RUNTIME_H





