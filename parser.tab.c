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


#line 86 "parser.tab.c"

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
  YYSYMBOL_VARIABLES = 76,                 /* VARIABLES  */
  YYSYMBOL_FONCTION = 77,                  /* FONCTION  */
  YYSYMBOL_RETOURNER = 78,                 /* RETOURNER  */
  YYSYMBOL_FINFONCTION = 79,               /* FINFONCTION  */
  YYSYMBOL_YYACCEPT = 80,                  /* $accept  */
  YYSYMBOL_program = 81,                   /* program  */
  YYSYMBOL_function_decl = 82,             /* function_decl  */
  YYSYMBOL_param_list = 83,                /* param_list  */
  YYSYMBOL_param = 84,                     /* param  */
  YYSYMBOL_args_list = 85,                 /* args_list  */
  YYSYMBOL_Declarations = 86,              /* Declarations  */
  YYSYMBOL_Declaration = 87,               /* Declaration  */
  YYSYMBOL_identifier_list = 88,           /* identifier_list  */
  YYSYMBOL_array_dimensions = 89,          /* array_dimensions  */
  YYSYMBOL_statement_list = 90,            /* statement_list  */
  YYSYMBOL_statement = 91,                 /* statement  */
  YYSYMBOL_elif_list = 92,                 /* elif_list  */
  YYSYMBOL_expression_list = 93,           /* expression_list  */
  YYSYMBOL_case_list = 94,                 /* case_list  */
  YYSYMBOL_expression = 95,                /* expression  */
  YYSYMBOL_type = 96                       /* type  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1531

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  80
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  266

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   334


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
      75,    76,    77,    78,    79
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    87,    87,    88,    92,    96,   103,   104,   105,   109,
     113,   114,   115,   119,   120,   130,   138,   142,   147,   152,
     157,   162,   169,   170,   174,   182,   196,   197,   201,   205,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   225,   227,   232,   233,   237,   238,   242,
     243,   244,   245,   246,   247,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   283,   284,   285,   286,   310,   311,   314,
     320,   321,   322,   323
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
  "LBRACKET", "RBRACKET", "VARIABLES", "FONCTION", "RETOURNER",
  "FINFONCTION", "$accept", "program", "function_decl", "param_list",
  "param", "args_list", "Declarations", "Declaration", "identifier_list",
  "array_dimensions", "statement_list", "statement", "elif_list",
  "expression_list", "case_list", "expression", "type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-81)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -55,    19,    38,   -55,    -6,    25,   -81,   -81,    35,   105,
      37,    39,    41,   -81,    42,    26,    -8,   237,    27,    36,
     237,    46,   237,   237,    32,   105,    43,   -11,    33,    63,
      76,    83,    72,     3,   237,   237,   237,   -81,   -81,   -81,
     -81,   -15,   237,   237,    86,    88,    89,    90,    91,    93,
      95,    96,   107,   109,   110,   112,   114,   115,   478,   237,
     127,   514,    87,   534,  1478,   -81,   -81,    17,   237,   113,
      41,     3,     3,   116,    42,   -81,   -81,   -81,   -81,   -81,
    1478,   117,   572,   276,   237,   237,   608,   100,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   203,   237,   237,
     237,   237,   237,   237,   237,   237,   -81,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   120,
     644,   121,   -81,   237,   -81,   -81,   -81,   -81,   -81,   315,
       3,   -81,   -81,   -81,     3,   103,   -81,   -81,   237,    -5,
     125,   335,   -81,   680,   716,   752,   788,   824,   860,   896,
     932,   968,   -81,  1004,  1040,  1076,  1112,  1148,   310,   310,
     -24,   -24,   103,   238,  1164,  1164,  1478,   111,   111,   111,
     111,   412,   412,   100,   -22,   -81,   237,   -81,   103,  1184,
     123,    69,   -81,   -81,    68,   -81,   237,   237,   -81,    78,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   237,
     -81,   237,   237,   237,    20,   -81,   108,   237,   237,    -3,
     237,   103,   -81,  1478,   374,   237,  1220,  1256,  1292,  1328,
     -81,   237,   -81,    24,   -81,  1348,  1386,   -81,   -81,   394,
      77,   147,   433,   -81,   -81,   237,   -81,   103,  1422,   -81,
     -81,   -81,   105,   103,   -81,   -81,   237,   -81,  1458,   149,
     105,   103,   103,   130,   118,  1478,   -81,   -81,   151,   154,
     137,   -81,   -81,   -81,   -81,   -81
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      13,     0,     0,    13,     0,     0,     1,     3,     0,     0,
       0,     0,     0,    14,     6,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,     0,    22,     0,
       0,     0,     7,     0,     0,    10,     0,    49,    50,    51,
      52,    53,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    42,     2,    27,     0,     0,     0,
       0,     0,     0,    13,     6,    90,    91,    93,    92,    15,
      30,     0,    11,     0,    10,     0,     0,    65,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    13,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      45,     0,    13,     0,    13,    17,    18,    19,    20,     0,
       0,    23,    16,     9,     0,     0,     8,    41,    10,     0,
       0,     0,    72,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    82,     0,     0,     0,     0,     0,    55,    56,
      57,    58,     0,    59,    61,    62,    60,    66,    67,    68,
      69,    70,    71,    63,    64,    35,     0,    36,     0,     0,
       0,    24,    21,    13,     0,    12,     0,     0,    54,    88,
      73,    74,    75,    76,    77,    78,    79,    80,    81,     0,
      84,     0,     0,     0,     0,    46,     0,     0,     0,     0,
       0,     0,     4,    28,     0,     0,     0,     0,     0,     0,
      13,     0,    31,     0,    37,     0,     0,    13,    39,     0,
       0,     0,     0,    83,    85,     0,    87,     0,     0,    13,
      32,    13,     0,     0,    25,     5,     0,    89,     0,     0,
       0,     0,     0,    47,     0,    29,    86,    34,    43,     0,
       0,    48,    40,    44,    33,    38
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -81,   165,   -81,    98,   -81,   -76,   -66,   -81,   119,   -81,
     -16,   -81,   -80,    16,   -59,   -17,   -70
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,    31,    32,    81,     4,    13,    29,    69,
      24,    25,   223,   119,   209,    82,    79
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      58,   132,   133,    61,    84,    63,    64,   135,   140,    66,
      34,    35,   227,   186,   110,     8,   110,    80,     9,    83,
     125,   126,     1,   127,   128,    86,    87,     5,   117,   118,
     117,    75,    76,    77,    78,   220,   221,   222,     6,   239,
     162,   240,   120,    15,    14,    26,    59,    27,    10,    28,
      30,   129,    33,   228,    62,    60,   178,    65,   180,    85,
     182,    67,   185,    68,   183,    70,    36,    11,   141,   187,
      12,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     153,   154,   155,   156,   157,   158,   159,   160,   161,    71,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,    72,    73,    74,    88,   179,    89,    90,    91,
      92,    16,    93,    16,    94,    95,    17,   211,    17,   184,
     102,   103,   104,   105,     8,    18,    96,    18,    97,    98,
      19,    99,    19,   100,   101,   121,   123,   137,   110,   130,
     175,   177,   134,   210,     8,   188,   204,   212,    20,   110,
      20,    21,   215,    21,   237,   224,   245,    10,    22,   120,
      22,   243,   206,   117,   118,   246,   257,   221,     7,   213,
     214,   264,   136,   251,   262,   252,    11,    10,   263,    12,
     208,    23,   216,    23,   217,   218,   219,   208,   265,   131,
     225,   226,   205,   229,   261,   230,    11,     0,   232,    12,
       0,     0,     0,     0,   238,     0,    37,    38,     0,    39,
      40,    41,     0,     0,     0,     0,     0,     0,   248,     0,
       0,   249,    42,   152,     0,     0,   253,   254,     0,   255,
       0,     0,     0,     0,   258,   259,   260,     0,     0,    43,
      37,    38,     0,    39,    40,    41,     0,   102,   103,   104,
     105,     0,     0,     0,     0,     0,    42,     0,     0,     0,
       0,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    43,    56,    57,   110,   111,   112,   113,
     114,   115,   116,     0,     0,   102,   103,   104,   105,     0,
     117,   118,     0,     0,     0,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,     0,    56,    57,
     107,   108,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   104,   105,     0,   102,   103,   104,   105,   117,   118,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   102,   103,   104,   105,   110,   107,
     108,   139,   109,   110,   111,   112,   113,   114,   115,   116,
       0,     0,   117,   118,     0,     0,     0,   117,   118,   107,
     108,     0,   109,   110,   111,   112,   113,   114,   115,   116,
       0,     0,     0,   102,   103,   104,   105,   117,   118,     0,
     181,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   102,   103,   104,   105,     0,   107,   108,
     189,   109,   110,   111,   112,   113,   114,   115,   116,     0,
       0,   102,   103,   104,   105,     0,   117,   118,   107,   108,
       0,   109,   110,   111,   112,   113,   114,   115,   116,     0,
       0,     0,   102,   103,   104,   105,   117,   118,     0,   231,
     110,   111,   112,   113,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   117,   118,     0,   107,   108,   244,
     109,   110,   111,   112,   113,   114,   115,   116,     0,     0,
       0,     0,     0,     0,     0,   117,   118,   102,   103,   104,
     105,     0,   106,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   247,     0,
       0,     0,   107,   108,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   102,   103,   104,   105,     0,     0,     0,
     117,   118,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   102,   103,   104,   105,     0,   107,   108,
       0,   109,   110,   111,   112,   113,   114,   115,   116,     0,
     122,     0,     0,     0,     0,     0,   117,   118,   107,   108,
       0,   109,   110,   111,   112,   113,   114,   115,   116,     0,
     124,   102,   103,   104,   105,     0,   117,   118,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   138,     0,   107,   108,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   102,   103,   104,
     105,     0,     0,     0,   117,   118,     0,     0,   142,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   107,   108,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   102,   103,   104,   105,     0,     0,     0,
     117,   118,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   176,     0,   107,   108,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   102,
     103,   104,   105,     0,     0,     0,   117,   118,     0,     0,
     190,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   107,   108,     0,   109,   110,   111,
     112,   113,   114,   115,   116,   102,   103,   104,   105,     0,
       0,     0,   117,   118,     0,     0,   191,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     107,   108,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   102,   103,   104,   105,     0,     0,     0,   117,   118,
       0,     0,   192,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   107,   108,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   102,   103,   104,
     105,     0,     0,     0,   117,   118,     0,     0,   193,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   107,   108,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   102,   103,   104,   105,     0,     0,     0,
     117,   118,     0,     0,   194,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   107,   108,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   102,
     103,   104,   105,     0,     0,     0,   117,   118,     0,     0,
     195,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   107,   108,     0,   109,   110,   111,
     112,   113,   114,   115,   116,   102,   103,   104,   105,     0,
       0,     0,   117,   118,     0,     0,   196,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     107,   108,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   102,   103,   104,   105,     0,     0,     0,   117,   118,
       0,     0,   197,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   107,   108,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   102,   103,   104,
     105,     0,     0,     0,   117,   118,     0,     0,   198,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   107,   108,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   102,   103,   104,   105,     0,     0,     0,
     117,   118,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   199,     0,   107,   108,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   102,
     103,   104,   105,     0,     0,     0,   117,   118,     0,     0,
     200,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   107,   108,     0,   109,   110,   111,
     112,   113,   114,   115,   116,   102,   103,   104,   105,     0,
       0,     0,   117,   118,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   201,     0,
     107,   108,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   102,   103,   104,   105,     0,     0,     0,   117,   118,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   202,     0,   107,   108,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   102,   103,   104,
     105,     0,     0,     0,   117,   118,     0,     0,     0,     0,
       0,     0,     0,   102,   103,   104,   105,     0,     0,     0,
     203,     0,   107,   108,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   102,   103,   104,   105,     0,   107,     0,
     117,   118,   110,   111,   112,   113,   114,   115,   116,     0,
       0,     0,     0,     0,     0,     0,   117,   118,   107,   108,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   102,
     103,   104,   105,     0,   207,     0,   117,   118,     0,     0,
     233,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   107,   108,     0,   109,   110,   111,
     112,   113,   114,   115,   116,   102,   103,   104,   105,     0,
       0,     0,   117,   118,     0,     0,   234,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     107,   108,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   102,   103,   104,   105,     0,     0,     0,   117,   118,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   235,     0,   107,   108,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   102,   103,   104,
     105,     0,     0,     0,   117,   118,     0,     0,   236,     0,
       0,     0,     0,     0,     0,     0,     0,   102,   103,   104,
     105,     0,   107,   108,     0,   109,   110,   111,   112,   113,
     114,   115,   116,     0,     0,     0,     0,     0,     0,     0,
     117,   118,   107,   108,     0,   109,   110,   111,   112,   113,
     114,   115,   116,     0,   241,   102,   103,   104,   105,     0,
     117,   118,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   242,     0,     0,     0,     0,     0,     0,     0,
     107,   108,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   102,   103,   104,   105,     0,   250,     0,   117,   118,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   107,   108,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   102,   103,   104,
     105,     0,     0,     0,   117,   118,     0,     0,   256,     0,
       0,     0,     0,     0,     0,     0,     0,   102,   103,   104,
     105,     0,   107,   108,     0,   109,   110,   111,   112,   113,
     114,   115,   116,     0,     0,     0,     0,     0,     0,     0,
     117,   118,   107,   108,     0,   109,   110,   111,   112,   113,
     114,   115,   116,     0,     0,     0,     0,     0,     0,     0,
     117,   118
};

static const yytype_int16 yycheck[] =
{
      17,    71,    72,    20,    19,    22,    23,    73,    84,    25,
      18,    19,    15,    18,    38,    21,    38,    34,    24,    36,
       3,     4,    77,     6,     7,    42,    43,     8,    52,    53,
      52,    28,    29,    30,    31,    15,    16,    17,     0,    15,
     106,    17,    59,     8,    19,     8,    19,     8,    54,     8,
       8,    68,    26,    56,     8,    19,   122,    25,   124,    74,
     130,    18,   138,    74,   134,    32,    74,    73,    85,    74,
      76,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,    26,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,    26,    20,    32,    19,   123,    19,    19,    19,
      19,     8,    19,     8,    19,    19,    13,   183,    13,   135,
       9,    10,    11,    12,    21,    22,    19,    22,    19,    19,
      27,    19,    27,    19,    19,     8,    49,    20,    38,    26,
      20,    20,    26,    74,    21,    20,   162,    79,    45,    38,
      45,    48,    74,    48,   220,    47,    79,    54,    55,   176,
      55,   227,   178,    52,    53,    18,    17,    16,     3,   186,
     187,    17,    74,   239,    56,   241,    73,    54,   258,    76,
      57,    78,   199,    78,   201,   202,   203,    57,    51,    70,
     207,   208,   176,   210,   253,   211,    73,    -1,   215,    76,
      -1,    -1,    -1,    -1,   221,    -1,     3,     4,    -1,     6,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,   235,    -1,
      -1,   237,    19,    20,    -1,    -1,   242,   243,    -1,   246,
      -1,    -1,    -1,    -1,   250,   251,   252,    -1,    -1,    36,
       3,     4,    -1,     6,     7,     8,    -1,     9,    10,    11,
      12,    -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    36,    71,    72,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,     9,    10,    11,    12,    -1,
      52,    53,    -1,    -1,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    71,    72,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    11,    12,    -1,     9,    10,    11,    12,    52,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     9,    10,    11,    12,    38,    34,
      35,    75,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    52,    53,    -1,    -1,    -1,    52,    53,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    -1,     9,    10,    11,    12,    52,    53,    -1,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     9,    10,    11,    12,    -1,    34,    35,
      75,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,     9,    10,    11,    12,    -1,    52,    53,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    -1,     9,    10,    11,    12,    52,    53,    -1,    75,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    53,    -1,    34,    35,    75,
      37,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    53,     9,    10,    11,
      12,    -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,
      -1,    -1,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,     9,    10,    11,    12,    -1,    -1,    -1,
      52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     9,    10,    11,    12,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      46,    -1,    -1,    -1,    -1,    -1,    52,    53,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      46,     9,    10,    11,    12,    -1,    52,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,     9,    10,    11,
      12,    -1,    -1,    -1,    52,    53,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,     9,    10,    11,    12,    -1,    -1,    -1,
      52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    34,    35,
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
      52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,     9,
      10,    11,    12,    -1,    -1,    -1,    52,    53,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,     9,    10,    11,    12,    -1,
      -1,    -1,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,     9,    10,    11,    12,    -1,    -1,    -1,    52,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,     9,    10,    11,
      12,    -1,    -1,    -1,    52,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     9,    10,    11,    12,    -1,    -1,    -1,
      32,    -1,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,     9,    10,    11,    12,    -1,    34,    -1,
      52,    53,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,     9,
      10,    11,    12,    -1,    50,    -1,    52,    53,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,     9,    10,    11,    12,    -1,
      -1,    -1,    52,    53,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,     9,    10,    11,    12,    -1,    -1,    -1,    52,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,     9,    10,    11,
      12,    -1,    -1,    -1,    52,    53,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,
      12,    -1,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    53,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    46,     9,    10,    11,    12,    -1,
      52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,     9,    10,    11,    12,    -1,    14,    -1,    52,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,     9,    10,    11,
      12,    -1,    -1,    -1,    52,    53,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,
      12,    -1,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    53,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    53
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    77,    81,    82,    86,     8,     0,    81,    21,    24,
      54,    73,    76,    87,    19,     8,     8,    13,    22,    27,
      45,    48,    55,    78,    90,    91,     8,     8,     8,    88,
       8,    83,    84,    26,    18,    19,    74,     3,     4,     6,
       7,     8,    19,    36,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    71,    72,    95,    19,
      19,    95,     8,    95,    95,    25,    90,    18,    74,    89,
      32,    26,    26,    20,    32,    28,    29,    30,    31,    96,
      95,    85,    95,    95,    19,    74,    95,    95,    19,    19,
      19,    19,    19,    19,    19,    19,    19,    19,    19,    19,
      19,    19,     9,    10,    11,    12,    14,    34,    35,    37,
      38,    39,    40,    41,    42,    43,    44,    52,    53,    93,
      95,     8,    46,    49,    46,     3,     4,     6,     7,    95,
      26,    88,    96,    96,    26,    86,    83,    20,    32,    75,
      85,    95,    20,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    20,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    86,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    20,    32,    20,    86,    95,
      86,    75,    96,    96,    90,    85,    18,    74,    20,    75,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    32,
      20,    32,    32,    32,    90,    93,    90,    50,    57,    94,
      74,    86,    79,    95,    95,    74,    95,    95,    95,    95,
      15,    16,    17,    92,    47,    95,    95,    15,    56,    95,
      90,    75,    95,    20,    20,    32,    20,    86,    95,    15,
      17,    46,    26,    86,    75,    79,    18,    75,    95,    90,
      14,    86,    86,    90,    90,    95,    20,    17,    90,    90,
      90,    94,    56,    92,    17,    51
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    80,    81,    81,    82,    82,    83,    83,    83,    84,
      85,    85,    85,    86,    86,    87,    87,    87,    87,    87,
      87,    87,    88,    88,    89,    89,    90,    90,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    92,    92,    93,    93,    94,    94,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      96,    96,    96,    96
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     2,     8,    10,     0,     1,     3,     3,
       0,     1,     3,     0,     2,     4,     4,     4,     4,     4,
       4,     5,     1,     3,     3,     6,     1,     2,     6,     9,
       3,     6,     7,    10,     9,     4,     4,     6,    10,     6,
       9,     4,     2,     4,     5,     1,     3,     4,     5,     1,
       1,     1,     1,     1,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     3,     6,     4,     6,     8,     6,     4,     7,
       1,     1,     1,     1
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
  case 2: /* program: Declarations DEBUT statement_list FIN  */
