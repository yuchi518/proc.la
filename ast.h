//
// Created by Yuchi Chen on 2017/8/13.
//

#ifndef PROC_LA_AST_C_H
#define PROC_LA_AST_C_H

#include "plat_mgn_mem.h"
#include "utarray.h"

typedef enum la_ast_typ {
    la_ast_none                     = 0x00000000,

    /// const
    __la_ast_inst_flag__           = 0x00000100,
    la_ast_inst_int,
    la_ast_inst_long,
    la_ast_inst_float,
    la_ast_inst_double,
    la_ast_inst_number,
    la_ast_inst_string,
    la_ast_inst_raw,
    la_ast_inst_container,          // array or map

    /// type
    __la_ast_type_flag__            = 0x00000200,
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
    la_ast_type_combination,

    /// ctrl
    __la_ast_ctrl_flag__            = 0x00000400,
    la_ast_ctrl_out,
    la_ast_ctrl_is,
    la_ast_ctrl_declare,
    la_ast_ctrl_sync,

    /// name
    __la_ast_name_flag__            = 0x00000800,
    la_ast_package_name,
    la_ast_domain_name,
    la_ast_identifier,

    /// expr, statement
    __la_ast_expr_flag__            = 0x00001000,
    la_ast_var_declare,
    la_ast_var_instance,            // include var declaration (identifier, type) + instance (la_ast_inst_xxx or la_ast_la_declaration)
    la_ast_la_alias,
    la_ast_la_declaration,          // input + body + output declarations

    /// collections
    __la_ast_coll_flag__            = 0x00002000,
    la_ast_var_list_declaration,
    la_ast_type_list_declaration,
    la_ast_external_declarations,
    la_ast_la_body_declaration,     // only body declaration

    /// a proc la
    la_ast_a_proc_la                = 0x00100000,


    /// for ast implementation
    __la_ast_impl__                 = 0x01000000,
    la_ast_impl_stack,
    la_ast_impl_scope,
} astObj_typ;

typedef enum la_ast_container_typ {
    la_ast_container_typ_array = 1,
    la_ast_container_typ_map   = 2,
} astObj_container_typ;

static inline const char* la_ast_typ_to_string(enum la_ast_typ typ) {
#define return_enum_string(enum_name)   case enum_name: { return #enum_name; }
    switch(typ)
    {
        return_enum_string(la_ast_none);

        return_enum_string(__la_ast_inst_flag__);
        return_enum_string(la_ast_inst_int);
        return_enum_string(la_ast_inst_long);
        return_enum_string(la_ast_inst_float);
        return_enum_string(la_ast_inst_double);
        return_enum_string(la_ast_inst_number);
        return_enum_string(la_ast_inst_string);
        return_enum_string(la_ast_inst_raw);
        return_enum_string(la_ast_inst_container);

        return_enum_string(__la_ast_type_flag__);
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
        return_enum_string(la_ast_type_combination);

        return_enum_string(__la_ast_ctrl_flag__);
        return_enum_string(la_ast_ctrl_out);
        return_enum_string(la_ast_ctrl_is);
        return_enum_string(la_ast_ctrl_declare);
        return_enum_string(la_ast_ctrl_sync);

        return_enum_string(__la_ast_name_flag__);
        return_enum_string(la_ast_package_name);
        return_enum_string(la_ast_domain_name);
        return_enum_string(la_ast_identifier);

        return_enum_string(__la_ast_expr_flag__);
        return_enum_string(la_ast_var_declare);
        return_enum_string(la_ast_var_instance);
        return_enum_string(la_ast_la_alias);
        return_enum_string(la_ast_la_declaration);

        return_enum_string(__la_ast_coll_flag__);
        return_enum_string(la_ast_var_list_declaration);
        return_enum_string(la_ast_type_list_declaration);
        return_enum_string(la_ast_external_declarations);
        return_enum_string(la_ast_la_body_declaration);

        return_enum_string(la_ast_a_proc_la);

        return_enum_string(__la_ast_impl__);
        return_enum_string(la_ast_impl_stack);
        return_enum_string(la_ast_impl_scope);
        default:
            return "unknown";
    }
}

