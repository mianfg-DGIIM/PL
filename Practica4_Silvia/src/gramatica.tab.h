/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SRC_GRAMATICA_TAB_H_INCLUDED
# define YY_YY_SRC_GRAMATICA_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    MAIN = 258,                    /* MAIN  */
    BLOCK_START = 259,             /* BLOCK_START  */
    BLOCK_END = 260,               /* BLOCK_END  */
    PARENT_START = 261,            /* PARENT_START  */
    PARENT_END = 262,              /* PARENT_END  */
    BRACKET_START = 263,           /* BRACKET_START  */
    BRACKET_END = 264,             /* BRACKET_END  */
    COLON = 265,                   /* COLON  */
    COMMA = 266,                   /* COMMA  */
    BEGIN_LOCAL = 267,             /* BEGIN_LOCAL  */
    END_LOCAL = 268,               /* END_LOCAL  */
    TYPE = 269,                    /* TYPE  */
    LIST_OF = 270,                 /* LIST_OF  */
    ASSIGN = 271,                  /* ASSIGN  */
    IF = 272,                      /* IF  */
    ELSE = 273,                    /* ELSE  */
    WHILE = 274,                   /* WHILE  */
    FOR = 275,                     /* FOR  */
    TO = 276,                      /* TO  */
    INPUT = 277,                   /* INPUT  */
    OUTPUT = 278,                  /* OUTPUT  */
    RETURN = 279,                  /* RETURN  */
    CONST_INT = 280,               /* CONST_INT  */
    CONST_FLOAT = 281,             /* CONST_FLOAT  */
    CONST_BOOL = 282,              /* CONST_BOOL  */
    CONST_CHAR = 283,              /* CONST_CHAR  */
    STRING = 284,                  /* STRING  */
    IDENTIFIER = 285,              /* IDENTIFIER  */
    OP_BINARY_LIST = 286,          /* OP_BINARY_LIST  */
    OP_TERNARY_1 = 287,            /* OP_TERNARY_1  */
    OP_TERNARY_2 = 288,            /* OP_TERNARY_2  */
    OP_LIST = 289,                 /* OP_LIST  */
    OP_DOLLAR = 290,               /* OP_DOLLAR  */
    OP_BINARY_OR = 291,            /* OP_BINARY_OR  */
    OP_BINARY_AND = 292,           /* OP_BINARY_AND  */
    OP_BINARY_EQ = 293,            /* OP_BINARY_EQ  */
    OP_BINARY_REL = 294,           /* OP_BINARY_REL  */
    PLUS_MINUS = 295,              /* PLUS_MINUS  */
    OP_BINARY_MUL = 296,           /* OP_BINARY_MUL  */
    OP_UNARY = 297                 /* OP_UNARY  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_GRAMATICA_TAB_H_INCLUDED  */
