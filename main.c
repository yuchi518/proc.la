#include "ast.h"
#include "mmo_unittest.h"

bool print_ast(AstNode obj, uint level, scope_action action, AstScope scope)
{
    static char sc[3];
    sc[scope_action_created] = '+';
    sc[scope_action_using] = '|';
    sc[scope_action_destroyed] = '-';

    uint32 oid = oid_of_last_mmobj(obj);
    if (oid == oid_of_AstDomainName())
    {
        plat_io_printf_std("%*s%c <<%s(%p:%d)>>\t%s\n", level<<2, "", sc[action], name_of_last_mmobj(obj), obj, retain_count_of_mmobj(obj), toAstDomainName(obj)->name->value);
    }
    else if (oid == oid_of_AstPackage())
    {
        plat_io_printf_std("%*s%c <<%s>>\t%s\n", level<<2, "", sc[action], name_of_last_mmobj(obj), toAstPackage(obj)->name->value);
    }
    else if (oid == oid_of_AstIdentifier())
    {
        plat_io_printf_std("%*s%c <<%s(%p:%d)>>\t%s\n", level<<2, "", sc[action], name_of_last_mmobj(obj), obj, retain_count_of_mmobj(obj), toAstIdentifier(obj)->name->value);
    }
    else if (oid == oid_of_AstVarDeclare())
    {
        AstVarDeclare varDeclare = toAstVarDeclare(obj);
        AstTypeCombination typeCombination = toAstTypeCombination(varDeclare->identifier_type);
        if (typeCombination) {
            char str[64] = "\0";
            char* p = str;
            uint i;
            for (i=0; i<16; i++) {
                ast_type_combination tc = getCombinationType(typeCombination, i);
                if (tc) p += sprintf(p, "%s", ast_type_combination_name(tc));
                else break;
            }
            plat_io_printf_std("%*s%c <<%s(%p:%d)>>\t%s:%s%s\n", level<<2, "", sc[action], name_of_last_mmobj(obj), obj, retain_count_of_mmobj(obj),
                               varDeclare->identifier->name->value, ast_type_name(varDeclare->identifier_type->type), str);
        } else {
            plat_io_printf_std("%*s%c <<%s(%p:%d)>>\t%s:%s\n", level<<2, "", sc[action], name_of_last_mmobj(obj), obj, retain_count_of_mmobj(obj),
                               varDeclare->identifier->name->value, ast_type_name(varDeclare->identifier_type->type));
        }
    }
    else if (oid == oid_of_AstVariable())
    {
        AstVariable variable = toAstVariable(obj);
        ast_type type = variable->type;
        switch (type)
        {
            case ast_type_int: {
                int32 i = toMMInt(variable->value)->value;
                plat_io_printf_std("%*s%c <<%s>> %d(%08x)\n", level<<2, "", sc[action], ast_type_name(type), i, i);
                break;
            }
            case ast_type_long: {
                int64 l = toMMLong(variable->value)->value;
                plat_io_printf_std("%*s%c <<%s>> %lld(%16llx)\n", level<<2, "", sc[action], ast_type_name(type), (long long)l, (long long)l);
                break;
            }
            case ast_type_float: {
                plat_io_printf_std("%*s%c <<%s>> %f\n", level<<2, "", sc[action], ast_type_name(type), toMMFloat(variable->value)->value);
                break;
            }
            case ast_type_double: {
                plat_io_printf_std("%*s%c <<%s>> %f\n", level<<2, "", sc[action], ast_type_name(type), toMMDouble(variable->value)->value);
                break;
            }
            case ast_type_string: {
                plat_io_printf_std("%*s%c <<%s>> %s\n", level<<2, "", sc[action], ast_type_name(type), toMMString(variable->value)->value);
                break;
            }
            case ast_type_number:break;
            case ast_type_raw:break;
            case ast_type_proc:break;
            case ast_type_la:break;
            case ast_type_var:break;
            default: {
                plat_io_printf_std("%*s%c <<%s>> Not support format.(%d)\n", level<<2, "", sc[action], ast_type_name(type), type);
                break;
            }
        }
    }
    else if (oid == oid_of_AstType())
    {
        plat_io_printf_std("%*s%c <<%s(%p:%d)>>\t%s\n", level<<2, "", sc[action], name_of_last_mmobj(obj), obj, retain_count_of_mmobj(obj),
                           ast_type_name(toAstType(obj)->type));
    }
    else if (oid == oid_of_AstUnaryOpExpr())
    {
        plat_io_printf_std("%*s%c <<%s(%p:%d)>>\t%s\n", level<<2, "", sc[action], name_of_last_mmobj(obj), obj, retain_count_of_mmobj(obj),
                           ast_ast_unary_op_text(toAstUnaryOpExpr(obj)->op));
    }
    else if (oid == oid_of_AstBinaryOpExpr())
    {
        plat_io_printf_std("%*s%c <<%s(%p:%d)>>\t%s\n", level<<2, "", sc[action], name_of_last_mmobj(obj), obj, retain_count_of_mmobj(obj),
                           ast_ast_binary_op_text(toAstBinaryOpExpr(obj)->op));
    }
    else if (oid == oid_of_AstTernaryOpExpr())
    {
        plat_io_printf_std("%*s%c <<%s(%p:%d)>>\t%s\n", level<<2, "", sc[action], name_of_last_mmobj(obj), obj, retain_count_of_mmobj(obj),
                           ast_ast_ternary_op_text(toAstTernaryOpExpr(obj)->op));
    }
    // TODO: Implement each, loop statement
    else if (oid == oid_of_AstErrorRecovery())
    {
        plat_io_printf_std("%*s%c <<%s(%p:%d)>>\t%s\n", level<<2, "", sc[action], name_of_last_mmobj(obj), obj, retain_count_of_mmobj(obj),
                           "\t\t!!!!! Error here !!!!!");
        plat_io_flush_std();
        //plat_io_printf_err("\t\t!!!!! Error here !!!!!\n");
        //plat_io_flush_err();
    }
    else
    {
        plat_io_printf_std("%*s%c <<%s(%p:%d)>>\n", level<<2, "", sc[action], name_of_last_mmobj(obj), obj, retain_count_of_mmobj(obj));
    }
    return true;
}

