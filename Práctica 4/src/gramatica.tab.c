/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/gramatica.y"
 //CÓDIGO C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semantic.h"

void yyerror(const char *msg);

#define YYERROR_VERBOSE


#line 83 "src/gramatica.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    OP_BINARY_LIST = 286,
    OP_TERNARY_1 = 287,
    OP_TERNARY_2 = 288,
    OP_LIST = 289,
    OP_DOLLAR = 290,
    OP_BINARY_OR = 291,
    OP_BINARY_AND = 292,
    OP_BINARY_EQ = 293,
    OP_BINARY_REL = 294,
    PLUS_MINUS = 295,
    OP_BINARY_MUL = 296,
    OP_UNARY = 297
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



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   366

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  178

#define YYUNDEFTOK  2
#define YYMAXUTOK   297


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    69,    69,    70,    70,    73,    74,    75,    76,    77,
      77,    79,    80,    81,    81,    85,    85,    87,    88,    88,
      89,    90,    91,    92,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   100,   101,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   119,   124,   129,   134,
     142,   143,   144,   145,   146,   147,   148,   149,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MAIN", "BLOCK_START", "BLOCK_END",
  "PARENT_START", "PARENT_END", "BRACKET_START", "BRACKET_END", "COLON",
  "COMMA", "BEGIN_LOCAL", "END_LOCAL", "TYPE", "LIST_OF", "ASSIGN", "IF",
  "ELSE", "WHILE", "FOR", "TO", "INPUT", "OUTPUT", "RETURN", "CONST_INT",
  "CONST_FLOAT", "CONST_BOOL", "CONST_CHAR", "STRING", "IDENTIFIER",
  "OP_BINARY_LIST", "OP_TERNARY_1", "OP_TERNARY_2", "OP_LIST", "OP_DOLLAR",
  "OP_BINARY_OR", "OP_BINARY_AND", "OP_BINARY_EQ", "OP_BINARY_REL",
  "PLUS_MINUS", "OP_BINARY_MUL", "OP_UNARY", "$accept", "Programa",
  "bloque", "$@1", "bloque_in", "Declar_de_subprogs", "Declar_subprog",
  "$@2", "tipo", "Cabecera_subprograma", "$@3", "$@4",
  "Declar_de_variables_locales", "$@5", "Variables_locales",
  "Cuerpo_declar_variables", "$@6", "lista_variables",
  "lista_de_parametros", "Sentencias", "$@7", "$@8", "Sentencia",
  "Sentencia_asignacion", "Sentencia_if", "Sentencia_while",
  "Sentencia_for", "Sentencia_entrada", "Sentencia_salida",
  "Lista_expresiones_o_cadena", "Sentencia_return", "@9",
  "Sentencia_lista", "expresion", "funcion", "Lista_expresiones",
  "constante", "constante_base", "constante_lista", "constante_lista_int",
  "constante_lista_float", "constante_lista_bool", "constante_lista_char", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297
};
# endif

