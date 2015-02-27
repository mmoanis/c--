%{
#include <stdio.h>
#include "y.tab.h"
#include <stdlib.h>
#include <math.h>
%}

%option yylineno
%option noyywrap

ID     [A-Za-z_][A-Za-z_0-9]*
INT    -?[1-9][0-9]*
FLOAT	[0-9]+.[0-9]+f
DOUBLE 	[0-9]+.[0-9]+
NUM 	-?[0-9]*
AOP     [-+*/^=~!]
LOP     [<>]|("==")|("<=")|(>=)
yytext 


%%
/* float token */
float
{	
/*yylval = atof(yytext);*/
return FLOAT;
}

/* double token */
double
{	
/*yylval = atof(yytext);*/
return DOUBLE;
}

/* integer token */
int
{
/* yylval = atoi(yytext);*/
return INT;
}

AOP
return *yytext;

 /* conditions  token */
if {return IF;}
			
else {return ELSE;}
			
elseif {return ELSEIF;}
	/*loop statement*/
for     {printf(">>>>>>>>(for \"%s\" %u)\n", yytext, yylineno);}
while 	{printf(">>>>>>>>>>(while \"%s\" %u)\n", yytext, yylineno);}
do 		{printf(">>>>>>>>(do  \"%s\" %u)\n", yytext, yylineno);}
whiledo   {printf(">>>>>>>>(whiledo \"%s\" %u)\n", yytext, yylineno);}


 /* Print delimiters. */
[(]         {printf("(left-parenthesis %u)\n", yylineno);}
[)]         {printf("(right-parenthesis %u)\n", yylineno);}
[;]         {printf("(semicolon %u)\n", yylineno);}

 /* Print identifiers, integers and operators. */

{INT}       {printf("(int %s %u)\n",yytext, yylineno);}
{NUM}       {printf("(number %s %u)\n",yytext, yylineno);}
{ID}        {printf("(id \"%s\" %u)\n", yytext, yylineno);}
{AOP}        {printf("(op \"%s\" %u)\n", yytext, yylineno);}


 /* Ignore comments and whitespace. */
#[^\n]*     {}
[ \t\r\n]   {}

<<EOF>>     {printf("(eof %u)\n", yylineno); return 0;}

%%

int main(int argc, char* argv[]) {
  yylex() ;
  return EXIT_SUCCESS ;
}

