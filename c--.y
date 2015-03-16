%{
#include <stdio.h>
#include "y.tab.h"
#include <stdlib.h>

extern int yylineno;
%}

%start list

%token INT DOUBLE AOP LOP VARIABLE STRING CHAR COMMENT
%token IF SWITCH ELSE ELSIF CASE DEFAULT TRUE FALSE CONST
%token DO WHILE FOR AND OR NOT BREAK CONTINUE

%left "==" '>' '<' "!=" ">=" "<="
%left '-' '+'
%left '*' '/'
%left '|' '&' '^' '~'
%left UMINUS

%%

    list 
        : statement 
        | statement list 
		| statement error {yyerrok;}
        ;
    statement
        : assignment_statement
		| declartion_statement
		| expr
        ;
	expr
		: INT
		| DOUBLE 
		;
    assignment_statement
        : VARIABLE '=' assignment_expr ';'
        | CONST VARIABLE '=' assignment_expr ';'
        ;
	declartion_statement
		: VARIABLE ';' 
		;
	assignment_expr
		: expr 
		| string_expr 
		;
	string_expr
		: STRING
		| CHAR 
		;
%%

int
main() {
  return yyparse() ;
}

yyerror(s)
char *s;
{
  fprintf(stderr, "at %d: %s\n",yylineno, s);
}

yywrap()
{
  return(1);
}
