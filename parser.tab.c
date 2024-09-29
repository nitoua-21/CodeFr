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
#include "ast.h"

void yyerror(const char *s);
int yylex(void);

StatementList *parsed_program = NULL;

#line 84 "parser.tab.c"

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
  YYSYMBOL_YYACCEPT = 65,                  /* $accept  */
  YYSYMBOL_program = 66,                   /* program  */
  YYSYMBOL_Declarations = 67,              /* Declarations  */
  YYSYMBOL_Declaration = 68,               /* Declaration  */
  YYSYMBOL_statement_list = 69,            /* statement_list  */
  YYSYMBOL_statement = 70,                 /* statement  */
  YYSYMBOL_case_list = 71,                 /* case_list  */
  YYSYMBOL_expression = 72,                /* expression  */
  YYSYMBOL_type = 73                       /* type  */
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
#define YYLAST   679

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  9
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  144

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   319


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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    69,    69,    72,    74,    77,    78,    79,    80,    81,
      85,    86,    90,    91,    92,    93,    94,    95,    96,    97,
      98,   102,   103,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   135,   140,   145,
     150,   155,   160,   168,   169,   170,   171
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
  "COSINE", "TANGENT", "LOG", "LOG10", "ROUND", "$accept", "program",
  "Declarations", "Declaration", "statement_list", "statement",
  "case_list", "expression", "type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-36)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -2,     1,    12,   -36,   -36,   -14,    28,    -7,    29,   -36,
      13,    24,    73,    27,    30,    73,    42,    73,    50,    -7,
       9,     2,    73,   -36,   -36,   -36,   -36,   -36,    73,    73,
      63,    64,    65,    70,    71,    72,    74,   112,    73,    86,
     132,    46,   170,   -36,   -36,    10,    93,   -36,   -36,   -36,
     -36,   -36,   610,   208,    59,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    -7,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,   244,
      78,    -7,    73,    43,   -36,   -36,   -36,   -36,   -36,   280,
     316,   352,   388,   424,   460,   496,    -9,    -9,   -30,   -30,
      11,   588,   149,   149,   610,    76,    76,    76,    76,   626,
     626,    59,   -33,   -36,   -36,    52,   516,    73,   -11,   -36,
     -36,   -36,   -36,   -36,   -36,   -36,    -7,   -36,   -36,    73,
     552,    -7,   -36,    84,   572,    -7,    47,   -36,    -7,    43,
     -36,    51,   -36,   -36
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     3,     1,     0,     0,     0,     0,     4,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
       0,     0,     0,    23,    24,    25,    26,    27,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,    11,     0,     0,    53,    54,    56,
      55,     5,    12,     0,    38,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     8,     9,     6,    45,     0,
       0,     0,     0,     0,     0,     0,    28,    29,    30,    31,
       0,    32,    34,    35,    33,    39,    40,    41,    42,    43,
      44,    36,    37,    15,    16,     0,     0,     0,     0,    46,
      47,    48,    49,    50,    51,    52,     0,    13,    17,     0,
       0,     0,    19,     0,     0,     0,     0,    14,     0,    21,
      20,     0,    22,    18
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -36,   -36,   -36,   -36,   -19,   -36,   -35,    -4,   -36
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     5,     9,    18,    19,   118,    37,    51
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      44,    11,    64,    65,   131,    70,    12,     6,    70,     3,
       7,    40,     4,    42,    84,    13,    85,    86,    52,    77,
      14,     1,    77,    78,    53,    54,   126,    45,   127,    70,
      47,    48,    49,    50,    79,    46,    10,    20,    15,    21,
       8,    16,    22,    77,    78,   132,    38,   100,    17,    39,
      41,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   115,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    43,    23,    24,   116,    25,
      26,    27,    55,    56,    57,    62,    63,    64,    65,    58,
      59,    60,    28,    61,    80,    82,    87,    70,   114,   128,
     117,   137,   143,   140,   142,     0,     0,   133,     0,    29,
       0,     0,   136,   130,    70,     0,   139,     0,     0,   141,
       0,    62,    63,    64,    65,   134,    66,     0,    77,    78,
       0,    30,    31,    32,    33,    34,    35,    36,     0,     0,
       0,    62,    63,    64,    65,     0,    67,    68,     0,    69,
      70,    71,    72,    73,    74,    75,    76,     0,    62,    63,
      64,    65,     0,     0,    77,    78,    67,    68,     0,    69,
      70,    71,    72,    73,    74,    75,    76,     0,    81,    62,
      63,    64,    65,    67,    77,    78,     0,    70,    71,    72,
      73,    74,    75,    76,     0,     0,     0,     0,     0,     0,
       0,    77,    78,     0,    67,    68,     0,    69,    70,    71,
      72,    73,    74,    75,    76,     0,    83,    62,    63,    64,
      65,     0,    77,    78,     0,     0,     0,     0,    88,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    67,    68,     0,    69,    70,    71,    72,    73,
      74,    75,    76,    62,    63,    64,    65,     0,     0,     0,
      77,    78,     0,     0,   113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    67,    68,
       0,    69,    70,    71,    72,    73,    74,    75,    76,    62,
      63,    64,    65,     0,     0,     0,    77,    78,     0,     0,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    67,    68,     0,    69,    70,    71,
      72,    73,    74,    75,    76,    62,    63,    64,    65,     0,
       0,     0,    77,    78,     0,     0,   120,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      67,    68,     0,    69,    70,    71,    72,    73,    74,    75,
      76,    62,    63,    64,    65,     0,     0,     0,    77,    78,
       0,     0,   121,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    67,    68,     0,    69,
      70,    71,    72,    73,    74,    75,    76,    62,    63,    64,
      65,     0,     0,     0,    77,    78,     0,     0,   122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    67,    68,     0,    69,    70,    71,    72,    73,
      74,    75,    76,    62,    63,    64,    65,     0,     0,     0,
      77,    78,     0,     0,   123,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    67,    68,
       0,    69,    70,    71,    72,    73,    74,    75,    76,    62,
      63,    64,    65,     0,     0,     0,    77,    78,     0,     0,
     124,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    67,    68,     0,    69,    70,    71,
      72,    73,    74,    75,    76,    62,    63,    64,    65,     0,
       0,     0,    77,    78,     0,     0,   125,     0,     0,     0,
       0,     0,     0,     0,     0,    62,    63,    64,    65,     0,
      67,    68,     0,    69,    70,    71,    72,    73,    74,    75,
      76,     0,     0,     0,     0,     0,     0,     0,    77,    78,
      67,    68,     0,    69,    70,    71,    72,    73,    74,    75,
      76,    62,    63,    64,    65,     0,   129,     0,    77,    78,
       0,     0,     0,     0,     0,     0,     0,     0,   135,     0,
       0,    62,    63,    64,    65,     0,    67,    68,     0,    69,
      70,    71,    72,    73,    74,    75,    76,    62,    63,    64,
      65,     0,     0,     0,    77,    78,    67,    68,     0,    69,
      70,    71,    72,    73,    74,    75,    76,     0,   138,    62,
      63,    64,    65,     0,    77,    78,    70,    71,    72,    73,
      74,    75,    76,     0,     0,    62,    63,    64,    65,     0,
      77,    78,     0,     0,    67,    68,     0,    69,    70,    71,
      72,    73,    74,    75,    76,     0,     0,     0,     0,     0,
       0,     0,    77,    78,    70,    71,    72,    73,    74,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,    78
};

