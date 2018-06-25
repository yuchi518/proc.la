//
// Created by Yuchi Chen on 2017/9/16.
//

#ifndef PROC_LA_AST_NODE_H
#define PROC_LA_AST_NODE_H

#include "mmo.h"
#include "mmo_ext.h"
#include "mmo_pack.h"

/*enum {
    AST_NODE     = 0,

    AST_TYPE,
    AST_TYPE_COMBINATION,

    AST_STATEMENT,
    AST_PACKAGE,
    AST_TYPE_LIST_DECLARATION,          // A list of type declarations, ex. A La output
    AST_BLOCK,                          // A block statement, aka "{ .... }", include a la body.
    AST_CASE,                           // case XXX: statement;
    AST_SWITCH,
    AST_IF,
    AST_LOOP,
    AST_EACH,
    AST_JUMP,                           // break, continue, goto, etc.
    AST_ANCHOR,                         // label
    AST_EXTERNAL_DECLARATIONS,
    AST_A_LA,                           // input + body + output

    AST_EXPRESSION,

    AST_IDENTIFIER,

    AST_NONE,
    AST_OUT,

    AST_VARIABLE,                       // primary type variable
    AST_VARIABLE_COMBINATION,
    AST_VARIABLE_DOMAIN_NAME,

    AST_CONTAINER_EXPR,                 // many expressions
    AST_PAIR_EXPR,

    AST_VAR_DECLARE,                    // variable type & name
    AST_VAR_INSTANCE,
    AST_UNARY_OP,                       // 1 expression
    AST_BINARY_OP,                      // 2 expressions
    AST_TERNARY_OP,                     // 3 expressions
    AST_IS,                             // 1 expression, 1 type
    AST_SYNC,                           // 1 identifier

    AST_A_PROC_LA,                      // A proc.la file

    AST_STACK,
    AST_SCOPE,

};*/

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

plat_inline const char* ast_type_combination_name(ast_type_combination type) {
    switch(type) {
        case ast_type_list: return "[]";
        case ast_type_map: return "{}";
        default: return "Unknown";
    }
}

/**
 * For container expr objs
 */
typedef enum {
    ast_container_type_list     = 1,
    ast_container_type_map      = 2,
    ast_container_type_tuple    = 3,
} ast_container_type;

plat_inline const char* ast_container_type_text(ast_container_type type) {
    switch (type) {
        case ast_container_type_list: return "[]";
        case ast_container_type_map: return "{}";
        case ast_container_type_tuple: return "()";
        default: return "Unknown";
    }
}

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

plat_inline const char* ast_ast_unary_op_text(ast_unary_op op) {
    switch (op) {
        case ast_unary_op_plus: return "+";
        case ast_unary_op_minus: return "-";
        case ast_unary_op_invert: return "~";
        case ast_unary_op_not: return "!";
        case ast_unary_op_inc_f: return "++N";
        case ast_unary_op_inc_l: return "N++";
        case ast_unary_op_dec_f: return "--N";
        case ast_unary_op_dec_l: return "N--";
        default: return "Unknown Op";
    }
}

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

    ast_binary_op_apply_to,
    ast_binary_op_pipe_1to1,
    ast_binary_op_pipe_reduce,
    ast_binary_op_pipe_expand,
    ast_binary_op_pipe_inject,
} ast_binary_op;

plat_inline const char* ast_ast_binary_op_text(ast_binary_op op) {
    switch (op) {
        case ast_binary_op_add: return "+";
        case ast_binary_op_subtract: return "-";
        case ast_binary_op_multiply: return "*";
        case ast_binary_op_divide: return "/";
        case ast_binary_op_modulo: return "%";
        case ast_binary_op_list_access: return "[i]";
        case ast_binary_op_map_access: return "{k}";
        case ast_binary_op_shift_left: return "<<";
        case ast_binary_op_shift_right: return ">>";
        case ast_binary_op_equal: return "==";
        case ast_binary_op_not_equal: return "!=";
        case ast_binary_op_less: return "<";
        case ast_binary_op_great: return ">";
        case ast_binary_op_less_or_equal: return "<=";
        case ast_binary_op_great_or_equal: return ">=";
        case ast_binary_op_and: return "&&";
        case ast_binary_op_or: return "||";
        case ast_binary_op_bit_and: return "&";
        case ast_binary_op_bit_or: return "|";
        case ast_binary_op_bit_xor: return "^";
        case ast_binary_op_apply_to: return "->";
        case ast_binary_op_pipe_1to1: return "-->";
        case ast_binary_op_pipe_reduce: return "=->";
        case ast_binary_op_pipe_expand: return "-*>";
        case ast_binary_op_pipe_inject: return "*->";
        default: return "Unknown";
    }
}