#line 87 "parser.y"
                                          { parsed_program = (yyvsp[-1].statement_list); }
#line 1590 "parser.tab.c"
    break;

  case 4: /* function_decl: FONCTION IDENTIFIANT LPAREN param_list RPAREN Declarations statement_list FINFONCTION  */
#line 92 "parser.y"
                                                                                          {
        (yyval.function) = new_function((yyvsp[-6].var_name), (yyvsp[-4].parameter), TYPE_VOID, (yyvsp[-2].statement_list), (yyvsp[-1].statement_list));
        add_function((yyval.function));
    }
#line 1599 "parser.tab.c"
    break;

  case 5: /* function_decl: FONCTION IDENTIFIANT LPAREN param_list RPAREN COLON type Declarations statement_list FINFONCTION  */
#line 96 "parser.y"
                                                                                                       {
        (yyval.function) = new_function((yyvsp[-8].var_name), (yyvsp[-6].parameter), (yyvsp[-3].type), (yyvsp[-2].statement_list), (yyvsp[-1].statement_list));
        add_function((yyval.function));
    }
#line 1608 "parser.tab.c"
    break;

  case 6: /* param_list: %empty  */
#line 103 "parser.y"
                { (yyval.parameter) = NULL; }
#line 1614 "parser.tab.c"
    break;

  case 7: /* param_list: param  */
