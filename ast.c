//
// Created by Yuchi Chen on 2017/8/13.
//

#include "ast.h"
#include "proc.la.l.c"

static struct src_stack *_curbs = null;
static mgn_memory_pool* _pool = null;
AstNode* _ast = null;
static const bool verbose = false;

int create_ast(mgn_memory_pool* pool, char* content, uint content_size, AstNode* ast)
{
    _pool = pool;
    struct src_stack *bs = (struct src_stack*)mgn_mem_alloc(pool, sizeof(struct src_stack));
    if(!bs) {
        if (ast) *ast = null;
        return -1;
    }

    _ast = ast;

    /*bs->src_buffer = plat_mem_allocate(size);
    if(!bs->src_buffer)
    {
        plat_mem_release(bs);
        return jserr_no_memory;
    }

    bs->src_size = size;
    plat_mem_copy(bs->src_buffer, buff, size);*/

    /* remember state */
    //if(_curbs) _curbs->lineno = yylineno;
    bs->prev = _curbs;

    /* set up current entry */
    //bs->bs = yy_scan_bytes(bs->src_buffer, bs->src_size);
    bs->bs = yy_scan_bytes(content, content_size);
    yy_switch_to_buffer(bs->bs);
    _curbs = bs;
    //yylineno = 1;

    yyparse();

    mgn_mem_release(pool, bs);

    return 0;
}

AstNode ast_create_none(void) {
    return toAstNode(autorelease_mmobj(allocAstNone(_pool)));
}

AstNode ast_create_out(void)
{
    return toAstNode(autorelease_mmobj(allocAstOut(_pool)));
}

AstNode ast_create_type(ast_type type)
{
    return toAstNode(autorelease_mmobj(allocAstTypeWithType(_pool, type)));
}

AstNode ast_create_combined_type(AstNode base_type, ast_type_combination container_typ)
{
    AstTypeCombination combination = toAstTypeCombination(base_type);

    if (combination)
    {
        // base type is already a combined type
        retain_mmobj(combination);
    }
    else
    {
        AstType base = toAstType(base_type);
        combination = allocAstTypeCombinationWithCombinedType(_pool, base->type, 0);
    }

    int i=0;
    for (i=0;i<16;i+=2)
    {
        if ((combination->combined_type & (0x03<<i)) == 0)
        {
            // empty slot
            combination->combined_type |= (0x03 & container_typ) << i;
            break;
        }
    }

    if (i>=16)
    {
        plat_io_printf_err("Create combined type - slot is not enough (%08x)\n", combination->combined_type);
    }

    return toAstNode(autorelease_mmobj(combination));
}

AstNode ast_create_const_i(char* value)
{
    if (verbose) plat_io_printf_dbg("Create int - %s\n", value);

    // TODO: implement parser
    // include three types: la_ast_inst_int, la_ast_inst_long, la_ast_inst_number

    long long long_val = atoll(value);

    if ((long_val & 0xffffffff00000000) != 0)
    {
        return toAstNode(autorelease_mmobj(allocVariableWithLongValue(_pool, (int64)long_val)));
    }
    else
    {
        return toAstNode(autorelease_mmobj(allocVariableWithIntValue(_pool, (int32)long_val)));
    }

    return null;
}

AstNode ast_create_const_f(char* value)
{
    if (verbose) plat_io_printf_dbg("Create float - %s\n", value);

    AstNode obj = toAstNode(allocVariableWithFloatValue(_pool, 0));
    // TODO: implement float, double parser

    return autorelease_mmobj(obj);
}

AstNode ast_create_const_s(char* value)
{
    if (verbose) plat_io_printf_dbg("Create string - %s\n", value);

    return toAstNode(autorelease_mmobj(allocVariableWithCString(_pool, value)));
}

AstNode ast_create_ctrl(ast_ctrl_type ctrl)
{
    return toAstNode(autorelease_mmobj(allocAstCtrlFlowWithCtrl(_pool, ctrl)));
}

AstNode ast_create_package(char* value)
{
    return toAstNode(autorelease_mmobj(allocAstPackageWithCStringName(_pool, value)));
}

AstNode ast_create_domain(char* value)
{
    return toAstNode(autorelease_mmobj(allocAstDomainNameWithCStringName(_pool, value)));
}

