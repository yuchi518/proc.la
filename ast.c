//
// Created by Yuchi Chen on 2017/8/13.
//
#include <stdarg.h>

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

AstNode la_ast_create_none(void) {
    return toAstNode(allocAstNone(_pool));
}

AstNode la_ast_create_type(ast_type type)
{
    return toAstNode(allocAstTypeWithType(_pool, type));
}

AstNode la_ast_create_combined_type(AstNode base_type, ast_type_combination container_typ)
{
    //if (verbose) plat_io_printf_std("la_ast_create_combined_type - %s - %d\n", name_of_mmobj(base_type), container_typ);

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

    return toAstNode(combination);
}

AstNode la_ast_create_const_i(char* value)
{
    if (verbose) plat_io_printf_std("Create int - %s\n", value);

    // TODO: implement parser
    // include three types: la_ast_inst_int, la_ast_inst_long, la_ast_inst_number

    long long long_val = atoll(value);

    if ((long_val & 0xffffffff00000000) != 0)
    {
        return toAstNode(allocVariableWithLongValue(_pool, (int64)long_val));
    }
    else
    {
        return toAstNode(allocVariableWithIntValue(_pool, (int32)long_val));
    }

    return null;
}

AstNode la_ast_create_const_f(char* value)
{
    if (verbose) plat_io_printf_std("Create float - %s\n", value);

    AstNode obj = toAstNode(allocVariableWithFloatValue(_pool, 0));
    // TODO: implement float, double parser

    return obj;
}

AstNode la_ast_create_const_s(char* value)
{
    if (verbose) plat_io_printf_std("Create string - %s\n", value);

    return toAstNode(allocVariableWithCString(_pool, value));
}

AstNode la_ast_create_ctrl(ast_ctrl_type ctrl)
{
    return toAstNode(allocAstCtrlFlowWithCtrl(_pool, ctrl));
}

AstNode la_ast_create_package(char* value)
{
    return toAstNode(allocAstPackageWithCStringName(_pool, value));
}

AstNode la_ast_create_domain(char* value)
{
    return toAstNode(allocAstDomainNameWithCStringName(_pool, value));
}

AstNode la_ast_create_identifier(char* value)
{
    return toAstNode(allocAstIdentifierWithCStringName(_pool, value));
}


AstNode la_ast_create_var_instance(AstNode declare, AstNode inst)
{
    AstVarDeclare declare_obj = toAstVarDeclare(declare);
    AstVariable variable = toAstVariable(inst);
    return toAstNode(allocAstVarInstantWithDeclareAndInstance(_pool, declare_obj, variable));
}

AstNode la_ast_create_var_instance_ex(AstNode type, AstNode identifier, AstNode inst)
{
    AstType type_obj = toAstType(type);
    AstIdentifier identifier_obj = toAstIdentifier(identifier);
    AstVarDeclare declare = allocAstVarDeclareWithIdentifier(_pool, identifier_obj, type_obj);
    return la_ast_create_var_instance(toAstNode(autorelease_mmobj(declare)), inst);
}

AstNode la_ast_create_var_declare(AstNode type, AstNode identifier)
{
    AstType type_obj = toAstType(type);
    AstIdentifier identifier_obj = toAstIdentifier(identifier);
    return toAstNode(allocAstVarDeclareWithIdentifier(_pool, identifier_obj, type_obj));
}

AstNode la_ast_create_type_list(AstNode first, AstNode second)
{
    AstTypeList first_list = toAstTypeList(first);
    AstTypeList second_list = toAstTypeList(first);

    if (first_list && second_list) {
        concatTypeList(first_list, second_list);
        return retain_mmobj(first);
    }
    else if (first_list) {
        if (second) {
            addTypeToTypeList(first_list, toAstType(second));
        }
        return retain_mmobj(first);
    }
    else if (second_list) {
        if (first) {
            insertTypeToTypeListAt(second_list, toAstType(first), 0);
        }
        return retain_mmobj(second);
    }
    else {
        first_list = allocAstTypeList(_pool);

        if (first) {
            addTypeToTypeList(first_list, toAstType(first));
        }

        if (second) {
            addTypeToTypeList(first_list, toAstType(second));
        }

        return toAstNode(first_list);
    }
}

