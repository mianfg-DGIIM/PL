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
  YYSYMBOL_PARENT_END = 4,                 /* PARENT_END  */
  YYSYMBOL_BLOCK_START = 5,                /* BLOCK_START  */
  YYSYMBOL_BLOCK_END = 6,                  /* BLOCK_END  */
  YYSYMBOL_BRACKET_START = 7,              /* BRACKET_START  */
  YYSYMBOL_BRACKET_END = 8,                /* BRACKET_END  */
  YYSYMBOL_COLON = 9,                      /* COLON  */
  YYSYMBOL_COMMA = 10,                     /* COMMA  */
  YYSYMBOL_ASSIGN = 11,                    /* ASSIGN  */
  YYSYMBOL_IF = 12,                        /* IF  */
  YYSYMBOL_ELSE = 13,                      /* ELSE  */
  YYSYMBOL_WHILE = 14,                     /* WHILE  */
  YYSYMBOL_RETURN = 15,                    /* RETURN  */
  YYSYMBOL_FOR = 16,                       /* FOR  */
  YYSYMBOL_TO = 17,                        /* TO  */
  YYSYMBOL_OUTPUT = 18,                    /* OUTPUT  */
  YYSYMBOL_INPUT = 19,                     /* INPUT  */
  YYSYMBOL_BEGIN_LOCAL = 20,               /* BEGIN_LOCAL  */
  YYSYMBOL_END_LOCAL = 21,                 /* END_LOCAL  */
  YYSYMBOL_LIST_OF = 22,                   /* LIST_OF  */
  YYSYMBOL_TYPE = 23,                      /* TYPE  */
  YYSYMBOL_STRING = 24,                    /* STRING  */
  YYSYMBOL_AT = 25,                        /* AT  */
  YYSYMBOL_OP_BINARY_OR = 26,              /* OP_BINARY_OR  */
  YYSYMBOL_OP_BINARY_AND = 27,             /* OP_BINARY_AND  */
  YYSYMBOL_OP_BINARY_EQ = 28,              /* OP_BINARY_EQ  */
  YYSYMBOL_OP_BINARY_REL = 29,             /* OP_BINARY_REL  */
  YYSYMBOL_PLUS_MINUS = 30,                /* PLUS_MINUS  */
  YYSYMBOL_OP_BINARY_MUL = 31,             /* OP_BINARY_MUL  */
  YYSYMBOL_OP_UNARY_NEG = 32,              /* OP_UNARY_NEG  */
  YYSYMBOL_OP_UNARY_COUNT = 33,            /* OP_UNARY_COUNT  */
  YYSYMBOL_OP_UNARY_QUEST = 34,            /* OP_UNARY_QUEST  */
  YYSYMBOL_MINUS_MINUS = 35,               /* MINUS_MINUS  */
  YYSYMBOL_PLUS_PLUS = 36,                 /* PLUS_PLUS  */
  YYSYMBOL_DOLLAR = 37,                    /* DOLLAR  */
  YYSYMBOL_OP_LIST = 38,                   /* OP_LIST  */
  YYSYMBOL_CONST_INT = 39,                 /* CONST_INT  */
  YYSYMBOL_CONST_FLOAT = 40,               /* CONST_FLOAT  */
  YYSYMBOL_CONST_BOOL = 41,                /* CONST_BOOL  */
  YYSYMBOL_CONST_CHAR = 42,                /* CONST_CHAR  */
  YYSYMBOL_IDENTIFIER = 43,                /* IDENTIFIER  */
  YYSYMBOL_PARENT_START = 44,              /* PARENT_START  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_Programa = 46,                  /* Programa  */
  YYSYMBOL_47_1 = 47,                      /* $@1  */
  YYSYMBOL_bloque = 48,                    /* bloque  */
  YYSYMBOL_49_2 = 49,                      /* $@2  */
  YYSYMBOL_50_3 = 50,                      /* $@3  */
  YYSYMBOL_bloque_in = 51,                 /* bloque_in  */
  YYSYMBOL_52_4 = 52,                      /* $@4  */
  YYSYMBOL_53_5 = 53,                      /* $@5  */
  YYSYMBOL_Declar_de_subprogs = 54,        /* Declar_de_subprogs  */
  YYSYMBOL_Declar_subprog = 55,            /* Declar_subprog  */
  YYSYMBOL_56_6 = 56,                      /* $@6  */
  YYSYMBOL_Declar_de_variables_locales = 57, /* Declar_de_variables_locales  */
  YYSYMBOL_58_7 = 58,                      /* $@7  */
  YYSYMBOL_Variables_locales = 59,         /* Variables_locales  */
  YYSYMBOL_Cuerpo_declar_variables = 60,   /* Cuerpo_declar_variables  */
  YYSYMBOL_61_8 = 61,                      /* $@8  */
  YYSYMBOL_Cabecera_subprograma = 62,      /* Cabecera_subprograma  */
  YYSYMBOL_63_9 = 63,                      /* $@9  */
  YYSYMBOL_64_10 = 64,                     /* $@10  */
  YYSYMBOL_lista_de_parametros = 65,       /* lista_de_parametros  */
  YYSYMBOL_parametro = 66,                 /* parametro  */
  YYSYMBOL_Sentencias = 67,                /* Sentencias  */
  YYSYMBOL_68_11 = 68,                     /* $@11  */
  YYSYMBOL_69_12 = 69,                     /* $@12  */
  YYSYMBOL_Sentencia = 70,                 /* Sentencia  */
  YYSYMBOL_71_13 = 71,                     /* $@13  */
  YYSYMBOL_72_14 = 72,                     /* $@14  */
  YYSYMBOL_73_15 = 73,                     /* $@15  */
  YYSYMBOL_74_16 = 74,                     /* $@16  */
  YYSYMBOL_75_17 = 75,                     /* $@17  */
  YYSYMBOL_76_18 = 76,                     /* $@18  */
  YYSYMBOL_77_19 = 77,                     /* $@19  */
  YYSYMBOL_78_20 = 78,                     /* $@20  */
  YYSYMBOL_Sentencia_asignacion = 79,      /* Sentencia_asignacion  */
  YYSYMBOL_Sentencia_if = 80,              /* Sentencia_if  */
  YYSYMBOL_81_21 = 81,                     /* $@21  */
  YYSYMBOL_Sentencia_while = 82,           /* Sentencia_while  */
  YYSYMBOL_83_22 = 83,                     /* $@22  */
  YYSYMBOL_Sentencia_entrada = 84,         /* Sentencia_entrada  */
  YYSYMBOL_Sentencia_salida = 85,          /* Sentencia_salida  */
  YYSYMBOL_Sentencia_return = 86,          /* Sentencia_return  */
  YYSYMBOL_87_23 = 87,                     /* @23  */
  YYSYMBOL_Sentencia_for = 88,             /* Sentencia_for  */
  YYSYMBOL_Sentencia_lista = 89,           /* Sentencia_lista  */
  YYSYMBOL_expresion = 90,                 /* expresion  */
  YYSYMBOL_funcion = 91,                   /* funcion  */
  YYSYMBOL_cabecera_funcion = 92,          /* cabecera_funcion  */
  YYSYMBOL_argumentos_funcion = 93,        /* argumentos_funcion  */
  YYSYMBOL_Lista_expresiones_o_cadena = 94, /* Lista_expresiones_o_cadena  */
  YYSYMBOL_constante = 95,                 /* constante  */
  YYSYMBOL_constante_base = 96,            /* constante_base  */
  YYSYMBOL_constante_lista = 97,           /* constante_lista  */
  YYSYMBOL_constante_lista_int = 98,       /* constante_lista_int  */
  YYSYMBOL_constante_lista_float = 99,     /* constante_lista_float  */
  YYSYMBOL_constante_lista_bool = 100,     /* constante_lista_bool  */
  YYSYMBOL_constante_lista_char = 101,     /* constante_lista_char  */
  YYSYMBOL_Lista_expresiones = 102,        /* Lista_expresiones  */
  YYSYMBOL_tipo = 103,                     /* tipo  */
  YYSYMBOL_lista_variables = 104           /* lista_variables  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   303

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  118
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  199

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    45,    45,    45,    47,    49,    47,    52,    51,    62,
      61,    71,    72,    73,    73,    75,    75,    76,    77,    78,
      79,    79,    80,    81,    84,    81,    85,    86,    87,    88,
      89,    90,    90,    91,    91,    92,    92,    98,    99,    99,
     100,   100,   109,   109,   115,   115,   121,   121,   127,   127,
     133,   133,   139,   148,   157,   157,   165,   165,   175,   176,
     177,   178,   178,   180,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236
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
  "\"end of file\"", "error", "\"invalid token\"", "MAIN", "PARENT_END",
  "BLOCK_START", "BLOCK_END", "BRACKET_START", "BRACKET_END", "COLON",
  "COMMA", "ASSIGN", "IF", "ELSE", "WHILE", "RETURN", "FOR", "TO",
  "OUTPUT", "INPUT", "BEGIN_LOCAL", "END_LOCAL", "LIST_OF", "TYPE",
  "STRING", "AT", "OP_BINARY_OR", "OP_BINARY_AND", "OP_BINARY_EQ",
  "OP_BINARY_REL", "PLUS_MINUS", "OP_BINARY_MUL", "OP_UNARY_NEG",
  "OP_UNARY_COUNT", "OP_UNARY_QUEST", "MINUS_MINUS", "PLUS_PLUS", "DOLLAR",
  "OP_LIST", "CONST_INT", "CONST_FLOAT", "CONST_BOOL", "CONST_CHAR",
  "IDENTIFIER", "PARENT_START", "$accept", "Programa", "$@1", "bloque",
  "$@2", "$@3", "bloque_in", "$@4", "$@5", "Declar_de_subprogs",
  "Declar_subprog", "$@6", "Declar_de_variables_locales", "$@7",
  "Variables_locales", "Cuerpo_declar_variables", "$@8",
  "Cabecera_subprograma", "$@9", "$@10", "lista_de_parametros",
  "parametro", "Sentencias", "$@11", "$@12", "Sentencia", "$@13", "$@14",
  "$@15", "$@16", "$@17", "$@18", "$@19", "$@20", "Sentencia_asignacion",
  "Sentencia_if", "$@21", "Sentencia_while", "$@22", "Sentencia_entrada",
  "Sentencia_salida", "Sentencia_return", "@23", "Sentencia_for",
  "Sentencia_lista", "expresion", "funcion", "cabecera_funcion",
  "argumentos_funcion", "Lista_expresiones_o_cadena", "constante",
  "constante_base", "constante_lista", "constante_lista_int",
  "constante_lista_float", "constante_lista_bool", "constante_lista_char",
  "Lista_expresiones", "tipo", "lista_variables", YY_NULLPTR
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
     295,   296,   297,   298,   299
};
#endif

#define YYPACT_NINF (-59)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-51)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -59,    12,    22,   -59,    10,   -59,   -59,    15,   -59,    76,
      81,     8,   -59,   -59,   -59,   -59,    78,   -59,    33,   -59,
     -59,   -59,    39,    39,   -59,   -59,   -59,    82,   -59,   -59,
     142,   215,   115,   -59,    37,    10,   215,    68,   -59,    10,
     173,   184,   183,   191,   197,   206,   -30,   -59,   -59,   170,
     -59,   192,   -59,   -59,    73,   -59,   199,   -59,   200,   -59,
      16,   -59,     9,   -59,    73,   -59,   202,   -59,   210,   216,
     -59,   222,   -59,   -59,   -59,    36,    73,    73,    73,    73,
      73,    73,   -59,   -59,   -59,   -59,   223,    73,    93,   -59,
      56,   -59,   -59,   -59,    73,    73,   247,   140,   -59,   234,
      84,   234,   257,   269,   270,     4,   -59,   -59,   -59,   -59,
     122,   145,   146,   213,   134,   134,   134,   134,   134,   244,
     -59,   136,   -59,    73,    73,    73,    73,    73,    73,    73,
      73,    73,   -59,   234,   -59,     7,   148,   164,    82,   -59,
     -59,   103,   281,    73,   -59,   -59,   -59,    54,   -59,   252,
     -59,   259,   -59,   260,   -59,   255,   -59,   261,   -59,   234,
     256,   220,   151,   258,   175,   134,   134,   246,   -59,    73,
     215,   -59,   187,   -59,   234,   -59,   211,   -59,    39,   -59,
     -59,   -59,   -59,   -59,    73,   234,   284,   215,   -59,    73,
     -59,   -59,   234,   -59,   -59,   189,   215,   -59,   -59
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,     4,     3,    17,    15,     0,
       7,     0,     5,    12,    12,    22,     0,   114,     0,    19,
      20,     6,    33,    10,   115,    16,    18,     0,    11,    13,
      31,    35,     0,   117,     0,     0,    35,     0,    34,     0,
       0,     0,     0,     0,     0,     0,     0,    37,    23,     0,
      21,     0,    14,    32,     0,    36,     0,    39,     0,    41,
       0,    43,     0,    45,     0,    47,     0,    49,     0,     0,
      51,     0,   118,   116,    85,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,    99,    80,     0,     0,    82,
       0,    81,    94,    95,     0,     0,     0,     0,    93,    92,
       0,    61,     0,     0,     0,     0,   105,   107,   109,   111,
       0,     0,     0,     0,    72,    66,    67,    68,    70,    69,
      87,     0,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    89,   113,    86,     0,     0,     0,     0,    59,
      60,     0,     0,     0,    65,    64,    29,     0,    27,     0,
     100,     0,   101,     0,   102,     0,   103,     0,    84,    78,
      75,    74,    77,    76,    71,    73,    79,     0,    88,     0,
      35,    56,     0,    91,    90,    62,     0,    24,     0,    30,
     104,   106,   108,   110,     0,   112,    53,    35,    58,     0,
      25,    26,    83,    54,    57,    35,    35,    63,    55
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -59,   -59,   -59,   -11,   -59,   -59,   -59,   -59,   -59,   285,
     -59,   -59,   -59,   -59,   -59,   283,   -59,   -59,   -59,   -59,
     -59,   124,   -59,   -59,   -59,   -36,   -59,   -59,   -59,   -59,
     -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,
     -59,   -59,   -59,   -59,   -59,   -58,   -59,   -59,   -59,   -59,
     -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -21,   -57
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     6,     7,    21,     9,    13,    14,    22,
      28,    35,    10,    11,    18,    19,    27,    29,    71,   190,
     147,   148,    30,    36,    31,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    57,   196,    59,   187,    61,
      63,    65,   142,    67,    70,    88,    89,    90,   134,   100,
      91,    92,    93,   110,   111,   112,   113,   135,    20,    34
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,    32,    32,    97,    99,   146,   101,    68,   -28,    15,
      74,   168,     3,    69,   -28,     5,    75,   169,   114,   115,
     116,   117,   118,   119,    52,     4,    16,    17,    55,   121,
      16,    17,   133,    98,    15,     8,   136,   137,    49,    76,
      96,    77,    78,    79,    80,    81,    50,    51,    82,    83,
      84,    85,    86,    87,    25,    16,    17,    74,   177,    33,
     132,    16,    17,    75,   178,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    74,   106,   107,   108,   109,    54,
      75,   172,    12,   174,   149,   176,    76,    -9,    77,    78,
      79,    80,    81,   140,   141,    82,    83,    84,    85,    86,
      87,    24,   122,    76,    74,    77,    78,    79,    80,    81,
      75,   185,    82,    83,    84,    85,    86,    87,   123,   124,
     125,   126,   127,   128,   129,    33,   192,   173,   130,   131,
     150,   195,   151,    76,   186,    77,    78,    79,    80,    81,
     158,    49,    82,    83,    84,    85,    86,    87,    -8,   139,
      51,   194,   170,   152,   154,   153,   155,   149,    48,   197,
     198,   123,   124,   125,   126,   127,   128,   129,   171,   130,
     131,   130,   131,   123,   124,   125,   126,   127,   128,   129,
     127,   128,   129,   130,   131,    56,   130,   131,    49,   123,
     124,   125,   126,   127,   128,   129,   188,    51,    58,   130,
     131,   -38,    60,   -40,   -46,   -48,   129,   -44,   -42,    62,
     130,   131,    64,    72,   123,   124,   125,   126,   127,   128,
     129,   156,    66,   157,   130,   131,   -50,   -38,   189,   -40,
     -46,   -48,    37,   -44,   -42,    73,   123,   124,   125,   126,
     127,   128,   129,    94,    95,   102,   130,   131,   126,   127,
     128,   129,   -50,   103,   104,   130,   131,   138,    37,   123,
     124,   125,   126,   127,   128,   129,   105,   120,   143,   130,
     131,   184,   124,   125,   126,   127,   128,   129,   144,   145,
     131,   130,   131,   125,   126,   127,   128,   129,   128,   129,
     175,   130,   131,   130,   131,   179,   182,   193,   180,    23,
     181,    26,   191,   183
};

static const yytype_uint8 yycheck[] =
{
      36,    22,    23,    60,    62,     1,    64,    37,     4,     1,
       1,     4,     0,    43,    10,     5,     7,    10,    76,    77,
      78,    79,    80,    81,    35,     3,    22,    23,    39,    87,
      22,    23,    90,    24,     1,    20,    94,    95,     1,    30,
      24,    32,    33,    34,    35,    36,     9,    10,    39,    40,
      41,    42,    43,    44,    21,    22,    23,     1,     4,    43,
       4,    22,    23,     7,    10,   123,   124,   125,   126,   127,
     128,   129,   130,   131,     1,    39,    40,    41,    42,    11,
       7,   138,     6,   141,   105,   143,    30,     6,    32,    33,
      34,    35,    36,     9,    10,    39,    40,    41,    42,    43,
      44,    23,     9,    30,     1,    32,    33,    34,    35,    36,
       7,   169,    39,    40,    41,    42,    43,    44,    25,    26,
      27,    28,    29,    30,    31,    43,   184,    24,    35,    36,
       8,   189,    10,    30,   170,    32,    33,    34,    35,    36,
       4,     1,    39,    40,    41,    42,    43,    44,     6,     9,
      10,   187,     4,     8,     8,    10,    10,   178,    43,   195,
     196,    25,    26,    27,    28,    29,    30,    31,     4,    35,
      36,    35,    36,    25,    26,    27,    28,    29,    30,    31,
      29,    30,    31,    35,    36,    12,    35,    36,     1,    25,
      26,    27,    28,    29,    30,    31,     9,    10,    14,    35,
      36,    12,    19,    14,    15,    16,    31,    18,    19,    18,
      35,    36,    15,    43,    25,    26,    27,    28,    29,    30,
      31,     8,    16,    10,    35,    36,    37,    12,    17,    14,
      15,    16,    43,    18,    19,    43,    25,    26,    27,    28,
      29,    30,    31,    44,    44,    43,    35,    36,    28,    29,
      30,    31,    37,    43,    38,    35,    36,    10,    43,    25,
      26,    27,    28,    29,    30,    31,    44,    44,    11,    35,
      36,    25,    26,    27,    28,    29,    30,    31,     9,     9,
      36,    35,    36,    27,    28,    29,    30,    31,    30,    31,
       9,    35,    36,    35,    36,    43,    41,    13,    39,    14,
      40,    18,   178,    42
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    46,    47,     0,     3,     5,    48,    49,    20,    51,
      57,    58,     6,    52,    53,     1,    22,    23,    59,    60,
     103,    50,    54,    54,    23,    21,    60,    61,    55,    62,
      67,    69,   103,    43,   104,    56,    68,    43,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    43,     1,
       9,    10,    48,    70,    11,    48,    12,    80,    14,    82,
      19,    84,    18,    85,    15,    86,    16,    88,    37,    43,
      89,    63,    43,    43,     1,     7,    30,    32,    33,    34,
      35,    36,    39,    40,    41,    42,    43,    44,    90,    91,
      92,    95,    96,    97,    44,    44,    24,   104,    24,    90,
      94,    90,    43,    43,    38,    44,    39,    40,    41,    42,
      98,    99,   100,   101,    90,    90,    90,    90,    90,    90,
      44,    90,     9,    25,    26,    27,    28,    29,    30,    31,
      35,    36,     4,    90,    93,   102,    90,    90,    10,     9,
       9,    10,    87,    11,     9,     9,     1,    65,    66,   103,
       8,    10,     8,    10,     8,    10,     8,    10,     4,    90,
      90,    90,    90,    90,    90,    90,    90,    90,     4,    10,
       4,     4,   104,    24,    90,     9,    90,     4,    10,    43,
      39,    40,    41,    42,    25,    90,    70,    83,     9,    17,
      64,    66,    90,    13,    70,    90,    81,    70,    70
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    47,    46,    49,    50,    48,    52,    51,    53,
      51,    54,    54,    56,    55,    58,    57,    57,    59,    59,
      61,    60,    60,    63,    64,    62,    65,    65,    65,    65,
      66,    68,    67,    69,    67,    71,    70,    70,    72,    70,
      73,    70,    74,    70,    75,    70,    76,    70,    77,    70,
      78,    70,    79,    80,    81,    80,    83,    82,    84,    84,
      85,    87,    86,    88,    89,    89,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    91,    92,    93,    93,
      94,    94,    94,    94,    95,    95,    96,    96,    96,    96,
      97,    97,    97,    97,    98,    98,    99,    99,   100,   100,
     101,   101,   102,   102,   103,   103,   104,   104,   104
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     0,     0,     5,     0,     4,     0,
       3,     2,     0,     0,     3,     0,     4,     0,     2,     1,
       0,     4,     1,     0,     0,     7,     3,     1,     0,     1,
       2,     0,     3,     0,     2,     0,     2,     1,     0,     2,
       0,     2,     0,     2,     0,     2,     0,     2,     0,     2,
       0,     2,     4,     5,     0,     8,     0,     6,     5,     3,
       3,     0,     4,     7,     3,     3,     2,     2,     2,     2,
       2,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     5,     3,     1,     2,     2,     2,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     1,     2,     3,     1,     3
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
  case 2: /* $@1: %empty  */