int load_file_and_create_ast(const char* file_name) {
    char* content;
    uint content_size;
    int res;
    AstNode ast = null;
    mgn_memory_pool pool = null;

    res = plat_io_get_resource(file_name, (void**)&content, &content_size);

    if (res == 0)
    {
        //printf("=====Source =====\n");
        //printf("%s\n", content);
        //printf("=================\n");
        //plat_io_flush_std();
        res = create_ast(&pool, content, content_size, &ast);
        free(content);
        plat_io_flush_std();

        if (res == 0 && ast != null)
        {
            if (!verify_and_optimize_ast(ast)) {
                plat_io_printf_err("Verification or optimization fail.\n");
                //mgn_mem_release_all(&pool);
                //return -1;
            }

            retain_mmobj(ast);
            mgn_mem_release_unused(&pool);
            plat_io_printf_dbg("=== Tree ===\n");
            iterate_ast(ast, print_ast);
            plat_io_printf_dbg("=== Pack ===\n");

            MMPacker packer = allocMMPacker(&pool);
            pack_mmobj(0, ast, packer);
            uint len;
            uint8 *data = dyb_get_data_before_current_position(packer->dyb, &len);
            //PRINTF_HEXMEM_TO_TARGET(fprintf, stdout, data, len, 256);

            plat_io_printf_dbg("=== UnPack ===\n");
            MMUnpacker unpacker = allocMMUnpackerWithData(&pool, data, len);
            register_all_ast_to_unpacker(unpacker);
            AstNode cloned_ast = toAstNode(unpack_mmobj(0, unpacker));      // autorelease

            plat_io_printf_dbg("=== Cloned Tree ===\n");
            iterate_ast(cloned_ast, print_ast);

            if (are_equal_mmobjs(ast, cloned_ast)) {
                plat_io_printf_dbg("Original ast tree and cloned ast tree are equal!!\n");
            } else {
                plat_io_flush_std();
                plat_io_printf_err("Original ast tree is not equal to cloned ast tree!!\n");
            }

            plat_io_printf_dbg("=== Release ===\n");
            release_mmobj(ast);
            release_mmobj(unpacker);
            release_mmobj(packer);
            mgn_mem_release_unused(&pool);

            if (mgn_mem_count_of_mem(&pool) > 0) {
                plat_io_printf_err("=== Fail ===\n");
                plat_io_printf_err("Zombie objects count:%zu\n", mgn_mem_count_of_mem(&pool));
            } else {
                plat_io_printf_dbg("=== Pass ===\n");
            }
        }
    }

    mgn_mem_release_all(&pool);

    return 0;
}


int main() {

    unit_test_mmobj();

    load_file_and_create_ast("first.la");
    load_file_and_create_ast("expr.la");

    return 0;
}