AstNode la_ast_create_var_list(AstNode first, AstNode second)
{
    AstVarDeclareList first_list = toAstVarDeclareList(first);
    AstVarDeclareList second_list = toAstVarDeclareList(first);

    if (first_list && second_list) {
        concatVarDeclareList(first_list, second_list);
        return retain_mmobj(first);
    }
    else if (first_list) {
        if (second) {
            addVarDeclareToVarDeclareList(first_list, toAstVarDeclare(second));
        }
        return retain_mmobj(first);
    }
    else if (second_list) {
        if (first) {
            insertVarDeclareToVarDeclareListAt(second_list, toAstVarDeclare(first), 0);
        }
        return retain_mmobj(second);
    }
    else {
        first_list = allocAstVarDeclareList(_pool);

        if (first) {
            addVarDeclareToVarDeclareList(first_list, toAstVarDeclare(first));
        }

        if (second) {
            addVarDeclareToVarDeclareList(first_list, toAstVarDeclare(second));
        }

        return toAstNode(first_list);
    }
}

AstNode la_ast_create_external_declarations(AstNode first, AstNode second)
{
    AstExternalDeclarations first_list = toAstExternalDeclarations(first);
    AstExternalDeclarations second_list = toAstExternalDeclarations(first);

    if (first_list && second_list) {
        concatExternalDeclarations(first_list, second_list);
        return retain_mmobj(first);
    }
    else if (first_list) {
        if (second) {
            addExternalDeclarationToExternalDeclarations(first_list, toAstNode(second));
        }
        return retain_mmobj(first);
    }
    else if (second_list) {
        if (first) {
            insertExternalDeclarationToExternalDeclarationsAt(second_list, toAstNode(first), 0);
        }
        return retain_mmobj(second);
    }
    else {
        first_list = allocAstExternalDeclarations(_pool);

        if (first) {
            addExternalDeclarationToExternalDeclarations(first_list, toAstNode(first));
        }

        if (second) {
            addExternalDeclarationToExternalDeclarations(first_list, toAstNode(second));
        }

        return toAstNode(first_list);
    }
}

AstNode la_ast_create_ast_body(AstNode first, AstNode second)
{
    /// TODO: implementation
    return toAstNode(allocAstLaBody(_pool));
}

AstNode la_ast_create_la_declaration(AstNode input, AstNode body, AstNode output)
{
    if (verbose) plat_io_printf_std("Declare la\n");

    if (input == null)
    {
        // mean in:var input variable
        AstNode name_obj = la_ast_create_identifier("in");
        AstNode type_obj = la_ast_create_type(ast_type_var);
        AstNode var_obj = la_ast_create_var_declare(type_obj, name_obj);

        input = la_ast_create_var_list(var_obj, null);

        release_mmobj(var_obj);
        release_mmobj(type_obj);
        release_mmobj(name_obj);

        autorelease_mmobj(input);
    }

    if (output == null)
    {
        // mean var-type output variable
        AstNode type_obj = la_ast_create_type(ast_type_var);

        output = la_ast_create_type_list(type_obj, null);

        release_mmobj(type_obj);

        autorelease_mmobj(output);
    }

    return toAstNode(allocAstVariableLaWithImpl(_pool, toAstVarDeclareList(input), toAstLaBody(body), toAstTypeList(output)));
}

AstNode la_ast_create_a_proc_la(AstNode package, AstNode external_declarations)
{
    if (verbose) plat_io_printf_std("la_ast_create_a_proc_la\n");
    AstPackage package_obj = toAstPackage(package);
    AstExternalDeclarations external_declarations_obj = toAstExternalDeclarations(external_declarations);

    *_ast = toAstNode(allocAstAProcLaWithPackageAndExternalDeclarations(_pool, package_obj, external_declarations_obj));
    return *_ast;
}


/// ============================= AST implementation =======================================================

#define alloc_string(pool, string_size) \
    (char*)mgn_mem_alloc(pool, string_size)

#if 0

