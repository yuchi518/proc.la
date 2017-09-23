//
// Created by Yuchi Chen on 2017/9/17.
//

#ifndef PROC_LA_AST_LA_H
#define PROC_LA_AST_LA_H

#include "ast_node.h"
#include "ast_type.h"
#include "ast_variable.h"
#include "ast_stmt.h"

/// ===== External Declarations =====

typedef struct AstExternalDeclarations {
    MMList external_declarations;
}*AstExternalDeclarations;

plat_inline AstExternalDeclarations initAstExternalDeclarations(AstExternalDeclarations obj, Unpacker unpkr) {
    obj->external_declarations = allocMMList(pool_of_mmobj(obj));
    if (obj->external_declarations == null) return null;
    return obj;
}

plat_inline void destroyAstExternalDeclarations(AstExternalDeclarations obj) {
    if (obj->external_declarations) {
        release_mmobj(obj->external_declarations);
    }
}

plat_inline void packAstExternalDeclarations(AstExternalDeclarations obj, Packer pkr) {

}

MMSubObject(AST_EXTERNAL_DECLARATIONS, AstExternalDeclarations, AstNode, initAstExternalDeclarations, destroyAstExternalDeclarations, packAstExternalDeclarations);

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

plat_inline AstAProcLa initAstAProcLa(AstAProcLa obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstAProcLa(AstAProcLa obj) {
    if (obj->package) {
        release_mmobj(obj->package);
    }
    if (obj->external_declarations) {
        release_mmobj(obj->external_declarations);
    }
}

plat_inline void packAstAProcLa(AstAProcLa obj, Packer pkr) {

}

MMSubObject(AST_A_PROC_LA, AstAProcLa, AstNode, initAstAProcLa, destroyAstAProcLa, packAstAProcLa);

plat_inline AstAProcLa allocAstAProcLaWithPackageAndExternalDeclarations(mgn_memory_pool* pool, AstPackage package, AstExternalDeclarations external_declarations) {
    AstAProcLa obj = allocAstAProcLa(pool);
    if (obj) {
        obj->package = retain_mmobj(package);
        obj->external_declarations = retain_mmobj(external_declarations);
    }
    return obj;
}


#endif //PROC_LA_AST_LA_H
