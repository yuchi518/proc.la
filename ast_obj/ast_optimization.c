//
// Created by Yuchi Chen on 2017/11/19.
//

#include "ast_la.h"
#include "ast_runtime.h"

struct AstErrorRecovery* optimizeAstAProcLa(void* stru, struct AstContext* context)
{
    AstAProcLa aProcLa = toAstAProcLa(stru);
    if (aProcLa == null) {
        plat_io_printf_err("What is this?(%s)\n", name_of_last_mmobj(stru));
    }

    MMMap constants = context->scope->constants;

    if (aProcLa->external_declarations) {
        MMList list = aProcLa->external_declarations->external_declarations;
        if (list) {
            uint cnt = sizeOfMMList(list);
            uint i;
            for (i=0; i<cnt; i++) {
                AstNode node = toAstNode(getMMListItem(list, i));
                AstVarInstance varInstance = toAstVarInstance(node);
                if (varInstance) {
                    AstVarDeclare varDeclare = varInstance->declare;
                    if (varDeclare->identifier_type->type == ast_type_la) {
                        // TODO: Add number of input parameters as partial of name
                        // TODO: check input variables is correct
                        addMMMapItem(constants, toMMPrimary(varDeclare->identifier->name), toMMObject(varInstance));
                    }
                }
            }

            return null;
        }
    }

    return null;
}