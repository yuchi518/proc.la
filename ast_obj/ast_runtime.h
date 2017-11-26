//
// Created by Yuchi Chen on 2017/9/22.
//

#ifndef PROC_LA_AST_RUNTIME_H
#define PROC_LA_AST_RUNTIME_H

#include "ast_expr.h"

/// ===== Error Recovery =====
// Use to replace a error node
typedef struct AstErrorRecovery {
    uint code;              // error code
    MMString message;       // error message
    AstNode node;           // replaced node
}*AstErrorRecovery;

plat_inline int compareForAstErrorRecovery(void*, void*);
plat_inline AstErrorRecovery initAstErrorRecovery(AstErrorRecovery obj, Unpacker unpkr) {
    set_compare_for_mmobj(obj, compareForAstErrorRecovery);
    if (is_unpacker_v1(unpkr)) {
        obj->code = unpack_uint(0, unpkr);
        obj->message = unpack_mmobj_retained(1, unpkr);
        obj->node = unpack_mmobj_retained(2, unpkr);
    }
    return obj;
}

plat_inline void destroyAstErrorRecovery(AstErrorRecovery obj) {
    release_mmobj(obj->message);
    release_mmobj(obj->node);
}

plat_inline void packAstErrorRecovery(AstErrorRecovery obj, Packer pkr) {
    if (is_packer_v1(pkr)) {
        pack_uint(0, obj->code, pkr);
        pack_mmobj(1, obj->message, pkr);
        pack_mmobj(2, obj->node, pkr);
    }
}

MMSubObject(AstErrorRecovery, AstExpression, initAstErrorRecovery, destroyAstErrorRecovery, packAstErrorRecovery);

plat_inline int compareForAstErrorRecovery(void* this_stru, void* that_stru) {
    AstErrorRecovery errorRecovery1 = toAstErrorRecovery(this_stru);
    AstErrorRecovery errorRecovery2 = toAstErrorRecovery(that_stru);

    return FIRST_Of_3RESULTS((int)(errorRecovery1->code - errorRecovery2->code),
                             compare_mmobjs(errorRecovery1->message, errorRecovery2->message),
                             compare_mmobjs(errorRecovery1->node, errorRecovery2->node));
}

plat_inline AstErrorRecovery allocAstErrorRecoveryWithCodeAndMessage(mgn_memory_pool* pool, uint code, MMString message, AstNode node) {
    AstErrorRecovery errorRecovery = allocAstErrorRecovery(pool);
    if (errorRecovery) {
        errorRecovery->code = code;
        errorRecovery->message = retain_mmobj(message);
        errorRecovery->node = retain_mmobj(node);
    }
    return errorRecovery;
}

plat_inline AstErrorRecovery error_recovery(mgn_memory_pool* pool, uint code, MMString message, AstNode node) {
    return autorelease_mmobj(allocAstErrorRecoveryWithCodeAndMessage(pool, code, message, node));
}

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
    int r = compareForAstNode(this_stru, that_stru);
    if (r) return r;
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
    struct AstScope* last_scope;        // weak reference, don't retain
    /**
     *  Belong to package.
     */
    AstPackage package;
    /**
     *  Constants
     *  1. domain.name.la vs. la instance
     *     MMString (la name + ':' + input parameters number) vs. AstVarInstance
     *  2. identifier vs. constant/literal
     *     MMString (identifier) vs. AstVarInstance
     */
    MMMap constants;
    // runtime variable, clean when the node is out of stack
    MMMap variables;
}*AstScope;

plat_inline AstScope initAstScope(AstScope obj, Unpacker unpkr);

plat_inline void destroyAstScope(AstScope obj) {
    obj->trigger = null;
    obj->last_scope = null;
    release_mmobj(obj->package);
    release_mmobj(obj->constants);
    release_mmobj(obj->variables);
}

plat_inline void packAstScope(AstScope obj, Packer pkr) {
    if (is_packer_v1(pkr)) {
        pack_mmobj(0, obj->trigger, pkr);
        pack_mmobj(1, obj->last_scope, pkr);
        pack_mmobj(2, obj->package, pkr);
        pack_mmobj(3, obj->constants, pkr);
        pack_mmobj(4, obj->variables, pkr);
    }
}

MMSubObject(AstScope, AstNode, initAstScope, destroyAstScope, packAstScope);

