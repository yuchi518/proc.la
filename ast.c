//
// Created by Yuchi Chen on 2017/8/13.
//
#include <stdarg.h>

#include "ast.h"
#include "plat_string.h"
#include "proc.la.l.c"

static struct src_stack *_curbs = null;
static mgn_memory_pool* _pool = null;

#define alloc_struct(pool, struct_name) \
    (struct_name*)mgn_mem_alloc(pool, sizeof(struct_name))
#define alloc_string(pool, string_size) \
    (char*)mgn_mem_alloc(pool, string_size)

int create_ast(mgn_memory_pool* pool, char* content, uint content_size)
{
    _pool = pool;
    struct src_stack *bs = alloc_struct(pool, struct src_stack);
    if(!bs) return -1;
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

    return 0;
}

/// ============================= AST implementation =======================================================

void release_struct(struct la_ast* obj)
{
    boolean release_member = mgn_mem_retained_count(_pool, obj) == 1?true:false;

    if (release_member)
    {
        switch(obj->typ)
        {
            case la_ast_const_number:
                /** TODO: release number variables **/
                break;
            case la_ast_const_string: {
                struct la_ast_const_string *string_obj = _obj2inst(obj, struct la_ast_const_string);
                mgn_mem_release(_pool, string_obj->string);
                break;
            }
            case la_ast_package_name:
            case la_ast_domain_name:
            case la_ast_identifier: {
                struct la_ast_name* name_obj = _obj2inst(obj, struct la_ast_name);
                mgn_mem_release(_pool, name_obj);
                break;
            }
            case la_ast_var_declare:
            {
                struct la_ast_var_declare* var_obj = _obj2inst(obj, struct la_ast_var_declare);
                mgn_mem_release(_pool, var_obj->identifier_name);
                break;
            }
            case la_ast_external_declarations:
            {
                struct la_ast_collection* collection_obj = _obj2inst(obj, struct la_ast_collection);
                utarray_done(&collection_obj->collection);
                break;
            }
            default:
                break;
        }
    }

    mgn_mem_release(_pool, obj);
}

void ut_ast_init(void *elt)
{
    struct la_ast* obj = *(struct la_ast**)elt;
    obj = null;
}
void ut_ast_copy(void *dst, const void *src)
{
    struct la_ast* dst_obj = *(struct la_ast**)dst;
    struct la_ast* src_obj = *(struct la_ast**)src;
    dst_obj = src_obj;
    mgn_mem_retain(_pool, dst_obj);
}

void ut_ast_del(void *elt)
{
    struct la_ast* obj = *(struct la_ast**)elt;
    mgn_mem_release(_pool, obj);
}

UT_icd ut_ast__icd = {sizeof(struct la_ast*), ut_ast_init, ut_ast_copy, ut_ast_del };

/// ========================================================================

struct la_ast* la_ast_create_unit(enum la_ast_typ typ)
{
    struct la_ast_unit* obj = alloc_struct(_pool, struct la_ast_unit);
    if (obj) obj->is_a.typ = typ;

    return &obj->is_a;
}

struct la_ast* la_ast_create_const_i(char* value)
{
    struct la_ast* is_a;
    /** TODO: implement parser **/
    // include three types: la_ast_const_int, la_ast_const_long, la_ast_const_number

    long long long_val = atoll(value);

    if ((long_val & 0xffffffff00000000) != 0)
    {
        struct la_ast_const_long* obj = alloc_struct(_pool, struct la_ast_const_long);
        if (obj) obj->is_a.typ = la_ast_const_long;   // long
        is_a = & obj->is_a;
    }
    else
    {
        struct la_ast_const_int* obj = alloc_struct(_pool, struct la_ast_const_int);
        if (obj) obj->is_a.typ = la_ast_const_int;   // int
        is_a = & obj->is_a;
    }

    return is_a;
}

struct la_ast* la_ast_create_const_f(char* value)
{
    struct la_ast_const_double* obj = alloc_struct(_pool, struct la_ast_const_double);
    if (obj) obj->is_a.typ = la_ast_const_float;   // float, double, etc.

    return &obj->is_a;
}

struct la_ast* la_ast_create_const_s(char* value)
{
    struct la_ast_const_string* obj = alloc_struct(_pool, struct la_ast_const_string);
    if (obj) obj->is_a.typ = la_ast_const_string;

    uint text_size = plat_cstr_length(value);
    obj->string = alloc_string(_pool, text_size+1);
    if (obj->string)
    {
        plat_mem_copy(obj->string, value, text_size);
        obj->string[text_size] = '\0';
    }

    return &obj->is_a;
}

struct la_ast* la_ast_create_name(enum la_ast_typ typ, char* value)
{
    struct la_ast_name* obj = alloc_struct(_pool, struct la_ast_name);
    if (obj) obj->is_a.typ = typ;   // la_ast_package_name, la_ast_full_name, la_ast_identifier

    uint text_size = plat_cstr_length(value);
    obj->name = alloc_string(_pool, text_size+1);
    if (obj->name)
    {
        plat_mem_copy(obj->name, value, text_size);
        obj->name[text_size] = '\0';
    }

    return &obj->is_a;
}

struct la_ast* la_ast_create_var_declare(struct la_ast* var, struct la_ast* var_typ)
{
    struct la_ast_var_declare* obj = alloc_struct(_pool, struct la_ast_var_declare);
    struct la_ast_name* name_obj = _obj2inst(var, struct la_ast_name);

    obj->identifier_name = mgn_mem_retain(_pool, name_obj->name);
    obj->identifier_typ = var_typ->typ;

    plat_io_printf_std("%s:%s\n", obj->identifier_name, la_ast_typ_to_string(obj->identifier_typ));

    return &obj->is_a;
}

struct la_ast* la_ast_create_la_alias(struct la_ast* domain, struct la_ast* identifier)
{
    struct la_ast_la_alias* obj = alloc_struct(_pool, struct la_ast_la_alias);
    struct la_ast_name* domain_obj = _obj2inst(domain, struct la_ast_name);
    struct la_ast_name* identifier_obj = _obj2inst(identifier, struct la_ast_name);

    obj->domain_name = mgn_mem_retain(_pool, domain_obj->name);
    obj->identifier_name = mgn_mem_retain(_pool, identifier_obj->name);

    plat_io_printf_std("alias %s -> %s\n", obj->domain_name, obj->identifier_name);

    return &obj->is_a;
}


struct la_ast* la_ast_create_collection(enum la_ast_typ typ, ...)
{
    int i;
    struct la_ast_collection *coll = null;
    va_list valist;
    va_start(valist, typ);

    for (i = 0; ; i++)
    {
        struct la_ast* obj = va_arg(valist, struct la_ast*);
        if (obj == null) break;

        if (coll == null)
        {
            if (obj->typ == typ)
            {
                coll = _obj2inst(obj, struct la_ast_collection);
                mgn_mem_retained_count(_pool, coll);
            }
            else
            {
                coll = alloc_struct(_pool, struct la_ast_collection);
                utarray_init(&coll->collection, &ut_ast__icd);
                utarray_push_back(&coll->collection, &obj);
            }
        }
        else
        {
            if (obj->typ == typ)
            {
                struct la_ast_collection* more_coll = _obj2inst(obj, struct la_ast_collection);
                utarray_concat(&coll->collection, &more_coll->collection);
            }
            else
            {
                utarray_push_back(&coll->collection, &obj);
            }
        }
    }

    va_end(valist);

    if (coll == null)
    {
        plat_io_printf_err("Ast collection is empty, why?");
    }

    return &coll->is_a;
}