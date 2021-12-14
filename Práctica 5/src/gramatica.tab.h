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
    PARENT_END = 259,              /* PARENT_END  */
    BLOCK_START = 260,             /* BLOCK_START  */
    BLOCK_END = 261,               /* BLOCK_END  */
    BRACKET_START = 262,           /* BRACKET_START  */
    BRACKET_END = 263,             /* BRACKET_END  */
    COLON = 264,                   /* COLON  */
    COMMA = 265,                   /* COMMA  */
    ASSIGN = 266,                  /* ASSIGN  */
    IF = 267,                      /* IF  */
    ELSE = 268,                    /* ELSE  */
    WHILE = 269,                   /* WHILE  */
    RETURN = 270,                  /* RETURN  */
    FOR = 271,                     /* FOR  */
    TO = 272,                      /* TO  */
    OUTPUT = 273,                  /* OUTPUT  */
    INPUT = 274,                   /* INPUT  */
    BEGIN_LOCAL = 275,             /* BEGIN_LOCAL  */
    END_LOCAL = 276,               /* END_LOCAL  */
    LIST_OF = 277,                 /* LIST_OF  */
    TYPE = 278,                    /* TYPE  */
    STRING = 279,                  /* STRING  */
    AT = 280,                      /* AT  */
    OP_BINARY_OR = 281,            /* OP_BINARY_OR  */
    OP_BINARY_AND = 282,           /* OP_BINARY_AND  */
    OP_BINARY_EQ = 283,            /* OP_BINARY_EQ  */
    OP_BINARY_REL = 284,           /* OP_BINARY_REL  */
    PLUS_MINUS = 285,              /* PLUS_MINUS  */
    OP_BINARY_MUL = 286,           /* OP_BINARY_MUL  */
    OP_UNARY_NEG = 287,            /* OP_UNARY_NEG  */
    OP_UNARY_COUNT = 288,          /* OP_UNARY_COUNT  */
    OP_UNARY_QUEST = 289,          /* OP_UNARY_QUEST  */
    MINUS_MINUS = 290,             /* MINUS_MINUS  */
    PLUS_PLUS = 291,               /* PLUS_PLUS  */
    DOLLAR = 292,                  /* DOLLAR  */
    OP_LIST = 293,                 /* OP_LIST  */
    CONST_INT = 294,               /* CONST_INT  */
    CONST_FLOAT = 295,             /* CONST_FLOAT  */
    CONST_BOOL = 296,              /* CONST_BOOL  */
    CONST_CHAR = 297,              /* CONST_CHAR  */
    IDENTIFIER = 298,              /* IDENTIFIER  */
    PARENT_START = 299             /* PARENT_START  */
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
