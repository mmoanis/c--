%{
#include <stdio.h>
#include "y.tab.h"
#include <stdlib.h>
#include "symbolTable.h"

// line number exported from yacc
extern int yylineno;

extern struct symbol * symbolTable;

/////////////////////////////////////////////////////////////////////////////
%}

%union {
    int ival;
    char cval;
    double dval;
    char * iname;
    char * sval;
};

%start list

%token <ival> INT
%token <dval> DOUBLE
%token <cval> CHAR
%token <sval> STRING
%token AOP LOP VARIABLE
%token IF SWITCH ELSE ELSIF CASE DEFAULT TRUE FALSE CONST
%token DO WHILE FOR AND OR NOT BREAK CONTINUE

%left "==" '>' '<' "!=" ">=" "<="
%left '-' '+'
%left '*' '/'
%left '|' '&' '^' '~'
%left UMINUS

%%

    list : 
            |
            list error  {yyerrok;}

%%

/**
* Generate assembly code for a hypothitical stack based machine
* @param node in the parse tree
**/
void generate_code(struct Node * n)
{
    // check the type of the node
    switch(n->type)
    {
        case OPERATION:
            // check the type of the operation
            //switch(n->opr.operation)
            //{
            //}
        break;
        
        case IDENTIFIER:
        break;
        
        case CONSTANT:
        break;
        
        default:
            // no node should be typless
            return;
    }
}


int
main()
{
    return yyparse() ;
}

yyerror(s)
char *s;
{
  fprintf(stderr, "at %d: %s\n",yylineno, s);
}

int
yywrap()
{
  return(1);
}
