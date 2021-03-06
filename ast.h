//
// Created by Yuchi Chen on 2017/8/13.
//

#ifndef PROC_LA_AST_C_H
#define PROC_LA_AST_C_H

#include "ast_la.h"
#include "ast_runtime.h"

plat_inline void register_all_ast_to_unpacker(Unpacker unpkr) {
    register_all_mmo_ext_to_unpacker(unpkr);
    registerAstALaToUnpacker(unpkr);
    registerAstAnchorStmtToUnpacker(unpkr);
    registerAstAProcLaToUnpacker(unpkr);
    registerAstBinaryOpExprToUnpacker(unpkr);
    registerAstBlockStmtToUnpacker(unpkr);
    registerAstCaseStmtToUnpacker(unpkr);
    registerAstContainerExprToUnpacker(unpkr);
    registerAstContextToUnpacker(unpkr);
    registerAstDomainNameToUnpacker(unpkr);
    registerAstEachStmtToUnpacker(unpkr);
    registerAstErrorRecoveryToUnpacker(unpkr);
    registerAstExpressionToUnpacker(unpkr);
    registerAstExternalDeclarationsToUnpacker(unpkr);
    registerAstIdentifierToUnpacker(unpkr);
    registerAstIfStmtToUnpacker(unpkr);
    registerAstIsExprToUnpacker(unpkr);
    registerAstJumpStmtToUnpacker(unpkr);
    registerAstLoopStmtToUnpacker(unpkr);
    registerAstEmptyToUnpacker(unpkr);
    registerAstNoneToUnpacker(unpkr);
    registerAstOutToUnpacker(unpkr);
    registerAstPackageToUnpacker(unpkr);
    registerAstPairExprToUnpacker(unpkr);
    registerAstScopeToUnpacker(unpkr);
    registerAstStackToUnpacker(unpkr);
    registerAstSwitchStmtToUnpacker(unpkr);
    registerAstSyncStmtToUnpacker(unpkr);
    registerAstTernaryOpExprToUnpacker(unpkr);
    registerAstTypeListToUnpacker(unpkr);
    registerAstTypeCombinationToUnpacker(unpkr);
    registerAstTypeToUnpacker(unpkr);
    registerAstUnaryOpExprToUnpacker(unpkr);
    registerAstVarDeclareToUnpacker(unpkr);
    registerAstVariableCombinationToUnpacker(unpkr);
    registerAstVariableToUnpacker(unpkr);
    registerAstVarInstanceToUnpacker(unpkr);
}

AstNode ast_create_empty(void);
AstNode ast_create_none(void);
AstNode ast_create_out(void);
AstNode ast_create_type(ast_type type);
AstNode ast_create_const_i(char* value);
AstNode ast_create_const_f(char* value);
AstNode ast_create_const_s(char* value);
AstNode ast_create_combined_type(AstNode base_type, ast_type_combination container_typ);
AstNode ast_create_package(char* value);
AstNode ast_create_domain(char* value);
AstNode ast_create_identifier(char* value);

AstNode ast_create_unary_op_expr(AstNode expr, ast_unary_op op);
AstNode ast_create_unary_op_expr_ex(AstNode expr, AstNode op);
AstNode ast_create_binary_op_expr(AstNode expr_a, AstNode expr_b, ast_binary_op op);
AstNode ast_create_binary_op_expr_w_op(ast_binary_op op);
AstNode ast_apply_binary_op_expr_w_expr_a(AstNode op_expr, AstNode expr_a);
AstNode ast_apply_binary_op_expr_w_expr_b(AstNode op_expr, AstNode expr_b);
AstNode ast_create_ternary_op_expr(AstNode expr_a, AstNode expr_b, AstNode expr_c, ast_ternary_op op);
AstNode ast_create_is_expr(AstNode expr, AstNode type);

AstNode ast_create_container(AstNode expr_a, AstNode expr_b, ast_container_type type);
AstNode ast_close_container(AstNode expr);
AstNode ast_create_pair(AstNode key, AstNode value);

AstNode ast_create_var_instance(AstNode declare, AstNode inst);
AstNode ast_create_var_instance_ex(AstNode type, AstNode identifier, AstNode inst);
AstNode ast_create_var_declare(AstNode var_typ, AstNode identifier);
AstNode ast_create_type_list(AstNode first, AstNode second);

AstNode ast_create_block(AstNode first, AstNode second);
AstNode ast_close_block(AstNode block);
AstNode ast_create_case(AstNode check);
AstNode ast_create_switch(AstNode eval, AstNode stmt);
AstNode ast_create_ifelse(AstNode eval, AstNode true_stmt, AstNode false_stmt);
AstNode ast_create_loop(AstNode stmt);
AstNode ast_create_each(AstNode eval, AstNode stmt);
AstNode ast_create_jump(ast_jump_type type, AstNode id);
AstNode ast_create_anchor(AstNode label);
AstNode ast_create_sync(AstNode identifier);

AstNode ast_create_la_declaration(AstNode input, AstNode body, AstNode output);

AstNode ast_create_external_declarations(AstNode first, AstNode second);
AstNode ast_create_a_proc_la(AstNode package, AstNode external_declarations);

AstNode ast_create_error_recovery(void);
AstNode ast_create_error_recovery_ex(const char* msg, int first_line, int first_column, int last_line, int last_column);

/// =================== ast management =================
int create_ast(mgn_memory_pool* pool, char* source_code, uint source_code_size, AstNode* ast);

typedef enum {
    scope_action_created    = 2,
    scope_action_using      = 1,
    scope_action_destroyed  = 0,
} scope_action;
typedef bool (*ast_iterator)(AstNode obj, uint level, scope_action action, AstScope scope);
typedef bool (*ast_iterator_ex)(AstNode obj, AstContext context);
void iterate_ast(AstNode obj, ast_iterator iterator);
bool verify_and_optimize_ast(AstNode obj);

#endif //PROC_LA_AST_C_H




