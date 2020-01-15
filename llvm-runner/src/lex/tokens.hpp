//
// Created by 刘丰恺 on 15/1/2020.
//

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


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 13 "lex\\hobby.yxx"

//    AstType		*tp;
//    AstNode		*expr;
    char*		str;
    int			type;


/* Line 1676 of yacc.c  */
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;
