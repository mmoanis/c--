
#include "uthash/uthash.h"


#define SIZEOF_NODETYPE ((char *)&n->con - (char *)n)

// types of nodes in parse tree
typedef enum 
{
    OPERATION, 
    IDENTIFIER, 
    CONSTANT
} NodeType;

// types of a varialbe in the language
typedef enum 
{
    tINT = 0,
    tDOUBLE,
    tSTRING,
    tCHAR
} VariableType;

// constant value
typedef struct {
    union
    {
        int ival;
        double dval;
        char cval;
        char * sval; 
    };
    VariableType type;
} ConstantNodeType;

// identifier
typedef struct {
    char usage; //1 assigned to, 2 used
    char * name;    // name of the identifier, ie the key
} IdentifierNodeType;

// operations
typedef struct {
    int operation;  // operation
    int noOfOperands;   // no. of operands
    struct Node *op[2];  // operands
} OperationNodeType;

// a node in the parse tree.
struct Node 
{
        NodeType type;  // the type of the node

        // data inside the node
        union {
            ConstantNodeType con;
            IdentifierNodeType id;
            OperationNodeType opr;
        };
        
} ;

// entry in hash table, which keeps a key of type string
struct Symbol
{
    //int scope;          /* identify scope with numbers */
    char isConst;
    char * name;        // name of the varialbe and the key in the hash table
    VariableType type;     /* identify the type of the variable*/
    ConstantNodeType value;      // yystype should be a union
    UT_hash_handle hh;  /* makes this structure hashable, leave as it is!!! */
} ;