AstNode ast_create_identifier(char* value)
{
    return toAstNode(autorelease_mmobj(allocAstIdentifierWithCStringName(_pool, value)));
}

AstNode ast_create_parentheses_expr(AstNode expr)
{
    return toAstNode(autorelease_mmobj(allocAstParenthesesExprWithExpr(_pool, toAstExpression(expr))));
}

AstNode ast_create_unary_op_expr(AstNode expr, ast_unary_op op)
{
    switch (op)
    {
        case ast_unary_op_plus:
        case ast_unary_op_minus:
        case ast_unary_op_invert:
        case ast_unary_op_not:
        case ast_unary_op_inc_f:
        case ast_unary_op_inc_l:
        case ast_unary_op_dec_f:
        case ast_unary_op_dec_l:
            break;
        default: {
            plat_io_printf_err("Incorrect unary op(%d)\n", op);
            return null;
        }
    }

    // expr can be null

    return toAstNode(autorelease_mmobj(allocAstUnaryOpExprWithOp(_pool, toAstExpression(expr), op)));
}

AstNode ast_create_unary_op_expr_ex(AstNode expr, AstNode op) {
    AstUnaryOpExpr opExpr = toAstUnaryOpExpr(op);
    if (opExpr == null) {
        plat_io_printf_err("Op(%s) is not a op expr.\n", name_of_last_mmobj(op));
        return null;
    }
    if (expr == null) {
        plat_io_printf_err("Expr can't be null.\n");
        return null;
    }
    AstExpression expression = toAstExpression(expr);
    if (expression == null) {
        plat_io_printf_err("expr(%s) is an expr object.\n", name_of_last_mmobj(expr));
        return null;
    }

    opExpr->expr = retain_mmobj(expression);

    return op;
}

AstNode ast_create_binary_op_expr(AstNode expr_a, AstNode expr_b, ast_binary_op op)
{
    switch (op)
    {
        case ast_binary_op_add:
        case ast_binary_op_subtract:
        case ast_binary_op_multiply:
        case ast_binary_op_divide:
        case ast_binary_op_modulo:

        case ast_binary_op_list_access:
        case ast_binary_op_map_access:

        case ast_binary_op_shift_left:
        case ast_binary_op_shift_right:

        case ast_binary_op_equal:
        case ast_binary_op_not_equal:
        case ast_binary_op_less:
        case ast_binary_op_great:
        case ast_binary_op_less_or_equal:
        case ast_binary_op_great_or_equal:
        case ast_binary_op_and:
        case ast_binary_op_or:

        case ast_binary_op_bit_and:
        case ast_binary_op_bit_or:
        case ast_binary_op_bit_xor:

        case ast_binary_op_apply_to:
        case ast_binary_op_pipe_1to1:
        case ast_binary_op_pipe_reduce:
        case ast_binary_op_pipe_expand:
        case ast_binary_op_pipe_inject:
            break;
        default: {
            plat_io_printf_err("Incorrect binary op(%d)\n", op);
            return null;
        }
     }

    return toAstNode(autorelease_mmobj(allocAstBinaryOpExprWithExprsAndOp(_pool, toAstExpression(expr_a), toAstExpression(expr_b), op)));
}

AstNode ast_create_binary_op_expr_w_op(ast_binary_op op)
{
    switch (op)
    {
        case ast_binary_op_add:
        case ast_binary_op_subtract:
        case ast_binary_op_multiply:
        case ast_binary_op_divide:
        case ast_binary_op_modulo:

        case ast_binary_op_list_access:
        case ast_binary_op_map_access:

        case ast_binary_op_shift_left:
        case ast_binary_op_shift_right:

        case ast_binary_op_equal:
        case ast_binary_op_not_equal:
        case ast_binary_op_less:
        case ast_binary_op_great:
        case ast_binary_op_less_or_equal:
        case ast_binary_op_great_or_equal:
        case ast_binary_op_and:
        case ast_binary_op_or:

        case ast_binary_op_bit_and:
        case ast_binary_op_bit_or:
        case ast_binary_op_bit_xor:

        case ast_binary_op_apply_to:
        case ast_binary_op_pipe_1to1:
        case ast_binary_op_pipe_reduce:
        case ast_binary_op_pipe_expand:
        case ast_binary_op_pipe_inject:
            break;
        default: {
            plat_io_printf_err("Incorrect binary op(%d)\n", op);
            return null;
        }
    }

    return toAstNode(autorelease_mmobj(allocAstBinaryOpExprWithOp(_pool, op)));
}