#line 104 "parser.y"
            { (yyval.parameter) = (yyvsp[0].parameter); }
#line 1620 "parser.tab.c"
    break;

  case 8: /* param_list: param COMMA param_list  */
#line 105 "parser.y"
                             { (yyval.parameter) = (yyvsp[-2].parameter); (yyval.parameter)->next = (yyvsp[0].parameter); }
#line 1626 "parser.tab.c"
    break;

  case 9: /* param: IDENTIFIANT COLON type  */
#line 109 "parser.y"
                           { (yyval.parameter) = new_parameter((yyvsp[-2].var_name), (yyvsp[0].type), NULL); }
#line 1632 "parser.tab.c"
    break;

  case 10: /* args_list: %empty  */
#line 113 "parser.y"
                { (yyval.expression_list) = NULL; }
#line 1638 "parser.tab.c"
    break;

  case 11: /* args_list: expression  */
#line 114 "parser.y"
                 { (yyval.expression_list) = new_expression_list((yyvsp[0].expression), NULL); }
#line 1644 "parser.tab.c"
    break;

  case 12: /* args_list: expression COMMA args_list  */
#line 115 "parser.y"
                                 { (yyval.expression_list) = new_expression_list((yyvsp[-2].expression), (yyvsp[0].expression_list)); }
