%{
    #include "ast.h"
    typedef struct la_ast* YYSTYPE;
    #define YYSTYPE_IS_DECLARED     1
    void yyerror (char const *s);
    int yylex();
%}

%token          IDENTIFIER
%token          I_CONSTANT F_CONSTANT STRING_LITERAL N_CONSTANT

%token	        INT LONG FLOAT DOUBLE NUMBER STRING RAW VAR PROC LA

%token          APPLY_TO PIPE_1_TO_1 PIPE_REDUCE PIPE_EXPAND PIPE_INJECT

%token          RIGHT_ASSIGN LEFT_ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN
%token          RIGHT_OP LEFT_OP INC_OP DEC_OP AND_OP OR_OP LE_OP GE_OP EQ_OP NE_OP
%token          IS OUT DECLARE SYNC DOMAIN_NAME PACKAGE_NAME

%start          a_proc_la

%%

basic_var_type_specifier
	: INT
	| LONG
	| FLOAT
	| DOUBLE
	| NUMBER
	| STRING
	| RAW
	| VAR
	;

combined_var_type_specifier
    : basic_var_type_specifier "[]" {
        $$ = la_ast_create_combined_type($1, la_ast_container_typ_array);
        release_astObj($1);
    }
    | basic_var_type_specifier "{}" {
        $$ = la_ast_create_combined_type($1, la_ast_container_typ_map);
                release_astObj($1);
    }
    | combined_var_type_specifier "[]" {
        $$ = la_ast_create_combined_type($1, la_ast_container_typ_array);
                release_astObj($1);
    }
    | combined_var_type_specifier "{}" {
        $$ = la_ast_create_combined_type($1, la_ast_container_typ_map);
                        release_astObj($1);
    }
    ;

var_type_specifier
    : basic_var_type_specifier
    | combined_var_type_specifier
    ;

var_declaration
    : IDENTIFIER ':' var_type_specifier {
        $$ = la_ast_create_var_declare($1, $3);
        release_astObj($1);
        release_astObj($3);
    }
    ;

var_list_declaration
    : var_list_declaration ',' var_declaration {
        $$ = la_ast_create_collection(la_ast_var_list_declaration, $1, $3, null);
        release_astObj($1);
        release_astObj($3);
    }
    | var_declaration {
        $$ = la_ast_create_collection(la_ast_var_list_declaration, $1, null);
        release_astObj($1);
    }
    ;

type_list_declaration
    : type_list_declaration ',' var_type_specifier {
        $$ = la_ast_create_collection(la_ast_type_list_declaration, $1, $3, null);
        release_astObj($1);
        release_astObj($3);
    }
    | var_type_specifier {
        $$ = la_ast_create_collection(la_ast_type_list_declaration, $1, null);
        release_astObj($1);
    }
    ;


la_input_declaration
    : '(' var_list_declaration ')' {
        $$ = $2;
    }
    | '(' ')' {
        // create an empty list
        $$ = la_ast_create_collection(la_ast_var_list_declaration, null);
    }
    ;

la_output_declaration
    : '(' type_list_declaration ')' {
        $$ = $2;
    }
    | '(' ')' {
        // create an empty list
        $$ = la_ast_create_collection(la_ast_type_list_declaration, null);
    }
    ;

la_body_implementation
    : '{' '}' {
        $$ = la_ast_create_collection(la_ast_la_body_declaration, null);
    }
    ;

la_body_declaration
    : la_input_declaration APPLY_TO la_body_implementation APPLY_TO la_output_declaration {
        $$ = la_ast_create_la_declaration($1, $3, $5);
        release_astObj($1);
        release_astObj($3);
        release_astObj($5);
    }
    | la_input_declaration APPLY_TO la_body_implementation {
        $$ = la_ast_create_la_declaration($1, $3, null);
        release_astObj($1);
        release_astObj($3);
    }
    | la_body_implementation APPLY_TO la_output_declaration {
        $$ = la_ast_create_la_declaration(null, $1, $3);
        release_astObj($1);
        release_astObj($3);
    }
    | la_body_implementation {
        $$ = la_ast_create_la_declaration(null, $1, null);
        release_astObj($1);
    }
    ;

la_declaration
    : DECLARE IDENTIFIER ':' LA la_body_declaration ';' {
        $$ = la_ast_create_var_instance_ex($2, $4, $5);
        release_astObj($1);
        release_astObj($2);
        release_astObj($4);
        release_astObj($5);
    }
    ;

la_alias
    : DOMAIN_NAME APPLY_TO IDENTIFIER ':' LA ';' {
        $$ = la_ast_create_la_alias($1, $3);
        release_astObj($1);
        release_astObj($3);
        release_astObj($5);
    }
    ;

external_declaration
    : la_alias
    | la_declaration
    ;

external_declaration_list
    : external_declaration_list external_declaration {
        $$ = la_ast_create_collection(la_ast_external_declarations, $1, $2, null);
        release_astObj($1);
        release_astObj($2);
    }
    | external_declaration {
        $$ = la_ast_create_collection(la_ast_external_declarations, $1, null);
        release_astObj($1);
    }
    ;

package_declare
    : PACKAGE_NAME
    ;

a_proc_la
    : package_declare external_declaration_list {
        $$ = la_ast_create_a_proc_la($1, $2);
        release_astObj($1);
        release_astObj($2);
    }
    | external_declaration_list {
        $$ = la_ast_create_a_proc_la(null, $1);
        release_astObj($1);
    }
    ;

%%

#include <stdio.h>

void yyerror(const char *s)
{
	fflush(stdout);
	fprintf(stderr, "LN:%04d %s\n", yylineno, s);
}