AstNode ast_apply_binary_op_expr_w_expr_a(AstNode op_expr, AstNode expr_a)
{
    AstBinaryOpExpr binaryOpExpr = toAstBinaryOpExpr(op_expr);
    if (binaryOpExpr == null) {
        plat_io_printf_err("op_expr should be AstBinaryOpExpr.(%s)\n", name_of_last_mmobj(op_expr));
        return null;
    }

    AstExpression expression = toAstExpression(expr_a);
    if (expression == null) {
        plat_io_printf_err("expr_a should be AstExpression.(%s)\n", name_of_last_mmobj(expr_a));
        return null;
    }

    applyExprAtoBinaryOpExpr(binaryOpExpr, expression);
    return op_expr;
}

AstNode ast_apply_binary_op_expr_w_expr_b(AstNode op_expr, AstNode expr_b)
{
    AstBinaryOpExpr binaryOpExpr = toAstBinaryOpExpr(op_expr);
    if (binaryOpExpr == null) {
        plat_io_printf_err("op_expr should be AstBinaryOpExpr.(%s)\n", name_of_last_mmobj(op_expr));
        return null;
    }

    AstExpression expression = toAstExpression(expr_b);
    if (expression == null) {
        plat_io_printf_err("expr_b should be AstExpression.(%s)\n", name_of_last_mmobj(expr_b));
        return null;
    }

    applyExprBtoBinaryOpExpr(binaryOpExpr, expression);
    return op_expr;
}

AstNode ast_create_ternary_op_expr(AstNode expr_a, AstNode expr_b, AstNode expr_c, ast_ternary_op op)
{
    switch (op)
    {
        case ast_ternary_op_conditional:
            break;
        default: {
            plat_io_printf_err("Incorrect ternary op(%d)\n", op);
            return null;
        }
    }

    return toAstNode(autorelease_mmobj(allocAstTernaryOpExprWithOp(_pool, toAstExpression(expr_a), toAstExpression(expr_b), toAstExpression(expr_c), op)));
}

AstNode ast_create_container(AstNode expr_a, AstNode expr_b, ast_container_type type)
{
    AstExprContainer exprContainerA = toAstExprContainer(expr_a);
    AstExprContainer exprContainerB = toAstExprContainer(expr_b);

    if (exprContainerA && isExprContainerClosed(exprContainerA)) {
        exprContainerA = null;      // it is just an expression, not a container.
    }

    if (exprContainerB && isExprContainerClosed(exprContainerB)) {
        exprContainerB = null;      // it is just an expression, not a container.
    }

    if (exprContainerA && exprContainerB) {
        concatExprContainer(exprContainerA, exprContainerB);
        return (expr_a);
    } else if (exprContainerA) {
        if (expr_b) {
            addExprToExprContainer(exprContainerA, toAstExpression(expr_b));
        }
        return (expr_a);
    }
    else if (exprContainerB) {
        if (expr_a) {
            insertExprToExprContainerAt(exprContainerB, toAstExpression(expr_a), 0);
        }
        return (expr_b);
    }
    else {
        exprContainerA = allocAstExprContainerWithType(_pool, type);

        if (expr_a) {
            addExprToExprContainer(exprContainerA, toAstExpression(expr_a));
        }

        if (expr_b) {
            addExprToExprContainer(exprContainerA, toAstExpression(expr_b));
        }

        return toAstNode(autorelease_mmobj(exprContainerA));
    }
}

AstNode ast_close_container(AstNode expr)
{
    AstExprContainer exprContainer = toAstExprContainer(expr);
    if (exprContainer == null) {
        plat_io_printf_err("Is this a container?(%s)\n", name_of_last_mmobj(expr));
        return null;
    }
    closeExprContainer(exprContainer);
    return expr;
}

AstNode ast_create_pair(AstNode key, AstNode value)
{
    AstExpression expression_key = toAstExpression(key);
    if (expression_key == null) {
        plat_io_printf_err("Key is not an expression.(%s)\n", name_of_last_mmobj(key));
    }
    AstExpression expression_value = toAstExpression(value);
    if (expression_value == null) {
        plat_io_printf_err("Value is not an expression.(%s)\n", name_of_last_mmobj(value));
    }

    return toAstNode(autorelease_mmobj(allocAstExprPairWithKeyAndValue(_pool, expression_key, expression_value)));
}

