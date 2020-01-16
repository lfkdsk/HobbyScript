%{

#include "object.h"
#define YYERROR_VERBOSE 1
#define YYDEBUG 1
#define YY_NO_UNISTD_H

extern "C" int yylex();
void yyerror( const char* error );

%}


%union{
	AstType		*tp;
	AstNode		*expr;
	char*		str;
	int			type;
}

%right '=' AEQ '.'
%left ISOPT
%left OR AND
%left EQ NOEQ
%left '<' '>' LEQ REQ
%left LEFTMOVE RIGHTMOVE URIGHTMOVE ARRAY STRING_LITERAL
%left '+' '-'
%left '*' '/'
%left '&' '|' '^'
%left '(' ')'
%right '~' '!' INC DEC
%token BINARY EOL FEOF FUNC DOTS TYPE RGO WHEN_NULL
%token '{' '}' ';' '[' ']' ':' '`'
%token<type>	ITYPE
%token<str>		L_IDENTIFIER U_IDENTIFIER
%token<expr>	INTEGER FLOAT INT64 FLOAT64 BOOLEAN STRING_LITERAL
%type<tp>		def_type def_types cls_inherit func_type
%type<expr>		typeLet function_variable equal block_or_none
%type<expr>		typeLets function_parameters class_new go types
%type<type>		cls_type cls_construct operator operator_binary operator_unary
%type<expr>		expr expr_value lambda call exprs for_loop cls function_def def sequence array_new
%type<expr>		tuple tupleResolve assignment splice index  while_loop type_expr if_expr function_ret
%type<expr>		line const enum function rtn if_cond switch object_block lines tupleResolveParams block_or_line
%type<expr>		interface if_else try object_delete operator_overload annotation block return_tuple_elem return_tuple_elems
%token CALL IF ELSE WHILE FOR RETURN CLASS INTERF PROTECTED
%token PACKAGE IMPORT NULLPTR STATIC CONST ENUM SWITCH CASE DEFAULT SINGLETON
%token TRY_TOKEN CATCH FINALLY GET_TOKEN SET_TOKEN OPERATOR NEW_TOKEN DELETE_TOKEN
%token INIT_TOKEN FINALIZE_TOKEN GO_TOKEN BBRACKETS

%defines

%%

package
	:	package_name_line
		import
		lines
		{ setPackageLines($3); }
	;

package_name
	:	L_IDENTIFIER						{ $<expr>$=let($1); }
	|	package_name '.' L_IDENTIFIER		{ $<expr>$=link($<expr>1, let($3)); }
	;

package_name_line
	: PACKAGE package_name		{ $<expr>$=packageName($<expr>2); }
	| { $<expr>$=nullptr; }
	;

/*
	import org.silang.net
	import (	// 导入多个
		org.silang.math.sin
		org.silang.io.print
	)
*/
import
	:
	|	import_line
	|	import import_line
	;

import_line
	:	IMPORT import_name 					{ packageImport( $<expr>2 ); }
	|	IMPORT '(' import_names ')' 		{ packageImport( $<expr>3 ); }
	;

import_name_pre
	:	L_IDENTIFIER							{ $<expr>$=let($1); }
	|	import_name_pre '.' L_IDENTIFIER		{ $<expr>$=link($<expr>1, let($3)); }
	;

import_name
	:	import_name_pre '.' '*'					{ $<expr>$=importName($<expr>1, "*"); }
	|	import_name_pre '.' U_IDENTIFIER		{ $<expr>$=importName($<expr>1, $3); }
	|	import_name_pre '.' L_IDENTIFIER		{ $<expr>$=importName($<expr>1, $3, true); }
	;

import_names
	:	import_name
	|	import_names import_name				{ $<expr>$=link($<expr>1, $<expr>2); }
	;

block
	:	'{' '}' { $<expr>$=makeEmpty(); } // 插入一个空节点，以便和没有 block 区分开
	|	'{' lines '}' { $$=$2; }
	;

lines
	:	line
	|	lines line	{ $$=link($1,$2); }
	;

line
	:	def
	|	cls
	|   interface
	|	tupleResolve
	|   call
	|	assignment
	|	expr
	|	rtn
	|	for_loop
	|	while_loop
	|	if_else
	|   function
	|   const
	|	enum
	|	switch
	|	try
	|	object_delete
	|	operator_overload
	|	class_new
	;

const
	:	CONST L_IDENTIFIER '=' expr	{ $$=makeConst($2,$4); }

equal
	: L_IDENTIFIER '=' expr	{ $<expr>$=let($1,$3);  }

