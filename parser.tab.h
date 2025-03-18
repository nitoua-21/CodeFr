/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
    BREAK = 328,
    CONTINUE = 329,
    TABLEAU = 330,
    LBRACKET = 331,
    RBRACKET = 332,
    VARIABLES = 333,
    FONCTION = 334,
    RETOURNER = 335,
    FINFONCTION = 336,
    TYPE_KWRD = 337,
    MODULE = 338,
    FINMODULE = 339,
    IMPORTER = 340,
    DEPUIS = 341,
    DOT = 342
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

#line 167 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
