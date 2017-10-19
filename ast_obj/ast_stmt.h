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

MMSubObject(AstPackage, AstStatement , initAstPackage, destroyAstPackage, packAstPackage);

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

MMSubObject(AstTypeList, AstStatement, initAstTypeList, destroyAstTypeList, packAstTypeList);

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

typedef struct AstBlockStmt {
    bool closed;
    MMList stmts;               // not all AstStatement objs,
}*AstBlockStmt;

plat_inline AstBlockStmt initAstBlockStmt(AstBlockStmt obj, Unpacker unpkr) {
    obj->closed = false;
    obj->stmts = allocMMList(pool_of_mmobj(obj));
    if (obj->stmts == null) return null;
    return obj;
}

plat_inline void destroyAstBlockStmt(AstBlockStmt obj) {
    release_mmobj(obj->stmts);
}

plat_inline void packAstBlockStmt(AstBlockStmt obj, Packer pkr) {

}

MMSubObject(AstBlockStmt, AstStatement, initAstBlockStmt, destroyAstBlockStmt, packAstBlockStmt);

plat_inline void addStmtToBlock(AstBlockStmt block, AstStatement stmt) {
    pushMMListItem(block->stmts, toMMObject(stmt));
}

plat_inline void concatBlock(AstBlockStmt block, AstBlockStmt a_list) {
    concatMMList(block->stmts, a_list->stmts);
}

plat_inline void insertStmtToBlockAt(AstBlockStmt block, AstStatement stmt, uint idx) {
    insertMMListItem(block->stmts, toMMObject(stmt), idx);
}

plat_inline uint sizeOfBlock(AstBlockStmt block) {
    return sizeOfMMList(block->stmts);
}

plat_inline AstStatement getStmtFromBlockAt(AstBlockStmt block, uint idx) {
    return toAstStatement(getMMListItem(block->stmts, idx));
}

plat_inline bool isBlockClosed(AstBlockStmt block) {
    return block->closed;
}

plat_inline void closeBlock(AstBlockStmt block) {
    block->closed = true;
}


/// ===== Statement - Case =====

typedef struct AstCaseStmt {
    AstExpression check;            // if null, means 'default' case.
}*AstCaseStmt;

