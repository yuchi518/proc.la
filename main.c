#include "ast.h"

int main() {
    //printf("Hello, World!\n");
    char* content;
    uint content_size;
    int res;
    mgn_memory_pool pool = null;

    res = plat_io_get_resource("first.la", (void**)&content, &content_size);

    if (res == 0)
    {
        //printf("=====Source =====\n");
        //printf("%s\n", content);
        //printf("=================\n");
        //fflush(stdout);
        res = create_ast(&pool, content, content_size);

        free(content);
    }

    mgn_mem_release_all(&pool);

    return 0;
}