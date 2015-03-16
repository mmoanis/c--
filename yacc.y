%{
#include <stdio.h>
#include "y.tab.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>
%}


%start expr

%token INT DOUBLE AOP LOP ROP VARIABLE STRING CHAR COMMENT 
%token IF SWITCH ELSE ELSIF CASE DEFAULT TRUE FALSE CONST
%token DO WHILE FOR AND OR NOT BREAK CONTINUE

%left "==" '>' '<' "!=" ">=" "<="
%left '-' '+'
%left '*' '/'
%left '|' '&' '^' '~'
%left UMINUS
	
%%
expr:

        INT	 { $$ = $1; printf ("yacc:int "); }
    |
         DOUBLE   { $$ = $1; printf ("yacc:double");}
    |
	
	 expr "==" expr  
	{$$ == $1 ;
		 printf ("yacc:equal equal ");}
	|
        expr '*' expr
         {

           $$ = $1 * $3;
		    printf ("yacc:times");
          }
   |
        expr '/' expr
         {
           $$ = $1 / $3;
		    printf ("yacc:divide");
         }
	|
	  PLUS  expr '+' expr
         {
           $$ = $1 + $3;
		    printf ("yacc:plus");
         }
	|
         expr '-' expr
         {
           $$ = $1 - $3;
		    printf ("yacc:minus");
         }
	|	 
        expr '|' expr
         {
           $$ = $1 | $3;
		    printf ("yacc:or");
         }
	|
	    expr '&' expr
         {
           $$ = $1 & $3;
		    printf ("yacc:and");
         }
	|
	    expr '^' expr      
	 { $$ = pow($1, $3);
		 printf ("yacc:power");}
	 
	|
	 
	 '~' expr
	 { $$ = ~ $2;
	  printf ("yacc:not");}
	|
    '-' expr  UMINUS
         {
           $$ = -$2;
		    printf ("yacc:negative");
         }	
	
	;
%%
main()
{
return (yyparse());
}
yyerror(s)
char *s;
{
  fprintf(stderr, "%s\n",s);
}
