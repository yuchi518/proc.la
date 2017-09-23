//
// Created by Yuchi Chen on 2017/9/16.
//

#ifndef PROC_LA_AST_STMT_H
#define PROC_LA_AST_STMT_H

#include "ast_type.h"
#include "ast_variable.h"
#include "ast_ctrl.h"

/// ===== Statement =====

typedef struct AstStatement {

}*AstStatement;

plat_inline AstStatement initAstStatement(AstStatement obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstStatement(AstStatement obj) {

}

plat_inline void packAstStatement(AstStatement obj, Packer pkr) {

}

MMSubObject(AST_STATEMENT, AstStatement, AstNode , initAstStatement, destroyAstStatement, packAstStatement);

plat_inline AstStatement allocAstStatementWith(mgn_memory_pool* pool, ...) {
    AstStatement obj = allocAstStatement(pool);
    if (obj) {
    }
    return obj;
}


/// ===== Stmt - Package =====

typedef struct AstPackage {
    MMString name;
}*AstPackage;

plat_inline AstPackage initAstPackage(AstPackage obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstPackage(AstPackage obj) {
    if (obj->name) {
        release_mmobj(obj->name);
        obj->name = null;
    }
}

plat_inline void packAstPackage(AstPackage obj, Packer pkr) {

}

MMSubObject(AST_PACKAGE, AstPackage, AstStatement , initAstPackage, destroyAstPackage, packAstPackage);

plat_inline AstPackage allocAstPackageWithName(mgn_memory_pool* pool, MMString name) {
    if (name == null) {
        plat_io_printf_err("Package should have a name\n");
        return null;
    }

    AstPackage obj = allocAstPackage(pool);
    if (obj) {
        obj->name = retain_mmobj(name);
    }
    return obj;
}

plat_inline AstPackage allocAstPackageWithCStringName(mgn_memory_pool* pool, char* name) {
    if (name == null) {
        plat_io_printf_err("Package should have a name\n");
        return null;
    }

    return allocAstPackageWithName(pool, autorelease_mmobj(allocMMStringWithCString(pool, name)));
}


/// ===== Statement - Type Declaration List =====

typedef struct AstTypeList {
    MMList list;
}*AstTypeList;

plat_inline AstTypeList initAstTypeList(AstTypeList obj, Unpacker unpkr) {
    obj->list = allocMMList(pool_of_mmobj(obj));
    if (obj->list == null) return null;
    return obj;
}

plat_inline void destroyAstTypeList(AstTypeList obj) {
    if (obj->list) {
        release_mmobj(obj->list);
    }
}

plat_inline void packAstTypeList(AstTypeList obj, Packer pkr) {

}

MMSubObject(AST_TYPE_LIST_DECLARATION, AstTypeList, AstStatement, initAstTypeList, destroyAstTypeList, packAstTypeList);

plat_inline void addTypeToTypeList(AstTypeList list, AstType type) {
    pushMMListItem(list->list, toMMObject(type));
}

plat_inline void concatTypeList(AstTypeList dest_list, AstTypeList a_list) {
    concatMMList(dest_list->list, a_list->list);
}

plat_inline void insertTypeToTypeListAt(AstTypeList list, AstType type, uint idx) {
    insertMMListItem(list->list, toMMObject(type), idx);
}

plat_inline uint sizeOfTypeList(AstTypeList typeList) {
    return sizeOfMMList(typeList->list);
}

plat_inline AstType getTypeFromTypeListAt(AstTypeList typeList, uint idx) {
    return toAstType(getMMListItem(typeList->list, idx));
}

/// ===== Statement - Var Declaration =====
/**
 * Includes two parts:
 *   variable identifier
 *   variable type
 */
typedef struct AstVarDeclare {
    AstIdentifier identifier;
    AstType identifier_type;
}*AstVarDeclare;

plat_inline AstVarDeclare initAstVarDeclare(AstVarDeclare obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstVarDeclare(AstVarDeclare obj) {
    if (obj->identifier) {
        release_mmobj(obj->identifier);
    }
}

plat_inline void packAstVarDeclare(AstVarDeclare obj, Packer pkr) {

}

MMSubObject(AST_VAR_DECLARE, AstVarDeclare, AstStatement, initAstVarDeclare, destroyAstVarDeclare, packAstVarDeclare);


plat_inline AstVarDeclare allocAstVarDeclareWithIdentifier(mgn_memory_pool* pool, AstIdentifier identifier, AstType type) {
    if (identifier == null) {
        plat_io_printf_err("Identifier can't be null\n");
        return null;
    }
    AstVarDeclare obj = allocAstVarDeclare(pool);
    if (obj) {
        obj->identifier = retain_mmobj(identifier);
        obj->identifier_type = type;
    }
    return obj;
}


/// ===== Statement - Var Declaration List =====

typedef struct AstVarDeclareList {
    MMList list;
}*AstVarDeclareList;

plat_inline AstVarDeclareList initAstVarDeclareList(AstVarDeclareList obj, Unpacker unpkr) {
    obj->list = allocMMList(pool_of_mmobj(obj));
    if (obj->list == null) return null;
    return obj;
}

plat_inline void destroyAstVarDeclareList(AstVarDeclareList obj) {
    if (obj->list) {
        release_mmobj(obj->list);
    }
}

plat_inline void packAstVarDeclareList(AstVarDeclareList obj, Packer pkr) {

}

MMSubObject(AST_VAR_LIST_DECLARATION, AstVarDeclareList, AstStatement, initAstVarDeclareList, destroyAstVarDeclareList, packAstVarDeclareList);

plat_inline void addVarDeclareToVarDeclareList(AstVarDeclareList list, AstVarDeclare declare) {
    pushMMListItem(list->list, toMMObject(declare));
}

plat_inline void concatVarDeclareList(AstVarDeclareList dest_list, AstVarDeclareList a_list) {
    concatMMList(dest_list->list, a_list->list);
}

plat_inline void insertVarDeclareToVarDeclareListAt(AstVarDeclareList list, AstVarDeclare declare, uint idx) {
    insertMMListItem(list->list, toMMObject(declare), idx);
}

plat_inline uint sizeOfVarDeclareListAt(AstVarDeclareList varDeclareList) {
    return sizeOfMMList(varDeclareList->list);
}

plat_inline AstVarDeclare getVarDeclareFromAstVarDeclareListAt(AstVarDeclareList varDeclareList, uint idx) {
    return toAstVarDeclare(getMMListItem(varDeclareList->list, idx));
}

/// ===== Statement - Var Instance =====
/**
 * Includes two parts:
 *   var declare
 *   variable
 */

typedef struct AstVarInstance {
    AstVarDeclare declare;
    AstVariable inst;
}*AstVarInstance;

plat_inline AstVarInstance initAstVarInstant(AstVarInstance obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstVarInstant(AstVarInstance obj) {
    if (obj->declare) {
        release_mmobj(obj->declare);
    }
    if (obj->inst) {
        release_mmobj(obj->inst);
    }
}

plat_inline void packAstVarInstant(AstVarInstance obj, Packer pkr) {

}

MMSubObject(AST_VAR_INSTANCE, AstVarInstance, AstStatement, initAstVarInstant, destroyAstVarInstant, packAstVarInstant);

plat_inline AstVarInstance allocAstVarInstantWithDeclareAndInstance(mgn_memory_pool* pool, AstVarDeclare declare, AstVariable instance) {
    if (declare == null) {
        plat_io_printf_err("Declare can not be null\n");
        return null;
    }
    if (instance == null) {
        plat_io_printf_err("Instance can't be null\n");
        return null;
    }

    AstVarInstance obj = allocAstVarInstance(pool);
    if (obj) {
        obj->declare = retain_mmobj(declare);
        obj->inst = retain_mmobj(instance);
    }
    return obj;
}


/// ===== Statement - La body =====

typedef struct AstLaBody {
    MMList stmts;               // not all AstStatement objs,
}*AstLaBody;

plat_inline AstLaBody initAstLaBody(AstLaBody obj, Unpacker unpkr) {
    obj->stmts = allocMMList(pool_of_mmobj(obj));
    if (obj->stmts == null) return null;
    return obj;
}

plat_inline void destroyAstLaBody(AstLaBody obj) {
    if (obj->stmts) {
        release_mmobj(obj->stmts);
    }
}

plat_inline void packAstLaBody(AstLaBody obj, Packer pkr) {

}

MMSubObject(AST_LA_BODY_DECLARATION, AstLaBody, AstStatement, initAstLaBody, destroyAstLaBody, packAstLaBody);

plat_inline void addStmtToLaBody(AstLaBody obj, AstNode stmt) {
    pushMMListItem(obj->stmts, toMMObject(stmt));
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
    AstVarDeclareList input;
    AstLaBody body;
    AstTypeList output;
}*AstALa;

plat_inline AstALa initAstVariableLa(AstALa obj, Unpacker unpkr) {
    toAstVariable(obj)->type = ast_type_la;
    return obj;
}

plat_inline void destroyAstVariableLa(AstALa obj) {
    if (obj->input) {
        release_mmobj(obj->input);
    }
    if (obj->body) {
        release_mmobj(obj->body);
    }
    if (obj->output) {
        release_mmobj(obj->output);
    }
}

plat_inline void packAstVariableLa(AstALa obj, Packer pkr) {

}

MMSubObject(AST_A_LA, AstALa, AstVariable, initAstVariableLa, destroyAstVariableLa, packAstVariableLa);

plat_inline AstALa allocAstALaWithImpl(mgn_memory_pool* pool, AstVarDeclareList input, AstLaBody body, AstTypeList output) {
    AstALa obj = allocAstALa(pool);
    if (obj) {
        obj->input = retain_mmobj(input);
        obj->body = retain_mmobj(body);
        obj->output = retain_mmobj(output);
    }
    return obj;
}


#endif //PROC_LA_AST_STMT_H
