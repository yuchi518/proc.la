//
// Created by Yuchi Chen on 2017/8/27.
//

#ifndef PROC_LA_AST_OBJ_H
#define PROC_LA_AST_OBJ_H


typedef enum la_ast_typ {


    /// for ast implementation
    __la_ast_impl__                         = 0x01000000,
    la_ast_impl_stack,
    la_ast_impl_scope,
} astObj_typ;


#define return_enum_string(enum_name)   case enum_name: { return #enum_name; }

static inline const char* la_ast_typ_to_string(enum la_ast_typ typ) {
    switch(typ)
    {


        return_enum_string(__la_ast_impl__);
        return_enum_string(la_ast_impl_stack);
        return_enum_string(la_ast_impl_scope);
        default:
            return "unknown";
    }
}

static inline bool is_collection_type(enum la_ast_typ typ)
{
    switch(typ)
    {
            return true;
        default:
            return false;
    }
}

/// ===== unit test =====

void unit_test_mmobj(void);



#endif //PROC_LA_AST_OBJ_H