#line 1650 "parser.tab.c"
    break;

  case 13: /* Declarations: %empty  */
#line 119 "parser.y"
              { (yyval.statement_list) = NULL; }
#line 1656 "parser.tab.c"
    break;

  case 14: /* Declarations: Declarations Declaration  */
#line 120 "parser.y"
                               { 
        if ((yyvsp[0].statement) != NULL) {
            (yyval.statement_list) = new_statement_list((yyvsp[0].statement), (yyvsp[-1].statement_list));
        } else {
            (yyval.statement_list) = (yyvsp[-1].statement_list);
        }
    }
#line 1668 "parser.tab.c"
    break;

  case 15: /* Declaration: VARIABLE_KWRD IDENTIFIANT COLON type  */
#line 130 "parser.y"
                                         { 
        Statement *stmt = malloc(sizeof(Statement));
        stmt->type = VAR_DECL;
        stmt->data.var_decl.name = (yyvsp[-2].var_name);
        stmt->data.var_decl.type = (yyvsp[0].type);
        add_symbol((yyvsp[-2].var_name), (yyvsp[0].type), false);
        (yyval.statement) = stmt;
    }
#line 1681 "parser.tab.c"
    break;

  case 16: /* Declaration: VARIABLES identifier_list COLON type  */
#line 138 "parser.y"
                                           { 
        add_multiple_symbols((yyvsp[-2].identifier_list), (yyvsp[0].type)); 
        (yyval.statement) = NULL; 
    }