// expr, expr ...
exprs
	:	expr
	|	exprs ',' expr			{ $<expr>$=link($1, $3); }
	;

// Type i { = x }
typeLet
	: 	def_type  L_IDENTIFIER			  			{ $$=let($1, $2); }
	|	def_type  L_IDENTIFIER '=' expr				{ $$=let($1, $2, $4); }
	|	func_type L_IDENTIFIER			  			{ $$=let($1, $2); }
	;

typeLets
	:	typeLet
	|	typeLets ',' typeLet	{ $<expr>$=link($<expr>1, $3); }

/***********************
*	枚举
************************/
enum
	:	ENUM U_IDENTIFIER '{' enum_list '}' { $$=createEnum($2, $<expr>4); }
	;

enum_list
	: enum_assignment
	| enum_list ',' enum_assignment		{ $<expr>$=link($<expr>1,$<expr>3); }
	;

enum_assignment
	: U_IDENTIFIER '=' expr	{ $<expr>$=let($1,$3);  }// red = 10
	| U_IDENTIFIER			{ $<expr>$=let($1,nullptr); }
	;

/************************
	* 类定义
**********************/
cls_inherit
	:					{ $$=nullptr; }
	|	':' def_type	{ $$=$2; }
	;

cls_template_list
	:					{ $<expr>$=nullptr; }
	|	'<' types '>'	{ $<expr>$=$<expr>2; }
	;

types
	:	U_IDENTIFIER			{ $$=createNode($1); }
	|	types ',' U_IDENTIFIER	{ $$=link($1, createNode($3)); }
	;

cls
	:	cls_type U_IDENTIFIER cls_template_list cls_inherit cls_block
		{ $$=makeClass($1,$2, $<expr>3, $4, $<expr>5 ); }
	|	annotation cls { $$=annotationdClass($1,$2); }	// 注解
	;

cls_type
	:	CLASS { $<type>$=0; }
	|	SINGLETON { $<type>$=1; }
	;

cls_line
	:	def
	|	get
	|	set
	|	cls_construct
	|	cls_destory
	|   const
	|	function
	|	PROTECTED ':'			{ $<expr>$=setProtected(); }
	|	operator_overload
	;

// 构造函数
cls_construct
	: INIT_TOKEN '(' function_parameters ')' construct_block_or_none
		 { $<expr>$=createFunction(2, "Init", $3, nullptr, $<expr>5); }
	;

construct_block_or_none
	:	{ $<expr>$=nullptr; }
	|	'{' '}' { $<expr>$=makeEmpty(); } // 插入一个空节点，以便和没有 block 区分开
	|	'{' construct_block_lines '}' { $<expr>$=$<expr>2; }
	;

construct_block_lines
	: INIT_TOKEN '(' call_args ')' { $<expr>$=makeCall("Init", $<expr>3); }
	| lines
	;

cls_destory
	:   FINALIZE_TOKEN block_or_none
		{ $<expr>$=createFunction(3, "Finalize", nullptr, nullptr, $2); }
	;

cls_lines
	:	cls_line
	|	cls_lines cls_line		{ $<expr>$=link($<expr>1, $<expr>2); }

cls_block
	:	'{' cls_lines '}'		{ $<expr>$=$<expr>2; }
	|
	;

/**********************************************
*	接口
/**********************************************/
interface
	:	INTERF L_IDENTIFIER '{' interface_lines '}' { $<tp>$=createInterface($2, $<expr>4); }
	;

interface_line
	:	def
	|	function_def
	;

interface_lines
	:	interface_line
	|	interface_lines interface_line	{ $<expr>$=link($<expr>1, $<expr>2); }
	;

function_def
	: FUNC L_IDENTIFIER '(' function_parameters ')' function_ret
		 { $<expr>$=createFunction(0, $2, $4, $6, nullptr); }
	;

/**********************************************
*	GET, SET
**********************************************/
get
	: GET_TOKEN L_IDENTIFIER block { $<expr>$=makeGet($2,$3); }
	;

set
	: SET_TOKEN L_IDENTIFIER '(' def_type L_IDENTIFIER ')' block { $<expr>$=makeSet($2, $4, $5, $7); }
	| SET_TOKEN L_IDENTIFIER block { $<expr>$=makeSet($2, nullptr, nullptr, $3); }
	;

/**********************************************
	* 类型定义
		例
	var i=20, a
	int[] a=...
	tuple<int,float> tup=
	func x=...
	func()
/**********************************************/
def_type
	:	U_IDENTIFIER							{ $$=getClassType($1); }
	|	U_IDENTIFIER '<' def_types '>'			{ $$=getClassType($1, $3); }
	|	ITYPE									{ $$=getType($1); }
	|	def_type '[' ']'						{ $$=makeArray($1); }
	|   def_type '?'							{ $$=nullAble($1); }
	;

