//
// Created by Yuchi Chen on 2017/9/16.
//

#ifndef PROC_LA_AST_NODE_H
#define PROC_LA_AST_NODE_H

#include "mmObj.h"
#include "mmObj_lib.h"

#include "mmObj_unittest.h"

enum {
    AST_NODE     = 0,

    AST_CTRL,
    AST_CTRL_FLOW,

    AST_IDENTIFIER,

    AST_TYPE,
    AST_TYPE_COMBINATION,

    AST_STATEMENT,
    AST_PACKAGE,
    AST_VAR_DECLARE,                    // variable type & name
    AST_VAR_LIST_DECLARATION,           // A list of var declarations, ex. A La input
    AST_TYPE_LIST_DECLARATION,          // A list of type declarations, ex. A La output
    AST_LA_BODY_DECLARATION,            // A la body
    AST_EXTERNAL_DECLARATIONS,
    AST_A_LA,                           // input + body + output

    AST_EXPRESSION,

    AST_NONE,

    AST_VARIABLE,                       // primary type variable
    AST_VARIABLE_COMBINATION,
    AST_VARIABLE_DOMAIN_NAME,
    //AST_VARIABLE_LIST,
    //AST_VARIABLE_MAP,

    AST_EXPR_CONTAINER,
    AST_EXPR_PAIR,

    AST_VAR_INSTANCE,
    AST_PARENTHESES_EXPR,
    AST_UNARY_OP_EXPR,
    AST_BINARY_OP_EXPR,
    AST_TERNARY_OP_EXPR,
    AST_APPLY_CHAIN,

    AST_A_PROC_LA,                      // A proc.la file

    AST_STACK,
    AST_SCOPE,

};

typedef enum {
    ast_type_var             = 0,
    ast_type_int,
    ast_type_long,
    ast_type_float,
    ast_type_double,
    ast_type_number,
    ast_type_string,
    ast_type_raw,
    ast_type_proc,
    ast_type_la,
} ast_type;

typedef enum {
    ast_type_list   = 1,
    ast_type_map    = 2,
} ast_type_combination;

plat_inline const char* ast_type_name(ast_type type) {
    switch(type) {
        case ast_type_var: return "var";
        case ast_type_int: return "int";
        case ast_type_long: return "long";
        case ast_type_float: return "float";
        case ast_type_double: return "double";
        case ast_type_number: return "number";
        case ast_type_string: return "string";
        case ast_type_raw: return "raw";
        case ast_type_proc: return "proc";
        case ast_type_la: return "la";
        default: return "Unknown";
    }
}

typedef enum {
    ast_container_type_list = 1,
    ast_container_type_map = 2,
    ast_container_type_tuple = 3,
} ast_container_type;

typedef enum {
    ast_unary_op_plus,      // +
    ast_unary_op_minus,     // -
    ast_unary_op_invert,    // ~
    ast_unary_op_not,       // !

    ast_unary_op_inc_f,     // ++N
    ast_unary_op_inc_l,     // N++
    ast_unary_op_dec_f,     // --N
    ast_unary_op_dec_l,     // N--
} ast_unary_op;

typedef enum {
    ast_binary_op_add,
    ast_binary_op_subtract,
    ast_binary_op_multiply,
    ast_binary_op_divide,
    ast_binary_op_modulo,

    ast_binary_op_list_access,
    ast_binary_op_map_access,

    ast_binary_op_shift_left,
    ast_binary_op_shift_right,

    ast_binary_op_equal,
    ast_binary_op_not_equal,
    ast_binary_op_less,
    ast_binary_op_great,
    ast_binary_op_less_or_equal,
    ast_binary_op_great_or_equal,
    ast_binary_op_and,
    ast_binary_op_or,

    ast_binary_op_bit_and,
    ast_binary_op_bit_or,
    ast_binary_op_bit_xor,
} ast_binary_op;

typedef enum {
    ast_ternary_op_conditional,
} ast_ternary_op;

/// ===== Abstract Tree node =====
typedef struct AstNode {

}*AstNode;

