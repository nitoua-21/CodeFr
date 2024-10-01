/* A Bison parser, made by GNU Bison 3.8.2.  */

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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 8 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "ast.h"

void yyerror(const char *s);
int yylex(void);

StatementList *parsed_program = NULL;

#line 85 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ENTIER_VAL = 3,                 /* ENTIER_VAL  */
  YYSYMBOL_DECIMAL_VAL = 4,                /* DECIMAL_VAL  */
  YYSYMBOL_CHAINE = 5,                     /* CHAINE  */
  YYSYMBOL_STRING_VAL = 6,                 /* STRING_VAL  */
  YYSYMBOL_LOGIQUE_VAL = 7,                /* LOGIQUE_VAL  */
  YYSYMBOL_IDENTIFIANT = 8,                /* IDENTIFIANT  */
  YYSYMBOL_PLUS = 9,                       /* PLUS  */
  YYSYMBOL_MINUS = 10,                     /* MINUS  */
  YYSYMBOL_TIMES = 11,                     /* TIMES  */
  YYSYMBOL_DIVIDE = 12,                    /* DIVIDE  */
  YYSYMBOL_SI = 13,                        /* SI  */
  YYSYMBOL_ALORS = 14,                     /* ALORS  */
  YYSYMBOL_SINON = 15,                     /* SINON  */
  YYSYMBOL_SINONSI = 16,                   /* SINONSI  */
  YYSYMBOL_FINSI = 17,                     /* FINSI  */
  YYSYMBOL_EQUALS = 18,                    /* EQUALS  */
  YYSYMBOL_LPAREN = 19,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 20,                    /* RPAREN  */
  YYSYMBOL_VARIABLE_KWRD = 21,             /* VARIABLE_KWRD  */
  YYSYMBOL_ECRIRE = 22,                    /* ECRIRE  */
  YYSYMBOL_ALGORITHME = 23,                /* ALGORITHME  */
  YYSYMBOL_DEBUT = 24,                     /* DEBUT  */
  YYSYMBOL_FIN = 25,                       /* FIN  */
  YYSYMBOL_COLON = 26,                     /* COLON  */
  YYSYMBOL_LIRE = 27,                      /* LIRE  */
  YYSYMBOL_ENTIER_KWRD = 28,               /* ENTIER_KWRD  */
  YYSYMBOL_DECIMAL_KWRD = 29,              /* DECIMAL_KWRD  */
  YYSYMBOL_LOGIQUE_KWRD = 30,              /* LOGIQUE_KWRD  */
  YYSYMBOL_CHAINE_KWRD = 31,               /* CHAINE_KWRD  */
  YYSYMBOL_COMMA = 32,                     /* COMMA  */
  YYSYMBOL_COMMENT = 33,                   /* COMMENT  */
  YYSYMBOL_AND = 34,                       /* AND  */
  YYSYMBOL_OR = 35,                        /* OR  */
  YYSYMBOL_NOT = 36,                       /* NOT  */
  YYSYMBOL_XOR = 37,                       /* XOR  */
  YYSYMBOL_CONCAT = 38,                    /* CONCAT  */
  YYSYMBOL_LT = 39,                        /* LT  */
  YYSYMBOL_GT = 40,                        /* GT  */
  YYSYMBOL_LE = 41,                        /* LE  */
  YYSYMBOL_GE = 42,                        /* GE  */
  YYSYMBOL_EQ = 43,                        /* EQ  */
  YYSYMBOL_NE = 44,                        /* NE  */
  YYSYMBOL_TANTQUE = 45,                   /* TANTQUE  */
  YYSYMBOL_FAIRE = 46,                     /* FAIRE  */
  YYSYMBOL_FINTANTQUE = 47,                /* FINTANTQUE  */
  YYSYMBOL_POUR = 48,                      /* POUR  */
  YYSYMBOL_DE = 49,                        /* DE  */
  YYSYMBOL_A = 50,                         /* A  */
  YYSYMBOL_FINPOUR = 51,                   /* FINPOUR  */
  YYSYMBOL_POWER = 52,                     /* POWER  */
  YYSYMBOL_MODULO = 53,                    /* MODULO  */
  YYSYMBOL_CONSTANT = 54,                  /* CONSTANT  */
  YYSYMBOL_SELON = 55,                     /* SELON  */
  YYSYMBOL_FINSELON = 56,                  /* FINSELON  */
  YYSYMBOL_CAS = 57,                       /* CAS  */
  YYSYMBOL_SQUARE_ROOT = 58,               /* SQUARE_ROOT  */
  YYSYMBOL_SINE = 59,                      /* SINE  */
  YYSYMBOL_COSINE = 60,                    /* COSINE  */
  YYSYMBOL_TANGENT = 61,                   /* TANGENT  */
  YYSYMBOL_LOG = 62,                       /* LOG  */
  YYSYMBOL_LOG10 = 63,                     /* LOG10  */
  YYSYMBOL_ROUND = 64,                     /* ROUND  */
  YYSYMBOL_ABS = 65,                       /* ABS  */
  YYSYMBOL_INT = 66,                       /* INT  */
  YYSYMBOL_RANDOM = 67,                    /* RANDOM  */
  YYSYMBOL_LENGTH = 68,                    /* LENGTH  */
  YYSYMBOL_COMPARE = 69,                   /* COMPARE  */
  YYSYMBOL_CONCATENATE = 70,               /* CONCATENATE  */
  YYSYMBOL_COPY = 71,                      /* COPY  */
  YYSYMBOL_SEARCH = 72,                    /* SEARCH  */
  YYSYMBOL_YYACCEPT = 73,                  /* $accept  */
  YYSYMBOL_program = 74,                   /* program  */
  YYSYMBOL_Declarations = 75,              /* Declarations  */
  YYSYMBOL_Declaration = 76,               /* Declaration  */
  YYSYMBOL_statement_list = 77,            /* statement_list  */
  YYSYMBOL_statement = 78,                 /* statement  */
  YYSYMBOL_expression_list = 79,           /* expression_list  */
  YYSYMBOL_case_list = 80,                 /* case_list  */
  YYSYMBOL_expression = 81,                /* expression  */
  YYSYMBOL_type = 82                       /* type  */
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

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1216

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  73
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  10
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  186

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   327


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    74,    74,    77,    79,    82,    83,    84,    85,    86,
      90,    91,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   107,   108,   112,   113,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   154,   155,
     156,   157,   181,   185,   186,   187,   188
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ENTIER_VAL",
  "DECIMAL_VAL", "CHAINE", "STRING_VAL", "LOGIQUE_VAL", "IDENTIFIANT",
  "PLUS", "MINUS", "TIMES", "DIVIDE", "SI", "ALORS", "SINON", "SINONSI",
  "FINSI", "EQUALS", "LPAREN", "RPAREN", "VARIABLE_KWRD", "ECRIRE",
  "ALGORITHME", "DEBUT", "FIN", "COLON", "LIRE", "ENTIER_KWRD",
  "DECIMAL_KWRD", "LOGIQUE_KWRD", "CHAINE_KWRD", "COMMA", "COMMENT", "AND",
  "OR", "NOT", "XOR", "CONCAT", "LT", "GT", "LE", "GE", "EQ", "NE",
  "TANTQUE", "FAIRE", "FINTANTQUE", "POUR", "DE", "A", "FINPOUR", "POWER",
  "MODULO", "CONSTANT", "SELON", "FINSELON", "CAS", "SQUARE_ROOT", "SINE",
  "COSINE", "TANGENT", "LOG", "LOG10", "ROUND", "ABS", "INT", "RANDOM",
  "LENGTH", "COMPARE", "CONCATENATE", "COPY", "SEARCH", "$accept",
  "program", "Declarations", "Declaration", "statement_list", "statement",
  "expression_list", "case_list", "expression", "type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-66)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -14,    16,    28,   -66,   -66,   -20,    24,    76,    27,   -66,
       5,    18,   149,    19,    25,   149,    29,   149,    20,    76,
       0,   -16,   149,   -66,   -66,   -66,   -66,   -66,   149,   149,
      67,    68,    69,    71,    72,    73,    74,    75,    77,    80,
      81,    82,    83,    85,   213,   149,    38,   233,    46,   271,
     -66,   -66,    23,   102,   -66,   -66,   -66,   -66,   -66,  1127,
     309,    11,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   131,   149,   149,   149,   149,   149,   149,   149,   149,
      76,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,    86,   345,    87,    76,   149,    51,   -66,
     -66,   -66,   -66,   -66,   381,   417,   453,   489,   525,   561,
     597,   633,   669,   -66,   705,   741,   777,   813,   849,    -5,
      -5,   -30,   -30,     4,  1143,   250,   250,  1127,    30,    30,
      30,    30,  1163,  1163,    11,   -27,   -66,   149,   -66,    62,
     885,   149,   -13,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   149,   -66,   149,   149,   149,    76,   -66,   -66,
     -66,   149,   905,    76,   -66,   941,   977,  1013,  1049,    93,
    1069,    76,    55,   -66,   -66,   149,   -66,   -66,    76,    51,
     -66,  1107,    61,   -66,   -66,   -66
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     3,     1,     0,     0,     0,     0,     4,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
       0,     0,     0,    25,    26,    27,    28,    29,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,    11,     0,     0,    63,    64,    66,    65,     5,    12,
       0,    40,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,     0,     0,     0,     0,     7,
       8,     9,     6,    47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    57,     0,     0,     0,     0,     0,    30,
      31,    32,    33,     0,    34,    36,    37,    35,    41,    42,
      43,    44,    45,    46,    38,    39,    15,     0,    16,     0,
       0,     0,     0,    48,    49,    50,    51,    52,    53,    54,
      55,    56,     0,    59,     0,     0,     0,     0,    13,    22,
      17,     0,     0,     0,    19,     0,     0,     0,     0,     0,
       0,     0,     0,    58,    60,     0,    62,    14,     0,    23,
      20,     0,     0,    24,    61,    18
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -66,   -66,   -66,   -66,     1,   -66,   -24,   -65,   -12,   -66
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     5,     9,    18,    19,    93,   142,    94,    58
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      44,     6,   163,    47,     7,    49,    78,    79,    84,     1,
      59,    84,    54,    55,    56,    57,    60,    61,    52,   157,
      51,   158,    91,    92,     3,    91,    53,    99,     4,   100,
     101,    21,    10,    84,     8,    20,    22,    48,    45,    76,
      77,    78,    79,   164,    46,    50,    95,    91,    92,    84,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   114,
     115,   116,   117,   118,   119,   120,   121,   122,    84,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   123,    91,    92,    11,   140,    62,    63,    64,    12,
      65,    66,    67,    68,    69,    97,    70,   139,    13,    71,
      72,    73,    74,    14,    75,   102,   136,   138,   141,   160,
     177,   180,   185,   159,   183,     0,     0,     0,     0,     0,
       0,    15,     0,     0,    16,     0,     0,     0,     0,   162,
       0,    17,     0,     0,    23,    24,     0,    25,    26,    27,
     165,     0,   166,   167,   168,     0,     0,     0,     0,   170,
      28,   113,    23,    24,     0,    25,    26,    27,   169,     0,
       0,     0,     0,   181,   172,     0,     0,    29,    28,     0,
       0,     0,   179,     0,     0,     0,     0,     0,     0,   182,
       0,     0,     0,     0,     0,    29,     0,     0,     0,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,    42,    43,     0,     0,     0,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
      42,    43,    76,    77,    78,    79,     0,    80,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,    77,    78,    79,     0,    81,    82,     0,
      83,    84,    85,    86,    87,    88,    89,    90,     0,    76,
      77,    78,    79,     0,     0,    91,    92,    81,    82,     0,
      83,    84,    85,    86,    87,    88,    89,    90,     0,    96,
      76,    77,    78,    79,    81,    91,    92,     0,    84,    85,
      86,    87,    88,    89,    90,     0,     0,     0,     0,     0,
       0,     0,    91,    92,     0,    81,    82,     0,    83,    84,
      85,    86,    87,    88,    89,    90,     0,    98,    76,    77,
      78,    79,     0,    91,    92,     0,     0,     0,     0,   103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    81,    82,     0,    83,    84,    85,    86,
      87,    88,    89,    90,    76,    77,    78,    79,     0,     0,
       0,    91,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   137,     0,    81,
      82,     0,    83,    84,    85,    86,    87,    88,    89,    90,
      76,    77,    78,    79,     0,     0,     0,    91,    92,     0,
       0,   143,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    81,    82,     0,    83,    84,
      85,    86,    87,    88,    89,    90,    76,    77,    78,    79,
       0,     0,     0,    91,    92,     0,     0,   144,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    81,    82,     0,    83,    84,    85,    86,    87,    88,
      89,    90,    76,    77,    78,    79,     0,     0,     0,    91,
      92,     0,     0,   145,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    81,    82,     0,
      83,    84,    85,    86,    87,    88,    89,    90,    76,    77,
      78,    79,     0,     0,     0,    91,    92,     0,     0,   146,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    81,    82,     0,    83,    84,    85,    86,
      87,    88,    89,    90,    76,    77,    78,    79,     0,     0,
       0,    91,    92,     0,     0,   147,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    81,
      82,     0,    83,    84,    85,    86,    87,    88,    89,    90,
      76,    77,    78,    79,     0,     0,     0,    91,    92,     0,
       0,   148,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    81,    82,     0,    83,    84,
      85,    86,    87,    88,    89,    90,    76,    77,    78,    79,
       0,     0,     0,    91,    92,     0,     0,   149,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    81,    82,     0,    83,    84,    85,    86,    87,    88,
      89,    90,    76,    77,    78,    79,     0,     0,     0,    91,
      92,     0,     0,   150,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    81,    82,     0,
      83,    84,    85,    86,    87,    88,    89,    90,    76,    77,
      78,    79,     0,     0,     0,    91,    92,     0,     0,   151,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    81,    82,     0,    83,    84,    85,    86,
      87,    88,    89,    90,    76,    77,    78,    79,     0,     0,
       0,    91,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   152,     0,    81,
      82,     0,    83,    84,    85,    86,    87,    88,    89,    90,
      76,    77,    78,    79,     0,     0,     0,    91,    92,     0,
       0,   153,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    81,    82,     0,    83,    84,
      85,    86,    87,    88,    89,    90,    76,    77,    78,    79,
       0,     0,     0,    91,    92,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   154,
       0,    81,    82,     0,    83,    84,    85,    86,    87,    88,
      89,    90,    76,    77,    78,    79,     0,     0,     0,    91,
      92,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   155,     0,    81,    82,     0,
      83,    84,    85,    86,    87,    88,    89,    90,    76,    77,
      78,    79,     0,     0,     0,    91,    92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   156,     0,    81,    82,     0,    83,    84,    85,    86,
      87,    88,    89,    90,    76,    77,    78,    79,     0,     0,
       0,    91,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    76,    77,    78,    79,     0,    81,
      82,     0,    83,    84,    85,    86,    87,    88,    89,    90,
       0,   171,     0,     0,     0,   161,     0,    91,    92,    81,
      82,     0,    83,    84,    85,    86,    87,    88,    89,    90,
      76,    77,    78,    79,     0,     0,     0,    91,    92,     0,
       0,   173,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    81,    82,     0,    83,    84,
      85,    86,    87,    88,    89,    90,    76,    77,    78,    79,
       0,     0,     0,    91,    92,     0,     0,   174,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    81,    82,     0,    83,    84,    85,    86,    87,    88,
      89,    90,    76,    77,    78,    79,     0,     0,     0,    91,
      92,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   175,     0,    81,    82,     0,
      83,    84,    85,    86,    87,    88,    89,    90,    76,    77,
      78,    79,     0,     0,     0,    91,    92,     0,     0,   176,
       0,     0,     0,     0,     0,     0,     0,     0,    76,    77,
      78,    79,     0,    81,    82,     0,    83,    84,    85,    86,
      87,    88,    89,    90,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    81,    82,     0,    83,    84,    85,    86,
      87,    88,    89,    90,     0,   178,    76,    77,    78,    79,
       0,    91,    92,     0,     0,     0,     0,   184,     0,     0,
       0,     0,     0,     0,     0,     0,    76,    77,    78,    79,
       0,    81,    82,     0,    83,    84,    85,    86,    87,    88,
      89,    90,    76,    77,    78,    79,     0,     0,     0,    91,
      92,    81,    82,     0,    83,    84,    85,    86,    87,    88,
      89,    90,    76,    77,    78,    79,     0,     0,     0,    91,
      92,    84,    85,    86,    87,    88,    89,    90,     0,     0,
       0,     0,     0,     0,     0,    91,    92,     0,     0,     0,
       0,    84,    85,    86,    87,    88,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92
};

