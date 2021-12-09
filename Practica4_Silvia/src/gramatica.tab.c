/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

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


#line 84 "src/gramatica.tab.c"

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

#include "gramatica.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_MAIN = 3,                       /* MAIN  */
  YYSYMBOL_BLOCK_START = 4,                /* BLOCK_START  */
  YYSYMBOL_BLOCK_END = 5,                  /* BLOCK_END  */
  YYSYMBOL_PARENT_START = 6,               /* PARENT_START  */
  YYSYMBOL_PARENT_END = 7,                 /* PARENT_END  */
  YYSYMBOL_BRACKET_START = 8,              /* BRACKET_START  */
  YYSYMBOL_BRACKET_END = 9,                /* BRACKET_END  */
  YYSYMBOL_COLON = 10,                     /* COLON  */
  YYSYMBOL_COMMA = 11,                     /* COMMA  */
  YYSYMBOL_BEGIN_LOCAL = 12,               /* BEGIN_LOCAL  */
  YYSYMBOL_END_LOCAL = 13,                 /* END_LOCAL  */
  YYSYMBOL_TYPE = 14,                      /* TYPE  */
  YYSYMBOL_LIST_OF = 15,                   /* LIST_OF  */
  YYSYMBOL_ASSIGN = 16,                    /* ASSIGN  */
  YYSYMBOL_IF = 17,                        /* IF  */
  YYSYMBOL_ELSE = 18,                      /* ELSE  */
  YYSYMBOL_WHILE = 19,                     /* WHILE  */
  YYSYMBOL_FOR = 20,                       /* FOR  */
  YYSYMBOL_TO = 21,                        /* TO  */
  YYSYMBOL_INPUT = 22,                     /* INPUT  */
  YYSYMBOL_OUTPUT = 23,                    /* OUTPUT  */
  YYSYMBOL_RETURN = 24,                    /* RETURN  */
  YYSYMBOL_CONST_INT = 25,                 /* CONST_INT  */
  YYSYMBOL_CONST_FLOAT = 26,               /* CONST_FLOAT  */
  YYSYMBOL_CONST_BOOL = 27,                /* CONST_BOOL  */
  YYSYMBOL_CONST_CHAR = 28,                /* CONST_CHAR  */
  YYSYMBOL_STRING = 29,                    /* STRING  */
  YYSYMBOL_IDENTIFIER = 30,                /* IDENTIFIER  */
  YYSYMBOL_OP_BINARY_LIST = 31,            /* OP_BINARY_LIST  */
  YYSYMBOL_OP_TERNARY_1 = 32,              /* OP_TERNARY_1  */
  YYSYMBOL_OP_TERNARY_2 = 33,              /* OP_TERNARY_2  */
  YYSYMBOL_OP_LIST = 34,                   /* OP_LIST  */
  YYSYMBOL_OP_DOLLAR = 35,                 /* OP_DOLLAR  */
  YYSYMBOL_OP_BINARY_OR = 36,              /* OP_BINARY_OR  */
  YYSYMBOL_OP_BINARY_AND = 37,             /* OP_BINARY_AND  */
  YYSYMBOL_OP_BINARY_EQ = 38,              /* OP_BINARY_EQ  */
  YYSYMBOL_OP_BINARY_REL = 39,             /* OP_BINARY_REL  */
  YYSYMBOL_PLUS_MINUS = 40,                /* PLUS_MINUS  */
  YYSYMBOL_OP_BINARY_MUL = 41,             /* OP_BINARY_MUL  */
  YYSYMBOL_OP_UNARY = 42,                  /* OP_UNARY  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_Programa = 44,                  /* Programa  */
  YYSYMBOL_bloque = 45,                    /* bloque  */
  YYSYMBOL_46_1 = 46,                      /* $@1  */
  YYSYMBOL_bloque_in = 47,                 /* bloque_in  */
  YYSYMBOL_Declar_de_subprogs = 48,        /* Declar_de_subprogs  */
  YYSYMBOL_Declar_subprog = 49,            /* Declar_subprog  */
  YYSYMBOL_50_2 = 50,                      /* $@2  */
  YYSYMBOL_tipo = 51,                      /* tipo  */
  YYSYMBOL_Cabecera_subprograma = 52,      /* Cabecera_subprograma  */
  YYSYMBOL_53_3 = 53,                      /* $@3  */
  YYSYMBOL_54_4 = 54,                      /* $@4  */
  YYSYMBOL_Declar_de_variables_locales = 55, /* Declar_de_variables_locales  */
  YYSYMBOL_56_5 = 56,                      /* $@5  */
  YYSYMBOL_Variables_locales = 57,         /* Variables_locales  */
  YYSYMBOL_Cuerpo_declar_variables = 58,   /* Cuerpo_declar_variables  */
  YYSYMBOL_59_6 = 59,                      /* $@6  */
  YYSYMBOL_lista_variables = 60,           /* lista_variables  */
  YYSYMBOL_lista_de_parametros = 61,       /* lista_de_parametros  */
  YYSYMBOL_Sentencias = 62,                /* Sentencias  */
  YYSYMBOL_63_7 = 63,                      /* $@7  */
  YYSYMBOL_64_8 = 64,                      /* $@8  */
  YYSYMBOL_Sentencia = 65,                 /* Sentencia  */
  YYSYMBOL_Sentencia_asignacion = 66,      /* Sentencia_asignacion  */
  YYSYMBOL_Sentencia_if = 67,              /* Sentencia_if  */
  YYSYMBOL_Sentencia_while = 68,           /* Sentencia_while  */
  YYSYMBOL_Sentencia_for = 69,             /* Sentencia_for  */
  YYSYMBOL_Sentencia_entrada = 70,         /* Sentencia_entrada  */
  YYSYMBOL_Sentencia_salida = 71,          /* Sentencia_salida  */
  YYSYMBOL_Lista_expresiones_o_cadena = 72, /* Lista_expresiones_o_cadena  */
  YYSYMBOL_Sentencia_return = 73,          /* Sentencia_return  */
  YYSYMBOL_74_9 = 74,                      /* @9  */
  YYSYMBOL_Sentencia_lista = 75,           /* Sentencia_lista  */
  YYSYMBOL_expresion = 76,                 /* expresion  */
  YYSYMBOL_funcion = 77,                   /* funcion  */
  YYSYMBOL_cabecera_funcion = 78,          /* cabecera_funcion  */
  YYSYMBOL_argumentos_funcion = 79,        /* argumentos_funcion  */
  YYSYMBOL_Lista_expresiones = 80,         /* Lista_expresiones  */
  YYSYMBOL_constante = 81,                 /* constante  */
  YYSYMBOL_constante_base = 82,            /* constante_base  */
  YYSYMBOL_constante_lista = 83,           /* constante_lista  */
  YYSYMBOL_constante_lista_int = 84,       /* constante_lista_int  */
  YYSYMBOL_constante_lista_float = 85,     /* constante_lista_float  */
  YYSYMBOL_constante_lista_bool = 86,      /* constante_lista_bool  */
  YYSYMBOL_constante_lista_char = 87       /* constante_lista_char  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
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

#if 1

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
#endif /* 1 */

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
#define YYLAST   285

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  169

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      77,    79,    80,    81,    81,    85,    85,    87,    87,    88,
      89,    90,    91,    91,    92,    93,    94,    95,    96,    96,
      97,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   116,   121,   126,   131,   139,   140,   141,   142,
     143,   144,   145,   146,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "MAIN", "BLOCK_START",
  "BLOCK_END", "PARENT_START", "PARENT_END", "BRACKET_START",
  "BRACKET_END", "COLON", "COMMA", "BEGIN_LOCAL", "END_LOCAL", "TYPE",
  "LIST_OF", "ASSIGN", "IF", "ELSE", "WHILE", "FOR", "TO", "INPUT",
  "OUTPUT", "RETURN", "CONST_INT", "CONST_FLOAT", "CONST_BOOL",
  "CONST_CHAR", "STRING", "IDENTIFIER", "OP_BINARY_LIST", "OP_TERNARY_1",
  "OP_TERNARY_2", "OP_LIST", "OP_DOLLAR", "OP_BINARY_OR", "OP_BINARY_AND",
  "OP_BINARY_EQ", "OP_BINARY_REL", "PLUS_MINUS", "OP_BINARY_MUL",
  "OP_UNARY", "$accept", "Programa", "bloque", "$@1", "bloque_in",
  "Declar_de_subprogs", "Declar_subprog", "$@2", "tipo",
  "Cabecera_subprograma", "$@3", "$@4", "Declar_de_variables_locales",
  "$@5", "Variables_locales", "Cuerpo_declar_variables", "$@6",
  "lista_variables", "lista_de_parametros", "Sentencias", "$@7", "$@8",
  "Sentencia", "Sentencia_asignacion", "Sentencia_if", "Sentencia_while",
  "Sentencia_for", "Sentencia_entrada", "Sentencia_salida",
  "Lista_expresiones_o_cadena", "Sentencia_return", "@9",
  "Sentencia_lista", "expresion", "funcion", "cabecera_funcion",
  "argumentos_funcion", "Lista_expresiones", "constante", "constante_base",
  "constante_lista", "constante_lista_int", "constante_lista_float",
  "constante_lista_bool", "constante_lista_char", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
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
#endif

