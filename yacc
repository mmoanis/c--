%{
#include <stdio.h>
#include "y.tab.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>

extern int yylineno;
extern char * yytext;
%}


%start list

%token INT DOUBLE  LOP ROP VARIABLE STRING CHAR COMMENT 
%token IF SWITCH ELSE ELSIF CASE DEFAULT TRUE FALSE CONST
%token DO WHILE FOR AND OR NOT BREAK CONTINUE

%left "==" '>' '<' "!=" ">=" "<="
%left '-' '+'
%left '*' '/'
%left '|' '&'  '~'
%right '^'
%left UMINUS
	
%%


list
    : statement
    | statement list
    ;

statement
    : expr ';'
    | ';'
    ;    

expr:
    INT	 { $$ = $1; printf ("yacc:int \n"); }
    |
    DOUBLE  { $$ = $1; printf ("yacc:double\n");}
    |

    expr "==" expr  
    {$$ == $1 ;
    printf ("yacc:equal equal\n");}
    |
    expr '*' expr
    {

    $$ = $1 * $3;
    printf ("yacc:times\n");
    }
    |
    expr '/' expr
    {
    $$ = $1 / $3;
    printf ("yacc:divide\n");
    }
    |
    expr '+' expr
    {
    $$ = $1 + $3;
    printf ("yacc:plus\n");
    }
    |
    expr '-' expr
    {
    $$ = $1 - $3;
    printf ("yacc:minus\n");
    }
    |	 
    expr '|' expr
    {
    $$ = $1 | $3;
    printf ("yacc:or\n");
    }
    |
    expr '&' expr
    {
    $$ = $1 & $3;
    printf ("yacc:and\n");
    }
    |
    expr '^' expr 
    {  
    printf ("yacc:power\n");}

    |

    '~' expr
    { $$ = ~ $2;
    printf ("yacc:not\n");}
    |
    '-' expr  UMINUS
    {
    $$ = -$2;
    printf ("yacc:negative\n");
    }	
	
	;
%%

main()
{
    #if YYDEBUG
        yydebug = 1;
    #endif
    return (yyparse());
}
yyerror(s)
char *s;
{
  fprintf(stderr, "%s at %d: %s\n", yytext, yylineno, s);
}
