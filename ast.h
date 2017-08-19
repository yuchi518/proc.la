//
// Created by Yuchi Chen on 2017/8/13.
//

#ifndef PROC_LA_AST_C_H
#define PROC_LA_AST_C_H

#include "plat_mgn_mem.h"
#include "utarray.h"

enum la_ast_typ {
    la_ast_none,

    // const
    la_ast_const_int,
    la_ast_const_long,
    la_ast_const_float,
    la_ast_const_double,
    la_ast_const_number,
    la_ast_const_string,

    // type
    la_ast_type_int,
    la_ast_type_long,
    la_ast_type_float,
    la_ast_type_double,
    la_ast_type_number,
    la_ast_type_string,
    la_ast_type_raw,
    la_ast_type_var,
    la_ast_type_proc,
    la_ast_type_la,

    // ctrl
    la_ast_ctrl_out,
    la_ast_ctrl_is,
    la_ast_ctrl_declare,
    la_ast_ctrl_sync,

    // name
    la_ast_package_name,
    la_ast_domain_name,
    la_ast_identifier,

    // expr
    la_ast_var_declare,
    la_ast_la_alias,

    la_ast_external_declarations,
} ;

static inline const char* la_ast_typ_to_string(enum la_ast_typ typ) {
#define return_enum_string(enum_name)   case enum_name: { return #enum_name; }
    switch(typ)
    {
        return_enum_string(la_ast_const_int);
        return_enum_string(la_ast_const_long);
        return_enum_string(la_ast_const_float);
        return_enum_string(la_ast_const_double);
        return_enum_string(la_ast_const_number);

        return_enum_string(la_ast_type_int);
        return_enum_string(la_ast_type_long);
        return_enum_string(la_ast_type_float);
        return_enum_string(la_ast_type_double);
        return_enum_string(la_ast_type_number);
        return_enum_string(la_ast_type_string);
        return_enum_string(la_ast_type_raw);
        return_enum_string(la_ast_type_var);
        return_enum_string(la_ast_type_proc);
        return_enum_string(la_ast_type_la);

        return_enum_string(la_ast_ctrl_out);
        return_enum_string(la_ast_ctrl_is);
        return_enum_string(la_ast_ctrl_declare);
        return_enum_string(la_ast_ctrl_sync);

        return_enum_string(la_ast_package_name);
        return_enum_string(la_ast_domain_name);
        return_enum_string(la_ast_identifier);

        return_enum_string(la_ast_var_declare);
        return_enum_string(la_ast_la_alias);

        return_enum_string(la_ast_external_declarations);
        default:
            return "unknown";
    }
}

static inline bool is_collection_type(enum la_ast_typ typ)
{
    switch(typ)
    {
        case la_ast_external_declarations:
            return true;
        default:
            return false;
    }
}

#ifdef __GNUC__
#define member_type(type, member) __typeof__ (((type *)0)->member)
#else
#define member_type(type, member) const void
#endif

#define _obj2inst(ptr, type) ((type *)( \
    (char *)(member_type(type, is_a) *){ ptr } - ((size_t) &((type *)0)->is_a) ))

/**
 * Subclass should always put superclass in first.
 */
struct la_ast {
    enum la_ast_typ typ;
};

struct la_ast_unit {
    struct la_ast is_a;
};

struct la_ast* la_ast_create_unit(enum la_ast_typ typ);

struct la_ast_const_int {
    struct la_ast is_a;
    int32 value;
};

struct la_ast_const_long {
    struct la_ast is_a;
    int64 value;
};

struct la_ast* la_ast_create_const_i(char* value);

struct la_ast_const_float {
    struct la_ast is_a;
    float value;
};

struct la_ast_const_double {
    struct la_ast is_a;
    double value;
};

struct la_ast* la_ast_create_const_f(char* value);

struct la_ast_const_string {
    struct la_ast is_a;
    char* string;
};

struct la_ast* la_ast_create_const_s(char* value);

struct la_ast_name {
    struct la_ast is_a;
    char* name;
};

struct la_ast* la_ast_create_name(enum la_ast_typ typ, char* value);

struct la_ast_var_declare {
    struct la_ast is_a;
    char* identifier_name;
    enum la_ast_typ identifier_typ;
};

struct la_ast* la_ast_create_var_declare(struct la_ast* var, struct la_ast* var_typ);

struct la_ast_la_alias {
    struct la_ast is_a;
    char* domain_name;
    char* identifier_name;
};

struct la_ast* la_ast_create_la_alias(struct la_ast* domain, struct la_ast* identifier);

struct la_ast_collection {
    struct la_ast is_a;
    UT_array collection;       // UT_array in current implementation
};

struct la_ast* la_ast_create_collection(enum la_ast_typ typ, ...);

int create_ast(mgn_memory_pool* pool, char* source_code, uint source_code_size);
void release_struct(struct la_ast* obj);

#endif //PROC_LA_AST_C_H