#define YYPACT_NINF (-34)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-7)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      16,    28,    38,   -34,   -34,   -34,    34,   -34,    23,   -34,
      -8,   -34,     0,   -34,    51,   -34,    -2,   -34,   -34,    68,
     -34,    87,    77,   -34,    76,   -34,   -34,   -34,    28,    77,
     165,    62,   105,   137,   117,    32,   102,   165,   -34,   -34,
     -34,   -34,     2,   165,   165,   -34,   -34,   -34,   -34,   -34,
     -34,   -34,   -34,   -34,   -34,   233,   -34,   132,   -34,   -34,
     -34,   -34,   103,   166,   171,   -34,   -34,   175,   147,   -34,
     -34,   -34,   -34,    18,    24,    73,   152,   165,   165,   148,
     178,   124,   -34,   131,    84,    84,   -34,   165,   198,   -34,
     165,   165,   192,   165,   165,   165,   165,   165,   165,   -34,
      84,   -34,    13,   -34,   176,    -8,   196,   -34,   -34,   191,
     -34,   189,   -34,   194,   -34,   203,   173,   187,   165,    76,
     -34,   -34,   140,   207,   210,   -34,    84,   244,   -34,   112,
     158,    39,   115,   135,   181,   -34,   165,   -34,   202,    15,
     -34,   -34,   -34,   -34,   -34,    77,    77,   222,   190,   -34,
      84,   -34,   -34,   165,    84,   -34,   -34,    -8,   215,   -34,
     165,   -34,    36,   214,    77,    17,   -34,   -34,   -34
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     3,     2,     1,    19,    17,     0,     8,
       0,     4,    30,    11,     0,    22,     0,    21,     7,     0,
       9,    28,     0,    12,     0,    18,    20,    13,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    78,    79,
      80,    81,    67,     0,     0,    32,    31,    33,    34,    35,
      36,    37,    38,    39,    40,     0,    69,     0,    68,    76,
      77,    25,     0,     0,     0,    10,    29,    67,     0,    87,
      89,    91,    93,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    52,     0,    51,    53,    71,     0,     0,    58,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    73,
      75,    70,     0,    23,     0,     0,     0,    57,    82,     0,
      83,     0,    84,     0,    85,     0,     0,     0,     0,     0,
      46,    48,     0,     0,     0,    56,    59,     0,    55,    60,
      61,    62,    63,    65,    64,    72,     0,    24,     0,     0,
      16,    86,    88,    90,    92,     0,     0,     0,     0,    50,
      49,    54,    41,     0,    74,    27,    14,     0,    42,    44,
       0,    47,    66,     0,     0,     0,    26,    43,    45
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -34,   -34,     3,   -34,   -34,   -34,   -34,   -34,   -12,   -34,
     -34,   -34,   -34,   -34,   -34,   224,   -34,   -33,   -34,   -34,
     -34,   -34,   -28,   -34,   -34,   -34,   -34,   -34,   -34,   -34,
     -34,   -34,   -34,   -27,   -34,   -34,   -34,   -34,   -34,   -34,
     -34,   -34,   -34,   -34,   -34
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,    45,     6,     8,    12,    18,    28,    15,    20,
      63,    64,     9,    10,    16,    17,    24,    62,   139,    21,
      29,    22,    46,    47,    48,    49,    50,    51,    52,    83,
      53,   123,    54,    55,    56,    57,   101,   102,    58,    59,
      60,    73,    74,    75,    76
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      19,    66,    81,    68,     4,    -5,    13,    14,    86,    84,
      85,    25,    13,    14,    13,    14,    88,    89,    87,     1,
     135,     3,   156,    30,   136,    31,   157,   108,    11,   109,
     100,    65,     3,   110,    32,   111,    33,    34,     5,    35,
      36,    37,    38,    39,    40,    41,     7,    42,    90,    91,
     116,   117,    43,    93,    94,    95,    96,    97,    98,    44,
     124,    80,    61,   126,   127,    23,   129,   130,   131,   132,
     133,   134,    93,    94,    95,    96,    97,    98,    96,    97,
      98,     3,   112,    30,   113,    31,   148,    69,    70,    71,
      72,   147,    -6,   138,    32,   150,    33,    34,    27,    35,
      36,    37,    38,    39,    40,    41,    61,    42,    30,   154,
      31,    77,    43,   103,   104,    90,    91,   158,   159,    44,
      93,    94,    95,    96,    97,    98,   162,    38,    39,    40,
      41,    82,    67,   165,   120,   104,   167,   168,    30,    99,
      31,   121,   122,    78,    44,   163,    30,    79,    31,    94,
      95,    96,    97,    98,   107,    97,    98,    38,    39,    40,
      41,   114,    67,   115,   118,    38,    39,    40,    41,   149,
      67,    30,   105,    31,    44,    -7,    98,   106,    90,    91,
     145,    86,    44,    93,    94,    95,    96,    97,    98,   119,
      38,    39,    40,    41,   146,    67,    95,    96,    97,    98,
     161,   104,   128,   140,    90,    91,   137,    44,   125,    93,
      94,    95,    96,    97,    98,   142,   141,   151,    90,    91,
     152,   143,    98,    93,    94,    95,    96,    97,    98,    90,
      91,   144,   155,   164,    93,    94,    95,    96,    97,    98,
      26,    90,    91,   160,   166,     0,    93,    94,    95,    96,
      97,    98,     0,    90,    91,     0,     0,     0,    93,    94,
      95,    96,    97,    98,    90,    91,     0,    92,     0,    93,
      94,    95,    96,    97,    98,    90,    91,   153,     0,     0,
      93,    94,    95,    96,    97,    98
};