static const yytype_int16 yycheck[] =
{
      19,     8,    11,    12,    15,    38,    13,    21,    38,     8,
      24,    15,     0,    17,     4,    22,     6,     7,    22,    52,
      27,    23,    52,    53,    28,    29,    15,    18,    17,    38,
      28,    29,    30,    31,    38,    26,     8,     8,    45,    26,
      54,    48,    18,    52,    53,    56,    19,    66,    55,    19,
       8,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    81,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    25,     3,     4,    82,     6,
       7,     8,    19,    19,    19,     9,    10,    11,    12,    19,
      19,    19,    19,    19,     8,    49,     3,    38,    20,    47,
      57,    17,    51,    56,   139,    -1,    -1,   126,    -1,    36,
      -1,    -1,   131,   117,    38,    -1,   135,    -1,    -1,   138,
      -1,     9,    10,    11,    12,   129,    14,    -1,    52,    53,
      -1,    58,    59,    60,    61,    62,    63,    64,    -1,    -1,
      -1,     9,    10,    11,    12,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,     9,    10,
      11,    12,    -1,    -1,    52,    53,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    46,     9,
      10,    11,    12,    34,    52,    53,    -1,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    53,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    46,     9,    10,    11,
      12,    -1,    52,    53,    -1,    -1,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,     9,    10,    11,    12,    -1,    -1,    -1,
      52,    53,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,     9,
      10,    11,    12,    -1,    -1,    -1,    52,    53,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,     9,    10,    11,    12,    -1,
      -1,    -1,    52,    53,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,     9,    10,    11,    12,    -1,    -1,    -1,    52,    53,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,     9,    10,    11,
      12,    -1,    -1,    -1,    52,    53,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,     9,    10,    11,    12,    -1,    -1,    -1,
      52,    53,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,     9,
      10,    11,    12,    -1,    -1,    -1,    52,    53,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,     9,    10,    11,    12,    -1,
      -1,    -1,    52,    53,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    10,    11,    12,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,     9,    10,    11,    12,    -1,    50,    -1,    52,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,
      -1,     9,    10,    11,    12,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,     9,    10,    11,
      12,    -1,    -1,    -1,    52,    53,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    46,     9,
      10,    11,    12,    -1,    52,    53,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,     9,    10,    11,    12,    -1,
      52,    53,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    53,    38,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    23,    66,     8,     0,    67,    21,    24,    54,    68,
       8,     8,    13,    22,    27,    45,    48,    55,    69,    70,
       8,    26,    18,     3,     4,     6,     7,     8,    19,    36,
      58,    59,    60,    61,    62,    63,    64,    72,    19,    19,
      72,     8,    72,    25,    69,    18,    26,    28,    29,    30,
      31,    73,    72,    72,    72,    19,    19,    19,    19,    19,
      19,    19,     9,    10,    11,    12,    14,    34,    35,    37,
      38,    39,    40,    41,    42,    43,    44,    52,    53,    72,
       8,    46,    49,    46,     4,     6,     7,     3,    20,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      69,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    20,    20,    69,    72,    57,    71,    20,
      20,    20,    20,    20,    20,    20,    15,    17,    47,    50,
      72,    15,    56,    69,    72,    26,    69,    17,    46,    69,
      56,    69,    71,    51
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    65,    66,    67,    67,    68,    68,    68,    68,    68,
      69,    69,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    71,    71,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    73,    73,    73,    73
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     6,     0,     2,     4,     4,     4,     4,     4,
       1,     2,     3,     5,     7,     4,     4,     5,     9,     5,
       7,     4,     5,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     4,     4,     4,     4,
       4,     4,     4,     1,     1,     1,     1
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
#line 69 "parser.y"
                                                                 { printf("*********************\nAlgorithme %s\n\n*********************\n\n", (yyvsp[-4].var_name)); parsed_program = (yyvsp[-1].statement_list); }
#line 1337 "parser.tab.c"
    break;

  case 5: /* Declaration: VARIABLE_KWRD IDENTIFIANT COLON type  */
#line 77 "parser.y"
                                         { add_symbol((yyvsp[-2].var_name), (yyvsp[0].type), false); }
#line 1343 "parser.tab.c"
    break;

  case 6: /* Declaration: CONSTANT IDENTIFIANT COLON ENTIER_VAL  */
#line 78 "parser.y"
                                            { add_symbol((yyvsp[-2].var_name), TYPE_ENTIER, true); set_symbol_value((yyvsp[-2].var_name), new_integer((yyvsp[0].int_value))); }
#line 1349 "parser.tab.c"
    break;

  case 7: /* Declaration: CONSTANT IDENTIFIANT EQUALS DECIMAL_VAL  */
#line 79 "parser.y"
                                              { add_symbol((yyvsp[-2].var_name), TYPE_DECIMAL, true); set_symbol_value((yyvsp[-2].var_name), new_decimal((yyvsp[0].double_value))); }
#line 1355 "parser.tab.c"
    break;

  case 8: /* Declaration: CONSTANT IDENTIFIANT EQUALS STRING_VAL  */
#line 80 "parser.y"
                                             { add_symbol((yyvsp[-2].var_name), TYPE_CHAINE, true); set_symbol_value((yyvsp[-2].var_name), new_string((yyvsp[0].string_value)));}
#line 1361 "parser.tab.c"
    break;

  case 9: /* Declaration: CONSTANT IDENTIFIANT EQUALS LOGIQUE_VAL  */
#line 81 "parser.y"
                                              { add_symbol((yyvsp[-2].var_name), TYPE_LOGIQUE, true); set_symbol_value((yyvsp[-2].var_name), new_boolean((yyvsp[0].bval))); }
#line 1367 "parser.tab.c"
    break;

  case 10: /* statement_list: statement  */
#line 85 "parser.y"
              { (yyval.statement_list) = new_statement_list((yyvsp[0].statement), NULL); }
#line 1373 "parser.tab.c"
    break;

  case 11: /* statement_list: statement statement_list  */
#line 86 "parser.y"
                               { (yyval.statement_list) = new_statement_list((yyvsp[-1].statement), (yyvsp[0].statement_list)); }
#line 1379 "parser.tab.c"
    break;

  case 12: /* statement: IDENTIFIANT EQUALS expression  */
#line 90 "parser.y"
                                  { (yyval.statement) = new_assign((yyvsp[-2].var_name), (yyvsp[0].expression)); }
#line 1385 "parser.tab.c"
    break;

  case 13: /* statement: SI expression ALORS statement_list FINSI  */
#line 91 "parser.y"
                                               { (yyval.statement) = new_if((yyvsp[-3].expression), (yyvsp[-1].statement_list), NULL); }
#line 1391 "parser.tab.c"
    break;

  case 14: /* statement: SI expression ALORS statement_list SINON statement_list FINSI  */
#line 92 "parser.y"
                                                                    { (yyval.statement) = new_if((yyvsp[-5].expression), (yyvsp[-3].statement_list), (yyvsp[-1].statement_list)); }
#line 1397 "parser.tab.c"
    break;

  case 15: /* statement: ECRIRE LPAREN expression RPAREN  */
#line 93 "parser.y"
                                      { (yyval.statement) = new_print((yyvsp[-1].expression)); }
#line 1403 "parser.tab.c"
    break;

  case 16: /* statement: LIRE LPAREN IDENTIFIANT RPAREN  */
#line 94 "parser.y"
                                     { (yyval.statement) = new_read((yyvsp[-1].var_name)); }
#line 1409 "parser.tab.c"
    break;

  case 17: /* statement: TANTQUE expression FAIRE statement_list FINTANTQUE  */
#line 95 "parser.y"
                                                         { (yyval.statement) = new_while((yyvsp[-3].expression), (yyvsp[-1].statement_list)); }
#line 1415 "parser.tab.c"
    break;

  case 18: /* statement: POUR IDENTIFIANT DE expression A expression FAIRE statement_list FINPOUR  */
#line 96 "parser.y"
                                                                               { (yyval.statement) = new_for((yyvsp[-7].var_name), (yyvsp[-5].expression), (yyvsp[-3].expression), (yyvsp[-1].statement_list)); }
#line 1421 "parser.tab.c"
    break;

  case 19: /* statement: SELON expression FAIRE case_list FINSELON  */
#line 97 "parser.y"
                                                { (yyval.statement) = new_switch((yyvsp[-3].expression), (yyvsp[-1].case_list), NULL); }
#line 1427 "parser.tab.c"
    break;

  case 20: /* statement: SELON expression FAIRE case_list SINON statement_list FINSELON  */
#line 98 "parser.y"
                                                                     { (yyval.statement) = new_switch((yyvsp[-5].expression), (yyvsp[-3].case_list), (yyvsp[-1].statement_list)); }
#line 1433 "parser.tab.c"
    break;

  case 21: /* case_list: CAS expression COLON statement_list  */
#line 102 "parser.y"
                                        { (yyval.case_list) = new_case_list((yyvsp[-2].expression), (yyvsp[0].statement_list), NULL); }
#line 1439 "parser.tab.c"
    break;

  case 22: /* case_list: CAS expression COLON statement_list case_list  */
#line 103 "parser.y"
                                                    { (yyval.case_list) = new_case_list((yyvsp[-3].expression), (yyvsp[-1].statement_list), (yyvsp[0].case_list)); }
#line 1445 "parser.tab.c"
    break;

  case 23: /* expression: ENTIER_VAL  */
#line 107 "parser.y"
               { (yyval.expression) = new_integer((yyvsp[0].int_value)); }
#line 1451 "parser.tab.c"
    break;

  case 24: /* expression: DECIMAL_VAL  */
#line 108 "parser.y"
                  { (yyval.expression) = new_decimal((yyvsp[0].double_value)); }
#line 1457 "parser.tab.c"
    break;

  case 25: /* expression: STRING_VAL  */
#line 109 "parser.y"
                 { (yyval.expression) = new_string((yyvsp[0].string_value)); }
#line 1463 "parser.tab.c"
    break;

  case 26: /* expression: LOGIQUE_VAL  */
#line 110 "parser.y"
                  { (yyval.expression) = new_boolean((yyvsp[0].bval)); }
#line 1469 "parser.tab.c"
    break;

  case 27: /* expression: IDENTIFIANT  */
#line 111 "parser.y"
                  { (yyval.expression) = new_variable((yyvsp[0].var_name)); }
#line 1475 "parser.tab.c"
    break;

  case 28: /* expression: expression PLUS expression  */
#line 112 "parser.y"
                                 { (yyval.expression) = new_binary_op('+', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1481 "parser.tab.c"
    break;

  case 29: /* expression: expression MINUS expression  */
#line 113 "parser.y"
                                  { (yyval.expression) = new_binary_op('-', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1487 "parser.tab.c"
    break;

  case 30: /* expression: expression TIMES expression  */
#line 114 "parser.y"
                                  { (yyval.expression) = new_binary_op('*', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1493 "parser.tab.c"
    break;

  case 31: /* expression: expression DIVIDE expression  */
#line 115 "parser.y"
                                   { (yyval.expression) = new_binary_op('/', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1499 "parser.tab.c"
    break;

  case 32: /* expression: expression AND expression  */
#line 116 "parser.y"
                                { (yyval.expression) = new_binary_op('&', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1505 "parser.tab.c"
    break;

  case 33: /* expression: expression CONCAT expression  */
#line 117 "parser.y"
                                   { (yyval.expression) = new_binary_op('C', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1511 "parser.tab.c"
    break;

  case 34: /* expression: expression OR expression  */
#line 118 "parser.y"
                               { (yyval.expression) = new_binary_op('|', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1517 "parser.tab.c"
    break;

  case 35: /* expression: expression XOR expression  */
#line 119 "parser.y"
                                { (yyval.expression) = new_binary_op('^', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1523 "parser.tab.c"
    break;

  case 36: /* expression: expression POWER expression  */
#line 120 "parser.y"
                                  { (yyval.expression) = new_binary_op('P', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1529 "parser.tab.c"
    break;

  case 37: /* expression: expression MODULO expression  */
#line 121 "parser.y"
                                   { (yyval.expression) = new_binary_op('M', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1535 "parser.tab.c"
    break;

  case 38: /* expression: NOT expression  */
#line 122 "parser.y"
                     { (yyval.expression) = new_unary_op('!', (yyvsp[0].expression)); }
#line 1541 "parser.tab.c"
    break;

  case 39: /* expression: expression LT expression  */
#line 123 "parser.y"
                               { (yyval.expression) = new_binary_op('<', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1547 "parser.tab.c"
    break;

  case 40: /* expression: expression GT expression  */
#line 124 "parser.y"
                               { (yyval.expression) = new_binary_op('>', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1553 "parser.tab.c"
    break;

  case 41: /* expression: expression LE expression  */
#line 125 "parser.y"
                               { (yyval.expression) = new_binary_op('L', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1559 "parser.tab.c"
    break;

  case 42: /* expression: expression GE expression  */
#line 126 "parser.y"
                               { (yyval.expression) = new_binary_op('G', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1565 "parser.tab.c"
    break;

  case 43: /* expression: expression EQ expression  */
#line 127 "parser.y"
                               { (yyval.expression) = new_binary_op('=', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1571 "parser.tab.c"
    break;

  case 44: /* expression: expression NE expression  */
#line 128 "parser.y"
                               { (yyval.expression) = new_binary_op('!', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1577 "parser.tab.c"
    break;

  case 45: /* expression: LPAREN expression RPAREN  */
#line 129 "parser.y"
                               { (yyval.expression) = (yyvsp[-1].expression); }
#line 1583 "parser.tab.c"
    break;

  case 46: /* expression: SQUARE_ROOT LPAREN expression RPAREN  */
#line 130 "parser.y"
                                           {
        Expression *exp = evaluate_expression((yyvsp[-1].expression));
        (yyval.expression) = new_decimal(exp->type == INTEGER ? sqrt(exp->data.int_value) : sqrt(exp->data.double_value));
        free(exp);
    }
#line 1593 "parser.tab.c"
    break;

  case 47: /* expression: SINE LPAREN expression RPAREN  */
#line 135 "parser.y"
                                    {
        Expression *exp = evaluate_expression((yyvsp[-1].expression));
        (yyval.expression) = new_decimal(exp->type == INTEGER ? sin(exp->data.int_value) : sin(exp->data.double_value));
        free(exp);
    }
#line 1603 "parser.tab.c"
    break;

  case 48: /* expression: COSINE LPAREN expression RPAREN  */
#line 140 "parser.y"
                                      {
        Expression *exp = evaluate_expression((yyvsp[-1].expression));
        (yyval.expression) = new_decimal(exp->type == INTEGER ? cos(exp->data.int_value) : cos(exp->data.double_value));
        free(exp);
    }
#line 1613 "parser.tab.c"
    break;

  case 49: /* expression: TANGENT LPAREN expression RPAREN  */
#line 145 "parser.y"
                                       {
        Expression *exp = evaluate_expression((yyvsp[-1].expression));
        (yyval.expression) = new_decimal(exp->type == INTEGER ? tan(exp->data.int_value) : tan(exp->data.double_value));
        free(exp);
    }
#line 1623 "parser.tab.c"
    break;

  case 50: /* expression: LOG LPAREN expression RPAREN  */
#line 150 "parser.y"
                                   {
        Expression *exp = evaluate_expression((yyvsp[-1].expression));
        (yyval.expression) = new_decimal(exp->type == INTEGER ? log(exp->data.int_value) : log(exp->data.double_value));
        free(exp);
    }
#line 1633 "parser.tab.c"
    break;

  case 51: /* expression: LOG10 LPAREN expression RPAREN  */
#line 155 "parser.y"
                                     {
        Expression *exp = evaluate_expression((yyvsp[-1].expression));
        (yyval.expression) = new_decimal(exp->type == INTEGER ? log10(exp->data.int_value) : log10(exp->data.double_value));
        free(exp);
    }
#line 1643 "parser.tab.c"
    break;

  case 52: /* expression: ROUND LPAREN expression RPAREN  */
#line 160 "parser.y"
                                     {
        Expression *exp = evaluate_expression((yyvsp[-1].expression));
        (yyval.expression) = new_decimal(exp->type == INTEGER ? round(exp->data.int_value) : round(exp->data.double_value));
        free(exp);
    }
#line 1653 "parser.tab.c"
    break;

  case 53: /* type: ENTIER_KWRD  */
#line 168 "parser.y"
                { (yyval.type) = TYPE_ENTIER; }
#line 1659 "parser.tab.c"
    break;

  case 54: /* type: DECIMAL_KWRD  */
#line 169 "parser.y"
                   { (yyval.type) = TYPE_DECIMAL; }
#line 1665 "parser.tab.c"
    break;

  case 55: /* type: CHAINE_KWRD  */
#line 170 "parser.y"
                  { (yyval.type) = TYPE_CHAINE; }
#line 1671 "parser.tab.c"
    break;

  case 56: /* type: LOGIQUE_KWRD  */
#line 171 "parser.y"
                   { (yyval.type) = TYPE_LOGIQUE; }
#line 1677 "parser.tab.c"
    break;


#line 1681 "parser.tab.c"

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

#line 174 "parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "Erreur ligne %d: %s\n", yylineno, s);
}
