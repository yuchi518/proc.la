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

plat_inline AstVariableCombination initAstVariableCombination(AstVariableCombination obj, Unpacker unpkr) {
    toAstVariable(obj)->type = ast_type_var;        // base type
    return obj;
}

plat_inline void destroyAstVariableCombination(AstVariableCombination obj) {

}

plat_inline void packAstVariableCombination(AstVariableCombination obj, Packer pkr) {

}

MMSubObject(AstVariableCombination, AstVariable, initAstVariableCombination, destroyAstVariableCombination, packAstVariableCombination);


/// TODO - implement combination type.


/// ===== Domain Name  =====

typedef struct AstDomainName {
    MMString name;
}*AstDomainName;

plat_inline AstDomainName initAstDomainName(AstDomainName obj, Unpacker unpkr) {
    toAstVariable(obj)->type = ast_type_la;
    return obj;
}

plat_inline void destroyAstDomainName(AstDomainName obj) {
    release_mmobj(obj->name);
}

plat_inline void packAstDomainName(AstDomainName obj, Packer pkr) {

}

MMSubObject(AstDomainName, AstVariable, initAstDomainName, destroyAstDomainName, packAstDomainName);

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
}*AstALa;

plat_inline AstALa initAstVariableLa(AstALa obj, Unpacker unpkr) {
    toAstVariable(obj)->type = ast_type_la;
    return obj;
}

plat_inline void destroyAstVariableLa(AstALa obj) {
    release_mmobj(obj->input);
    release_mmobj(obj->body);
    release_mmobj(obj->output);
}

plat_inline void packAstVariableLa(AstALa obj, Packer pkr) {

}

MMSubObject(AstALa, AstVariable, initAstVariableLa, destroyAstVariableLa, packAstVariableLa);

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
