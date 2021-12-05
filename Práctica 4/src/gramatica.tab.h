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
    BLOCK_START = 259,
    BLOCK_END = 260,
    PARENT_START = 261,
    PARENT_END = 262,
    BRACKET_START = 263,
    BRACKET_END = 264,
    COLON = 265,
    COMMA = 266,
    BEGIN_LOCAL = 267,
    END_LOCAL = 268,
    TYPE = 269,
    LIST_OF = 270,
    ASSIGN = 271,
    IF = 272,
    ELSE = 273,
    WHILE = 274,
    FOR = 275,
    TO = 276,
    INPUT = 277,
    OUTPUT = 278,
    RETURN = 279,
    CONST_INT = 280,
    CONST_FLOAT = 281,
    CONST_BOOL = 282,
    CONST_CHAR = 283,
    STRING = 284,
    IDENTIFIER = 285,
    OP_BINARY = 286,
    OP_TERNARY_1 = 287,
    OP_TERNARY_2 = 288,
    OP_BINARY_OR = 289,
    OP_BINARY_AND = 290,
    OP_BINARY_EQ = 291,
    OP_BINARY_REL = 292,
    PLUS_MINUS = 293,
    OP_BINARY_MUL = 294,
    OP_UNARY = 295
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