void iterate_ast(struct la_ast* obj, ast_iterator iterator)
{
    struct la_ast* scope = null;
    struct la_ast_impl_scope* scopeObj = null;

    struct la_ast* stack = la_ast_create_collection(la_ast_impl_stack, obj, null);
    struct la_ast_collection* stackObj = _obj2inst(stack, struct la_ast_collection);
    uint level = 0;
    bool postpone;

    while (utarray_len(&stackObj->collection))
    {
        void* tmp_ptr = utarray_back(&stackObj->collection);;
        obj = *(struct la_ast**)tmp_ptr;
        //if (obj==null) break;
        utarray_pop_back(&stackObj->collection);

        switch(obj->typ)
        {
            case la_ast_var_list_declaration:
            case la_ast_type_list_declaration:
            case la_ast_external_declarations:
            case la_ast_la_body_declaration:
            {
                level++;

                scope = la_ast_impl_create_scope(obj, scope/*last scope*/);
                scopeObj = _obj2inst(scope, struct la_ast_impl_scope);
                utarray_push_back(&stackObj->collection, &scope);
                // put all items
                struct la_ast_collection* collObj = _obj2inst(obj, struct la_ast_collection);
                //utarray_concat(&stackObj->collection, &collObj->collection);
                struct la_ast** p;
                for(p=(struct la_ast**)utarray_back(&collObj->collection); p!=NULL; p=(struct la_ast**)utarray_prev(&collObj->collection,p))
                {
                    utarray_push_back(&stackObj->collection, p);
                }

                postpone = true;
                break;
            }
            case la_ast_var_instance:
            {
                level ++;

                scope = la_ast_impl_create_scope(obj, scope/*last scope*/);
                scopeObj = _obj2inst(scope, struct la_ast_impl_scope);
                utarray_push_back(&stackObj->collection, &scope);

                struct la_ast_var_instance* varInstObj = _obj2inst(obj, struct la_ast_var_instance);
                if (varInstObj->inst) utarray_push_back(&stackObj->collection, &varInstObj->inst);
                if (varInstObj->declare) utarray_push_back(&stackObj->collection, &varInstObj->declare);

                postpone = true;
                break;
            }
            case la_ast_la_declaration:
            {
                level ++;

                scope = la_ast_impl_create_scope(obj, scope/*last scope*/);
                scopeObj = _obj2inst(scope, struct la_ast_impl_scope);
                utarray_push_back(&stackObj->collection, &scope);

                struct la_ast_la_declaration* laObj = _obj2inst(obj, struct la_ast_la_declaration);
                if (laObj->body) utarray_push_back(&stackObj->collection, &laObj->body);
                if (laObj->output) utarray_push_back(&stackObj->collection, &laObj->output);
                if (laObj->input) utarray_push_back(&stackObj->collection, &laObj->input);

                postpone = true;
                break;
            }
            case la_ast_a_proc_la:
            {
                level ++;

                scope = la_ast_impl_create_scope(obj, scope/*last scope*/);
                scopeObj = _obj2inst(scope, struct la_ast_impl_scope);
                utarray_push_back(&stackObj->collection, &scope);
                // put all items
                struct la_ast_a_proc_la* aprocObj = _obj2inst(obj, struct la_ast_a_proc_la);
                utarray_push_back(&stackObj->collection, &aprocObj->external_declarations);
                utarray_push_back(&stackObj->collection, &aprocObj->package_name);

                postpone = true;
                break;
            }
            case la_ast_impl_scope:
            {
                level--;

                scopeObj = _obj2inst(obj, struct la_ast_impl_scope);
                // restore last section
                obj = scopeObj->trigger;
                scope = scopeObj->last_scope;
                release_mmobj(&scopeObj->is_a);
                scopeObj = _obj2inst(scope, struct la_ast_impl_scope);

                postpone = false;
                break;
            }
            default:
            {
                postpone = false;
                break;
            }
        }

        if (!postpone) iterator(obj, level);



    }

    release_mmobj(stack);

}

struct la_ast* la_ast_impl_create_scope(struct la_ast* trigger, struct la_ast* last_scope)
{
    if (verbose) plat_io_printf_std("la_ast_impl_create_scope\n");

    struct la_ast_impl_scope* obj = alloc_astObj(_pool, struct la_ast_impl_scope, la_ast_impl_scope);
    obj->trigger = mgn_mem_retain(_pool, trigger);
    obj->last_scope = (last_scope==null)?null:mgn_mem_retain(_pool, last_scope);

    return &obj->is_a;
}
#endif