#line 1690 "parser.tab.c"
    break;

  case 17: /* Declaration: CONSTANT IDENTIFIANT EQUALS ENTIER_VAL  */
#line 142 "parser.y"
                                             { 
        add_symbol((yyvsp[-2].var_name), TYPE_ENTIER, true); 
        set_symbol_value((yyvsp[-2].var_name), new_integer((yyvsp[0].int_value))); 
        (yyval.statement) = NULL; 
    }
#line 1700 "parser.tab.c"
    break;

  case 18: /* Declaration: CONSTANT IDENTIFIANT EQUALS DECIMAL_VAL  */
#line 147 "parser.y"
                                              { 
        add_symbol((yyvsp[-2].var_name), TYPE_DECIMAL, true); 
        set_symbol_value((yyvsp[-2].var_name), new_decimal((yyvsp[0].double_value))); 
        (yyval.statement) = NULL; 
    }
#line 1710 "parser.tab.c"
    break;

  case 19: /* Declaration: CONSTANT IDENTIFIANT EQUALS STRING_VAL  */
#line 152 "parser.y"
                                             { 
        add_symbol((yyvsp[-2].var_name), TYPE_CHAINE, true); 
        set_symbol_value((yyvsp[-2].var_name), new_string((yyvsp[0].string_value))); 
        (yyval.statement) = NULL; 
    }
#line 1720 "parser.tab.c"
    break;

  case 20: /* Declaration: CONSTANT IDENTIFIANT EQUALS LOGIQUE_VAL  */
#line 157 "parser.y"
                                              { 
        add_symbol((yyvsp[-2].var_name), TYPE_LOGIQUE, true); 
        set_symbol_value((yyvsp[-2].var_name), new_boolean((yyvsp[0].bval))); 
        (yyval.statement) = NULL; 
    }
#line 1730 "parser.tab.c"
    break;

  case 21: /* Declaration: TABLEAU IDENTIFIANT array_dimensions COLON type  */
#line 162 "parser.y"
                                                      {
        add_array_symbol((yyvsp[-3].var_name), (yyvsp[0].type), (yyvsp[-2].dims));
        (yyval.statement) = NULL;
    }
#line 1739 "parser.tab.c"
    break;

  case 22: /* identifier_list: IDENTIFIANT  */
#line 169 "parser.y"
                { (yyval.identifier_list) = new_identifier_list((yyvsp[0].var_name), NULL); }
#line 1745 "parser.tab.c"
    break;

  case 23: /* identifier_list: IDENTIFIANT COMMA identifier_list  */
#line 170 "parser.y"
                                        { (yyval.identifier_list) = new_identifier_list((yyvsp[-2].var_name), (yyvsp[0].identifier_list)); }
#line 1751 "parser.tab.c"
    break;

  case 24: /* array_dimensions: LBRACKET expression RBRACKET  */
#line 174 "parser.y"
                                 {
        ArrayDimensions dims;
        Expression *size = evaluate_expression((yyvsp[-1].expression));
        dims.sizes[0] = size->data.int_value;
        dims.num_dimensions = 1;
        free(size);
        (yyval.dims) = dims;
    }
#line 1764 "parser.tab.c"
    break;

  case 25: /* array_dimensions: LBRACKET expression RBRACKET LBRACKET expression RBRACKET  */
#line 182 "parser.y"
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
#line 1780 "parser.tab.c"
    break;

  case 26: /* statement_list: statement  */
#line 196 "parser.y"
              { (yyval.statement_list) = new_statement_list((yyvsp[0].statement), NULL); }
#line 1786 "parser.tab.c"
    break;

  case 27: /* statement_list: statement statement_list  */
#line 197 "parser.y"
                               { (yyval.statement_list) = new_statement_list((yyvsp[-1].statement), (yyvsp[0].statement_list)); }
