/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "c--.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "symbolTable.h"
#include "y.tab.h"

// line number in input file
extern int yylineno;


// pointer to hash table
struct Symbol * symbolTable = NULL;
struct Symbol * symbolTable2 = NULL;

// identify the current scope of parsing
int scopeLevel;

// current available register to use in generate_code()
// its the resposnibility of the user to increment or decrement
// the value of the available register
int reg = 0;

// given a node, generate the code according to the parse tree
// -n tree head
void generate_code(struct Node * n);

// makes a variable node in the parse tree, use it in grammer rules
// when the rule refers to a variable. The node created will especify
// how the asembly code will be generated according to the usage of the
// variable
//
// -name: name of the varialbe to be stored in the node
// -used: 1 if the variable is read, 0 if its assigned
//
// returns: node pointer to a variable node
struct Node * make_identifier(char name[], char used);

// makes a const value node in the parse tree, use it in grammer rules
// when the rule refers to a variable. The node created will especify
// how the asembly code will be generated according to the type of const
//
// -value: actual value of variable
// -type: type of variable
//
// returns: node pointer to a const node
struct Node * make_constant(YYSTYPE value, VariableType type);

// makes an operation node in the parse tree, use in grammer rules
// when the rule refers to an operation. Also you can make special
// operations for statement_lists to treat them differently. The
// node created will especify how the asembly code will be generated
// according to the type of operation.
//
// -operation: operation number, use operation ASCII or Enums from lexxer
// -nOfOperands: number of operands to specify the size of variable argument list
// -argument list: arguments of the operations, must be same number of nOfOperands
//
// returns: node pointer to an operation
struct Node * make_operation(int operation, int nOfOperands, ... );

// free the tree of nodes
//
// -n: tree root
void free_node(struct Node * n);

// creates or checks the existance of variables in symbol table.
// this function will raise yyerrors in case of variable error.
// variable could be new one to be added, const variable used,
// undeclared variable, or reference to a global variable (see issue#13)
//
// -yytext: variable name, call scope_handler(yytext) first to resolve variable scope
// -isConst: 1 if variable is const
// - def: 0 if variable is assigned, 1 if its decleration of variable or
//      2 if variable is read
//
// notes: see issue#13
void variableHandler(char yytext[], char isConst, char def);

// read char data from a string
// eg: "'4'" = '4'
char validate_char(char * yytext);

// print the variables in symbol table to the output stream
void make_dataSegment();

// missing documentation!
void print_hashTable();

// print the equivalent assembly code of a given parse tree
//
// -tree: parse tree root
void make_codeSegment(struct Node * tree);

// missing documentation!
void printTree(struct Node * n,int lvl,int from,int to,int num);

// safe way to assign a char sequence another to the value of other one
//
// -txt: char sequence to be copied
//
// returns: char sequence with same value as txt
char * newstr(char * txt);

// resolve the scope of a give  by prefixing its name with its scope
// information
//
// -txt: variable name
//
// returns: new variable name that specifies its scope information
char * scope_resolution(char *txt);

// const value holder
YYSTYPE Const;


int sfrom=0,sto=1;
int scopes[110][110];
int ** scope_ptr;

int labl=0, labll=0;
int llbl,loop_lbl=0;
int brn_lbl=0;
// make sure only 1 default at maximum appears in switch body
int default_walker=-1, number_default[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

typedef enum {EQ, BQ, LQ, NQ} logicalOp;
#define IF_ELSE 213123
/////////////////////////////////////////////////////////////////////////////

#line 198 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    DOUBLE = 259,
    CHAR = 260,
    STRING = 261,
    VARIABLE = 262,
    AOP = 263,
    LOP = 264,
    HAN3RF = 265,
    IF = 266,
    SWITCH = 267,
    ELSE = 268,
    ELSIF = 269,
    CASE = 270,
    DEFAULT = 271,
    TRUE = 272,
    FALSE = 273,
    CONST = 274,
    DO = 275,
    WHILE = 276,
    FOR = 277,
    AND = 278,
    OR = 279,
    NOT = 280,
    BREAK = 281,
    CONTINUE = 282,
    LQ_T = 283,
    BQ_T = 284,
    EQ_T = 285,
    NQ_T = 286,
    UMINUS = 291
  };
#endif
/* Tokens.  */
#define INT 258
#define DOUBLE 259
#define CHAR 260
#define STRING 261
#define VARIABLE 262
#define AOP 263
#define LOP 264
#define HAN3RF 265
#define IF 266
#define SWITCH 267
#define ELSE 268
#define ELSIF 269
#define CASE 270
#define DEFAULT 271
#define TRUE 272
#define FALSE 273
#define CONST 274
#define DO 275
#define WHILE 276
#define FOR 277
#define AND 278
#define OR 279
#define NOT 280
#define BREAK 281
#define CONTINUE 282
#define LQ_T 283
#define BQ_T 284
#define EQ_T 285
#define NQ_T 286
#define UMINUS 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 133 "c--.y" /* yacc.c:355  */

    int ival;
    char cval;
    double dval;
    struct Node * node_ptr;
    char * iname;
    char * sval;

