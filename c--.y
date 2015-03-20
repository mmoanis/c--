%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "symbolTable.h"
#include "y.tab.h"

extern int yylineno;


// pointer to hash table
struct Symbol * symbolTable = NULL;
struct Symbol * symbolTable2 = NULL;

// identify the current scope of parsing
 int scopeLevel;

int reg = 0;

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

void variableHandler(char yytext[], char isConst);

void
validate_char(char * yytext);

void make_dataSegment();

void print_hashTable();

void make_codeSegment(struct Node * tree);

/*Edited Here*/
void printTree(struct Node * n,int lvl,int from,int to,int num);
struct Node* find_variable(char * txt);
char * newstr(char * txt);// to create string 
char * scope_resolution(char *txt);
YYSTYPE Const;
int sfrom=0,sto=1;
int scopes[110][110];
int ** scope_ptr;


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

%token AOP LOP HAN3RF
%token IF SWITCH ELSE ELSIF CASE DEFAULT TRUE FALSE CONST
%token DO WHILE FOR AND OR NOT BREAK CONTINUE

%type <node_ptr> list statement assignment_statement expr assignment_expr string_expr declartion_statement stmts

%left "==" '>' '<' "!=" ">=" "<="
%left '-' '+'
%left '*' '/'
%left '|' '&'  '~'
%right '^'
%left UMINUS
	
%%
    list 
        : list statement {	 make_codeSegment($2);}
        |
        ;
    
    statement
		: assignment_statement
		| declartion_statement
		| expr ';'
		| '{' stmts '}' {$$=make_operation('s', 1, $2);}
	    ;  
	stmts:
        statement     { $$ =  $1; }
        | stmts statement        { $$ = make_operation(';', 2, $1, $2); }
        ;
   
	assignment_statement
        : VARIABLE '=' assignment_expr ';' 			
        	{variableHandler(scope_resolution($1), 0); $$=make_operation( '=', 2, make_identifier($1), $3 );}
        | CONST VARIABLE '=' assignment_expr ';'    {variableHandler($2, 1); $$=make_identifier($2);}
		;
		
	assignment_expr
		: expr 
		| string_expr 
		;
		
	string_expr
		: STRING    { (Const.sval=newstr($1)); $$=make_constant(Const,tSTRING);}
		| CHAR 		{ (Const.cval=$1); $$=make_constant(Const,tCHAR);}
		;
		
	declartion_statement
		: HAN3RF VARIABLE ';'  {variableHandler(scope_resolution($2), 0); $$=make_identifier($2);}
		;
		
	expr
		:
		INT	 
		    { (Const.ival=$1); $$=make_constant(Const,tINT);
		    }
		|
		DOUBLE  
		    { (Const.dval=$1); $$= make_constant(Const,tDOUBLE);
		    }
		|
		
		expr "==" expr  
		    {	
				$$ = make_operation( "==", 2, $1, $3 );
		    }
		|
		expr "<=" expr  
		    {	
				$$ = make_operation( "<=", 2, $1, $3 );
		    }
		|
		expr ">=" expr  
		    {	
				$$ = make_operation( ">=", 2, $1, $3 );
		    }
		|
		expr '<' expr  
		    {	
				$$ = make_operation( '<', 2, $1, $3 );
		    }
		|
		expr '>' expr  
		    {	
				$$ = make_operation( '>', 2, $1, $3 );
		    }
		|
		expr "!=" expr  
		    {	
				$$ = make_operation( "!=", 2, $1, $3 );
		    }
		|
		expr '*' expr
		    {
			    $$ = make_operation( '*', 2, $1, $3 );
		    }
		|
		expr '/' expr
		    {
			    $$ = make_operation( '/', 2, $1, $3 );
		    }
		|
		expr '+' expr
		    {
			    $$ = make_operation( '+', 2, $1, $3 );
		    }
		|
		expr '-' expr
		    {
				$$ = make_operation( '-',2, $1, $3 );
		    }
		|	 
		expr '|' expr
		    {
				$$ = make_operation( '|', 2, $1, $3 );
		    }
		|
		expr '&' expr
		    {
				$$ = make_operation( '&', 2, $1, $3 );
		    }
		|
		expr '^' expr 
		    {  
				$$ = make_operation( '^', 2, $1, $3 );
		    }
		|
		'~' expr
		    {	
				$$ = make_operation( '~', 1, $2 );
		    }
		|
		'-' expr %prec  UMINUS
		    {
				$$ = make_operation( '-', 1, $2 );
		    }	
		;

%%

char * newstr(char * txt)
{
	char *ret;
	if((ret=malloc(strlen(txt)) )== NULL)
        yyerror("out of memory");
        
	strcpy(ret,txt);
	return ret;
}
/**
* Generate assembly code for a hypothitical stack based machine
* @param node in the parse tree
**/
struct Node* find_variable(char * txt)
{
	struct Symbol * temp;
    