#line 1792 "parser.tab.c"
    break;

  case 28: /* statement: IDENTIFIANT LBRACKET expression RBRACKET EQUALS expression  */
#line 201 "parser.y"
                                                               { 
        (yyval.statement) = new_array_assign((yyvsp[-5].var_name), (yyvsp[-3].expression), NULL, (yyvsp[0].expression)); 
        free((yyvsp[-5].var_name));
    }
#line 1801 "parser.tab.c"
    break;

  case 29: /* statement: IDENTIFIANT LBRACKET expression RBRACKET LBRACKET expression RBRACKET EQUALS expression  */
#line 205 "parser.y"
                                                                                              { 
        (yyval.statement) = new_array_assign((yyvsp[-8].var_name), (yyvsp[-6].expression), (yyvsp[-3].expression), (yyvsp[0].expression)); 
        free((yyvsp[-8].var_name));
    }
#line 1810 "parser.tab.c"
    break;

  case 30: /* statement: IDENTIFIANT EQUALS expression  */
#line 209 "parser.y"
                                    { (yyval.statement) = new_assign((yyvsp[-2].var_name), (yyvsp[0].expression)); }
#line 1816 "parser.tab.c"
    break;

  case 31: /* statement: SI expression ALORS Declarations statement_list FINSI  */
#line 210 "parser.y"
                                                            { (yyval.statement) = new_if_elif((yyvsp[-4].expression), (yyvsp[-1].statement_list), NULL, NULL); }
#line 1822 "parser.tab.c"
    break;

  case 32: /* statement: SI expression ALORS Declarations statement_list elif_list FINSI  */
#line 211 "parser.y"
                                                                      { (yyval.statement) = new_if_elif((yyvsp[-5].expression), (yyvsp[-2].statement_list), (yyvsp[-1].elseif_list), NULL); }
#line 1828 "parser.tab.c"
    break;

  case 33: /* statement: SI expression ALORS Declarations statement_list elif_list SINON Declarations statement_list FINSI  */
#line 212 "parser.y"
                                                                                                        { (yyval.statement) = new_if_elif((yyvsp[-8].expression), (yyvsp[-5].statement_list), (yyvsp[-4].elseif_list), (yyvsp[-1].statement_list)); }
#line 1834 "parser.tab.c"
    break;

  case 34: /* statement: SI expression ALORS Declarations statement_list SINON Declarations statement_list FINSI  */
#line 213 "parser.y"
                                                                                              { (yyval.statement) = new_if_elif((yyvsp[-7].expression), (yyvsp[-4].statement_list), NULL, (yyvsp[-1].statement_list)); }
#line 1840 "parser.tab.c"
    break;

  case 35: /* statement: ECRIRE LPAREN expression_list RPAREN  */
#line 214 "parser.y"
                                           { (yyval.statement) = new_print((yyvsp[-1].expression_list)); }
#line 1846 "parser.tab.c"
    break;

  case 36: /* statement: LIRE LPAREN IDENTIFIANT RPAREN  */
#line 215 "parser.y"
                                     { (yyval.statement) = new_read((yyvsp[-1].var_name)); }
#line 1852 "parser.tab.c"
    break;

  case 37: /* statement: TANTQUE expression FAIRE Declarations statement_list FINTANTQUE  */
#line 216 "parser.y"
                                                                      { (yyval.statement) = new_while((yyvsp[-4].expression), (yyvsp[-1].statement_list)); }
#line 1858 "parser.tab.c"
    break;

  case 38: /* statement: POUR IDENTIFIANT DE expression A expression FAIRE Declarations statement_list FINPOUR  */
#line 217 "parser.y"
                                                                                            { (yyval.statement) = new_for((yyvsp[-8].var_name), (yyvsp[-6].expression), (yyvsp[-4].expression), (yyvsp[-1].statement_list)); }
#line 1864 "parser.tab.c"
    break;

  case 39: /* statement: SELON expression FAIRE Declarations case_list FINSELON  */
#line 218 "parser.y"
                                                             { (yyval.statement) = new_switch((yyvsp[-4].expression), (yyvsp[-1].case_list), NULL); }
#line 1870 "parser.tab.c"
    break;

  case 40: /* statement: SELON expression FAIRE Declarations case_list SINON Declarations statement_list FINSELON  */
#line 219 "parser.y"
                                                                                               { (yyval.statement) = new_switch((yyvsp[-7].expression), (yyvsp[-4].case_list), (yyvsp[-1].statement_list)); }
#line 1876 "parser.tab.c"
    break;

  case 41: /* statement: IDENTIFIANT LPAREN args_list RPAREN  */
#line 220 "parser.y"
                                          { (yyval.statement) = new_function_call((yyvsp[-3].var_name), (yyvsp[-1].expression_list)); }
#line 1882 "parser.tab.c"
    break;

  case 42: /* statement: RETOURNER expression  */
#line 221 "parser.y"
                           { (yyval.statement) = new_return((yyvsp[0].expression)); }
#line 1888 "parser.tab.c"
    break;

  case 43: /* elif_list: SINONSI expression ALORS statement_list  */
#line 226 "parser.y"
        { (yyval.elseif_list) = new_elif_list((yyvsp[-2].expression), (yyvsp[0].statement_list), NULL); }
#line 1894 "parser.tab.c"
    break;

  case 44: /* elif_list: SINONSI expression ALORS statement_list elif_list  */
#line 228 "parser.y"
        { (yyval.elseif_list) = new_elif_list((yyvsp[-3].expression), (yyvsp[-1].statement_list), (yyvsp[0].elseif_list)); }
#line 1900 "parser.tab.c"
    break;

  case 45: /* expression_list: expression  */
