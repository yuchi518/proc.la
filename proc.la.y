%{
    #include "ast.h"
    typedef AstNode YYSTYPE;
    #define YYSTYPE_IS_DECLARED     1
    void yyerror (char const *s);
    int yylex();
%}

%token          IDENTIFIER
%token          I_CONSTANT F_CONSTANT STRING_LITERAL N_CONSTANT

%token	        INT LONG FLOAT DOUBLE NUMBER STRING RAW VAR PROC LA LIST MAP

%token          APPLY_TO PIPE_1_TO_1 PIPE_REDUCE PIPE_EXPAND PIPE_INJECT

%token          RIGHT_ASSIGN LEFT_ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN
%token          RIGHT_OP LEFT_OP INC_OP DEC_OP AND_OP OR_OP LE_OP GE_OP EQ_OP NE_OP

%token          AUTO BREAK CASE CONTINUE DEFAULT DO ELSE FOR GOTO IF SWITCH WHILE LOOP EACH
%token          IS OUT DECLARE SYNC DOMAIN_NAME PACKAGE_NAME

//%right          IF ELSE
//%precedence     ':'
//%precedence     var_type_specifier
//%right          APPLY_TO
%right          IDENTIFIER ':'
%right          ')' ELSE
//%right          ''

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
    : basic_var_type_specifier LIST {
        $$ = ast_create_combined_type($1, ast_type_list);
    }
    | basic_var_type_specifier MAP {
        $$ = ast_create_combined_type($1, ast_type_map);
    }
    | combined_var_type_specifier LIST {
        $$ = ast_create_combined_type($1, ast_type_list);
    }
    | combined_var_type_specifier MAP {
        $$ = ast_create_combined_type($1, ast_type_map);
    }
    ;

var_type_specifier
    : basic_var_type_specifier
    | combined_var_type_specifier
    ;

type_list_declaration
    : type_list_declaration ',' var_type_specifier {
        $$ = ast_create_type_list($1, $3);
    }
    | var_type_specifier {
        $$ = ast_create_type_list($1, null);
    }
    ;

var_declaration
    : IDENTIFIER ':' var_type_specifier {
        $$ = ast_create_var_declare($3, $1);
    }
    ;

constant
    : N_CONSTANT
    | I_CONSTANT
    | F_CONSTANT
    ;

string
    : STRING_LITERAL
    ;

primary_expression
    : constant
    | string
    | IDENTIFIER
    | var_declaration
    ;

list_expression
    : '[' list_item_list ']' {
        $$ = ast_close_container($2);
    }
    | '[' ']' {
        $$ = ast_create_none();
    }
    | LIST {
        $$ = ast_create_none();
    }
    ;

list_item_list
    : expression {
        $$ = ast_create_container($1, null, ast_container_type_list);
    }
    /*| expression ':' expression ':' expression {
        // TODO: from ~ to, incremental
    }*/
    | list_item_list ',' expression {
        $$ = ast_create_container($1, $3, ast_container_type_list);
    }
    ;

map_expression
    : '{' map_item_list '}' {
        $$ = ast_close_container($2);
    }
    //| '{' '}'  // This is a empty block.
    | MAP {
        $$ = ast_create_none();
    }
    ;

map_item_list
    : expression ':' expression {
        $$ = ast_create_container(ast_create_pair($1, $3), null, ast_container_type_map);
    }
    | map_item_list ',' expression ':' expression {
        $$ = ast_create_container($1, ast_create_pair($3, $5), ast_container_type_map);
    }
    ;

tuple_expression
    : '(' tuple_item_list ')' {
        $$ = ast_close_container($2);
    }
    | '(' ')' {
        $$ = ast_create_none();
    }
    ;

tuple_item_list
    : expression {
        $$ = ast_create_container($1, null, ast_container_type_tuple);
    }
    | tuple_item_list ',' expression {
         $$ = ast_create_container($1, $3, ast_container_type_tuple);
    }
    ;

container_access_expression
    : primary_expression
    | container_access_expression '[' expression ']' {
        $$ = ast_create_binary_op_expr($1, $3, ast_binary_op_list_access);
    }
    | container_access_expression '{' expression '}' {
        $$ = ast_create_binary_op_expr($1, $3, ast_binary_op_map_access);
    }

