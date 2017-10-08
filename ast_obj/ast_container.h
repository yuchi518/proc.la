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

plat_inline AstContainerExpr initAstContainer(AstContainerExpr obj, Unpacker unpkr) {
    obj->closed = false;
    obj->list = allocMMList(pool_of_mmobj(obj));
    return obj->list?obj:null;
}

plat_inline void destroyAstContainer(AstContainerExpr obj) {
    release_mmobj(obj->list);
}

plat_inline void packAstContainer(AstContainerExpr obj, Packer pkr) {

}

MMSubObject(AST_CONTAINER_EXPR, AstContainerExpr, AstExpression, initAstContainer, destroyAstContainer, packAstContainer);

plat_inline AstContainerExpr allocAstContainerExprWithType(mgn_memory_pool* pool, ast_container_type type) {
    AstContainerExpr containerExpr = allocAstContainerExpr(pool);
    if (containerExpr) {
        containerExpr->type = type;
    }
    return containerExpr;
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

plat_inline AstPairExpr initAstPairExpr(AstPairExpr obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstPairExpr(AstPairExpr obj) {
    release_mmobj(obj->expr_k);
    release_mmobj(obj->expr_v);
}

plat_inline void packAstPairExpr(AstPairExpr obj, Packer pkr) {

}

MMSubObject(AST_PAIR_EXPR, AstPairExpr, AstExpression, initAstPairExpr, destroyAstPairExpr, packAstPairExpr);

plat_inline AstPairExpr allocAstPairExprWithKeyAndValue(mgn_memory_pool* pool, AstExpression key, AstExpression value) {
    AstPairExpr obj = allocAstPairExpr(pool);
    if (obj) {
        obj->expr_k = retain_mmobj(key);
        obj->expr_v = retain_mmobj(value);
    }
    return obj;
}


#endif //PROC_LA_AST_CONTAINER_H



