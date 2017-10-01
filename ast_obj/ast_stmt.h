//
// Created by Yuchi Chen on 2017/9/16.
//

#ifndef PROC_LA_AST_STMT_H
#define PROC_LA_AST_STMT_H

#include "ast_type.h"
#include "ast_variable.h"
#include "ast_ctrl.h"


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
    if (obj->identifier_type) {
        release_mmobj(obj->identifier_type);
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
        obj->identifier_type = retain_mmobj(type);
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


/// ===== Statement - La body =====

typedef struct AstBlockStatement {
    MMList stmts;               // not all AstStatement objs,
}*AstBlockStatement;

plat_inline AstBlockStatement initAstBlockStatement(AstBlockStatement obj, Unpacker unpkr) {
    obj->stmts = allocMMList(pool_of_mmobj(obj));
    if (obj->stmts == null) return null;
    return obj;
}

plat_inline void destroyAstBlockStatement(AstBlockStatement obj) {
    if (obj->stmts) {
        release_mmobj(obj->stmts);
    }
}

plat_inline void packAstBlockStatement(AstBlockStatement obj, Packer pkr) {

}

MMSubObject(AST_LA_BODY_DECLARATION, AstBlockStatement, AstStatement, initAstBlockStatement, destroyAstBlockStatement, packAstBlockStatement);

plat_inline void addStmtToBlock(AstBlockStatement block, AstNode stmt) {
    pushMMListItem(block->stmts, toMMObject(stmt));
}

plat_inline void concatBlock(AstBlockStatement block, AstBlockStatement a_list) {
    concatMMList(block->stmts, a_list->stmts);
}

plat_inline void insertStmtToBlockAt(AstBlockStatement block, AstNode stmt, uint idx) {
    insertMMListItem(block->stmts, toMMObject(stmt), idx);
}

plat_inline uint sizeOfBlock(AstBlockStatement block) {
    return sizeOfMMList(block->stmts);
}

plat_inline AstNode getStmtFromBlockAt(AstBlockStatement block, uint idx) {
    return toAstNode(getMMListItem(block->stmts, idx));
}


#endif //PROC_LA_AST_STMT_H