AstNode ast_create_var_instance(AstNode declare, AstNode inst)
{
    AstVarDeclare declare_obj = toAstVarDeclare(declare);
    AstVariable variable = toAstVariable(inst);
    return toAstNode(autorelease_mmobj(allocAstVarInstantWithDeclareAndInstance(_pool, declare_obj, variable)));
}

AstNode ast_create_var_instance_ex(AstNode type, AstNode identifier, AstNode inst)
{
    AstType type_obj = toAstType(type);
    AstIdentifier identifier_obj = toAstIdentifier(identifier);
    AstVarDeclare declare = autorelease_mmobj(allocAstVarDeclareWithIdentifier(_pool, identifier_obj, type_obj));
    return ast_create_var_instance(toAstNode(declare), inst);
}

AstNode ast_create_var_declare(AstNode type, AstNode identifier)
{
    AstType type_obj = toAstType(type);
    AstIdentifier identifier_obj = toAstIdentifier(identifier);
    return toAstNode(autorelease_mmobj(allocAstVarDeclareWithIdentifier(_pool, identifier_obj, type_obj)));
}

AstNode ast_create_type_list(AstNode first, AstNode second)
{
    AstTypeList first_list = toAstTypeList(first);
    AstTypeList second_list = toAstTypeList(second);

    if (first_list && second_list) {
        concatTypeList(first_list, second_list);
        return (first);
    }
    else if (first_list) {
        if (second) {
            addTypeToTypeList(first_list, toAstType(second));
        }
        return (first);
    }
    else if (second_list) {
        if (first) {
            insertTypeToTypeListAt(second_list, toAstType(first), 0);
        }
        return (second);
    }
    else {
        first_list = allocAstTypeList(_pool);

        if (first) {
            addTypeToTypeList(first_list, toAstType(first));
        }

        if (second) {
            addTypeToTypeList(first_list, toAstType(second));
        }

        return toAstNode(autorelease_mmobj(first_list));
    }
}

AstNode ast_create_var_list(AstNode first, AstNode second)
{
    AstVarDeclareList first_list = toAstVarDeclareList(first);
    AstVarDeclareList second_list = toAstVarDeclareList(second);

    if (first_list && second_list) {
        concatVarDeclareList(first_list, second_list);
        return (first);
    }
    else if (first_list) {
        if (second) {
            addVarDeclareToVarDeclareList(first_list, toAstVarDeclare(second));
        }
        return (first);
    }
    else if (second_list) {
        if (first) {
            insertVarDeclareToVarDeclareListAt(second_list, toAstVarDeclare(first), 0);
        }
        return (second);
    }
    else {
        first_list = allocAstVarDeclareList(_pool);

        if (first) {
            addVarDeclareToVarDeclareList(first_list, toAstVarDeclare(first));
        }

        if (second) {
            addVarDeclareToVarDeclareList(first_list, toAstVarDeclare(second));
        }

        return toAstNode(autorelease_mmobj(first_list));
    }
}

AstNode ast_create_external_declarations(AstNode first, AstNode second)
{
    AstExternalDeclarations first_list = toAstExternalDeclarations(first);
    AstExternalDeclarations second_list = toAstExternalDeclarations(second);

    //plat_io_printf_dbg("ext_dec %s(%p) - %s(%p)\n", name_of_last_mmobj(first), first, name_of_last_mmobj(second), second);

    if (first_list && second_list) {
        concatExternalDeclarations(first_list, second_list);
        return (first);
    }
    else if (first_list) {
        if (second) {
            addExternalDeclarationTo(first_list, toAstNode(second));
        }
        return (first);
    }
    else if (second_list) {
        if (first) {
            insertExternalDeclarationAt(second_list, toAstNode(first), 0);
        }
        return (second);
    }
    else {
        first_list = allocAstExternalDeclarations(_pool);

        if (first) {
            addExternalDeclarationTo(first_list, toAstNode(first));
        }

        if (second) {
            addExternalDeclarationTo(first_list, toAstNode(second));
        }

        return toAstNode(autorelease_mmobj(first_list));
    }
}

