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

#ifndef YY_YY_FONTE_TAB_H_INCLUDED
# define YY_YY_FONTE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INICIO_PROGRAMA = 258,
    FIM_PROGRAMA = 259,
    IF = 260,
    FOR = 261,
    DO = 262,
    ELSE = 263,
    ELSEIF = 264,
    WHILE = 265,
    RETURN = 266,
    TIPOS_VARIAVEIS = 267,
    NUMERO_INTEIRO = 268,
    NUMERO_REAL = 269,
    ID = 270,
    OPERADORES_ARITMETICOS = 271,
    OPERADORES_RELACIONAIS = 272,
    OPERADORES_LOGICOS = 273,
    PONTO_E_VIRGULA = 274,
    VIRGULA = 275,
    ABRE_PARENTESES = 276,
    FECHA_PARENTESES = 277,
    ABRE_CHAVES = 278,
    FECHA_CHAVES = 279,
    ATRIBUICAO = 280,
    STRING = 281,
    PRINT = 282
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_FONTE_TAB_H_INCLUDED  */
