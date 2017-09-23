//
// Created by Yuchi Chen on 2017/8/13.
//

#ifndef PROC_LA_AST_C_H
#define PROC_LA_AST_C_H

#include "ast_la.h"
#include "ast_runtime.h"

AstNode ast_create_none(void);
AstNode ast_create_type(ast_type type);
AstNode ast_create_const_i(char* value);
AstNode ast_create_const_f(char* value);
AstNode ast_create_const_s(char* value);
AstNode ast_create_combined_type(AstNode base_type, ast_type_combination container_typ);
AstNode ast_create_ctrl(ast_ctrl_type ctrl);
AstNode ast_create_package(char* value);
AstNode ast_create_domain(char* value);
AstNode ast_create_identifier(char* value);
AstNode ast_create_var_instance(AstNode declare, AstNode inst);
AstNode ast_create_var_instance_ex(AstNode type, AstNode identifier, AstNode inst);
AstNode ast_create_var_declare(AstNode var_typ, AstNode identifier);
AstNode ast_create_type_list(AstNode first, AstNode second);
AstNode ast_create_var_list(AstNode first, AstNode second);
AstNode ast_create_external_declarations(AstNode first, AstNode second);
AstNode ast_create_ast_body(AstNode first, AstNode second);
AstNode ast_create_la_declaration(AstNode input, AstNode body, AstNode output);
AstNode ast_create_a_proc_la(AstNode package, AstNode external_declarations);

/// =================== ast management =================
int create_ast(mgn_memory_pool* pool, char* source_code, uint source_code_size, AstNode* ast);

typedef enum {
    scope_action_created    = 2,
    scope_action_using      = 1,
    scope_action_destroyed  = 0,
} scope_action;
typedef bool (*ast_iterator)(AstNode obj, uint level, scope_action action, AstScope scope);
void iterate_ast(AstNode obj, ast_iterator iterator);

#endif //PROC_LA_AST_C_H




