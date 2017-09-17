//
// Created by Yuchi Chen on 2017/9/16.
//

#ifndef PROC_LA_AST_CTRL_H
#define PROC_LA_AST_CTRL_H

#include "ast_node.h"

/// ===== Ctrl =====

typedef struct AstCtrl {

}*AstCtrl;

plat_inline AstCtrl initAstCtrl(AstCtrl obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstCtrl(AstCtrl obj) {

}

plat_inline void packAstCtrl(AstCtrl obj, Packer pkr) {

}

MMSubObject(AST_CTRL, AstCtrl, AstNode , initAstCtrl, destroyAstCtrl, packAstCtrl);


/// ===== Ctrl - Flow =====
/**
 * One of following controls:
 *   la_ast_ctrl_out
 *   la_ast_ctrl_is
 *   la_ast_ctrl_declare
 *   la_ast_ctrl_sync
 */

typedef struct AstCtrlFlow {

}*AstCtrlFlow;

plat_inline AstCtrlFlow initAstCtrlFlow(AstCtrlFlow obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstCtrlFlow(AstCtrlFlow obj) {

}

plat_inline void packAstCtrlFlow(AstCtrlFlow obj, Packer pkr) {

}

MMSubObject(AST_CTRL_FLOW, AstCtrlFlow, AstCtrl , initAstCtrlFlow, destroyAstCtrlFlow, packAstCtrlFlow);

plat_inline AstCtrlFlow allocAstCtrlFlowWithCtrl(mgn_memory_pool* pool, enum la_ast_typ ctrl) {
    switch (ctrl)
    {
        case la_ast_ctrl_out:
        case la_ast_ctrl_is:
        case la_ast_ctrl_declare:
        case la_ast_ctrl_sync:
            break;
        default: {
            plat_io_printf_err("Is not a ctrl(flow) type: %s\n", la_ast_typ_to_string(ctrl));
            return null;
        }
    }

    AstCtrlFlow obj = allocAstCtrlFlow(pool);
    if (obj) {
        toAstNode(obj)->type = ctrl;
    }

    return obj;
}


#endif //PROC_LA_AST_CTRL_H
