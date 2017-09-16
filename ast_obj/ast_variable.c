//
// Created by Yuchi Chen on 2017/9/16.
//

#include <stdarg.h>
#include "ast_variable.h"

AstVariableList allocAstVariableListWithItems(mgn_memory_pool* pool, AstVariable first_item, ...) {
    AstVariableList obj = allocAstVariableList(pool);
    if (obj) {
        if (first_item) {
            AstVariable var = toAstVariable(first_item);
            if (var) pushMMListItem(obj->list, toMMObject(var));
            else {
                plat_io_printf_err("Not an abstract variable, %p\n", first_item);
            }

            va_list valist;
            va_start(valist, first_item);

            while (1) {
                void* item = va_arg(valist, void*);
                if (item == null) break;
                var = toAstVariable(item);
                if (var) pushMMListItem(obj->list, toMMObject(var));
                else {
                    plat_io_printf_err("Not an abstract variable, %p\n", item);
                }
            }

            va_end(valist);
        }
    }
    return obj;
}

static void __addAstVariableKeyValue(AstVariableMap obj, MMString first_key, va_list valist)
{
    void* item = va_arg(valist, void*);
    if (item == null) {
        plat_io_printf_err("Value is null, key=%s\n", first_key->value);
    } else {
        AstVariable var = toAstVariable(item);
        if (var == null) {
            plat_io_printf_err("Value is not an AstVariable, %p, key=%s\n", item, first_key->value);
        } else {
            addMMMapItem(obj->map, toMMPrimary(first_key), toMMObject(var));

            while(1) {
                item = va_arg(valist, void*);
                if (item == null) break;
                MMString key = toMMString(item);
                if (key == null) {
                    plat_io_printf_err("Key is not a MMString object, %p\n", item);
                    break;
                }

                item = va_arg(valist, void*);
                if (item == null) {
                    plat_io_printf_err("Value is null, key=%s\n", key->value);
                    break;
                }
                var = toAstVariable(item);
                if (var == null) {
                    plat_io_printf_err("Value is not an AstVariable, %p, key=%s\n", item, key->value);
                } else {
                    addMMMapItem(obj->map, toMMPrimary(key), toMMObject(var));
                }
            }
        }
    }
}

AstVariableMap allocAstVariableMapWithKeyValue(mgn_memory_pool* pool, MMString first_key, ...) {
    AstVariableMap obj = allocAstVariableMap(pool);
    if (obj) {
        if (first_key) {
            va_list valist;
            va_start(valist, first_key);

            __addAstVariableKeyValue(obj, first_key, valist);

            va_end(valist);
        }
    }
    return obj;
}

void addAstVariableKeyValue(AstVariableMap obj, MMString first_key, .../* AstVariable first_value, and more keys and values */)
{
    if (first_key) {
        va_list valist;
        va_start(valist, first_key);

        __addAstVariableKeyValue(obj, first_key, valist);

        va_end(valist);
    }
}