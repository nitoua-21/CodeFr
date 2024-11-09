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
  YYSYMBOL_TABLEAU = 73,                   /* TABLEAU  */
  YYSYMBOL_LBRACKET = 74,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 75,                  /* RBRACKET  */
  YYSYMBOL_YYACCEPT = 76,                  /* $accept  */
  YYSYMBOL_program = 77,                   /* program  */
  YYSYMBOL_Declarations = 78,              /* Declarations  */
  YYSYMBOL_Declaration = 79,               /* Declaration  */
  YYSYMBOL_array_dimensions = 80,          /* array_dimensions  */
  YYSYMBOL_statement_list = 81,            /* statement_list  */
  YYSYMBOL_statement = 82,                 /* statement  */
  YYSYMBOL_elif_list = 83,                 /* elif_list  */
  YYSYMBOL_array_ref = 84,                 /* array_ref  */
  YYSYMBOL_expression_list = 85,           /* expression_list  */
  YYSYMBOL_case_list = 86,                 /* case_list  */
  YYSYMBOL_expression = 87,                /* expression  */
  YYSYMBOL_type = 88                       /* type  */
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
#define YYLAST   1427

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  222

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   330


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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    80,    80,    83,    85,    88,    89,    90,    91,    92,
      93,    99,   107,   121,   122,   126,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   144,   146,   151,
     157,   167,   168,   172,   173,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   214,   215,
     216,   217,   241,   242,   245,   251,   252,   253,   254
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
  "LENGTH", "COMPARE", "CONCATENATE", "COPY", "SEARCH", "TABLEAU",
  "LBRACKET", "RBRACKET", "$accept", "program", "Declarations",
  "Declaration", "array_dimensions", "statement_list", "statement",
  "elif_list", "array_ref", "expression_list", "case_list", "expression",
  "type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-67)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -12,     6,    15,   -67,   -67,    79,    30,    -4,    32,    34,
     -67,    24,   -17,   182,    26,    33,   182,    45,   182,    29,
      -4,    38,     4,     2,    -3,   182,   182,   -67,   -67,   -67,
     -67,    17,   182,   182,    70,    73,    75,    76,    82,    83,
      85,    86,    92,    93,    94,    95,    96,    97,   390,   182,
     109,   426,    69,   446,   -67,   -67,   182,    25,   116,   182,
     106,   -67,   -67,   -67,   -67,   -67,  1338,    87,   182,   484,
      99,   182,   182,   182,   182,   182,   182,   182,   182,   182,
     163,   182,   182,   182,   182,   182,   182,   182,   182,    -4,
     182,   182,   182,   182,   182,   182,   182,   182,   182,   182,
     182,   182,   100,   520,   103,    -4,   182,    77,  1338,   -67,
     -67,   -67,   -67,   227,    -3,    61,   247,   -67,   556,   592,
     628,   664,   700,   736,   772,   808,   844,   -67,   880,   916,
     952,   988,  1024,    -5,    -5,   -36,   -36,    19,   324,  1354,
    1354,  1338,    98,    98,    98,    98,  1374,  1374,    99,   -28,
     -67,   182,   -67,    91,  1060,   182,    -7,    67,   -67,   182,
      71,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     182,   -67,   182,   182,   182,    -4,   182,   -67,    22,   -67,
     -67,   182,  1080,    -4,   -67,   182,   286,   182,  1116,  1152,
    1188,  1224,   126,  1260,    -4,   -67,  1280,    -4,    88,   306,
     -67,   345,   -67,   -67,   182,   -67,   -67,    -4,   130,    -4,
      77,   -67,   -67,   -67,  1318,   132,   -67,   102,   -67,   -67,
     -67,   -67
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     3,     1,     0,     0,     0,     0,     0,
       4,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      13,     0,     0,     0,     0,     0,     0,    35,    36,    37,
      38,    39,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,    14,     0,     0,     0,     0,
       0,    75,    76,    78,    77,     5,    16,     0,     0,     0,
      50,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    31,     0,     0,     0,     0,    15,     7,
       8,     9,     6,     0,     0,    29,     0,    57,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    67,     0,     0,
       0,     0,     0,    40,    41,    42,    43,     0,    44,    46,
      47,    45,    51,    52,    53,    54,    55,    56,    48,    49,
      21,     0,    22,     0,     0,     0,     0,    11,    10,     0,
      73,    58,    59,    60,    61,    62,    63,    64,    65,    66,
       0,    69,     0,     0,     0,     0,     0,    17,     0,    32,
      23,     0,     0,     0,    25,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,     0,     0,     0,     0,
      30,     0,    68,    70,     0,    72,    20,     0,     0,     0,
      33,    26,    12,    74,     0,    27,    19,     0,    34,    71,
      28,    24
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -67,   -67,   -67,   -67,   -67,     1,   -67,   -66,   -67,     3,
     -55,   -13,    42
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     5,    10,    60,    19,    20,   178,    21,   102,
     156,   103,    65
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      48,    25,    93,    51,    12,    53,    87,    88,   183,    13,
      93,     1,    66,    67,     3,     4,   100,   101,    14,    69,
      70,    55,    57,    15,   100,    61,    62,    63,    64,   109,
      58,   110,   111,    93,   175,   176,   177,   194,    11,   195,
      22,    16,    23,   108,    17,    49,   113,   100,   101,   184,
      24,    18,    50,    52,    54,   116,    56,    26,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   128,   129,   130,
     131,   132,   133,   134,   135,   136,    59,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,    71,
     137,    68,    72,   154,    73,    74,    85,    86,    87,    88,
       6,    75,    76,     7,    77,    78,   153,    85,    86,    87,
      88,    79,    80,    81,    82,    83,    84,   104,   106,   112,
     150,    90,    91,   152,    92,    93,    94,    95,    96,    97,
      98,    99,   114,     8,   155,   159,    93,    93,   180,   100,
     101,   185,   182,   206,   211,   187,   186,   216,   176,   220,
     100,   101,     9,   221,   179,   218,   158,   188,     0,   189,
     190,   191,   115,   193,     0,     0,    27,    28,   196,    29,
      30,    31,   199,     0,   201,     0,   192,     0,     0,     0,
       0,     0,    32,   127,   198,    27,    28,     0,    29,    30,
      31,   214,     0,     0,     0,   208,     0,     0,   210,    33,
       0,    32,     0,     0,     0,     0,     0,     0,   215,     0,
     217,     0,     0,     0,     0,     0,     0,     0,    33,     0,
       0,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,     0,    46,    47,    85,    86,    87,    88,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,     0,    46,    47,     0,    85,    86,    87,    88,
       0,    90,    91,     0,    92,    93,    94,    95,    96,    97,
      98,    99,     0,     0,     0,     0,     0,     0,     0,   100,
     101,    90,    91,     0,    92,    93,    94,    95,    96,    97,
      98,    99,     0,     0,     0,    85,    86,    87,    88,   100,
     101,     0,   157,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    85,    86,    87,    88,     0,
      90,    91,   160,    92,    93,    94,    95,    96,    97,    98,
      99,     0,     0,    85,    86,    87,    88,     0,   100,   101,
      90,    91,     0,    92,    93,    94,    95,    96,    97,    98,
      99,     0,     0,     0,    85,    86,    87,    88,   100,   101,
       0,   200,    93,    94,    95,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,     0,   100,   101,     0,    90,
      91,   212,    92,    93,    94,    95,    96,    97,    98,    99,
       0,     0,     0,     0,     0,     0,     0,   100,   101,    85,
      86,    87,    88,     0,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     213,     0,     0,     0,    90,    91,     0,    92,    93,    94,
      95,    96,    97,    98,    99,    85,    86,    87,    88,     0,
       0,     0,   100,   101,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    85,    86,    87,    88,     0,
      90,    91,     0,    92,    93,    94,    95,    96,    97,    98,
      99,     0,   105,     0,     0,     0,     0,     0,   100,   101,
      90,    91,     0,    92,    93,    94,    95,    96,    97,    98,
      99,     0,   107,    85,    86,    87,    88,     0,   100,   101,
       0,     0,     0,     0,   117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,    91,
       0,    92,    93,    94,    95,    96,    97,    98,    99,    85,
      86,    87,    88,     0,     0,     0,   100,   101,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   151,     0,    90,    91,     0,    92,    93,    94,
      95,    96,    97,    98,    99,    85,    86,    87,    88,     0,
       0,     0,   100,   101,     0,     0,   161,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      90,    91,     0,    92,    93,    94,    95,    96,    97,    98,
      99,    85,    86,    87,    88,     0,     0,     0,   100,   101,
       0,     0,   162,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    91,     0,    92,
      93,    94,    95,    96,    97,    98,    99,    85,    86,    87,
      88,     0,     0,     0,   100,   101,     0,     0,   163,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    90,    91,     0,    92,    93,    94,    95,    96,
      97,    98,    99,    85,    86,    87,    88,     0,     0,     0,
     100,   101,     0,     0,   164,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,    91,
       0,    92,    93,    94,    95,    96,    97,    98,    99,    85,
      86,    87,    88,     0,     0,     0,   100,   101,     0,     0,
     165,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    91,     0,    92,    93,    94,
      95,    96,    97,    98,    99,    85,    86,    87,    88,     0,
       0,     0,   100,   101,     0,     0,   166,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      90,    91,     0,    92,    93,    94,    95,    96,    97,    98,
      99,    85,    86,    87,    88,     0,     0,     0,   100,   101,
       0,     0,   167,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    91,     0,    92,
      93,    94,    95,    96,    97,    98,    99,    85,    86,    87,
      88,     0,     0,     0,   100,   101,     0,     0,   168,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    90,    91,     0,    92,    93,    94,    95,    96,
      97,    98,    99,    85,    86,    87,    88,     0,     0,     0,
     100,   101,     0,     0,   169,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,    91,
       0,    92,    93,    94,    95,    96,    97,    98,    99,    85,
      86,    87,    88,     0,     0,     0,   100,   101,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   170,     0,    90,    91,     0,    92,    93,    94,
      95,    96,    97,    98,    99,    85,    86,    87,    88,     0,
       0,     0,   100,   101,     0,     0,   171,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      90,    91,     0,    92,    93,    94,    95,    96,    97,    98,
      99,    85,    86,    87,    88,     0,     0,     0,   100,   101,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   172,     0,    90,    91,     0,    92,
      93,    94,    95,    96,    97,    98,    99,    85,    86,    87,
      88,     0,     0,     0,   100,   101,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     173,     0,    90,    91,     0,    92,    93,    94,    95,    96,
      97,    98,    99,    85,    86,    87,    88,     0,     0,     0,
     100,   101,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   174,     0,    90,    91,
       0,    92,    93,    94,    95,    96,    97,    98,    99,    85,
      86,    87,    88,     0,     0,     0,   100,   101,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    85,
      86,    87,    88,     0,    90,    91,     0,    92,    93,    94,
      95,    96,    97,    98,    99,     0,   197,     0,     0,     0,
     181,     0,   100,   101,    90,    91,     0,    92,    93,    94,
      95,    96,    97,    98,    99,    85,    86,    87,    88,     0,
       0,     0,   100,   101,     0,     0,   202,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      90,    91,     0,    92,    93,    94,    95,    96,    97,    98,
      99,    85,    86,    87,    88,     0,     0,     0,   100,   101,
       0,     0,   203,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    91,     0,    92,
      93,    94,    95,    96,    97,    98,    99,    85,    86,    87,
      88,     0,     0,     0,   100,   101,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     204,     0,    90,    91,     0,    92,    93,    94,    95,    96,
      97,    98,    99,    85,    86,    87,    88,     0,     0,     0,
     100,   101,     0,     0,   205,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,    91,
       0,    92,    93,    94,    95,    96,    97,    98,    99,    85,
      86,    87,    88,     0,   207,     0,   100,   101,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    85,
      86,    87,    88,     0,    90,    91,     0,    92,    93,    94,
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,     0,   100,   101,    90,    91,     0,    92,    93,    94,
      95,    96,    97,    98,    99,     0,   209,    85,    86,    87,
      88,     0,   100,   101,     0,     0,     0,     0,   219,     0,
       0,     0,     0,     0,     0,     0,     0,    85,    86,    87,
      88,     0,    90,    91,     0,    92,    93,    94,    95,    96,
      97,    98,    99,    85,    86,    87,    88,     0,     0,     0,
     100,   101,    90,    91,     0,    92,    93,    94,    95,    96,
      97,    98,    99,    85,    86,    87,    88,     0,    90,     0,
     100,   101,    93,    94,    95,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,     0,   100,   101,     0,     0,
       0,     0,    93,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   100,   101
};