static const yytype_int16 yycheck[] =
{
      12,    21,    15,    15,    24,    17,    11,    12,    38,    23,
      22,    38,    28,    29,    30,    31,    28,    29,    18,    15,
      19,    17,    52,    53,     8,    52,    26,     4,     0,     6,
       7,    26,     8,    38,    54,     8,    18,     8,    19,     9,
      10,    11,    12,    56,    19,    25,     8,    52,    53,    38,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    38,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    80,    52,    53,     8,    97,    19,    19,    19,    13,
      19,    19,    19,    19,    19,    49,    19,    96,    22,    19,
      19,    19,    19,    27,    19,     3,    20,    20,    57,    47,
      17,    56,    51,   137,   179,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    -1,    48,    -1,    -1,    -1,    -1,   141,
      -1,    55,    -1,    -1,     3,     4,    -1,     6,     7,     8,
     152,    -1,   154,   155,   156,    -1,    -1,    -1,    -1,   161,
      19,    20,     3,     4,    -1,     6,     7,     8,   157,    -1,
      -1,    -1,    -1,   175,   163,    -1,    -1,    36,    19,    -1,
      -1,    -1,   171,    -1,    -1,    -1,    -1,    -1,    -1,   178,
      -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    72,    -1,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      71,    72,     9,    10,    11,    12,    -1,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    10,    11,    12,    -1,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    -1,     9,
      10,    11,    12,    -1,    -1,    52,    53,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    -1,    46,
       9,    10,    11,    12,    34,    52,    53,    -1,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    53,    -1,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    46,     9,    10,
      11,    12,    -1,    52,    53,    -1,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,     9,    10,    11,    12,    -1,    -1,
      -1,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
       9,    10,    11,    12,    -1,    -1,    -1,    52,    53,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,     9,    10,    11,    12,
      -1,    -1,    -1,    52,    53,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,     9,    10,    11,    12,    -1,    -1,    -1,    52,
      53,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,     9,    10,
      11,    12,    -1,    -1,    -1,    52,    53,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,     9,    10,    11,    12,    -1,    -1,
      -1,    52,    53,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
       9,    10,    11,    12,    -1,    -1,    -1,    52,    53,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,     9,    10,    11,    12,
      -1,    -1,    -1,    52,    53,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,     9,    10,    11,    12,    -1,    -1,    -1,    52,
      53,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,     9,    10,
      11,    12,    -1,    -1,    -1,    52,    53,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,     9,    10,    11,    12,    -1,    -1,
      -1,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
       9,    10,    11,    12,    -1,    -1,    -1,    52,    53,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,     9,    10,    11,    12,
      -1,    -1,    -1,    52,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      -1,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,     9,    10,    11,    12,    -1,    -1,    -1,    52,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,     9,    10,
      11,    12,    -1,    -1,    -1,    52,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    -1,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,     9,    10,    11,    12,    -1,    -1,
      -1,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     9,    10,    11,    12,    -1,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    26,    -1,    -1,    -1,    50,    -1,    52,    53,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
       9,    10,    11,    12,    -1,    -1,    -1,    52,    53,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,     9,    10,    11,    12,
      -1,    -1,    -1,    52,    53,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,     9,    10,    11,    12,    -1,    -1,    -1,    52,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,     9,    10,
      11,    12,    -1,    -1,    -1,    52,    53,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    10,
      11,    12,    -1,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    53,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    46,     9,    10,    11,    12,
      -1,    52,    53,    -1,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,    12,
      -1,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,     9,    10,    11,    12,    -1,    -1,    -1,    52,
      53,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,     9,    10,    11,    12,    -1,    -1,    -1,    52,
      53,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    53,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    53
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    23,    74,     8,     0,    75,    21,    24,    54,    76,
       8,     8,    13,    22,    27,    45,    48,    55,    77,    78,
       8,    26,    18,     3,     4,     6,     7,     8,    19,    36,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    71,    72,    81,    19,    19,    81,     8,    81,
      25,    77,    18,    26,    28,    29,    30,    31,    82,    81,
      81,    81,    19,    19,    19,    19,    19,    19,    19,    19,
      19,    19,    19,    19,    19,    19,     9,    10,    11,    12,
      14,    34,    35,    37,    38,    39,    40,    41,    42,    43,
      44,    52,    53,    79,    81,     8,    46,    49,    46,     4,
       6,     7,     3,    20,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    20,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    77,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    20,    32,    20,    77,
      81,    57,    80,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    32,    20,    32,    32,    32,    15,    17,    79,
      47,    50,    81,    15,    56,    81,    81,    81,    81,    77,
      81,    26,    77,    20,    20,    32,    20,    17,    46,    77,
      56,    81,    77,    80,    20,    51
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    73,    74,    75,    75,    76,    76,    76,    76,    76,
      77,    77,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    79,    79,    80,    80,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    82,    82,    82,    82
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     6,     0,     2,     4,     4,     4,     4,     4,
       1,     2,     3,     5,     7,     4,     4,     5,     9,     5,
       7,     1,     3,     4,     5,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     3,     6,     4,
       6,     8,     6,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
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
  case 2: /* program: ALGORITHME IDENTIFIANT Declarations DEBUT statement_list FIN  */
#line 74 "parser.y"
                                                                 { printf("*********************\nAlgorithme %s\n\n*********************\n\n", (yyvsp[-4].var_name)); parsed_program = (yyvsp[-1].statement_list); }
#line 1472 "parser.tab.c"
    break;

  case 5: /* Declaration: VARIABLE_KWRD IDENTIFIANT COLON type  */
#line 82 "parser.y"
                                         { add_symbol((yyvsp[-2].var_name), (yyvsp[0].type), false); }
#line 1478 "parser.tab.c"
    break;

  case 6: /* Declaration: CONSTANT IDENTIFIANT COLON ENTIER_VAL  */
#line 83 "parser.y"
                                            { add_symbol((yyvsp[-2].var_name), TYPE_ENTIER, true); set_symbol_value((yyvsp[-2].var_name), new_integer((yyvsp[0].int_value))); }
#line 1484 "parser.tab.c"
    break;

  case 7: /* Declaration: CONSTANT IDENTIFIANT EQUALS DECIMAL_VAL  */
#line 84 "parser.y"
                                              { add_symbol((yyvsp[-2].var_name), TYPE_DECIMAL, true); set_symbol_value((yyvsp[-2].var_name), new_decimal((yyvsp[0].double_value))); }
#line 1490 "parser.tab.c"
    break;

  case 8: /* Declaration: CONSTANT IDENTIFIANT EQUALS STRING_VAL  */
#line 85 "parser.y"
                                             { add_symbol((yyvsp[-2].var_name), TYPE_CHAINE, true); set_symbol_value((yyvsp[-2].var_name), new_string((yyvsp[0].string_value)));}
#line 1496 "parser.tab.c"
    break;

  case 9: /* Declaration: CONSTANT IDENTIFIANT EQUALS LOGIQUE_VAL  */
#line 86 "parser.y"
                                              { add_symbol((yyvsp[-2].var_name), TYPE_LOGIQUE, true); set_symbol_value((yyvsp[-2].var_name), new_boolean((yyvsp[0].bval))); }
#line 1502 "parser.tab.c"
    break;

  case 10: /* statement_list: statement  */
#line 90 "parser.y"
              { (yyval.statement_list) = new_statement_list((yyvsp[0].statement), NULL); }
#line 1508 "parser.tab.c"
    break;

  case 11: /* statement_list: statement statement_list  */
#line 91 "parser.y"
                               { (yyval.statement_list) = new_statement_list((yyvsp[-1].statement), (yyvsp[0].statement_list)); }
#line 1514 "parser.tab.c"
    break;

  case 12: /* statement: IDENTIFIANT EQUALS expression  */
#line 95 "parser.y"
                                  { (yyval.statement) = new_assign((yyvsp[-2].var_name), (yyvsp[0].expression)); }
#line 1520 "parser.tab.c"
    break;

  case 13: /* statement: SI expression ALORS statement_list FINSI  */
#line 96 "parser.y"
                                               { (yyval.statement) = new_if((yyvsp[-3].expression), (yyvsp[-1].statement_list), NULL); }
#line 1526 "parser.tab.c"
    break;

  case 14: /* statement: SI expression ALORS statement_list SINON statement_list FINSI  */
#line 97 "parser.y"
                                                                    { (yyval.statement) = new_if((yyvsp[-5].expression), (yyvsp[-3].statement_list), (yyvsp[-1].statement_list)); }
#line 1532 "parser.tab.c"
    break;

  case 15: /* statement: ECRIRE LPAREN expression_list RPAREN  */
#line 98 "parser.y"
                                           { (yyval.statement) = new_print((yyvsp[-1].expression_list)); }
#line 1538 "parser.tab.c"
    break;

  case 16: /* statement: LIRE LPAREN IDENTIFIANT RPAREN  */
#line 99 "parser.y"
                                     { (yyval.statement) = new_read((yyvsp[-1].var_name)); }
#line 1544 "parser.tab.c"
    break;

  case 17: /* statement: TANTQUE expression FAIRE statement_list FINTANTQUE  */
#line 100 "parser.y"
                                                         { (yyval.statement) = new_while((yyvsp[-3].expression), (yyvsp[-1].statement_list)); }
#line 1550 "parser.tab.c"
    break;

  case 18: /* statement: POUR IDENTIFIANT DE expression A expression FAIRE statement_list FINPOUR  */
#line 101 "parser.y"
                                                                               { (yyval.statement) = new_for((yyvsp[-7].var_name), (yyvsp[-5].expression), (yyvsp[-3].expression), (yyvsp[-1].statement_list)); }
#line 1556 "parser.tab.c"
    break;

  case 19: /* statement: SELON expression FAIRE case_list FINSELON  */
#line 102 "parser.y"
                                                { (yyval.statement) = new_switch((yyvsp[-3].expression), (yyvsp[-1].case_list), NULL); }
#line 1562 "parser.tab.c"
    break;

  case 20: /* statement: SELON expression FAIRE case_list SINON statement_list FINSELON  */
#line 103 "parser.y"
                                                                     { (yyval.statement) = new_switch((yyvsp[-5].expression), (yyvsp[-3].case_list), (yyvsp[-1].statement_list)); }
#line 1568 "parser.tab.c"
    break;

  case 21: /* expression_list: expression  */
#line 107 "parser.y"
               { (yyval.expression_list) = new_expression_list((yyvsp[0].expression), NULL); }
#line 1574 "parser.tab.c"
    break;

  case 22: /* expression_list: expression COMMA expression_list  */
#line 108 "parser.y"
                                       { (yyval.expression_list) = new_expression_list((yyvsp[-2].expression), (yyvsp[0].expression_list)); }
#line 1580 "parser.tab.c"
    break;

  case 23: /* case_list: CAS expression COLON statement_list  */
#line 112 "parser.y"
                                        { (yyval.case_list) = new_case_list((yyvsp[-2].expression), (yyvsp[0].statement_list), NULL); }
#line 1586 "parser.tab.c"
    break;

  case 24: /* case_list: CAS expression COLON statement_list case_list  */
#line 113 "parser.y"
                                                    { (yyval.case_list) = new_case_list((yyvsp[-3].expression), (yyvsp[-1].statement_list), (yyvsp[0].case_list)); }
#line 1592 "parser.tab.c"
    break;

  case 25: /* expression: ENTIER_VAL  */
#line 117 "parser.y"
               { (yyval.expression) = new_integer((yyvsp[0].int_value)); }
#line 1598 "parser.tab.c"
    break;

  case 26: /* expression: DECIMAL_VAL  */
#line 118 "parser.y"
                  { (yyval.expression) = new_decimal((yyvsp[0].double_value)); }
#line 1604 "parser.tab.c"
    break;

  case 27: /* expression: STRING_VAL  */
#line 119 "parser.y"
                 { (yyval.expression) = new_string((yyvsp[0].string_value)); }
#line 1610 "parser.tab.c"
    break;

  case 28: /* expression: LOGIQUE_VAL  */
#line 120 "parser.y"
                  { (yyval.expression) = new_boolean((yyvsp[0].bval)); }
#line 1616 "parser.tab.c"
    break;

  case 29: /* expression: IDENTIFIANT  */
#line 121 "parser.y"
                  { (yyval.expression) = new_variable((yyvsp[0].var_name)); }
#line 1622 "parser.tab.c"
    break;

  case 30: /* expression: expression PLUS expression  */
#line 122 "parser.y"
                                 { (yyval.expression) = new_binary_op('+', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1628 "parser.tab.c"
    break;

  case 31: /* expression: expression MINUS expression  */
#line 123 "parser.y"
                                  { (yyval.expression) = new_binary_op('-', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1634 "parser.tab.c"
    break;

  case 32: /* expression: expression TIMES expression  */
#line 124 "parser.y"
                                  { (yyval.expression) = new_binary_op('*', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1640 "parser.tab.c"
    break;

  case 33: /* expression: expression DIVIDE expression  */
#line 125 "parser.y"
                                   { (yyval.expression) = new_binary_op('/', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1646 "parser.tab.c"
    break;

  case 34: /* expression: expression AND expression  */
#line 126 "parser.y"
                                { (yyval.expression) = new_binary_op('&', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1652 "parser.tab.c"
    break;

  case 35: /* expression: expression CONCAT expression  */
#line 127 "parser.y"
                                   { (yyval.expression) = new_binary_op('C', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1658 "parser.tab.c"
    break;

  case 36: /* expression: expression OR expression  */
#line 128 "parser.y"
                               { (yyval.expression) = new_binary_op('|', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1664 "parser.tab.c"
    break;

  case 37: /* expression: expression XOR expression  */
#line 129 "parser.y"
                                { (yyval.expression) = new_binary_op('^', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1670 "parser.tab.c"
    break;

  case 38: /* expression: expression POWER expression  */
#line 130 "parser.y"
                                  { (yyval.expression) = new_binary_op('P', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1676 "parser.tab.c"
    break;

  case 39: /* expression: expression MODULO expression  */
#line 131 "parser.y"
                                   { (yyval.expression) = new_binary_op('M', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1682 "parser.tab.c"
    break;

  case 40: /* expression: NOT expression  */
#line 132 "parser.y"
                     { (yyval.expression) = new_unary_op('!', (yyvsp[0].expression)); }
#line 1688 "parser.tab.c"
    break;

  case 41: /* expression: expression LT expression  */
#line 133 "parser.y"
                               { (yyval.expression) = new_binary_op('<', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1694 "parser.tab.c"
    break;

  case 42: /* expression: expression GT expression  */
#line 134 "parser.y"
                               { (yyval.expression) = new_binary_op('>', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1700 "parser.tab.c"
    break;

  case 43: /* expression: expression LE expression  */
#line 135 "parser.y"
                               { (yyval.expression) = new_binary_op('L', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1706 "parser.tab.c"
    break;

  case 44: /* expression: expression GE expression  */
#line 136 "parser.y"
                               { (yyval.expression) = new_binary_op('G', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1712 "parser.tab.c"
    break;

  case 45: /* expression: expression EQ expression  */
#line 137 "parser.y"
                               { (yyval.expression) = new_binary_op('=', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1718 "parser.tab.c"
    break;

  case 46: /* expression: expression NE expression  */
#line 138 "parser.y"
                               { (yyval.expression) = new_binary_op('!', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1724 "parser.tab.c"
    break;

  case 47: /* expression: LPAREN expression RPAREN  */
#line 139 "parser.y"
                               { (yyval.expression) = (yyvsp[-1].expression); }
#line 1730 "parser.tab.c"
    break;

  case 48: /* expression: SQUARE_ROOT LPAREN expression RPAREN  */
#line 140 "parser.y"
                                           { (yyval.expression) = new_unary_op('R', (yyvsp[-1].expression)); }
#line 1736 "parser.tab.c"
    break;

  case 49: /* expression: SINE LPAREN expression RPAREN  */
#line 141 "parser.y"
                                    { (yyval.expression) = new_unary_op('S', (yyvsp[-1].expression)); }
#line 1742 "parser.tab.c"
    break;

  case 50: /* expression: COSINE LPAREN expression RPAREN  */
#line 142 "parser.y"
                                      { (yyval.expression) = new_unary_op('C', (yyvsp[-1].expression)); }
#line 1748 "parser.tab.c"
    break;

  case 51: /* expression: TANGENT LPAREN expression RPAREN  */
#line 143 "parser.y"
                                       { (yyval.expression) = new_unary_op('T', (yyvsp[-1].expression)); }
#line 1754 "parser.tab.c"
    break;

  case 52: /* expression: LOG LPAREN expression RPAREN  */
#line 144 "parser.y"
                                   {(yyval.expression) = new_unary_op('L', (yyvsp[-1].expression)); }
#line 1760 "parser.tab.c"
    break;

  case 53: /* expression: LOG10 LPAREN expression RPAREN  */
#line 145 "parser.y"
                                     { (yyval.expression) = new_unary_op('l', (yyvsp[-1].expression));}
#line 1766 "parser.tab.c"
    break;

  case 54: /* expression: ROUND LPAREN expression RPAREN  */
#line 146 "parser.y"
                                     { (yyval.expression) = new_unary_op('D', (yyvsp[-1].expression));}
#line 1772 "parser.tab.c"
    break;

  case 55: /* expression: ABS LPAREN expression RPAREN  */
#line 147 "parser.y"
                                   { (yyval.expression) = new_unary_op('A', (yyvsp[-1].expression));}
#line 1778 "parser.tab.c"
    break;

  case 56: /* expression: INT LPAREN expression RPAREN  */
#line 148 "parser.y"
                                   { (yyval.expression) = new_unary_op('E', (yyvsp[-1].expression));}
#line 1784 "parser.tab.c"
    break;

  case 57: /* expression: RANDOM LPAREN RPAREN  */
#line 149 "parser.y"
                           {
        srand(time(0));
        double random_number = (double)rand() / (RAND_MAX + 1.0);
        (yyval.expression) = new_decimal(random_number);
    }
#line 1794 "parser.tab.c"
    break;

  case 58: /* expression: RANDOM LPAREN expression COMMA expression RPAREN  */
#line 154 "parser.y"
                                                       { (yyval.expression) = new_binary_op('A', (yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 1800 "parser.tab.c"
    break;

  case 59: /* expression: LENGTH LPAREN expression RPAREN  */
#line 155 "parser.y"
                                      { (yyval.expression) = new_unary_op('H', (yyvsp[-1].expression)); }
#line 1806 "parser.tab.c"
    break;

  case 60: /* expression: COMPARE LPAREN expression COMMA expression RPAREN  */
#line 156 "parser.y"
                                                        { (yyval.expression) = new_binary_op('p', (yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 1812 "parser.tab.c"
    break;

  case 61: /* expression: COPY LPAREN expression COMMA expression COMMA expression RPAREN  */
#line 157 "parser.y"
                                                                       {
        Expression *str_exp = evaluate_expression((yyvsp[-5].expression));
        Expression *pos_exp = evaluate_expression((yyvsp[-3].expression));
        Expression *n_exp = evaluate_expression((yyvsp[-1].expression));

        if (str_exp->type != STRING || pos_exp->type != INTEGER || n_exp->type != INTEGER)
        {
            printf("Erreur ligne %d: Invalid argument type for 'Copie'\n", yylineno);
            exit(1);
        }

        char *new_str = malloc(sizeof(char*) * strlen(str_exp->data.string_value) + 1);

        strncpy(new_str, str_exp->data.string_value + pos_exp->data.int_value, n_exp->data.int_value);
        new_str[n_exp->data.int_value] = '\0';

        printf("\nNew String: %s\n", new_str);

        (yyval.expression) = new_string(new_str);
        free(str_exp);
        free(pos_exp);
        free(n_exp);
        //free(new_str);
    }
#line 1841 "parser.tab.c"
    break;

  case 62: /* expression: SEARCH LPAREN expression COMMA expression RPAREN  */
#line 181 "parser.y"
                                                       { (yyval.expression) = new_binary_op('r', (yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 1847 "parser.tab.c"
    break;

  case 63: /* type: ENTIER_KWRD  */
#line 185 "parser.y"
                { (yyval.type) = TYPE_ENTIER; }
#line 1853 "parser.tab.c"
    break;

  case 64: /* type: DECIMAL_KWRD  */
#line 186 "parser.y"
                   { (yyval.type) = TYPE_DECIMAL; }
#line 1859 "parser.tab.c"
    break;

  case 65: /* type: CHAINE_KWRD  */
#line 187 "parser.y"
                  { (yyval.type) = TYPE_CHAINE; }
#line 1865 "parser.tab.c"
    break;

  case 66: /* type: LOGIQUE_KWRD  */
#line 188 "parser.y"
                   { (yyval.type) = TYPE_LOGIQUE; }
#line 1871 "parser.tab.c"
    break;


#line 1875 "parser.tab.c"

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
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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

  return yyresult;
}

#line 191 "parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "Erreur ligne %d: %s\n", yylineno, s);
}
