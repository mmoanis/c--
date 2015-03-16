#include "uthash/uthash.h"
#include "y.tab.c"


struct Table
{
    int scope;          /* identify scope with numbers */
    YYSTYPE value;
    UT_hash_handle hh;  /* makes this structure hashable */
};
