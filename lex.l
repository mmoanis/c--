%{
#include <stdio.h>
#include "y.tab.h"
%}

%%


switch  {
            /* switch token */
            printf("switch: %s\n", yytext);
            return (SWITCH);
        }


          
case    {
            /* case token */  
            printf("case\n");
            return (CASE);
        }
        
break   {
            /* break token */
            printf("break\n");
            return (BREAK);
        }
 

default     {
                /* default token */
                printf("default\n");
                return (DEFAULT);
            }
            

\"[^"]*\"    {
                            /* string token */
                            printf("stringo: %s\n", yytext);
                            return (STRING);
             }

'[^']'  {
                /* char token */
                
                // dummie statments
                if (yytext[1] == '\\')   {
                    yytext[1] = yytext[2] = '\'';
                    yytext[3] = '\0';
                }
                    
                printf("charo: %s\n", yytext);
                return (STRING);
            }

[/][/]|[/][*]|[*][/]    {
                            /* comment tokens*/
                            printf("commento: %s\n", yytext);
                            return (COMMENT);
                        }
 

[a-zA-Z_][a-zA-Z0-9_]*  {
                            /* variable token */
                            printf("varo: %s\n", yytext);
                            return (VARIABLE);
                        }
                        
[ \t\n]+ ;

%%
