/* A Bison parser, made by GNU Bison 3.7.1.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_CMINUS_TAB_H_INCLUDED
# define YY_YY_CMINUS_TAB_H_INCLUDED
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
    IF = 258,                      /* IF  */
    ELSE = 259,                    /* ELSE  */
    RETURN = 260,                  /* RETURN  */
    INT = 261,                     /* INT  */
    VOID = 262,                    /* VOID  */
    WHILE = 263,                   /* WHILE  */
    ID = 264,                      /* ID  */
    NUM = 265,                     /* NUM  */
    LESS_OR_EQUAL = 266,           /* LESS_OR_EQUAL  */
    GREATER_OR_EQUAL = 267,        /* GREATER_OR_EQUAL  */
    EQUAL = 268,                   /* EQUAL  */
    NOT_EQUAL = 269,               /* NOT_EQUAL  */
    LEFT_PRNTS = 270,              /* LEFT_PRNTS  */
    RIGHT_PRNTS = 271,             /* RIGHT_PRNTS  */
    LEFT_BRACKET = 272,            /* LEFT_BRACKET  */
    RIGHT_BRACKET = 273,           /* RIGHT_BRACKET  */
    LEFT_BRACE = 274,              /* LEFT_BRACE  */
    RIGHT_BRACE = 275,             /* RIGHT_BRACE  */
    ADD = 276,                     /* ADD  */
    SUBSTRACT = 277,               /* SUBSTRACT  */
    MULTIPLY = 278,                /* MULTIPLY  */
    DIVIDE = 279,                  /* DIVIDE  */
    MOD = 280,                     /* MOD  */
    LESS = 281,                    /* LESS  */
    GREATER = 282,                 /* GREATER  */
    ASSIGN = 283,                  /* ASSIGN  */
    SEMICOLON = 284,               /* SEMICOLON  */
    COMMA = 285                    /* COMMA  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 11 "cminus.y"

     char* name;            
     int value;                
     struct ASTNode* node;      
 

#line 101 "cminus.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CMINUS_TAB_H_INCLUDED  */
