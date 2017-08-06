%token          IDENTIFIER
%token          I_CONSTANT F_CONSTANT STRING_LITERAL

%token	        INT LONG FLOAT DOUBLE NUMBER STRING RAW VAR PROC LA

%start          a_proc_la

%%

var_type_specifier
	: INT
	| LONG
	| FLOAT
	| DOUBLE
	| NUMBER
	| STRING
	| RAW
	| VAR
	;

la_body_declaration
    : '{' '}'
    ;

la_header_var_declaration
    : var_type_specifier IDENTIFIER
    ;

la_header_var_list_declaration
    : la_header_var_declaration ',' la_header_var_list_declaration
    | la_header_var_declaration
    ;

la_header_declaration
    : '(' la_header_var_list_declaration ')'
    | '(' la_header_var_list_declaration ')' ':' '(' la_header_var_list_declaration ')'
    ;

la_declaration
    : LA IDENTIFIER '=' IDENTIFIER ';'
    | LA IDENTIFIER la_header_declaration '=' la_body_declaration
    ;

proc_alias
    : PROC IDENTIFIER '=' package_name ';'
    ;

external_declaration
    : proc_alias
    | la_declaration
    ;

external_declaration_list
    : external_declaration external_declaration_list
    | external_declaration
    ;

package_name
    : IDENTIFIER
    | IDENTIFIER '.' package_name
    ;

package_declare
    : '@' package_name
    ;

a_proc_la
    : package_declare external_declaration_list
    | external_declaration_list
    ;

%%


#include <stdio.h>

void yyerror(const char *s)
{
	fflush(stdout);
	fprintf(stderr, "*** %s\n", s);
}