#line 45 "src/gramatica.y"
          {generateIntermedio();}
#line 1626 "src/gramatica.tab.c"
    break;

  case 3: /* Programa: $@1 MAIN bloque  */
#line 45 "src/gramatica.y"
                                              {closeIntermedio();}
#line 1632 "src/gramatica.tab.c"
    break;

  case 4: /* $@2: %empty  */
#line 47 "src/gramatica.y"
                     { TS_AddMark(); }
#line 1638 "src/gramatica.tab.c"
    break;

  case 5: /* $@3: %empty  */
#line 49 "src/gramatica.y"
                    { fputs("\n}\n",file); }
#line 1644 "src/gramatica.tab.c"
    break;

  case 6: /* bloque: BLOCK_START $@2 bloque_in BLOCK_END $@3  */
#line 49 "src/gramatica.y"
                                             { TS_ClearBlock(); }
#line 1650 "src/gramatica.tab.c"
    break;

  case 7: /* $@4: %empty  */
#line 52 "src/gramatica.y"
              {
                if(varPrinc==1){
                  varPrinc=0;
                  fputs("int main(){\n",file); 
                }
               
              }
#line 1662 "src/gramatica.tab.c"
    break;

  case 9: /* $@5: %empty  */
#line 62 "src/gramatica.y"
              {
                if(varPrinc==1){
                  varPrinc=0;
                  fputs("int main(){\n",file); 
                }
               
              }
