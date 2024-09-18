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
# define YYDEBUG 0
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
    IDENTIFIER = 260,              /* IDENTIFIER  */
    STRING_VAL = 261,              /* STRING_VAL  */
    LOGIQUE_VAL = 262,             /* LOGIQUE_VAL  */
    COMPARISON_OP = 263,           /* COMPARISON_OP  */
    PLUS = 264,                    /* PLUS  */
    MINUS = 265,                   /* MINUS  */
    TIMES = 266,                   /* TIMES  */
    DIVIDE = 267,                  /* DIVIDE  */
    CONCAT = 268,                  /* CONCAT  */
    LPAREN = 269,                  /* LPAREN  */
    RPAREN = 270,                  /* RPAREN  */
    ASSIGN = 271,                  /* ASSIGN  */
    VARIABLE = 272,                /* VARIABLE  */
    VARIABLES = 273,               /* VARIABLES  */
    ECRIRE = 274,                  /* ECRIRE  */
    LIRE = 275,                    /* LIRE  */
    COLON = 276,                   /* COLON  */
    COMMA = 277,                   /* COMMA  */
    ALGORITHME = 278,              /* ALGORITHME  */
    DEBUT = 279,                   /* DEBUT  */
    FIN = 280,                     /* FIN  */
    ENTIER = 281,                  /* ENTIER  */
    DECIMAL = 282,                 /* DECIMAL  */
    LOGIQUE = 283,                 /* LOGIQUE  */
    CHAINE = 284,                  /* CHAINE  */
    SI = 285,                      /* SI  */
    ALORS = 286,                   /* ALORS  */
    SINONSI = 287,                 /* SINONSI  */
    SINON = 288,                   /* SINON  */
    FINSI = 289                    /* FINSI  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "parser.y"

    int ival;
    double fval;
    char *sval;
    bool bval;
    char **str_list;
    char op;
    SymbolType type;

#line 108 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
