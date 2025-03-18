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
#line 8 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "ast.h"
#include "module.h"

void yyerror(const char *s);
int yylex(void);

StatementList *parsed_program = NULL;
Module *current_module = NULL;


#line 87 "parser.tab.c"

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
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ENTIER_VAL = 258,
    DECIMAL_VAL = 259,
    CHAINE = 260,
    STRING_VAL = 261,
    LOGIQUE_VAL = 262,
    IDENTIFIANT = 263,
    PLUS = 264,
    MINUS = 265,
    TIMES = 266,
    DIVIDE = 267,
    SI = 268,
    ALORS = 269,
    SINON = 270,
    SINONSI = 271,
    FINSI = 272,
    EQUALS = 273,
    LPAREN = 274,
    RPAREN = 275,
    VARIABLE_KWRD = 276,
    ECRIRE = 277,
    ALGORITHME = 278,
    DEBUT = 279,
    FIN = 280,
    COLON = 281,
    LIRE = 282,
    ENTIER_KWRD = 283,
    DECIMAL_KWRD = 284,
    LOGIQUE_KWRD = 285,
    CHAINE_KWRD = 286,
    COMMA = 287,
    COMMENT = 288,
    AND = 289,
    OR = 290,
    NOT = 291,
    XOR = 292,
    CONCAT = 293,
    LT = 294,
    GT = 295,
    LE = 296,
    GE = 297,
    EQ = 298,
    NE = 299,
    TANTQUE = 300,
    FAIRE = 301,
    FINTANTQUE = 302,
    POUR = 303,
    DE = 304,
    A = 305,
    FINPOUR = 306,
    POWER = 307,
    MODULO = 308,
    CONSTANT = 309,
    SELON = 310,
    FINSELON = 311,
    CAS = 312,
    SQUARE_ROOT = 313,
    SINE = 314,
    COSINE = 315,
    TANGENT = 316,
    LOG = 317,
    LOG10 = 318,
    ROUND = 319,
    ABS = 320,
    INT = 321,
    RANDOM = 322,
    LENGTH = 323,
    COMPARE = 324,
    CONCATENATE = 325,
    COPY = 326,
    SEARCH = 327,
    TABLEAU = 328,
    LBRACKET = 329,
    RBRACKET = 330,
    VARIABLES = 331,
    FONCTION = 332,
    RETOURNER = 333,
    FINFONCTION = 334,
    TYPE_KWRD = 335,
    MODULE = 336,
    FINMODULE = 337,
    IMPORTER = 338,
    DEPUIS = 339,
    DOT = 340
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "parser.y"

    int int_value;
    double double_value;
    char *string_value;
    char *var_name;
    bool bval;
    SymbolType type;
    Expression *expression;
    Statement *statement;
    StatementList *statement_list;
    CaseList *case_list;
    ExpressionList *expression_list;
    ArrayDimensions dims;
    ElseIfList *elseif_list;
    IdentifierList *identifier_list;
    Parameter *parameter;
    Function *function;
    struct Module *module;
    struct Import *import;
    char **function_names;

#line 247 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */



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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1555

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  296

#define YYUNDEFTOK  2
#define YYMAXUTOK   340


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    95,    95,    96,    97,    98,   102,   110,   121,   122,
     123,   127,   131,   132,   133,   137,   138,   148,   156,   160,
     165,   170,   175,   180,   187,   188,   192,   200,   214,   215,
     219,   223,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   243,   245,   250,   251,   255,
     256,   260,   261,   262,   263,   264,   265,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   301,   302,   303,   304,   326,
     327,   330,   333,   336,   346,   354,   355,   356,   357,   361,
     378,   379,   383,   387,   394,   399
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ENTIER_VAL", "DECIMAL_VAL", "CHAINE",
  "STRING_VAL", "LOGIQUE_VAL", "IDENTIFIANT", "PLUS", "MINUS", "TIMES",
  "DIVIDE", "SI", "ALORS", "SINON", "SINONSI", "FINSI", "EQUALS", "LPAREN",
  "RPAREN", "VARIABLE_KWRD", "ECRIRE", "ALGORITHME", "DEBUT", "FIN",
  "COLON", "LIRE", "ENTIER_KWRD", "DECIMAL_KWRD", "LOGIQUE_KWRD",
  "CHAINE_KWRD", "COMMA", "COMMENT", "AND", "OR", "NOT", "XOR", "CONCAT",
  "LT", "GT", "LE", "GE", "EQ", "NE", "TANTQUE", "FAIRE", "FINTANTQUE",
  "POUR", "DE", "A", "FINPOUR", "POWER", "MODULO", "CONSTANT", "SELON",
  "FINSELON", "CAS", "SQUARE_ROOT", "SINE", "COSINE", "TANGENT", "LOG",
  "LOG10", "ROUND", "ABS", "INT", "RANDOM", "LENGTH", "COMPARE",
  "CONCATENATE", "COPY", "SEARCH", "TABLEAU", "LBRACKET", "RBRACKET",
  "VARIABLES", "FONCTION", "RETOURNER", "FINFONCTION", "TYPE_KWRD",
  "MODULE", "FINMODULE", "IMPORTER", "DEPUIS", "DOT", "$accept", "program",
  "function_decl", "param_list", "param", "args_list", "Declarations",
  "Declaration", "identifier_list", "array_dimensions", "statement_list",
  "statement", "elif_list", "expression_list", "case_list", "expression",
  "type", "module_decl", "module_content", "import_stmt",
  "function_name_list", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340
};
# endif

