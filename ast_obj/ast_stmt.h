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
    release_mmobj(obj->name);
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
    release_mmobj(obj->list);
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

/// ===== Statement - Block =====

typedef struct AstBlockStatement {
    bool closed;
    MMList stmts;               // not all AstStatement objs,
}*AstBlockStatement;

plat_inline AstBlockStatement initAstBlockStatement(AstBlockStatement obj, Unpacker unpkr) {
    obj->closed = false;
    obj->stmts = allocMMList(pool_of_mmobj(obj));
    if (obj->stmts == null) return null;
    return obj;
}

plat_inline void destroyAstBlockStatement(AstBlockStatement obj) {
    release_mmobj(obj->stmts);
}

plat_inline void packAstBlockStatement(AstBlockStatement obj, Packer pkr) {

}

MMSubObject(AST_BLOCK_STATEMENT, AstBlockStatement, AstStatement, initAstBlockStatement, destroyAstBlockStatement, packAstBlockStatement);

plat_inline void addStmtToBlock(AstBlockStatement block, AstStatement stmt) {
    pushMMListItem(block->stmts, toMMObject(stmt));
}

plat_inline void concatBlock(AstBlockStatement block, AstBlockStatement a_list) {
    concatMMList(block->stmts, a_list->stmts);
}

plat_inline void insertStmtToBlockAt(AstBlockStatement block, AstStatement stmt, uint idx) {
    insertMMListItem(block->stmts, toMMObject(stmt), idx);
}

plat_inline uint sizeOfBlock(AstBlockStatement block) {
    return sizeOfMMList(block->stmts);
}

plat_inline AstStatement getStmtFromBlockAt(AstBlockStatement block, uint idx) {
    return toAstStatement(getMMListItem(block->stmts, idx));
}

plat_inline bool isBlockClosed(AstBlockStatement block) {
    return block->closed;
}

plat_inline void closeBlock(AstBlockStatement block) {
    block->closed = true;
}


/// ===== Statement - Case =====

typedef struct AstCaseStatement {
    AstExpression check;            // if null, means 'default' case.
}*AstCaseStatement;

plat_inline AstCaseStatement initAstCaseStatement(AstCaseStatement obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstCaseStatement(AstCaseStatement obj) {
    release_mmobj(obj->check);
}

plat_inline void packAstCaseStatement(AstCaseStatement obj, Packer pkr) {

}

MMSubObject(AST_CASE_STATEMENT, AstCaseStatement, AstStatement, initAstCaseStatement, destroyAstCaseStatement, packAstCaseStatement);

plat_inline AstCaseStatement allocAstCaseStatementWithCheck(mgn_memory_pool* pool, AstExpression check) {
    AstCaseStatement obj = allocAstCaseStatement(pool);
    if (obj) {
        obj->check = retain_mmobj(check);
    }
    return obj;
}


/// ===== Statement - Switch =====

typedef struct AstSwitchStatement {
    AstExpression eval;
    AstStatement stmt;
}*AstSwitchStatement;

plat_inline AstSwitchStatement initAstSwitchStatement(AstSwitchStatement obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstSwitchStatement(AstSwitchStatement obj) {
    release_mmobj(obj->eval);
    release_mmobj(obj->stmt);
}

plat_inline void packAstSwitchStatement(AstSwitchStatement obj, Packer pkr) {

}

MMSubObject(AST_SWITCH_STATEMENT, AstSwitchStatement, AstStatement, initAstSwitchStatement, destroyAstSwitchStatement, packAstSwitchStatement);

plat_inline AstSwitchStatement allocAstSwitchStatementWithEvalAndStmt(mgn_memory_pool* pool, AstExpression eval, AstStatement stmt) {
    AstSwitchStatement obj = allocAstSwitchStatement(pool);
    if (obj) {
        obj->eval = retain_mmobj(eval);
        obj->stmt = retain_mmobj(stmt);
    }
    return obj;
}

/// ===== Statement - Address =====

typedef struct AstStmtAddress {
    AstIdentifier label;
}*AstStmtAddress;

plat_inline AstStmtAddress initAstStmtAddress(AstStmtAddress obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstStmtAddress(AstStmtAddress obj) {
    release_mmobj(obj->label);
}

plat_inline void packAstStmtAddress(AstStmtAddress obj, Packer pkr) {

}

MMSubObject(AST_STATEMENT_ADDRESS, AstStmtAddress, AstStatement, initAstStmtAddress, destroyAstStmtAddress, packAstStmtAddress);

plat_inline AstStmtAddress allocAstStmtAddressWithLabel(mgn_memory_pool* pool, AstIdentifier label) {
    AstStmtAddress obj = allocAstStmtAddress(pool);
    if (obj) {
        obj->label = retain_mmobj(label);
    }
    return obj;
}



#endif //PROC_LA_AST_STMT_H
