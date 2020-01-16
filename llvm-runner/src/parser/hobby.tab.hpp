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

#include "object.h"
/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     AEQ = 258,
     ISOPT = 259,
     AND = 260,
     OR = 261,
     NOEQ = 262,
     EQ = 263,
     REQ = 264,
     LEQ = 265,
     STRING_LITERAL = 266,
     ARRAY = 267,
     URIGHTMOVE = 268,
     RIGHTMOVE = 269,
     LEFTMOVE = 270,
     DEC = 271,
     INC = 272,
     BINARY = 273,
     EOL = 274,
     FEOF = 275,
     FUNC = 276,
     DOTS = 277,
     TYPE = 278,
     RGO = 279,
     WHEN_NULL = 280,
     ITYPE = 281,
     L_IDENTIFIER = 282,
     U_IDENTIFIER = 283,
     INTEGER = 284,
     FLOAT = 285,
     INT64 = 286,
     FLOAT64 = 287,
     BOOLEAN = 288,
     CALL = 289,
     IF = 290,
     ELSE = 291,
     WHILE = 292,
     FOR = 293,
     RETURN = 294,
     CLASS = 295,
     INTERF = 296,
     PROTECTED = 297,
     PACKAGE = 298,
     IMPORT = 299,
     NULLPTR = 300,
     STATIC = 301,
     CONST = 302,
     ENUM = 303,
     SWITCH = 304,
     CASE = 305,
     DEFAULT = 306,
     SINGLETON = 307,
     TRY_TOKEN = 308,
     CATCH = 309,
     FINALLY = 310,
     GET_TOKEN = 311,
     SET_TOKEN = 312,
     OPERATOR = 313,
     NEW_TOKEN = 314,
     DELETE_TOKEN = 315,
     INIT_TOKEN = 316,
     FINALIZE_TOKEN = 317,
     GO_TOKEN = 318,
     BBRACKETS = 319
   };
#endif
/* Tokens.  */
#define AEQ 258
#define ISOPT 259
#define AND 260
#define OR 261
#define NOEQ 262
#define EQ 263
#define REQ 264
#define LEQ 265
#define STRING_LITERAL 266
#define ARRAY 267
#define URIGHTMOVE 268
#define RIGHTMOVE 269
#define LEFTMOVE 270
#define DEC 271
#define INC 272
#define BINARY 273
#define EOL 274
#define FEOF 275
#define FUNC 276
#define DOTS 277
#define TYPE 278
#define RGO 279
#define WHEN_NULL 280
#define ITYPE 281
#define L_IDENTIFIER 282
#define U_IDENTIFIER 283
#define INTEGER 284
#define FLOAT 285
#define INT64 286
#define FLOAT64 287
#define BOOLEAN 288
#define CALL 289
#define IF 290
#define ELSE 291
#define WHILE 292
#define FOR 293
#define RETURN 294
#define CLASS 295
#define INTERF 296
#define PROTECTED 297
#define PACKAGE 298
#define IMPORT 299
#define NULLPTR 300
#define STATIC 301
#define CONST 302
#define ENUM 303
#define SWITCH 304
#define CASE 305
#define DEFAULT 306
#define SINGLETON 307
#define TRY_TOKEN 308
#define CATCH 309
#define FINALLY 310
#define GET_TOKEN 311
#define SET_TOKEN 312
#define OPERATOR 313
#define NEW_TOKEN 314
#define DELETE_TOKEN 315
#define INIT_TOKEN 316
#define FINALIZE_TOKEN 317
#define GO_TOKEN 318
#define BBRACKETS 319




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 14 "hobby.yy"
{
	AstType		*tp;
	AstNode		*expr;
	char*		str;
	int			type;
}
/* Line 1529 of yacc.c.  */
#line 184 "hobby.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