plat_inline AstCaseStmt initAstCaseStmt(AstCaseStmt obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstCaseStmt(AstCaseStmt obj) {
    release_mmobj(obj->check);
}

plat_inline void packAstCaseStmt(AstCaseStmt obj, Packer pkr) {

}

MMSubObject(AstCaseStmt, AstStatement, initAstCaseStmt, destroyAstCaseStmt, packAstCaseStmt);

plat_inline AstCaseStmt allocAstCaseStmtWithCheck(mgn_memory_pool* pool, AstExpression check) {
    AstCaseStmt obj = allocAstCaseStmt(pool);
    if (obj) {
        obj->check = retain_mmobj(check);
    }
    return obj;
}


/// ===== Statement - Switch =====

typedef struct AstSwitchStmt {
    AstExpression eval;
    AstStatement stmt;
}*AstSwitchStmt;

plat_inline AstSwitchStmt initAstSwitchStmt(AstSwitchStmt obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstSwitchStmt(AstSwitchStmt obj) {
    release_mmobj(obj->eval);
    release_mmobj(obj->stmt);
}

plat_inline void packAstSwitchStmt(AstSwitchStmt obj, Packer pkr) {

}

MMSubObject(AstSwitchStmt, AstStatement, initAstSwitchStmt, destroyAstSwitchStmt, packAstSwitchStmt);

plat_inline AstSwitchStmt allocAstSwitchStmtWithEvalAndStmt(mgn_memory_pool* pool, AstExpression eval, AstStatement stmt) {
    AstSwitchStmt obj = allocAstSwitchStmt(pool);
    if (obj) {
        obj->eval = retain_mmobj(eval);
        obj->stmt = retain_mmobj(stmt);
    }
    return obj;
}

/// ===== Statement - If, Else =====

typedef struct AstIfStmt {
    AstExpression eval;
    AstStatement true_stmt;
    AstStatement false_stmt;
}*AstIfStmt;

plat_inline AstIfStmt initAstIfStmt(AstIfStmt obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstIfStmt(AstIfStmt obj) {
    release_mmobj(obj->eval);
    release_mmobj(obj->true_stmt);
    release_mmobj(obj->false_stmt);
}

plat_inline void packAstIfStmt(AstIfStmt obj, Packer pkr) {

}

MMSubObject(AstIfStmt, AstStatement, initAstIfStmt, destroyAstIfStmt, packAstIfStmt);

plat_inline AstIfStmt allocAstIfStmtWithEvalAndStmts(mgn_memory_pool* pool, AstExpression eval, AstStatement true_stmt, AstStatement false_stmt) {
    AstIfStmt obj = allocAstIfStmt(pool);
    if (obj) {
        obj->eval = retain_mmobj(eval);
        obj->true_stmt = retain_mmobj(true_stmt);
        obj->false_stmt = retain_mmobj(false_stmt);
    }
    return obj;
}


/// ===== Statement - Loop =====

typedef struct AstLoopStmt {
    AstStatement stmt;
}*AstLoopStmt;

plat_inline AstLoopStmt initAstLoopStmt(AstLoopStmt obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstLoopStmt(AstLoopStmt obj) {
    release_mmobj(obj->stmt);
}

plat_inline void packAstLoopStmt(AstLoopStmt obj, Packer pkr) {

}

MMSubObject(AstLoopStmt, AstStatement, initAstLoopStmt, destroyAstLoopStmt, packAstLoopStmt);

plat_inline AstLoopStmt allocAstLoopStmtWithStmt(mgn_memory_pool* pool, AstStatement stmt) {
    AstLoopStmt obj = allocAstLoopStmt(pool);
    if (obj) {
        obj->stmt = retain_mmobj(stmt);
    }
    return obj;
}


/// ===== Statement - Each =====

typedef struct AstEachStmt {
    AstExpression eval;
    AstStatement stmt;
}*AstEachStmt;

plat_inline AstEachStmt initAstEachStmt(AstEachStmt obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstEachStmt(AstEachStmt obj) {
    release_mmobj(obj->eval);
    release_mmobj(obj->stmt);
}

plat_inline void packAstEachStmt(AstEachStmt obj, Packer pkr) {

}

MMSubObject(AstEachStmt, AstStatement, initAstEachStmt, destroyAstEachStmt, packAstEachStmt);

plat_inline AstEachStmt allocAstEachStmtWithEvalAndStmt(mgn_memory_pool* pool, AstExpression eval, AstStatement stmt) {
    AstEachStmt obj = allocAstEachStmt(pool);
    if (obj) {
        obj->eval = retain_mmobj(eval);
        obj->stmt = retain_mmobj(stmt);
    }
    return obj;
}


/// ===== Statement - Jump =====

typedef struct AstJumpStmt {
    ast_jump_type type;
    AstIdentifier identifier;
}*AstJumpStmt;

plat_inline AstJumpStmt initAstJumpStmt(AstJumpStmt obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstJumpStmt(AstJumpStmt obj) {
    release_mmobj(obj->identifier);
}

plat_inline void packAstJumpStmt(AstJumpStmt obj, Packer pkr) {

}

MMSubObject(AstJumpStmt, AstStatement, initAstJumpStmt, destroyAstJumpStmt, packAstJumpStmt);

plat_inline AstJumpStmt allocAstJumpStmtWithTypeAndIdentifier(mgn_memory_pool* pool, ast_jump_type type, AstIdentifier identifier) {
    AstJumpStmt obj = allocAstJumpStmt(pool);
    if (obj) {
        obj->type = type;
        obj->identifier = retain_mmobj(identifier);
    }
    return obj;
}

/// ===== Statement - Anchor =====

typedef struct AstAnchorStmt {
    AstIdentifier label;
}*AstAnchorStmt;

plat_inline AstAnchorStmt initAstAnchorStmt(AstAnchorStmt obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstAnchorStmt(AstAnchorStmt obj) {
    release_mmobj(obj->label);
}

plat_inline void packAstAnchorStmt(AstAnchorStmt obj, Packer pkr) {

}

MMSubObject(AstAnchorStmt, AstStatement, initAstAnchorStmt, destroyAstAnchorStmt, packAstAnchorStmt);

plat_inline AstAnchorStmt allocAstAnchorStmtWithLabel(mgn_memory_pool* pool, AstIdentifier label) {
    AstAnchorStmt obj = allocAstAnchorStmt(pool);
    if (obj) {
        obj->label = retain_mmobj(label);
    }
    return obj;
}

/// ===== Statement - Sync =====

typedef struct AstSyncStmt {
    AstIdentifier identifier;
}*AstSyncStmt;

plat_inline AstSyncStmt initAstSync(AstSyncStmt obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstSync(AstSyncStmt obj) {
    release_mmobj(obj->identifier);
}

plat_inline void packAstSync(AstSyncStmt obj, Packer pkr) {

}

MMSubObject(AstSyncStmt, AstStatement, initAstSync, destroyAstSync, packAstSync);

plat_inline AstSyncStmt allocAstSyncStmtWithIdentifier(mgn_memory_pool* pool, AstIdentifier identifier) {
    AstSyncStmt obj = allocAstSyncStmt(pool);
    if (obj) {
        obj->identifier = retain_mmobj(identifier);
    }
    return obj;
}


#endif //PROC_LA_AST_STMT_H