AstNode ast_create_block(AstNode first, AstNode second)
{
    AstBlockStatement first_block = toAstBlockStatement(first);
    AstBlockStatement second_block = toAstBlockStatement(second);

    if (first_block && isBlockClosed(first_block)) {
        first_block = null;
    }

    if (second_block && isBlockClosed(second_block)) {
        second_block = null;
    }

    if (first_block && second_block) {
        concatBlock(first_block, second_block);
        return (first);
    }
    else if (first_block) {
        if (second) {
            addStmtToBlock(first_block, toAstNode(second));
        }
        return (first);
    }
    else if (second_block) {
        if (first) {
            insertStmtToBlockAt(second_block, toAstNode(first), 0);
        }
        return (second);
    }
    else {
        first_block = allocAstBlockStatement(_pool);

        if (first) {
            addStmtToBlock(first_block, toAstNode(first));
        }

        if (second) {
            addStmtToBlock(first_block, toAstNode(second));
        }

        return toAstNode(autorelease_mmobj(first_block));
    }
}

AstNode ast_close_block(AstNode block)
{
    AstBlockStatement blockStatement = toAstBlockStatement(block);

    if (blockStatement == null) {
        plat_io_printf_err("Is this a block statement?(%s)\n", name_of_last_mmobj(block));
        return null;
    }

    closeBlock(blockStatement);

    return block;
}

AstNode ast_create_stmt_address(AstNode label)
{
    AstIdentifier identifier = toAstIdentifier(label);
    if (identifier == null) {
        plat_io_printf_err("Statement Address needs a identifier label.(%s)\n", name_of_last_mmobj(label));
    }

    return toAstNode(autorelease_mmobj(allocAstStmtAddressWithLabel(_pool, identifier)));
}

AstNode ast_create_la_declaration(AstNode input, AstNode body, AstNode output)
{
    if (verbose) plat_io_printf_dbg("Declare la\n");

    if (input == null)
    {
        // mean in:var input variable
        AstNode name_obj = ast_create_identifier("in");
        AstNode type_obj = ast_create_type(ast_type_var);
        AstNode var_obj = ast_create_var_declare(type_obj, name_obj);

        input = ast_create_var_list(var_obj, null);
    }

    if (output == null)
    {
        // mean var-type output variable
        AstNode type_obj = ast_create_type(ast_type_var);

        output = ast_create_type_list(type_obj, null);
    }

    return toAstNode(autorelease_mmobj(allocAstALaWithImpl(_pool, toAstVarDeclareList(input), toAstBlockStatement(body), toAstTypeList(output))));
}

AstNode ast_create_a_proc_la(AstNode package, AstNode external_declarations)
{
    if (verbose) plat_io_printf_dbg("ast_create_a_proc_la\n");
    AstPackage package_obj = toAstPackage(package);
    AstExternalDeclarations external_declarations_obj = toAstExternalDeclarations(external_declarations);

    *_ast = toAstNode(autorelease_mmobj(allocAstAProcLaWithPackageAndExternalDeclarations(_pool, package_obj, external_declarations_obj)));
    return *_ast;
}

AstScope ast_impl_create_scope(AstNode trigger, AstScope last_scope)
{
    if (verbose) plat_io_printf_dbg("ast_impl_create_scope\n");

    AstScope scope = autorelease_mmobj(allocAstScopeWithTriggerAndLastScope(_pool, trigger, last_scope));

    return scope;
}


/// ============================= AST implementation =======================================================

plat_inline void pushAllToAstStack(AstStack stack, MMList list, bool revert) {
    const uint size = sizeOfMMList(list);
    uint idx;
    if (size)
    {
        if (revert) {
            idx = size;
            do {
                idx--;
                AstNode node = toAstNode(getMMListItem(list, idx));
                pushToAstStack(stack, node);
                //plat_io_printf_dbg("%d. %p\n", idx, node);
            } while (idx > 0);
        } else {
            for (idx=0; idx<size; idx++) {
                AstNode node = toAstNode(getMMListItem(list, idx));
                pushToAstStack(stack, node);
                //plat_io_printf_dbg("%d. %p\n", idx, node);
            }
        }
    }
}