static const yytype_int16 yycheck[] =
{
      12,    29,    35,    30,     1,     5,    14,    15,     6,    36,
      37,    13,    14,    15,    14,    15,    43,    44,    16,     3,
       7,     4,     7,     6,    11,     8,    11,     9,     5,    11,
      57,    28,     4,     9,    17,    11,    19,    20,     0,    22,
      23,    24,    25,    26,    27,    28,    12,    30,    31,    32,
      77,    78,    35,    36,    37,    38,    39,    40,    41,    42,
      87,    29,    30,    90,    91,    14,    93,    94,    95,    96,
      97,    98,    36,    37,    38,    39,    40,    41,    39,    40,
      41,     4,     9,     6,    11,     8,   119,    25,    26,    27,
      28,   118,     5,   105,    17,   122,    19,    20,    30,    22,
      23,    24,    25,    26,    27,    28,    30,    30,     6,   136,
       8,     6,    35,    10,    11,    31,    32,   145,   146,    42,
      36,    37,    38,    39,    40,    41,   153,    25,    26,    27,
      28,    29,    30,   160,    10,    11,   164,   165,     6,     7,
       8,    10,    11,     6,    42,   157,     6,    30,     8,    37,
      38,    39,    40,    41,     7,    40,    41,    25,    26,    27,
      28,     9,    30,    11,    16,    25,    26,    27,    28,    29,
      30,     6,     6,     8,    42,    40,    41,     6,    31,    32,
       7,     6,    42,    36,    37,    38,    39,    40,    41,    11,
      25,    26,    27,    28,     7,    30,    38,    39,    40,    41,
      10,    11,    10,     7,    31,    32,    30,    42,    10,    36,
      37,    38,    39,    40,    41,    26,    25,    10,    31,    32,
      10,    27,    41,    36,    37,    38,    39,    40,    41,    31,
      32,    28,    30,    18,    36,    37,    38,    39,    40,    41,
      16,    31,    32,    21,    30,    -1,    36,    37,    38,    39,
      40,    41,    -1,    31,    32,    -1,    -1,    -1,    36,    37,
      38,    39,    40,    41,    31,    32,    -1,    34,    -1,    36,
      37,    38,    39,    40,    41,    31,    32,    33,    -1,    -1,
      36,    37,    38,    39,    40,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    44,     4,    45,     0,    46,    12,    47,    55,
      56,     5,    48,    14,    15,    51,    57,    58,    49,    51,
      52,    62,    64,    14,    59,    13,    58,    30,    50,    63,
       6,     8,    17,    19,    20,    22,    23,    24,    25,    26,
      27,    28,    30,    35,    42,    45,    65,    66,    67,    68,
      69,    70,    71,    73,    75,    76,    77,    78,    81,    82,
      83,    30,    60,    53,    54,    45,    65,    30,    76,    25,
      26,    27,    28,    84,    85,    86,    87,     6,     6,    30,
      29,    60,    29,    72,    76,    76,     6,    16,    76,    76,
      31,    32,    34,    36,    37,    38,    39,    40,    41,     7,
      76,    79,    80,    10,    11,     6,     6,     7,     9,    11,
       9,    11,     9,    11,     9,    11,    76,    76,    16,    11,
      10,    10,    11,    74,    76,    10,    76,    76,    10,    76,
      76,    76,    76,    76,    76,     7,    11,    30,    51,    61,
       7,    25,    26,    27,    28,     7,     7,    76,    60,    29,
      76,    10,    10,    33,    76,    30,     7,    11,    65,    65,
      21,    10,    76,    51,    18,    76,    30,    65,    65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    46,    45,    47,    47,    48,    48,    50,
      49,    51,    51,    53,    52,    54,    52,    56,    55,    55,
      57,    57,    59,    58,    60,    60,    61,    61,    63,    62,
      64,    62,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    66,    67,    67,    68,    69,    70,    70,    71,    72,
      72,    72,    72,    74,    73,    75,    75,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      77,    78,    79,    79,    80,    80,    81,    81,    82,    82,
      82,    82,    83,    83,    83,    83,    84,    84,    85,    85,
      86,    86,    87,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     4,     2,     3,     2,     0,     0,
       3,     1,     2,     0,     6,     0,     5,     0,     4,     0,
       2,     1,     0,     4,     3,     1,     4,     2,     0,     3,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     5,     7,     5,     7,     3,     5,     3,     3,
       3,     1,     1,     0,     4,     3,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     5,     1,     1,     1,
       2,     2,     2,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     1,     3,     1,
       3,     1,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
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
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
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


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

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
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 3: /* $@1: %empty  */
#line 70 "src/gramatica.y"
                     { TS_AddMark(); }
#line 1586 "src/gramatica.tab.c"
    break;

  case 4: /* bloque: BLOCK_START $@1 bloque_in BLOCK_END  */
#line 72 "src/gramatica.y"
                   { TS_ClearBlock(); }
#line 1592 "src/gramatica.tab.c"
    break;

  case 9: /* $@2: %empty  */
#line 77 "src/gramatica.y"
                                      { esFunc = 1; }
#line 1598 "src/gramatica.tab.c"
    break;

  case 10: /* Declar_subprog: Cabecera_subprograma $@2 bloque  */
#line 78 "src/gramatica.y"
                        { esFunc = 0; }
#line 1604 "src/gramatica.tab.c"
    break;

  case 11: /* tipo: TYPE  */
#line 79 "src/gramatica.y"
            { yyval.type = yyvsp[0].type; }
#line 1610 "src/gramatica.tab.c"
    break;

  case 12: /* tipo: LIST_OF TYPE  */
#line 80 "src/gramatica.y"
                    { yyval.type = getListType(yyvsp[0].type); }
#line 1616 "src/gramatica.tab.c"
    break;

  case 13: /* $@3: %empty  */
#line 81 "src/gramatica.y"
                                       { setType(yyvsp[-1]); decParam = 1; TS_AddFunction(yyvsp[0]); }
#line 1622 "src/gramatica.tab.c"
    break;

  case 14: /* Cabecera_subprograma: tipo IDENTIFIER $@3 PARENT_START lista_de_parametros PARENT_END  */
#line 84 "src/gramatica.y"
                                  { decParam = 0; yyvsp[-2].nDim = 0; }
#line 1628 "src/gramatica.tab.c"
    break;

  case 15: /* $@4: %empty  */
#line 85 "src/gramatica.y"
                                        { setType(yyvsp[-1]); decParam = 1; TS_AddFunction(yyvsp[0]); }
#line 1634 "src/gramatica.tab.c"
    break;

  case 16: /* Cabecera_subprograma: tipo IDENTIFIER $@4 PARENT_START PARENT_END  */
#line 86 "src/gramatica.y"
                                               { decParam = 0; yyvsp[-1].nDim = 0; }
#line 1640 "src/gramatica.tab.c"
    break;

  case 17: /* $@5: %empty  */
#line 87 "src/gramatica.y"
                                          { decVar = 1; }
#line 1646 "src/gramatica.tab.c"
    break;

  case 18: /* Declar_de_variables_locales: BEGIN_LOCAL $@5 Variables_locales END_LOCAL  */
#line 87 "src/gramatica.y"
                                                                                      { decVar = 0; }
#line 1652 "src/gramatica.tab.c"
    break;

  case 22: /* $@6: %empty  */
#line 91 "src/gramatica.y"
                               { setType(yyvsp[0]); }
#line 1658 "src/gramatica.tab.c"
    break;

  case 24: /* lista_variables: lista_variables COMMA IDENTIFIER  */
#line 92 "src/gramatica.y"
                                                   { VarList_Id(yyvsp[0], &yyval); }
#line 1664 "src/gramatica.tab.c"
    break;

  case 25: /* lista_variables: IDENTIFIER  */
#line 93 "src/gramatica.y"
                             { VarList_Id(yyvsp[0], &yyval); }
#line 1670 "src/gramatica.tab.c"
    break;

  case 26: /* lista_de_parametros: lista_de_parametros COMMA tipo IDENTIFIER  */
#line 94 "src/gramatica.y"
                                                                { yyvsp[0].nDim=0; setType(yyvsp[-1]); TS_AddParam(yyvsp[0]); }
#line 1676 "src/gramatica.tab.c"
    break;

  case 27: /* lista_de_parametros: tipo IDENTIFIER  */
#line 95 "src/gramatica.y"
                                      { yyvsp[0].nDim=0; setType(yyvsp[-1]); TS_AddParam(yyvsp[0]);}
#line 1682 "src/gramatica.tab.c"
    break;

  case 28: /* $@7: %empty  */
#line 96 "src/gramatica.y"
                        {decVar = 2; }
#line 1688 "src/gramatica.tab.c"
    break;

  case 30: /* $@8: %empty  */
#line 97 "src/gramatica.y"
             { decVar = 2; }
#line 1694 "src/gramatica.tab.c"
    break;

  case 41: /* Sentencia_asignacion: IDENTIFIER ASSIGN expresion COLON  */
#line 107 "src/gramatica.y"
                                                         {
                          if (TS_GetType(yyvsp[-3]) != yyvsp[-1].type) {
                            printf("[SEMANTIC ERROR @ line %d] In assignation: types are not equal\n", line);
                          }
                          
                          if (!Check_EqualSize(yyvsp[-3], yyvsp[-1])) {
                            printf("[SEMANTIC ERROR @ line %d] In assignation: sizes are not equal\n", line); 
                          }
                       }
#line 1708 "src/gramatica.tab.c"
    break;

  case 42: /* Sentencia_if: IF PARENT_START expresion PARENT_END Sentencia  */
#line 116 "src/gramatica.y"
                                                              {
                 if (yyvsp[-2].type != BOOLEAN) {
                   printf("[SEMANTIC ERROR @ line %d] Expression is not of type BOOLEAN\n", line);  
                 }
               }
#line 1718 "src/gramatica.tab.c"
    break;

  case 43: /* Sentencia_if: IF PARENT_START expresion PARENT_END Sentencia ELSE Sentencia  */
#line 121 "src/gramatica.y"
                                                                              {
                 if(yyvsp[-4].type != BOOLEAN) {
                   printf("[SEMANTIC ERROR @ line %d] Expression is not of type BOOLEAN\n", line);    
                 }
               }
#line 1728 "src/gramatica.tab.c"
    break;

  case 44: /* Sentencia_while: WHILE PARENT_START expresion PARENT_END Sentencia  */
#line 126 "src/gramatica.y"
                                                                    {
                    if (yyvsp[-2].type != BOOLEAN) {
                      printf("[SEMANTIC ERROR @ line %d] Expression is not of type BOOLEAN\n", line);
                    }
                  }
#line 1738 "src/gramatica.tab.c"
    break;

  case 45: /* Sentencia_for: FOR IDENTIFIER ASSIGN expresion TO expresion Sentencia  */
#line 131 "src/gramatica.y"
                                                                       {
                  if (yyvsp[-3].type != INT) {
                    printf("[SEMANTIC ERROR @ line %d] Expression is not of type INT\n", line);
                  }
                  if (yyvsp[-1].type != INT) {
                    printf("[SEMANTIC ERROR @ line %d] Expression is not of type INT\n", line);
                  }
                }
#line 1751 "src/gramatica.tab.c"
    break;

  case 49: /* Lista_expresiones_o_cadena: Lista_expresiones_o_cadena COMMA expresion  */
#line 142 "src/gramatica.y"
                                                                        { nParams++; TS_CheckParam(yyvsp[-2]); }
#line 1757 "src/gramatica.tab.c"
    break;

  case 50: /* Lista_expresiones_o_cadena: Lista_expresiones_o_cadena COMMA STRING  */
#line 143 "src/gramatica.y"
                                                                     { nParams++; TS_CheckParam(yyvsp[-2]); }
#line 1763 "src/gramatica.tab.c"
    break;

  case 51: /* Lista_expresiones_o_cadena: expresion  */
#line 144 "src/gramatica.y"
                                       { nParams=1; TS_CheckParam(yyvsp[0]); }
#line 1769 "src/gramatica.tab.c"
    break;

  case 52: /* Lista_expresiones_o_cadena: STRING  */
#line 145 "src/gramatica.y"
                                    { nParams=1; TS_CheckParam(yyvsp[0]); }
#line 1775 "src/gramatica.tab.c"
    break;

  case 53: /* @9: %empty  */
#line 146 "src/gramatica.y"
                                    { TS_CheckReturn(yyvsp[0], &yyval); }
#line 1781 "src/gramatica.tab.c"
    break;

  case 55: /* Sentencia_lista: expresion OP_LIST COLON  */
#line 147 "src/gramatica.y"
                                          { Check_ListSentence(yyvsp[-2]); }
#line 1787 "src/gramatica.tab.c"
    break;

  case 56: /* Sentencia_lista: OP_DOLLAR expresion COLON  */
#line 148 "src/gramatica.y"
                                            { Check_ListSentence(yyvsp[-1]); }
#line 1793 "src/gramatica.tab.c"
    break;

  case 57: /* expresion: PARENT_START expresion PARENT_END  */
#line 149 "src/gramatica.y"
                                              { yyval.type = yyvsp[-1].type; yyval.nDim = yyvsp[-1].nDim; }
#line 1799 "src/gramatica.tab.c"
    break;

  case 58: /* expresion: OP_UNARY expresion  */
#line 150 "src/gramatica.y"
                               { Check_OpUnary(yyvsp[-1], yyvsp[0], &yyval); }
#line 1805 "src/gramatica.tab.c"
    break;

  case 59: /* expresion: expresion OP_BINARY_LIST expresion  */
#line 151 "src/gramatica.y"
                                               { Check_OpBinaryList(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); }
#line 1811 "src/gramatica.tab.c"
    break;

  case 60: /* expresion: expresion OP_BINARY_OR expresion  */
#line 152 "src/gramatica.y"
                                             { Check_OpBinaryAndOr(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); }
#line 1817 "src/gramatica.tab.c"
    break;

  case 61: /* expresion: expresion OP_BINARY_AND expresion  */
#line 153 "src/gramatica.y"
                                              { Check_OpBinaryAndOr(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); }
#line 1823 "src/gramatica.tab.c"
    break;

  case 62: /* expresion: expresion OP_BINARY_EQ expresion  */
#line 154 "src/gramatica.y"
                                             { Check_OpBinaryEq(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); }
#line 1829 "src/gramatica.tab.c"
    break;

  case 63: /* expresion: expresion OP_BINARY_REL expresion  */
#line 155 "src/gramatica.y"
                                               { Check_OpBinaryRel(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); }
#line 1835 "src/gramatica.tab.c"
    break;

  case 64: /* expresion: expresion OP_BINARY_MUL expresion  */
#line 156 "src/gramatica.y"
                                              { Check_OpBinaryMul(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); }
#line 1841 "src/gramatica.tab.c"
    break;

  case 65: /* expresion: expresion PLUS_MINUS expresion  */
#line 157 "src/gramatica.y"
                                           { Check_PlusMinusBinary(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); }
#line 1847 "src/gramatica.tab.c"
    break;

  case 66: /* expresion: expresion OP_TERNARY_1 expresion OP_TERNARY_2 expresion  */
#line 160 "src/gramatica.y"
                                                                    { Check_ListTernary(yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); }
#line 1853 "src/gramatica.tab.c"
    break;

  case 67: /* expresion: IDENTIFIER  */
#line 161 "src/gramatica.y"
                       { yyval.type = TS_GetType(yyvsp[0]); decVar = 0; }
#line 1859 "src/gramatica.tab.c"
    break;

  case 68: /* expresion: constante  */
#line 162 "src/gramatica.y"
                      { yyval.type = yyvsp[0].type; yyval.nDim = yyvsp[0].nDim; }
#line 1865 "src/gramatica.tab.c"
    break;

  case 69: /* expresion: funcion  */
#line 163 "src/gramatica.y"
                    { yyval.type = yyvsp[0].type; yyval.nDim = yyvsp[0].nDim; currentFunction = -1; }
#line 1871 "src/gramatica.tab.c"
    break;

  case 71: /* cabecera_funcion: IDENTIFIER PARENT_START  */
#line 165 "src/gramatica.y"
                                           { Check_FunctionCall(yyvsp[-1]); }
#line 1877 "src/gramatica.tab.c"
    break;

  case 72: /* argumentos_funcion: Lista_expresiones PARENT_END  */
#line 166 "src/gramatica.y"
                                                  { TS_FunctionCall(&yyval); }
#line 1883 "src/gramatica.tab.c"
    break;

  case 73: /* argumentos_funcion: PARENT_END  */
#line 167 "src/gramatica.y"
                                { TS_FunctionCall(&yyval); }
#line 1889 "src/gramatica.tab.c"
    break;

  case 74: /* Lista_expresiones: Lista_expresiones COMMA expresion  */
#line 168 "src/gramatica.y"
                                                      { TS_CheckParam(yyvsp[0]); }
#line 1895 "src/gramatica.tab.c"
    break;

  case 75: /* Lista_expresiones: expresion  */
#line 169 "src/gramatica.y"
                              { /* WIP correct? -> */ checkParams = 0; TS_CheckParam(yyvsp[0]); }
#line 1901 "src/gramatica.tab.c"
    break;

  case 78: /* constante_base: CONST_INT  */
#line 172 "src/gramatica.y"
                           { yyval.type = INT; }
#line 1907 "src/gramatica.tab.c"
    break;

  case 79: /* constante_base: CONST_FLOAT  */
#line 173 "src/gramatica.y"
                             { yyval.type = FLOAT; }
#line 1913 "src/gramatica.tab.c"
    break;

  case 80: /* constante_base: CONST_BOOL  */
#line 174 "src/gramatica.y"
                            { yyval.type = BOOLEAN; }
#line 1919 "src/gramatica.tab.c"
    break;

  case 81: /* constante_base: CONST_CHAR  */
#line 175 "src/gramatica.y"
                            { yyval.type = CHAR; }
#line 1925 "src/gramatica.tab.c"
    break;

  case 82: /* constante_lista: BRACKET_START constante_lista_int BRACKET_END  */
#line 176 "src/gramatica.y"
                                                                { yyval.type = LIST_INT; yyval.nDim = yyvsp[-1].nDim; }
#line 1931 "src/gramatica.tab.c"
    break;

  case 83: /* constante_lista: BRACKET_START constante_lista_float BRACKET_END  */
#line 177 "src/gramatica.y"
                                                                  { yyval.type = LIST_FLOAT; yyval.nDim = yyvsp[-1].nDim; }
#line 1937 "src/gramatica.tab.c"
    break;

  case 84: /* constante_lista: BRACKET_START constante_lista_bool BRACKET_END  */
#line 178 "src/gramatica.y"
                                                                 { yyval.type = LIST_BOOLEAN; yyval.nDim = yyvsp[-1].nDim; }
#line 1943 "src/gramatica.tab.c"
    break;

  case 85: /* constante_lista: BRACKET_START constante_lista_char BRACKET_END  */
#line 179 "src/gramatica.y"
                                                                 { yyval.type = LIST_CHAR; yyval.nDim = yyvsp[-1].nDim; }
#line 1949 "src/gramatica.tab.c"
    break;


#line 1953 "src/gramatica.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 189 "src/gramatica.y"


#ifdef DOSWINDOWS /* Variable de entorno que indica la plataforma */
#include "lexyy.c"
#else
#include "lex.yy.c"
#endif

void yyerror(const char *msg) {
  fprintf(stderr, "[SYNTACTIC ERROR] Line %d: %s\n", yylineno, msg) ;
}