static const yytype_int16 yycheck[] =
{
      13,    18,    38,    16,     8,    18,    11,    12,    15,    13,
      38,    23,    25,    26,     8,     0,    52,    53,    22,    32,
      33,    20,    18,    27,    52,    28,    29,    30,    31,     4,
      26,     6,     7,    38,    15,    16,    17,    15,     8,    17,
       8,    45,     8,    56,    48,    19,    59,    52,    53,    56,
      26,    55,    19,     8,    25,    68,    18,    74,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    74,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,    19,
      89,    74,    19,   106,    19,    19,     9,    10,    11,    12,
      21,    19,    19,    24,    19,    19,   105,     9,    10,    11,
      12,    19,    19,    19,    19,    19,    19,     8,    49,     3,
      20,    34,    35,    20,    37,    38,    39,    40,    41,    42,
      43,    44,    26,    54,    57,    74,    38,    38,    47,    52,
      53,    74,   155,    17,    56,    74,   159,    17,    16,   215,
      52,    53,    73,    51,   151,   210,   114,   170,    -1,   172,
     173,   174,    75,   176,    -1,    -1,     3,     4,   181,     6,
       7,     8,   185,    -1,   187,    -1,   175,    -1,    -1,    -1,
      -1,    -1,    19,    20,   183,     3,     4,    -1,     6,     7,
       8,   204,    -1,    -1,    -1,   194,    -1,    -1,   197,    36,
      -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,
     209,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    71,    72,     9,    10,    11,    12,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    72,    -1,     9,    10,    11,    12,
      -1,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      53,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,     9,    10,    11,    12,    52,
      53,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    10,    11,    12,    -1,
      34,    35,    75,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,     9,    10,    11,    12,    -1,    52,    53,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,     9,    10,    11,    12,    52,    53,
      -1,    75,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    -1,    34,
      35,    75,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,     9,
      10,    11,    12,    -1,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,     9,    10,    11,    12,    -1,
      -1,    -1,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    10,    11,    12,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    46,    -1,    -1,    -1,    -1,    -1,    52,    53,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    46,     9,    10,    11,    12,    -1,    52,    53,
      -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,     9,
      10,    11,    12,    -1,    -1,    -1,    52,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    34,    35,    -1,    37,    38,    39,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,     9,    10,    11,    12,    -1,
      -1,    -1,    52,    53,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,     9,    10,    11,    12,    -1,    -1,    -1,    52,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,     9,    10,    11,
      12,    -1,    -1,    -1,    52,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    -1,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,     9,    10,    11,    12,    -1,    -1,    -1,
      52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,     9,
      10,    11,    12,    -1,    -1,    -1,    52,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      10,    11,    12,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    26,    -1,    -1,    -1,
      50,    -1,    52,    53,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,     9,    10,    11,    12,    -1,
      -1,    -1,    52,    53,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,     9,    10,    11,    12,    -1,    -1,    -1,    52,    53,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,     9,    10,    11,
      12,    -1,    -1,    -1,    52,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    -1,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,     9,    10,    11,    12,    -1,    -1,    -1,
      52,    53,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,     9,
      10,    11,    12,    -1,    14,    -1,    52,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      10,    11,    12,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    53,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    46,     9,    10,    11,
      12,    -1,    52,    53,    -1,    -1,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,
      12,    -1,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,     9,    10,    11,    12,    -1,    -1,    -1,
      52,    53,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,     9,    10,    11,    12,    -1,    34,    -1,
      52,    53,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    53
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    23,    77,     8,     0,    78,    21,    24,    54,    73,
      79,     8,     8,    13,    22,    27,    45,    48,    55,    81,
      82,    84,     8,     8,    26,    18,    74,     3,     4,     6,
       7,     8,    19,    36,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    71,    72,    87,    19,
      19,    87,     8,    87,    25,    81,    18,    18,    26,    74,
      80,    28,    29,    30,    31,    88,    87,    87,    74,    87,
      87,    19,    19,    19,    19,    19,    19,    19,    19,    19,
      19,    19,    19,    19,    19,     9,    10,    11,    12,    14,
      34,    35,    37,    38,    39,    40,    41,    42,    43,    44,
      52,    53,    85,    87,     8,    46,    49,    46,    87,     4,
       6,     7,     3,    87,    26,    75,    87,    20,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    20,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    81,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      20,    32,    20,    81,    87,    57,    86,    75,    88,    74,
      75,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      32,    20,    32,    32,    32,    15,    16,    17,    83,    85,
      47,    50,    87,    15,    56,    74,    87,    74,    87,    87,
      87,    87,    81,    87,    15,    17,    87,    26,    81,    87,
      75,    87,    20,    20,    32,    20,    17,    14,    81,    46,
      81,    56,    75,    75,    87,    81,    17,    81,    86,    20,
      83,    51
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    76,    77,    78,    78,    79,    79,    79,    79,    79,
      79,    80,    80,    81,    81,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    83,    83,    84,
      84,    85,    85,    86,    86,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    88,    88,    88,    88
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     6,     0,     2,     4,     4,     4,     4,     4,
       5,     3,     6,     1,     2,     3,     3,     5,     6,     8,
       7,     4,     4,     5,     9,     5,     7,     4,     5,     4,
       7,     1,     3,     4,     5,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     3,     6,     4,
       6,     8,     6,     4,     7,     1,     1,     1,     1
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
#line 80 "parser.y"
                                                                 { printf("*********************\nAlgorithme %s\n\n*********************\n\n", (yyvsp[-4].var_name)); parsed_program = (yyvsp[-1].statement_list); }
#line 1540 "parser.tab.c"
    break;

  case 5: /* Declaration: VARIABLE_KWRD IDENTIFIANT COLON type  */
#line 88 "parser.y"
                                         { add_symbol((yyvsp[-2].var_name), (yyvsp[0].type), false); }
#line 1546 "parser.tab.c"
    break;

  case 6: /* Declaration: CONSTANT IDENTIFIANT COLON ENTIER_VAL  */
#line 89 "parser.y"
                                            { add_symbol((yyvsp[-2].var_name), TYPE_ENTIER, true); set_symbol_value((yyvsp[-2].var_name), new_integer((yyvsp[0].int_value))); }
#line 1552 "parser.tab.c"
    break;

  case 7: /* Declaration: CONSTANT IDENTIFIANT EQUALS DECIMAL_VAL  */
#line 90 "parser.y"
                                              { add_symbol((yyvsp[-2].var_name), TYPE_DECIMAL, true); set_symbol_value((yyvsp[-2].var_name), new_decimal((yyvsp[0].double_value))); }
#line 1558 "parser.tab.c"
    break;

  case 8: /* Declaration: CONSTANT IDENTIFIANT EQUALS STRING_VAL  */
#line 91 "parser.y"
                                             { add_symbol((yyvsp[-2].var_name), TYPE_CHAINE, true); set_symbol_value((yyvsp[-2].var_name), new_string((yyvsp[0].string_value)));}
#line 1564 "parser.tab.c"
    break;

  case 9: /* Declaration: CONSTANT IDENTIFIANT EQUALS LOGIQUE_VAL  */
#line 92 "parser.y"
                                              { add_symbol((yyvsp[-2].var_name), TYPE_LOGIQUE, true); set_symbol_value((yyvsp[-2].var_name), new_boolean((yyvsp[0].bval))); }
#line 1570 "parser.tab.c"
    break;

  case 10: /* Declaration: TABLEAU IDENTIFIANT array_dimensions COLON type  */
#line 93 "parser.y"
                                                      {
        add_array_symbol((yyvsp[-3].var_name), (yyvsp[0].type), (yyvsp[-2].dims));
    }
#line 1578 "parser.tab.c"
    break;

  case 11: /* array_dimensions: LBRACKET expression RBRACKET  */
#line 99 "parser.y"
                                 {
        ArrayDimensions dims;
        Expression *size = evaluate_expression((yyvsp[-1].expression));
        dims.sizes[0] = size->data.int_value;
        dims.num_dimensions = 1;
        free(size);
        (yyval.dims) = dims;
    }
#line 1591 "parser.tab.c"
    break;

  case 12: /* array_dimensions: LBRACKET expression RBRACKET LBRACKET expression RBRACKET  */
#line 107 "parser.y"
                                                                {
        ArrayDimensions dims;
        Expression *size1 = evaluate_expression((yyvsp[-4].expression));
        Expression *size2 = evaluate_expression((yyvsp[-1].expression));
        dims.sizes[0] = size1->data.int_value;
        dims.sizes[1] = size2->data.int_value;
        dims.num_dimensions = 2;
        free(size1);
        free(size2);
        (yyval.dims) = dims;
    }
#line 1607 "parser.tab.c"
    break;

  case 13: /* statement_list: statement  */
#line 121 "parser.y"
              { (yyval.statement_list) = new_statement_list((yyvsp[0].statement), NULL); }
#line 1613 "parser.tab.c"
    break;

  case 14: /* statement_list: statement statement_list  */
#line 122 "parser.y"
                               { (yyval.statement_list) = new_statement_list((yyvsp[-1].statement), (yyvsp[0].statement_list)); }
#line 1619 "parser.tab.c"
    break;

  case 15: /* statement: array_ref EQUALS expression  */
#line 126 "parser.y"
                                { 
        (yyval.statement) = new_assign((yyvsp[-2].var_name), (yyvsp[0].expression)); 
        free((yyvsp[-2].var_name));
    }
#line 1628 "parser.tab.c"
    break;

  case 16: /* statement: IDENTIFIANT EQUALS expression  */
#line 130 "parser.y"
                                    { (yyval.statement) = new_assign((yyvsp[-2].var_name), (yyvsp[0].expression)); }
#line 1634 "parser.tab.c"
    break;

  case 17: /* statement: SI expression ALORS statement_list FINSI  */
#line 131 "parser.y"
                                               { (yyval.statement) = new_if_elif((yyvsp[-3].expression), (yyvsp[-1].statement_list), NULL, NULL); }
#line 1640 "parser.tab.c"
    break;

  case 18: /* statement: SI expression ALORS statement_list elif_list FINSI  */
#line 132 "parser.y"
                                                         { (yyval.statement) = new_if_elif((yyvsp[-4].expression), (yyvsp[-2].statement_list), (yyvsp[-1].elseif_list), NULL); }
#line 1646 "parser.tab.c"
    break;

  case 19: /* statement: SI expression ALORS statement_list elif_list SINON statement_list FINSI  */
#line 133 "parser.y"
                                                                              { (yyval.statement) = new_if_elif((yyvsp[-6].expression), (yyvsp[-4].statement_list), (yyvsp[-3].elseif_list), (yyvsp[-1].statement_list)); }
#line 1652 "parser.tab.c"
    break;

  case 20: /* statement: SI expression ALORS statement_list SINON statement_list FINSI  */
#line 134 "parser.y"
                                                                    { (yyval.statement) = new_if_elif((yyvsp[-5].expression), (yyvsp[-3].statement_list), NULL, (yyvsp[-1].statement_list)); }
#line 1658 "parser.tab.c"
    break;

  case 21: /* statement: ECRIRE LPAREN expression_list RPAREN  */
#line 135 "parser.y"
                                           { (yyval.statement) = new_print((yyvsp[-1].expression_list)); }
#line 1664 "parser.tab.c"
    break;

  case 22: /* statement: LIRE LPAREN IDENTIFIANT RPAREN  */
#line 136 "parser.y"
                                     { (yyval.statement) = new_read((yyvsp[-1].var_name)); }
#line 1670 "parser.tab.c"
    break;

  case 23: /* statement: TANTQUE expression FAIRE statement_list FINTANTQUE  */
#line 137 "parser.y"
                                                         { (yyval.statement) = new_while((yyvsp[-3].expression), (yyvsp[-1].statement_list)); }
#line 1676 "parser.tab.c"
    break;

  case 24: /* statement: POUR IDENTIFIANT DE expression A expression FAIRE statement_list FINPOUR  */
#line 138 "parser.y"
                                                                               { (yyval.statement) = new_for((yyvsp[-7].var_name), (yyvsp[-5].expression), (yyvsp[-3].expression), (yyvsp[-1].statement_list)); }
#line 1682 "parser.tab.c"
    break;

  case 25: /* statement: SELON expression FAIRE case_list FINSELON  */
#line 139 "parser.y"
                                                { (yyval.statement) = new_switch((yyvsp[-3].expression), (yyvsp[-1].case_list), NULL); }
#line 1688 "parser.tab.c"
    break;

  case 26: /* statement: SELON expression FAIRE case_list SINON statement_list FINSELON  */
#line 140 "parser.y"
                                                                     { (yyval.statement) = new_switch((yyvsp[-5].expression), (yyvsp[-3].case_list), (yyvsp[-1].statement_list)); }
#line 1694 "parser.tab.c"
    break;

  case 27: /* elif_list: SINONSI expression ALORS statement_list  */
#line 145 "parser.y"
        { (yyval.elseif_list) = new_elif_list((yyvsp[-2].expression), (yyvsp[0].statement_list), NULL); }
#line 1700 "parser.tab.c"
    break;

  case 28: /* elif_list: SINONSI expression ALORS statement_list elif_list  */
#line 147 "parser.y"
        { (yyval.elseif_list) = new_elif_list((yyvsp[-3].expression), (yyvsp[-1].statement_list), (yyvsp[0].elseif_list)); }
#line 1706 "parser.tab.c"
    break;

  case 29: /* array_ref: IDENTIFIANT LBRACKET expression RBRACKET  */
#line 151 "parser.y"
                                             {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s[%d]", (yyvsp[-3].var_name), 
                evaluate_expression((yyvsp[-1].expression))->data.int_value);
        (yyval.var_name) = strdup(buffer);
    }
