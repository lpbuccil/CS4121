/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     AND = 258,
     ELSE = 259,
     EXIT = 260,
     FOR = 261,
     IF = 262,
     INTEGER = 263,
     NOT = 264,
     OR = 265,
     READ = 266,
     WHILE = 267,
     WRITE = 268,
     LBRACE = 269,
     RBRACE = 270,
     LE = 271,
     LT = 272,
     GE = 273,
     GT = 274,
     EQ = 275,
     NE = 276,
     ASSIGN = 277,
     COMMA = 278,
     SEMICOLON = 279,
     LBRACKET = 280,
     RBRACKET = 281,
     LPAREN = 282,
     RPAREN = 283,
     PLUS = 284,
     TIMES = 285,
     IDENTIFIER = 286,
     DIVIDE = 287,
     RETURN = 288,
     STRING = 289,
     INTCON = 290,
     MINUS = 291,
     DIVDE = 292
   };
#endif
/* Tokens.  */
#define AND 258
#define ELSE 259
#define EXIT 260
#define FOR 261
#define IF 262
#define INTEGER 263
#define NOT 264
#define OR 265
#define READ 266
#define WHILE 267
#define WRITE 268
#define LBRACE 269
#define RBRACE 270
#define LE 271
#define LT 272
#define GE 273
#define GT 274
#define EQ 275
#define NE 276
#define ASSIGN 277
#define COMMA 278
#define SEMICOLON 279
#define LBRACKET 280
#define RBRACKET 281
#define LPAREN 282
#define RPAREN 283
#define PLUS 284
#define TIMES 285
#define IDENTIFIER 286
#define DIVIDE 287
#define RETURN 288
#define STRING 289
#define INTCON 290
#define MINUS 291
#define DIVDE 292




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 86 "CminusParser.y"
{
	char* name;
	int symIndex;
	int ivalue;
	char* svalue;
}
/* Line 1529 of yacc.c.  */
#line 130 "CminusParser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE Cminus_lval;

