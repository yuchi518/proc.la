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

plat_inline int compareForAstPackage(void*, void*);
plat_inline AstPackage initAstPackage(AstPackage obj, Unpacker unpkr) {
    set_compare_for_mmobj(obj, compareForAstPackage);
    if (is_unpacker_v1(unpkr)) {
        obj->name = toMMString(unpack_mmobj_retained(0, unpkr));
    }
    return obj;
}

plat_inline void destroyAstPackage(AstPackage obj) {
    release_mmobj(obj->name);
}

plat_inline void packAstPackage(AstPackage obj, Packer pkr) {
    if (is_packer_v1(pkr)) {
        pack_mmobj(0, obj->name, pkr);
    }
}

MMSubObject(AstPackage, AstStatement, initAstPackage, destroyAstPackage, packAstPackage);

plat_inline int compareForAstPackage(void* this_stru, void* that_stru) {
    AstPackage package1 = toAstPackage(this_stru);
    AstPackage package2 = toAstPackage(that_stru);
    int r = compare_parent(package1, package2);
    if (r) return r;
    return compare_mmobjs(package1->name, package2->name);
}

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

plat_inline int compareForAstTypeList(void*, void*);
plat_inline AstTypeList initAstTypeList(AstTypeList obj, Unpacker unpkr) {
    set_compare_for_mmobj(obj, compareForAstTypeList);
    if (is_unpacker_v1(unpkr)) {
        obj->list = toMMList(unpack_mmobj_retained(0, unpkr));
    } else {
        obj->list = allocMMList(pool_of_mmobj(obj));
        if (obj->list == null) return null;
    }
    return obj;
}

plat_inline void destroyAstTypeList(AstTypeList obj) {
    release_mmobj(obj->list);
}

plat_inline void packAstTypeList(AstTypeList obj, Packer pkr) {
    if (is_packer_v1(pkr)) {
        pack_mmobj(0, obj->list, pkr);
    }
}

MMSubObject(AstTypeList, AstStatement, initAstTypeList, destroyAstTypeList, packAstTypeList);

plat_inline AstTypeList allocEmptyAstTypeList(mgn_memory_pool* pool) {
    AstTypeList typeList = allocAstTypeList(pool);
    if (typeList) {

    }
    return typeList;
}

plat_inline int compareForAstTypeList(void* this_stru, void* that_stru) {
    AstTypeList typeList1 = toAstTypeList(this_stru);
    AstTypeList typeList2 = toAstTypeList(that_stru);
    int r = compare_parent(typeList1, typeList2);
    if (r) return r;
    return compare_mmobjs(typeList1->list, typeList2->list);
}

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

plat_inline int compareForAstBlockStmt(void*, void*);
plat_inline AstBlockStmt initAstBlockStmt(AstBlockStmt obj, Unpacker unpkr) {
    set_compare_for_mmobj(obj, compareForAstBlockStmt);
    if (is_unpacker_v1(unpkr)) {
        obj->closed = unpack_bool(0, unpkr);
        obj->stmts = toMMList(unpack_mmobj_retained(1, unpkr));
    } else {
        obj->closed = false;
        obj->stmts = allocMMList(pool_of_mmobj(obj));
        if (obj->stmts == null) return null;
    }
    return obj;
}

plat_inline void destroyAstBlockStmt(AstBlockStmt obj) {
    release_mmobj(obj->stmts);
}

plat_inline void packAstBlockStmt(AstBlockStmt obj, Packer pkr) {
    if (is_packer_v1(pkr)) {
        pack_bool(0, obj->closed, pkr);
        pack_mmobj(1, obj->stmts, pkr);
    }
}

MMSubObject(AstBlockStmt, AstStatement, initAstBlockStmt, destroyAstBlockStmt, packAstBlockStmt);

plat_inline int compareForAstBlockStmt(void* this_stru, void* that_stru) {
    AstBlockStmt blockStmt1 = toAstBlockStmt(this_stru);
    AstBlockStmt blockStmt2 = toAstBlockStmt(that_stru);
    int r = compare_parent(blockStmt1, blockStmt2);
    if (r) return r;
    return FIRST_Of_2RESULTS((blockStmt1->closed?1:0) - (blockStmt2->closed?1:0),
                             compare_mmobjs(blockStmt1->stmts, blockStmt2->stmts));
}

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