#line 1717 "parser.tab.c"
    break;

  case 30: /* array_ref: IDENTIFIANT LBRACKET expression RBRACKET LBRACKET expression RBRACKET  */
#line 157 "parser.y"
                                                                            {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s[%d][%d]", (yyvsp[-6].var_name),
                evaluate_expression((yyvsp[-4].expression))->data.int_value,
                evaluate_expression((yyvsp[-1].expression))->data.int_value);
        (yyval.var_name) = strdup(buffer);
    }
#line 1729 "parser.tab.c"
    break;

  case 31: /* expression_list: expression  */
#line 167 "parser.y"
               { (yyval.expression_list) = new_expression_list((yyvsp[0].expression), NULL); }
#line 1735 "parser.tab.c"
    break;

  case 32: /* expression_list: expression COMMA expression_list  */
#line 168 "parser.y"
                                       { (yyval.expression_list) = new_expression_list((yyvsp[-2].expression), (yyvsp[0].expression_list)); }
#line 1741 "parser.tab.c"
    break;

  case 33: /* case_list: CAS expression COLON statement_list  */
#line 172 "parser.y"
                                        { (yyval.case_list) = new_case_list((yyvsp[-2].expression), (yyvsp[0].statement_list), NULL); }
#line 1747 "parser.tab.c"
    break;

  case 34: /* case_list: CAS expression COLON statement_list case_list  */