#define YYPACT_NINF (-38)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-72)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       0,    16,    23,   -38,   -38,   -38,    44,   -38,    61,   -38,
     106,   -38,    89,   -38,   -38,    70,     4,    85,   -38,   -38,
     -38,    75,   -38,    86,   133,   -38,   -38,     9,   -38,   -38,
     -38,    16,   133,   -38,   207,   191,   104,   112,   110,    25,
     161,   207,   -38,   -38,   -38,   -38,    45,   207,   207,   207,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
     282,   -38,   -38,   -38,   -38,   -38,   -38,    66,   132,   148,
     -38,   -38,   164,   222,   -38,   -38,   -38,   -38,    51,    78,
     117,   121,   207,   207,   156,   163,    91,   -38,   182,   293,
     293,   170,   207,    42,   -38,   -38,   207,   207,   207,   175,
     207,   207,   207,   207,   207,   207,   -38,   172,   206,   187,
     -38,   -38,   180,   -38,   181,   -38,   184,   -38,   186,   234,
     245,   207,     9,   -38,   -38,   198,   199,   -38,   293,    10,
     258,   -38,   325,   304,   143,   -38,   108,   204,   125,    95,
     195,   195,   -38,   192,    46,   -38,   -38,   -38,   -38,   -38,
     133,   133,   271,   220,   -38,   293,   -38,   -38,   207,   -38,
     207,   -38,   -38,   206,   221,   -38,   207,   -38,   293,   315,
     216,   133,     5,   -38,   -38,   207,   -38,   -22
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     3,     2,     1,    20,    18,     0,     8,
       0,     4,     0,    25,    11,     0,     0,     0,    22,    17,
       7,     0,     9,    32,     0,    12,    26,     0,    19,    21,
      13,     0,     0,    76,     0,     0,     0,     0,     0,     0,
       0,     0,    83,    84,    85,    86,    73,     0,     0,     0,
      36,    35,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    75,    74,    81,    82,    29,    28,     0,     0,     0,
      10,    33,    73,     0,    92,    94,    96,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    56,     0,    55,
      57,     0,     0,     0,    70,    62,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    24,     0,     0,     0,
      61,    87,     0,    88,     0,    89,     0,    90,     0,     0,
       0,     0,     0,    50,    52,     0,     0,    78,    80,     0,
       0,    60,    63,     0,    71,    59,    64,    65,    66,    67,
      69,    68,    27,     0,     0,    16,    91,    93,    95,    97,
       0,     0,     0,     0,    54,    53,    58,    77,     0,    45,
       0,    31,    14,     0,    46,    48,     0,    51,    79,    72,
       0,     0,     0,    30,    47,     0,    49,    69
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -38,   -38,    17,   -38,   -38,   -38,   -38,   -38,   -12,   -38,
     -38,   -38,   -38,   -38,   -38,   231,   -38,   -37,   -38,   -38,
     -38,   -38,   -28,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,   -33,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,   -38
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    50,     6,     8,    12,    20,    31,    16,    22,
      68,    69,     9,    10,    17,    18,    27,    67,   144,    23,
      32,    24,    51,    52,    53,    54,    55,    56,    57,    88,
      58,   126,    59,    60,    61,   129,    62,    63,    64,    78,
      79,    80,    81
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      21,    73,    86,     1,    71,    26,    33,    89,    90,     3,
      65,    34,   -70,    35,    93,    94,    95,   157,     4,   -70,
       3,   158,    36,     5,    37,    38,    65,    39,    40,    41,
      42,    43,    44,    45,   -23,    46,    96,    97,    98,    66,
      47,   100,   101,   102,   103,   175,   105,    49,    70,   119,
     120,    91,   131,   162,    85,    66,     7,   163,   128,   130,
     111,    92,   112,   132,   133,   134,    11,   136,   137,   138,
     139,   140,   141,    96,    97,    98,   106,   107,   100,   101,
     102,   103,   104,   105,    25,   153,    13,   113,   152,   114,
      19,    -6,   155,   -34,    -5,   -34,   143,   -34,    28,    14,
      15,   123,   107,    14,    15,    30,   -34,    13,   -34,   -34,
      82,   -34,   -34,   -34,   -34,   -34,   -34,   -34,    83,   -34,
      14,    15,   164,   165,   -34,   168,   115,   169,   116,   -34,
     117,   -34,   118,   172,    33,   104,   105,     3,   108,    34,
      84,    35,   177,   174,   176,   101,   102,   103,   104,   105,
      36,   170,    37,    38,   109,    39,    40,    41,    42,    43,
      44,    45,    33,    46,   103,   104,   105,    34,    47,    35,
      91,    33,   121,    48,   122,    49,    34,   127,    35,   100,
     101,   102,   103,   104,   105,   135,    42,    43,    44,    45,
      87,    72,   124,   125,   145,    42,    43,    44,    45,    33,
      72,    48,   142,    49,    34,   146,    35,   147,    33,   156,
      48,   148,    49,    34,   149,    35,    74,    75,    76,    77,
      14,    15,   161,    42,    43,    44,    45,   154,    72,   110,
     167,   107,    42,    43,    44,    45,   105,    72,    48,   171,
      49,   150,   102,   103,   104,   105,   173,    48,    29,    49,
       0,     0,   151,    96,    97,    98,     0,     0,   100,   101,
     102,   103,   104,   105,     0,    96,    97,    98,   159,     0,
     100,   101,   102,   103,   104,   105,    96,    97,    98,     0,
       0,   100,   101,   102,   103,   104,   105,     0,     0,    96,
      97,    98,   166,     0,   100,   101,   102,   103,   104,   105,
       0,     0,    96,    97,    98,     0,     0,   100,   101,   102,
     103,   104,   105,    96,    97,    98,    99,     0,   100,   101,
     102,   103,   104,   105,    96,    97,    98,     0,     0,   100,
     101,   102,   103,   104,   105,    96,    97,   160,     0,     0,
     100,   101,   102,   103,   104,   105,   -71,   -71,   -71,     0,
       0,   100,   101,   102,   103,   104,   105,    97,    98,     0,
       0,   100,   101,   102,   103,   104,   105
};