#line 1674 "src/gramatica.tab.c"
    break;

  case 13: /* $@6: %empty  */
#line 73 "src/gramatica.y"
                                      { esFunc = 1; }
#line 1680 "src/gramatica.tab.c"
    break;

  case 14: /* Declar_subprog: Cabecera_subprograma $@6 bloque  */
#line 74 "src/gramatica.y"
                        { esFunc = 0; }
#line 1686 "src/gramatica.tab.c"
    break;

  case 15: /* $@7: %empty  */
#line 75 "src/gramatica.y"
                                          { decVar = 1; }
#line 1692 "src/gramatica.tab.c"
    break;

  case 16: /* Declar_de_variables_locales: BEGIN_LOCAL $@7 Variables_locales END_LOCAL  */
#line 75 "src/gramatica.y"
                                                                                      { decVar = 0; }
#line 1698 "src/gramatica.tab.c"
    break;

  case 20: /* $@8: %empty  */
#line 79 "src/gramatica.y"
                               { setType(yyvsp[0]); }
#line 1704 "src/gramatica.tab.c"
    break;

  case 23: /* $@9: %empty  */
#line 81 "src/gramatica.y"
                                       { setType(yyvsp[-1]); decParam = 1; TS_AddFunction(yyvsp[0]); }
#line 1710 "src/gramatica.tab.c"
    break;

  case 24: /* $@10: %empty  */
