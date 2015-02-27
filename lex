%{
#include <stdio.h>
#include "y.tab.h"
 #include <math.h>
%}

%%

			[0-9]+.[0-9]+f
			{
				/* floats token */
                yylval = atof(yytext);
                return FLOAT;
            }
			[0-9]+.[0-9]+
			{
			/* double token */
                yylval = atof(yytext);
                return DOUBLE;
            }
			[0-9]+
    {
	            /* integer token */
                yylval = atoi(yytext);
                return INTEGER;
            }
			 /* expressions token */
			[-+*/%\n]      return *yytext;
			[&~|^!\n]      return *yytext;
			
			 /* conditions  token */
			if {return IF;}
			
			else {return ELSE;}
			
			elseif {return ELSEIF;}
			
%%
