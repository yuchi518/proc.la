%{
    #include "ast.h"
    typedef AstNode YYSTYPE;
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
        $$ = ast_create_combined_type($1, ast_type_list);
    }
    | basic_var_type_specifier "{}" {
        $$ = ast_create_combined_type($1, ast_type_map);
    }
    | combined_var_type_specifier "[]" {
        $$ = ast_create_combined_type($1, ast_type_list);
    }
    | combined_var_type_specifier "{}" {
        $$ = ast_create_combined_type($1, ast_type_map);
    }
    ;


la_const
    : N_CONSTANT
    | I_CONSTANT
    | F_CONSTANT
    | STRING_LITERAL
    ;

la_math_op_0
    : la_express '*' la_express
    | la_express '/' la_express
    | la_express '%' la_express
    ;

la_math_op_1
    : la_express '+' la_express
    | la_express '-' la_express
    ;

la_express
    : la_const
    | IDENTIFIER
    | la_math_op_1
    | '(' la_express ')' {
        $$ = $2;
    }
    | la_express APPLY_TO IDENTIFIER {

    }
    ;

la_segment
    : var_declaration ';'
    | la_express ';'
    ;

var_type_specifier
    : basic_var_type_specifier
    | combined_var_type_specifier
    ;

var_declaration
    : IDENTIFIER ':' var_type_specifier {
        $$ = ast_create_var_declare($3, $1);
    }
    ;

var_list_declaration
    : var_list_declaration ',' var_declaration {
        $$ = ast_create_var_list($1, $3);
    }
    | var_declaration {
        $$ = ast_create_var_list($1, null);
    }
    ;

type_list_declaration
    : type_list_declaration ',' var_type_specifier {
        $$ = ast_create_type_list($1, $3);
    }
    | var_type_specifier {
        $$ = ast_create_type_list($1, null);
    }
    ;

la_input_declaration
    : '(' var_list_declaration ')' {
        $$ = $2;
    }
    | '(' ')' {
        // create an empty list
        $$ = ast_create_var_list(null, null);
    }
    ;

la_output_declaration
    : '(' type_list_declaration ')' {
        $$ = $2;
    }
    | '(' ')' {
        // create an empty list
        $$ = ast_create_type_list(null, null);
    }
    ;

la_body_segments
    : la_body_segments la_segment {
        $$ = ast_create_ast_body($1, $2);
    }
    | la_segment {
        $$ = ast_create_ast_body($1, null);
    }
    ;

la_body_implementation
    : '{' la_body_segments '}' {
        $$ = $2;
    }
    | '{' '}' {
        $$ = ast_create_ast_body(null, null);
    }
    ;

la_body_declaration
    : la_input_declaration APPLY_TO la_body_implementation APPLY_TO la_output_declaration {
        $$ = ast_create_la_declaration($1, $3, $5);
    }
    | la_input_declaration APPLY_TO la_body_implementation {
        $$ = ast_create_la_declaration($1, $3, null);
    }
    | la_body_implementation APPLY_TO la_output_declaration {
        $$ = ast_create_la_declaration(null, $1, $3);
    }
    | la_body_implementation {
        $$ = ast_create_la_declaration(null, $1, null);
    }
    ;

la_declaration
    : DECLARE IDENTIFIER ':' LA la_body_declaration ';' {
        $$ = ast_create_var_instance_ex($4, $2, $5);
    }
    ;

la_alias
    : DOMAIN_NAME APPLY_TO IDENTIFIER ':' LA ';' {
        $$ = ast_create_var_instance_ex($5, $3, $1);
    }
    ;

external_declaration
    : la_alias
    | la_declaration
    ;

external_declaration_list
    : external_declaration_list external_declaration {
        $$ = ast_create_external_declarations($1, $2);
    }
    | external_declaration {
        $$ = ast_create_external_declarations($1, null);
    }
    ;

package_declare
    : PACKAGE_NAME
    ;

a_proc_la
    : package_declare external_declaration_list {
        $$ = ast_create_a_proc_la($1, $2);
    }
    | external_declaration_list {
        $$ = ast_create_a_proc_la(null, $1);
    }
    ;

%%

#include <stdio.h>

void yyerror(const char *s)
{
	fflush(stdout);
	fprintf(stderr, "LN:%04d %s\n", yylineno, s);
}