#line 84 "src/gramatica.y"
                                  { fputs(")",file); }
#line 1716 "src/gramatica.tab.c"
    break;

  case 25: /* Cabecera_subprograma: tipo IDENTIFIER $@9 PARENT_START lista_de_parametros PARENT_END $@10  */
#line 84 "src/gramatica.y"
                                                        { decParam = 0; yyvsp[-3].nDim = 0; /*WIP*/ }
#line 1722 "src/gramatica.tab.c"
    break;

  case 30: /* parametro: tipo IDENTIFIER  */
#line 89 "src/gramatica.y"
                            { /* WIP CHECK $2.nDim=0; */ setType(yyvsp[-1]); TS_AddParam(yyvsp[0]); }
#line 1728 "src/gramatica.tab.c"
    break;

  case 31: /* $@11: %empty  */
#line 90 "src/gramatica.y"
                        {decVar = 2; }
#line 1734 "src/gramatica.tab.c"
    break;

  case 33: /* $@12: %empty  */
#line 91 "src/gramatica.y"
             { decVar = 2; }
#line 1740 "src/gramatica.tab.c"
    break;

  case 35: /* $@13: %empty  */
#line 92 "src/gramatica.y"
            {	if(decIF==1){
                {insertCond(1);}
                fputs("{\n",file);
                decIF++;
              }  
				    }