container_expression
    : list_expression
    | map_expression
    | tuple_expression
    | container_access_expression
    ;


// === expression ===

postfix_expression
	: container_expression
//	| postfix_expression '.' IDENTIFIER
//	| postfix_expression PTR_OP IDENTIFIER
	| postfix_expression INC_OP {
	    $$ = ast_create_unary_op_expr($1, ast_unary_op_inc_l);
	}
	| postfix_expression DEC_OP {
	    $$ = ast_create_unary_op_expr($1, ast_unary_op_dec_l);
	}
//	| '(' type_name ')' '{' initializer_list '}'
//	| '(' type_name ')' '{' initializer_list ',' '}'
	;

unary_expression
    : postfix_expression
    | INC_OP unary_expression {
        $$ = ast_create_unary_op_expr($2, ast_unary_op_inc_f);
    }
    | DEC_OP unary_expression {
        $$ = ast_create_unary_op_expr($2, ast_unary_op_dec_f);
    }
    | unary_operator unary_expression {
        $$ = ast_create_unary_op_expr_ex($2, $1);
    }
    ;

unary_operator
	: '+' {
	    $$ = ast_create_unary_op_expr(null, ast_unary_op_plus);
	}
	| '-' {
	    $$ = ast_create_unary_op_expr(null, ast_unary_op_minus);
	}
	| '~' {
	    $$ = ast_create_unary_op_expr(null, ast_unary_op_invert);
	}
	| '!' {
	    $$ = ast_create_unary_op_expr(null, ast_unary_op_not);
	}
	;

multiplicative_expression
	: unary_expression
	| multiplicative_expression '*' unary_expression {
	    $$ = ast_create_binary_op_expr($1, $3, ast_binary_op_multiply);
	}
	| multiplicative_expression '/' unary_expression {
	    $$ = ast_create_binary_op_expr($1, $3, ast_binary_op_divide);
	}
	| multiplicative_expression '%' unary_expression {
	    $$ = ast_create_binary_op_expr($1, $3, ast_binary_op_modulo);
	}
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression {
	    $$ = ast_create_binary_op_expr($1, $3, ast_binary_op_add);
	}
	| additive_expression '-' multiplicative_expression {
	    $$ = ast_create_binary_op_expr($1, $3, ast_binary_op_subtract);
	}
	;

shift_expression
	: additive_expression
	| shift_expression LEFT_OP additive_expression {
	    $$ = ast_create_binary_op_expr($1, $3, ast_binary_op_shift_left);
	}
	| shift_expression RIGHT_OP additive_expression {
	    $$ = ast_create_binary_op_expr($1, $3, ast_binary_op_shift_right);
	}
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression {
	    $$ = ast_create_binary_op_expr($1, $3, ast_binary_op_less);
	}
	| relational_expression '>' shift_expression {
	    $$ = ast_create_binary_op_expr($1, $3, ast_binary_op_great);
	}
	| relational_expression LE_OP shift_expression {
	    $$ = ast_create_binary_op_expr($1, $3, ast_binary_op_less_or_equal);
	}
	| relational_expression GE_OP shift_expression {
	    $$ = ast_create_binary_op_expr($1, $3, ast_binary_op_great_or_equal);
	}
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression {
	    $$ = ast_create_binary_op_expr($1, $3, ast_binary_op_equal);
	}
	| equality_expression NE_OP relational_expression {
	    $$ = ast_create_binary_op_expr($1, $3, ast_binary_op_not_equal);
	}
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression {
	    $$ = ast_create_binary_op_expr($1, $3, ast_binary_op_bit_and);
	}
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression {
	    $$ = ast_create_binary_op_expr($1, $3, ast_binary_op_bit_xor);
	}
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression {
	    $$ = ast_create_binary_op_expr($1, $3, ast_binary_op_bit_or);
	}
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP inclusive_or_expression {
	    $$ = ast_create_binary_op_expr($1, $3, ast_binary_op_and);
	}
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression {
	    $$ = ast_create_binary_op_expr($1, $3, ast_binary_op_or);
	}
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression {
	    $$ = ast_create_ternary_op_expr($1, $3, $5, ast_ternary_op_conditional);
	}
	;

assignment_expression
	: conditional_expression
    ;