#line 173 "parser.y"
                                                    { (yyval.case_list) = new_case_list((yyvsp[-3].expression), (yyvsp[-1].statement_list), (yyvsp[0].case_list)); }
#line 1753 "parser.tab.c"
    break;

  case 35: /* expression: ENTIER_VAL  */
#line 177 "parser.y"
               { (yyval.expression) = new_integer((yyvsp[0].int_value)); }
#line 1759 "parser.tab.c"
    break;

  case 36: /* expression: DECIMAL_VAL  */
#line 178 "parser.y"
                  { (yyval.expression) = new_decimal((yyvsp[0].double_value)); }
#line 1765 "parser.tab.c"
    break;

  case 37: /* expression: STRING_VAL  */
#line 179 "parser.y"
                 { (yyval.expression) = new_string((yyvsp[0].string_value)); }
#line 1771 "parser.tab.c"
    break;

  case 38: /* expression: LOGIQUE_VAL  */
#line 180 "parser.y"
                  { (yyval.expression) = new_boolean((yyvsp[0].bval)); }
#line 1777 "parser.tab.c"
    break;

  case 39: /* expression: IDENTIFIANT  */
#line 181 "parser.y"
                  { (yyval.expression) = new_variable((yyvsp[0].var_name)); }
#line 1783 "parser.tab.c"
    break;

  case 40: /* expression: expression PLUS expression  */