func_type
	:	FUNC									{ $$=getFuncType(); }
	|	FUNC '(' ')'							{ $$=getFuncType(NULL); }
	|   FUNC '(' def_types ')'					{ $$=getFuncType($3, NULL); }
	|	FUNC '(' def_types ')' ':' def_type		{ $$=getFuncType($3, $6); }
	;

def_types
	: def_type
	| func_type
	| def_types ',' def_type	{ $$=link($1, $3); }
	;

def
	: 	typeLet									{ $$=createDef($1); }
	|	def ',' L_IDENTIFIER					{ $$=appendDef($1, $3); }
	|	def ',' L_IDENTIFIER '=' expr			{ $$=appendDef($1, $3, $5); }
	|	def_type L_IDENTIFIER AEQ expr			{ $$=tupleResolve(let($2), $<expr>4, true); }	// 单元组解构
	|	def_type '(' tupleResolveParams ')' AEQ expr	{ $$=tupleResolve($<expr>3, $<expr>5, true); }
	;

sequence
	:	'[' exprs ']'		{ $$=makeSequence( $2 ); }
	;

/*********************
* 元组 (3, "a4", 5)
**********************/

tuple
	:	'(' expr ',' exprs ')'	{ $<expr>$=makeTuple($4, $2); }
	;

tupleResolve	/* 元组的自动解构 */
	:   tupleResolveParams AEQ expr		{ $$=tupleResolve($<expr>1, $<expr>3); }
	;

tupleResolveParams
	:	L_IDENTIFIER ',' L_IDENTIFIER		{ $$=link(let($1), let($3)); }
	|	tupleResolveParams ',' L_IDENTIFIER	{ $$=link($1, let($3)); }
	;

/**********************************************
	* 函数调用
/**********************************************/
call
	: L_IDENTIFIER '(' call_args ')' { $$=makeCall($1, $<expr>3); }
	;

call_args
	:							{ $<expr>$=nullptr; }
	|  call_arg
	|  call_args ',' call_arg	{ $<expr>$=link($<expr>1, $<expr>3); }
	;

call_arg
	:	expr
	|	equal				/* 命名调用 */
	;



/*******************************************
*	类的实例化
*	MyCls cls( 1 )
********************************************/
class_new
	: def_type L_IDENTIFIER '(' call_args ')'	{ $<expr>$=createNew($1, $2, $<expr>4); }
	;

object_delete
	:	DELETE_TOKEN expr	{ $<expr>$=makeDelete($2); }
	;

/** String[num]
*/
array_new
	: def_type '[' expr ']'	{ $<expr>$=createNewArray($1, $3); }
	;

/**********************************************
	* 函数定义
	func myfunc(int a, long, mycls val=my) => (int, var named)
**********************************************/
function
	: function_def block_or_none				 { $$=addFunctionBlock($1, $<expr>2); }
	;

block_or_none
	:	{ $<expr>$=NULL; }
	|	block
	;

/*尾部允许可变参数*/
function_variable
	:	 def_type DOTS L_IDENTIFIER		{ $$=let($1, $3, nullptr, 1); }
	;

/* 函数参数定义 */
function_parameters
	:										{ $$=nullptr; }
	|	typeLets
	|   typeLets ',' function_variable		{ $$=link($1, $3); }
	|	function_variable
	;

/**********************************************
	* 操作符重载
	operator +(int a, long, mycls val=my) :  (int, var named)
/**********************************************/
operator_overload
	: OPERATOR operator '(' function_parameters ')' function_ret block_or_none
		 { $$=createOperator($2, $4, $6, $7); }
	| OPERATOR '(' ')' '(' function_parameters ')' function_ret block_or_none
		 { $$=createOperator(BBRACKETS, $5, $7, $8); }
	| OPERATOR ARRAY '(' function_parameters ')' function_ret block_or_none
		 { $$=createOperator(ARRAY, $4, $6, $7); }
	;

function_ret
	:									{ $$=nullptr; }
	| ':' return_tuple_elems 			{ $$=$<expr>2; }/*命名返回*/
	;

return_tuple_elem
	:   typeLet			                // int a = 20
	|	def_type						{ $$=let($1); }
	;

return_tuple_elems
	:	return_tuple_elem
	|	return_tuple_elems ',' return_tuple_elem	{ $$=link($1,$3); }
	;

