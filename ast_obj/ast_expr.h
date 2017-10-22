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

plat_inline int compareForAstVarDeclare(void *, void *);
plat_inline AstVarDeclare initAstVarDeclare(AstVarDeclare obj, Unpacker unpkr) {
    set_compare_for_mmobj(obj, compareForAstVarDeclare);
    if (is_unpacker_v1(unpkr)) {
        obj->identifier = toAstIdentifier(unpack_mmobj_retained(0, unpkr));
        obj->identifier_type = toAstType(unpack_mmobj_retained(1, unpkr));
    }
    return obj;
}

plat_inline void destroyAstVarDeclare(AstVarDeclare obj) {
    release_mmobj(obj->identifier);
    release_mmobj(obj->identifier_type);
}

plat_inline void packAstVarDeclare(AstVarDeclare obj, Packer pkr) {
    if (is_packer_v1(pkr)) {
        pack_mmobj(0, obj->identifier, pkr);
        pack_mmobj(1, obj->identifier_type, pkr);
    }
}

MMSubObject(AstVarDeclare, AstExpression, initAstVarDeclare, destroyAstVarDeclare, packAstVarDeclare);

plat_inline int compareForAstVarDeclare(void* this_stru, void* that_stru) {
    AstVarDeclare varDeclare1 = toAstVarDeclare(this_stru);
    AstVarDeclare varDeclare2 = toAstVarDeclare(that_stru);
    int diff = compare_mmobjs(varDeclare1->identifier, varDeclare2->identifier);
    if (diff) return diff;
    return compare_mmobjs(varDeclare1->identifier_type, varDeclare2->identifier_type);
}

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

plat_inline int compareForAstVarInstance(void *, void *);
plat_inline AstVarInstance initAstVarInstant(AstVarInstance obj, Unpacker unpkr) {
    set_compare_for_mmobj(obj, compareForAstVarInstance);
    if (is_unpacker_v1(unpkr)) {
        obj->declare = toAstVarDeclare(unpack_mmobj_retained(0, unpkr));
        obj->inst = toAstVariable(unpack_mmobj_retained(1, unpkr));
    }
    return obj;
}

plat_inline void destroyAstVarInstant(AstVarInstance obj) {
    release_mmobj(obj->declare);
    release_mmobj(obj->inst);
}

plat_inline void packAstVarInstant(AstVarInstance obj, Packer pkr) {
    if (is_packer_v1(pkr)) {
        pack_mmobj(0, obj->declare, pkr);
        pack_mmobj(1, obj->inst, pkr);
    }
}

MMSubObject(AstVarInstance, AstExpression, initAstVarInstant, destroyAstVarInstant, packAstVarInstant);

plat_inline int compareForAstVarInstance(void* this_stru, void* that_stru) {
    AstVarInstance varInstance1 = toAstVarInstance(this_stru);
    AstVarInstance varInstance2 = toAstVarInstance(that_stru);
    int diff = compare_mmobjs(varInstance1->declare, varInstance2->declare);
    if (diff) return diff;
    return compare_mmobjs(varInstance1->inst, varInstance2->inst);
}

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

plat_inline int compareForAstUnaryOpExpr(void*, void*);
plat_inline AstUnaryOpExpr initAstUnaryExpr(AstUnaryOpExpr obj, Unpacker unpkr) {
    set_compare_for_mmobj(obj, compareForAstUnaryOpExpr);
    if (is_unpacker_v1(unpkr)) {
        obj->expr = toAstExpression(unpack_mmobj_retained(0, unpkr));
        obj->op = (ast_unary_op)unpack_varint(1, unpkr);
    }
    return obj;
}

plat_inline void destroyAstUnaryExpr(AstUnaryOpExpr obj) {
    release_mmobj(obj->expr);
}

plat_inline void packAstUnaryExpr(AstUnaryOpExpr obj, Packer pkr) {
    if (is_packer_v1(pkr)) {
        pack_mmobj(0, obj->expr, pkr);
        pack_varint(1, obj->op, pkr);
    }
}

MMSubObject(AstUnaryOpExpr, AstExpression, initAstUnaryExpr, destroyAstUnaryExpr, packAstUnaryExpr);

plat_inline int compareForAstUnaryOpExpr(void* this_stru, void* that_stru) {
    AstUnaryOpExpr unaryOpExpr1 = toAstUnaryOpExpr(this_stru);
    AstUnaryOpExpr unaryOpExpr2 = toAstUnaryOpExpr(that_stru);
    return FIRST_Of_2RESULTS((int)unaryOpExpr1->op - (int)unaryOpExpr2->op,
                             compare_mmobjs(unaryOpExpr1->expr, unaryOpExpr2->expr));
}

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

plat_inline int compareForAstBinaryOpExpr(void*, void*);
plat_inline AstBinaryOpExpr initAstBinaryOpExpr(AstBinaryOpExpr obj, Unpacker unpkr) {
    set_compare_for_mmobj(obj, compareForAstBinaryOpExpr);
    if (is_unpacker_v1(unpkr)) {
        obj->expr_a = toAstExpression(unpack_mmobj_retained(0, unpkr));
        obj->expr_b = toAstExpression(unpack_mmobj_retained(1, unpkr));
        obj->op = (ast_binary_op)unpack_varint(2, unpkr);
    }
    return obj;
}