#line 311 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 326 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   307

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  145

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    43,     2,
      48,    49,    40,    39,     2,    38,     2,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    53,    47,
      34,    50,    33,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    45,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,    42,    52,    44,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    35,    36,
      37,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   168,   168,   169,   173,   174,   175,   176,   177,   178,
     179,   183,   184,   185,   188,   191,   194,   197,   198,   199,
     203,   205,   206,   211,   212,   219,   220,   224,   225,   229,
     230,   234,   238,   239,   243,   247,   248,   252,   254,   255,
     260,   261,   265,   266,   267,   268,   269,   273,   277,   282,
     284,   288,   292,   297,   302,   307,   312,   317,   322,   327,
     332,   337,   342,   347,   352,   357,   362,   367,   372
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "DOUBLE", "CHAR", "STRING",
  "VARIABLE", "AOP", "LOP", "HAN3RF", "IF", "SWITCH", "ELSE", "ELSIF",
  "CASE", "DEFAULT", "TRUE", "FALSE", "CONST", "DO", "WHILE", "FOR", "AND",
  "OR", "NOT", "BREAK", "CONTINUE", "LQ_T", "BQ_T", "EQ_T", "NQ_T",
  "\"==\"", "'>'", "'<'", "\"!=\"", "\">=\"", "\"<=\"", "'-'", "'+'",
  "'*'", "'/'", "'|'", "'&'", "'~'", "'^'", "UMINUS", "';'", "'('", "')'",
  "'='", "'{'", "'}'", "':'", "$accept", "list", "statement",
  "loop_statement", "for_statement", "while_statement", "do_statement",
  "opexpr", "assignment_statement2", "if_statement",
  "switch_body_statement", "case_list_statement", "case_statement",
  "parantasis_statement", "statement_list", "control_statement",
  "jump_statement", "assignment_statement", "assignment_expr",
  "const_value", "string_expr", "declartion_statement", "expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,    62,    60,   288,   289,   290,    45,    43,
      42,    47,   124,    38,   126,    94,   291,    59,    40,    41,
      61,   123,   125,    58
};
# endif

#define YYPACT_NINF -105

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-105)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -105,   104,  -105,  -105,  -105,  -105,   -47,    -2,   -38,   -33,
      12,   166,   -13,     4,    95,    95,    95,   166,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,   218,    74,
     -20,    13,    46,     9,    33,    13,    13,  -105,   106,   116,
     196,  -105,   146,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,  -105,  -105,    11,  -105,
     238,  -105,    74,    15,    53,    60,    19,  -105,   238,    21,
      74,    23,    27,    35,  -105,  -105,  -105,   238,   238,   238,
     238,   256,   256,   262,   262,    44,    44,   116,   116,   116,
    -105,    36,    74,    40,    42,   166,    18,    48,    13,   166,
      13,  -105,  -105,    74,    74,    88,     8,    50,    34,  -105,
    -105,  -105,    56,  -105,    63,  -105,  -105,   166,  -105,  -105,
    -105,  -105,     8,    64,   166,    10,  -105,  -105,    13,  -105,
      70,   166,   101,  -105,  -105,    79,  -105,   101,  -105,    83,
     166,    84,  -105,  -105,  -105
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,    50,    51,    52,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     9,
      11,    12,    13,    10,     7,     6,     4,     5,     0,     0,
       0,    19,     0,     0,     0,    19,    19,    49,    67,    66,
       0,    32,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     8,    47,     0,    41,
      40,    48,     0,    49,     0,     0,     0,    17,    18,     0,
       0,     0,     0,     0,    68,    31,    33,    55,    56,    53,
      54,    58,    57,    62,    61,    59,    60,    63,    64,    65,
      37,     0,     0,     0,     0,     0,     0,     0,    19,     0,
      19,    39,    20,     0,     0,    23,     0,     0,     0,    34,
      25,    38,     0,    15,     0,    22,    21,     0,    43,    46,
      45,    44,     0,     0,     0,     0,    27,    16,    19,    24,
       0,     0,    36,    26,    28,     0,    42,    36,    35,     0,
       0,     0,    30,    14,    29
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -105,  -105,   -11,  -105,  -105,  -105,  -105,   -34,  -105,  -105,
    -105,  -105,  -104,  -105,  -105,  -105,    -5,  -105,   119,    16,
    -105,  -105,    -7
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    18,    19,    20,    21,    22,    66,    67,    23,
     109,   125,   110,    24,    42,    25,   139,    26,    58,   123,
      59,    27,    28
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      34,    72,    73,    29,   126,    30,    41,    38,    39,    40,
      31,   118,   119,   120,   121,    32,     3,     4,     5,    33,
      63,   134,    60,    64,    68,   106,   107,    61,    68,    68,
      62,    76,    65,   106,   107,    35,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,   106,
     107,    14,    36,    69,    71,    60,   122,    15,    90,    70,
      93,    16,   133,    60,   112,    92,   114,    94,    95,   108,
      96,    98,    43,    44,    45,    46,    99,     3,     4,     5,
      57,    37,   100,   101,   105,    60,    53,    54,   113,    55,
     103,    68,   104,    68,   135,   111,    60,    60,     3,     4,
       5,   117,    37,   124,     2,   127,   129,     3,     4,     5,
     128,     6,    14,   132,     7,     8,     9,   131,    15,   136,
     137,    68,    16,    10,    11,    12,    13,   138,   140,   143,
     142,   144,   141,    14,    43,    44,    45,    46,   130,    15,
       0,     0,    14,    16,    43,    44,    45,    46,    15,     3,
       4,     5,    16,     6,     0,    17,     7,     8,     9,     0,
       0,    55,     0,     0,     0,    10,    11,    12,    13,     3,
       4,     5,     0,     6,     0,     0,     7,     8,     9,     0,
       0,    91,     0,     0,    14,    10,    11,    12,    13,    97,
      15,     0,     0,     0,    16,     0,     0,    17,    75,     0,
       0,     0,     0,     0,    14,     0,     0,     0,     0,     0,
      15,   102,     0,     0,    16,     0,     0,    17,     0,     0,
       0,     0,   115,   116,    43,    44,    45,    46,     0,    47,
      48,     0,     0,     0,    49,    50,    51,    52,    53,    54,
       0,    55,     0,     0,     0,    74,    43,    44,    45,    46,
       0,    47,    48,     0,     0,     0,    49,    50,    51,    52,
      53,    54,     0,    55,     0,    56,    43,    44,    45,    46,
       0,    47,    48,     0,     0,     0,    49,    50,    51,    52,
      53,    54,     0,    55,    43,    44,    45,    46,     0,     0,
      43,    44,    45,    46,    49,    50,    51,    52,    53,    54,
       0,    55,    51,    52,    53,    54,     0,    55
};

