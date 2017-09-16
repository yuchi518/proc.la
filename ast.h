//
// Created by Yuchi Chen on 2017/8/13.
//

#ifndef PROC_LA_AST_C_H
#define PROC_LA_AST_C_H

#include "plat_mgn_mem.h"
#include "utarray.h"
#include "ast_obj.h"

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




