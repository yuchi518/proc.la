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

plat_inline int compareForAstContainerExpr(void *, void *);
plat_inline AstContainerExpr initAstContainer(AstContainerExpr obj, Unpacker unpkr) {
    set_compare_for_mmobj(obj, compareForAstContainerExpr);
    if (is_unpacker_v1(unpkr)) {
        obj->type = (ast_container_type)unpack_varint(0, unpkr);
        obj->closed = unpack_bool(1, unpkr);
        obj->list = toMMList(unpack_mmobj_retained(2, unpkr));
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

plat_inline AstContainerExpr allocEmptyAstContainerExprWithType(mgn_memory_pool* pool, ast_container_type type) {
    AstContainerExpr containerExpr = allocAstContainerExpr(pool);
    if (containerExpr) {
        containerExpr->type = type;
        containerExpr->closed = true;
    }
    return containerExpr;
}

plat_inline int compareForAstContainerExpr(void* this_stru, void* that_stru) {
    int r = compareForAstStatement(this_stru, that_stru);
    if (r) return r;
    AstContainerExpr a = toAstContainerExpr(this_stru);
    AstContainerExpr b = toAstContainerExpr(that_stru);
    return FIRST_Of_3RESULTS((int)a->type - (int)b->type,
                             (a->closed?1:0) - (b->closed?1:0),
                             compare_mmobjs(a->list, b->list));
}

plat_inline bool isContainerExprClosed(AstContainerExpr exprList) {
    return exprList->closed;
}

// If closed, it can't add more expressions.
plat_inline void closeContainerExpr(AstContainerExpr containerExpr) {
    containerExpr->closed = true;
}

plat_inline void addExprToContainerExpr(AstContainerExpr containerExpr, AstExpression expr) {
    pushMMListItem(containerExpr->list, toMMObject(expr));
}

plat_inline void insertExprToContainerExprAt(AstContainerExpr containerExpr, AstExpression expr, uint idx) {
    insertMMListItem(containerExpr->list, toMMObject(expr), idx);
}

plat_inline void concatContainerExpr(AstContainerExpr containerExpr1, AstContainerExpr containerExpr2) {
    concatMMList(containerExpr1->list, containerExpr2->list);
}

plat_inline uint sizeOfContainerExpr(AstContainerExpr containerExpr) {
    return sizeOfMMList(containerExpr->list);
}

plat_inline AstExpression getExprFromContainerExprAt(AstContainerExpr containerExpr, uint idx) {
    return toAstExpression(getMMListItem(containerExpr->list, idx));
}

plat_inline ast_container_type getContainerExprType(AstContainerExpr containerExpr) {
    return containerExpr->type;
}

/*plat_inline void setContainerExprType(AstContainerExpr containerExpr, ast_container_type type) {
    containerExpr->type = type;
}*/

/// ===== Expr - Pair =====

typedef struct AstPairExpr {
    AstExpression expr_k;
    AstExpression expr_v;
}*AstPairExpr;

plat_inline int compareForAstPairExpr(void *, void *);
plat_inline AstPairExpr initAstPairExpr(AstPairExpr obj, Unpacker unpkr) {
    set_compare_for_mmobj(obj, compareForAstPairExpr);
    if (is_unpacker_v1(unpkr)) {
        obj->expr_k = toAstExpression(unpack_mmobj_retained(0, unpkr));
        obj->expr_v = toAstExpression(unpack_mmobj_retained(1, unpkr));
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

plat_inline int compareForAstPairExpr(void* this_stru, void* that_stru) {
    int r = compareForAstStatement(this_stru, that_stru);
    if (r) return r;
    AstPairExpr a = toAstPairExpr(this_stru);
    AstPairExpr b = toAstPairExpr(that_stru);
    return FIRST_Of_2RESULTS(compare_mmobjs(a->expr_k, b->expr_k),
                             compare_mmobjs(a->expr_v, b->expr_v));
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



