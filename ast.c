//
// Created by Yuchi Chen on 2017/8/13.
//

#include "ast.h"
#include "autogen/proc.la.l.c"

static struct src_stack *_curbs = null;
static mgn_memory_pool* _pool = null;
AstNode* _ast = null;
static const bool verbose = false;
static char* _content;
static uint _content_size;

int create_ast(mgn_memory_pool* pool, char* content, uint content_size, AstNode* ast)
{
    _pool = pool;
    struct src_stack *bs = (struct src_stack*)mgn_mem_alloc(pool, sizeof(struct src_stack));
    if(!bs) {
        if (ast) *ast = null;
        return -1;
    }

    _ast = ast;
    _content = content;
    _content_size = content_size;
    yycolumn = 1;
    yylineno = 1;
    //yylloc.first_column = 0; yylloc.last_column = 0;
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

AstNode ast_create_empty(void) {
    return toAstNode(autorelease_mmobj(allocAstEmpty(_pool)));
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

    if (appendCombinationType(combination, container_typ) >= 16)
    {
        plat_io_printf_err("Create combined type - slot is not enough (%08x)\n", combination->combined_type);
        return null;
    }

    return toAstNode(autorelease_mmobj(combination));
}

AstNode ast_create_const_i(char* value)
{
    if (verbose) plat_io_printf_dbg("Create int - %s\n", value);

    uint base, idx;
    uint cnt, max_cnt;
    uint8 v;
    char c;
    dybuf* dyb;

    switch (value[0]) {
        case 'b':
        case 'B':
        {
            // binary format, b(00000001 00000010 00000011 000000100)
            base = 2;
            max_cnt = 8;
            break;
        }
        case 'o':
        case 'O':
        {
            // octal format: o(377 377 377 377)
            base = 8;
            max_cnt = 3;
            break;
        }
        case 'h':
        case 'H':
        {
            // hex format: h(0a 02 0f 04)
            base = 16;
            max_cnt = 2;
            break;
        }
        default:
        {
            long long long_val = atoll(value);

            if ((long_val & 0xffffffff00000000) != 0)
            {
                return toAstNode(autorelease_mmobj(allocVariableWithLongValue(_pool, (int64)long_val)));
            }
            else
            {
                return toAstNode(autorelease_mmobj(allocVariableWithIntValue(_pool, (int32)long_val)));
            }
            break;
        }
    }

    idx = 2;
    cnt = 0;
    v = 0;
    dyb = dyb_create(null, 16);

    while ((c=value[idx++]))
    {
        if (c == ')') break;
        if (c == ' ') continue;

        v *= base;

        if (c >= '0' && c<='9') {
            v += c - '0';
        } else if (c >= 'a' && c <= 'f') {
            v += c - 'a' + 10;
        } else if (c >= 'A' && c <= 'F') {
            v += c - 'A' + 10;
        }

        if (++cnt >= max_cnt) {
            dyb_append_u8(dyb, v);
            v = 0;
            cnt = 0;
        }
    }

    AstNode node = null;
    uint size = dyb_get_position(dyb);
    dyb_flip(dyb);

    if (size <= 4) {
        int32 i = (int32)dyb_next_u32(dyb);
        node = toAstNode(autorelease_mmobj(allocVariableWithIntValue(_pool, i)));
    } else if (size <= 8) {
        int64 l = (int64)dyb_next_u64(dyb);
        node = toAstNode(autorelease_mmobj(allocVariableWithIntValue(_pool, l)));
    } else {
        node = toAstNode(autorelease_mmobj(allocVariableWithRawData(_pool, dyb_next_data_without_len(dyb, size), size)));
    }

    dyb_release(dyb);

    return node;
}

AstNode ast_create_const_f(char* value)
{
    if (verbose) plat_io_printf_dbg("Create float - %s\n", value);

    double d = strtod(value, NULL);
    AstNode obj = toAstNode(allocVariableWithDoubleValue(_pool, d));

    return autorelease_mmobj(obj);
}

AstNode ast_create_const_s(char* value)
{
    if (verbose) plat_io_printf_dbg("Create string - %s\n", value);
    uint len = plat_cstr_length(value);
    if (len>=2 && value[0]=='\"' && value[len-1]=='\"') {
        char* new_value = plat_mem_allocate(len);
        plat_mem_copy(new_value, value+1, len-2);
        new_value[len-2]='\0';
        value = new_value;
    }

    return toAstNode(autorelease_mmobj(allocVariableWithCString(_pool, value)));
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
    //plat_io_printf_err("iden: %s\n", value);
    return toAstNode(autorelease_mmobj(allocAstIdentifierWithCStringName(_pool, value)));
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
        plat_io_printf_err("Unary Op is not an Op expression.(%s)\n", name_of_last_mmobj(op));
        return null;
    }

    AstExpression expression = toAstExpression(expr);
    if (expression == null) {
        plat_io_printf_err("Unary Op need an expression.(%s)\n", name_of_last_mmobj(expr));
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

    AstExpression expression_a = toAstExpression(expr_a);
    if (expression_a == null) {
        plat_io_printf_err("Ternary expression needs an expression(a).(%s)\n", name_of_last_mmobj(expr_a));
        return null;
    }

    AstExpression expression_b = toAstExpression(expr_b);
    if (expression_b == null) {
        plat_io_printf_err("Ternary expression needs an expression(b).(%s)\n", name_of_last_mmobj(expr_b));
        return null;
    }

    AstExpression expression_c = toAstExpression(expr_c);
    if (expression_c == null) {
        plat_io_printf_err("Ternary expression needs an expression(c).(%s)\n", name_of_last_mmobj(expr_c));
        return null;
    }

    return toAstNode(autorelease_mmobj(allocAstTernaryOpExprWithOp(_pool, expression_a, expression_b, expression_c, op)));
}

AstNode ast_create_is_expr(AstNode expr, AstNode typ)
{
    AstExpression expression = toAstExpression(expr);
    if (expression == null) {
        plat_io_printf_err("Is expression needs an expression.(%s)\n", name_of_last_mmobj(expr));
        return null;
    }

    AstType type = toAstType(typ);
    if (type == null) {
        plat_io_printf_err("Is expression needs a type.(%s)\n", name_of_last_mmobj(typ));
        return null;
    }

    return toAstNode(autorelease_mmobj(allocAstIsExprWithExprAndType(_pool, expression, type)));
}

AstNode ast_create_container(AstNode expr_a, AstNode expr_b, ast_container_type type)
{
    AstContainerExpr containerExprA = toAstContainerExpr(expr_a);
    AstContainerExpr containerExprB = toAstContainerExpr(expr_b);

    if (containerExprA && isContainerExprClosed(containerExprA)) {
        containerExprA = null;      // it is just an expression, not a container.
    }

    if (containerExprB && isContainerExprClosed(containerExprB)) {
        containerExprB = null;      // it is just an expression, not a container.
    }

    if (containerExprA && containerExprB) {
        concatContainerExpr(containerExprA, containerExprB);
        return (expr_a);
    } else if (containerExprA) {
        if (expr_b) {
            addExprToContainerExpr(containerExprA, toAstExpression(expr_b));
        }
        return (expr_a);
    }
    else if (containerExprB) {
        if (expr_a) {
            insertExprToContainerExprAt(containerExprB, toAstExpression(expr_a), 0);
        }
        return (expr_b);
    }
    else {
        containerExprA = allocAstContainerExprWithType(_pool, type);

        if (expr_a) {
            addExprToContainerExpr(containerExprA, toAstExpression(expr_a));
        }

        if (expr_b) {
            addExprToContainerExpr(containerExprA, toAstExpression(expr_b));
        }

        return toAstNode(autorelease_mmobj(containerExprA));
    }
}

AstNode ast_close_container(AstNode expr)
{
    AstContainerExpr containerExpr = toAstContainerExpr(expr);
    if (containerExpr == null) {
        plat_io_printf_err("Is this a container?(%s)\n", name_of_last_mmobj(expr));
        return null;
    }
    closeContainerExpr(containerExpr);
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

    return toAstNode(autorelease_mmobj(allocAstPairExprWithKeyAndValue(_pool, expression_key, expression_value)));
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
    AstBlockStmt first_block = toAstBlockStmt(first);
    AstBlockStmt second_block = toAstBlockStmt(second);

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
            AstStatement statement = toAstStatement(second);
            if (statement == null) {
                plat_io_printf_err("Why is not a statement?(%s)\n", name_of_last_mmobj(second));
                return null;
            }
            addStmtToBlock(first_block, statement);
        }
        return (first);
    }
    else if (second_block) {
        if (first) {
            AstStatement statement = toAstStatement(first);
            if (statement == null) {
                plat_io_printf_err("Why is not a statement?(%s)\n", name_of_last_mmobj(first));
                return null;
            }
            insertStmtToBlockAt(second_block, statement, 0);
        }
        return (second);
    }
    else {
        first_block = allocAstBlockStmt(_pool);

        if (first) {
            AstStatement statement = toAstStatement(first);
            if (statement == null) {
                plat_io_printf_err("Why is not a statement?(%s)\n", name_of_last_mmobj(first));
                return null;
            }
            addStmtToBlock(first_block, statement);
        }

        if (second) {
            AstStatement statement = toAstStatement(second);
            if (statement == null) {
                plat_io_printf_err("Why is not a statement?(%s)\n", name_of_last_mmobj(second));
                return null;
            }
            addStmtToBlock(first_block, statement);
        }

        return toAstNode(autorelease_mmobj(first_block));
    }
}

