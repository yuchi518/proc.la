%option yylineno

BIN                     [0-1]
OCT_1st                 [0-3]
OCT                     [0-7]
HEX                     [a-fA-F0-9]
DIG                     [0-9]
DIG_NZ                  [1-9]
EXP_D                   ([Ee][+-]?{DIG}+)
LETTER                  [a-zA-Z_]
ASCII                   [a-zA-Z_0-9]
ESCAPE                  (\\(['"\?\\abfnrtv]))
WS                      [ \t\v\n\f]

%{

#include <stdio.h>
//#include "y.tab.h"
#include "proc.la.y.c"

extern void yyerror(const char *);  /* prints grammar violation message */

extern int sym_type(const char *);  /* returns type from symbol table */

#define sym_type(identifier) IDENTIFIER /* with no symbol table, fake it */

static void comment(void);
static int check_type(void);
static void log_verb(char* title, int is_char);

struct src_stack
{
    struct src_stack *prev;
    YY_BUFFER_STATE bs;
    //int lineno;
    //char* src_buffer;
    //unsigned int src_size;
};

%}


%%

"/*"                                                    { comment(); }
"//".*                                                  { /*log_verb("CMD", 0);*/ /* consume //-comment */ }

"int"					                                { yylval = la_ast_create_type(ast_type_int); return(INT); }
"long"					                                { yylval = la_ast_create_type(ast_type_long); return(LONG); }
"float"					                                { yylval = la_ast_create_type(ast_type_float); return(FLOAT); }
"double"				                                { yylval = la_ast_create_type(ast_type_double); return(DOUBLE); }
"num"                                                   { yylval = la_ast_create_type(ast_type_number); return(NUMBER); }
"string"                                                { yylval = la_ast_create_type(ast_type_string); return(STRING); }
"raw"                                                   { yylval = la_ast_create_type(ast_type_raw); return(RAW); }
"var"                                                   { yylval = la_ast_create_type(ast_type_var); return(VAR); }
"proc"                                                  { yylval = la_ast_create_type(ast_type_proc); return(PROC); }
"la"                                                    { yylval = la_ast_create_type(ast_type_la); return(LA); }
"none"                                                  { yylval = la_ast_create_none(); return N_CONSTANT; }

"out"                                                   { yylval = la_ast_create_ctrl(ast_ctrl_type_out); return OUT; }
"is"                                                    { yylval = la_ast_create_ctrl(ast_ctrl_type_is); return IS; }
"declare"                                               { yylval = la_ast_create_ctrl(ast_ctrl_type_declare); return DECLARE; }
"sync"                                                  { yylval = la_ast_create_ctrl(ast_ctrl_type_sync); return SYNC; }

({LETTER}{ASCII}*)("."{LETTER}{ASCII}*)+                { yylval = la_ast_create_domain(yytext); return DOMAIN_NAME; }
(@{LETTER}{ASCII}*)("."{LETTER}{ASCII}*)*               { yylval = la_ast_create_package(yytext); return PACKAGE_NAME; }

{LETTER}{ASCII}*					                    { yylval = la_ast_create_identifier(yytext); return IDENTIFIER/*check_type()*/; }

([bB]\()({BIN}{BIN}{BIN}{BIN}{BIN}{BIN}{BIN}{BIN})+\)   { yylval = la_ast_create_const_i(yytext); return I_CONSTANT; }
([oO]\()({OCT_1st}{OCT}{OCT})+\)                        { yylval = la_ast_create_const_i(yytext); return I_CONSTANT; }
([hH]\()({HEX}{HEX})+\)                                 { yylval = la_ast_create_const_i(yytext); return I_CONSTANT; }
{DIG_NZ}{DIG}*				                            { yylval = la_ast_create_const_i(yytext); return I_CONSTANT; }
"'"([^'\\\n]|{ESCAPE})+"'"		                        { yylval = la_ast_create_const_i(yytext); return I_CONSTANT; }

{DIG}+{EXP_D}				                            { yylval = la_ast_create_const_f(yytext); return F_CONSTANT; }
{DIG}*"."{DIG}+{EXP_D}?			                        { yylval = la_ast_create_const_f(yytext); return F_CONSTANT; }
{DIG}+"."{EXP_D}?			                            { yylval = la_ast_create_const_f(yytext); return F_CONSTANT; }

(\"([^"\\\n]|{ESCAPE})*\"{WS}*)+	                    { yylval = la_ast_create_const_s(yytext); return STRING_LITERAL; }

">>="					                                { return RIGHT_ASSIGN; }
"<<="					                                { return LEFT_ASSIGN; }
"+="					                                { return ADD_ASSIGN; }
"-="					                                { return SUB_ASSIGN; }
"*="					                                { return MUL_ASSIGN; }
"/="					                                { return DIV_ASSIGN; }
"%="					                                { return MOD_ASSIGN; }
"&="					                                { return AND_ASSIGN; }
"^="					                                { return XOR_ASSIGN; }
"|="					                                { return OR_ASSIGN; }
">>"					                                { return RIGHT_OP; }
"<<"					                                { return LEFT_OP; }
"++"					                                { return INC_OP; }
"--"					                                { return DEC_OP; }
"&&"					                                { return AND_OP; }
"||"					                                { return OR_OP; }
"<="					                                { return LE_OP; }
">="					                                { return GE_OP; }
"=="					                                { return EQ_OP; }
"!="					                                { return NE_OP; }
";"					                                    { return ';'; }
"{"				                                        { return '{'; }
"}"				                                        { return '}'; }
","					                                    { return ','; }
":"					                                    { return ':'; }
"->"					                                { return APPLY_TO; }
"-->"                                                   { return PIPE_1_TO_1; }
"=->"                                                   { return PIPE_REDUCE; }
"-*>"                                                   { return PIPE_EXPAND; }
"*->"                                                   { return PIPE_INJECT; }
"="					                                    { return '='; }
"("					                                    { return '('; }
")"					                                    { return ')'; }
("["|"<:")				                                { return '['; }
("]"|":>")				                                { return ']'; }
"."					                                    { return '.'; }
"&"					                                    { return '&'; }
"!"					                                    { return '!'; }
"~"					                                    { return '~'; }
"-"					                                    { return '-'; }
"+"					                                    { return '+'; }
"*"					                                    { return '*'; }
"/"					                                    { return '/'; }
"%"					                                    { return '%'; }
"<"					                                    { return '<'; }
">"					                                    { return '>'; }
"^"					                                    { return '^'; }
"|"					                                    { return '|'; }
"?"					                                    { return '?'; }

{WS}+					                                { /* whitespace separates tokens */ }
.					                                    { fprintf(stderr, "Bad character: %c\n", *yytext); /* discard bad characters */ }

%%

int yywrap(void)        /* called at end of input */
{
    return 1;           /* terminate now */
}

static void comment(void)
{
    int c;
    //fprintf(stderr, "CMT %c\n", *yytext);

    while ((c = input()) != 0)
    {
        //putc(c, stdout);
        if (c == '*')
        {
             while ((c = input()) == '*')
                 ;

             if (c == '/')
                 return;

             if (c == 0)
                 break;
        }
    }
    yyerror("unterminated comment");
}

static int check_type(void)
{
    log_verb("ID", 0);
    //fprintf(stderr, "check_type %s\n", yytext);
     //switch (sym_type(yytext))
     //{
     //default:                          /* includes undefined */
         return IDENTIFIER;
     //}
}

static void log_verb(char* title, int is_char)
{
    if (is_char)
        fprintf(stderr, "%s: %c\n", title, *yytext);
    else
        fprintf(stderr, "%s: %s\n", title, yytext);
}