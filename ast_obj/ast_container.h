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
    bool closed;
    MMList list;
}*AstExprContainer;

plat_inline AstExprContainer initAstContainer(AstExprContainer obj, Unpacker unpkr) {
    obj->closed = false;
    obj->list = allocMMList(pool_of_mmobj(obj));
    return obj->list?obj:null;
}

plat_inline void destroyAstContainer(AstExprContainer obj) {
    if (obj->list) release_mmobj(obj->list);
}

plat_inline void packAstContainer(AstExprContainer obj, Packer pkr) {

}

MMSubObject(AST_EXPR_CONTAINER, AstExprContainer, AstExpression, initAstContainer, destroyAstContainer, packAstContainer);

plat_inline bool isExprListclosed(AstExprContainer exprList) {
    return exprList->closed;
}

// If closed, it can't add more expressions.
plat_inline void closeExprList(AstExprContainer exprList) {
    exprList->closed = true;
}

plat_inline void addExprToExprList(AstExprContainer exprList, AstExpression expr) {
    pushMMListItem(exprList->list, toMMObject(expr));
}

plat_inline void concatExprList(AstExprContainer exprList1, AstExprContainer exprList2) {
    concatMMList(exprList1->list, exprList2->list);
}

plat_inline uint sizeOfExprList(AstExprContainer exprList) {
    return sizeOfMMList(exprList->list);
}

plat_inline AstExpression getExprFromExprListAt(AstExprContainer exprList, uint idx) {
    return toAstExpression(getMMListItem(exprList->list, idx));
}




#endif //PROC_LA_AST_CONTAINER_H



