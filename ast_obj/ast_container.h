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

typedef struct AstExprContainer {
    ast_container_type type;
    bool closed;
    MMList list;
}*AstExprContainer;

plat_inline AstExprContainer initAstContainer(AstExprContainer obj, Unpacker unpkr) {
    obj->closed = false;
    obj->list = allocMMList(pool_of_mmobj(obj));
    return obj->list?obj:null;
}

plat_inline void destroyAstContainer(AstExprContainer obj) {
    release_mmobj(obj->list);
}

plat_inline void packAstContainer(AstExprContainer obj, Packer pkr) {

}

MMSubObject(AST_EXPR_CONTAINER, AstExprContainer, AstExpression, initAstContainer, destroyAstContainer, packAstContainer);

plat_inline AstExprContainer allocAstExprContainerWithType(mgn_memory_pool* pool, ast_container_type type) {
    AstExprContainer exprContainer = allocAstExprContainer(pool);
    if (exprContainer) {
        exprContainer->type = type;
    }
    return exprContainer;
}

plat_inline bool isExprContainerClosed(AstExprContainer exprList) {
    return exprList->closed;
}

// If closed, it can't add more expressions.
plat_inline void closeExprContainer(AstExprContainer exprContainer) {
    exprContainer->closed = true;
}

plat_inline void addExprToExprContainer(AstExprContainer exprContainer, AstExpression expr) {
    pushMMListItem(exprContainer->list, toMMObject(expr));
}

plat_inline void insertExprToExprContainerAt(AstExprContainer exprContainer, AstExpression expr, uint idx) {
    insertMMListItem(exprContainer->list, toMMObject(expr), idx);
}

plat_inline void concatExprContainer(AstExprContainer exprContainer1, AstExprContainer exprContainer2) {
    concatMMList(exprContainer1->list, exprContainer2->list);
}

plat_inline uint sizeOfExprContainer(AstExprContainer exprContainer) {
    return sizeOfMMList(exprContainer->list);
}

plat_inline AstExpression getExprFromExprContainerAt(AstExprContainer exprContainer, uint idx) {
    return toAstExpression(getMMListItem(exprContainer->list, idx));
}

plat_inline ast_container_type getExprContainerType(AstExprContainer exprContainer) {
    return exprContainer->type;
}

/*plat_inline void setExprContainerType(AstExprContainer exprContainer, ast_container_type type) {
    exprContainer->type = type;
}*/

/// ===== Expr - Pair =====

typedef struct AstExprPair {
    AstExpression expr_k;
    AstExpression expr_v;
}*AstExprPair;

plat_inline AstExprPair initAstExprPair(AstExprPair obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstExprPair(AstExprPair obj) {
    release_mmobj(obj->expr_k);
    release_mmobj(obj->expr_v);
}

plat_inline void packAstExprPair(AstExprPair obj, Packer pkr) {

}

MMSubObject(AST_EXPR_PAIR, AstExprPair, AstExpression, initAstExprPair, destroyAstExprPair, packAstExprPair);

plat_inline AstExprPair allocAstExprPairWithKeyAndValue(mgn_memory_pool* pool, AstExpression key, AstExpression value) {
    AstExprPair obj = allocAstExprPair(pool);
    if (obj) {
        obj->expr_k = retain_mmobj(key);
        obj->expr_v = retain_mmobj(value);
    }
    return obj;
}


#endif //PROC_LA_AST_CONTAINER_H



