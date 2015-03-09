%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
%}

%option yylineno

_INT	     [0-9]+
_DOUBLE 	 [0-9]+\.[0-9]+|[0-9]+
_AOP         [-+*/=~]
_LOP         [|&^]
_ROP         [<>]|("==")|("<=")|(">=")|("!=")
_VARIABLE    [a-zA-Z_][a-zA-Z0-9_]*
_STRING      \"([^"\\]|\\.)*\"
_CHAR        \'([^\'\\]|\\.)\'
_COMMENT     (\/\/.*\n)

%%
true	    {return (TRUE); }

false	    {return (FALSE); }

switch      {return (SWITCH); }

case        {return (CASE); }
        
break       {return (BREAK); }

continue    {return (CONTINUE)}; 

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

{_INT}	    {return (INT); }

{_DOUBLE}    {return (DOUBLE); }


{_STRING}    {return (STRING); }

{_CHAR}      {return (CHAR); }

{_VARIABLE}  {return (VARIABLE); }

{_COMMENT}   {return (COMMENT); }

[ \t\r\n]*   ;






<<EOF>>     {printf("(eof %u)\n", yylineno); return 0;}

%%