static const yytype_int16 yycheck[] =
{
      11,    35,    36,    50,   108,     7,    17,    14,    15,    16,
      48,     3,     4,     5,     6,    48,     3,     4,     5,     7,
       7,   125,    29,    10,    31,    15,    16,    47,    35,    36,
      50,    42,    19,    15,    16,    48,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    15,
      16,    38,    48,     7,    21,    62,    48,    44,    47,    50,
       7,    48,    52,    70,    98,    50,   100,     7,    49,    51,
      49,    48,    28,    29,    30,    31,    49,     3,     4,     5,
       6,     7,    47,    47,    95,    92,    42,    43,    99,    45,
      50,    98,    50,   100,   128,    47,   103,   104,     3,     4,
       5,    13,     7,    53,     0,    49,   117,     3,     4,     5,
      47,     7,    38,   124,    10,    11,    12,    53,    44,    49,
     131,   128,    48,    19,    20,    21,    22,    26,    49,   140,
      47,    47,   137,    38,    28,    29,    30,    31,   122,    44,
      -1,    -1,    38,    48,    28,    29,    30,    31,    44,     3,
       4,     5,    48,     7,    -1,    51,    10,    11,    12,    -1,
      -1,    45,    -1,    -1,    -1,    19,    20,    21,    22,     3,
       4,     5,    -1,     7,    -1,    -1,    10,    11,    12,    -1,
      -1,    62,    -1,    -1,    38,    19,    20,    21,    22,    70,
      44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      44,    92,    -1,    -1,    48,    -1,    -1,    51,    -1,    -1,
      -1,    -1,   103,   104,    28,    29,    30,    31,    -1,    33,
      34,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      -1,    45,    -1,    -1,    -1,    49,    28,    29,    30,    31,
      -1,    33,    34,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    -1,    45,    -1,    47,    28,    29,    30,    31,
      -1,    33,    34,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    -1,    45,    28,    29,    30,    31,    -1,    -1,
      28,    29,    30,    31,    38,    39,    40,    41,    42,    43,
      -1,    45,    40,    41,    42,    43,    -1,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    55,     0,     3,     4,     5,     7,    10,    11,    12,
      19,    20,    21,    22,    38,    44,    48,    51,    56,    57,
      58,    59,    60,    63,    67,    69,    71,    75,    76,    50,
       7,    48,    48,     7,    56,    48,    48,     7,    76,    76,
      76,    56,    68,    28,    29,    30,    31,    33,    34,    38,
      39,    40,    41,    42,    43,    45,    47,     6,    72,    74,
      76,    47,    50,     7,    10,    19,    61,    62,    76,     7,
      50,    21,    61,    61,    49,    52,    56,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      47,    72,    50,     7,     7,    49,    49,    72,    48,    49,
      47,    47,    72,    50,    50,    56,    15,    16,    51,    64,
      66,    47,    61,    56,    61,    72,    72,    13,     3,     4,
       5,     6,    48,    73,    53,    65,    66,    49,    47,    56,
      73,    53,    56,    52,    66,    61,    49,    56,    26,    70,
      49,    70,    47,    56,    47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    55,    56,    56,    56,    56,    56,    56,
      56,    57,    57,    57,    58,    59,    60,    61,    61,    61,
      62,    62,    62,    63,    63,    64,    64,    65,    65,    66,
      66,    67,    68,    68,    69,    70,    70,    71,    71,    71,
      72,    72,    73,    73,    73,    73,    73,    74,    75,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     9,     5,     6,     1,     1,     0,
       3,     4,     4,     5,     7,     1,     3,     1,     2,     6,
       5,     3,     1,     2,     5,     1,     0,     4,     5,     5,
       1,     1,     3,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 168 "c--.y" /* yacc.c:1646  */
    {	 make_codeSegment((yyvsp[0].node_ptr));}
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 169 "c--.y" /* yacc.c:1646  */
    {(yyval.node_ptr)=NULL;}
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 173 "c--.y" /* yacc.c:1646  */
    {(yyval.node_ptr)=(yyvsp[0].node_ptr);}
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 174 "c--.y" /* yacc.c:1646  */
    {(yyval.node_ptr)=(yyvsp[0].node_ptr);}
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 175 "c--.y" /* yacc.c:1646  */
    {(yyval.node_ptr)=(yyvsp[0].node_ptr);}
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 176 "c--.y" /* yacc.c:1646  */
    {(yyval.node_ptr)=(yyvsp[0].node_ptr);}
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 177 "c--.y" /* yacc.c:1646  */
    {(yyval.node_ptr)=(yyvsp[-1].node_ptr);}
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 178 "c--.y" /* yacc.c:1646  */
    {(yyval.node_ptr)=(yyvsp[0].node_ptr);}
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 179 "c--.y" /* yacc.c:1646  */
    {(yyval.node_ptr)=(yyvsp[0].node_ptr);}
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 183 "c--.y" /* yacc.c:1646  */
    {(yyval.node_ptr)=(yyvsp[0].node_ptr);}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 184 "c--.y" /* yacc.c:1646  */
    {(yyval.node_ptr)=(yyvsp[0].node_ptr);}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 185 "c--.y" /* yacc.c:1646  */
    {(yyval.node_ptr)=(yyvsp[0].node_ptr);}
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 188 "c--.y" /* yacc.c:1646  */
    {  (yyval.node_ptr) = make_operation(FOR, 4, (yyvsp[-6].node_ptr), (yyvsp[-4].node_ptr),(yyvsp[-2].node_ptr),(yyvsp[0].node_ptr) );}
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 191 "c--.y" /* yacc.c:1646  */
    {(yyval.node_ptr) = make_operation(WHILE, 2, (yyvsp[-2].node_ptr), (yyvsp[0].node_ptr) );}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 194 "c--.y" /* yacc.c:1646  */
    {(yyval.node_ptr)=make_operation(DO, 2, (yyvsp[-4].node_ptr), (yyvsp[-1].node_ptr) );}
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 197 "c--.y" /* yacc.c:1646  */
    {(yyval.node_ptr)=(yyvsp[0].node_ptr);}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 198 "c--.y" /* yacc.c:1646  */
    {(yyval.node_ptr)=(yyvsp[0].node_ptr);}
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 199 "c--.y" /* yacc.c:1646  */
    {(yyval.node_ptr)=NULL;}
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 204 "c--.y" /* yacc.c:1646  */
    {variableHandler(scope_resolution((yyvsp[-2].iname)), 0, 0); (yyval.node_ptr)=make_operation( '=', 2, make_identifier((yyvsp[-2].iname), 0), (yyvsp[0].node_ptr) );}
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 205 "c--.y" /* yacc.c:1646  */
    {variableHandler(scope_resolution((yyvsp[-2].iname)), 1, 1); (yyval.node_ptr)=make_operation( '=', 2, make_identifier((yyvsp[-2].iname), 0), (yyvsp[0].node_ptr) );}
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 206 "c--.y" /* yacc.c:1646  */
    {variableHandler(scope_resolution((yyvsp[-2].iname)), 0, 1); (yyval.node_ptr)=make_operation( '=', 2, make_identifier((yyvsp[-2].iname), 0), (yyvsp[0].node_ptr) );}
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 211 "c--.y" /* yacc.c:1646  */
    {(yyval.node_ptr)=make_operation(IF, 2, (yyvsp[-2].node_ptr), (yyvsp[0].node_ptr) );}
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 212 "c--.y" /* yacc.c:1646  */
    {(yyval.node_ptr)=make_operation(IF_ELSE, 3, (yyvsp[-4].node_ptr), (yyvsp[-2].node_ptr),(yyvsp[0].node_ptr) );}
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 219 "c--.y" /* yacc.c:1646  */
    {(yyval.node_ptr)=(yyvsp[0].node_ptr);}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 220 "c--.y" /* yacc.c:1646  */
    {(yyval.node_ptr)=(yyvsp[-1].node_ptr);}
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 224 "c--.y" /* yacc.c:1646  */
    {(yyval.node_ptr) = (yyvsp[0].node_ptr);}
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 225 "c--.y" /* yacc.c:1646  */
    {(yyval.node_ptr) = make_operation('c', 2, (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 229 "c--.y" /* yacc.c:1646  */
    {   (yyval.node_ptr) = make_operation(CASE, 3, (yyvsp[-4].node_ptr), (yyvsp[-2].node_ptr), (yyvsp[-1].node_ptr));  }
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 230 "c--.y" /* yacc.c:1646  */
    {   (yyval.node_ptr) = make_operation(DEFAULT, 2, (yyvsp[-2].node_ptr), (yyvsp[-1].node_ptr));  }
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 234 "c--.y" /* yacc.c:1646  */
    {(yyval.node_ptr)=(yyvsp[-1].node_ptr);}
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 238 "c--.y" /* yacc.c:1646  */
    {(yyval.node_ptr)=(yyvsp[0].node_ptr);}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 239 "c--.y" /* yacc.c:1646  */
    {(yyval.node_ptr)=make_operation('s', 2, (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 243 "c--.y" /* yacc.c:1646  */
    { variableHandler(scope_resolution((yyvsp[-2].iname)), 0, 2);  (yyval.node_ptr) = make_operation(SWITCH, 2, make_identifier((yyvsp[-2].iname), 1), (yyvsp[0].node_ptr) );   }
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 247 "c--.y" /* yacc.c:1646  */
    {   (yyval.node_ptr) = make_operation(BREAK, 0);  }
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 248 "c--.y" /* yacc.c:1646  */
    {(yyval.node_ptr)=NULL;}
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 253 "c--.y" /* yacc.c:1646  */
    {variableHandler(scope_resolution((yyvsp[-3].iname)), 0, 0); (yyval.node_ptr)=make_operation( '=', 2, make_identifier((yyvsp[-3].iname), 0), (yyvsp[-1].node_ptr) );}
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 254 "c--.y" /* yacc.c:1646  */
    {variableHandler(scope_resolution((yyvsp[-3].iname)), 1, 1); (yyval.node_ptr)=make_operation( '=', 2, make_identifier((yyvsp[-3].iname), 0), (yyvsp[-1].node_ptr) );}
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 255 "c--.y" /* yacc.c:1646  */
    {variableHandler(scope_resolution((yyvsp[-3].iname)), 0, 1); (yyval.node_ptr)=make_operation( '=', 2, make_identifier((yyvsp[-3].iname), 0), (yyvsp[-1].node_ptr) );}
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 260 "c--.y" /* yacc.c:1646  */
    {(yyval.node_ptr)=(yyvsp[0].node_ptr);}
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 261 "c--.y" /* yacc.c:1646  */
    {(yyval.node_ptr)=(yyvsp[0].node_ptr);}
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 265 "c--.y" /* yacc.c:1646  */
    { (yyval.node_ptr) = (yyvsp[-1].node_ptr);}
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 266 "c--.y" /* yacc.c:1646  */
    { (Const.ival=(yyvsp[0].ival)); (yyval.node_ptr)=make_constant(Const,tINT);}
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 267 "c--.y" /* yacc.c:1646  */
    { (Const.sval=newstr((yyvsp[0].sval))); (yyval.node_ptr)=make_constant(Const,tSTRING);}
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 268 "c--.y" /* yacc.c:1646  */
    { (Const.cval=(yyvsp[0].cval)); (yyval.node_ptr)=make_constant(Const,tCHAR);}
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 269 "c--.y" /* yacc.c:1646  */
    { (Const.dval=(yyvsp[0].dval)); (yyval.node_ptr)= make_constant(Const,tDOUBLE);}
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 273 "c--.y" /* yacc.c:1646  */
    { (Const.sval=newstr((yyvsp[0].sval))); (yyval.node_ptr)=make_constant(Const,tSTRING);}
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 277 "c--.y" /* yacc.c:1646  */
    {variableHandler(scope_resolution((yyvsp[-1].iname)), 0, 1);(yyval.node_ptr)=NULL;}
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 282 "c--.y" /* yacc.c:1646  */
    {variableHandler(scope_resolution((yyvsp[0].iname)), 0, 2); (yyval.node_ptr)=make_identifier((yyvsp[0].iname), 1);}
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 285 "c--.y" /* yacc.c:1646  */
    { (Const.ival=(yyvsp[0].ival)); (yyval.node_ptr)=make_constant(Const,tINT);
		    }
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 289 "c--.y" /* yacc.c:1646  */
    { (Const.dval=(yyvsp[0].dval)); (yyval.node_ptr)= make_constant(Const,tDOUBLE);
		    }
#line 1831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 293 "c--.y" /* yacc.c:1646  */
    {
		    { (Const.cval=(yyvsp[0].cval)); (yyval.node_ptr)=make_constant(Const,tCHAR);}
		}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 298 "c--.y" /* yacc.c:1646  */
    {
				(yyval.node_ptr) = make_operation( EQ, 2, (yyvsp[-2].node_ptr), (yyvsp[0].node_ptr) );
		    }
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 303 "c--.y" /* yacc.c:1646  */
    {
				(yyval.node_ptr) = make_operation( NQ, 2, (yyvsp[-2].node_ptr), (yyvsp[0].node_ptr) );
		    }
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 308 "c--.y" /* yacc.c:1646  */
    {
				(yyval.node_ptr) = make_operation( LQ, 2, (yyvsp[-2].node_ptr), (yyvsp[0].node_ptr) );
		    }
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 313 "c--.y" /* yacc.c:1646  */
    {
				(yyval.node_ptr) = make_operation( BQ, 2, (yyvsp[-2].node_ptr), (yyvsp[0].node_ptr) );
		    }
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 318 "c--.y" /* yacc.c:1646  */
    {
				(yyval.node_ptr) = make_operation( '<', 2, (yyvsp[-2].node_ptr), (yyvsp[0].node_ptr) );
		    }
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 323 "c--.y" /* yacc.c:1646  */
    {
				(yyval.node_ptr) = make_operation( '>', 2, (yyvsp[-2].node_ptr), (yyvsp[0].node_ptr) );
		    }
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 328 "c--.y" /* yacc.c:1646  */
    {
			    (yyval.node_ptr) = make_operation( '*', 2, (yyvsp[-2].node_ptr), (yyvsp[0].node_ptr) );
		    }
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 333 "c--.y" /* yacc.c:1646  */
    {
			    (yyval.node_ptr) = make_operation( '/', 2, (yyvsp[-2].node_ptr), (yyvsp[0].node_ptr) );
		    }
#line 1903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 338 "c--.y" /* yacc.c:1646  */
    {
			    (yyval.node_ptr) = make_operation( '+', 2, (yyvsp[-2].node_ptr), (yyvsp[0].node_ptr) );
		    }
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 343 "c--.y" /* yacc.c:1646  */
    {
				(yyval.node_ptr) = make_operation( '-',2, (yyvsp[-2].node_ptr), (yyvsp[0].node_ptr) );
		    }
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 348 "c--.y" /* yacc.c:1646  */
    {
				(yyval.node_ptr) = make_operation( '|', 2, (yyvsp[-2].node_ptr), (yyvsp[0].node_ptr) );
		    }
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 353 "c--.y" /* yacc.c:1646  */
    {
				(yyval.node_ptr) = make_operation( '&', 2, (yyvsp[-2].node_ptr), (yyvsp[0].node_ptr) );
		    }
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 358 "c--.y" /* yacc.c:1646  */
    {
				(yyval.node_ptr) = make_operation( '^', 2, (yyvsp[-2].node_ptr), (yyvsp[0].node_ptr) );
		    }
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 363 "c--.y" /* yacc.c:1646  */
    {
				(yyval.node_ptr) = make_operation( '~', 1, (yyvsp[0].node_ptr) );
		    }
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 368 "c--.y" /* yacc.c:1646  */
    {
				(yyval.node_ptr) = make_operation( '-', 1, (yyvsp[0].node_ptr) );
		    }
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 373 "c--.y" /* yacc.c:1646  */
    {
           (yyval.node_ptr) = (yyvsp[-1].node_ptr);
         }
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1971 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 378 "c--.y" /* yacc.c:1906  */



// allocate new string
char * newstr(char * txt)
{
	char *ret;
	if((ret=malloc(strlen(txt)) )== NULL)
        yyerror("out of memory");

	strcpy(ret,txt);
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
    if (n == NULL) return;  // in case there is no tree

    int ca, labl2;
    int clbl;
    // check the type of the node
    switch(n->type)
    {

        // check the type of the operation
        case OPERATION:
            switch(n->opr.operation)
            {
                    case FOR:
                    	//sfrom++;sto++;++scopes[sfrom][sto];
                    	llbl=++loop_lbl;
                    	clbl=llbl;
                    	printf("#=====init=======\n");
                    	generate_code(n->opr.op[0]);
                    	printf("looplable_%d:\n",clbl);
                    	printf("#-----cond-----\n");
                    	generate_code(n->opr.op[1]);
                    	if(n->opr.op[1]!=NULL)// da law fe condition 
                    	{
                    		char cond[4];
                    		if(n->opr.op[1]->opr.operation=='<')
                    		printf("JBQ Endloop_lable_%d\n",clbl);
                    		if(n->opr.op[1]->opr.operation=='>')
                    		printf("JLQ Endloop_lable_%d\n",clbl);
                    		if(n->opr.op[1]->opr.operation==BQ)
                    		printf("JL Endloop_lable_%d\n",clbl);
                    		if(n->opr.op[1]->opr.operation==LQ)
                    		printf("JB Endloop_lable_%d\n",clbl);
                    		if(n->opr.op[1]->opr.operation==EQ)
                    		printf("JNQ Endloop_lable_%d\n",clbl);
                    		if(n->opr.op[1]->opr.operation==NQ)
                    		printf("JEQ Endloop_lable_%d\n",clbl);
                    		//printf("%s Endloop_lable_%d\n",cond,llbl);
                    	}
                    	
                    	printf("#-----statement-----\n");
                    	generate_code(n->opr.op[3]);
                    	printf("#-----step-----\n");
                    	generate_code(n->opr.op[2]);
                    	printf("JMP looplable_%d\n",clbl);
                    	printf("#=====end=======\n");
                    	printf("Endloop_lable_%d:\n",clbl);
                    	//sfrom--;sto--;
                    	break;
                    case WHILE:
                    	//sfrom++;sto++;++scopes[sfrom][sto];
                    	llbl=++loop_lbl;
                    	clbl=llbl;
                    	printf("#=====cond=======\n");
                    	
                    	printf("looplable_%d:\n",clbl);
                    	
                    	generate_code(n->opr.op[0]);
                    	if(n->opr.op[0]!=NULL)// da law fe condition 
                    	{
                    		char cond[4];
                    		if(n->opr.op[0]->opr.operation=='>')
                    		printf("JLQ Endloop_lable_%d\n",clbl);
                    		if(n->opr.op[0]->opr.operation=='<')
                    		printf("JBQ Endloop_lable_%d\n",clbl);
                    		
                    		if(n->opr.op[0]->opr.operation==BQ)
                    		printf("JL Endloop_lable_%d\n",clbl);
                    		if(n->opr.op[0]->opr.operation==LQ)
                    		printf("JB Endloop_lable_%d\n",clbl);
                    		if(n->opr.op[0]->opr.operation==EQ)
                    		printf("JNQ Endloop_lable_%d\n",clbl);
                    		if(n->opr.op[0]->opr.operation==NQ)
                    		printf("JEQ Endloop_lable_%d\n",clbl);
                    		//printf("%s Endloop_lable_%d\n",cond,llbl);
                    	}
                    	
                    	printf("#-----statement-----\n");
                    	generate_code(n->opr.op[1]);
                    	printf("JMP looplable_%d\n",clbl);
                    	printf("#=====end=======\n");
                    	printf("Endloop_lable_%d:\n",clbl);
                    	//sfrom--;sto--;
                    	break;
                    
                    case DO:
                    	//sfrom++;sto++;++scopes[sfrom][sto];
                    	llbl=++loop_lbl;
                    	clbl=llbl;
                    	printf("#===============\n");
                    	
                    	printf("looplable_%d:\n",clbl);
                    	printf("#-----statement-----\n");
                    	generate_code(n->opr.op[0]);
                    	printf("#-----cond-----\n");
                    	generate_code(n->opr.op[1]);
                    	if(n->opr.op[1]!=NULL)// da law fe condition 
                    	{
                    		char cond[4];
                    		if(n->opr.op[1]->opr.operation=='>')
                    		printf("JB loop_lable_%d\n",clbl);
                    		if(n->opr.op[1]->opr.operation=='<')
                    		printf("JL loop_lable_%d\n",clbl);
                    		
                    		if(n->opr.op[1]->opr.operation==BQ)
                    		printf("JBQ loop_lable_%d\n",clbl);
                    		if(n->opr.op[1]->opr.operation==LQ)
                    		printf("JLQ loop_lable_%d\n",clbl);
                    		if(n->opr.op[1]->opr.operation==EQ)
                    		printf("JEQ loop_lable_%d\n",clbl);
                    		if(n->opr.op[1]->opr.operation==NQ)
                    		printf("JNQ loop_lable_%d\n",clbl);
                    		//printf("%s Endloop_lable_%d\n",cond,llbl);
                    	}
                    	
                    	
                    	//printf("JMP looplable_%d\n",clbl);
                    	printf("#=====end=======\n");
                    	printf("Endloop_lable_%d:\n",clbl);
                    	//sfrom--;sto--;
                    	break;
                    
                    case IF_ELSE:
                    	clbl=++brn_lbl;
                    	printf("#-----cond-----\n");
                    	generate_code(n->opr.op[0]);
                    	if(n->opr.op[0]!=NULL)// da law fe condition 
                    	{
                    		char cond[4];
                    		if(n->opr.op[0]->opr.operation=='>')
                    		printf("JLQ branch_lable_%d\n",clbl);
                    		if(n->opr.op[0]->opr.operation=='<')
                    		printf("JBQ branch_lable_%d\n",clbl);
                    		
                    		if(n->opr.op[0]->opr.operation==BQ)
                    		printf("JL branch_lable_%d\n",clbl);
                    		if(n->opr.op[0]->opr.operation==LQ)
                    		printf("JB branch_lable_%d\n",clbl);
                    		if(n->opr.op[0]->opr.operation==EQ)
                    		printf("JNQ branch_lable_%d\n",clbl);
                    		if(n->opr.op[0]->opr.operation==NQ)
                    		printf("JEQ branch_lable_%d\n",clbl);
                    		//printf("%s Endloop_lable_%d\n",cond,llbl);
                    	}
                    	printf("#-----statement----\n");
                    	generate_code(n->opr.op[1]);
                    	printf("JMP End_branch_lable_%d:\n",clbl);
                    	printf("branch_lable_%d:\n",clbl);
                    	printf("#-----else statement----\n");
                    	generate_code(n->opr.op[2]);
                    	printf("End_branch_lable_%d:\n",clbl);
                    	
                    	break;
                    case IF:
                    	clbl=++brn_lbl;
                    	printf("#-----cond-----\n");
                    	generate_code(n->opr.op[0]);
                    	if(n->opr.op[0]!=NULL)// da law fe condition 
                    	{
                    		char cond[4];
                    		if(n->opr.op[0]->opr.operation=='>')
                    		printf("JLQ branch_lable_%d\n",clbl);
                    		if(n->opr.op[0]->opr.operation=='<')
                    		printf("JBQ branch_lable_%d\n",clbl);
                    		
                    		if(n->opr.op[0]->opr.operation==BQ)
                    		printf("JL branch_lable_%d\n",clbl);
                    		if(n->opr.op[0]->opr.operation==LQ)
                    		printf("JB branch_lable_%d\n",clbl);
                    		if(n->opr.op[0]->opr.operation==EQ)
                    		printf("JNQ branch_lable_%d\n",clbl);
                    		if(n->opr.op[0]->opr.operation==NQ)
                    		printf("JEQ branch_lable_%d\n",clbl);
                    		//printf("%s Endloop_lable_%d\n",cond,llbl);
                    	}
                    	printf("#-----statement----\n");
                    	generate_code(n->opr.op[1]);
                    	printf("branch_lable_%d:\n",clbl);
                    	
                    	break;
                    	
                    
                    case '<'://logical operation assum CMP saving in register FLAGS E,G,L,GE,LE => "==",">","<", ..
                    	generate_code(n->opr.op[1]);
        				generate_code(n->opr.op[0]);
        				printf("CMP R%d, R%d\n", reg, reg-1);
        				reg -= 2;
                    	break;
                    case '>'://logical operation assum CMP saving in register FLAGS E,G,L,GE,LE => "==",">","<", ..
                    	generate_code(n->opr.op[1]);
        				generate_code(n->opr.op[0]);
        				printf("CMP R%d, R%d\n", reg, reg-1);
        				reg -= 2;
                    	break;
                   	case EQ://logical operation assum CMP saving in register FLAGS E,G,L,GE,LE => "==",">","<", ..
                    	generate_code(n->opr.op[1]);
        				generate_code(n->opr.op[0]);
        				printf("CMP R%d, R%d\n", reg, reg-1);
        				reg -= 2;
                    	break;
                    case BQ://logical operation assum CMP saving in register FLAGS E,G,L,GE,LE => "==",">","<", ..
                    	generate_code(n->opr.op[1]);
        				generate_code(n->opr.op[0]);
        				printf("CMP R%d, R%d\n", reg-1, reg);
        				reg -= 2;
                    	break;
                    case LQ://logical operation assum CMP saving in register FLAGS E,G,L,GE,LE => "==",">","<", ..
                    	generate_code(n->opr.op[1]);
        				generate_code(n->opr.op[0]);
        				printf("CMP R%d, R%d\n", reg, reg-1);
        				reg -= 2;
                    	break;
                    case NQ://logical operation assum CMP saving in register FLAGS E,G,L,GE,LE => "==",">","<", ..
                    	generate_code(n->opr.op[1]);
        				generate_code(n->opr.op[0]);
        				printf("CMP R%d, R%d\n", reg, reg-1);
        				reg -= 2;
                    	break;
                    	
                    	
                    case SWITCH:
                        default_walker++;
                        // move the switch variable to a register
                        generate_code(n->opr.op[0]);
                        labll++;

                        // generate the switch body
                        generate_code(n->opr.op[1]);

                        // label the end of the switch statement
                        printf("switch_labl%d:\n", labll--);

                        // check the number of defualt statements that appeared
                        // in the switch body
                        if (number_default[default_walker] > 1)
                        {
                            yyerror("multiple default labels in one switch");
                        }

                        default_walker--;

                        reg -= 1;
                        break;
                    case CASE:
                        generate_code(n->opr.op[1]);
                        if (n->opr.op[2] != NULL)
                            generate_code(n->opr.op[2]);
                        break;

                    case DEFAULT:
                        number_default[default_walker] += 1;

                        generate_code(n->opr.op[0]);
                        if (n->opr.op[1] != NULL)
                            generate_code(n->opr.op[1]);
                        break;
                    case BREAK:
                        printf("JMP switch_labl%d\n", labll);
                        break;

                    case 'c':
                        // case statement special operations
                        // that connect list of case statements that follows
                        // each other. Goal here is to make all conditions first
                        // then followed by the body of the case statements

                        // generate the code of case statements conditions first
                        for (ca = 0; ca <2; ca++)
                            if (n->opr.op[ca]->opr.op[0] != NULL && n->opr.op[ca]->type == OPERATION && n->opr.op[ca]->opr.operation == CASE)
                            {
                                
                                generate_code(n->opr.op[ca]->opr.op[0]);
                                // compare it
                                printf("CMP R%d, R%d\n", reg-1, reg);
                                printf("JE case_labl%d\n", labl2 = labl++);
                                reg -= 1;
                            }
                            else if (n->opr.op[ca]->opr.op[0] != NULL && n->opr.op[ca]->type == OPERATION && n->opr.op[ca]->opr.operation == DEFAULT)
                            {
                                printf("JMP case_labl%d\n", labl2 = labl++);
                                labl++;
                            }

                        // generate the code of case statements body
                        for (ca = 1; ca >=0; ca--)
                            if (n->opr.op[ca] != NULL )
                            {
                                printf("case_labl%d:\n", labl2--);
                                generate_code(n->opr.op[ca]);
                            }


                        break;
                    // dummy operation for joining to statements together
                    // see statement_list grammer
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
        				break;
        		    case UMINUS:
        		        generate_code(n->opr.op[0]);
        				printf("NEG R%d, R%d\n", reg-1, reg);
        				reg -= 1;
        		        break;

            }
            break;

        case IDENTIFIER:
            if (n->id.usage == 1)
            {   reg+=1; printf("MOV R%d, %s\n", reg, n->id.name);   }
            else
            printf("MOV %s, R%d\n", n->id.name, reg);
        break;

        case CONSTANT:
        	switch(n->con.type)
        	{
        		case tINT:
        			reg += 1; printf("MOV R%d, %d\n",reg, n->con.ival);
        			break;
        		case tDOUBLE:
        			reg += 1; printf("MOV R%d, %f\n",reg, n->con.dval);
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
// @param used either 1 or 0, 1 if the variable is read, 0 if its assigned
struct Node * make_identifier(char name[], char used)
{
    struct Node *n;
    size_t nodeSize;

    /* allocate node */
    nodeSize = SIZEOF_NODETYPE + sizeof(IdentifierNodeType);

    if ((n = (struct Node * )malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    /* copy information */
    n->type = IDENTIFIER;

    if (used == 1)   n->id.usage = 1;
    else n->id.usage = 0;

    n->id.name=newstr(name);
    //strcpy(n->id.name, name);
    return n;
}

// handle a const usage
// @param value actual value of the const, use the 'Const' varialbe to allocate it
// @param type of the variable
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

// free the memory occupied by a given tree
void free_node(struct Node * n)
{
    if (!n) return;

    int i;
    if (n->type == OPERATION)
    {
        for (i = 0; i < n->opr.noOfOperands; i++)
        free_node(n->opr.op[i]);
    }

    free (n);
}

// check if the varialbe exits, or
// create a new entry in hashtable and save the reference to it
void variableHandler(char yytext[], char isConst, char def)
{
    struct Symbol * temp;

    // look up the symbol table
    HASH_FIND_STR(symbolTable, yytext, temp);

    if (!temp && def == 1)
    {
        // create an entry for the variable
        temp = ( struct Symbol*)malloc(sizeof( struct Symbol));

        temp->name = newstr(yytext);
        temp->isConst = isConst;

        // add to hashtable
        HASH_ADD_STR( symbolTable, name, temp );
    }
    else if (!temp && def != 1)
    {
        // check for a more global defination

        int length = strlen(yytext);
        char * global = newstr(yytext);
        global[length-1] = '0';
        global[length-2] = '1';
        global[length-3] = '0';

        // look up the symbol table
        HASH_FIND_STR(symbolTable, global, temp);
        //yyerror(global);
        if (!temp)
            yyerror("undeclared variable, first use in scope");
        else
            strcpy(yytext, global);
    }
    else if (temp)
    {

        // check the constants
        if (def == 0 && temp->isConst == 1)
        {
            yyerror("attempt to assign a const variable");
        }
        else if (def == 1)
        {
            yyerror("variable alread defined in the scope");
        }
    }
}

// read char data from a string
// eg: "'4'" = '4'
char validate_char(char * yytext)
{
    if (strlen(yytext) > 3)
    {
        // check for allawable escaped chars
        switch (yytext[2])
        {
            case 'n':
                return '\n';
            case 't':
                return '\t';
            case '\'':
                return '\'';
            case '\\':
                return '\\';
            case '\/':
                return '\/';
            case '\"':
                return '\"';
            case '0':
                return '\0';
            case 'r':
                return '\r';
            case 'b':
                return '\b';

            default:
                return '\0';
                yyerror("undefinded character literal.");

        }
    }
    else
    {
        return yytext[1];
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

// generate the code given by the tree root node tree
// and clean that tree
void make_codeSegment(struct Node * tree)
{

    //printTree(tree,0,0,1,0);
    generate_code(tree);
    free_node(tree);
}

int
main()
{
    #if YYDEBUG
        yydebug = 1;
    #endif

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
  exit(0);
}

int
yywrap()
{
  return(1);
}
