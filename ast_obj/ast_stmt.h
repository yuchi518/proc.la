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

/// ===== Statement - Var Declare =====
/**
 * Includes two parts:
 *   variable identifier
 *   variable type
 */
typedef struct AstVarDeclare {
    AstCtrlName var_identifier;
    enum la_ast_typ var_type;
}*AstVarDeclare;

plat_inline AstVarDeclare initAstVarDeclare(AstVarDeclare obj, Unpacker unpkr) {
    toAstNode(obj)->type = la_ast_var_declare;
    return obj;
}

plat_inline void destroyAstVarDeclare(AstVarDeclare obj) {
    if (obj->var_identifier) {
        release_mmobj(obj->var_identifier);
    }
}

plat_inline void packAstVarDeclare(AstVarDeclare obj, Packer pkr) {

}

MMSubObject(AST_VAR_DECLARE, AstVarDeclare, AstStatement, initAstVarDeclare, destroyAstVarDeclare, packAstVarDeclare);


plat_inline AstVarDeclare allocAstVarDeclareWithIdentifier(mgn_memory_pool* pool, AstCtrlName identifier, enum la_ast_typ type) {
    if (identifier == null) {
        plat_io_printf_err("Identifier can't be null\n");
        return null;
    }
    AstVarDeclare obj = allocAstVarDeclare(pool);
    if (obj) {
        obj->var_identifier = retain_mmobj(identifier);
        obj->var_type = type;
    }
    return obj;
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
    toAstNode(obj)->type = la_ast_var_instance;
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

/// ===== Variable - La =====
/**
 * Includes three parts:
 *   Input, input variable declaration (type + identifier)
 *   Body, statement, expression
 *   Output, output variable declaration (only type)
 */
typedef struct AstVariableLa {
    // input + body + output declarations

}*AstVariableLa;

plat_inline AstVariableLa initAstVariableLa(AstVariableLa obj, Unpacker unpkr) {
    toAstNode(obj)->type = la_ast_la_declaration;
    return obj;
}

plat_inline void destroyAstVariableLa(AstVariableLa obj) {

}

plat_inline void packAstVariableLa(AstVariableLa obj, Packer pkr) {

}

MMSubObject(AST_VARIABLE_LA, AstVariableLa, AstVariable , initAstVariableLa, destroyAstVariableLa, packAstVariableLa);

#if 0
plat_inline AstVariableLa allocAstVariableLaWith(mgn_memory_pool* pool, ...) {
    AstVariableLa obj = allocAstVariableLa(pool);
    if (obj) {
    }
    return obj;
}
#endif

#endif //PROC_LA_AST_STMT_H
