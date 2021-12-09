/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_SRC_GRAMATICA_TAB_H_INCLUDED
# define YY_YY_SRC_GRAMATICA_TAB_H_INCLUDED
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
    MAIN = 258,
    PARENT_END = 259,
    BLOCK_START = 260,
    BLOCK_END = 261,
    BRACKET_START = 262,
    BRACKET_END = 263,
    COLON = 264,
    COMMA = 265,
    ASSIGN = 266,
    IF = 267,
    ELSE = 268,
    WHILE = 269,
    RETURN = 270,
    FOR = 271,
    TO = 272,
    OUTPUT = 273,
    INPUT = 274,
    BEGIN_LOCAL = 275,
    END_LOCAL = 276,
    LIST_OF = 277,
    TYPE = 278,
    STRING = 279,
    AT = 280,
    OP_BINARY_OR = 281,
    OP_BINARY_AND = 282,
    OP_BINARY_EQ = 283,
    OP_BINARY_REL = 284,
    PLUS_MINUS = 285,
    OP_BINARY_MUL = 286,
    OP_UNARY_NEG = 287,
    OP_UNARY_COUNT = 288,
    OP_UNARY_QUEST = 289,
    MINUS_MINUS = 290,
    PLUS_PLUS = 291,
    DOLLAR = 292,
    OP_LIST = 293,
    CONST_INT = 294,
    CONST_FLOAT = 295,
    CONST_BOOL = 296,
    CONST_CHAR = 297,
    IDENTIFIER = 298,
    PARENT_START = 299
  };
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
