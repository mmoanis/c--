%{
#include <stdio.h>
#include "y.tab.h"
#include <stdlib.h>
#include <math.h>
%}

%option yylineno
%option noyywrap

FLOAT	    [0-9]+.[0-9]+f
DOUBLE 	    [0-9]+.[0-9]+
INT 	    [-+]?[0-9]+
AOP         [-+*/^=~!]
LOP         [<>]|("==")|("<=")|(">=")|("!=")
VARIABLE    [a-zA-Z_][a-zA-Z0-9_]*
STRING      \"([^"\\]|\\.)*\"
CHAR        \'([^\'\\]|\\.)\'
COMMENT     (\/\/.*\n)

%%
switch  
{
	/* switch token */
	printf("switch: %s\n", yytext);
	return (SWITCH);
}

case    
{
	/* case token */  
	printf("case\n");
	return (CASE);
}
        
break   
{
	/* break token */
	printf("break\n");
	return (BREAK);
}

default     
{
	/* default token */
	printf("default\n");
	return (DEFAULT);
}

const
{
    printf("constant\n");
    return (CONST);
}

/* conditions  token */
if {
    printf(">>>>>>>>(if \"%s\" %u)\n", yytext, yylineno);
    return IF;
}
			
else 
{
    printf(">>>>>>>>(else \"%s\" %u)\n", yytext, yylineno);
    return ELSE;
}
			
elsif 
{
    printf(">>>>>>>>(elsif \"%s\" %u)\n", yytext, yylineno);
    return ELSIF;
}

/*loop statement*/
for     {printf(">>>>>>>>(for \"%s\" %u)\n", yytext, yylineno);}
while 	{printf(">>>>>>>>>>(while \"%s\" %u)\n", yytext, yylineno);}
do 		{printf(">>>>>>>>(do  \"%s\" %u)\n", yytext, yylineno);}
whiledo   {printf(">>>>>>>>(whiledo \"%s\" %u)\n", yytext, yylineno);}

INT
{
	/* integer token */
	/* yylval = atoi(yytext);*/
	return INT;
}

FLOAT
{
	/* float token */
	/*yylval = atof(yytext);*/
	return FLOAT;
}


DOUBLE
{
	/* double token */
	/*yylval = atof(yytext);*/
	return DOUBLE;
}

STRING   
{
	/* string token */
	printf("stringo: %s\n", yytext);
	return (STRING);
}

CHAR  
{
	/* char token */
	
	// dummie statments
	//if (yytext[1] == '\\')   {
		//yytext[1] = yytext[2] = '\'';
		//yytext[3] = '\0';
	//}            
	printf("charo: %s\n", yytext);
	return (CHAR);
}

VARIABLE  
{
	/* variable token */
	printf("varo: %s\n", yytext);
	return (VARIABLE);
}


AOP
	return *yytext;

 /* Print delimiters. */
[(]         {printf("(left-bracket %u)\n", yylineno);}
[)]         {printf("(right-bracket %u)\n", yylineno);}
[{]         {printf("(left-parenthesis %u)\n", yylineno);}
[}]         {printf("(right-parenthesis %u)\n", yylineno);}
[;]         {printf("(semicolon %u)\n", yylineno);}

 /* Print identifiers, integers and operators. */

{INT}       {printf("(int %s %u)\n",yytext, yylineno);}
{AOP}        {printf("(op \"%s\" %u)\n", yytext, yylineno);}


 /* Ignore comments and whitespace. */
 COMMENT    
{
	/* comment tokens*/
	printf("commento: %s\n", yytext);
}
[ \t\r\n]*   ;



<<EOF>>     {printf("(eof %u)\n", yylineno); return 0;}

%%

int main(int argc, char* argv[]) {
  yylex() ;
  return EXIT_SUCCESS ;
}