static inline const char* la_ast_container_typ_to_string(enum la_ast_container_typ typ) {
    switch(typ)
    {
        return_enum_string(la_ast_container_typ_array);
        return_enum_string(la_ast_container_typ_map);
        default:
            return "unknown";
    }
}

static inline bool is_collection_type(enum la_ast_typ typ)
{
    switch(typ)
    {
        case la_ast_var_list_declaration:
        case la_ast_type_list_declaration:
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
    uint id;
};

// none, type, ctrl
struct la_ast_unit {
    struct la_ast is_a;
};

struct la_ast* la_ast_create_unit(enum la_ast_typ typ);
#define la_ast_create_none()    la_ast_create_unit(la_ast_none)
#define la_ast_create_type(typ) la_ast_create_unit(typ)
#define la_ast_create_ctrl(typ) la_ast_create_unit(typ)

struct la_ast_type_combination {
    struct la_ast is_a;
    /**
     * combined_type = base_type | ([1 or 2] << (16+0)) | ([1 or 2] << (16+2)) | ... | ([1 or 2] << (16+N))
     * base_type = la_ast_type_int | la_ast_type_long | ... etc.
     * [1 or 2], 1 = array [], 2 = map {}
     * 16 + (0~14), the maximum level of combined type is 8, use 2 bits to maintain each level.
     */
    int32 combined_type;
};

struct la_ast* la_ast_create_combined_type(struct la_ast* base_type, enum la_ast_container_typ container_typ);

struct la_ast_inst_int {
    struct la_ast is_a;
    int32 value;
};

struct la_ast_inst_long {
    struct la_ast is_a;
    int64 value;
};

struct la_ast* la_ast_create_const_i(char* value);

struct la_ast_inst_float {
    struct la_ast is_a;
    float value;
};

struct la_ast_inst_double {
    struct la_ast is_a;
    double value;
};

struct la_ast* la_ast_create_const_f(char* value);

struct la_ast_inst_string {
    struct la_ast is_a;
    char* string;
};

struct la_ast* la_ast_create_const_s(char* value);

// TODO: implement raw, container

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

struct la_ast* la_ast_create_var_declare(struct la_ast* var/*aka. identifier*/, struct la_ast* var_typ);

struct la_ast_var_instance {
    struct la_ast is_a;
    struct la_ast* declare;     // struct la_ast_var_declare
    struct la_ast* inst;        // la_ast_inst_xxx or la_ast_la_declaration
};

struct la_ast* la_ast_create_var_instance(struct la_ast* declare, struct la_ast* inst);
struct la_ast* la_ast_create_var_instance_ex(struct la_ast* var/*aka. identifier*/, struct la_ast* var_typ, struct la_ast* inst);

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

struct la_ast_la_declaration {
    struct la_ast is_a;
    struct la_ast* input;
    struct la_ast* body;
    struct la_ast* output;
};

struct la_ast* la_ast_create_la_declaration(struct la_ast* input, struct la_ast* body, struct la_ast* output);

struct la_ast_a_proc_la {
    struct la_ast is_a;
    struct la_ast* package_name;
    struct la_ast* external_declarations;
};

struct la_ast* la_ast_create_a_proc_la(struct la_ast* package, struct la_ast* external_declarations);

struct la_ast_impl_scope {
    struct la_ast is_a;
    struct la_ast* last_scope;
    struct la_ast* trigger;
};

struct la_ast* la_ast_impl_create_scope(struct la_ast* trigger, struct la_ast* last_scope);

/// =================== ast management =================
int create_ast(mgn_memory_pool* pool, char* source_code, uint source_code_size, struct la_ast** ast);
typedef bool (*ast_iterator)(struct la_ast* obj, uint level);
void iterate_ast(struct la_ast* obj, ast_iterator iterator);

#define alloc_astObj(pool, struct_name, assign_typ) \
    ({ struct_name* rv = (struct_name*)mgn_mem_alloc(pool, sizeof(struct_name)); if (rv) rv->is_a.typ = assign_typ; rv; })
void release_astObj(struct la_ast* obj);

#endif //PROC_LA_AST_C_H