#line 1751 "src/gramatica.tab.c"
    break;

  case 38: /* $@14: %empty  */
#line 99 "src/gramatica.y"
            { decIF=1;insertDesc(1);}
#line 1757 "src/gramatica.tab.c"
    break;

  case 39: /* Sentencia: $@14 Sentencia_if  */
#line 99 "src/gramatica.y"
                                                   {decIF = 0;eliminaDesc();}
#line 1763 "src/gramatica.tab.c"
    break;

  case 40: /* $@15: %empty  */
#line 100 "src/gramatica.y"
            {	if(decIF==1){
                insertCond(1);
                fputs("{\n",file);
                decIF++;
						  }
              insertDesc(2);
              insertEtiqInput();
              fputs("{\n",file);
					  }
#line 1777 "src/gramatica.tab.c"
    break;

  case 42: /* $@16: %empty  */
#line 109 "src/gramatica.y"
            {	if(decIF==1){
                insertCond(1);
                fputs("{\n",file);
                decIF++;
						  }
					}
#line 1788 "src/gramatica.tab.c"
    break;

  case 44: /* $@17: %empty  */
#line 115 "src/gramatica.y"
            {if(decIF==1){
							insertCond(1);
							fputs("{\n",file);
							decIF++;
						}
					  }
#line 1799 "src/gramatica.tab.c"
    break;

  case 46: /* $@18: %empty  */