lambda
	: FUNC '(' function_parameters ')' function_ret block
		 { $$=createFunction(6, "", $3, $5, $6); }
	;

/*
	expr-> {}
	expr-> (int v){}
*/
array_call
	: expr ARRAY block
		{ $<expr>$=makeArrayCall($1, createFunction(6, "", NULL, NULL, $3)); }
	| expr ARRAY '(' function_parameters ')' function_ret block
		{ $<expr>$=makeArrayCall($1, createFunction(6, "", $4, $6, $7)); }
	;

go
	: GO_TOKEN function_ret block
		{ $$=createGo(createFunction(6, "", nullptr, $2, $3)); }
	| GO_TOKEN expr	{ $$=createGo($<expr>2); }
	;

/* return 语句 */
rtn
	:	RETURN			{ $$=callReturn(); }
	|	RETURN exprs	{ $$=callReturn( $2 ); }
	;

/* 操作符 */
operator_binary
	: '+'	{ $<type>$='+'; }
	| '-'	{ $<type>$='-'; }
	| '*'	{ $<type>$='*'; }
	| '/'	{ $<type>$='/'; }
	| '&'	{ $<type>$='&'; }
	| '|'	{ $<type>$='|'; }
	| '!'	{ $<type>$='!'; }
	| '<'	{ $<type>$='<'; }
	| '>'	{ $<type>$='>'; }
	| '%'	{ $<type>$='%'; }
	| '.'	{ $<type>$='.'; }
	| LEFTMOVE		{ $<type>$=LEFTMOVE; }
	| RIGHTMOVE		{ $<type>$=RIGHTMOVE; }
	| URIGHTMOVE	{ $<type>$=URIGHTMOVE; }
	| LEQ	{ $<type>$=LEQ; }
	| REQ	{ $<type>$=REQ; }
	| RGO	{ $<type>$=RGO; }
	| OR	{ $<type>$=OR; }
	| AND	{ $<type>$=AND; }
	;

operator_unary
	: '^'  { $<type>$='^'; }
	| '~'  { $<type>$='~'; }
	;

operator
	:	operator_binary
	|	operator_unary
	;

/**********************************************
	* 分支
***********************************************/

if_cond
	:   IF '(' if_expr ')' block_or_line		{ $$=makeIf( $<expr>3, $5 ); }
	;

if_else
	:	if_cond ELSE block_or_line	{ $<expr>$=setElse($<expr>1, $3); }
	|	if_cond
	;

if_expr
	:	expr
	|	type_expr
	;

block_or_line
	:	line
	|	block
	;

switch
	:	SWITCH expr '{'
			cases
		'}'						{ $$=createSwitch($2, $<expr>4); }
	;

cases
	:	case
	|	cases case		{ $<expr>$=link($<expr>1, $<expr>2); }
	;

case
	:	CASE case_exprs ':'	lines	{ $<expr>$=createCase($<expr>2, $<expr>4); }
	|	DEFAULT ':' lines			{ $<expr>$=createCase(nullptr, $<expr>3); }
	;

case_exprs
	:	expr
	|	case_exprs ',' expr		{ $<expr>$=link($<expr>1, $3); }
	;

/**********************************************
* 异常
***********************************************/
try
	:	TRY_TOKEN block try_catchs try_finally { $<expr>$=createTry( $<expr>2, $<expr>3, $<expr>4 ); }
	;

try_catchs
	:							{ $<expr>$=nullptr; }
	|	try_catch
	|	try_catchs try_catch	{ $<expr>$=link($<expr>1,$<expr>2); }
	;

try_catch
	:	CATCH '(' try_types L_IDENTIFIER ')' block	{ $<expr>$=makeCatch($<expr>3, $4, $<expr>6); }
	;

try_types
	:	def_type							{ $<expr>$=let($1); }
	|	try_types ',' def_type				{ $<expr>$=link($<expr>1,let($3)); }
	;

try_finally
	:					{ $<expr>$=nullptr; }
	|	FINALLY block	{ $<expr>$=$2; }
	;

/**********************************************
	* 循环
***********************************************/

while_loop
	:	WHILE '(' expr ')' block_or_line	{ $$=makeWhile($<expr>3, $5); }

for_loop
	:	FOR '(' for_line ';' expr ';' expr ')'	block_or_line
			{ $$=makeFor( $<expr>3, $<expr>5, $<expr>7, $9); }
	;

for_line
	:
	|	typeLet
	;

