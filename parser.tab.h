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
    FINSI = 271,                   /* FINSI  */
    EQUALS = 272,                  /* EQUALS  */
    LPAREN = 273,                  /* LPAREN  */
    RPAREN = 274,                  /* RPAREN  */
    VARIABLE_KWRD = 275,           /* VARIABLE_KWRD  */
    ECRIRE = 276,                  /* ECRIRE  */
    ALGORITHME = 277,              /* ALGORITHME  */
    DEBUT = 278,                   /* DEBUT  */
    FIN = 279,                     /* FIN  */
    COLON = 280,                   /* COLON  */
    LIRE = 281,                    /* LIRE  */
    ENTIER_KWRD = 282,             /* ENTIER_KWRD  */
    DECIMAL_KWRD = 283,            /* DECIMAL_KWRD  */
    LOGIQUE_KWRD = 284,            /* LOGIQUE_KWRD  */
    CHAINE_KWRD = 285,             /* CHAINE_KWRD  */
    COMMA = 286,                   /* COMMA  */
    COMMENT = 287,                 /* COMMENT  */
    AND = 288,                     /* AND  */
    OR = 289,                      /* OR  */
    NOT = 290,                     /* NOT  */
    XOR = 291,                     /* XOR  */
    LT = 292,                      /* LT  */
    GT = 293,                      /* GT  */
    LE = 294,                      /* LE  */
    GE = 295,                      /* GE  */
    EQ = 296,                      /* EQ  */
    NE = 297                       /* NE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "parser.y"

    int int_value;
    double double_value;
    char *string_value;
    char *var_name;
    bool bval;
    SymbolType type;
    Expression *expression;
    Statement *statement;
    StatementList *statement_list;

#line 118 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
