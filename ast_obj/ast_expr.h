//
// Created by Yuchi Chen on 2017/9/23.
//

#ifndef PROC_LA_AST_EXPR_H
#define PROC_LA_AST_EXPR_H

#include "ast_stmt.h"

/// ===== Expr - Var Instance =====
/**
 * Includes two parts:
 *   var declare
 *   variable
 */

typedef struct AstVarInstance {
    AstVarDeclare declare;
    AstVariable inst;
}*AstVarInstance;

plat_inline AstVarInstance initAstVarInstant(AstVarInstance obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstVarInstant(AstVarInstance obj) {
    if (obj->declare) {
        release_mmobj(obj->declare);
    }
    if (obj->inst) {
        release_mmobj(obj->inst);
    }
}

plat_inline void packAstVarInstant(AstVarInstance obj, Packer pkr) {

}

MMSubObject(AST_VAR_INSTANCE, AstVarInstance, AstExpression, initAstVarInstant, destroyAstVarInstant, packAstVarInstant);

plat_inline AstVarInstance allocAstVarInstantWithDeclareAndInstance(mgn_memory_pool* pool, AstVarDeclare declare, AstVariable instance) {
    if (declare == null) {
        plat_io_printf_err("Declare can not be null\n");
        return null;
    }
    if (instance == null) {
        plat_io_printf_err("Instance can't be null\n");
        return null;
    }

    AstVarInstance obj = allocAstVarInstance(pool);
    if (obj) {
        obj->declare = retain_mmobj(declare);
        obj->inst = retain_mmobj(instance);
    }
    return obj;
}


/// ===== Expr - () =====

typedef struct AstParenthesesExpr {
    AstExpression expr;
}*AstParenthesesExpr;

plat_inline AstParenthesesExpr initAstParenthesesExpr(AstParenthesesExpr obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstParenthesesExpr(AstParenthesesExpr obj) {
    if (obj->expr) {
        release_mmobj(obj->expr);
    }
}

plat_inline void packAstParenthesesExpr(AstParenthesesExpr obj, Packer pkr) {

}

MMSubObject(AST_PARENTHESES_EXPR, AstParenthesesExpr, AstExpression , initAstParenthesesExpr, destroyAstParenthesesExpr, packAstParenthesesExpr);

plat_inline AstParenthesesExpr allocAstParenthesesExprWithExpr(mgn_memory_pool* pool, AstExpression expr) {
    AstParenthesesExpr obj = allocAstParenthesesExpr(pool);
    if (obj) {
        obj->expr = retain_mmobj(expr);
    }
    return obj;
}


/// ===== Expr - Unary Op =====

typedef struct AstUnaryOpExpr {
    AstExpression expr;
    ast_unary_op op;
}*AstUnaryOpExpr;

plat_inline AstUnaryOpExpr initAstUnaryExpr(AstUnaryOpExpr obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstUnaryExpr(AstUnaryOpExpr obj) {
    if (obj->expr) {
        release_mmobj(obj->expr);
    }
}

plat_inline void packAstUnaryExpr(AstUnaryOpExpr obj, Packer pkr) {

}

MMSubObject(AST_UNARY_OP_EXPR, AstUnaryOpExpr, AstExpression, initAstUnaryExpr, destroyAstUnaryExpr, packAstUnaryExpr);

plat_inline AstUnaryOpExpr allocAstUnaryOpExprWithOp(mgn_memory_pool* pool, AstExpression expr, ast_unary_op op) {
    AstUnaryOpExpr obj = allocAstUnaryOpExpr(pool);
    if (obj) {
        obj->expr = retain_mmobj(expr);
        obj->op = op;
    }
    return obj;
}

/// ===== Expr - Binary Op =====

typedef struct AstBinaryOpExpr {
    AstExpression expr_a;
    AstExpression expr_b;
    ast_binary_op op;
}*AstBinaryOpExpr;

plat_inline AstBinaryOpExpr initAstBinaryOpExpr(AstBinaryOpExpr obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstBinaryOpExpr(AstBinaryOpExpr obj) {
    if (obj->expr_a) {
        release_mmobj(obj->expr_a);
    }
    if (obj->expr_b) {
        release_mmobj(obj->expr_b);
    }
}

plat_inline void packAstBinaryOpExpr(AstBinaryOpExpr obj, Packer pkr) {

}

MMSubObject(AST_BINARY_OP_EXPR, AstBinaryOpExpr, AstExpression, initAstBinaryOpExpr, destroyAstBinaryOpExpr, packAstBinaryOpExpr);

plat_inline AstBinaryOpExpr allocAstBinaryOpExprWithOp(mgn_memory_pool* pool, AstExpression expr_a, AstExpression expr_b, ast_binary_op op) {
    AstBinaryOpExpr obj = allocAstBinaryOpExpr(pool);
    if (obj) {
        obj->expr_a = retain_mmobj(expr_a);
        obj->expr_b = retain_mmobj(expr_b);
        obj->op = op;
    }
    return obj;
}

/// =====  =====

typedef struct AstTernaryOpExpr {
    AstExpression expr_a;
    AstExpression expr_b;
    AstExpression expr_c;
    ast_ternary_op op;
}*AstTernaryOpExpr;

plat_inline AstTernaryOpExpr initAstTernaryOpExpr(AstTernaryOpExpr obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstTernaryOpExpr(AstTernaryOpExpr obj) {
    if (obj->expr_a) {
        release_mmobj(obj->expr_a);
    }
    if (obj->expr_b) {
        release_mmobj(obj->expr_b);
    }
    if (obj->expr_c) {
        release_mmobj(obj->expr_c);
    }
}

plat_inline void packAstTernaryOpExpr(AstTernaryOpExpr obj, Packer pkr) {

}

MMSubObject(AST_TERNARY_OP_EXPR, AstTernaryOpExpr, AstExpression, initAstTernaryOpExpr, destroyAstTernaryOpExpr, packAstTernaryOpExpr);

plat_inline AstTernaryOpExpr allocAstTernaryOpExprWithOp(mgn_memory_pool* pool, AstExpression expr_a, AstExpression expr_b, AstExpression expr_c, ast_ternary_op op) {
    AstTernaryOpExpr obj = allocAstTernaryOpExpr(pool);
    if (obj) {
        obj->expr_a = retain_mmobj(expr_a);
        obj->expr_b = retain_mmobj(expr_b);
        obj->expr_c = retain_mmobj(expr_c);
        obj->op = op;
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