#line 232 "parser.y"
               { (yyval.expression_list) = new_expression_list((yyvsp[0].expression), NULL); }
#line 1906 "parser.tab.c"
    break;

  case 46: /* expression_list: expression COMMA expression_list  */
#line 233 "parser.y"
                                       { (yyval.expression_list) = new_expression_list((yyvsp[-2].expression), (yyvsp[0].expression_list)); }
#line 1912 "parser.tab.c"
    break;

  case 47: /* case_list: CAS expression COLON statement_list  */
#line 237 "parser.y"
                                        { (yyval.case_list) = new_case_list((yyvsp[-2].expression), (yyvsp[0].statement_list), NULL); }
#line 1918 "parser.tab.c"
    break;

  case 48: /* case_list: CAS expression COLON statement_list case_list  */
#line 238 "parser.y"
                                                    { (yyval.case_list) = new_case_list((yyvsp[-3].expression), (yyvsp[-1].statement_list), (yyvsp[0].case_list)); }
#line 1924 "parser.tab.c"
    break;

  case 49: /* expression: ENTIER_VAL  */
#line 242 "parser.y"
               { (yyval.expression) = new_integer((yyvsp[0].int_value)); }
#line 1930 "parser.tab.c"
    break;

  case 50: /* expression: DECIMAL_VAL  */
#line 243 "parser.y"
                  { (yyval.expression) = new_decimal((yyvsp[0].double_value)); }
#line 1936 "parser.tab.c"
    break;

  case 51: /* expression: STRING_VAL  */
#line 244 "parser.y"
                 { (yyval.expression) = new_string((yyvsp[0].string_value)); }
#line 1942 "parser.tab.c"
    break;

  case 52: /* expression: LOGIQUE_VAL  */
#line 245 "parser.y"
                  { (yyval.expression) = new_boolean((yyvsp[0].bval)); }
#line 1948 "parser.tab.c"
    break;

  case 53: /* expression: IDENTIFIANT  */
#line 246 "parser.y"
                  { (yyval.expression) = new_variable((yyvsp[0].var_name)); }
#line 1954 "parser.tab.c"
    break;

  case 54: /* expression: IDENTIFIANT LPAREN args_list RPAREN  */
#line 247 "parser.y"
                                          { 
        //Statement *call = new_function_call($1, $3);
        (yyval.expression) = new_function_expression((yyvsp[-3].var_name), (yyvsp[-1].expression_list));
    }
#line 1963 "parser.tab.c"
    break;

  case 55: /* expression: expression PLUS expression  */