plat_inline AstNode initAstNode(AstNode obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstNode(AstNode obj) {

}

plat_inline void packAstNode(AstNode obj, Packer pkr) {

}

MMSubObject(AST_NODE, AstNode, MMObject , initAstNode, destroyAstNode, packAstNode);

/// ===== Statement =====

typedef struct AstStatement {

}*AstStatement;

plat_inline AstStatement initAstStatement(AstStatement obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstStatement(AstStatement obj) {

}

plat_inline void packAstStatement(AstStatement obj, Packer pkr) {

}

MMSubObject(AST_STATEMENT, AstStatement, AstNode , initAstStatement, destroyAstStatement, packAstStatement);

plat_inline AstStatement allocAstStatementWith(mgn_memory_pool* pool, ...) {
    AstStatement obj = allocAstStatement(pool);
    if (obj) {
    }
    return obj;
}

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

MMSubObject(AST_EXPRESSION, AstExpression, AstStatement , initAstExpression, destroyAstExpression, packAstExpression);

plat_inline AstExpression allocAstExpressionWith(mgn_memory_pool* pool, ...) {
    AstExpression obj = allocAstExpression(pool);
    if (obj) {
    }
    return obj;
}

/// ===== NONE =====

typedef struct AstNone {

}*AstNone;

plat_inline AstNone initAstNone(AstNone obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstNone(AstNone obj) {

}

plat_inline void packAstNone(AstNone obj, Packer pkr) {

}

MMSubObject(AST_NONE, AstNone, AstExpression, initAstNone, destroyAstNone, packAstNone);


/// ===== Variable =====
/**
 * One of following variables:
 *  int, long, float, double, number, string, raw
 *  list, map, la
 */

typedef struct AstVariable {
    ast_type type;
    bool is_const;
    MMObject value;
}*AstVariable;

plat_inline AstVariable initAstVariable(AstVariable obj, Unpacker unpkr) {
    obj->type = ast_type_var;
    obj->is_const = false;
    return obj;
}

plat_inline void destroyAstVariable(AstVariable obj) {
    if (obj->value) {
        release_mmobj(obj->value);
    }
}

plat_inline void packAstVariable(AstVariable obj, Packer pkr) {

}

MMSubObject(AST_VARIABLE, AstVariable, AstExpression, initAstVariable, destroyAstVariable, packAstVariable);

plat_inline AstVariable allocVariableWithIntValue(mgn_memory_pool* pool, int32 value)
{
    AstVariable obj = allocAstVariable(pool);
    if (obj) {
        obj->type = ast_type_int;
        obj->value = toMMObject(allocMMIntWithValue(pool, value));
        if (obj->value == null) {
            release_mmobj(obj);
            obj = null;
        }
    }
    return obj;
}

plat_inline AstVariable allocVariableWithConstIntValue(mgn_memory_pool* pool, int32 value)
{
    AstVariable obj = allocVariableWithIntValue(pool, value);
    if (obj) {
        obj->is_const = true;
    }
    return obj;
}

plat_inline AstVariable allocVariableWithLongValue(mgn_memory_pool* pool, int64 value)
{
    AstVariable obj = allocAstVariable(pool);
    if (obj) {
        obj->type = ast_type_long;
        obj->value = toMMObject(allocMMLongWithValue(pool, value));
        if (obj->value == null) {
            release_mmobj(obj);
            obj = null;
        }
    }
    return obj;
}

plat_inline AstVariable allocVariableWithConstLongValue(mgn_memory_pool* pool, int64 value)
{
    AstVariable obj = allocVariableWithLongValue(pool, value);
    if (obj) {
        obj->is_const = true;
    }
    return obj;
}

plat_inline AstVariable allocVariableWithFloatValue(mgn_memory_pool* pool, float value)
{
    AstVariable obj = allocAstVariable(pool);
    if (obj) {
        obj->type = ast_type_float;
        obj->value = toMMObject(allocMMFloatWithValue(pool, value));
        if (obj->value == null) {
            release_mmobj(obj);
            obj = null;
        }
    }
    return obj;
}

plat_inline AstVariable allocVariableWithConstFloatValue(mgn_memory_pool* pool, float value)
{
    AstVariable obj = allocVariableWithFloatValue(pool, value);
    if (obj) {
        obj->is_const = true;
    }
    return obj;
}


plat_inline AstVariable allocVariableWithDoubleValue(mgn_memory_pool* pool, double value)
{
    AstVariable obj = allocAstVariable(pool);
    if (obj) {
        obj->type = ast_type_double;
        obj->value = toMMObject(allocMMDoubleWithValue(pool, value));
        if (obj->value == null) {
            release_mmobj(obj);
            obj = null;
        }
    }
    return obj;
}

plat_inline AstVariable allocVariableWithConstDoubleValue(mgn_memory_pool* pool, double value)
{
    AstVariable obj = allocVariableWithDoubleValue(pool, value);
    if (obj) {
        obj->is_const = true;
    }
    return obj;
}

plat_inline AstVariable allocVariableWithNumberValue(mgn_memory_pool* pool, double value)
{
    AstVariable obj = allocAstVariable(pool);
    if (obj) {
        obj->type = ast_type_number;
        /// TODO: implementation
    }
    return obj;
}

plat_inline AstVariable allocVariableWithConstNumberValue(mgn_memory_pool* pool, double value)
{
    AstVariable obj = allocVariableWithNumberValue(pool, value);
    if (obj) {
        obj->is_const = true;
    }
    return obj;
}

plat_inline AstVariable allocVariableWithCString(mgn_memory_pool* pool, char* cstring)
{
    AstVariable obj = allocAstVariable(pool);
    if (obj) {
        obj->type = ast_type_string;
        obj->value = toMMObject(allocMMStringWithCString(pool, cstring));
        if (obj->value == null) {
            release_mmobj(obj);
            obj = null;
        }
    }
    return obj;
}

plat_inline AstVariable allocVariableWithConstCString(mgn_memory_pool* pool, char* cstring)
{
    AstVariable obj = allocVariableWithCString(pool, cstring);
    if (obj) {
        obj->is_const = true;
    }
    return obj;
}

plat_inline AstVariable allocVariableWithRawData(mgn_memory_pool* pool, void* data, uint size) {
    AstVariable obj = allocAstVariable(pool);
    if (obj) {
        obj->type = ast_type_raw;
        obj->value = toMMObject(allocMMDataWithData(pool, data, size));
        if (obj->value == null) {
            release_mmobj(obj);
            return null;
        }
    }
    return obj;
}

/// ===== Identifier =====

typedef struct AstIdentifier {
    MMString name;
}*AstIdentifier;

plat_inline AstIdentifier initAstIdentifier(AstIdentifier obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstIdentifier(AstIdentifier obj) {
    if (obj->name) {
        release_mmobj(obj->name);
        obj->name = null;
    }
}

plat_inline void packAstIdentifier(AstIdentifier obj, Packer pkr) {

}

MMSubObject(AST_IDENTIFIER, AstIdentifier, AstExpression, initAstIdentifier, destroyAstIdentifier, packAstIdentifier);

plat_inline AstIdentifier allocAstIdentifierWithName(mgn_memory_pool* pool, MMString name) {
    if (name == null) {
        plat_io_printf_err("Identifier should have a name\n");
        return null;
    }

    AstIdentifier obj = allocAstIdentifier(pool);
    if (obj) {
        obj->name = retain_mmobj(name);
    }
    return obj;
}

plat_inline AstIdentifier allocAstIdentifierWithCStringName(mgn_memory_pool* pool, char* name) {
    if (name == null) {
        plat_io_printf_err("Identifier should have a name\n");
        return null;
    }

    return allocAstIdentifierWithName(pool, autorelease_mmobj(allocMMStringWithCString(pool, name)));
}

#endif //PROC_LA_AST_NODE_H
