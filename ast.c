//
// Created by Yuchi Chen on 2017/8/13.
//
#include <stdarg.h>

#include "ast.h"
#include "plat_string.h"
#include "proc.la.l.c"

static struct src_stack *_curbs = null;
static mgn_memory_pool* _pool = null;

int create_ast(mgn_memory_pool* pool, char* content, uint content_size)
{
    _pool = pool;
    struct src_stack *bs = (struct src_stack*)mgn_mem_alloc(pool, sizeof(struct src_stack));
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

#define alloc_struct(pool, struct_name, assign_typ) \
    ({ struct_name* rv = (struct_name*)mgn_mem_alloc(pool, sizeof(struct_name)); if (rv) rv->is_a.typ = assign_typ; rv; })
#define alloc_string(pool, string_size) \
    (char*)mgn_mem_alloc(pool, string_size)


void release_struct(struct la_ast* obj)
{
    plat_io_printf_std("- release_struct - %s\n", la_ast_typ_to_string(obj->typ));
    boolean release_member = mgn_mem_retained_count(_pool, obj) == 1?true:false;

    if (release_member)
    {
        switch(obj->typ)
        {
            case la_ast_inst_number:
                /** TODO: release number variables **/
                break;
            case la_ast_inst_string: {
                struct la_ast_inst_string *string_obj = _obj2inst(obj, struct la_ast_inst_string);
                mgn_mem_release(_pool, string_obj->string);
                break;
            }
            case la_ast_package_name:
            case la_ast_domain_name:
            case la_ast_identifier: {
                struct la_ast_name* name_obj = _obj2inst(obj, struct la_ast_name);
                mgn_mem_release(_pool, name_obj->name);
                break;
            }
            case la_ast_var_declare:
            {
                struct la_ast_var_declare* var_obj = _obj2inst(obj, struct la_ast_var_declare);
                mgn_mem_release(_pool, var_obj->identifier_name);
                break;
            }
            case la_ast_var_list_declaration:
            case la_ast_type_list_declaration:
            case la_ast_external_declarations:
            {
                struct la_ast_collection* collection_obj = _obj2inst(obj, struct la_ast_collection);
                utarray_done(&collection_obj->collection);
                break;
            }
            case la_ast_a_proc_la:
            {
                struct la_ast_a_proc_la* a_proc_la_obj = _obj2inst(obj, struct la_ast_a_proc_la);
                if (a_proc_la_obj->package_name) mgn_mem_release(_pool, a_proc_la_obj->package_name);
                if (a_proc_la_obj->external_declarations) mgn_mem_release(_pool, a_proc_la_obj->external_declarations);
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
    plat_io_printf_std("Create unit - %s\n", la_ast_typ_to_string(typ));

    struct la_ast_unit* obj = alloc_struct(_pool, struct la_ast_unit, typ);

    return &obj->is_a;
}

struct la_ast* la_ast_create_combined_type(struct la_ast* base_type, enum la_ast_container_typ container_typ)
{
    plat_io_printf_std("la_ast_create_combined_type - %s - %s\n", la_ast_typ_to_string(base_type->typ), la_ast_container_typ_to_string(container_typ));

    struct la_ast_type_container* container = null;

    if ((base_type->typ & __la_ast_type_flag__) == 0)
    {
        plat_io_printf_err("Create combined type - incorrect type\n");
        return null;
    }

    if (base_type->typ == la_ast_type_container)
    {
        // base type is already a combined type
        container = _obj2inst(base_type, struct la_ast_type_container);
        mgn_mem_retain(_pool, container);
    }
    else
    {
        container = alloc_struct(_pool, struct la_ast_type_container, la_ast_type_container);
        container->combined_type = base_type->typ;      // init combined type
    }

    int i=0;
    for (i=0;i<16;i+=2)
    {
        if ((container->combined_type & (0x03<<i)) == 0)
        {
            // empty slot
            container->combined_type |= (0x03 & container_typ) << i;
            break;
        }
    }

    if (i>=16)
    {
        plat_io_printf_err("Create combined type - slot is not enough (%08x)\n", container->combined_type);
    }

    return &container->is_a;
}

struct la_ast* la_ast_create_const_i(char* value)
{
    plat_io_printf_std("Create int - %s\n", value);

    struct la_ast* is_a;
    // TODO: implement parser
    // include three types: la_ast_inst_int, la_ast_inst_long, la_ast_inst_number

    long long long_val = atoll(value);

    if ((long_val & 0xffffffff00000000) != 0)
    {
        struct la_ast_inst_long* obj = alloc_struct(_pool, struct la_ast_inst_long, la_ast_inst_long);
        is_a = &obj->is_a;
    }
    else
    {
        struct la_ast_inst_int* obj = alloc_struct(_pool, struct la_ast_inst_int, la_ast_inst_int);
        is_a = &obj->is_a;
    }

    return is_a;
}

struct la_ast* la_ast_create_const_f(char* value)
{
    plat_io_printf_std("Create float - %s\n", value);

    struct la_ast_inst_double* obj = alloc_struct(_pool, struct la_ast_inst_double, la_ast_inst_float); // float, double, etc.
    // TODO: implement float, double parser

    return &obj->is_a;
}

struct la_ast* la_ast_create_const_s(char* value)
{
    plat_io_printf_std("Create string - %s\n", value);

    struct la_ast_inst_string* obj = alloc_struct(_pool, struct la_ast_inst_string, la_ast_inst_string);

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
    plat_io_printf_std("Create name - %s for %s\n", value, la_ast_typ_to_string(typ));

    struct la_ast_name* obj = alloc_struct(_pool, struct la_ast_name, typ); // la_ast_package_name, la_ast_full_name, la_ast_identifier

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
    plat_io_printf_std("Declare var - %s - %s\n", la_ast_typ_to_string(var->typ), la_ast_typ_to_string(var_typ->typ));

    struct la_ast_var_declare* obj = alloc_struct(_pool, struct la_ast_var_declare, la_ast_var_declare);

    struct la_ast_name* name_obj = _obj2inst(var, struct la_ast_name);

    obj->identifier_name = mgn_mem_retain(_pool, name_obj->name);
    obj->identifier_typ = var_typ->typ;

    plat_io_printf_std("\t\t%s:%s\n", obj->identifier_name, la_ast_typ_to_string(obj->identifier_typ));

    return &obj->is_a;
}

struct la_ast* la_ast_create_var_instance(struct la_ast* declare, struct la_ast* inst)
{
    plat_io_printf_std("Create var instance - %s - %s\n", la_ast_typ_to_string(declare->typ), la_ast_typ_to_string(inst->typ));

    struct la_ast_var_instance* instance = alloc_struct(_pool, struct la_ast_var_instance, la_ast_var_instance);

    instance->declare = mgn_mem_retain(_pool, declare);
    instance->inst = mgn_mem_retain(_pool, inst);

    return &instance->is_a;
}

struct la_ast* la_ast_create_var_instance_ex(struct la_ast* var/*aka. identifier*/, struct la_ast* var_typ, struct la_ast* inst)
{
    plat_io_printf_std("Create var instance - %s - %s - %s\n", la_ast_typ_to_string(var->typ), la_ast_typ_to_string(var_typ->typ), la_ast_typ_to_string(inst->typ));

    struct la_ast* declare = la_ast_create_var_declare(var, var_typ);
    struct la_ast* instance = la_ast_create_var_instance(declare, inst);
    release_struct(declare);

    return instance;
}

struct la_ast* la_ast_create_la_alias(struct la_ast* domain, struct la_ast* identifier)
{
    plat_io_printf_std("Create la alias - %s - %s\n", la_ast_typ_to_string(domain->typ), la_ast_typ_to_string(identifier->typ));

    struct la_ast_la_alias* obj = alloc_struct(_pool, struct la_ast_la_alias, la_ast_la_alias);

    struct la_ast_name* domain_obj = _obj2inst(domain, struct la_ast_name);
    struct la_ast_name* identifier_obj = _obj2inst(identifier, struct la_ast_name);

    obj->domain_name = mgn_mem_retain(_pool, domain_obj->name);
    obj->identifier_name = mgn_mem_retain(_pool, identifier_obj->name);

    plat_io_printf_std("\t\talias %s -> %s\n", obj->domain_name, obj->identifier_name);

    return &obj->is_a;
}


struct la_ast* la_ast_create_collection(enum la_ast_typ typ, ...)
{
    int i;
    struct la_ast_collection *coll = null;

    plat_io_printf_std("Create collection - %s\n", la_ast_typ_to_string(typ));

    va_list valist;
    va_start(valist, typ);

    for (i = 0; ; i++)
    {
        struct la_ast* obj = va_arg(valist, struct la_ast*);
        if (obj == null) break;

        plat_io_printf_std("\t\t- %s\n", la_ast_typ_to_string(obj->typ));

        if (coll == null)
        {
            if (obj->typ == typ)
            {
                coll = _obj2inst(obj, struct la_ast_collection);
                mgn_mem_retain(_pool, coll);
            }
            else
            {
                coll = alloc_struct(_pool, struct la_ast_collection, typ);
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
        if (i==0)
        {
            coll = alloc_struct(_pool, struct la_ast_collection, typ);
            utarray_init(&coll->collection, &ut_ast__icd);
        }
        else
        {
            plat_io_printf_err("Ast collection is empty, why?\n");
            return null;
        }
    }

    return &coll->is_a;
}

struct la_ast* la_ast_create_la_declaration(struct la_ast* input, struct la_ast* body, struct la_ast* output)
{
    plat_io_printf_std("Declare la\n");
    struct la_ast_la_declaration* a_la = alloc_struct(_pool, struct la_ast_la_declaration, la_ast_la_declaration);

    if (input == null)
    {
        // mean in:var input variable
        struct la_ast* name_obj = la_ast_create_name(la_ast_identifier, "in");
        struct la_ast* type_obj = la_ast_create_type(la_ast_type_var);
        struct la_ast* var_obj = la_ast_create_var_declare(name_obj, type_obj);

        input = la_ast_create_collection(la_ast_var_list_declaration, var_obj, null);

        release_struct(var_obj);
        release_struct(type_obj);
        release_struct(name_obj);
    }
    else
    {
        mgn_mem_retain(_pool, input);
    }

    if (output == null)
    {
        // mean var-type output variable
        struct la_ast* type_obj = la_ast_create_type(la_ast_type_var);

        output = la_ast_create_collection(la_ast_type_list_declaration, type_obj, null);

        release_struct(type_obj);
    }
    else
    {
        mgn_mem_retain(_pool, output);
    }

    a_la->input = input;
    a_la->body = body;
    a_la->output = output;

    return &a_la->is_a;
}

struct la_ast* la_ast_create_a_proc_la(struct la_ast* package, struct la_ast* external_declarations)
{
    plat_io_printf_std("la_ast_create_a_proc_la\n");

    struct la_ast_a_proc_la* a_proc_la = alloc_struct(_pool, struct la_ast_a_proc_la, la_ast_a_proc_la);

    if (package != null)
    {
        if (package->typ == la_ast_package_name)
        {
            a_proc_la->package_name = mgn_mem_retain(_pool, package);
        }
        else
        {
            plat_io_printf_err("Incorrect package name(%d)\n", package->typ);
        }
    }
    else
        a_proc_la->package_name = null;

    if (external_declarations != null)
    {
        if (external_declarations->typ == la_ast_external_declarations)
        {
            a_proc_la->external_declarations = mgn_mem_retain(_pool, external_declarations);
        }
        else
        {
            plat_io_printf_err("Incorrect external declarations(%d)\n", external_declarations->typ);
        }
    }
    else
        a_proc_la->external_declarations = null;

    return &a_proc_la->is_a;
}