AstNode ast_close_block(AstNode block)
{
    AstBlockStmt blockStatement = toAstBlockStmt(block);

    if (blockStatement == null) {
        plat_io_printf_err("Is this a block statement?(%s)\n", name_of_last_mmobj(block));
        return null;
    }

    closeBlock(blockStatement);

    return block;
}

AstNode ast_create_case(AstNode check)
{
    AstExpression expression = toAstExpression(check);
    if (check && expression==null) {
        plat_io_printf_err("Check for case needs an expression.(%s)\n", name_of_last_mmobj(check));
        return null;
    }

    plat_io_printf_err("%s\n", name_of_last_mmobj(check));

    return toAstNode(autorelease_mmobj(allocAstCaseStmtWithCheck(_pool, expression)));
}

AstNode ast_create_switch(AstNode eval, AstNode stmt)
{
    AstExpression expression = toAstExpression(eval);
    if (expression == null) {
        plat_io_printf_err("Switch statement needs an evaluation.(%s)\n", name_of_last_mmobj(eval));
        return null;
    }

    AstStatement statement = toAstStatement(stmt);
    if (statement==null || (toAstNone(stmt)==null && toAstBlockStmt(stmt)==null)) {
        // Switch statement must uses block statement.
        plat_io_printf_err("Switch statement needs a block statement.(%s)\n", name_of_last_mmobj(stmt));
        return null;
    }

    return toAstNode(autorelease_mmobj(allocAstSwitchStmtWithEvalAndStmt(_pool, expression, statement)));
}

