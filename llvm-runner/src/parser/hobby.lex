%{
#include <stdio.h>
#include <memory.h>
#include <string>
#include <assert.h>
#include <unistd.h>
#define YY_DECL extern "C" int yylex()
#include "object.h"
#include "hobby.tab.hpp"

#define YY_NO_UNISTD_H

#ifdef _WIN32
#	define isatty	_isatty
#	define SAVETOKEN(x)	{ yylval.str=_strdup(yytext); return x; }
#else
#	define SAVETOKEN(x)	{ yylval.str=strdup(yytext); return x; }
#endif
void comment(void);
%}

%option noyywrap
%option yylineno
D		[0-9]
H		[a-fA-F0-9]

%%
"/*"			{ comment(); }
"//".*			{ /* 忽略注释 */ }

"var"		yylval.type=0;	return ITYPE;	/* 内部变量 */
"bool"		yylval.type=1;	return ITYPE;
"byte"		yylval.type=2;	return ITYPE;
"char"		yylval.type=3;	return ITYPE;
"short"		yylval.type=4;	return ITYPE;
"int"		yylval.type=5;	return ITYPE;
"long"		yylval.type=6;	return ITYPE;
"float"		yylval.type=7;	return ITYPE;
"double"	yylval.type=8;	return ITYPE;
"string"		yylval.type=9;	return ITYPE;
"any"			yylval.type=10;	return ITYPE;
"ushort"		yylval.type=11;	return ITYPE;
"uint"		    yylval.type=12;	return ITYPE;
"ulong"		yylval.type=13;	return ITYPE;


"0"[lL]|(\-?[1-9]{D}*)[lL] { yylval.expr=makeValue(yytext,  (int64_t) std::stoll(yytext));			return INT64; }
"0"|("-"?[1-9]{D}*)			{ yylval.expr=makeValue(yytext, (int32_t) std::stol(yytext));			return INTEGER;  }
"0x"{H}[lL]					{ yylval.expr=makeValue(yytext, (int32_t) std::stol(yytext, 0, 16 ));	return INTEGER; }
"0x"{H}						{ yylval.expr=makeValue(yytext, (int64_t) std::stoll(yytext, 0, 16 ));	return INT64; }
0[0-7]+[lL]					{ yylval.expr=makeValue(yytext, (int32_t) std::stol(yytext, 0, 8));		return INTEGER; }
0[0-7]+						{ yylval.expr=makeValue(yytext, (int64_t) std::stoll(yytext,0, 8));		return INT64; }
"-"{D}+\.{D}+[fF]			{ yylval.expr=makeValue(yytext,std::stof(yytext));			return FLOAT; }
"-"{D}+\.{D}+				{ yylval.expr=makeValue(yytext,std::stod(yytext));			return FLOAT64; }
{D}*\.{D}+[fF]				{ yylval.expr=makeValue(yytext,std::stof(yytext));			return FLOAT; }
{D}*\.{D}+					{ yylval.expr=makeValue(yytext,std::stod(yytext));			return FLOAT64; }
"true"						{ yylval.expr=makeValue(yytext,true);	return BOOLEAN; }
"false"						{ yylval.expr=makeValue(yytext,false);	return BOOLEAN; }

"package"				return PACKAGE;
"import"				return IMPORT;
"func"					return FUNC;
"return"				return RETURN;
"class"					return CLASS;
"null"					return NULLPTR;
"if"					return IF;
"else"					return ELSE;
"while"					return WHILE;
"for"					return FOR;
"interface"				return INTERF;
"protected"				return PROTECTED;
"static"				return STATIC;
"const"					return CONST;
"enum"					return ENUM;
"switch"				return SWITCH;
"case"					return CASE;
"default"				return DEFAULT;
"singleton"				return SINGLETON;
"try"					return TRY_TOKEN;
"catch"					return CATCH;
"finally"				return FINALLY;
"get"					return GET_TOKEN;
"set"					return SET_TOKEN;
"operator"				return OPERATOR;
"new"					return NEW_TOKEN;
"free"					return DELETE_TOKEN;
"is"					return ISOPT;
"init"				return INIT_TOKEN;
"finalize"			return FINALIZE_TOKEN;

[a-z][a-zA-Z0-9]*		SAVETOKEN(L_IDENTIFIER);
[A-Z][a-zA-Z0-9]*		SAVETOKEN(U_IDENTIFIER);

\"(\\.|[^\\"\n])*\"		yylval.expr=makeValue(yytext); return STRING_LITERAL;
"<<"					return LEFTMOVE;
">>"					return RIGHTMOVE;
">>>"					return URIGHTMOVE;
"->"					return ARRAY;
"<="					return LEQ;
">="					return REQ;
"=>"					return RGO;
"=="					return EQ;
":="					return AEQ;
"!="					return NOEQ;
"||"					return OR;
"&&"					return AND;
"++"					return INC;
"--"					return DEC;
"..."					return DOTS;
"?:"					return WHEN_NULL;

[&*+-/~!=^<>\|%\(\):`\?\{\}\[\];@\.]	return *yytext;

[ \t\r] { }
\n			{  }
.   { /*printf("Mystery %c\n", *yytext);*/ }
%%

void comment(void)
{
	char c, prev = 0;

	while ((c =
#ifdef __cplusplus
		yyinput()
#else
		input()
#endif
	) != 0)      /* (EOF maps to 0) */
	{
		if (c == '/' && prev == '*')
			return;
		prev = c;
	}
	YY_FATAL_ERROR("unterminated comment");
}

void yyerror( const char* error ){
	printf("Line %d:  %s  at  '%s'  \n",yylineno,error,yytext);
}