#line 121 "src/gramatica.y"
            {if(decIF==1){
							insertCond(1);
							fputs("{\n",file);
							decIF++;
						}
					}
#line 1810 "src/gramatica.tab.c"
    break;

  case 48: /* $@19: %empty  */
#line 127 "src/gramatica.y"
            {if(decIF==1){
							insertCond(1);
							fputs("{\n",file);
							decIF++;
						}
					}
#line 1821 "src/gramatica.tab.c"
    break;

  case 50: /* $@20: %empty  */
#line 133 "src/gramatica.y"
            {if(decIF==1){
							insertCond(1);
							fputs("{\n",file);
							decIF++;
						}
					}
#line 1832 "src/gramatica.tab.c"
    break;

  case 52: /* Sentencia_asignacion: IDENTIFIER ASSIGN expresion COLON  */
#line 139 "src/gramatica.y"
                                                         { 
                  Check_Assign(yyvsp[-3], yyvsp[-1]); 
                  if(decIF==1){
                    insertCond(1);
                    fputs("{\n",file);
                    decIF++;
                  }
		              generate(4,yyvsp[-3],yyvsp[-2],yyvsp[-1],yyvsp[0]);
                }
#line 1846 "src/gramatica.tab.c"
    break;

  case 53: /* Sentencia_if: IF PARENT_START expresion PARENT_END Sentencia  */
#line 148 "src/gramatica.y"
                                                              { 
                Check_Boolean(yyvsp[-2]);
                
                yyval.lex = yyvsp[-2].lex;
                fputs("}\n",file);
                insertEtiqElse();
                fputs("{}\n",file);
					     
              }
#line 1860 "src/gramatica.tab.c"
    break;

  case 54: /* $@21: %empty  */
#line 157 "src/gramatica.y"
                                                                     {
                decElse=1; 
                fputs("}\n",file);
                insertEtiqElse();
                fputs("{\n",file);
                decElse=0;
                }
#line 1872 "src/gramatica.tab.c"
    break;

  case 55: /* Sentencia_if: IF PARENT_START expresion PARENT_END Sentencia ELSE $@21 Sentencia  */
#line 164 "src/gramatica.y"
                          { Check_Boolean(yyvsp[-5]);fputs("}\n",file);insertEtiqOutput();fputs("{}\n",file);}
#line 1878 "src/gramatica.tab.c"
    break;

  case 56: /* $@22: %empty  */
#line 165 "src/gramatica.y"
                                                          {insertCond(2);}
#line 1884 "src/gramatica.tab.c"
    break;

  case 57: /* Sentencia_while: WHILE PARENT_START expresion PARENT_END $@22 Sentencia  */
#line 165 "src/gramatica.y"
                                                                                     { 
                    Check_Boolean(yyvsp[-3]); 

                    yyval.lex = yyvsp[-3].lex;
                    fputs("}\n",file);
                    insertGotoInput();
                    insertEtiqOutput();
                    fputs("{}\n",file);
                    
                  }
#line 1899 "src/gramatica.tab.c"
    break;

  case 58: /* Sentencia_entrada: INPUT STRING COMMA lista_variables COLON  */
#line 175 "src/gramatica.y"
                                                             {generateEntSal(1,yyvsp[-3]);}
#line 1905 "src/gramatica.tab.c"
    break;

  case 59: /* Sentencia_entrada: INPUT lista_variables COLON  */
#line 176 "src/gramatica.y"
                                                {generateEntSal(1,yyvsp[-1]);}
#line 1911 "src/gramatica.tab.c"
    break;

  case 60: /* Sentencia_salida: OUTPUT Lista_expresiones_o_cadena COLON  */
#line 177 "src/gramatica.y"
                                                           {generateEntSal(2,yyvsp[-1]);}
#line 1917 "src/gramatica.tab.c"
    break;

  case 61: /* @23: %empty  */
#line 178 "src/gramatica.y"
                                    { TS_CheckReturn(yyvsp[0], &yyval); }
#line 1923 "src/gramatica.tab.c"
    break;

  case 63: /* Sentencia_for: FOR IDENTIFIER ASSIGN expresion TO expresion Sentencia  */
#line 180 "src/gramatica.y"
                                                                       { Check_Int(yyvsp[-3]); Check_Int(yyvsp[-1]); }
#line 1929 "src/gramatica.tab.c"
    break;

  case 64: /* Sentencia_lista: IDENTIFIER OP_LIST COLON  */
#line 182 "src/gramatica.y"
                                           { Check_ListSentence(yyvsp[-2]); }
#line 1935 "src/gramatica.tab.c"
    break;

  case 65: /* Sentencia_lista: DOLLAR IDENTIFIER COLON  */