expression
    : assignment_expression
    | expression APPLY_TO assignment_expression {
        $$ = ast_create_binary_op_expr($1, $3, ast_binary_op_apply_to);
    }
	| expression la_statement {
	    $$ = ast_apply_binary_op_expr_w_expr_b($2, $1);
	}
	| expression IS var_type_specifier {
	    $$ = ast_create_is_expr($1, $3);
	}
    ;

expression_statement
	: ';'
	| expression ';' {
	    $$ = $1;
	}
    | expression APPLY_TO OUT ';' {
        $$ = ast_create_binary_op_expr($1, $3, ast_binary_op_apply_to);
    }
	;

// ===== la statement/expression =====

la_statement
    : pipe_op DOMAIN_NAME {
        $$ = ast_apply_binary_op_expr_w_expr_b($1, $2);
    }
    | pipe_op la_body_declaration {
        $$ = ast_apply_binary_op_expr_w_expr_b($1, $2);
    }
    | pipe_op OUT {
        $$ = ast_apply_binary_op_expr_w_expr_b($1, $2);
    }
    | pipe_op assignment_expression {
        $$ = ast_apply_binary_op_expr_w_expr_b($1, $2);
    }
    ;

pipe_op
    : PIPE_1_TO_1 {
        $$ = ast_create_binary_op_expr_w_op(ast_binary_op_pipe_1to1);
    }
    | PIPE_REDUCE {
        $$ = ast_create_binary_op_expr_w_op(ast_binary_op_pipe_reduce);
    }
    | PIPE_EXPAND {
        $$ = ast_create_binary_op_expr_w_op(ast_binary_op_pipe_expand);
    }
    | PIPE_INJECT {
        $$ = ast_create_binary_op_expr_w_op(ast_binary_op_pipe_inject);
    }
    ;

// ==== statement flow =====

statement
	: labeled_statement
	| block_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	| SYNC IDENTIFIER ';' {
	    $$ = ast_create_sync($2);
	}
	;

labeled_statement
	: IDENTIFIER ':' statement {
	    $$ = ast_create_block(ast_create_anchor($1), $3);
	}
	;

case_statement
    : CASE expression ':' statement {
        $$ = ast_create_block(ast_create_case($2), $4);
    }
    | DEFAULT ':' statement {
        $$ = ast_create_block(ast_create_case(null), $3);
    }
    ;

cases_block_statement
    : cases_block_statement case_statement {
        $$ = ast_create_block($1, $2);
    }
    | case_statement
    ;

block_statement
    : '{' '}' {
        // This is also a empty map.
	    //$$ = ast_close_block(ast_create_block(null, null));
	    $$ = ast_create_none();
	}
	| '{'  block_item_list '}' {
	    $$ = ast_close_block($2);
	}
	;

block_item_list
	: block_item {
	    $$ = ast_create_block($1, null);
	}
	| block_item_list block_item {
	    $$ = ast_create_block($1, $2);
	}
	;

block_item
	: statement
	;

selection_statement
	: IF '(' expression ')' statement {
	    $$ = ast_create_ifelse($3, $5, null);
	}
	| IF '(' expression ')' statement ELSE statement {
	    $$ = ast_create_ifelse($3, $5, $7);
	}
	| SWITCH '(' expression ')' '{' cases_block_statement '}' {
	    $$ = ast_create_switch($3, ast_close_block($6));
	}
	;

iteration_statement
    : LOOP statement {
        $$ = ast_create_loop($2);
    }
    | EACH '(' expression ')' statement {
        $$ = ast_create_each($3, $5);
    }
	;

jump_statement
	: GOTO IDENTIFIER ';' {
	    $$ = ast_create_jump(ast_jump_type_goto, $2);
	}
	| CONTINUE ';' {
	    $$ = ast_create_jump(ast_jump_type_continue, null);
	}
	| BREAK ';' {
	    $$ = ast_create_jump(ast_jump_type_break, null);
	}
	;

/// ====================================================

la_input_declaration
    : tuple_expression
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
    : la_input_declaration block_statement la_output_declaration {
        $$ = ast_create_la_declaration($1, $2, $3);
    }
    | la_input_declaration block_statement {
        $$ = ast_create_la_declaration($1, $2, null);
    }
    | block_statement la_output_declaration {
        $$ = ast_create_la_declaration(null, $1, $2);
    }
    | block_statement {
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