#include "ast.h"
#include "mmObj_unittest.h"

bool print_ast(AstNode obj, uint level, scope_action action, AstScope scope)
{
    static char sc[3];
    sc[scope_action_created] = '+';
    sc[scope_action_using] = '|';
    sc[scope_action_destroyed] = '-';

    switch(oid_of_mmobj(obj))
    {
        case AST_VARIABLE_DOMAIN_NAME:
        {
            plat_io_printf_std("%*s%c <<%s(%p:%d)>>\t%s\n", level<<2, "", sc[action], last_name_of_mmobj(obj), obj, retain_count_of_mmobj(obj), toAstDomainName(obj)->name->value);
            break;
        }
        case AST_VAR_DECLARE:
        {
            AstVarDeclare varDeclare = toAstVarDeclare(obj);
            plat_io_printf_std("%*s%c <<%s(%p:%d)>>\t%s:%s\n", level<<2, "", sc[action], last_name_of_mmobj(obj), obj, retain_count_of_mmobj(obj),
                               varDeclare->identifier->name->value, ast_type_name(varDeclare->identifier_type->type));

            break;
        }
        case AST_TYPE:
        {
            plat_io_printf_std("%*s%c <<%s(%p:%d)>>\t%s\n", level<<2, "", sc[action], last_name_of_mmobj(obj), obj, retain_count_of_mmobj(obj),
                               ast_type_name(toAstType(obj)->type));
            break;
        }
        default:
        {
            plat_io_printf_std("%*s%c <<%s(%p:%d)>>\n", level<<2, "", sc[action], last_name_of_mmobj(obj), obj, retain_count_of_mmobj(obj));
            break;
        }
    }
    return true;
}

int main() {
    //printf("Hello, World!\n");
    char* content;
    uint content_size;
    int res;
    AstNode ast;
    mgn_memory_pool pool = null;

    unit_test_mmobj();

    res = plat_io_get_resource("first.la", (void**)&content, &content_size);

    if (res == 0)
    {
        //printf("=====Source =====\n");
        //printf("%s\n", content);
        //printf("=================\n");
        //fflush(stdout);
        res = create_ast(&pool, content, content_size, &ast);
        free(content);
        fflush(stdout);

        if (res == 0 && ast != null)
        {
            plat_io_printf_dbg("=== Tree ===\n");
            iterate_ast(ast, print_ast);
            plat_io_printf_dbg("=== Release ===\n");
            release_mmobj(ast);
            mgn_mem_release_unused(&pool);

            plat_io_printf_dbg("=== done ===\n");

            if (mgn_mem_count_of_mem(&pool) > 0) {
                plat_io_printf_err("Zombie objects count:%zu\n", mgn_mem_count_of_mem(&pool));
            }
        }
    }

    mgn_mem_release_all(&pool);

    return 0;
}