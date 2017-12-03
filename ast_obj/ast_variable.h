//
// Created by Yuchi Chen on 2017/9/16.
//

#ifndef PROC_LA_AST_VARIABLE_H
#define PROC_LA_AST_VARIABLE_H

#include "ast_expr.h"
#include "ast_container.h"


/// ===== Variable - Combination  =====

typedef struct AstVariableCombination {
    int32 combined_type;
}*AstVariableCombination;

plat_inline int compareForAstVariableCombination(void*, void*);
plat_inline AstVariableCombination initAstVariableCombination(AstVariableCombination obj, Unpacker unpkr) {
    set_compare_for_mmobj(obj, compareForAstVariableCombination);
    if (is_unpacker_v1(unpkr)) {
        obj->combined_type = (int32)unpack_varint(0, unpkr);
    } else {
        toAstVariable(obj)->type = ast_type_var;        // base type
    }
    return obj;
}

plat_inline void destroyAstVariableCombination(AstVariableCombination obj) {

}

plat_inline void packAstVariableCombination(AstVariableCombination obj, Packer pkr) {
    pack_varint(0, obj->combined_type, pkr);
}

MMSubObject(AstVariableCombination, AstVariable, initAstVariableCombination, destroyAstVariableCombination, packAstVariableCombination);

plat_inline int compareForAstVariableCombination(void* this_stru, void* that_stru) {
    AstVariableCombination variableCombination1 = toAstVariableCombination(this_stru);
    AstVariableCombination variableCombination2 = toAstVariableCombination(that_stru);
    int r = compare_parent(variableCombination1, variableCombination2);
    if (r) return r;
    AstVariable variable1 = toAstVariable(variableCombination1);
    AstVariable variable2 = toAstVariable(variableCombination2);
    return variableCombination1->combined_type - variableCombination2->combined_type;
}

/// TODO - implement combination type.


/// ===== Domain Name  =====

typedef struct AstDomainName {
    MMString name;
}*AstDomainName;

plat_inline int compareForAstDomainName(void*, void*);
plat_inline AstDomainName initAstDomainName(AstDomainName obj, Unpacker unpkr) {
    set_compare_for_mmobj(obj, compareForAstDomainName);
    if (is_unpacker_v1(unpkr)) {
        obj->name = toMMString(unpack_mmobj_retained(0, unpkr));
    } else {
        toAstVariable(obj)->type = ast_type_la;
    }
    return obj;
}

plat_inline void destroyAstDomainName(AstDomainName obj) {
    release_mmobj(obj->name);
}

plat_inline void packAstDomainName(AstDomainName obj, Packer pkr) {
    if (is_packer_v1(pkr)) {
        pack_mmobj(0, obj->name, pkr);
    }
}

MMSubObject(AstDomainName, AstVariable, initAstDomainName, destroyAstDomainName, packAstDomainName);

plat_inline int compareForAstDomainName(void* this_stru, void* that_stru) {
    AstDomainName domainName1 = toAstDomainName(this_stru);
    AstDomainName domainName2 = toAstDomainName(that_stru);
    int r = compare_parent(domainName1, domainName2);
    if (r) return r;
    AstVariable variable1 = toAstVariable(domainName1);
    AstVariable variable2 = toAstVariable(domainName2);
    return compare_mmobjs(domainName1->name, domainName2->name);

}

plat_inline AstDomainName allocAstDomainNameWithName(mgn_memory_pool* pool, MMString name) {
    if (name == null) {
        plat_io_printf_err("DomainName should have a name\n");
        return null;
    }

    AstDomainName obj = allocAstDomainName(pool);
    if (obj) {
        obj->name = retain_mmobj(name);
    }
    return obj;
}

plat_inline AstDomainName allocAstDomainNameWithCStringName(mgn_memory_pool* pool, char* name) {
    if (name == null) {
        plat_io_printf_err("DomainName should have a name\n");
        return null;
    }

    return allocAstDomainNameWithName(pool, autorelease_mmobj(allocMMStringWithCString(pool, name)));
}


/// ===== La/Proc =====
/**
 * Includes three parts:
 *   Input, input variable declaration (type + identifier)
 *   Body, statement, expression
 *   Output, output variable declaration (only type)
 */
typedef struct AstALa {
    // input + body + output declarations
    AstContainerExpr input;
    AstBlockStmt body;
    AstTypeList output;
    // == runtime ==
    // TODO: create anchor list
}*AstALa;

plat_inline int compareForAstALa(void*, void*);
plat_inline AstALa initAstVariableLa(AstALa obj, Unpacker unpkr) {
    set_compare_for_mmobj(obj, compareForAstALa);
    if (is_unpacker_v1(unpkr)) {
        obj->input = toAstContainerExpr(unpack_mmobj_retained(0, unpkr));
        obj->output = toAstTypeList(unpack_mmobj_retained(1, unpkr));
        obj->body = toAstBlockStmt(unpack_mmobj_retained(2, unpkr));
    } else {
        toAstVariable(obj)->type = ast_type_la;
    }
    return obj;
}

plat_inline void destroyAstVariableLa(AstALa obj) {
    release_mmobj(obj->input);
    release_mmobj(obj->body);
    release_mmobj(obj->output);
}

plat_inline void packAstVariableLa(AstALa obj, Packer pkr) {
    if (is_packer_v1(pkr)) {
        pack_mmobj(0, obj->input, pkr);
        pack_mmobj(1, obj->output, pkr);
        pack_mmobj(2, obj->body, pkr);
    }
}

MMSubObject(AstALa, AstVariable, initAstVariableLa, destroyAstVariableLa, packAstVariableLa);

plat_inline int compareForAstALa(void* this_stru, void* that_stru) {
    AstALa aLa1 = toAstALa(this_stru);
    AstALa aLa2 = toAstALa(that_stru);
    int r = compare_parent(aLa1, aLa2);
    if (r) return r;
    AstVariable variable1 = toAstVariable(aLa1);
    AstVariable variable2 = toAstVariable(aLa2);
    return FIRST_Of_3RESULTS(compare_mmobjs(aLa1->input, aLa2->input),
                             compare_mmobjs(aLa1->output, aLa2->output),
                             compare_mmobjs(aLa1->body, aLa2->body));
}

plat_inline AstALa allocAstALaWithImpl(mgn_memory_pool* pool, AstContainerExpr input, AstBlockStmt body, AstTypeList output) {
    AstALa obj = allocAstALa(pool);
    if (obj) {
        obj->input = retain_mmobj(input);
        obj->body = retain_mmobj(body);
        obj->output = retain_mmobj(output);
    }
    return obj;
}


#endif //PROC_LA_AST_VARIABLE_H
