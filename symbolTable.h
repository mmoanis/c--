#ifndef _SYMBOL_
#define _SYMBOL_
#include "uthash/uthash.h"


// types of nodes in parse tree
typedef enum 
{
    OPERATION, 
    IDENTIFIER, 
    CONSTANT
} nodeType;

// types of a varialbe in the language
typedef enum
{
    tINT,
    tDOUBLE,
    tSTRING,
    tCHAR
} variableType;


// constant value
typedef struct {
    union
    {
        int ival;
        double dval;
        char cval;
        char * sval;
    };
} constantNodeType;

// identifier
typedef struct {
int i;
} identifierNodeType;

// operations
typedef struct {
    int operation;
    int noOfOperands;
    struct nodeTypeTag *op[1];
} operationNodeType;

// a node in the parse tree.
struct Node 
{
        nodeType type;  // the type of the node

        // data inside the node
        union {
            constantNodeType con;
            identifierNodeType id;
            operationNodeType opr;
        };
        
} ;

// entry in hash table, which keeps a key of type string
struct symbol
{
    //int scope;          /* identify scope with numbers */
    char * name;        // name of the varialbe and the key in the hash table
    variableType type;     /* identify the type of the variable*/
    YYSTYPE value;      // yystype should be a union
    UT_hash_handle hh;  /* makes this structure hashable, leave as it is!!! */
} ;


// pointer to hash table
struct symbol * symbolTable = NULL;

// identify the current scope of parsing
int scopeLevel;


#endif