void iterate_ast(AstNode obj, ast_iterator iterator)
{
    AstScope scope = null;

    AstStack stack = allocAstStackWithANode(_pool, obj);
    fflush(stdout);
    uint level = 0;
    scope_action sa;

    while (!isEmptyAstStack(stack))
    {
        obj = popFromAstStack(stack);

        switch(oid_of_last_mmobj(obj))
        {
            case AST_A_PROC_LA:
            {
                scope = ast_impl_create_scope(obj, scope/*last scope*/);
                pushToAstStack(stack, toAstNode(scope));
                // put all items
                AstAProcLa aprocObj = toAstAProcLa(obj);
                pushToAstStack(stack, toAstNode(aprocObj->external_declarations));
                pushToAstStack(stack, toAstNode(aprocObj->package));

                sa = scope_action_created;
                break;
            }
            case AST_EXTERNAL_DECLARATIONS:
            {
                scope = ast_impl_create_scope(obj, scope/*last scope*/);
                pushToAstStack(stack, toAstNode(scope));
                // put all items
                AstExternalDeclarations externalDeclarations = toAstExternalDeclarations(obj);
                pushAllToAstStack(stack, externalDeclarations->external_declarations, true);

                sa = scope_action_created;
                break;
            }
            case AST_A_LA:
            {
                scope = ast_impl_create_scope(obj, scope/*last scope*/);
                pushToAstStack(stack, toAstNode(scope));

                AstALa variableLa = toAstALa(obj);

                if (variableLa->output) pushToAstStack(stack, toAstNode(variableLa->output));       // AST_TYPE_LIST_DECLARATION
                if (variableLa->body) pushToAstStack(stack, toAstNode(variableLa->body));           // AST_BLOCK_STATEMENT
                if (variableLa->input) pushToAstStack(stack, toAstNode(variableLa->input));         // AST_VAR_LIST_DECLARATION

                sa = scope_action_created;
                break;
            }
            case AST_TYPE_LIST_DECLARATION:
            {
                scope = ast_impl_create_scope(obj, scope/*last scope*/);
                pushToAstStack(stack, toAstNode(scope));
                // put all items
                AstTypeList typeList = toAstTypeList(obj);
                pushAllToAstStack(stack, typeList->list, true);

                sa = scope_action_created;
                break;
            }
            case AST_VAR_LIST_DECLARATION:
            {
                scope = ast_impl_create_scope(obj, scope/*last scope*/);
                pushToAstStack(stack, toAstNode(scope));
                // put all items
                AstVarDeclareList varDeclareList = toAstVarDeclareList(obj);
                pushAllToAstStack(stack, varDeclareList->list, true);

                sa = scope_action_created;
                break;
            }
            case AST_BLOCK_STATEMENT:
            {
                scope = ast_impl_create_scope(obj, scope/*last scope*/);
                pushToAstStack(stack, toAstNode(scope));
                // put all items
                AstBlockStatement laBody = toAstBlockStatement(obj);
                pushAllToAstStack(stack, laBody->stmts, true);

                sa = scope_action_created;
                break;
            }
            case AST_VAR_INSTANCE:
            {
                scope = ast_impl_create_scope(obj, scope/*last scope*/);
                pushToAstStack(stack, toAstNode(scope));

                AstVarInstance varInstance = toAstVarInstance(obj);
                pushToAstStack(stack, toAstNode(varInstance->inst));
                pushToAstStack(stack, toAstNode(varInstance->declare));

                sa = scope_action_created;
                break;
            }
            case AST_SCOPE:
            {
                if (scope != toAstScope(obj)) {
                    plat_io_printf_err("Impossible\n");
                }
                scope = toAstScope(obj);
                obj = scope->trigger;

                sa = scope_action_destroyed;
                break;
            }
            default:
            {
                sa = scope_action_using;
                break;
            }

        }

        if (sa == scope_action_destroyed)
        {
            level --;
        }

        iterator(obj, level, sa, scope);

        if (sa == scope_action_created)
        {
            level ++;
        }
        else if (sa == scope_action_destroyed)
        {
            // restore last scope
            scope = scope->last_scope;

            // == garbage collection ==
            uint size0 = mgn_mem_count_of_mem(_pool);
            mgn_mem_release_unused(_pool);
            uint size1 = mgn_mem_count_of_mem(_pool);
            if (size0 != size1) {
                //plat_io_printf_dbg("GC, autorelease count: %u\n", size0-size1);
            }
        }
    }

    release_mmobj(stack);

}