plat_inline int compareForAstCaseStmt(void*, void*);
plat_inline AstCaseStmt initAstCaseStmt(AstCaseStmt obj, Unpacker unpkr) {
    set_compare_for_mmobj(obj, compareForAstCaseStmt);
    if (is_unpacker_v1(unpkr)) {
        obj->check = toAstExpression(unpack_mmobj_retained(0, unpkr));
    }
    return obj;
}

plat_inline void destroyAstCaseStmt(AstCaseStmt obj) {
    release_mmobj(obj->check);
}

plat_inline void packAstCaseStmt(AstCaseStmt obj, Packer pkr) {
    if (is_packer_v1(pkr)) {
        pack_mmobj(0, obj->check, pkr);
    }
}

MMSubObject(AstCaseStmt, AstStatement, initAstCaseStmt, destroyAstCaseStmt, packAstCaseStmt);

plat_inline int compareForAstCaseStmt(void* this_stru, void* that_stru) {
    AstCaseStmt caseStmt1 = toAstCaseStmt(this_stru);
    AstCaseStmt caseStmt2 = toAstCaseStmt(that_stru);
    int r = compare_parent(caseStmt1, caseStmt2);
    if (r) return r;
    return compare_mmobjs(caseStmt1->check, caseStmt2->check);
}

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

plat_inline int compareForAstSwitchStmt(void*, void*);
plat_inline AstSwitchStmt initAstSwitchStmt(AstSwitchStmt obj, Unpacker unpkr) {
    set_compare_for_mmobj(obj, compareForAstSwitchStmt);
    if (is_unpacker_v1(unpkr)) {
        obj->eval = toAstExpression(unpack_mmobj_retained(0, unpkr));
        obj->stmt = toAstStatement(unpack_mmobj_retained(1, unpkr));
    }
    return obj;
}

plat_inline void destroyAstSwitchStmt(AstSwitchStmt obj) {
    release_mmobj(obj->eval);
    release_mmobj(obj->stmt);
}

plat_inline void packAstSwitchStmt(AstSwitchStmt obj, Packer pkr) {
    if (is_packer_v1(pkr)) {
        pack_mmobj(0, obj->eval, pkr);
        pack_mmobj(1, obj->stmt, pkr);
    }
}

MMSubObject(AstSwitchStmt, AstStatement, initAstSwitchStmt, destroyAstSwitchStmt, packAstSwitchStmt);

plat_inline int compareForAstSwitchStmt(void* this_stru, void* that_stru) {
    AstSwitchStmt switchStmt1 = toAstSwitchStmt(this_stru);
    AstSwitchStmt switchStmt2 = toAstSwitchStmt(that_stru);
    int r = compare_parent(switchStmt1, switchStmt2);
    if (r) return r;
    return FIRST_Of_2RESULTS(compare_mmobjs(switchStmt1->eval, switchStmt2->eval),
                             compare_mmobjs(switchStmt1->stmt, switchStmt2->stmt));
}

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

plat_inline int compareForAstIfStmt(void*, void*);
plat_inline AstIfStmt initAstIfStmt(AstIfStmt obj, Unpacker unpkr) {
    set_compare_for_mmobj(obj, compareForAstIfStmt);
    if (is_unpacker_v1(unpkr)) {
        obj->eval = toAstExpression(unpack_mmobj_retained(0, unpkr));
        obj->true_stmt = toAstStatement(unpack_mmobj_retained(1, unpkr));
        obj->false_stmt = toAstStatement(unpack_mmobj_retained(2, unpkr));
    }
    return obj;
}

plat_inline void destroyAstIfStmt(AstIfStmt obj) {
    release_mmobj(obj->eval);
    release_mmobj(obj->true_stmt);
    release_mmobj(obj->false_stmt);
}

plat_inline void packAstIfStmt(AstIfStmt obj, Packer pkr) {
    if (is_packer_v1(pkr)) {
        pack_mmobj(0, obj->eval, pkr);
        pack_mmobj(1, obj->true_stmt, pkr);
        pack_mmobj(2, obj->false_stmt, pkr);
    }
}

