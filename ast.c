//
// Created by Yuchi Chen on 2017/8/13.
//

#include "ast.h"
#include "proc.la.l.c"

static struct src_stack *curbs = NULL;

int create_ast(mgn_memory_pool* pool, char* content, uint content_size)
{
    struct src_stack *bs = plat_mem_allocate(sizeof(*bs));
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
    //if(curbs) curbs->lineno = yylineno;
    bs->prev = curbs;

    /* set up current entry */
    //bs->bs = yy_scan_bytes(bs->src_buffer, bs->src_size);
    bs->bs = yy_scan_bytes(content, content_size);
    yy_switch_to_buffer(bs->bs);
    curbs = bs;
    //yylineno = 1;

    yyparse();

    return 0;
}