AstNode ast_create_ifelse(AstNode eval, AstNode true_stmt, AstNode false_stmt)
{
    AstExpression expression = toAstExpression(eval);
    if (expression == null) {
        plat_io_printf_err("If statement needs an evaluation.(%s)\n", name_of_last_mmobj(eval));
        return null;
    }

    AstStatement statement_ture = toAstStatement(true_stmt);
    if (statement_ture==null) {
        plat_io_printf_err("If statement needs a statement.(%s)\n", name_of_last_mmobj(true_stmt));
        return null;
    }

    AstStatement statement_false = toAstStatement(false_stmt);
    if (false_stmt && statement_false==null) {
        plat_io_printf_err("Else statement needs a statement.(%s)\n", name_of_last_mmobj(false_stmt));
        return null;
    }

    return toAstNode(autorelease_mmobj(allocAstIfStmtWithEvalAndStmts(_pool, expression, statement_ture, statement_false)));
}

AstNode ast_create_loop(AstNode stmt)
{
    AstStatement statement = toAstStatement(stmt);
    if (statement == null) {
        plat_io_printf_err("Loop statement needs a statement.(%s)\n", name_of_last_mmobj(stmt));
        return null;
    }

    return toAstNode(autorelease_mmobj(allocAstLoopStmtWithStmt(_pool, statement)));
}

AstNode ast_create_each(AstNode eval, AstNode stmt)
{
    AstExpression expression = toAstExpression(eval);
    if (expression == null) {
        plat_io_printf_err("Each statement needs an evaluation.(%s)\n", name_of_last_mmobj(eval));
        return null;
    }

    AstStatement statement = toAstStatement(stmt);
    if (statement == null) {
        plat_io_printf_err("Each statement needs a statement.(%s)\n", name_of_last_mmobj(stmt));
        return null;
    }

    return toAstNode(autorelease_mmobj(allocAstEachStmtWithEvalAndStmt(_pool, expression, statement)));
}