#line 251 "parser.y"
                                 { (yyval.expression) = new_binary_op('+', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1969 "parser.tab.c"
    break;

  case 56: /* expression: expression MINUS expression  */
#line 252 "parser.y"
                                  { (yyval.expression) = new_binary_op('-', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1975 "parser.tab.c"
    break;

  case 57: /* expression: expression TIMES expression  */
#line 253 "parser.y"
                                  { (yyval.expression) = new_binary_op('*', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1981 "parser.tab.c"
    break;

  case 58: /* expression: expression DIVIDE expression  */
#line 254 "parser.y"
                                   { (yyval.expression) = new_binary_op('/', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1987 "parser.tab.c"
    break;

  case 59: /* expression: expression AND expression  */
#line 255 "parser.y"
                                { (yyval.expression) = new_binary_op('&', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1993 "parser.tab.c"
    break;

  case 60: /* expression: expression CONCAT expression  */
#line 256 "parser.y"
                                   { (yyval.expression) = new_binary_op('C', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1999 "parser.tab.c"
    break;

  case 61: /* expression: expression OR expression  */
#line 257 "parser.y"
                               { (yyval.expression) = new_binary_op('|', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2005 "parser.tab.c"
    break;

  case 62: /* expression: expression XOR expression  */
#line 258 "parser.y"
                                { (yyval.expression) = new_binary_op('^', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2011 "parser.tab.c"
    break;

  case 63: /* expression: expression POWER expression  */
#line 259 "parser.y"
                                  { (yyval.expression) = new_binary_op('P', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2017 "parser.tab.c"
    break;

  case 64: /* expression: expression MODULO expression  */
#line 260 "parser.y"
                                   { (yyval.expression) = new_binary_op('M', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2023 "parser.tab.c"
    break;

  case 65: /* expression: NOT expression  */
#line 261 "parser.y"
                     { (yyval.expression) = new_unary_op('!', (yyvsp[0].expression)); }
#line 2029 "parser.tab.c"
    break;

  case 66: /* expression: expression LT expression  */
#line 262 "parser.y"
                               { (yyval.expression) = new_binary_op('<', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2035 "parser.tab.c"
    break;

  case 67: /* expression: expression GT expression  */
#line 263 "parser.y"
                               { (yyval.expression) = new_binary_op('>', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2041 "parser.tab.c"
    break;

  case 68: /* expression: expression LE expression  */
#line 264 "parser.y"
                               { (yyval.expression) = new_binary_op('L', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2047 "parser.tab.c"
    break;

  case 69: /* expression: expression GE expression  */
#line 265 "parser.y"
                               { (yyval.expression) = new_binary_op('G', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2053 "parser.tab.c"
    break;

  case 70: /* expression: expression EQ expression  */
#line 266 "parser.y"
                               { (yyval.expression) = new_binary_op('=', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2059 "parser.tab.c"
    break;

  case 71: /* expression: expression NE expression  */
#line 267 "parser.y"
                               { (yyval.expression) = new_binary_op('!', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2065 "parser.tab.c"
    break;

  case 72: /* expression: LPAREN expression RPAREN  */
#line 268 "parser.y"
                               { (yyval.expression) = (yyvsp[-1].expression); }
#line 2071 "parser.tab.c"
    break;

  case 73: /* expression: SQUARE_ROOT LPAREN expression RPAREN  */
#line 269 "parser.y"
                                           { (yyval.expression) = new_unary_op('R', (yyvsp[-1].expression)); }
#line 2077 "parser.tab.c"
    break;

  case 74: /* expression: SINE LPAREN expression RPAREN  */
#line 270 "parser.y"
                                    { (yyval.expression) = new_unary_op('S', (yyvsp[-1].expression)); }
#line 2083 "parser.tab.c"
    break;

  case 75: /* expression: COSINE LPAREN expression RPAREN  */
#line 271 "parser.y"
                                      { (yyval.expression) = new_unary_op('C', (yyvsp[-1].expression)); }
#line 2089 "parser.tab.c"
    break;

  case 76: /* expression: TANGENT LPAREN expression RPAREN  */
#line 272 "parser.y"
                                       { (yyval.expression) = new_unary_op('T', (yyvsp[-1].expression)); }
#line 2095 "parser.tab.c"
    break;

  case 77: /* expression: LOG LPAREN expression RPAREN  */
#line 273 "parser.y"
                                   {(yyval.expression) = new_unary_op('L', (yyvsp[-1].expression)); }
#line 2101 "parser.tab.c"
    break;

  case 78: /* expression: LOG10 LPAREN expression RPAREN  */
#line 274 "parser.y"
                                     { (yyval.expression) = new_unary_op('l', (yyvsp[-1].expression));}
#line 2107 "parser.tab.c"
    break;

  case 79: /* expression: ROUND LPAREN expression RPAREN  */
#line 275 "parser.y"
                                     { (yyval.expression) = new_unary_op('D', (yyvsp[-1].expression));}
#line 2113 "parser.tab.c"
    break;

  case 80: /* expression: ABS LPAREN expression RPAREN  */
#line 276 "parser.y"
                                   { (yyval.expression) = new_unary_op('A', (yyvsp[-1].expression));}
#line 2119 "parser.tab.c"
    break;

  case 81: /* expression: INT LPAREN expression RPAREN  */
#line 277 "parser.y"
                                   { (yyval.expression) = new_unary_op('E', (yyvsp[-1].expression));}
#line 2125 "parser.tab.c"
    break;

  case 82: /* expression: RANDOM LPAREN RPAREN  */
#line 278 "parser.y"
                           {
        srand(time(0));
        double random_number = (double)rand() / (RAND_MAX + 1.0);
        (yyval.expression) = new_decimal(random_number);
    }
#line 2135 "parser.tab.c"
    break;

  case 83: /* expression: RANDOM LPAREN expression COMMA expression RPAREN  */
#line 283 "parser.y"
                                                       { (yyval.expression) = new_binary_op('A', (yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 2141 "parser.tab.c"
    break;

  case 84: /* expression: LENGTH LPAREN expression RPAREN  */
#line 284 "parser.y"
                                      { (yyval.expression) = new_unary_op('H', (yyvsp[-1].expression)); }
#line 2147 "parser.tab.c"
    break;

  case 85: /* expression: COMPARE LPAREN expression COMMA expression RPAREN  */
#line 285 "parser.y"
                                                        { (yyval.expression) = new_binary_op('p', (yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 2153 "parser.tab.c"
    break;

  case 86: /* expression: COPY LPAREN expression COMMA expression COMMA expression RPAREN  */
#line 286 "parser.y"
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
#line 2182 "parser.tab.c"
    break;

  case 87: /* expression: SEARCH LPAREN expression COMMA expression RPAREN  */
#line 310 "parser.y"
                                                       { (yyval.expression) = new_binary_op('r', (yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 2188 "parser.tab.c"
    break;

  case 88: /* expression: IDENTIFIANT LBRACKET expression RBRACKET  */
#line 311 "parser.y"
                                               {
        (yyval.expression) = new_array_access((yyvsp[-3].var_name), (yyvsp[-1].expression), NULL);
    }
#line 2196 "parser.tab.c"
    break;

  case 89: /* expression: IDENTIFIANT LBRACKET expression RBRACKET LBRACKET expression RBRACKET  */
#line 314 "parser.y"
                                                                            {
        (yyval.expression) = new_array_access((yyvsp[-6].var_name), (yyvsp[-4].expression), (yyvsp[-1].expression));
    }
#line 2204 "parser.tab.c"
    break;

  case 90: /* type: ENTIER_KWRD  */
#line 320 "parser.y"
                { (yyval.type) = TYPE_ENTIER; }
#line 2210 "parser.tab.c"
    break;

  case 91: /* type: DECIMAL_KWRD  */
#line 321 "parser.y"
                   { (yyval.type) = TYPE_DECIMAL; }
#line 2216 "parser.tab.c"
    break;

  case 92: /* type: CHAINE_KWRD  */
#line 322 "parser.y"
                  { (yyval.type) = TYPE_CHAINE; }
#line 2222 "parser.tab.c"
    break;

  case 93: /* type: LOGIQUE_KWRD  */
#line 323 "parser.y"
                   { (yyval.type) = TYPE_LOGIQUE; }
#line 2228 "parser.tab.c"
    break;


#line 2232 "parser.tab.c"

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

#line 326 "parser.y"


void yyerror(const char *s) {
    if (strcmp(s, "syntax error") == 0) {
        fprintf(stderr, "Erreur ligne %d: Syntaxe incorrecte\n", yylineno);
    }
    else {
        fprintf(stderr, "Erreur ligne %d: %s\n", yylineno, s);
    }
}
