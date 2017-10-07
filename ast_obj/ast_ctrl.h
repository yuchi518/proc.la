//
// Created by Yuchi Chen on 2017/9/16.
//

#ifndef PROC_LA_AST_CTRL_H
#define PROC_LA_AST_CTRL_H

#include "ast_node.h"

typedef enum {
    ast_ctrl_type_is,
    ast_ctrl_type_declare,
    ast_ctrl_type_sync,
} ast_ctrl_type;
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
 *   out, is, declare, sync
 */

typedef struct AstCtrlFlow {
    ast_ctrl_type ctrl_type;
}*AstCtrlFlow;

plat_inline AstCtrlFlow initAstCtrlFlow(AstCtrlFlow obj, Unpacker unpkr) {
    return obj;
}

plat_inline void destroyAstCtrlFlow(AstCtrlFlow obj) {

}

plat_inline void packAstCtrlFlow(AstCtrlFlow obj, Packer pkr) {

}

MMSubObject(AST_CTRL_FLOW, AstCtrlFlow, AstCtrl , initAstCtrlFlow, destroyAstCtrlFlow, packAstCtrlFlow);

plat_inline AstCtrlFlow allocAstCtrlFlowWithCtrl(mgn_memory_pool* pool, ast_ctrl_type ctrl) {
    switch (ctrl)
    {
        case ast_ctrl_type_is:
        case ast_ctrl_type_declare:
        case ast_ctrl_type_sync:
            break;
        default: {
            plat_io_printf_err("Is not a ctrl(flow) type: %d\n", ctrl);
            return null;
        }
    }

    AstCtrlFlow obj = allocAstCtrlFlow(pool);
    if (obj) {
        obj->ctrl_type = ctrl;
    }

    return obj;
}


#endif //PROC_LA_AST_CTRL_H