AstNode ast_create_jump(ast_jump_type type, AstNode id)
{
    switch (type) {
        case ast_jump_type_goto:break;
        case ast_jump_type_break:break;
        case ast_jump_type_continue:break;
        default:
            plat_io_printf_err("Unknown jump type.(%d)\n", type);
            break;
    }

    if (type==ast_jump_type_goto) {
        AstIdentifier identifier = toAstIdentifier(id);
        if (identifier == null) {
            plat_io_printf_err("Goto statement needs an identifier.(%s)\n", name_of_last_mmobj(id));
            return null;
        }
        return toAstNode(autorelease_mmobj(allocAstJumpStmtWithTypeAndIdentifier(_pool, type, identifier)));
    } else {
        if (id) {
            plat_io_printf_err("Redundant identifier:%s\n", name_of_last_mmobj(id));
            return null;
        }
        return toAstNode(autorelease_mmobj(allocAstJumpStmtWithTypeAndIdentifier(_pool, type, null)));
    }
}

AstNode ast_create_anchor(AstNode label)
{
    AstIdentifier identifier = toAstIdentifier(label);
    if (identifier == null) {
        plat_io_printf_err("Anchor statement needs a label.(%s)\n", name_of_last_mmobj(label));
        return null;
    }

    return toAstNode(autorelease_mmobj(allocAstAnchorStmtWithLabel(_pool, identifier)));
}

AstNode ast_create_sync(AstNode id)
{
    AstIdentifier identifier = toAstIdentifier(identifier);
    if (identifier == null) {
        plat_io_printf_err("Sync statement needs an identifier.(%s)\n", name_of_last_mmobj(id));
        return null;
    }

    return toAstNode(autorelease_mmobj(allocAstSyncStmtWithIdentifier(_pool, identifier)));
}

