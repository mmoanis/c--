%{
#include <stdio.h>
//#include "y.tab.h"
#include <stdlib.h>
#include <math.h>
%}

%option yylineno
%option noyywrap

INT	    [0-9]+
DOUBLE 	    [0-9]+\.[0-9]+|[0-9]+
AOP         [-+*/^=~!]
LOP         [<>]|("==")|("<=")|(">=")|("!=")
VARIABLE    [a-zA-Z_][a-zA-Z0-9_]*
STRING      \"([^"\\]|\\.)*\"
CHAR        \'([^\'\\]|\\.)\'
COMMENT     (\/\/.*\n)

%%
true	    {printf("(true %u)\n", yylineno);}

false	    {printf("(false %u)\n", yylineno);}

switch      {printf("(switch %u)\n", yylineno);}

case        {printf("(case %u)\n", yylineno);}
        
break       {printf("(break %u)\n", yylineno);}

default     {printf("(default %u)\n", yylineno);}

const       {printf("(if %u)\n", yylineno);}


if          {printf("(if %u)\n", yylineno);}
			
else        {printf("(else %u)\n", yylineno);}
			
elsif       {printf("(elsif %u)\n", yylineno);}


for         {printf("(for %u)\n", yylineno);}
while       {printf("(while %u)\n", yylineno);}
do 		    {printf("(do %u)\n", yylineno);}

{INT}	    {printf("(int \"%s\" %u)\n", yytext, yylineno);}

{DOUBLE}    {printf("(double \"%s\" %u)\n", yytext, yylineno);}


{STRING}    {printf("(string \"%s\" %u)\n", yytext, yylineno);}

{CHAR}      {printf("(char \"%s\" %u)\n", yytext, yylineno);}

{VARIABLE}  {printf("(variable \"%s\" %u)\n", yytext, yylineno);}

{COMMENT}   {printf("(comment \"%s\" %u)\n", yytext, yylineno);}

[ \t\r\n]*   ;






<<EOF>>     {printf("(eof %u)\n", yylineno); return 0;}

%%

int main(int argc, char* argv[]) {
  yylex() ;
  return EXIT_SUCCESS ;
}