static const yytype_int16 yycheck[] =
{
      12,    34,    39,     3,    32,     1,     1,    40,    41,     4,
       1,     6,    34,     8,    47,    48,    49,     7,     1,    41,
       4,    11,    17,     0,    19,    20,     1,    22,    23,    24,
      25,    26,    27,    28,    30,    30,    31,    32,    33,    30,
      35,    36,    37,    38,    39,    40,    41,    42,    31,    82,
      83,     6,    10,     7,    29,    30,    12,    11,    91,    92,
       9,    16,    11,    96,    97,    98,     5,   100,   101,   102,
     103,   104,   105,    31,    32,    33,    10,    11,    36,    37,
      38,    39,    40,    41,    14,   122,     1,     9,   121,    11,
       1,     5,   125,     4,     5,     6,   108,     8,    13,    14,
      15,    10,    11,    14,    15,    30,    17,     1,    19,    20,
       6,    22,    23,    24,    25,    26,    27,    28,     6,    30,
      14,    15,   150,   151,    35,   158,     9,   160,    11,    40,
       9,    42,    11,   166,     1,    40,    41,     4,     6,     6,
      30,     8,   175,   171,   172,    37,    38,    39,    40,    41,
      17,   163,    19,    20,     6,    22,    23,    24,    25,    26,
      27,    28,     1,    30,    39,    40,    41,     6,    35,     8,
       6,     1,    16,    40,    11,    42,     6,     7,     8,    36,
      37,    38,    39,    40,    41,    10,    25,    26,    27,    28,
      29,    30,    10,    11,     7,    25,    26,    27,    28,     1,
      30,    40,    30,    42,     6,    25,     8,    26,     1,    10,
      40,    27,    42,     6,    28,     8,    25,    26,    27,    28,
      14,    15,    30,    25,    26,    27,    28,    29,    30,     7,
      10,    11,    25,    26,    27,    28,    41,    30,    40,    18,
      42,     7,    38,    39,    40,    41,    30,    40,    17,    42,
      -1,    -1,     7,    31,    32,    33,    -1,    -1,    36,    37,
      38,    39,    40,    41,    -1,    31,    32,    33,    10,    -1,
      36,    37,    38,    39,    40,    41,    31,    32,    33,    -1,
      -1,    36,    37,    38,    39,    40,    41,    -1,    -1,    31,
      32,    33,    21,    -1,    36,    37,    38,    39,    40,    41,
      -1,    -1,    31,    32,    33,    -1,    -1,    36,    37,    38,
      39,    40,    41,    31,    32,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    31,    32,    33,    -1,    -1,    36,
      37,    38,    39,    40,    41,    31,    32,    33,    -1,    -1,
      36,    37,    38,    39,    40,    41,    31,    32,    33,    -1,
      -1,    36,    37,    38,    39,    40,    41,    32,    33,    -1,
      -1,    36,    37,    38,    39,    40,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    44,     4,    45,     0,    46,    12,    47,    55,
      56,     5,    48,     1,    14,    15,    51,    57,    58,     1,
      49,    51,    52,    62,    64,    14,     1,    59,    13,    58,
      30,    50,    63,     1,     6,     8,    17,    19,    20,    22,
      23,    24,    25,    26,    27,    28,    30,    35,    40,    42,
      45,    65,    66,    67,    68,    69,    70,    71,    73,    75,
      76,    77,    79,    80,    81,     1,    30,    60,    53,    54,
      45,    65,    30,    76,    25,    26,    27,    28,    82,    83,
      84,    85,     6,     6,    30,    29,    60,    29,    72,    76,
      76,     6,    16,    76,    76,    76,    31,    32,    33,    34,
      36,    37,    38,    39,    40,    41,    10,    11,     6,     6,
       7,     9,    11,     9,    11,     9,    11,     9,    11,    76,
      76,    16,    11,    10,    10,    11,    74,     7,    76,    78,
      76,    10,    76,    76,    76,    10,    76,    76,    76,    76,
      76,    76,    30,    51,    61,     7,    25,    26,    27,    28,
       7,     7,    76,    60,    29,    76,    10,     7,    11,    10,
      33,    30,     7,    11,    65,    65,    21,    10,    76,    76,
      51,    18,    76,    30,    65,    40,    65,    76
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    46,    45,    47,    47,    48,    48,    50,
      49,    51,    51,    53,    52,    54,    52,    52,    56,    55,
      55,    57,    57,    59,    58,    58,    58,    60,    60,    60,
      61,    61,    63,    62,    64,    62,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    66,    67,    67,    68,    69,
      70,    70,    71,    72,    72,    72,    72,    74,    73,    75,
      75,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    77,    77,    78,
      78,    79,    79,    80,    80,    80,    80,    81,    81,    81,
      81,    82,    82,    83,    83,    84,    84,    85,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     4,     2,     3,     2,     0,     0,
       3,     1,     2,     0,     6,     0,     5,     1,     0,     4,
       0,     2,     1,     0,     4,     1,     2,     3,     1,     1,
       4,     2,     0,     3,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     5,     7,     5,     7,
       3,     5,     3,     3,     3,     1,     1,     0,     4,     3,
       3,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     5,     1,     1,     1,     1,     4,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     1,     3,     1,     3,     1,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 3:
#line 70 "src/gramatica.y"
                     { TS_AddMark(); }
#line 1518 "src/gramatica.tab.c"
    break;

  case 4:
#line 72 "src/gramatica.y"
                   { TS_ClearBlock(); }
#line 1524 "src/gramatica.tab.c"
    break;

  case 9:
#line 77 "src/gramatica.y"
                                      { esFunc = 1; }
#line 1530 "src/gramatica.tab.c"
    break;

  case 10:
#line 78 "src/gramatica.y"
                        { esFunc = 0; }
#line 1536 "src/gramatica.tab.c"
    break;

  case 11:
#line 79 "src/gramatica.y"
            { yyval.type = yyvsp[0].type; }
#line 1542 "src/gramatica.tab.c"
    break;

  case 12:
#line 80 "src/gramatica.y"
                    { yyval.type = getListType(yyvsp[-1].type); }
#line 1548 "src/gramatica.tab.c"
    break;

  case 13:
#line 81 "src/gramatica.y"
                                       { setType(yyvsp[-1]); decParam = 1; TS_AddFunction(yyvsp[0]); }
#line 1554 "src/gramatica.tab.c"
    break;

  case 14:
#line 84 "src/gramatica.y"
                                  { decParam = 0; yyvsp[-2].nDim = 0; }
#line 1560 "src/gramatica.tab.c"
    break;

  case 15:
#line 85 "src/gramatica.y"
                                       { setType(yyvsp[-1]); decParam = 1; TS_AddFunction(yyvsp[0]); }
#line 1566 "src/gramatica.tab.c"
    break;

  case 16:
#line 86 "src/gramatica.y"
                                               { decParam = 0; yyvsp[-1].nDim = 0; }
#line 1572 "src/gramatica.tab.c"
    break;

  case 18:
#line 88 "src/gramatica.y"
                                          { decVar = 1; }
#line 1578 "src/gramatica.tab.c"
    break;

  case 19:
#line 88 "src/gramatica.y"
                                                                                      { decVar = 0; }
#line 1584 "src/gramatica.tab.c"
    break;

  case 23:
#line 92 "src/gramatica.y"
                               { setType(yyvsp[0]); }
#line 1590 "src/gramatica.tab.c"
    break;

  case 27:
#line 95 "src/gramatica.y"
                                                   { VarList_Id(yyvsp[0], &yyval); }
#line 1596 "src/gramatica.tab.c"
    break;

  case 28:
#line 96 "src/gramatica.y"
                             { VarList_Id(yyvsp[0], &yyval); }
#line 1602 "src/gramatica.tab.c"
    break;

  case 30:
#line 98 "src/gramatica.y"
                                                                { yyvsp[0].nDim=0; setType(yyvsp[-1]); TS_AddParam(yyvsp[0]); }
#line 1608 "src/gramatica.tab.c"
    break;

  case 31:
#line 99 "src/gramatica.y"
                                      { yyvsp[0].nDim=0; setType(yyvsp[-1]); TS_AddParam(yyvsp[0]);}
#line 1614 "src/gramatica.tab.c"
    break;

  case 32:
#line 100 "src/gramatica.y"
                        {decVar = 2; }
#line 1620 "src/gramatica.tab.c"
    break;

  case 34:
#line 101 "src/gramatica.y"
             { decVar = 2; }
#line 1626 "src/gramatica.tab.c"
    break;

  case 45:
#line 111 "src/gramatica.y"
                                                         {
                         if (TS_GetType(yyvsp[-3]) != yyvsp[-1].type) {
                           printf("[SEMANTIC ERROR @ line %d] In assignation: types are not equal\n", line);
                         }
                         if (!Check_EqualSize(yyvsp[-3], yyvsp[-1])) {
                           printf("[SEMANTIC ERROR @ line %d] In assignation: sizes are not equal\n", line); 
                         }
                       }
#line 1639 "src/gramatica.tab.c"
    break;

  case 46:
#line 119 "src/gramatica.y"
                                                              {
                 if (yyvsp[-2].type != BOOLEAN) {
                   printf("[SEMANTIC ERROR @ line %d] Expression is not of type BOOLEAN\n", line);  
                 }
               }
#line 1649 "src/gramatica.tab.c"
    break;

  case 47:
#line 124 "src/gramatica.y"
                                                                             {
                 if(yyvsp[-4].type != BOOLEAN) {
                   printf("[SEMANTIC ERROR @ line %d] Expression is not of type BOOLEAN\n", line);    
                 }
               }
#line 1659 "src/gramatica.tab.c"
    break;

  case 48:
#line 129 "src/gramatica.y"
                                                                    {
                    if (yyvsp[-2].type != BOOLEAN) {
                      printf("[SEMANTIC ERROR @ line %d] Expression is not of type BOOLEAN\n", line);
                    }
                  }
#line 1669 "src/gramatica.tab.c"
    break;

  case 49:
#line 134 "src/gramatica.y"
                                                                       {
                  if (yyvsp[-3].type != INT) {
                    printf("[SEMANTIC ERROR @ line %d] Expression is not of type INT\n", line);
                  }
                  if (yyvsp[-1].type != INT) {
                    printf("[SEMANTIC ERROR @ line %d] Expression is not of type INT\n", line);
                  }
                }
#line 1682 "src/gramatica.tab.c"
    break;

  case 53:
#line 145 "src/gramatica.y"
                                                                        { nParams++; TS_CheckParam(yyvsp[-2]); }
#line 1688 "src/gramatica.tab.c"
    break;

  case 54:
#line 146 "src/gramatica.y"
                                                                     { nParams++; TS_CheckParam(yyvsp[-2]); }
#line 1694 "src/gramatica.tab.c"
    break;

  case 55:
#line 147 "src/gramatica.y"
                                       { nParams=1; TS_CheckParam(yyvsp[0]); }
#line 1700 "src/gramatica.tab.c"
    break;

  case 56:
#line 148 "src/gramatica.y"
                                    { nParams=1; TS_CheckParam(yyvsp[0]); }
#line 1706 "src/gramatica.tab.c"
    break;

  case 57:
#line 149 "src/gramatica.y"
                                    { TS_CheckReturn(yyvsp[0], &yyval); }
#line 1712 "src/gramatica.tab.c"
    break;

  case 59:
#line 150 "src/gramatica.y"
                                          { Check_ListSentence(yyvsp[-2]); }
#line 1718 "src/gramatica.tab.c"
    break;

  case 60:
#line 151 "src/gramatica.y"
                                            { Check_ListSentence(yyvsp[-1]); }
#line 1724 "src/gramatica.tab.c"
    break;

  case 61:
#line 152 "src/gramatica.y"
                                              { yyval.type = yyvsp[-1].type; yyval.nDim = yyvsp[-1].nDim; }
#line 1730 "src/gramatica.tab.c"
    break;

  case 62:
#line 153 "src/gramatica.y"
                               { Check_OpUnary(yyvsp[-1], yyvsp[0], &yyval); }
#line 1736 "src/gramatica.tab.c"
    break;

  case 63:
#line 154 "src/gramatica.y"
                                               { Check_OpBinaryList(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); }
#line 1742 "src/gramatica.tab.c"
    break;

  case 64:
#line 155 "src/gramatica.y"
                                             { Check_OpBinaryAndOr(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); }
#line 1748 "src/gramatica.tab.c"
    break;

  case 65:
#line 156 "src/gramatica.y"
                                              { Check_OpBinaryAndOr(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); }
#line 1754 "src/gramatica.tab.c"
    break;

  case 66:
#line 157 "src/gramatica.y"
                                             { Check_OpBinaryEq(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); }
#line 1760 "src/gramatica.tab.c"
    break;

  case 67:
#line 158 "src/gramatica.y"
                                               { Check_OpBinaryRel(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); }
#line 1766 "src/gramatica.tab.c"
    break;

  case 68:
#line 159 "src/gramatica.y"
                                              { Check_OpBinaryMul(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); }
#line 1772 "src/gramatica.tab.c"
    break;

  case 69:
#line 160 "src/gramatica.y"
                                           { Check_PlusMinusBinary(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); }
#line 1778 "src/gramatica.tab.c"
    break;

  case 70:
#line 161 "src/gramatica.y"
                                 { Check_PlusMinus(yyvsp[-1], yyvsp[0], &yyval); }
#line 1784 "src/gramatica.tab.c"
    break;

  case 71:
#line 162 "src/gramatica.y"
                                             { Check_At(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); }
#line 1790 "src/gramatica.tab.c"
    break;

  case 72:
#line 163 "src/gramatica.y"
                                                                    { Check_ListTernary(yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); }
#line 1796 "src/gramatica.tab.c"
    break;

  case 73:
#line 164 "src/gramatica.y"
                       { decVar = 0; }
#line 1802 "src/gramatica.tab.c"
    break;

  case 74:
#line 165 "src/gramatica.y"
                      { yyval.type = yyvsp[0].type; yyval.nDim = yyvsp[0].nDim; }
#line 1808 "src/gramatica.tab.c"
    break;

  case 75:
#line 166 "src/gramatica.y"
                    { yyval.type = yyvsp[0].type; yyval.nDim = yyvsp[0].nDim; currentFunction = -1; }
#line 1814 "src/gramatica.tab.c"
    break;

  case 77:
#line 168 "src/gramatica.y"
                                                               { Check_FunctionCall(yyvsp[-3], &yyval); }
#line 1820 "src/gramatica.tab.c"
    break;

  case 78:
#line 169 "src/gramatica.y"
                                             { Check_FunctionCall(yyvsp[-2], &yyval); }
#line 1826 "src/gramatica.tab.c"
    break;

  case 79:
#line 170 "src/gramatica.y"
                                                      { TS_CheckParam(yyvsp[0]); }
#line 1832 "src/gramatica.tab.c"
    break;

  case 80:
#line 171 "src/gramatica.y"
                              { /* WIP correct? -> */ checkParams = 0; TS_CheckParam(yyvsp[0]); }
#line 1838 "src/gramatica.tab.c"
    break;

  case 83:
#line 174 "src/gramatica.y"
                           { yyval.type = INT; }
#line 1844 "src/gramatica.tab.c"
    break;

  case 84:
#line 175 "src/gramatica.y"
                             { yyval.type = FLOAT; }
#line 1850 "src/gramatica.tab.c"
    break;

  case 85:
#line 176 "src/gramatica.y"
                            { yyval.type = BOOLEAN; }
#line 1856 "src/gramatica.tab.c"
    break;

  case 86:
#line 177 "src/gramatica.y"
                            { yyval.type = CHAR; }
#line 1862 "src/gramatica.tab.c"
    break;

  case 87:
#line 178 "src/gramatica.y"
                                                                { yyval.type = LIST_INT; yyval.nDim = yyvsp[-1].nDim; }
#line 1868 "src/gramatica.tab.c"
    break;

  case 88:
#line 179 "src/gramatica.y"
                                                                  { yyval.type = LIST_FLOAT; yyval.nDim = yyvsp[-1].nDim; }
#line 1874 "src/gramatica.tab.c"
    break;

  case 89:
#line 180 "src/gramatica.y"
                                                                 { yyval.type = LIST_BOOLEAN; yyval.nDim = yyvsp[-1].nDim; }
#line 1880 "src/gramatica.tab.c"
    break;

  case 90:
#line 181 "src/gramatica.y"
                                                                 { yyval.type = LIST_CHAR; yyval.nDim = yyvsp[-1].nDim; }
#line 1886 "src/gramatica.tab.c"
    break;


#line 1890 "src/gramatica.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 191 "src/gramatica.y"


#ifdef DOSWINDOWS /* Variable de entorno que indica la plataforma */
#include "lexyy.c"
#else
#include "lex.yy.c"
#endif

void yyerror(const char *msg) {
  fprintf(stderr, "[SYNTACTIC ERROR] Line %d: %s\n", yylineno, msg) ;
}
