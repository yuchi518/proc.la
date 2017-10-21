//
// Created by Yuchi Chen on 2017/10/4.
//

#ifndef PROC_LA_AST_CONTAINER_H
#define PROC_LA_AST_CONTAINER_H

#include "ast_expr.h"

/// ===== Expr - Container =====
/**
 * One of following container:
 *    List:   ( value, ... )
 *    Map:    ( string: value, ... )
 *    Tuple:  ( value, ...)
 * This is not real containers, it is used to express a container for AST.
 */

typedef struct AstContainerExpr {
    ast_container_type type;
    bool closed;
    MMList list;
}*AstContainerExpr;

plat_inline int compare_for_AstContainerExpr(void *, void *);
plat_inline AstContainerExpr initAstContainer(AstContainerExpr obj, Unpacker unpkr) {
    set_compare_for_mmobj(obj, compare_for_AstContainerExpr);
    if (is_unpacker_v1(unpkr)) {
        obj->type = (ast_container_type)unpack_varint(0, unpkr);
        obj->closed = unpack_bool(1, unpkr);
        obj->list = unpack_mmobj(2, unpkr);
    } else {
        obj->closed = false;
        obj->list = allocMMList(pool_of_mmobj(obj));
    }
    return obj->list?obj:null;
}

plat_inline void destroyAstContainer(AstContainerExpr obj) {
    release_mmobj(obj->list);
}

plat_inline void packAstContainer(AstContainerExpr obj, Packer pkr) {
    if (is_packer_v1(pkr)) {
        pack_varint(0, obj->type, pkr);
        pack_bool(1, obj->closed, pkr);
        pack_mmobj(2, obj->list, pkr);
    }
}

MMSubObject(AstContainerExpr, AstExpression, initAstContainer, destroyAstContainer, packAstContainer);

plat_inline AstContainerExpr allocAstContainerExprWithType(mgn_memory_pool* pool, ast_container_type type) {
    AstContainerExpr containerExpr = allocAstContainerExpr(pool);
    if (containerExpr) {
        containerExpr->type = type;
    }
    return containerExpr;
}

plat_inline int compare_for_AstContainerExpr(void *this_stru, void *that_stru) {
    AstContainerExpr a = toAstContainerExpr(this_stru);
    AstContainerExpr b = toAstContainerExpr(that_stru);
    if (a->type != b->type) return (int)a->type - (int)b->type;
    if (a->closed != b->closed) return (a->closed?1:0) - (b->closed?1:0);
    return compare_mmobjs(a->list, b->list);
}

plat_inline bool isExprContainerClosed(AstContainerExpr exprList) {
    return exprList->closed;
}

// If closed, it can't add more expressions.
plat_inline void closeExprContainer(AstContainerExpr containerExpr) {
    containerExpr->closed = true;
}

plat_inline void addExprToExprContainer(AstContainerExpr containerExpr, AstExpression expr) {
    pushMMListItem(containerExpr->list, toMMObject(expr));
}

plat_inline void insertExprToExprContainerAt(AstContainerExpr containerExpr, AstExpression expr, uint idx) {
    insertMMListItem(containerExpr->list, toMMObject(expr), idx);
}

plat_inline void concatExprContainer(AstContainerExpr containerExpr1, AstContainerExpr containerExpr2) {
    concatMMList(containerExpr1->list, containerExpr2->list);
}

plat_inline uint sizeOfExprContainer(AstContainerExpr containerExpr) {
    return sizeOfMMList(containerExpr->list);
}

plat_inline AstExpression getExprFromExprContainerAt(AstContainerExpr containerExpr, uint idx) {
    return toAstExpression(getMMListItem(containerExpr->list, idx));
}

plat_inline ast_container_type getExprContainerType(AstContainerExpr containerExpr) {
    return containerExpr->type;
}

/*plat_inline void setExprContainerType(AstContainerExpr containerExpr, ast_container_type type) {
    containerExpr->type = type;
}*/

/// ===== Expr - Pair =====

typedef struct AstPairExpr {
    AstExpression expr_k;
    AstExpression expr_v;
}*AstPairExpr;

plat_inline int compare_for_AstPairExpr(void *, void *);
plat_inline AstPairExpr initAstPairExpr(AstPairExpr obj, Unpacker unpkr) {
    set_compare_for_mmobj(obj, compare_for_AstPairExpr);
    if (is_unpacker_v1(unpkr)) {
        obj->expr_k = unpack_mmobj(0, unpkr);
        obj->expr_v = unpack_mmobj(1, unpkr);
    }
    return obj;
}

plat_inline void destroyAstPairExpr(AstPairExpr obj) {
    release_mmobj(obj->expr_k);
    release_mmobj(obj->expr_v);
}

plat_inline void packAstPairExpr(AstPairExpr obj, Packer pkr) {
    if (is_packer_v1(pkr)) {
        pack_mmobj(0, obj->expr_k, pkr);
        pack_mmobj(1, obj->expr_v, pkr);
    }
}

MMSubObject(AstPairExpr, AstExpression, initAstPairExpr, destroyAstPairExpr, packAstPairExpr);

plat_inline int compare_for_AstPairExpr(void *this_stru, void *that_stru) {
    AstPairExpr a = toAstPairExpr(this_stru);
    AstPairExpr b = toAstPairExpr(that_stru);
    int diff = compare_mmobjs(a->expr_k, b->expr_k);
    if (diff != 0) return diff;
    return compare_mmobjs(a->expr_v, b->expr_v);
}

plat_inline AstPairExpr allocAstPairExprWithKeyAndValue(mgn_memory_pool* pool, AstExpression key, AstExpression value) {
    AstPairExpr obj = allocAstPairExpr(pool);
    if (obj) {
        obj->expr_k = retain_mmobj(key);
        obj->expr_v = retain_mmobj(value);
    }
    return obj;
}


#endif //PROC_LA_AST_CONTAINER_H



