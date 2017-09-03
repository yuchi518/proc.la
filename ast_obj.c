//
// Created by Yuchi Chen on 2017/8/27.
//

#include "ast_obj.h"

void unit_test_mmobj(void)
{
    plat_io_printf_std("===== unit_test_mmobj - START =====\n");

    mgn_memory_pool pool = null;
    MMSon son = allocMMSon(&pool);
    MMChild child = toMMChild(son);
    MMRoot root = toMMRoot(child);

    plat_io_printf_std("Son's name = %s\n", name_of_mmobj(son));
    plat_io_printf_std("Child's name = %s\n", name_of_mmobj(child));
    plat_io_printf_std("Root's name = %s\n", name_of_mmobj(root));

    release_mmobj(child);
    if (mgn_mem_count_of_mem(&pool) != 0)
    {
        plat_io_printf_err("Memory leak? (%zu)\n", mgn_mem_count_of_mem(&pool));
    }

    MMString hi5 = autorelease_mmobj(allocMMStringWithCString(&pool, "hi5"));
    MMInt v5 = autorelease_mmobj(allocMMInt(&pool));
    v5->value = 5;

    MMString hi6 = autorelease_mmobj(allocMMStringWithCString(&pool, "hi6"));
    MMDouble v6 = autorelease_mmobj(allocMMDouble(&pool));
    v6->value = 6.0;

    MMMap map = allocMMMap(&pool);

    addMMMapItem(map, toMMPrimary(hi5), toMMObject(v5));
    addMMMapItem(map, toMMPrimary(hi6), toMMObject(v6));

    MMObject obj = getMMMapItemValue(map, toMMPrimary(hi5));
    if (oid_of_mmobj(obj) == MMOBJ_INT) {
        plat_io_printf_std("Got it!! (%d)\n", toMMInt(obj)->value);
    } else {
        plat_io_printf_err("What is this?(%u)\n", oid_of_mmobj(obj));
    }

    obj = getMMMapItemValue(map, toMMPrimary(hi6));
    if (oid_of_mmobj(obj) == MMOBJ_DOUBLE) {
        plat_io_printf_std("Got it!! (%f)\n", toMMDouble(obj)->value);
    } else {
        plat_io_printf_err("What is this?(%u)\n", oid_of_mmobj(obj));
    }

    release_mmobj(map);
    if (mgn_mem_count_of_mem(&pool) != 0)
    {
        plat_io_printf_err("Memory leak? (%zu)\n", mgn_mem_count_of_mem(&pool));
    }

    map = allocMMMap(&pool);

    MMString hi7 = autorelease_mmobj(allocMMStringWithCString(&pool, "hi7"));
    MMLong v7 = autorelease_mmobj(allocMMLong(&pool));
    v7->value = 7;

    MMString hi8 = autorelease_mmobj(allocMMStringWithCString(&pool, "hi8"));
    MMLong v8 = autorelease_mmobj(allocMMLong(&pool));
    v8->value = 8;

    void* hash_key = null;
    uint hash_key_len = 0;
    hash_of_mmobj(toMMPrimary(v7), &hash_key, &hash_key_len);

    addMMMapItem(map, toMMPrimary(v7), toMMObject(hi7));
    addMMMapItem(map, toMMPrimary(v8), toMMObject(hi8));

    obj = getMMMapItemValue(map, toMMPrimary(v7));
    if (oid_of_mmobj(obj) == MMOBJ_STRING) {
        plat_io_printf_std("Got it!! (%s)\n", toMMString(obj)->value);
    }

    release_mmobj(map);
    if (mgn_mem_count_of_mem(&pool) != 0)
    {
        plat_io_printf_err("Memory leak? (%zu)\n", mgn_mem_count_of_mem(&pool));
    }

    MMList list = allocMMList(&pool);
    MMString hi9 = autorelease_mmobj(allocMMStringWithCString(&pool, "hi9"));
    MMFloat v9 = autorelease_mmobj(allocMMFloat(&pool));
    v9->value = 9;

    pushMMListItem(list, toMMObject(hi9));
    pushMMListItem(list, toMMObject(v9));
    release_mmobj(list);
    if (mgn_mem_count_of_mem(&pool) != 0)
    {
        plat_io_printf_err("Memory leak? (%zu)\n", mgn_mem_count_of_mem(&pool));
    }


    plat_io_printf_std("===== unit_test_mmobj - END =====\n");
}