//
// Created by Yuchi Chen on 2017/9/23.
//

#ifndef PROC_LA_AST_EXPR_H
#define PROC_LA_AST_EXPR_H

#include "ast_node.h"

/// ===== Expression =====

typedef struct AstExpression {

}*AstExpression;

plat_inline AstExpression initAstExpression(AstExpression obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstExpression(AstExpression obj) {

}

plat_inline void packAstExpression(AstExpression obj, Packer pkr) {

}

MMSubObject(AST_EXPRESSION, AstExpression, AstNode, initAstExpression, destroyAstExpression, packAstExpression);

plat_inline AstExpression allocAstExpressionWith(mgn_memory_pool* pool, ...) {
    AstExpression obj = allocAstExpression(pool);
    if (obj) {
    }
    return obj;
}

/// ===== Apply Chain =====

typedef struct AstApplyChain {

}*AstApplyChain;

plat_inline AstApplyChain initAstApplyChain(AstApplyChain obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstApplyChain(AstApplyChain obj) {

}

plat_inline void packAstApplyChain(AstApplyChain obj, Packer pkr) {

}

MMSubObject(AST_APPLY_CHAIN, AstApplyChain, AstExpression, initAstApplyChain, destroyAstApplyChain, packAstApplyChain);

plat_inline AstApplyChain allocAstApplyChainWith(mgn_memory_pool* pool, ...) {
    AstApplyChain obj = allocAstApplyChain(pool);
    if (obj) {
    }
    return obj;
}


#endif //PROC_LA_AST_EXPR_H
