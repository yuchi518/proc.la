//
// Created by Yuchi Chen on 2017/8/13.
//

#ifndef PROC_LA_AST_C_H
#define PROC_LA_AST_C_H

#include "ast_la.h"

AstNode la_ast_create_none(void);
AstNode la_ast_create_type(ast_type type);
AstNode la_ast_create_const_i(char* value);
AstNode la_ast_create_const_f(char* value);
AstNode la_ast_create_const_s(char* value);
AstNode la_ast_create_combined_type(AstNode base_type, ast_type_combination container_typ);
AstNode la_ast_create_ctrl(ast_ctrl_type ctrl);
AstNode la_ast_create_package(char* value);
AstNode la_ast_create_domain(char* value);
AstNode la_ast_create_identifier(char* value);
AstNode la_ast_create_var_instance(AstNode declare, AstNode inst);
AstNode la_ast_create_var_instance_ex(AstNode type, AstNode identifier, AstNode inst);
AstNode la_ast_create_var_declare(AstNode var_typ, AstNode identifier);
AstNode la_ast_create_type_list(AstNode first, AstNode second);
AstNode la_ast_create_var_list(AstNode first, AstNode second);
AstNode la_ast_create_external_declarations(AstNode first, AstNode second);
AstNode la_ast_create_ast_body(AstNode first, AstNode second);
AstNode la_ast_create_la_declaration(AstNode input, AstNode body, AstNode output);
AstNode la_ast_create_a_proc_la(AstNode package, AstNode external_declarations);

/// =================== ast management =================
int create_ast(mgn_memory_pool* pool, char* source_code, uint source_code_size, AstNode* ast);
//typedef bool (*ast_iterator)(struct la_ast* obj, uint level);
//void iterate_ast(struct la_ast* obj, ast_iterator iterator);

#endif //PROC_LA_AST_C_H




