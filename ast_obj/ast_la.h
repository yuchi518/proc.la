//
// Created by Yuchi Chen on 2017/9/17.
//

#ifndef PROC_LA_AST_LA_H
#define PROC_LA_AST_LA_H

#include "ast_node.h"
#include "ast_type.h"
#include "ast_variable.h"
#include "ast_expr.h"
#include "ast_stmt.h"
#include "ast_container.h"

/// ===== External Declarations =====

typedef struct AstExternalDeclarations {
    MMList external_declarations;
}*AstExternalDeclarations;

plat_inline int compareForAstExternalDeclarations(void*, void*);
plat_inline AstExternalDeclarations initAstExternalDeclarations(AstExternalDeclarations obj, Unpacker unpkr) {
    set_compare_for_mmobj(obj, compareForAstExternalDeclarations);
    if (is_unpacker_v1(unpkr)) {
        obj->external_declarations = toMMList(unpack_mmobj_retained(0, unpkr));
    } else {
        obj->external_declarations = allocMMList(pool_of_mmobj(obj));
        if (obj->external_declarations == null) return null;
    }
    return obj;
}

plat_inline void destroyAstExternalDeclarations(AstExternalDeclarations obj) {
    release_mmobj(obj->external_declarations);
}

plat_inline void packAstExternalDeclarations(AstExternalDeclarations obj, Packer pkr) {
    if (is_packer_v1(pkr)) {
        pack_mmobj(0, obj->external_declarations, pkr);
    }
}

MMSubObject(AstExternalDeclarations, AstNode, initAstExternalDeclarations, destroyAstExternalDeclarations, packAstExternalDeclarations);

plat_inline int compareForAstExternalDeclarations(void* this_stru, void* that_stru) {
    int r = compareForAstNode(this_stru, that_stru);
    if (r) return r;
    AstExternalDeclarations externalDeclarations1 = toAstExternalDeclarations(this_stru);
    AstExternalDeclarations externalDeclarations2 = toAstExternalDeclarations(that_stru);
    return compare_mmobjs(externalDeclarations1->external_declarations, externalDeclarations2->external_declarations);
}

plat_inline void addExternalDeclarationTo(AstExternalDeclarations external_declarations, AstNode node) {
    //plat_io_printf_dbg("ExtDec: %p\n", node);
    pushMMListItem(external_declarations->external_declarations, toMMObject(node));
}

plat_inline void concatExternalDeclarations(AstExternalDeclarations dest_list, AstExternalDeclarations a_list) {
    concatMMList(dest_list->external_declarations, a_list->external_declarations);
}

plat_inline void insertExternalDeclarationAt(AstExternalDeclarations list, AstNode declare, uint idx) {
    insertMMListItem(list->external_declarations, toMMObject(declare), idx);
}

plat_inline uint sizeOfExternalDeclarations(AstExternalDeclarations list) {
    return sizeOfMMList(list->external_declarations);
}

plat_inline AstNode getExternalDeclarationAt(AstExternalDeclarations list, uint idx) {
    return toAstNode(getMMListItem(list->external_declarations, idx));
}

/// ===== A Proc La =====

typedef struct AstAProcLa {
    AstPackage package;
    AstExternalDeclarations external_declarations;
}*AstAProcLa;

plat_inline int compareForAstAProcLa(void*, void*);
struct AstErrorRecovery* optimizeAstAProcLa(AstNode node, struct AstContext* context);
plat_inline AstAProcLa initAstAProcLa(AstAProcLa obj, Unpacker unpkr) {
    set_compare_for_mmobj(obj, compareForAstAProcLa);
    set_optimization(obj, optimizeAstAProcLa);
    if (is_unpacker_v1(unpkr)) {
        obj->package = toAstPackage(unpack_mmobj_retained(0, unpkr));
        obj->external_declarations = toAstExternalDeclarations(unpack_mmobj_retained(1, unpkr));
    }
    return obj;
}

plat_inline void destroyAstAProcLa(AstAProcLa obj) {
    release_mmobj(obj->package);
    release_mmobj(obj->external_declarations);
}

plat_inline void packAstAProcLa(AstAProcLa obj, Packer pkr) {
    if (is_packer_v1(pkr)) {
        pack_mmobj(0, obj->package, pkr);
        pack_mmobj(1, obj->external_declarations, pkr);
    }
}

MMSubObject(AstAProcLa, AstNode, initAstAProcLa, destroyAstAProcLa, packAstAProcLa);

plat_inline int compareForAstAProcLa(void* this_stru, void* that_stru) {
    int r = compareForAstNode(this_stru, that_stru);
    if (r) return r;
    AstAProcLa aProcLa1 = toAstAProcLa(this_stru);
    AstAProcLa aProcLa2 = toAstAProcLa(that_stru);
    return FIRST_Of_2RESULTS(compare_mmobjs(aProcLa1->package, aProcLa2->package),
                             compare_mmobjs(aProcLa1->external_declarations, aProcLa2->external_declarations));
}

plat_inline AstAProcLa allocAstAProcLaWithPackageAndExternalDeclarations(mgn_memory_pool* pool, AstPackage package, AstExternalDeclarations external_declarations) {
    AstAProcLa obj = allocAstAProcLa(pool);
    if (obj) {
        if (package) {
            obj->package = retain_mmobj(package);
        } else {
            obj->package = allocAstPackageWithCStringName(pool, "");
        }
        obj->external_declarations = retain_mmobj(external_declarations);
    }
    return obj;
}


#endif //PROC_LA_AST_LA_H
