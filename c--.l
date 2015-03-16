%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
#include "symbolTable.h"
#include "uthash/uthash.h"

void variableHandler(char yytext[]);
void validate_char(char * yytext);
%}

extern int scopeLevel;
%option yylineno

_INT	     [0-9]+
_DOUBLE 	 [0-9]+\.[0-9]+|[0-9]+
_ROP         [<>]|("==")|("<=")|(">=")|("!=")
_VARIABLE    [a-zA-Z_][a-zA-Z0-9_]*
_STRING      \"([^"\\]|\\.)*\"
_CHAR        \'([^\'\\]|\\.)\'
_COMMENT     (\/\/.*\n)
_OTHERS      [:=(){};\-+*~|&^\/]

%%
true	    {return (TRUE); }

false	    {return (FALSE); }

switch      {return (SWITCH); }

case        {return (CASE); }
        
break     {return (BREAK); }

continue    {return (CONTINUE); }

default     {return (DEFAULT); }

const       {return (CONST); }


if          {return (IF); }
			
else        {return (ELSE); }
			
elsif       {return (ELSIF); }


for         {return (FOR); }
while       {return (WHILE); }
do 		    {return (DO); }

and         {return (AND);  }

or          {return (OR);   }

not         {return (NOT);  }

{_INT}	    { yylval.ival = atoi(yytext);   return (INT); }

{_DOUBLE}    { yylval.dval = atof(yytext); return (DOUBLE); }

{_STRING}    { yylval.sval = yytext; return (STRING); }

{_CHAR}      { yylval.cval = *yytext; return (CHAR); }

{_VARIABLE}  { strcpy(yylval.iname, yytext); variableHandler(yytext); return (VARIABLE); }

{_COMMENT}   {; }

{_OTHERS}   { return yytext[0];    }

[ \t\r\n]*   ;

<<EOF>>     {printf("(eof %u)\n", yylineno); return 0;}

%%

// check if the varialbe exits, or
// create a new entry in hashtable and save the reference to it
void variableHandler(char yytext[])
{
    struct symbol * temp;
    
    // look up the symbol table
    HASH_FIND_STR(symbolTable, yytext, temp);
    
    if (!temp)
    {
        // create an entry for the variable
        temp = (struct symbol*)malloc(sizeof(struct symbol));
        
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