#define YYPACT_NINF (-93)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      46,    24,    26,    39,    41,    30,    46,     0,   -93,   -93,
       3,   -22,   -93,   -27,   -93,   -93,    50,   112,    76,   110,
     118,   -93,   107,   124,   -22,   -11,   125,    78,     1,   251,
     117,   119,   251,   137,   251,   251,    40,   112,   122,    72,
     115,   123,   112,   128,   131,   116,   -93,   -93,   -93,   126,
       9,   251,   251,   251,   -93,   -93,   -93,   -93,   -17,   251,
     251,   136,   140,   143,   144,   145,   146,   147,   152,   154,
     155,   156,   157,   158,   160,   162,   480,   251,   148,   500,
     133,   538,  1502,   -93,   -93,    57,   251,   161,   118,     9,
     166,     9,   167,   124,   178,   -93,   -93,   -93,   -93,   -93,
    1502,   172,   576,   295,   251,   251,   186,   612,   159,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   214,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   -93,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   175,   648,   176,   -93,   251,   -93,   -93,   -93,   -93,
     -93,   315,     9,   -93,   -93,   -93,   -93,     9,    -4,   -93,
     -93,   -93,   251,   -15,   179,   354,   182,   -93,   684,   720,
     756,   792,   828,   864,   900,   936,   972,   -93,  1008,  1044,
    1080,  1116,  1152,  1188,    14,    14,   -10,   -10,    -4,   554,
     517,   517,  1502,   132,   132,   132,   132,  1388,  1388,   159,
      -7,   -93,   251,   -93,    -4,  1208,    96,   134,   -93,   -93,
     130,   -93,   251,   251,   -93,   139,   251,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   251,   -93,   251,   251,
     251,   -93,    63,   -93,   151,   251,   251,    -8,   251,    -4,
     -93,  1502,   374,   251,   187,  1244,  1280,  1316,  1352,   -93,
     251,   -93,    -2,   -93,  1372,  1410,   -93,   -93,   413,   149,
     192,   433,   -93,   -93,   -93,   251,   -93,    -4,  1446,   -93,
     -93,   -93,   112,    -4,   -93,   -93,   251,   -93,  1482,   198,
     112,    -4,    -4,   168,   171,  1502,   -93,   -93,   200,   206,
     173,   -93,   -93,   -93,   -93,   -93
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      15,     0,     0,     0,     0,     0,    15,     0,     2,    15,
       0,     0,   102,     0,     1,     5,     0,     0,     0,     0,
       0,    16,     0,     8,   100,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    28,     0,     0,
      24,     0,     0,     0,     0,     9,   101,    99,   104,   103,
       0,     0,    12,     0,    51,    52,    53,    54,    55,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    44,     4,    29,     0,     0,     0,     0,     0,
       0,     0,    15,     8,     0,    95,    96,    98,    97,    17,
      32,     0,    13,     0,    12,     0,     0,     0,    67,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    47,     0,    15,     0,    15,    19,    20,    21,
      22,     0,     0,    25,    18,     3,    11,     0,     0,    10,
     105,    43,    12,     0,     0,     0,    94,    74,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,     0,     0,
       0,     0,     0,     0,    57,    58,    59,    60,     0,    61,
      63,    64,    62,    68,    69,    70,    71,    72,    73,    65,
      66,    37,     0,    38,     0,     0,     0,    26,    23,    15,
       0,    14,     0,     0,    56,    90,    12,    75,    76,    77,
      78,    79,    80,    81,    82,    83,     0,    86,     0,     0,
       0,    92,     0,    48,     0,     0,     0,     0,     0,     0,
       7,    30,     0,     0,     0,     0,     0,     0,     0,    15,
       0,    33,     0,    39,     0,     0,    15,    41,     0,     0,
       0,     0,    93,    85,    87,     0,    89,     0,     0,    15,
      34,    15,     0,     0,    27,     6,     0,    91,     0,     0,
       0,     0,     0,    49,     0,    31,    88,    36,    45,     0,
       0,    50,    42,    46,    35,    40
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -93,   223,    22,   142,   -93,   -92,    -9,   -93,   150,   -93,
     -36,   -93,   -58,    37,   -51,   -24,   -75,   -93,   218,   -93,
     -93
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,    44,    45,   101,     7,    21,    41,    87,
      36,    37,   252,   141,   237,   102,    99,     8,    25,     9,
      49
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      22,    84,   104,   212,    28,    76,    90,   256,    79,    29,
      81,    82,   164,   269,   154,   270,   156,    16,    30,    51,
      52,    16,    23,    31,    17,   126,   127,   100,   132,   103,
      14,   132,    10,    24,    11,   107,   108,    95,    96,    97,
      98,    32,   139,   140,    33,   139,    24,    12,   257,    13,
      18,    34,   132,   142,    18,     1,    26,   105,    27,   213,
     147,   148,   151,   149,   150,    83,   139,   140,   106,    19,
     211,    47,    20,    19,    35,    53,    20,   208,   249,   250,
     251,   165,   209,   158,    38,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    50,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    16,    39,   188,
      28,   205,   210,     1,   244,    29,    40,     2,    16,     3,
       4,    42,    43,    48,    30,   204,    77,   206,    78,    31,
      85,   124,   125,   126,   127,    80,    86,    88,    93,    89,
      18,    92,   232,   236,    91,   109,   143,    32,    94,   110,
      33,    18,   111,   112,   113,   114,   115,    34,   234,    19,
     132,   116,    20,   117,   118,   119,   120,   121,   142,   122,
      19,   123,   145,    20,   139,   140,   160,   152,   241,   242,
      35,   155,   161,   157,   166,   201,   203,   132,   253,   214,
     239,   216,   245,   259,   246,   247,   248,   262,   238,   240,
     276,   254,   255,   243,   258,   287,   250,    54,    55,   261,
      56,    57,    58,   294,   295,   236,   268,   292,   275,    15,
     293,   279,   291,    59,   177,   159,   283,   284,   153,   233,
     267,   278,    46,     0,   288,   289,   290,   273,     0,     0,
      60,     0,   285,     0,    54,    55,     0,    56,    57,    58,
     281,     0,   282,     0,     0,     0,     0,     0,     0,     0,
      59,     0,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,     0,    73,    74,    60,     0,     0,
       0,     0,     0,     0,    75,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   124,   125,   126,   127,     0,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,     0,    73,    74,   124,   125,   126,   127,     0,   129,
     130,    75,   131,   132,   133,   134,   135,   136,   137,   138,
       0,     0,     0,     0,     0,     0,     0,   139,   140,   129,
     130,     0,   131,   132,   133,   134,   135,   136,   137,   138,
       0,     0,     0,   124,   125,   126,   127,   139,   140,     0,
     163,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   124,   125,   126,   127,     0,   129,   130,
     207,   131,   132,   133,   134,   135,   136,   137,   138,     0,
       0,     0,     0,     0,     0,     0,   139,   140,   129,   130,
       0,   131,   132,   133,   134,   135,   136,   137,   138,     0,
       0,     0,   124,   125,   126,   127,   139,   140,     0,   215,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   124,   125,   126,   127,     0,   129,   130,   260,
     131,   132,   133,   134,   135,   136,   137,   138,     0,     0,
       0,     0,     0,     0,     0,   139,   140,   129,   130,     0,
     131,   132,   133,   134,   135,   136,   137,   138,     0,     0,
       0,     0,     0,     0,     0,   139,   140,     0,   274,   124,
     125,   126,   127,     0,   128,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   277,   124,
     125,   126,   127,     0,   129,   130,     0,   131,   132,   133,
     134,   135,   136,   137,   138,     0,   124,   125,   126,   127,
       0,     0,   139,   140,   129,   130,     0,   131,   132,   133,
     134,   135,   136,   137,   138,     0,   144,   124,   125,   126,
     127,   129,   139,   140,     0,   132,   133,   134,   135,   136,
     137,   138,     0,   124,   125,   126,   127,     0,     0,   139,
     140,     0,   129,   130,     0,   131,   132,   133,   134,   135,
     136,   137,   138,     0,   146,   124,   125,   126,   127,     0,
     139,   140,   132,   133,   134,   135,   136,   137,   138,     0,
       0,     0,     0,     0,     0,     0,   139,   140,   162,     0,
     129,   130,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   124,   125,   126,   127,     0,     0,     0,   139,   140,
       0,     0,   167,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   129,   130,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   124,   125,   126,
     127,     0,     0,     0,   139,   140,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     202,     0,   129,   130,     0,   131,   132,   133,   134,   135,
     136,   137,   138,   124,   125,   126,   127,     0,     0,     0,
     139,   140,     0,     0,   217,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   129,   130,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   124,
     125,   126,   127,     0,     0,     0,   139,   140,     0,     0,
     218,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   129,   130,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   124,   125,   126,   127,     0,
       0,     0,   139,   140,     0,     0,   219,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     129,   130,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   124,   125,   126,   127,     0,     0,     0,   139,   140,
       0,     0,   220,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   129,   130,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   124,   125,   126,
     127,     0,     0,     0,   139,   140,     0,     0,   221,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   129,   130,     0,   131,   132,   133,   134,   135,
     136,   137,   138,   124,   125,   126,   127,     0,     0,     0,
     139,   140,     0,     0,   222,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   129,   130,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   124,
     125,   126,   127,     0,     0,     0,   139,   140,     0,     0,
     223,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   129,   130,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   124,   125,   126,   127,     0,
       0,     0,   139,   140,     0,     0,   224,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     129,   130,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   124,   125,   126,   127,     0,     0,     0,   139,   140,
       0,     0,   225,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   129,   130,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   124,   125,   126,
     127,     0,     0,     0,   139,   140,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     226,     0,   129,   130,     0,   131,   132,   133,   134,   135,
     136,   137,   138,   124,   125,   126,   127,     0,     0,     0,
     139,   140,     0,     0,   227,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   129,   130,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   124,
     125,   126,   127,     0,     0,     0,   139,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   228,     0,   129,   130,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   124,   125,   126,   127,     0,
       0,     0,   139,   140,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   229,     0,
     129,   130,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   124,   125,   126,   127,     0,     0,     0,   139,   140,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   230,     0,   129,   130,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   124,   125,   126,
     127,     0,     0,     0,   139,   140,     0,     0,   231,     0,
       0,     0,     0,     0,     0,     0,     0,   124,   125,   126,
     127,     0,   129,   130,     0,   131,   132,   133,   134,   135,
     136,   137,   138,     0,     0,     0,     0,     0,     0,     0,
     139,   140,   129,   130,     0,   131,   132,   133,   134,   135,
     136,   137,   138,   124,   125,   126,   127,     0,   235,     0,
     139,   140,     0,     0,   263,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   129,   130,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   124,
     125,   126,   127,     0,     0,     0,   139,   140,     0,     0,
     264,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   129,   130,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   124,   125,   126,   127,     0,
       0,     0,   139,   140,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   265,     0,
     129,   130,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   124,   125,   126,   127,     0,     0,     0,   139,   140,
       0,     0,   266,     0,     0,     0,     0,     0,     0,     0,
       0,   124,   125,   126,   127,     0,   129,   130,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   124,   125,   126,
     127,     0,     0,     0,   139,   140,   129,   130,     0,   131,
     132,   133,   134,   135,   136,   137,   138,     0,   271,   124,
     125,   126,   127,     0,   139,   140,   132,   133,   134,   135,
     136,     0,     0,     0,     0,     0,   272,     0,     0,     0,
     139,   140,     0,     0,   129,   130,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   124,   125,   126,   127,     0,
     280,     0,   139,   140,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     129,   130,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   124,   125,   126,   127,     0,     0,     0,   139,   140,
       0,     0,   286,     0,     0,     0,     0,     0,     0,     0,
       0,   124,   125,   126,   127,     0,   129,   130,     0,   131,
     132,   133,   134,   135,   136,   137,   138,     0,     0,     0,
       0,     0,     0,     0,   139,   140,   129,   130,     0,   131,
     132,   133,   134,   135,   136,   137,   138,     0,     0,     0,
       0,     0,     0,     0,   139,   140
};

