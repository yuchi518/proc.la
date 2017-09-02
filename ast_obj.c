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
    }

    obj = getMMMapItemValue(map, toMMPrimary(hi6));
    if (oid_of_mmobj(obj) == MMOBJ_DOUBLE) {
        plat_io_printf_std("Got it!! (%f)\n", toMMDouble(obj)->value);
    }

    release_mmobj(map);

    map = allocMMMap(&pool);

    MMString hi7 = autorelease_mmobj(allocMMStringWithCString(&pool, "hi7"));
    MMLong v7 = autorelease_mmobj(allocMMLong(&pool));

    addMMMapItem(map, toMMPrimary(v7), toMMObject(hi7));

    obj = getMMMapItemValue(map, toMMPrimary(v7));
    if (oid_of_mmobj(obj) == MMOBJ_STRING) {
        plat_io_printf_std("Got it!! (%s)\n", toMMString(obj)->value);
    }

    release_mmobj(map);

    plat_io_printf_std("===== unit_test_mmobj - END =====\n");
}