    // look up the symbol table
    HASH_FIND_STR(symbolTable, txt, temp);
    if(!temp)return NULL;
    struct Node* ret;
    ret->id.name=temp->name;
    return ret;

}
char * scope_resolution(char *txt)
{
	char tmp[50];
	sprintf(tmp,"_%d%d%d",sfrom,sto,scopes[sfrom][sto]);
	strcat(txt,tmp);
	return txt;
}
void printTree(struct Node * n,int lvl,int from,int to,int num)
{
	if(n==NULL)return;
	int i;
	
	for(i=0;i<lvl;i++)
	{
		printf("%3c",' ');
	}
	if(n->type==OPERATION)
	{
		if(n->opr.operation=='s')
		{
			printf("OP -> %c (%d,%d,%d)\n",n->opr.operation,from,to,scopes[from][to]);
			printTree(n->opr.op[0],lvl+1,from+1,to+1,num);
			printTree(n->opr.op[1],lvl+1,from+1,to+1,num);
			
		}
		else
		{
			printf("OP -> %c\n",n->opr.operation);
			printTree(n->opr.op[0],lvl+1,from,to,num);
			printTree(n->opr.op[1],lvl+1,from,to,num);
		}
	}
	else if(n->type==CONSTANT)
	{
		printf("const -> %d\n",n->con.ival);
	}
	else if(n->type==IDENTIFIER)
	{
		printf("identifier -> %s\n",n->id.name);
	}
}
void generate_code(struct Node * n)
{
    // check the type of the node
    switch(n->type)
    {
        
        // check the type of the operation
        case OPERATION:    
            switch(n->opr.operation)
            {
            			case ';':
	            			generate_code(n->opr.op[0]);
            				generate_code(n->opr.op[1]);
            				break;
            			case 's':
	            			if(n->opr.op[0]!=NULL)
	            			generate_code(n->opr.op[0]);
	            			if(n->opr.op[1]!=NULL)
            				generate_code(n->opr.op[1]);
            				break;
            			case '=':
            			    generate_code(n->opr.op[1]);
            			    printf("MOV %s, R%d\n", n->opr.op[0]->id.name, reg);
            				break;
            			case '*':
            				generate_code(n->opr.op[1]);
            				generate_code(n->opr.op[0]);
            				printf("MUL R%d, R%d, R%d\n", reg-1, reg, reg-1);
            				reg -= 1;
            				break;
	            		case '+':
            				generate_code(n->opr.op[1]);
            				generate_code(n->opr.op[0]);
            				printf("ADD R%d, R%d, R%d\n", reg-1, reg, reg-1);
            				reg -= 1;
            				break;
            			case '-':
            				generate_code(n->opr.op[1]);
            				generate_code(n->opr.op[0]);
            				printf("SUB R%d, R%d, R%d\n", reg-1, reg, reg-1);
            				reg -= 1;
            				break;	
            			case '/':
            				generate_code(n->opr.op[1]);
            				generate_code(n->opr.op[0]);
            				printf("DIV R%d, R%d, R%d\n", reg-1, reg, reg-1);
            				reg -= 1;
            				break;
            		    case '|':
            		        generate_code(n->opr.op[1]);
            				generate_code(n->opr.op[0]);
            				printf("OR R%d, R%d, R%d\n", reg-1, reg, reg-1);
            				reg -= 1;
            		        break;
            		    case '&':
            		        generate_code(n->opr.op[1]);
            				generate_code(n->opr.op[0]);
            				printf("AND R%d, R%d, R%d\n", reg-1, reg, reg-1);
            				reg -= 1;
            		        break;
            		    case '~':
            				generate_code(n->opr.op[0]);
            				printf("NEG R%d, R%d\n", reg-1, reg);
            				reg -= 1;
            		        break;
            		    case '^':
            		        generate_code(n->opr.op[1]);
            				generate_code(n->opr.op[0]);
            				printf("XOR R%d, R%d, R%d\n", reg-1, reg, reg-1);
            				reg -= 1;
            		    case UMINUS:
            		        break;
            }
            break;
        
        case IDENTIFIER:
            printf("MOV %s, R%d\n", n->id.name, reg);
        break;
        
        case CONSTANT:
        	switch(n->con.type)
        	{
        		case tINT:
        			reg += 1; printf("MOV R%d, %d\n",reg, n->con.ival);
        			break;
        		case tDOUBLE:
        			reg += 1; printf("MOV R%d, %a\n",reg, n->con.dval);
        			break;
        		case tCHAR:
        			reg += 1; printf("MOV R%d, '%c'\n",reg, n->con.cval);
        			break;
        	}
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
    
    n->id.name=newstr(name);
    //strcpy(n->id.name, name);
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
    n->con.type=type;// to indicate the type of the constant 
    
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
void variableHandler(char yytext[], char isConst)
{
    struct Symbol * temp;
    
    // look up the symbol table
    HASH_FIND_STR(symbolTable, yytext, temp);
    
    if (!temp)
    {
        // create an entry for the variable
        temp = ( struct Symbol*)malloc(sizeof( struct Symbol));
        
        temp->name = newstr(yytext);
        temp->isConst = isConst;
        
        // add to hashtable
        HASH_ADD_STR( symbolTable, name, temp );
    }
    else
    {
        if (temp->isConst == 1)
        {
            yyerror("attempt to assign a const variable");
        }
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


// print the symbol table as a datasegment
void make_dataSegment()
{
    
    print_hashTable();
}

void print_hashTable()
{
    struct Symbol *s;
    
    printf("\n.data\n");
    for(s=symbolTable; s != NULL; s=s->hh.next) {
        printf("%s dd ?\n", s->name);
    }
}

void make_codeSegment(struct Node * tree)
{
	
    //printTree(tree,0,0,1,0);
    generate_code(tree);
    free_node(tree);
}

int
main()
{
    memset(scopes,0,sizeof(scopes));
    printf("#c-- compiler\n");
    if (yyparse() ==0)
        make_dataSegment();
    return 0;
}

yyerror(msg)
char *msg;
{
  fprintf(stderr, "%d: %s\n", yylineno, msg);
}

int
yywrap()
{
  return(1);
}