MMSubObject(AstIfStmt, AstStatement, initAstIfStmt, destroyAstIfStmt, packAstIfStmt);

plat_inline int compareForAstIfStmt(void* this_stru, void* that_stru) {
    AstIfStmt ifStmt1 = toAstIfStmt(this_stru);
    AstIfStmt ifStmt2 = toAstIfStmt(that_stru);
    int r = compare_parent(ifStmt1, ifStmt2);
    if (r) return r;
    return FIRST_Of_3RESULTS(compare_mmobjs(ifStmt1->eval, ifStmt2->eval),
                             compare_mmobjs(ifStmt1->true_stmt, ifStmt2->true_stmt),
                             compare_mmobjs(ifStmt1->false_stmt, ifStmt2->false_stmt));
}

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

plat_inline int compareForAstLoopStmt(void*, void*);
plat_inline AstLoopStmt initAstLoopStmt(AstLoopStmt obj, Unpacker unpkr) {
    set_compare_for_mmobj(obj, compareForAstLoopStmt);
    if (is_unpacker_v1(unpkr)) {
        obj->stmt = toAstStatement(unpack_mmobj_retained(0, unpkr));
    }
    return obj;
}

plat_inline void destroyAstLoopStmt(AstLoopStmt obj) {
    release_mmobj(obj->stmt);
}

plat_inline void packAstLoopStmt(AstLoopStmt obj, Packer pkr) {
    if (is_packer_v1(pkr)) {
        pack_mmobj(0, obj->stmt, pkr);
    }
}

MMSubObject(AstLoopStmt, AstStatement, initAstLoopStmt, destroyAstLoopStmt, packAstLoopStmt);

plat_inline int compareForAstLoopStmt(void* this_stru, void* that_stru) {
    AstLoopStmt loopStmt1 = toAstLoopStmt(this_stru);
    AstLoopStmt loopStmt2 = toAstLoopStmt(that_stru);
    int r = compare_parent(loopStmt1, loopStmt2);
    if (r) return r;
    return compare_mmobjs(loopStmt1->stmt, loopStmt2->stmt);
}

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

plat_inline int compareForAstEachStmt(void*, void*);
plat_inline AstEachStmt initAstEachStmt(AstEachStmt obj, Unpacker unpkr) {
    set_compare_for_mmobj(obj, compareForAstEachStmt);
    if (is_unpacker_v1(unpkr)) {
        obj->eval = toAstExpression(unpack_mmobj_retained(0, unpkr));
        obj->stmt = toAstStatement(unpack_mmobj_retained(1, unpkr));
    }
    return obj;
}

plat_inline void destroyAstEachStmt(AstEachStmt obj) {
    release_mmobj(obj->eval);
    release_mmobj(obj->stmt);
}

plat_inline void packAstEachStmt(AstEachStmt obj, Packer pkr) {
    if (is_packer_v1(pkr)) {
        pack_mmobj(0, obj->eval, pkr);
        pack_mmobj(1, obj->stmt, pkr);
    }
}

MMSubObject(AstEachStmt, AstStatement, initAstEachStmt, destroyAstEachStmt, packAstEachStmt);

plat_inline int compareForAstEachStmt(void* this_stru, void* that_stru) {
    AstEachStmt eachStmt1 = toAstEachStmt(this_stru);
    AstEachStmt eachStmt2 = toAstEachStmt(that_stru);
    int r = compare_parent(eachStmt1, eachStmt2);
    if (r) return r;
    return FIRST_Of_2RESULTS(compare_mmobjs(eachStmt1->eval, eachStmt2->eval),
                             compare_mmobjs(eachStmt1->stmt, eachStmt2->stmt));
}

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

plat_inline int compareForAstJumpStmt(void*, void*);
plat_inline AstJumpStmt initAstJumpStmt(AstJumpStmt obj, Unpacker unpkr) {
    set_compare_for_mmobj(obj, compareForAstJumpStmt);
    if (is_unpacker_v1(unpkr)) {
        obj->type = (ast_jump_type)unpack_varint(0, unpkr);
        obj->identifier = toAstIdentifier(unpack_mmobj_retained(1, unpkr));
    }
    return obj;
}

