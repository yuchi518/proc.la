//
// Created by Yuchi Chen on 2017/11/19.
//

#include "ast_la.h"
#include "ast_runtime.h"

#define OPT_DBG     1

struct AstErrorRecovery* optimizeAstAProcLa(AstNode node, struct AstContext* context)
{
    mgn_memory_pool* pool = pool_of_mmobj(node);
    AstAProcLa aProcLa = toAstAProcLa(node);
    if (aProcLa == null) {
        return error_recovery(pool, 0, mmstring(pool, "What is this?(%s)", name_of_last_mmobj(node)), node);
    }

    if (context != null) {
        // always should be null
        return error_recovery(pool, 0, mmstring(pool, "Redundant context."), node);
    }

    MMString package_name;
    if (aProcLa->package && (package_name=aProcLa->package->name)) {
        MMList list;
        if (aProcLa->external_declarations && (list=aProcLa->external_declarations->external_declarations)) {
            // init context
            context = allocAstContextWithStackAndScope(pool,
                                                       null,
                                                       autorelease_mmobj(allocAstScopeWithTriggerAndLastScopeInPackage(pool, null, null, aProcLa->package)));
            set_ast_context(node, autorelease_mmobj(context));
            MMMap constants = context->scope->constants;
            // verify each la
            uint cnt = sizeOfMMList(list);
            uint i;
            for (i=0; i<cnt; i++) {
                AstNode node = toAstNode(getMMListItem(list, i));
                AstVarInstance varInstance = toAstVarInstance(node);
                if (varInstance) {
                    AstVarDeclare varDeclare = varInstance->declare;
                    if (varDeclare->identifier_type->type == ast_type_la) {
                        // Two type of instant: AstDomainName, AstALa
                        uint num = 0;

                        if (isAstALa(varInstance->inst)) {
                            AstALa aLa = toAstALa(varInstance->inst);
                            num = sizeOfMMList(aLa->input->list);
                        } else if (isAstDomainName(varInstance->inst)) {
                            // Only one input arguments: var
                            AstDomainName domainName = toAstDomainName(varInstance);
                            num = 1;
                        } else {
                            return error_recovery(pool, 0, mmstring(pool, "This is not a La."), node);
                        }
                        MMString str = mmstring(pool, "%s.%s:%u", package_name->value, varDeclare->identifier->name->value, num);
                        if (OPT_DBG) plat_io_printf_std("Create a La entry: %s\n", str->value);
                        addMMMapItem(constants, toMMPrimary(str), toMMObject(varInstance));
                    }
                }
            }

            return null;
        }

        return error_recovery(pool, 0, mmstring(pool, "No any external declarations."), node);
    }

    return error_recovery(pool, 0, mmstring(pool, "No package name."), node);
}