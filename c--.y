%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "symbolTable.h"
#include "y.tab.h"
// pointer to hash table
struct Symbol * symbolTable = NULL;

// identify the current scope of parsing
int scopeLevel;


// perform a dfs to the parse tree to generate machine code
void generate_code(struct Node * n);

/// functions to build the parse tree

// handle a varialbe usage
struct Node * make_identifier(char name[]);

// handle a const usage
struct Node * make_constant(YYSTYPE value, VariableType type);

// handle an operation
struct Node * make_operation(int operation, int nOfOperands, ... );

void free_node(struct Node * n);

void variableHandler(char yytext[]);

void
validate_char(char * yytext);

/////////////////////////////////////////////////////////////////////////////
%}

%union {
    int ival;
    char cval;
    double dval;
    struct Node * node_ptr;
    char * iname;
    char * sval;
};

%start list

%token <ival> INT
%token <dval> DOUBLE
%token <cval> CHAR
%token <sval> STRING
%token <iname> VARIABLE

%token AOP LOP
%token IF SWITCH ELSE ELSIF CASE DEFAULT TRUE FALSE CONST
%token DO WHILE FOR AND OR NOT BREAK CONTINUE

%type <node_ptr> list statement

%left "==" '>' '<' "!=" ">=" "<="
%left '-' '+'
%left '*' '/'
%left '|' '&' '^' '~'
%left UMINUS

%%

    list : 
         | statement list
         | list error  {yyerrok;}
         ;
    
    statement
        : INT {make_constant( (YYSTYPE)$1, tINT);  }
        | DOUBLE {make_constant( (YYSTYPE)$1, tDOUBLE);  }
        ;

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

// handle a varialbe usage
struct Node * make_identifier(char name[])
{
    struct Node *n;
    size_t nodeSize;
    
    /* allocate node */
    nodeSize = SIZEOF_NODETYPE + sizeof(IdentifierNodeType);
    
    if ((n = (struct Node * )malloc(nodeSize)) == NULL)
        yyerror("out of memory");
        
    /* copy information */
    n->type = IDENTIFIER;
    strcpy(n->id.name, name);
    return n;
}

// handle a const usage
struct Node * make_constant(YYSTYPE value, VariableType type)
{
    struct Node * n;
    size_t nodeSize;
    
    /* allocate node */
    nodeSize = SIZEOF_NODETYPE + sizeof(ConstantNodeType);
    
    
    if ((n = (struct Node *)malloc(nodeSize)) == NULL)
        return NULL;
        
    /* copy information */
    n->type = CONSTANT;
    
    switch (type)
    {
        case tINT:
            n->con.ival = value.ival;
            break;
        
        case tDOUBLE:
            n->con.dval = value.dval;
            break;
        
        case tSTRING:
            strcpy(n->con.sval, value.sval);
            break;
        
        case tCHAR:
            n->con.cval = value.cval;
            break;
        
        default:
            return NULL;
    }
    
    
    return n;
}

// handle an operation
struct Node * make_operation(int operation, int nOfOperands, ... )
{
    va_list ap;
    struct Node *n;
    size_t nodeSize;
    
    int i;
    
    /* allocate node */
    nodeSize = SIZEOF_NODETYPE + sizeof(OperationNodeType) + (nOfOperands - 1) * sizeof(struct Node*);
    
    if ((n = malloc(nodeSize)) == NULL)
        yyerror("out of memory");
        
    /* copy information */
    n->type = OPERATION;
    n->opr.operation = operation;
    n->opr.noOfOperands = nOfOperands;
    
    va_start(ap, nOfOperands);
    for (i = 0; i < nOfOperands; i++)
        n->opr.op[i] = va_arg(ap, struct Node*);
    va_end(ap);
    
    return n;
}

void free_node(struct Node * n)
{
    int i;
    
    if (!n) return;
    
    if (n->type == OPERATION) 
    {
        for (i = 0; i < n->opr.noOfOperands; i++)
        free_node(n->opr.op[i]);
    }
    
    free (n);
}

// check if the varialbe exits, or
// create a new entry in hashtable and save the reference to it
void variableHandler(char yytext[])
{
    struct Symbol * temp;
    
    // look up the symbol table
    HASH_FIND_STR(symbolTable, yytext, temp);
    
    if (!temp)
    {
        // create an entry for the variable
        temp = ( struct Symbol*)malloc(sizeof( struct Symbol));
        
        strcpy(temp->name, yytext);
        
        // add to hashtable
        HASH_ADD_STR( symbolTable, name, temp );
    }
}

// TODO: not sure if we need this
void
validate_char(char * yytext)
{
    if (strlen(yytext) > 3)
    {
        yytext[1] = yytext[2];
        yytext[2] = '\'';
        yytext[3] = '\0';
    }
}




int
main()
{
    // TODO: I think after doing yyparse, we should call the generate_code()
    // and iterate over the symbolTable to make all variables say in a datasegment
    return yyparse() ;
}

yyerror(msg)
char *msg;
{
  fprintf(stderr, "at %s\n", msg);
}

int
yywrap()
{
  return(1);
}