#line 183 "src/gramatica.y"
                                          { Check_ListSentence(yyvsp[-1]); }
#line 1941 "src/gramatica.tab.c"
    break;

  case 66: /* expresion: OP_UNARY_NEG expresion  */
#line 184 "src/gramatica.y"
                                   { Check_OpUnaryNeg(yyvsp[-1], yyvsp[0], &yyval); }
#line 1947 "src/gramatica.tab.c"
    break;

  case 67: /* expresion: OP_UNARY_COUNT expresion  */
#line 185 "src/gramatica.y"
                                     { Check_OpUnaryCount(yyvsp[-1], yyvsp[0], &yyval); }
#line 1953 "src/gramatica.tab.c"
    break;

  case 68: /* expresion: OP_UNARY_QUEST expresion  */
#line 186 "src/gramatica.y"
                                     { Check_OpUnaryQuest(yyvsp[-1], yyvsp[0], &yyval); }
#line 1959 "src/gramatica.tab.c"
    break;

  case 69: /* expresion: PLUS_PLUS expresion  */
#line 187 "src/gramatica.y"
                                { Check_IncrementDecrement(yyvsp[-1], yyvsp[0], &yyval); }
#line 1965 "src/gramatica.tab.c"
    break;

  case 70: /* expresion: MINUS_MINUS expresion  */
#line 188 "src/gramatica.y"
                                  { Check_IncrementDecrement(yyvsp[-1], yyvsp[0], &yyval); }
#line 1971 "src/gramatica.tab.c"
    break;

  case 71: /* expresion: expresion PLUS_MINUS expresion  */
#line 189 "src/gramatica.y"
                                           { Check_PlusMinusBinary(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); }
#line 1977 "src/gramatica.tab.c"
    break;

  case 72: /* expresion: PLUS_MINUS expresion  */
#line 190 "src/gramatica.y"
                                                    { Check_PlusMinus(yyvsp[-1], yyvsp[0], &yyval); }
#line 1983 "src/gramatica.tab.c"
    break;

  case 73: /* expresion: expresion OP_BINARY_MUL expresion  */
#line 191 "src/gramatica.y"
                                              { Check_OpBinaryMul(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); }
#line 1989 "src/gramatica.tab.c"
    break;

  case 74: /* expresion: expresion OP_BINARY_AND expresion  */
#line 192 "src/gramatica.y"
                                              { Check_OpBinaryAndOr(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); }
#line 1995 "src/gramatica.tab.c"
    break;

  case 75: /* expresion: expresion OP_BINARY_OR expresion  */
#line 193 "src/gramatica.y"
                                             { Check_OpBinaryAndOr(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); }
#line 2001 "src/gramatica.tab.c"
    break;

  case 76: /* expresion: expresion OP_BINARY_REL expresion  */
#line 194 "src/gramatica.y"
                                               { Check_OpBinaryRel(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); }
#line 2007 "src/gramatica.tab.c"
    break;

  case 77: /* expresion: expresion OP_BINARY_EQ expresion  */
#line 195 "src/gramatica.y"
                                             { Check_OpBinaryEq(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); }
#line 2013 "src/gramatica.tab.c"
    break;

  case 78: /* expresion: expresion AT expresion  */
#line 196 "src/gramatica.y"
                                   { Check_At(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); }
#line 2019 "src/gramatica.tab.c"
    break;

  case 79: /* expresion: expresion MINUS_MINUS expresion  */
#line 197 "src/gramatica.y"
                                            { Check_MinusMinus(yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); }
#line 2025 "src/gramatica.tab.c"
    break;

  case 80: /* expresion: IDENTIFIER  */
#line 198 "src/gramatica.y"
                       { generateDecVar(yyvsp[0]); yyval.type = TS_GetType(yyvsp[0]); yyval.nDim = TS_GetNDim(yyvsp[0]); decVar = 0; }
#line 2031 "src/gramatica.tab.c"
    break;

  case 81: /* expresion: constante  */
#line 199 "src/gramatica.y"
                      { yyval.type = yyvsp[0].type; yyval.nDim = yyvsp[0].nDim; }
#line 2037 "src/gramatica.tab.c"
    break;

  case 82: /* expresion: funcion  */
#line 200 "src/gramatica.y"
                    { yyval.type = yyvsp[0].type; yyval.nDim = yyvsp[0].nDim; currentFunction = -1; }
#line 2043 "src/gramatica.tab.c"
    break;

  case 83: /* expresion: expresion PLUS_PLUS expresion AT expresion  */
#line 201 "src/gramatica.y"
                                                       { Check_ListTernary(yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0], &yyval); }
#line 2049 "src/gramatica.tab.c"
    break;

  case 84: /* expresion: PARENT_START expresion PARENT_END  */
#line 202 "src/gramatica.y"
                                              { yyval.type = yyvsp[-1].type; yyval.nDim = yyvsp[-1].nDim; }
#line 2055 "src/gramatica.tab.c"
    break;

  case 86: /* funcion: cabecera_funcion argumentos_funcion  */
#line 204 "src/gramatica.y"
                                              { yyval.attr = yyvsp[0].attr; yyval.type = yyvsp[0].type, yyval.nDim = yyvsp[0].nDim; }
#line 2061 "src/gramatica.tab.c"
    break;

  case 87: /* cabecera_funcion: IDENTIFIER PARENT_START  */
#line 205 "src/gramatica.y"
                                           { Check_FunctionCall(yyvsp[-1]); }
