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

%token          AUTO BREAK CASE CONTINUE DEFAULT DO ELSE FOR GOTO IF SWITCH WHILE
%token          IS OUT DECLARE SYNC DOMAIN_NAME PACKAGE_NAME

//%right          IF ELSE
//%precedence     IF
//%precedence     ELSE

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


primary_expression
    : IDENTIFIER
    | constant
    | string
    | '(' expression ')'
    ;

// only for case statement
value_expression
    : IDENTIFIER
    | constant
    | string
    | '(' value_expression ')'
    ;

constant
    : N_CONSTANT
    | I_CONSTANT
    | F_CONSTANT
    ;

string
    : STRING_LITERAL
    ;

// === expression ===

postfix_expression
	: primary_expression
	| postfix_expression '[' expression ']'
	| postfix_expression '{' expression '}'
//	| postfix_expression '.' IDENTIFIER
//	| postfix_expression PTR_OP IDENTIFIER
	| postfix_expression INC_OP
	| postfix_expression DEC_OP
//	| '(' type_name ')' '{' initializer_list '}'
//	| '(' type_name ')' '{' initializer_list ',' '}'
	;

unary_expression
    : postfix_expression
    | INC_OP unary_expression
    | DEC_OP unary_expression
    | unary_operator unary_expression
    ;

unary_operator
	: '+'
	| '-'
	| '~'
	| '!'
	;

multiplicative_expression
	: unary_expression
	| multiplicative_expression '*' unary_expression
	| multiplicative_expression '/' unary_expression
	| multiplicative_expression '%' unary_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	;

shift_expression
	: additive_expression
	| shift_expression LEFT_OP additive_expression
	| shift_expression RIGHT_OP additive_expression
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression LE_OP shift_expression
	| relational_expression GE_OP shift_expression
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression
	| equality_expression NE_OP relational_expression
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression
	;

assignment_expression
	: conditional_expression
	| assignment_expression APPLY_TO unary_expression
    ;

//argument_expression_list
//	: assignment_expression
//	| argument_expression_list ',' assignment_expression
//	;

expression
    : assignment_expression
	| value_initializer
    | expression ',' assignment_expression
	| '(' ')'
//	| '(' expression ')'
    ;

expression_statement
	: ';'
	| expression ';'
	| expression APPLY_TO OUT ';'
	| la_assignment_expression ';'
	;

// ===== la statement/expression =====

la_statement
    : pipe_op la_body_declaration pipe_op
    | la_statement pipe_op la_body_declaration pipe_op
    ;

la_assignment_expression
    : expression la_statement IDENTIFIER
    | expression la_statement OUT
    | expression la_statement pipe_op la_body_declaration
    ;

pipe_op
    : PIPE_1_TO_1
    | PIPE_REDUCE
    | PIPE_EXPAND
    | PIPE_INJECT
    ;

// ======================== declaration ==================

declaration
	: init_declarator ';'
	;

init_declarator
	: value_initializer APPLY_TO declarator
	| declarator
	;

declarator
    : var_declaration
    ;

value_initializer
    : assignment_expression
	| '[' list_initializer_list ']'
	| '{' map_initializer_list '}'
	;

list_initializer_list
    : value_initializer
//    | assignment_expression
    | list_initializer_list ',' assignment_expression
    ;

map_initializer_list
    : value_initializer
    | string ':' assignment_expression
    | map_initializer_list ',' string ':' assignment_expression


// ==== statement flow =====

statement
	: labeled_statement
	| compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

labeled_statement
	: IDENTIFIER ':' statement
	;

case_statement
    : CASE value_expression ':' statement
    | DEFAULT ':' statement
    ;

cases_block_statement
    : cases_block_statement case_statement
    | case_statement
    ;

compound_statement
    : '{' '}' {
        // TODO: refine the function
	    $$ = ast_create_ast_body(null, null);
	}
	| '{'  block_item_list '}' {
	    $$ = $2;
	}
	;

block_item_list
	: block_item
	| block_item_list block_item {
	    // TODO: refine the function
	    $$ = ast_create_ast_body($1, $2);
	}
	;

block_item
	: declaration
	| statement
	;

selection_statement
	: IF '(' expression ')' statement ELSE statement
	| IF '(' expression ')' statement
	| SWITCH '(' expression ')' '{' cases_block_statement '}'
	;

iteration_statement
	: WHILE '(' expression ')' statement
	| DO statement WHILE '(' expression ')' ';'
	| FOR '(' expression_statement expression_statement ')' statement
	| FOR '(' expression_statement expression_statement expression ')' statement
	| FOR '(' declaration expression_statement ')' statement
	| FOR '(' declaration expression_statement expression ')' statement
	;

jump_statement
	: GOTO IDENTIFIER ';'
	| CONTINUE ';'
	| BREAK ';'
//	| RETURN ';'
//	| RETURN expression ';'
	;

/// ====================================================

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

la_body_declaration
    : la_input_declaration APPLY_TO compound_statement APPLY_TO la_output_declaration {
        $$ = ast_create_la_declaration($1, $3, $5);
    }
    | la_input_declaration compound_statement la_output_declaration {
        $$ = ast_create_la_declaration($1, $2, $3);
    }
    | la_input_declaration APPLY_TO compound_statement {
        $$ = ast_create_la_declaration($1, $3, null);
    }
    | la_input_declaration compound_statement {
        $$ = ast_create_la_declaration($1, $2, null);
    }
    | compound_statement APPLY_TO la_output_declaration {
        $$ = ast_create_la_declaration(null, $1, $3);
    }
    | compound_statement la_output_declaration {
        $$ = ast_create_la_declaration(null, $1, $2);
    }
    | compound_statement {
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