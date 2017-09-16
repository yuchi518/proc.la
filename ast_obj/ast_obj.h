//
// Created by Yuchi Chen on 2017/8/27.
//

#ifndef PROC_LA_AST_OBJ_H
#define PROC_LA_AST_OBJ_H


typedef enum la_ast_typ {
    la_ast_none                             = 0x00000000,
    la_ast_unknown,

    /// const
            __la_ast_inst_flag__            = 0x00000100,
    la_ast_inst_int,
    la_ast_inst_long,
    la_ast_inst_float,
    la_ast_inst_double,
    la_ast_inst_number,
    la_ast_inst_string,
    la_ast_inst_raw,
    la_ast_inst_list,               // list
    la_ast_inst_map,                // map

    /// type
    __la_ast_type_flag__                    = 0x00000200,
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
    __la_ast_ctrl_flag__                    = 0x00000400,
    la_ast_ctrl_out,
    la_ast_ctrl_is,
    la_ast_ctrl_declare,
    la_ast_ctrl_sync,

    /// name
    __la_ast_name_flag__                    = 0x00000800,
    la_ast_package_name,
    la_ast_domain_name,
    la_ast_identifier,

    /// expr, statement
    __la_ast_expr_flag__                    = 0x00001000,
    la_ast_var_declare,
    la_ast_var_instance,            // include var declaration (identifier, type) + instance (la_ast_inst_xxx or la_ast_la_declaration)
    la_ast_la_alias,
    la_ast_la_declaration,          // input + body + output declarations

    /// collections
    __la_ast_coll_flag__                    = 0x00002000,
    la_ast_var_list_declaration,
    la_ast_type_list_declaration,
    la_ast_external_declarations,
    la_ast_la_body_declaration,     // only body declaration

    /// a proc la
    la_ast_a_proc_la                        = 0x00100000,


    /// for ast implementation
    __la_ast_impl__                         = 0x01000000,
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
        return_enum_string(la_ast_inst_list);
        return_enum_string(la_ast_inst_map);

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

/// ===== unit test =====

void unit_test_mmobj(void);



#endif //PROC_LA_AST_OBJ_H