#line 2067 "src/gramatica.tab.c"
    break;

  case 88: /* argumentos_funcion: Lista_expresiones PARENT_END  */
#line 206 "src/gramatica.y"
                                                  { TS_FunctionCall(&yyval); }
#line 2073 "src/gramatica.tab.c"
    break;

  case 89: /* argumentos_funcion: PARENT_END  */
#line 207 "src/gramatica.y"
                                { TS_FunctionCall(&yyval); }
#line 2079 "src/gramatica.tab.c"
    break;

  case 90: /* Lista_expresiones_o_cadena: Lista_expresiones_o_cadena COMMA expresion  */
#line 208 "src/gramatica.y"
                                                                        { nParams++; TS_CheckParam(yyvsp[-2]); }
#line 2085 "src/gramatica.tab.c"
    break;

  case 91: /* Lista_expresiones_o_cadena: Lista_expresiones_o_cadena COMMA STRING  */
#line 209 "src/gramatica.y"
                                                                     { nParams++; TS_CheckParam(yyvsp[-2]); }
#line 2091 "src/gramatica.tab.c"
    break;

  case 92: /* Lista_expresiones_o_cadena: expresion  */
#line 210 "src/gramatica.y"
                                       { nParams=1; TS_CheckParam(yyvsp[0]); }
#line 2097 "src/gramatica.tab.c"
    break;

  case 93: /* Lista_expresiones_o_cadena: STRING  */
#line 211 "src/gramatica.y"
                                    { nParams=1; TS_CheckParam(yyvsp[0]); }
#line 2103 "src/gramatica.tab.c"
    break;

  case 96: /* constante_base: CONST_INT  */
#line 214 "src/gramatica.y"
                           { yyval.type = INT; }
#line 2109 "src/gramatica.tab.c"
    break;

  case 97: /* constante_base: CONST_FLOAT  */
#line 215 "src/gramatica.y"
                             { yyval.type = FLOAT; }
#line 2115 "src/gramatica.tab.c"
    break;

  case 98: /* constante_base: CONST_BOOL  */
#line 216 "src/gramatica.y"
                            { yyval.type = BOOLEAN; }
#line 2121 "src/gramatica.tab.c"
    break;

  case 99: /* constante_base: CONST_CHAR  */
#line 217 "src/gramatica.y"
                            { yyval.type = CHAR; }
#line 2127 "src/gramatica.tab.c"
    break;

  case 100: /* constante_lista: BRACKET_START constante_lista_int BRACKET_END  */
#line 218 "src/gramatica.y"
                                                                { yyval.type = LIST_INT; yyval.nDim = yyvsp[-1].nDim; }
#line 2133 "src/gramatica.tab.c"
    break;

  case 101: /* constante_lista: BRACKET_START constante_lista_float BRACKET_END  */
#line 219 "src/gramatica.y"
                                                                  { yyval.type = LIST_FLOAT; yyval.nDim = yyvsp[-1].nDim; }
#line 2139 "src/gramatica.tab.c"
    break;

  case 102: /* constante_lista: BRACKET_START constante_lista_bool BRACKET_END  */
#line 220 "src/gramatica.y"
                                                                 { yyval.type = LIST_BOOLEAN; yyval.nDim = yyvsp[-1].nDim; }
#line 2145 "src/gramatica.tab.c"
    break;

  case 103: /* constante_lista: BRACKET_START constante_lista_char BRACKET_END  */
#line 221 "src/gramatica.y"
                                                                 { yyval.type = LIST_CHAR; yyval.nDim = yyvsp[-1].nDim; }
#line 2151 "src/gramatica.tab.c"
    break;

  case 112: /* Lista_expresiones: Lista_expresiones COMMA expresion  */
#line 230 "src/gramatica.y"
                                                      { TS_CheckParam(yyvsp[0]); }
#line 2157 "src/gramatica.tab.c"
    break;

  case 113: /* Lista_expresiones: expresion  */
#line 231 "src/gramatica.y"
                              { /* WIP correct? -> */ checkParams = 0; TS_CheckParam(yyvsp[0]); }
#line 2163 "src/gramatica.tab.c"
    break;

  case 114: /* tipo: TYPE  */
#line 232 "src/gramatica.y"
            { yyval.type = yyvsp[0].type; }
#line 2169 "src/gramatica.tab.c"
    break;

  case 115: /* tipo: LIST_OF TYPE  */
#line 233 "src/gramatica.y"
                    { yyval.type = getListType(yyvsp[0].type); }
#line 2175 "src/gramatica.tab.c"
    break;

  case 116: /* lista_variables: lista_variables COMMA IDENTIFIER  */
#line 234 "src/gramatica.y"
                                                   { VarList_Id(yyvsp[0], &yyval); }
#line 2181 "src/gramatica.tab.c"
    break;

  case 117: /* lista_variables: IDENTIFIER  */
#line 235 "src/gramatica.y"
                             { VarList_Id(yyvsp[0], &yyval); }
#line 2187 "src/gramatica.tab.c"
    break;


#line 2191 "src/gramatica.tab.c"

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

#line 238 "src/gramatica.y"


#ifdef DOSWINDOWS /* Variable de entorno que indica la plataforma */
#include "lexyy.c"
#else
#include "lex.yy.c"
#endif

void yyerror(const char *msg) {
  fprintf(stderr, "[SYNTACTIC ERROR @ line %d] %s\n", yylineno, msg) ;
}
