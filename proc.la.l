
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
#include "y.tab.h"

extern void yyerror(const char *);  /* prints grammar violation message */

extern int sym_type(const char *);  /* returns type from symbol table */

#define sym_type(identifier) IDENTIFIER /* with no symbol table, fake it */

static void comment(void);
static int check_type(void);

%}

%%
"/*"                                                    { comment(); }
"//".*                                                  { /* consume //-comment */ }

"int"					                                { return(INT); }
"long"					                                { return(LONG); }
"float"					                                { return(FLOAT); }
"double"				                                { return(DOUBLE); }
"num"                                                   { return(NUMBER); }
"string"                                                { return(STRING); }
"raw"                                                   { return(RAW); }
"var"                                                   { return(VAR); }
"proc"                                                  { return(PROC); }
"la"                                                    { return(LA); }

{LETTER}{ASCII}*					                    { return check_type(); }

([bB]\()({BIN}{BIN}{BIN}{BIN}{BIN}{BIN}{BIN}{BIN})+\)   { return I_CONSTANT; }
([oO]\()({OCT_1st}{OCT}{OCT})+\)                        { return I_CONSTANT; }
([hH]\()({HEX}{HEX})+\)                                 { return I_CONSTANT; }
{DIG_NZ}{DIG}*				                            { return I_CONSTANT; }
"'"([^'\\\n]|{ESCAPE})+"'"		                        { return I_CONSTANT; }

{DIG}+{EXP_D}				                            { return F_CONSTANT; }
{DIG}*"."{DIG}+{EXP_D}?			                        { return F_CONSTANT; }
{DIG}+"."{EXP_D}?			                            { return F_CONSTANT; }

(\"([^"\\\n]|{ESCAPE})*\"{WS}*)+	                    { return STRING_LITERAL; }

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
"->"					                                { return PTR_OP; }
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
.					                                    { /* discard bad characters */ }

%%

int yywrap(void)        /* called at end of input */
{
    return 1;           /* terminate now */
}

static void comment(void)
{
    int c;

    while ((c = input()) != 0)
    if (c == '*')
    {
         while ((c = input()) == '*')
             ;

         if (c == '/')
             return;

         if (c == 0)
             break;
    }
    yyerror("unterminated comment");
}

static int check_type(void)
{
     switch (sym_type(yytext))
     {
     default:                          /* includes undefined */
         return IDENTIFIER;
     }
}