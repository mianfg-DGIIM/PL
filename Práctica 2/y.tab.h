
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
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
     OP_UNARY = 286,
     OP_BINARY = 287,
     OP_TERNARY_1 = 288,
     OP_TERNARY_2 = 289,
     PLUS_MINUS = 290
   };
#endif
/* Tokens.  */
#define MAIN 258
#define BLOCK_START 259
#define BLOCK_END 260
#define PARENT_START 261
#define PARENT_END 262
#define BRACKET_START 263
#define BRACKET_END 264
#define COLON 265
#define COMMA 266
#define BEGIN_LOCAL 267
#define END_LOCAL 268
#define TYPE 269
#define LIST_OF 270
#define ASSIGN 271
#define IF 272
#define ELSE 273
#define WHILE 274
#define FOR 275
#define TO 276
#define INPUT 277
#define OUTPUT 278
#define RETURN 279
#define CONST_INT 280
#define CONST_FLOAT 281
#define CONST_BOOL 282
#define CONST_CHAR 283
#define STRING 284
#define IDENTIFIER 285
#define OP_UNARY 286
#define OP_BINARY 287
#define OP_TERNARY_1 288
#define OP_TERNARY_2 289
#define PLUS_MINUS 290




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


