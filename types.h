#include "y.tab.c"

typedef enum {
    OPERATION, 
    IDENTIFIER, 
    CONNECTION
} nodeType;

// TODO: fix the constants, variables, operators.
/* constants */
typedef struct {
    int value;
} conNodeType;

/* identifiers */
typedef struct {
int i;
} idNodeType;

/* operators */
typedef struct {
    int operation;
    int noOfOperands;
    struct nodeTypeTag *op[1];
} oprNodeType;

// a node in the parse tree.
typedef struct nodeTypeTag {
        nodeEnum type;  // the type of the node

        // data inside the node
        union {
            conNodeType con;
            idNodeType id;
            oprNodeType opr;
        };
        
} Node;

//extern YYSTYPE sym[26];