static const yytype_int16 yycheck[] =
{
       9,    37,    19,    18,     8,    29,    42,    15,    32,    13,
      34,    35,   104,    15,    89,    17,    91,    21,    22,    18,
      19,    21,    19,    27,    24,    11,    12,    51,    38,    53,
       0,    38,     8,    11,     8,    59,    60,    28,    29,    30,
      31,    45,    52,    53,    48,    52,    24,     8,    56,     8,
      54,    55,    38,    77,    54,    77,    83,    74,     8,    74,
       3,     4,    86,     6,     7,    25,    52,    53,    85,    73,
     162,    82,    76,    73,    78,    74,    76,   152,    15,    16,
      17,   105,   157,    92,     8,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,    26,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,    21,     8,   128,
       8,   145,   158,    77,   216,    13,     8,    81,    21,    83,
      84,    24,     8,     8,    22,   144,    19,   146,    19,    27,
      18,     9,    10,    11,    12,     8,    74,    32,    32,    26,
      54,    20,   188,    57,    26,    19,     8,    45,    32,    19,
      48,    54,    19,    19,    19,    19,    19,    55,   204,    73,
      38,    19,    76,    19,    19,    19,    19,    19,   202,    19,
      73,    19,    49,    76,    52,    53,     8,    26,   212,   213,
      78,    25,    20,    26,     8,    20,    20,    38,    47,    20,
     209,    19,   226,   239,   228,   229,   230,    20,    74,    79,
      18,   235,   236,    74,   238,    17,    16,     3,     4,   243,
       6,     7,     8,    17,    51,    57,   250,    56,    79,     6,
     288,   267,   283,    19,    20,    93,   272,   273,    88,   202,
     249,   265,    24,    -1,   280,   281,   282,   256,    -1,    -1,
      36,    -1,   276,    -1,     3,     4,    -1,     6,     7,     8,
     269,    -1,   271,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     9,    10,    11,    12,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    72,     9,    10,    11,    12,    -1,    34,
      35,    80,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    -1,     9,    10,    11,    12,    52,    53,    -1,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     9,    10,    11,    12,    -1,    34,    35,
      75,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    -1,     9,    10,    11,    12,    52,    53,    -1,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    10,    11,    12,    -1,    34,    35,    75,
      37,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    53,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    53,    -1,    75,     9,
      10,    11,    12,    -1,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,     9,
      10,    11,    12,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,     9,    10,    11,    12,
      -1,    -1,    52,    53,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    46,     9,    10,    11,
      12,    34,    52,    53,    -1,    38,    39,    40,    41,    42,
      43,    44,    -1,     9,    10,    11,    12,    -1,    -1,    52,
      53,    -1,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    46,     9,    10,    11,    12,    -1,
      52,    53,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    32,    -1,
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
      12,    -1,    -1,    -1,    52,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    -1,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,     9,    10,    11,    12,    -1,    -1,    -1,
      52,    53,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,     9,
      10,    11,    12,    -1,    -1,    -1,    52,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,     9,    10,    11,    12,    -1,
      -1,    -1,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,
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
      42,    43,    44,     9,    10,    11,    12,    -1,    50,    -1,
      52,    53,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,     9,
      10,    11,    12,    -1,    -1,    -1,    52,    53,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,     9,    10,    11,    12,    -1,
      -1,    -1,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,     9,    10,    11,    12,    -1,    -1,    -1,    52,    53,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    10,    11,    12,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,     9,    10,    11,
      12,    -1,    -1,    -1,    52,    53,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    46,     9,
      10,    11,    12,    -1,    52,    53,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,
      52,    53,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,     9,    10,    11,    12,    -1,
      14,    -1,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,     9,    10,    11,    12,    -1,    -1,    -1,    52,    53,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    10,    11,    12,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    53,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    53
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    77,    81,    83,    84,    87,    88,    92,   103,   105,
       8,     8,     8,     8,     0,    87,    21,    24,    54,    73,
      76,    93,    92,    19,    88,   104,    83,     8,     8,    13,
      22,    27,    45,    48,    55,    78,    96,    97,     8,     8,
       8,    94,    24,     8,    89,    90,   104,    82,     8,   106,
      26,    18,    19,    74,     3,     4,     6,     7,     8,    19,
      36,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    71,    72,    80,   101,    19,    19,   101,
       8,   101,   101,    25,    96,    18,    74,    95,    32,    26,
      96,    26,    20,    32,    32,    28,    29,    30,    31,   102,
     101,    91,   101,   101,    19,    74,    85,   101,   101,    19,
      19,    19,    19,    19,    19,    19,    19,    19,    19,    19,
      19,    19,    19,    19,     9,    10,    11,    12,    14,    34,
      35,    37,    38,    39,    40,    41,    42,    43,    44,    52,
      53,    99,   101,     8,    46,    49,    46,     3,     4,     6,
       7,   101,    26,    94,   102,    25,   102,    26,    92,    89,
       8,    20,    32,    75,    91,   101,     8,    20,   101,   101,
     101,   101,   101,   101,   101,   101,   101,    20,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,    92,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,    20,    32,    20,    92,   101,    92,    75,   102,   102,
      96,    91,    18,    74,    20,    75,    19,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    32,    20,    32,    32,
      32,    20,    96,    99,    96,    50,    57,   100,    74,    92,
      79,   101,   101,    74,    91,   101,   101,   101,   101,    15,
      16,    17,    98,    47,   101,   101,    15,    56,   101,    96,
      75,   101,    20,    20,    20,    32,    20,    92,   101,    15,
      17,    46,    26,    92,    75,    79,    18,    75,   101,    96,
      14,    92,    92,    96,    96,   101,    20,    17,    96,    96,
      96,   100,    56,    98,    17,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    86,    87,    87,    87,    87,    88,    88,    89,    89,
      89,    90,    91,    91,    91,    92,    92,    93,    93,    93,
      93,    93,    93,    93,    94,    94,    95,    95,    96,    96,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    98,    98,    99,    99,   100,
     100,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   102,   102,   102,   102,   103,
     104,   104,   105,   105,   106,   106
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     5,     4,     2,    10,     8,     0,     1,
       3,     3,     0,     1,     3,     0,     2,     4,     4,     4,
       4,     4,     4,     5,     1,     3,     3,     6,     1,     2,
       6,     9,     3,     6,     7,    10,     9,     4,     4,     6,
      10,     6,     9,     4,     2,     4,     5,     1,     3,     4,
       5,     1,     1,     1,     1,     1,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     3,     6,     4,     6,     8,     6,
       4,     7,     4,     6,     3,     1,     1,     1,     1,     4,
       1,     2,     2,     4,     1,     3
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
#line 96 "parser.y"
                                                        { parsed_program = (yyvsp[-1].statement_list); }
#line 1873 "parser.tab.c"
    break;

  case 4:
#line 97 "parser.y"
                                            { parsed_program = (yyvsp[-1].statement_list); }
#line 1879 "parser.tab.c"
    break;

  case 6:
#line 102 "parser.y"
                                                                                                     {
        (yyval.function) = new_function((yyvsp[-8].var_name), (yyvsp[-6].parameter), (yyvsp[-3].type), (yyvsp[-2].statement_list), (yyvsp[-1].statement_list));
        if (current_module) {
            add_function_to_module(current_module, (yyval.function));
        } else {
            add_function((yyval.function));
        }
    }
#line 1892 "parser.tab.c"
    break;

  case 7:
#line 110 "parser.y"
                                                                                            {
        (yyval.function) = new_function((yyvsp[-6].var_name), (yyvsp[-4].parameter), TYPE_VOID, (yyvsp[-2].statement_list), (yyvsp[-1].statement_list));
        if (current_module) {
            add_function_to_module(current_module, (yyval.function));
        } else {
            add_function((yyval.function));
        }
    }
#line 1905 "parser.tab.c"
    break;

  case 8:
#line 121 "parser.y"
                { (yyval.parameter) = NULL; }
#line 1911 "parser.tab.c"
    break;

  case 9:
#line 122 "parser.y"
            { (yyval.parameter) = (yyvsp[0].parameter); }
#line 1917 "parser.tab.c"
    break;

  case 10:
#line 123 "parser.y"
                             { (yyval.parameter) = (yyvsp[-2].parameter); (yyval.parameter)->next = (yyvsp[0].parameter); }
#line 1923 "parser.tab.c"
    break;

  case 11:
#line 127 "parser.y"
                           { (yyval.parameter) = new_parameter((yyvsp[-2].var_name), (yyvsp[0].type), NULL); }
#line 1929 "parser.tab.c"
    break;

  case 12:
#line 131 "parser.y"
                { (yyval.expression_list) = NULL; }
#line 1935 "parser.tab.c"
    break;

  case 13:
#line 132 "parser.y"
                 { (yyval.expression_list) = new_expression_list((yyvsp[0].expression), NULL); }
#line 1941 "parser.tab.c"
    break;

  case 14:
#line 133 "parser.y"
                                 { (yyval.expression_list) = new_expression_list((yyvsp[-2].expression), (yyvsp[0].expression_list)); }
#line 1947 "parser.tab.c"
    break;

  case 15:
#line 137 "parser.y"
              { (yyval.statement_list) = NULL; }
#line 1953 "parser.tab.c"
    break;

  case 16:
#line 138 "parser.y"
                               { 
        if ((yyvsp[0].statement) != NULL) {
            (yyval.statement_list) = new_statement_list((yyvsp[0].statement), (yyvsp[-1].statement_list));
        } else {
            (yyval.statement_list) = (yyvsp[-1].statement_list);
        }
    }
#line 1965 "parser.tab.c"
    break;

  case 17:
#line 148 "parser.y"
                                         { 
        Statement *stmt = malloc(sizeof(Statement));
        stmt->type = VAR_DECL;
        stmt->data.var_decl.name = (yyvsp[-2].var_name);
        stmt->data.var_decl.type = (yyvsp[0].type);
        add_symbol((yyvsp[-2].var_name), (yyvsp[0].type), false);
        (yyval.statement) = stmt;
    }
#line 1978 "parser.tab.c"
    break;

  case 18:
#line 156 "parser.y"
                                           { 
        add_multiple_symbols((yyvsp[-2].identifier_list), (yyvsp[0].type)); 
        (yyval.statement) = NULL; 
    }
#line 1987 "parser.tab.c"
    break;

  case 19:
#line 160 "parser.y"
                                             { 
        add_symbol((yyvsp[-2].var_name), TYPE_ENTIER, true); 
        set_symbol_value((yyvsp[-2].var_name), new_integer((yyvsp[0].int_value))); 
        (yyval.statement) = NULL; 
    }
#line 1997 "parser.tab.c"
    break;

  case 20:
#line 165 "parser.y"
                                              { 
        add_symbol((yyvsp[-2].var_name), TYPE_DECIMAL, true); 
        set_symbol_value((yyvsp[-2].var_name), new_decimal((yyvsp[0].double_value))); 
        (yyval.statement) = NULL; 
    }
#line 2007 "parser.tab.c"
    break;

  case 21:
#line 170 "parser.y"
                                             { 
        add_symbol((yyvsp[-2].var_name), TYPE_CHAINE, true); 
        set_symbol_value((yyvsp[-2].var_name), new_string((yyvsp[0].string_value))); 
        (yyval.statement) = NULL; 
    }
#line 2017 "parser.tab.c"
    break;

  case 22:
#line 175 "parser.y"
                                              { 
        add_symbol((yyvsp[-2].var_name), TYPE_LOGIQUE, true); 
        set_symbol_value((yyvsp[-2].var_name), new_boolean((yyvsp[0].bval))); 
        (yyval.statement) = NULL; 
    }
#line 2027 "parser.tab.c"
    break;

  case 23:
#line 180 "parser.y"
                                                      {
        add_array_symbol((yyvsp[-3].var_name), (yyvsp[0].type), (yyvsp[-2].dims));
        (yyval.statement) = NULL;
    }
#line 2036 "parser.tab.c"
    break;

  case 24:
#line 187 "parser.y"
                { (yyval.identifier_list) = new_identifier_list((yyvsp[0].var_name), NULL); }
#line 2042 "parser.tab.c"
    break;

  case 25:
#line 188 "parser.y"
                                        { (yyval.identifier_list) = new_identifier_list((yyvsp[-2].var_name), (yyvsp[0].identifier_list)); }
#line 2048 "parser.tab.c"
    break;

  case 26:
#line 192 "parser.y"
                                 {
        ArrayDimensions dims;
        Expression *size = evaluate_expression((yyvsp[-1].expression));
        dims.sizes[0] = size->data.int_value;
        dims.num_dimensions = 1;
        free(size);
        (yyval.dims) = dims;
    }
#line 2061 "parser.tab.c"
    break;

  case 27:
#line 200 "parser.y"
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
#line 2077 "parser.tab.c"
    break;

  case 28:
#line 214 "parser.y"
              { (yyval.statement_list) = new_statement_list((yyvsp[0].statement), NULL); }
#line 2083 "parser.tab.c"
    break;

  case 29:
#line 215 "parser.y"
                               { (yyval.statement_list) = new_statement_list((yyvsp[-1].statement), (yyvsp[0].statement_list)); }
#line 2089 "parser.tab.c"
    break;

  case 30:
#line 219 "parser.y"
                                                               { 
        (yyval.statement) = new_array_assign((yyvsp[-5].var_name), (yyvsp[-3].expression), NULL, (yyvsp[0].expression)); 
        free((yyvsp[-5].var_name));
    }
#line 2098 "parser.tab.c"
    break;

  case 31:
#line 223 "parser.y"
                                                                                              { 
        (yyval.statement) = new_array_assign((yyvsp[-8].var_name), (yyvsp[-6].expression), (yyvsp[-3].expression), (yyvsp[0].expression)); 
        free((yyvsp[-8].var_name));
    }
#line 2107 "parser.tab.c"
    break;

  case 32:
#line 227 "parser.y"
                                    { (yyval.statement) = new_assign((yyvsp[-2].var_name), (yyvsp[0].expression)); }
#line 2113 "parser.tab.c"
    break;

  case 33:
#line 228 "parser.y"
                                                            { (yyval.statement) = new_if_elif((yyvsp[-4].expression), (yyvsp[-1].statement_list), NULL, NULL); }
#line 2119 "parser.tab.c"
    break;

  case 34:
#line 229 "parser.y"
                                                                      { (yyval.statement) = new_if_elif((yyvsp[-5].expression), (yyvsp[-2].statement_list), (yyvsp[-1].elseif_list), NULL); }
#line 2125 "parser.tab.c"
    break;

  case 35:
#line 230 "parser.y"
                                                                                                        { (yyval.statement) = new_if_elif((yyvsp[-8].expression), (yyvsp[-5].statement_list), (yyvsp[-4].elseif_list), (yyvsp[-1].statement_list)); }
#line 2131 "parser.tab.c"
    break;

  case 36:
#line 231 "parser.y"
                                                                                              { (yyval.statement) = new_if_elif((yyvsp[-7].expression), (yyvsp[-4].statement_list), NULL, (yyvsp[-1].statement_list)); }
#line 2137 "parser.tab.c"
    break;

  case 37:
#line 232 "parser.y"
                                           { (yyval.statement) = new_print((yyvsp[-1].expression_list)); }
#line 2143 "parser.tab.c"
    break;

  case 38:
#line 233 "parser.y"
                                     { (yyval.statement) = new_read((yyvsp[-1].var_name)); }
#line 2149 "parser.tab.c"
    break;

  case 39:
#line 234 "parser.y"
                                                                      { (yyval.statement) = new_while((yyvsp[-4].expression), (yyvsp[-1].statement_list)); }
#line 2155 "parser.tab.c"
    break;

  case 40:
#line 235 "parser.y"
                                                                                            { (yyval.statement) = new_for((yyvsp[-8].var_name), (yyvsp[-6].expression), (yyvsp[-4].expression), (yyvsp[-1].statement_list)); }
#line 2161 "parser.tab.c"
    break;

  case 41:
#line 236 "parser.y"
                                                             { (yyval.statement) = new_switch((yyvsp[-4].expression), (yyvsp[-1].case_list), NULL); }
#line 2167 "parser.tab.c"
    break;

  case 42:
#line 237 "parser.y"
                                                                                               { (yyval.statement) = new_switch((yyvsp[-7].expression), (yyvsp[-4].case_list), (yyvsp[-1].statement_list)); }
#line 2173 "parser.tab.c"
    break;

  case 43:
#line 238 "parser.y"
                                          { (yyval.statement) = new_function_call((yyvsp[-3].var_name), (yyvsp[-1].expression_list)); }
#line 2179 "parser.tab.c"
    break;

  case 44:
#line 239 "parser.y"
                           { (yyval.statement) = new_return((yyvsp[0].expression)); }
#line 2185 "parser.tab.c"
    break;

  case 45:
#line 244 "parser.y"
        { (yyval.elseif_list) = new_elif_list((yyvsp[-2].expression), (yyvsp[0].statement_list), NULL); }
#line 2191 "parser.tab.c"
    break;

  case 46:
#line 246 "parser.y"
        { (yyval.elseif_list) = new_elif_list((yyvsp[-3].expression), (yyvsp[-1].statement_list), (yyvsp[0].elseif_list)); }
#line 2197 "parser.tab.c"
    break;

  case 47:
#line 250 "parser.y"
               { (yyval.expression_list) = new_expression_list((yyvsp[0].expression), NULL); }
#line 2203 "parser.tab.c"
    break;

  case 48:
#line 251 "parser.y"
                                       { (yyval.expression_list) = new_expression_list((yyvsp[-2].expression), (yyvsp[0].expression_list)); }
#line 2209 "parser.tab.c"
    break;

  case 49:
#line 255 "parser.y"
                                        { (yyval.case_list) = new_case_list((yyvsp[-2].expression), (yyvsp[0].statement_list), NULL); }
#line 2215 "parser.tab.c"
    break;

  case 50:
#line 256 "parser.y"
                                                    { (yyval.case_list) = new_case_list((yyvsp[-3].expression), (yyvsp[-1].statement_list), (yyvsp[0].case_list)); }
#line 2221 "parser.tab.c"
    break;

  case 51:
#line 260 "parser.y"
               { (yyval.expression) = new_integer((yyvsp[0].int_value)); }
#line 2227 "parser.tab.c"
    break;

  case 52:
#line 261 "parser.y"
                  { (yyval.expression) = new_decimal((yyvsp[0].double_value)); }
#line 2233 "parser.tab.c"
    break;

  case 53:
#line 262 "parser.y"
                 { (yyval.expression) = new_string((yyvsp[0].string_value)); }
#line 2239 "parser.tab.c"
    break;

  case 54:
#line 263 "parser.y"
                  { (yyval.expression) = new_boolean((yyvsp[0].bval)); }
#line 2245 "parser.tab.c"
    break;

  case 55:
#line 264 "parser.y"
                  { (yyval.expression) = new_variable((yyvsp[0].var_name)); }
#line 2251 "parser.tab.c"
    break;

  case 56:
#line 265 "parser.y"
                                          { 
        //Statement *call = new_function_call($1, $3);
        (yyval.expression) = new_function_expression((yyvsp[-3].var_name), (yyvsp[-1].expression_list));
    }
#line 2260 "parser.tab.c"
    break;

  case 57:
#line 269 "parser.y"
                                 { (yyval.expression) = new_binary_op('+', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2266 "parser.tab.c"
    break;

  case 58:
#line 270 "parser.y"
                                  { (yyval.expression) = new_binary_op('-', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2272 "parser.tab.c"
    break;

  case 59:
#line 271 "parser.y"
                                  { (yyval.expression) = new_binary_op('*', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2278 "parser.tab.c"
    break;

  case 60:
#line 272 "parser.y"
                                   { (yyval.expression) = new_binary_op('/', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2284 "parser.tab.c"
    break;

  case 61:
#line 273 "parser.y"
                                { (yyval.expression) = new_binary_op('&', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2290 "parser.tab.c"
    break;

  case 62:
#line 274 "parser.y"
                                   { (yyval.expression) = new_binary_op('C', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2296 "parser.tab.c"
    break;

  case 63:
#line 275 "parser.y"
                               { (yyval.expression) = new_binary_op('|', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2302 "parser.tab.c"
    break;

  case 64:
#line 276 "parser.y"
                                { (yyval.expression) = new_binary_op('^', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2308 "parser.tab.c"
    break;

  case 65:
#line 277 "parser.y"
                                  { (yyval.expression) = new_binary_op('P', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2314 "parser.tab.c"
    break;

  case 66:
#line 278 "parser.y"
                                   { (yyval.expression) = new_binary_op('M', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2320 "parser.tab.c"
    break;

  case 67:
#line 279 "parser.y"
                     { (yyval.expression) = new_unary_op('!', (yyvsp[0].expression)); }
#line 2326 "parser.tab.c"
    break;

  case 68:
#line 280 "parser.y"
                               { (yyval.expression) = new_binary_op('<', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2332 "parser.tab.c"
    break;

  case 69:
#line 281 "parser.y"
                               { (yyval.expression) = new_binary_op('>', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2338 "parser.tab.c"
    break;

  case 70:
#line 282 "parser.y"
                               { (yyval.expression) = new_binary_op('L', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2344 "parser.tab.c"
    break;

  case 71:
#line 283 "parser.y"
                               { (yyval.expression) = new_binary_op('G', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2350 "parser.tab.c"
    break;

  case 72:
#line 284 "parser.y"
                               { (yyval.expression) = new_binary_op('=', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2356 "parser.tab.c"
    break;

  case 73:
#line 285 "parser.y"
                               { (yyval.expression) = new_binary_op('!', (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2362 "parser.tab.c"
    break;

  case 74:
#line 286 "parser.y"
                               { (yyval.expression) = (yyvsp[-1].expression); }
#line 2368 "parser.tab.c"
    break;

  case 75:
#line 287 "parser.y"
                                           { (yyval.expression) = new_unary_op('R', (yyvsp[-1].expression)); }
#line 2374 "parser.tab.c"
    break;

  case 76:
#line 288 "parser.y"
                                    { (yyval.expression) = new_unary_op('S', (yyvsp[-1].expression)); }
#line 2380 "parser.tab.c"
    break;

  case 77:
#line 289 "parser.y"
                                      { (yyval.expression) = new_unary_op('C', (yyvsp[-1].expression)); }
#line 2386 "parser.tab.c"
    break;

  case 78:
#line 290 "parser.y"
                                       { (yyval.expression) = new_unary_op('T', (yyvsp[-1].expression)); }
#line 2392 "parser.tab.c"
    break;

  case 79:
#line 291 "parser.y"
                                   {(yyval.expression) = new_unary_op('L', (yyvsp[-1].expression)); }
#line 2398 "parser.tab.c"
    break;

  case 80:
#line 292 "parser.y"
                                     { (yyval.expression) = new_unary_op('l', (yyvsp[-1].expression));}
#line 2404 "parser.tab.c"
    break;

  case 81:
#line 293 "parser.y"
                                     { (yyval.expression) = new_unary_op('D', (yyvsp[-1].expression));}
#line 2410 "parser.tab.c"
    break;

  case 82:
#line 294 "parser.y"
                                   { (yyval.expression) = new_unary_op('A', (yyvsp[-1].expression));}
#line 2416 "parser.tab.c"
    break;

  case 83:
#line 295 "parser.y"
                                   { (yyval.expression) = new_unary_op('E', (yyvsp[-1].expression));}
#line 2422 "parser.tab.c"
    break;

  case 84:
#line 296 "parser.y"
                           {
        srand(time(0));
        double random_number = (double)rand() / (RAND_MAX + 1.0);
        (yyval.expression) = new_decimal(random_number);
    }
#line 2432 "parser.tab.c"
    break;

  case 85:
#line 301 "parser.y"
                                                       { (yyval.expression) = new_binary_op('A', (yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 2438 "parser.tab.c"
    break;

  case 86:
#line 302 "parser.y"
                                      { (yyval.expression) = new_unary_op('H', (yyvsp[-1].expression)); }
#line 2444 "parser.tab.c"
    break;

  case 87:
#line 303 "parser.y"
                                                        { (yyval.expression) = new_binary_op('p', (yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 2450 "parser.tab.c"
    break;

  case 88:
#line 304 "parser.y"
                                                                       {
        Expression *str_exp = evaluate_expression((yyvsp[-5].expression));
        Expression *pos_exp = evaluate_expression((yyvsp[-3].expression));
        Expression *n_exp = evaluate_expression((yyvsp[-1].expression));

        if (str_exp->type != STRING || pos_exp->type != INTEGER || n_exp->type != INTEGER)
        {
            printf("Erreur ligne %d: Type d'argument invalide pour 'Copie'\n", yylineno);
            exit(1);
        }

        char *new_str = malloc(sizeof(char*) * strlen(str_exp->data.string_value) + 1);

        strncpy(new_str, str_exp->data.string_value + pos_exp->data.int_value, n_exp->data.int_value);
        new_str[n_exp->data.int_value] = '\0';

        (yyval.expression) = new_string(new_str);
        free(str_exp);
        free(pos_exp);
        free(n_exp);
        //free(new_str);
    }
#line 2477 "parser.tab.c"
    break;

  case 89:
#line 326 "parser.y"
                                                       { (yyval.expression) = new_binary_op('r', (yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 2483 "parser.tab.c"
    break;

  case 90:
#line 327 "parser.y"
                                               {
        (yyval.expression) = new_array_access((yyvsp[-3].var_name), (yyvsp[-1].expression), NULL);
    }
#line 2491 "parser.tab.c"
    break;

  case 91:
#line 330 "parser.y"
                                                                            {
        (yyval.expression) = new_array_access((yyvsp[-6].var_name), (yyvsp[-4].expression), (yyvsp[-1].expression));
    }
#line 2499 "parser.tab.c"
    break;

  case 92:
#line 333 "parser.y"
                                         { 
        (yyval.expression) = new_unary_op('t', (yyvsp[-1].expression));
    }
#line 2507 "parser.tab.c"
    break;

  case 93:
#line 336 "parser.y"
                                                          {
        // Module-qualified function call
        Function *func = get_module_function((yyvsp[-5].var_name), (yyvsp[-3].var_name));
        if (!func) {
            yyerror("Fonction introuvable dans le module");
            YYERROR;
        }
        (yyval.expression) = new_function_expression((yyvsp[-3].var_name), (yyvsp[-1].expression_list));
        //$$ = evaluate_function_call($3, $5);
    }
#line 2522 "parser.tab.c"
    break;

  case 94:
#line 346 "parser.y"
                                  {
        // Module-qualified variable access
        yyerror("Accès à une variable qualifiée par module non supporté");
        YYERROR;
    }
#line 2532 "parser.tab.c"
    break;

  case 95:
#line 354 "parser.y"
                { (yyval.type) = TYPE_ENTIER; }
#line 2538 "parser.tab.c"
    break;

  case 96:
#line 355 "parser.y"
                   { (yyval.type) = TYPE_DECIMAL; }
#line 2544 "parser.tab.c"
    break;

  case 97:
#line 356 "parser.y"
                  { (yyval.type) = TYPE_CHAINE; }
#line 2550 "parser.tab.c"
    break;

  case 98:
#line 357 "parser.y"
                   { (yyval.type) = TYPE_LOGIQUE; }
#line 2556 "parser.tab.c"
    break;

  case 99:
#line 361 "parser.y"
                                                {
        (yyval.module) = new_module((yyvsp[-2].var_name));
        current_module = (yyval.module);
        module_table[module_count++] = (yyval.module);
        // Add all functions from module_content to module
        StatementList *list = (yyvsp[-1].statement_list);
        while (list) {
            if (list->statement && list->statement->type == FUNCTION_DECL) {
                add_function_to_module((yyval.module), list->statement->data.function_decl.function);
            }
            list = list->next;
        }
        current_module = NULL;
    }
#line 2575 "parser.tab.c"
    break;

  case 100:
#line 378 "parser.y"
                  { (yyval.statement_list) = new_statement_list(new_function_statement((yyvsp[0].function)), NULL); }
#line 2581 "parser.tab.c"
    break;

  case 101:
#line 379 "parser.y"
                                   { (yyval.statement_list) = new_statement_list(new_function_statement((yyvsp[-1].function)), (yyvsp[0].statement_list)); }
#line 2587 "parser.tab.c"
    break;

  case 102:
#line 383 "parser.y"
                         {
        (yyval.import) = new_import((yyvsp[0].var_name), NULL, 0);
        execute_import((yyval.import));
    }
#line 2596 "parser.tab.c"
    break;

  case 103:
#line 387 "parser.y"
                                                     {
        (yyval.import) = new_import((yyvsp[-2].var_name), (yyvsp[0].function_names), count_function_names((yyvsp[0].function_names)));
        execute_import((yyval.import));
    }
#line 2605 "parser.tab.c"
    break;

  case 104:
#line 394 "parser.y"
                {
        char **names = malloc(sizeof(char *));
        names[0] = (yyvsp[0].var_name);
        (yyval.function_names) = names;
    }
#line 2615 "parser.tab.c"
    break;

  case 105:
#line 399 "parser.y"
                                           {
        int count = 0;
        char **names = (yyvsp[-2].function_names);
        while (names[count]) count++;
        names = realloc(names, sizeof(char *) * (count + 2));
        names[count] = (yyvsp[0].var_name);
        names[count + 1] = NULL;
        (yyval.function_names) = names;
    }
#line 2629 "parser.tab.c"
    break;


#line 2633 "parser.tab.c"

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
#line 410 "parser.y"


void yyerror(const char *s) {
    if (strcmp(s, "syntax error") == 0) {
        fprintf(stderr, "Erreur ligne %d: Syntaxe incorrecte\n", yylineno);
    }
    else {
        fprintf(stderr, "Erreur ligne %d: %s\n", yylineno, s);
    }
}
