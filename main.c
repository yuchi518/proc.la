#include "ast.h"
#include "ast_obj/ast_obj.h"

/*bool print_ast(struct la_ast* obj, uint level)
{
    plat_io_printf_std("%*s<<%s>>\n", level<<1, "", la_ast_typ_to_string(obj->typ));
    return true;
}*/

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

        if (res == 0 && ast != null)
        {
            plat_io_printf_std("=== Tree ===\n");
            //iterate_ast(ast, print_ast);
            plat_io_printf_std("=== Release ===\n");
            release_mmobj(ast);
        }

    }

    plat_io_printf_std("=== done ===\n");

    mgn_mem_release_all(&pool);

    return 0;
}