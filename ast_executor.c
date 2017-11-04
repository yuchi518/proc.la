//
// Created by Yuchi Chen on 2017/11/4.
//

#include "ast_executor.h"


void execute_ast(AstNode ast_obj, const char* entry_name)
{
    if (entry_name == null) entry_name = "main";
    AstScope scope = null;

    AstStack stack = allocAstStackWithANode(_pool, ast_obj);
    plat_io_flush_std();
    uint level = 0;
    scope_action sa;

    AstNode node;

    while (!isEmptyAstStack(stack)) {
        node = popFromAstStack(stack);


    }
}