#line 182 "parser.y"
                                 { (yyval.expression) = new_binary_op('+', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1789 "parser.tab.c"
    break;

  case 41: /* expression: expression MINUS expression  */
#line 183 "parser.y"
                                  { (yyval.expression) = new_binary_op('-', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1795 "parser.tab.c"
    break;

  case 42: /* expression: expression TIMES expression  */
#line 184 "parser.y"
                                  { (yyval.expression) = new_binary_op('*', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1801 "parser.tab.c"
    break;

  case 43: /* expression: expression DIVIDE expression  */
#line 185 "parser.y"
                                   { (yyval.expression) = new_binary_op('/', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1807 "parser.tab.c"
    break;

  case 44: /* expression: expression AND expression  */
#line 186 "parser.y"
                                { (yyval.expression) = new_binary_op('&', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1813 "parser.tab.c"
    break;

  case 45: /* expression: expression CONCAT expression  */
#line 187 "parser.y"
                                   { (yyval.expression) = new_binary_op('C', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1819 "parser.tab.c"
    break;

  case 46: /* expression: expression OR expression  */
#line 188 "parser.y"
                               { (yyval.expression) = new_binary_op('|', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1825 "parser.tab.c"
    break;

  case 47: /* expression: expression XOR expression  */
#line 189 "parser.y"
                                { (yyval.expression) = new_binary_op('^', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1831 "parser.tab.c"
    break;

  case 48: /* expression: expression POWER expression  */
#line 190 "parser.y"
                                  { (yyval.expression) = new_binary_op('P', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1837 "parser.tab.c"
    break;

  case 49: /* expression: expression MODULO expression  */
#line 191 "parser.y"
                                   { (yyval.expression) = new_binary_op('M', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1843 "parser.tab.c"
    break;

  case 50: /* expression: NOT expression  */
#line 192 "parser.y"
                     { (yyval.expression) = new_unary_op('!', (yyvsp[0].expression)); }
#line 1849 "parser.tab.c"
    break;

  case 51: /* expression: expression LT expression  */
#line 193 "parser.y"
                               { (yyval.expression) = new_binary_op('<', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1855 "parser.tab.c"
    break;

  case 52: /* expression: expression GT expression  */
#line 194 "parser.y"
                               { (yyval.expression) = new_binary_op('>', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1861 "parser.tab.c"
    break;

  case 53: /* expression: expression LE expression  */
#line 195 "parser.y"
                               { (yyval.expression) = new_binary_op('L', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1867 "parser.tab.c"
    break;

  case 54: /* expression: expression GE expression  */
#line 196 "parser.y"
                               { (yyval.expression) = new_binary_op('G', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1873 "parser.tab.c"
    break;

  case 55: /* expression: expression EQ expression  */
#line 197 "parser.y"
                               { (yyval.expression) = new_binary_op('=', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1879 "parser.tab.c"
    break;

  case 56: /* expression: expression NE expression  */
#line 198 "parser.y"
                               { (yyval.expression) = new_binary_op('!', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1885 "parser.tab.c"
    break;

  case 57: /* expression: LPAREN expression RPAREN  */
#line 199 "parser.y"
                               { (yyval.expression) = (yyvsp[-1].expression); }
#line 1891 "parser.tab.c"
    break;

  case 58: /* expression: SQUARE_ROOT LPAREN expression RPAREN  */
#line 200 "parser.y"
                                           { (yyval.expression) = new_unary_op('R', (yyvsp[-1].expression)); }
#line 1897 "parser.tab.c"
    break;

  case 59: /* expression: SINE LPAREN expression RPAREN  */
#line 201 "parser.y"
                                    { (yyval.expression) = new_unary_op('S', (yyvsp[-1].expression)); }
#line 1903 "parser.tab.c"
    break;

  case 60: /* expression: COSINE LPAREN expression RPAREN  */
#line 202 "parser.y"
                                      { (yyval.expression) = new_unary_op('C', (yyvsp[-1].expression)); }
#line 1909 "parser.tab.c"
    break;

  case 61: /* expression: TANGENT LPAREN expression RPAREN  */
#line 203 "parser.y"
                                       { (yyval.expression) = new_unary_op('T', (yyvsp[-1].expression)); }
#line 1915 "parser.tab.c"
    break;

  case 62: /* expression: LOG LPAREN expression RPAREN  */
#line 204 "parser.y"
                                   {(yyval.expression) = new_unary_op('L', (yyvsp[-1].expression)); }
#line 1921 "parser.tab.c"
    break;

  case 63: /* expression: LOG10 LPAREN expression RPAREN  */
#line 205 "parser.y"
                                     { (yyval.expression) = new_unary_op('l', (yyvsp[-1].expression));}
#line 1927 "parser.tab.c"
    break;

  case 64: /* expression: ROUND LPAREN expression RPAREN  */
#line 206 "parser.y"
                                     { (yyval.expression) = new_unary_op('D', (yyvsp[-1].expression));}
#line 1933 "parser.tab.c"
    break;

  case 65: /* expression: ABS LPAREN expression RPAREN  */
#line 207 "parser.y"
                                   { (yyval.expression) = new_unary_op('A', (yyvsp[-1].expression));}
#line 1939 "parser.tab.c"
    break;

  case 66: /* expression: INT LPAREN expression RPAREN  */
#line 208 "parser.y"
                                   { (yyval.expression) = new_unary_op('E', (yyvsp[-1].expression));}
#line 1945 "parser.tab.c"
    break;

  case 67: /* expression: RANDOM LPAREN RPAREN  */
#line 209 "parser.y"
                           {
        srand(time(0));
        double random_number = (double)rand() / (RAND_MAX + 1.0);
        (yyval.expression) = new_decimal(random_number);
    }
#line 1955 "parser.tab.c"
    break;

  case 68: /* expression: RANDOM LPAREN expression COMMA expression RPAREN  */
#line 214 "parser.y"
                                                       { (yyval.expression) = new_binary_op('A', (yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 1961 "parser.tab.c"
    break;

  case 69: /* expression: LENGTH LPAREN expression RPAREN  */
#line 215 "parser.y"
                                      { (yyval.expression) = new_unary_op('H', (yyvsp[-1].expression)); }
#line 1967 "parser.tab.c"
    break;

  case 70: /* expression: COMPARE LPAREN expression COMMA expression RPAREN  */
#line 216 "parser.y"
                                                        { (yyval.expression) = new_binary_op('p', (yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 1973 "parser.tab.c"
    break;

  case 71: /* expression: COPY LPAREN expression COMMA expression COMMA expression RPAREN  */
#line 217 "parser.y"
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
#line 2002 "parser.tab.c"
    break;

  case 72: /* expression: SEARCH LPAREN expression COMMA expression RPAREN  */
#line 241 "parser.y"
                                                       { (yyval.expression) = new_binary_op('r', (yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 2008 "parser.tab.c"
    break;

  case 73: /* expression: IDENTIFIANT LBRACKET expression RBRACKET  */
#line 242 "parser.y"
                                               {
        (yyval.expression) = new_array_access((yyvsp[-3].var_name), (yyvsp[-1].expression), NULL);
    }
#line 2016 "parser.tab.c"
    break;

  case 74: /* expression: IDENTIFIANT LBRACKET expression RBRACKET LBRACKET expression RBRACKET  */
#line 245 "parser.y"
                                                                            {
        (yyval.expression) = new_array_access((yyvsp[-6].var_name), (yyvsp[-4].expression), (yyvsp[-1].expression));
    }
#line 2024 "parser.tab.c"
    break;

  case 75: /* type: ENTIER_KWRD  */
#line 251 "parser.y"
                { (yyval.type) = TYPE_ENTIER; }
#line 2030 "parser.tab.c"
    break;

  case 76: /* type: DECIMAL_KWRD  */
#line 252 "parser.y"
                   { (yyval.type) = TYPE_DECIMAL; }
#line 2036 "parser.tab.c"
    break;

  case 77: /* type: CHAINE_KWRD  */
#line 253 "parser.y"
                  { (yyval.type) = TYPE_CHAINE; }
#line 2042 "parser.tab.c"
    break;

  case 78: /* type: LOGIQUE_KWRD  */
#line 254 "parser.y"
                   { (yyval.type) = TYPE_LOGIQUE; }
#line 2048 "parser.tab.c"
    break;


#line 2052 "parser.tab.c"

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

#line 257 "parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "Erreur ligne %d: %s\n", yylineno, s);
}