plat_inline void destroyAstBinaryOpExpr(AstBinaryOpExpr obj) {
    release_mmobj(obj->expr_a);
    release_mmobj(obj->expr_b);
}

plat_inline void packAstBinaryOpExpr(AstBinaryOpExpr obj, Packer pkr) {
    if (is_packer_v1(pkr)) {
        pack_mmobj(0, obj->expr_a, pkr);
        pack_mmobj(1, obj->expr_b, pkr);
        pack_varint(2, obj->op, pkr);
    }
}

MMSubObject(AstBinaryOpExpr, AstExpression, initAstBinaryOpExpr, destroyAstBinaryOpExpr, packAstBinaryOpExpr);

plat_inline int compareForAstBinaryOpExpr(void* this_stru, void* that_stru) {
    AstBinaryOpExpr binaryOpExpr1 = toAstBinaryOpExpr(this_stru);
    AstBinaryOpExpr binaryOpExpr2 = toAstBinaryOpExpr(that_stru);
    return FIRST_Of_3RESULTS((int)binaryOpExpr1->op - (int)binaryOpExpr2->op,
                             compare_mmobjs(binaryOpExpr1->expr_a, binaryOpExpr2->expr_a),
                             compare_mmobjs(binaryOpExpr1->expr_b, binaryOpExpr2->expr_b));
}

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

plat_inline int compareForAstTernaryOpExpr(void*, void*);
plat_inline AstTernaryOpExpr initAstTernaryOpExpr(AstTernaryOpExpr obj, Unpacker unpkr) {
    set_compare_for_mmobj(obj, compareForAstTernaryOpExpr);
    if (is_unpacker_v1(unpkr)) {
        obj->expr_a = toAstExpression(unpack_mmobj_retained(0, unpkr));
        obj->expr_b = toAstExpression(unpack_mmobj_retained(1, unpkr));
        obj->expr_c = toAstExpression(unpack_mmobj_retained(2, unpkr));
        obj->op = (ast_ternary_op)unpack_varint(3, unpkr);
    }
    return obj;
}

plat_inline void destroyAstTernaryOpExpr(AstTernaryOpExpr obj) {
    release_mmobj(obj->expr_a);
    release_mmobj(obj->expr_b);
    release_mmobj(obj->expr_c);
}

plat_inline void packAstTernaryOpExpr(AstTernaryOpExpr obj, Packer pkr) {
    if (is_packer_v1(pkr)) {
        pack_mmobj(0, obj->expr_a, pkr);
        pack_mmobj(1, obj->expr_b, pkr);
        pack_mmobj(2, obj->expr_c, pkr);
        pack_varint(3, obj->op, pkr);
    }
}

MMSubObject(AstTernaryOpExpr, AstExpression, initAstTernaryOpExpr, destroyAstTernaryOpExpr, packAstTernaryOpExpr);

plat_inline int compareForAstTernaryOpExpr(void* this_stru, void* that_stru) {
    AstTernaryOpExpr ternaryOpExpr1 = toAstTernaryOpExpr(this_stru);
    AstTernaryOpExpr ternaryOpExpr2 = toAstTernaryOpExpr(that_stru);
    return FIRST_Of_4RESULTS((int)ternaryOpExpr1->op - (int)ternaryOpExpr2->op,
                             compare_mmobjs(ternaryOpExpr1->expr_a, ternaryOpExpr2->expr_a),
                             compare_mmobjs(ternaryOpExpr1->expr_b, ternaryOpExpr2->expr_b),
                             compare_mmobjs(ternaryOpExpr1->expr_c, ternaryOpExpr2->expr_c));
}

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

plat_inline int compareForAstIsExpr(void*, void*);
plat_inline AstIsExpr initAstIsExpr(AstIsExpr obj, Unpacker unpkr) {
    set_compare_for_mmobj(obj, compareForAstIsExpr);
    if (is_unpacker_v1(unpkr)) {
        obj->expr = toAstExpression(unpack_mmobj_retained(0, unpkr));
        obj->type = toAstType(unpack_mmobj_retained(1, unpkr));
    }
    return obj;
}

plat_inline void destroyAstIsExpr(AstIsExpr obj) {
    release_mmobj(obj->expr);
    release_mmobj(obj->type);
}

plat_inline void packAstIsExpr(AstIsExpr obj, Packer pkr) {
    if (is_packer_v1(pkr)) {
        pack_mmobj(0, obj->expr, pkr);
        pack_mmobj(1, obj->type, pkr);
    }
}

MMSubObject(AstIsExpr, AstExpression, initAstIsExpr, destroyAstIsExpr, packAstIsExpr);

plat_inline int compareForAstIsExpr(void* this_stru, void* that_stru) {
    AstIsExpr isExpr1 = toAstIsExpr(this_stru);
    AstIsExpr isExpr2 = toAstIsExpr(that_stru);
    return FIRST_Of_2RESULTS(compare_mmobjs(isExpr1->type, isExpr2->type),
                             compare_mmobjs(isExpr1->expr, isExpr2->expr));
}
plat_inline AstIsExpr allocAstIsExprWithExprAndType(mgn_memory_pool* pool, AstExpression expr, AstType type) {
    AstIsExpr obj = allocAstIsExpr(pool);
    if (obj) {
        obj->expr = retain_mmobj(expr);
        obj->type = retain_mmobj(type);
    }
    return obj;
}

#endif //PROC_LA_AST_EXPR_H