/* 赋值语句 */
assignment
	: L_IDENTIFIER '=' expr		  { $$=let($1, $3); }
	| L_IDENTIFIER '=' block	  { $$=let($1, createFunction(6, "", nullptr, nullptr, $3)); }
	| L_IDENTIFIER AEQ expr		  { $$=tupleResolve($<expr>1, $<expr>3); }
	| expr '=' expr				  { $$=binary('=', $1, $3); }
	;

/**********************************************
	* 表达式
***********************************************/
expr
	: expr_value
	| sequence
	| lambda
	| call
	| tuple
	| go
	| array_new
	| NULLPTR					{ $$=makeNull(); }
	| L_IDENTIFIER				{ $$=getVar($1); }
	| '(' expr ')'				{ $$=$2; }
	| operator_unary expr		{ $$=unary($<type>1, $2); }
	| expr operator_unary		{ $$=unaryAfter($<type>2, $1); }
	| assignment
	| splice
	| index
	| object_block
	| expr INC					{ $$=makeInc($1); }
	| expr DEC					{ $$=makeInc($1, false); }
	| expr WHEN_NULL expr		{ $$=makeIIF(makeIsNull($1), $3); }
	| expr '?' expr ':' expr	{ $$=makeIIF($1, $3, $5);}
	| U_IDENTIFIER '.' L_IDENTIFIER { $$=makeGetConstValue($1,$3); }
	| U_IDENTIFIER '.' U_IDENTIFIER { $$=makeGetConstValue($1,$3); }
	| def_type '(' call_args ')'	{ $<expr>$=createNew($1, NULL, $<expr>3); }
	| expr '+' expr				{ $$=binary('+', $1, $3);  }
	| expr '-' expr				{ $$=binary('-', $1, $3);  }
	| expr '*' expr				{ $$=binary('*', $1, $3);  }
	| expr '/' expr				{ $$=binary('/', $1, $3);  }
	| expr '&' expr				{ $$=binary('&', $1, $3);  }
	| expr '|' expr				{ $$=binary('|', $1, $3);  }
	| expr '<' expr				{ $$=binary('<', $1, $3);  }
	| expr '>' expr				{ $$=binary('>', $1, $3);  }
	| expr '%' expr				{ $$=binary('%', $1, $3);  }
	| expr '.' expr				{ $$=binary('.', $1, $3);  }
	| expr LEFTMOVE expr		{ $$=binary(LEFTMOVE, $1, $3);  }
	| expr RIGHTMOVE expr		{ $$=binary(RIGHTMOVE, $1, $3);  }
	| expr URIGHTMOVE expr		{ $$=binary(URIGHTMOVE, $1, $3);  }
	| expr LEQ expr		{ $$=binary(LEQ, $1, $3);  }
	| expr REQ expr		{ $$=binary(REQ, $1, $3);  }
	| expr RGO expr		{ $$=binary(RGO, $1, $3);  }
	| expr EQ expr		{ $$=binary(EQ, $1, $3);  }
	| expr AEQ expr		{ $$=binary(AEQ, $1, $3);  }
	| expr OR expr		{ $$=binary(OR, $1, $3);  }
	| expr AND expr		{ $$=binary(AND, $1, $3);  }
	| array_call		{ $$=$<expr>1; }
	;

type_expr
	: expr ISOPT ITYPE		{ $$=binaryIs($<expr>1, getType($3));  }
	;

string_lite
	:	STRING_LITERAL
	|	string_lite STRING_LITERAL {$<expr>$=stringCat($<expr>1, $2);}
	;

expr_value
	: INTEGER
	| FLOAT
	| INT64
	| FLOAT64
	| string_lite	{ $$=$<expr>$; }
	;


/**********************************************
* 切片
*	var a=str[2:4]
***********************************************/
splice
	:	expr '[' expr ':' expr ']'			{ $$=makeSplice($<expr>1, $<expr>3, $<expr>5); }
	;

/**********************************************
* 索引
*	expr[2]
***********************************************/
index
	:	expr '[' expr ']'	{ $$=makeIndex($1, $3); }
	;

/*********************************************
*	对象作用区
********************************************/

object_block
	:	expr block	{ $$=makeBased($<expr>1, $2); }
	;

/*
*/
annotation
	:   '@' U_IDENTIFIER '(' expr ')'					{ $$=makeAnnotation($2, $4); }
	|   '@'	U_IDENTIFIER '(' annotation_list ')'		{ $$=makeAnnotation($2, $<expr>4); }
	;

annotation_list
	: L_IDENTIFIER '=' expr							{ $<expr>$=let($1,$3); }
	| annotation_list ',' L_IDENTIFIER '=' expr		{ $<expr>$=link($<expr>1, let($3,$5)); }
	;

%%