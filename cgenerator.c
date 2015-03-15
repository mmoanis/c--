#include "y.tab.c"
#include "types.h"



/**
* Generate assembly code for a hypothitical stack based machine
* @param node in the parse tree
**/
void generate_code(Node * n)
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
        
        case CONNECTION:
        break;
        
        default:
            // no node should be typless
            return;
    }
}