AstNode ast_create_la_declaration(AstNode input, AstNode body, AstNode output)
{
    if (verbose) plat_io_printf_dbg("Declare la\n");

    if (input == null) {
        // mean in:var input variable
        AstNode name_obj = ast_create_identifier("in");
        AstNode type_obj = ast_create_type(ast_type_var);
        AstNode var_obj = ast_create_var_declare(type_obj, name_obj);
        input = ast_close_container(ast_create_container(var_obj, null, ast_container_type_tuple));
    }
    else {
        if (isAstNone(input)) {
            // We prefer using an empty container expression instead of a none object.
            input = toAstNode(autorelease_mmobj(allocEmptyAstContainerExprWithType(_pool, ast_container_type_tuple)));
        } else if (toAstContainerExpr(input) == null) {
            plat_io_printf_err("La declaration needs an expr container as input.(%s)\n", name_of_last_mmobj(input));
            return null;
        }
    }

    if (output == null) {
        // mean var-type output variable
        AstNode type_obj = ast_create_type(ast_type_var);
        output = ast_create_type_list(type_obj, null);
    }
    else {
        if (isAstNone(output)) {
            // We prefer using an empty type list instead of a none object
            output = toAstNode(autorelease_mmobj(allocEmptyAstTypeList(_pool)));
        } else if (toAstTypeList(output) == null) {
            plat_io_printf_err("La declaration needs a type list as output.(%s)\n", name_of_last_mmobj(output));
            return null;
        }
    }

    if (body == null) {
        // is possible?
        plat_io_printf_err("La declaration need a body.(null)\n");
        return null;
    } else {
        if (toAstBlockStmt(body) == null) {
            if (isAstNone(body)) {
                AstBlockStmt blockStmt = autorelease_mmobj(allocAstBlockStmt(_pool));
                closeBlock(blockStmt);
                body = toAstNode(blockStmt);
            } else {
                plat_io_printf_err("La declaration need a block statement as body.(%s)\n", name_of_last_mmobj(body));
                return null;
            }
        }
    }

    return toAstNode(autorelease_mmobj(allocAstALaWithImpl(_pool, toAstContainerExpr(input), toAstBlockStmt(body), toAstTypeList(output))));
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

AstNode ast_create_error_recovery(void)
{
    return toAstNode(autorelease_mmobj(allocAstErrorRecovery(_pool)));
}

AstNode ast_create_error_recovery_ex(const char* msg, int first_line, int first_column, int last_line, int last_column)
{

    plat_io_printf_err("Parse(%s) in %d.%d ~ %d.%d\n", msg, first_line, first_column, last_line, last_column);
    if (first_column < _content_size && last_column < _content_size) {
        int i;
        for (i=first_column; i<=last_column; i++) fprintf(stderr, "%c", _content[i]);
        fprintf(stderr, "\n");
    }
    return toAstNode(error_recovery(_pool, 0, mmstring(_pool, "Parse in %d.%d ~ %d.%d", first_line, first_column, last_line, last_column), null));
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
    plat_io_flush_std();
    uint level = 0;
    scope_action sa;

    while (!isEmptyAstStack(stack))
    {
        obj = popFromAstStack(stack);

        uint32 oid = oid_of_last_mmobj(obj);
        if (oid == oid_of_AstAProcLa())
        {
            scope = ast_impl_create_scope(obj, scope/*last scope*/);
            pushToAstStack(stack, toAstNode(scope));
            // put all items
            AstAProcLa aprocObj = toAstAProcLa(obj);
            pushToAstStack(stack, toAstNode(aprocObj->external_declarations));
            pushToAstStack(stack, toAstNode(aprocObj->package));

            sa = scope_action_created;
        }
        else if (oid == oid_of_AstExternalDeclarations())
        {
            scope = ast_impl_create_scope(obj, scope/*last scope*/);
            pushToAstStack(stack, toAstNode(scope));
            // put all items
            AstExternalDeclarations externalDeclarations = toAstExternalDeclarations(obj);
            pushAllToAstStack(stack, externalDeclarations->external_declarations, true);

            sa = scope_action_created;
        }
        else if (oid == oid_of_AstALa())
        {
            scope = ast_impl_create_scope(obj, scope/*last scope*/);
            pushToAstStack(stack, toAstNode(scope));

            AstALa variableLa = toAstALa(obj);

            if (variableLa->output) pushToAstStack(stack, toAstNode(variableLa->output));       // AST_TYPE_LIST_DECLARATION
            if (variableLa->body) pushToAstStack(stack, toAstNode(variableLa->body));           // AST_BLOCK
            if (variableLa->input) pushToAstStack(stack, toAstNode(variableLa->input));         // AST_VAR_LIST_DECLARATION

            sa = scope_action_created;
        }
        else if (oid == oid_of_AstTypeList())
        {
            scope = ast_impl_create_scope(obj, scope/*last scope*/);
            pushToAstStack(stack, toAstNode(scope));
            // put all items
            AstTypeList typeList = toAstTypeList(obj);
            pushAllToAstStack(stack, typeList->list, true);

            sa = scope_action_created;
        }
        else if (oid == oid_of_AstContainerExpr())
        {
            scope = ast_impl_create_scope(obj, scope/*last scope*/);
            pushToAstStack(stack, toAstNode(scope));
            // put all items
            AstContainerExpr containerExpr = toAstContainerExpr(obj);
            pushAllToAstStack(stack, containerExpr->list, true);

            sa = scope_action_created;
        }
        else if (oid == oid_of_AstUnaryOpExpr())
        {
            scope = ast_impl_create_scope(obj, scope/*last scope*/);
            pushToAstStack(stack, toAstNode(scope));
            AstUnaryOpExpr unaryOpExpr = toAstUnaryOpExpr(obj);
            pushToAstStack(stack, toAstNode(unaryOpExpr->expr));

            sa = scope_action_created;
        }
        else if (oid == oid_of_AstBinaryOpExpr())
        {
            scope = ast_impl_create_scope(obj, scope/*last scope*/);
            pushToAstStack(stack, toAstNode(scope));
            AstBinaryOpExpr binaryOpExpr = toAstBinaryOpExpr(obj);
            pushToAstStack(stack, toAstNode(binaryOpExpr->expr_b));
            pushToAstStack(stack, toAstNode(binaryOpExpr->expr_a));

            sa = scope_action_created;
        }
        else if (oid == oid_of_AstTernaryOpExpr())
        {
            scope = ast_impl_create_scope(obj, scope/*last scope*/);
            pushToAstStack(stack, toAstNode(scope));
            AstTernaryOpExpr ternaryOpExpr = toAstTernaryOpExpr(obj);
            pushToAstStack(stack, toAstNode(ternaryOpExpr->expr_c));
            pushToAstStack(stack, toAstNode(ternaryOpExpr->expr_b));
            pushToAstStack(stack, toAstNode(ternaryOpExpr->expr_a));

            sa = scope_action_created;
        }
        else if (oid == oid_of_AstBlockStmt())
        {
            scope = ast_impl_create_scope(obj, scope/*last scope*/);
            pushToAstStack(stack, toAstNode(scope));
            // put all items
            AstBlockStmt laBody = toAstBlockStmt(obj);
            pushAllToAstStack(stack, laBody->stmts, true);

            sa = scope_action_created;
        }
        else if (oid == oid_of_AstSwitchStmt())
        {
            scope = ast_impl_create_scope(obj, scope/*last scope*/);
            pushToAstStack(stack, toAstNode(scope));

            AstSwitchStmt switchStmt = toAstSwitchStmt(obj);
            pushToAstStack(stack, toAstNode(switchStmt->stmt));
            pushToAstStack(stack, toAstNode(switchStmt->eval));

            sa = scope_action_created;
        }
        else if (oid == oid_of_AstCaseStmt())
        {
            scope = ast_impl_create_scope(obj, scope/*last scope*/);
            pushToAstStack(stack, toAstNode(scope));

            AstCaseStmt caseStmt = toAstCaseStmt(obj);
            pushToAstStack(stack, toAstNode(caseStmt->check));

            sa = scope_action_created;
        }
        else if (oid == oid_of_AstVarInstance())
        {
            scope = ast_impl_create_scope(obj, scope/*last scope*/);
            pushToAstStack(stack, toAstNode(scope));

            AstVarInstance varInstance = toAstVarInstance(obj);
            pushToAstStack(stack, toAstNode(varInstance->inst));
            pushToAstStack(stack, toAstNode(varInstance->declare));

            sa = scope_action_created;
        }
        else if (oid == oid_of_AstPairExpr())
        {
            scope = ast_impl_create_scope(obj, scope/*last scope*/);
            pushToAstStack(stack, toAstNode(scope));

            AstPairExpr pairExpr = toAstPairExpr(obj);
            pushToAstStack(stack, toAstNode(pairExpr->expr_v));
            pushToAstStack(stack, toAstNode(pairExpr->expr_k));

            sa = scope_action_created;
        }
        else if (oid == oid_of_AstScope())
        {
            if (scope != toAstScope(obj)) {
                plat_io_printf_err("Impossible\n");
            }
            scope = toAstScope(obj);
            obj = scope->trigger;

            sa = scope_action_destroyed;
        }
        else
        {
            sa = scope_action_using;
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

/// ============================== AST syntax and semantic check, optimize =============


bool verify_and_optimize_ast(AstNode obj)
{
#if 1
    if (isAstAProcLa(obj)) {
        AstAProcLa aProcLa = toAstAProcLa(obj);
        AstErrorRecovery errorRecovery = optimize_node(aProcLa, null);
        if (errorRecovery) {
            plat_io_printf_err("Error %d: %s\n", errorRecovery->code, errorRecovery->message->value);
        } else {
            return true;
        }
    }
    return false;
#else
    AstScope scope = null;

    AstStack stack = allocAstStackWithANode(_pool, obj);
    plat_io_flush_std();
    //uint level = 0;
    //scope_action sa;
    AstAProcLa aProcLa = null;

    while (!isEmptyAstStack(stack)) {
        obj = popFromAstStack(stack);

        uint32 oid = oid_of_last_mmobj(obj);
        if (oid == oid_of_AstAProcLa()) {
            /**
             *  A Proc La verification/optimization
             *  @brief Create proc/la list
             */
            if (aProcLa) {
                plat_io_printf_err("Multiple aProcLa, impossible.\n");
                return false;
            }
            aProcLa = toAstAProcLa(obj);
            optimize_node(aProcLa, null);

            scope = ast_impl_create_scope(obj, scope/*last scope*/);
            pushToAstStack(stack, toAstNode(scope));
            // put all items

            if (aProcLa->external_declarations && aProcLa->external_declarations->external_declarations) {
                pushAllToAstStack(stack, aProcLa->external_declarations->external_declarations, true);
            } else {
                plat_io_printf_std("Warning!! Empty external declarations.\n");
            }
            //sa = scope_action_created;
        } else if (oid == oid_of_AstVarInstance()) {
            /**
             *  Var Instance verification/optimization
             *  @brief Make sure it is supported type.
             */
            AstVarInstance varInstance = toAstVarInstance(obj);
            AstVarDeclare varDeclare = varInstance->declare;
            ast_type type = varDeclare->identifier_type->type;

            if (type == ast_type_proc) {
                plat_io_printf_err("No supported type: ast_type_proc\n");
                return false;
            }

            pushVarInstanceIntoScope(scope, varInstance);       // push all variables into scopes for reference

            if (type == ast_type_la) {
                //varInstance->inst
                AstVariable variable = varInstance->inst;

                if (variable->type != ast_type_la) {
                    plat_io_printf_err("The variable instance is not a la.(%s)\n", ast_type_name(varInstance->inst->type));
                    return false;
                }

                if (isAstALa(variable)) {
                    // a la
                    pushToAstStack(stack, toAstNode(variable));
                } else if (isAstDomainName(variable)) {
                    // domain name
                } else {
                    plat_io_printf_err("What is this?(%s: %s)\n", varInstance->declare->identifier->name->value, name_of_last_mmobj(variable));
                    return false;
                }
            } else {
                if (varInstance->inst->type != type) {
                    plat_io_printf_err("Unsupported type conversion.(%s --> %s)\n", ast_type_name(varInstance->inst->type), ast_type_name(type));
                    return false;
                }
            }
        } else if (oid == oid_of_AstUnaryOpExpr()) {
            /**
             * Unary Op verification/optimization
             */
            AstUnaryOpExpr unaryOpExpr = toAstUnaryOpExpr(obj);

        } else if (oid == oid_of_AstALa()) {
            /**
             *  La verification/optimization
             *  @brief Make sure all input arguments are Var Declare.
             */
            AstALa aLa = toAstALa(obj);

            scope = ast_impl_create_scope(obj, scope/*last scope*/);
            pushToAstStack(stack, toAstNode(scope));

            //if (aLa->output) pushToAstStack(stack, toAstNode(aLa->output));       // AST_TYPE_LIST_DECLARATION
            //if (aLa->body) pushToAstStack(stack, toAstNode(aLa->body));           // AST_BLOCK
            //if (aLa->input) pushToAstStack(stack, toAstNode(aLa->input));         // AST_VAR_LIST_DECLARATION
            AstContainerExpr containerExpr = aLa->input;
            uint cnt = sizeOfContainerExpr(containerExpr);
            uint i;
            for (i=0; i<cnt; i++) {
                AstExpression expr = getExprFromContainerExprAt(containerExpr, i);
                if (isAstVarDeclare(expr)) {
                    pushVarDeclareIntoScope(scope, toAstVarDeclare(expr));       // push all variables into scopes for reference
                } else {
                    plat_io_printf_err("A la needs variable declare as input parameter.(%s)\n", name_of_last_mmobj(expr));
                    return false;
                }
            }

            AstBlockStmt blockStmt = aLa->body;
            set_ast_parent_node(blockStmt, obj);
            // TODO: set parent node for each statement of blockStmt->stmts
            pushAllToAstStack(stack, blockStmt->stmts, true);

        } else if (oid == oid_of_AstScope()) {
            if (scope != toAstScope(obj)) {
                plat_io_printf_err("Impossible\n");
            }
            scope = toAstScope(obj);
            obj = scope->trigger;

            //sa = scope_action_destroyed;
            scope = scope->last_scope;
        } else if (oid == oid_of_AstErrorRecovery()) {
            /**
             *  @brief Check existing errors.
             */
            plat_io_flush_std();
            plat_io_printf_err("Error in AST, fix it first.\n");
            return false;
        } else {
            plat_io_printf_std("No optimize - %s\n", name_of_last_mmobj(obj));
        }
    }

    release_mmobj(stack);

    return true;
#endif
}

void iterate_ast_ex(AstNode node, ast_iterator_ex previous, ast_iterator_ex executor)
{
    AstScope scope = null;

    AstStack stack = allocAstStackWithANode(_pool, node);
    plat_io_flush_std();
    //uint level = 0;
    //scope_action sa;
    AstAProcLa aProcLa = null;

    while (!isEmptyAstStack(stack)) {
        node = popFromAstStack(stack);
        uint32 oid = oid_of_last_mmobj(node);
        // TODO: implement new iterate function for executing code
    }

    release_mmobj(stack);
}