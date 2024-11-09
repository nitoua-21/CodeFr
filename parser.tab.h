/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ENTIER_VAL = 258,              /* ENTIER_VAL  */
    DECIMAL_VAL = 259,             /* DECIMAL_VAL  */
    CHAINE = 260,                  /* CHAINE  */
    STRING_VAL = 261,              /* STRING_VAL  */
    LOGIQUE_VAL = 262,             /* LOGIQUE_VAL  */
    IDENTIFIANT = 263,             /* IDENTIFIANT  */
    PLUS = 264,                    /* PLUS  */
    MINUS = 265,                   /* MINUS  */
    TIMES = 266,                   /* TIMES  */
    DIVIDE = 267,                  /* DIVIDE  */
    SI = 268,                      /* SI  */
    ALORS = 269,                   /* ALORS  */
    SINON = 270,                   /* SINON  */
    SINONSI = 271,                 /* SINONSI  */
    FINSI = 272,                   /* FINSI  */
    EQUALS = 273,                  /* EQUALS  */
    LPAREN = 274,                  /* LPAREN  */
    RPAREN = 275,                  /* RPAREN  */
    VARIABLE_KWRD = 276,           /* VARIABLE_KWRD  */
    ECRIRE = 277,                  /* ECRIRE  */
    ALGORITHME = 278,              /* ALGORITHME  */
    DEBUT = 279,                   /* DEBUT  */
    FIN = 280,                     /* FIN  */
    COLON = 281,                   /* COLON  */
    LIRE = 282,                    /* LIRE  */
    ENTIER_KWRD = 283,             /* ENTIER_KWRD  */
    DECIMAL_KWRD = 284,            /* DECIMAL_KWRD  */
    LOGIQUE_KWRD = 285,            /* LOGIQUE_KWRD  */
    CHAINE_KWRD = 286,             /* CHAINE_KWRD  */
    COMMA = 287,                   /* COMMA  */
    COMMENT = 288,                 /* COMMENT  */
    AND = 289,                     /* AND  */
    OR = 290,                      /* OR  */
    NOT = 291,                     /* NOT  */
    XOR = 292,                     /* XOR  */
    CONCAT = 293,                  /* CONCAT  */
    LT = 294,                      /* LT  */
    GT = 295,                      /* GT  */
    LE = 296,                      /* LE  */
    GE = 297,                      /* GE  */
    EQ = 298,                      /* EQ  */
    NE = 299,                      /* NE  */
    TANTQUE = 300,                 /* TANTQUE  */
    FAIRE = 301,                   /* FAIRE  */
    FINTANTQUE = 302,              /* FINTANTQUE  */
    POUR = 303,                    /* POUR  */
    DE = 304,                      /* DE  */
    A = 305,                       /* A  */
    FINPOUR = 306,                 /* FINPOUR  */
    POWER = 307,                   /* POWER  */
    MODULO = 308,                  /* MODULO  */
    CONSTANT = 309,                /* CONSTANT  */
    SELON = 310,                   /* SELON  */
    FINSELON = 311,                /* FINSELON  */
    CAS = 312,                     /* CAS  */
    SQUARE_ROOT = 313,             /* SQUARE_ROOT  */
    SINE = 314,                    /* SINE  */
    COSINE = 315,                  /* COSINE  */
    TANGENT = 316,                 /* TANGENT  */
    LOG = 317,                     /* LOG  */
    LOG10 = 318,                   /* LOG10  */
    ROUND = 319,                   /* ROUND  */
    ABS = 320,                     /* ABS  */
    INT = 321,                     /* INT  */
    RANDOM = 322,                  /* RANDOM  */
    LENGTH = 323,                  /* LENGTH  */
    COMPARE = 324,                 /* COMPARE  */
    CONCATENATE = 325,             /* CONCATENATE  */
    COPY = 326,                    /* COPY  */
    SEARCH = 327,                  /* SEARCH  */
    TABLEAU = 328,                 /* TABLEAU  */
    LBRACKET = 329,                /* LBRACKET  */
    RBRACKET = 330                 /* RBRACKET  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "parser.y"

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

#line 154 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