typedef enum {
    ast_ternary_op_conditional,
} ast_ternary_op;

plat_inline const char* ast_ast_ternary_op_text(ast_ternary_op op) {
    switch (op) {
        case ast_ternary_op_conditional: return "?:";
        default: return "Unknown";
    }
}

typedef enum {
    ast_jump_type_goto,
    ast_jump_type_break,
    ast_jump_type_continue,
} ast_jump_type;

struct AstContext;

/// Inheritable interfaces
/**
 *
 * @param stru
 * @return
 */
struct AstNode;
struct AstErrorRecovery;
struct AstContext;
typedef struct AstErrorRecovery* (*optimize_node_t)(struct AstNode* node, struct AstContext* context);

/// ===== Abstract Tree node =====
typedef struct AstNode {
    // == build ==
    // TODO: Record line number in source code for build error.
    // == runtime ==
}*AstNode;

plat_inline AstNode initAstNode(AstNode obj, Unpacker unpkr);
plat_inline void destroyAstNode(AstNode obj);
plat_inline void packAstNode(AstNode obj, Packer pkr);

MMSubObject(AstNode, MMObject, initAstNode, destroyAstNode, packAstNode);

plat_inline int compareForAstNode(void* this_stru, void* that_stru);
plat_inline AstNode initAstNode(AstNode obj, Unpacker unpkr) {
    set_compare_for_mmobj(obj, compareForAstNode);
    if (is_unpacker_v1(unpkr)) {

    }
    return obj;
}

plat_inline void destroyAstNode(AstNode obj) {

}

plat_inline void packAstNode(AstNode obj, Packer pkr) {
    if (is_packer_v1(pkr)) {

    }
}

plat_inline int compareForAstNode(void* this_stru, void* that_stru) {
    AstNode node1 = toAstNode(this_stru);
    AstNode node2 = toAstNode(that_stru);
    return 0; //;
}

plat_inline void __set_optimization(void* stru, optimize_node_t optimize) {
    if (stru == null) return;
    set_function_for_mmobj(stru, optimize_node_t, optimize);
}
#define set_optimization(stru, optimize) __set_optimization(stru, optimize)
plat_inline struct AstErrorRecovery* __optimize_node(void* stru, struct AstContext* context)
{
    return call_f(toAstNode(stru), optimize_node_t, context);
}
#define optimize_node(stru, context) __optimize_node(stru, context);


/// ===== Statement =====

typedef struct AstStatement {
    // == runtime ==
    // TODO: Add parent node for each statement
    AstNode parent_node;    // week reference, no retain
    // TODO: Set context if need.
    struct AstNode* context;        // In most case, it should be a AstContext.
}*AstStatement;

plat_inline int compareForAstStatement(void*, void*);
plat_inline AstStatement initAstStatement(AstStatement obj, Unpacker unpkr) {
    set_compare_for_mmobj(obj, compareForAstStatement);
    if (is_unpacker_v1(unpkr)) {
        obj->parent_node = toAstNode(unpack_mmobj(0, unpkr));           // Don't retain, else loop-retain
        obj->context = toAstNode(unpack_mmobj_retained(1, unpkr));
    }
    return obj;
}

plat_inline void destroyAstStatement(AstStatement obj) {
    //release_mmobj(obj->parent_node);              // Don't retain, else loop-retain
    release_mmobj(obj->context);
    obj->parent_node = null;
}

plat_inline void packAstStatement(AstStatement obj, Packer pkr) {
    if (is_packer_v1(pkr)) {
        pack_mmobj(0, obj->parent_node, pkr);
        pack_mmobj(1, obj->context, pkr);
    }
}

