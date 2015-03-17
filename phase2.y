%{
#include <stdio.h>
//#include "y.tab.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>
%}
%token INT	
%token DOUBLE 	
%%
expr:

 INT	 { $$ = $1; }
 DOUBLE   { $$ = $1; }
 
%%

yyerror(s)
char *s;
{
  fprintf(stderr, "%s\n",s);
}