plat_inline int compareForAstScope(void*, void*);
plat_inline AstScope initAstScope(AstScope obj, Unpacker unpkr) {
    set_compare_for_mmobj(obj, compareForAstScope);
    if (is_unpacker_v1(unpkr)) {
        obj->trigger = toAstNode(unpack_mmobj(0, unpkr));               // weak reference
        obj->last_scope = toAstScope(unpack_mmobj(1, unpkr));           // weak reference
        obj->package = toAstPackage(unpack_mmobj_retained(2, unpkr));
        obj->constants = toMMMap(unpack_mmobj_retained(3, unpkr));
        obj->variables = toMMMap(unpack_mmobj_retained(4, unpkr));
    } else {
        obj->constants = allocMMMap(pool_of_mmobj(obj));
        obj->variables = allocMMMap(pool_of_mmobj(obj));
    }
    return obj;
}

plat_inline int compareForAstScope(void* this_stru, void* that_stru) {
    int r = compareForAstNode(this_stru, that_stru);
    if (r) return r;
    AstScope scope1 = toAstScope(this_stru);
    AstScope scope2 = toAstScope(that_stru);
    return FIRST_Of_5RESULTS(compare_mmobjs(scope1->trigger, scope2->trigger),
                             compare_mmobjs(scope1->last_scope, scope2->last_scope),
                             compare_mmobjs(scope1->package, scope2->package),
                             compare_mmobjs(scope1->constants, scope2->constants),
                             compare_mmobjs(scope1->variables, scope2->variables));
}

plat_inline AstScope allocAstScopeWithTriggerAndLastScope(mgn_memory_pool* pool, AstNode trigger, AstScope last_scope) {
    AstScope obj = allocAstScope(pool);
    if (obj) {
        obj->trigger = trigger;                     // weak reference, don't retain
        obj->last_scope = last_scope;               // weak reference, don't retain
    }
    return obj;
}

plat_inline AstScope allocAstScopeWithTriggerAndLastScopeInPackage(mgn_memory_pool* pool, AstNode trigger, AstScope last_scope, AstPackage aPackage) {
    AstScope obj = allocAstScope(pool);
    if (obj) {
        obj->trigger = trigger;                     // weak reference, don't retain
        obj->last_scope = last_scope;               // weak reference, don't retain
        obj->package = retain_mmobj(aPackage);
    }
    return obj;
}

plat_inline void pushVarInstanceIntoScope(AstScope scope, AstVarInstance varInstance) {
    addMMMapItem(scope->variables, toMMPrimary(varInstance->declare->identifier->name), toMMObject(varInstance));
}

plat_inline void pushVarDeclareIntoScope(AstScope scope, AstVarDeclare varDeclare) {
    addMMMapItem(scope->variables, toMMPrimary(varDeclare->identifier->name), toMMObject(varDeclare));
}


/// ===== Context =====

typedef struct AstContext {
    AstStack stack;
    AstScope scope;
}*AstContext;

plat_inline int compareForAstContext(void*, void*);
plat_inline AstContext initAstContext(AstContext obj, Unpacker unpkr) {
    set_compare_for_mmobj(obj, compareForAstContext);
    if (is_unpacker_v1(unpkr)) {
        obj->stack = toAstStack(unpack_mmobj_retained(0, unpkr));
        obj->scope = toAstScope(unpack_mmobj_retained(1, unpkr));
    }
    return obj;
}

plat_inline void destroyAstContext(AstContext obj) {
    release_mmobj(obj->stack);
    release_mmobj(obj->scope);
}

plat_inline void packAstContext(AstContext obj, Packer pkr) {
    if (is_packer_v1(pkr)) {
        pack_mmobj(0, obj->stack, pkr);
        pack_mmobj(1, obj->scope, pkr);
    }
}

MMSubObject(AstContext, AstNode, initAstContext, destroyAstContext, packAstContext);

plat_inline int compareForAstContext(void* this_stru, void* that_stru) {
    int r = compareForAstNode(this_stru, that_stru);
    if (r) return r;
    AstContext context1 = toAstContext(this_stru);
    AstContext context2 = toAstContext(that_stru);
    return FIRST_Of_2RESULTS(compare_mmobjs(context1->stack, context2->stack),
                             compare_mmobjs(context1->scope, context2->scope));
}

plat_inline AstContext allocAstContextWithStackAndScope(mgn_memory_pool* pool, AstStack stack, AstScope scope) {
    AstContext obj = allocAstContext(pool);
    if (obj) {
        obj->stack = retain_mmobj(stack);
        obj->scope = retain_mmobj(scope);
    }
    return obj;
}



#endif //PROC_LA_AST_RUNTIME_H