plat_inline void destroyAstJumpStmt(AstJumpStmt obj) {
    release_mmobj(obj->identifier);
}

plat_inline void packAstJumpStmt(AstJumpStmt obj, Packer pkr) {
    if (is_packer_v1(pkr)) {
        pack_varint(0, obj->type, pkr);
        pack_mmobj(1, obj->identifier, pkr);
    }
}

MMSubObject(AstJumpStmt, AstStatement, initAstJumpStmt, destroyAstJumpStmt, packAstJumpStmt);

plat_inline int compareForAstJumpStmt(void* this_stru, void* that_stru) {
    AstJumpStmt jumpStmt1 = toAstJumpStmt(this_stru);
    AstJumpStmt jumpStmt2 = toAstJumpStmt(that_stru);
    int r = compare_parent(jumpStmt1, jumpStmt2);
    if (r) return r;
    return FIRST_Of_2RESULTS((int)jumpStmt1->type - (int)jumpStmt2->type,
                             compare_mmobjs(jumpStmt1->identifier, jumpStmt2->identifier));
}

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

plat_inline int compareForAstAnchorStmt(void*, void*);
plat_inline AstAnchorStmt initAstAnchorStmt(AstAnchorStmt obj, Unpacker unpkr) {
    set_compare_for_mmobj(obj, compareForAstAnchorStmt);
    if (is_unpacker_v1(unpkr)) {
        obj->label = toAstIdentifier(unpack_mmobj_retained(0, unpkr));
    }
    return obj;
}

plat_inline void destroyAstAnchorStmt(AstAnchorStmt obj) {
    release_mmobj(obj->label);
}

plat_inline void packAstAnchorStmt(AstAnchorStmt obj, Packer pkr) {
    if (is_packer_v1(pkr)) {
        pack_mmobj(0, obj->label, pkr);
    }
}

MMSubObject(AstAnchorStmt, AstStatement, initAstAnchorStmt, destroyAstAnchorStmt, packAstAnchorStmt);

plat_inline int compareForAstAnchorStmt(void* this_stru, void* that_stru) {
    AstAnchorStmt anchorStmt1 = toAstAnchorStmt(this_stru);
    AstAnchorStmt anchorStmt2 = toAstAnchorStmt(that_stru);
    int r = compare_parent(anchorStmt1, anchorStmt2);
    if (r) return r;
    return compare_mmobjs(anchorStmt1->label, anchorStmt2->label);
}

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

plat_inline int compareForAstSyncStmt(void*, void*);
plat_inline AstSyncStmt initAstSync(AstSyncStmt obj, Unpacker unpkr) {
    set_compare_for_mmobj(obj, compareForAstSyncStmt);
    if (is_unpacker_v1(unpkr)) {
        obj->identifier = toAstIdentifier(unpack_mmobj_retained(0, unpkr));
    }
    return obj;
}

plat_inline void destroyAstSync(AstSyncStmt obj) {
    release_mmobj(obj->identifier);
}

plat_inline void packAstSync(AstSyncStmt obj, Packer pkr) {
    if (is_packer_v1(pkr)) {
        pack_mmobj(0, obj->identifier, pkr);
    }
}

MMSubObject(AstSyncStmt, AstStatement, initAstSync, destroyAstSync, packAstSync);

plat_inline int compareForAstSyncStmt(void* this_stru, void* that_stru) {
    AstSyncStmt syncStmt1 = toAstSyncStmt(this_stru);
    AstSyncStmt syncStmt2 = toAstSyncStmt(that_stru);
    int r = compare_parent(syncStmt1, syncStmt2);
    if (r) return r;
    return compare_mmobjs(syncStmt1->identifier, syncStmt2->identifier);
}

plat_inline AstSyncStmt allocAstSyncStmtWithIdentifier(mgn_memory_pool* pool, AstIdentifier identifier) {
    AstSyncStmt obj = allocAstSyncStmt(pool);
    if (obj) {
        obj->identifier = retain_mmobj(identifier);
    }
    return obj;
}


#endif //PROC_LA_AST_STMT_H