MMSubObject(AstStatement, AstNode, initAstStatement, destroyAstStatement, packAstStatement);

plat_inline int compareForAstStatement(void* this_stru, void* that_stru) {
    AstStatement statement1 = toAstStatement(this_stru);
    AstStatement statement2 = toAstStatement(that_stru);
    int r = compare_parent(statement1, statement2);
    if (r) return r;
    return FIRST_Of_2RESULTS(compare_mmobjs(statement1->parent_node, statement2->parent_node),
                             compare_mmobjs(statement1->context, statement2->context));
}

plat_inline void set_ast_parent_node(void* node, void* parent) {
    AstStatement statement = toAstStatement(node);
    statement->parent_node = toAstNode(parent);       // Don't retain, else loop-retain
}

plat_inline void clean_ast_parent_node(void* node) {
    set_ast_parent_node(node, null);
}

plat_inline void set_ast_context(void* node, void* context) {
    AstStatement statement = toAstStatement(node);
    release_mmobj(statement->context);
    statement->context = retain_mmobj(toAstNode(context));
}

plat_inline void clean_ast_context(void* node) {
    set_ast_context(node, null);
}

/// ===== Expression =====

typedef struct AstExpression {
    // === runtime ===

}*AstExpression;

plat_inline AstExpression initAstExpression(AstExpression obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstExpression(AstExpression obj) {

}

plat_inline void packAstExpression(AstExpression obj, Packer pkr) {

}

MMSubObject(AstExpression, AstStatement, initAstExpression, destroyAstExpression, packAstExpression);

/// ===== Empty =====

typedef struct AstEmpty {

}*AstEmpty;

plat_inline AstEmpty initAstEmpty(AstEmpty obj, Unpacker unpkr) {
    (void) unpkr;
    set_single_instance_comparison_for_mmobj(obj);
    return obj;
}

/*plat_inline void destroyAstEmpty(AstNone obj) {

}*/

plat_inline void packAstEmpty(AstEmpty obj, Packer pkr) {

}

MMSubObject(AstEmpty, AstStatement , initAstEmpty, null/*destroyAstEmpty*/, packAstEmpty);


/// ===== NONE =====

typedef struct AstNone {

}*AstNone;

plat_inline AstNone initAstNone(AstNone obj, Unpacker unpkr) {
    (void) unpkr;
    set_single_instance_comparison_for_mmobj(obj);
    return obj;
}

/*plat_inline void destroyAstNone(AstNone obj) {

}*/

plat_inline void packAstNone(AstNone obj, Packer pkr) {

}

MMSubObject(AstNone, AstExpression, initAstNone, null/*destroyAstNone*/, packAstNone);


/// ===== Out =====

typedef struct AstOut {

}*AstOut;

plat_inline AstOut initAstOut(AstOut obj, Unpacker unpkr) {
    (void) unpkr;
    set_single_instance_comparison_for_mmobj(obj);
    return obj;
}

/*plat_inline void destroyAstOut(AstOut obj) {

}

plat_inline void packAstOut(AstOut obj, Packer pkr) {

}*/

MMSubObject(AstOut, AstExpression, initAstOut, null/*destroyAstOut*/, null/*packAstOut*/);


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

plat_inline int compareForAstVariable(void *, void *);
plat_inline AstVariable initAstVariable(AstVariable obj, Unpacker unpkr) {
    set_compare_for_mmobj(obj, compareForAstVariable);
    if (is_unpacker_v1(unpkr)) {
        obj->type = (ast_type) unpack_varint(0, unpkr);
        obj->is_const = unpack_bool(1, unpkr);
        obj->value = toMMObject(unpack_mmobj_retained(2, unpkr));
    } else {
        obj->type = ast_type_var;
        obj->is_const = false;
    }
    return obj;
}

plat_inline void destroyAstVariable(AstVariable obj) {
    release_mmobj(obj->value);
}

plat_inline void packAstVariable(AstVariable obj, Packer pkr) {
    if (is_packer_v1(pkr)) {
        pack_varint(0, obj->type, pkr);
        pack_bool(1, obj->is_const, pkr);
        pack_mmobj(2, obj->value, pkr);
    }
}

MMSubObject(AstVariable, AstExpression, initAstVariable, destroyAstVariable, packAstVariable);

plat_inline int compareForAstVariable(void* this_stru, void* that_stru) {
    AstVariable this_v = toAstVariable(this_stru);
    AstVariable that_v = toAstVariable(that_stru);
    int r = compare_parent(this_v, that_v);
    if (r) return r;
    if (this_v->type != that_v->type) return (int) this_v->type - (int) that_v->type;
    if (this_v->is_const != that_v->is_const) return (this_v->is_const ? 1 : 0) - (that_v->is_const ? 1 : 0);
    return compare_mmobjs(this_v->value, that_v->value);
}

plat_inline AstVariable allocVariableWithIntValue(mgn_memory_pool* pool, int32 value) {
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

plat_inline AstVariable allocVariableWithConstIntValue(mgn_memory_pool* pool, int32 value) {
    AstVariable obj = allocVariableWithIntValue(pool, value);
    if (obj) {
        obj->is_const = true;
    }
    return obj;
}

plat_inline AstVariable allocVariableWithLongValue(mgn_memory_pool* pool, int64 value) {
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

plat_inline AstVariable allocVariableWithConstLongValue(mgn_memory_pool* pool, int64 value) {
    AstVariable obj = allocVariableWithLongValue(pool, value);
    if (obj) {
        obj->is_const = true;
    }
    return obj;
}

plat_inline AstVariable allocVariableWithFloatValue(mgn_memory_pool* pool, float value) {
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

plat_inline AstVariable allocVariableWithConstFloatValue(mgn_memory_pool* pool, float value) {
    AstVariable obj = allocVariableWithFloatValue(pool, value);
    if (obj) {
        obj->is_const = true;
    }
    return obj;
}


plat_inline AstVariable allocVariableWithDoubleValue(mgn_memory_pool* pool, double value) {
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

plat_inline AstVariable allocVariableWithConstDoubleValue(mgn_memory_pool* pool, double value) {
    AstVariable obj = allocVariableWithDoubleValue(pool, value);
    if (obj) {
        obj->is_const = true;
    }
    return obj;
}

plat_inline AstVariable allocVariableWithNumberValue(mgn_memory_pool* pool, double value) {
    AstVariable obj = allocAstVariable(pool);
    if (obj) {
        obj->type = ast_type_number;
        /// TODO: implementation
        plat_io_printf_err("Unsupported type - number\n");
    }
    return obj;
}

plat_inline AstVariable allocVariableWithConstNumberValue(mgn_memory_pool* pool, double value) {
    AstVariable obj = allocVariableWithNumberValue(pool, value);
    if (obj) {
        obj->is_const = true;
    }
    return obj;
}

plat_inline AstVariable allocVariableWithCString(mgn_memory_pool* pool, char* cstring) {
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

plat_inline AstVariable allocVariableWithConstCString(mgn_memory_pool* pool, char* cstring) {
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

plat_inline int compareForAstIdentifier(void *, void *);
plat_inline AstIdentifier initAstIdentifier(AstIdentifier obj, Unpacker unpkr) {
    set_compare_for_mmobj(obj, compareForAstIdentifier);
    if (is_unpacker_v1(unpkr)) {
        obj->name = toMMString(unpack_mmobj_retained(0, unpkr));
    }
    return obj;
}

plat_inline void destroyAstIdentifier(AstIdentifier obj) {
    release_mmobj(obj->name);
}

plat_inline void packAstIdentifier(AstIdentifier obj, Packer pkr) {
    if (is_packer_v1(pkr)) {
        pack_mmobj(0, obj->name, pkr);
    }
}

MMSubObject(AstIdentifier, AstExpression, initAstIdentifier, destroyAstIdentifier, packAstIdentifier);

plat_inline int compareForAstIdentifier(void* this_stru, void* that_stru) {
    AstIdentifier this_i = toAstIdentifier(this_stru);
    AstIdentifier that_i = toAstIdentifier(that_stru);
    int r = compare_parent(this_i, that_i);
    if (r) return r;
    return compare_mmobjs(this_i->name, that_i->name);
}

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
