/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
#line 133 "c--.y" /* yacc.c:1909  */

    int ival;
    char cval;
    double dval;
    struct Node * node_ptr;
    char * iname;
    char * sval;

#line 127 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
