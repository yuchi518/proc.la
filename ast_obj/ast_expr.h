//
// Created by Yuchi Chen on 2017/9/23.
//

#ifndef PROC_LA_AST_EXPR_H
#define PROC_LA_AST_EXPR_H

#include "ast_stmt.h"


/// ===== Statement - Var Declaration =====
/**
 * Includes two parts:
 *   variable identifier
 *   variable type
 */
typedef struct AstVarDeclare {
    AstIdentifier identifier;
    AstType identifier_type;
}*AstVarDeclare;

plat_inline AstVarDeclare initAstVarDeclare(AstVarDeclare obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstVarDeclare(AstVarDeclare obj) {
    release_mmobj(obj->identifier);
    release_mmobj(obj->identifier_type);
}

plat_inline void packAstVarDeclare(AstVarDeclare obj, Packer pkr) {

}

MMSubObject(AstVarDeclare, AstExpression, initAstVarDeclare, destroyAstVarDeclare, packAstVarDeclare);


plat_inline AstVarDeclare allocAstVarDeclareWithIdentifier(mgn_memory_pool* pool, AstIdentifier identifier, AstType type) {
    if (identifier == null) {
        plat_io_printf_err("Identifier can't be null\n");
        return null;
    }
    AstVarDeclare obj = allocAstVarDeclare(pool);
    if (obj) {
        obj->identifier = retain_mmobj(identifier);
        obj->identifier_type = retain_mmobj(type);
    }
    return obj;
}

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
    release_mmobj(obj->declare);
    release_mmobj(obj->inst);
}

plat_inline void packAstVarInstant(AstVarInstance obj, Packer pkr) {

}

MMSubObject(AstVarInstance, AstExpression, initAstVarInstant, destroyAstVarInstant, packAstVarInstant);

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

/// ===== Expr - Unary Op =====

typedef struct AstUnaryOpExpr {
    AstExpression expr;
    ast_unary_op op;
}*AstUnaryOpExpr;

plat_inline AstUnaryOpExpr initAstUnaryExpr(AstUnaryOpExpr obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstUnaryExpr(AstUnaryOpExpr obj) {
    release_mmobj(obj->expr);
}

plat_inline void packAstUnaryExpr(AstUnaryOpExpr obj, Packer pkr) {

}

MMSubObject(AstUnaryOpExpr, AstExpression, initAstUnaryExpr, destroyAstUnaryExpr, packAstUnaryExpr);

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
    release_mmobj(obj->expr_a);
    release_mmobj(obj->expr_b);
}

plat_inline void packAstBinaryOpExpr(AstBinaryOpExpr obj, Packer pkr) {

}

MMSubObject(AstBinaryOpExpr, AstExpression, initAstBinaryOpExpr, destroyAstBinaryOpExpr, packAstBinaryOpExpr);

plat_inline AstBinaryOpExpr allocAstBinaryOpExprWithExprsAndOp(mgn_memory_pool* pool, AstExpression expr_a, AstExpression expr_b, ast_binary_op op) {
    AstBinaryOpExpr obj = allocAstBinaryOpExpr(pool);
    if (obj) {
        obj->expr_a = retain_mmobj(expr_a);
        obj->expr_b = retain_mmobj(expr_b);
        obj->op = op;
    }
    return obj;
}

plat_inline AstBinaryOpExpr allocAstBinaryOpExprWithOp(mgn_memory_pool* pool, ast_binary_op op) {
    AstBinaryOpExpr obj = allocAstBinaryOpExpr(pool);
    if (obj) {
        obj->op = op;
    }
    return obj;
}

plat_inline void applyExprAtoBinaryOpExpr(AstBinaryOpExpr opExpr, AstExpression expr_a) {
    release_mmobj(opExpr->expr_a);
    opExpr->expr_a = retain_mmobj(expr_a);
}

plat_inline void applyExprBtoBinaryOpExpr(AstBinaryOpExpr opExpr, AstExpression expr_b) {
    release_mmobj(opExpr->expr_b);
    opExpr->expr_b = retain_mmobj(expr_b);
}

/// ===== Expr - Ternary Op =====

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
    release_mmobj(obj->expr_a);
    release_mmobj(obj->expr_b);
    release_mmobj(obj->expr_c);
}

plat_inline void packAstTernaryOpExpr(AstTernaryOpExpr obj, Packer pkr) {

}

MMSubObject(AstTernaryOpExpr, AstExpression, initAstTernaryOpExpr, destroyAstTernaryOpExpr, packAstTernaryOpExpr);

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

/// ===== Expression - IS =====

typedef struct AstIsExpr {
    AstExpression expr;
    AstType type;
}*AstIsExpr;

plat_inline AstIsExpr initAstIsExpr(AstIsExpr obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstIsExpr(AstIsExpr obj) {
    release_mmobj(obj->expr);
    release_mmobj(obj->type);
}

plat_inline void packAstIsExpr(AstIsExpr obj, Packer pkr) {

}

MMSubObject(AstIsExpr, AstExpression, initAstIsExpr, destroyAstIsExpr, packAstIsExpr);

plat_inline AstIsExpr allocAstIsExprWithExprAndType(mgn_memory_pool* pool, AstExpression expr, AstType type) {
    AstIsExpr obj = allocAstIsExpr(pool);
    if (obj) {
        obj->expr = retain_mmobj(expr);
        obj->type = retain_mmobj(type);
    }
    return obj;
}

#endif //PROC_LA_AST_EXPR_H
