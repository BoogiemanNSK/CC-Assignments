DIGIT			[0-9]
ANYCHAR			[a-zA-Z_]
HEXCHAR			[a-fA-F0-9]
EXPONENT		([Ee][+-]?{DIGIT}+)
HEXEXPONENT   	([Pp][+-]?{DIGIT}+)
FLOATSUFFIX		(f|F|l|L)
INTSUFFIX       ((u|U)|(u|U)?(l|L|ll|LL)|(l|L|ll|LL)(u|U))

%option noyywrap nounput noinput batch debug 

%{
	#include <cerrno>
	#include <climits>
	#include <cstdlib>
	#include <cstring>
	#include <string>
	#include "driver.hh"
	#include "parser.hh"
	#define YY_NO_UNISTD_H

	yy::parser::symbol_type make_NUMBER (const std::string &s, const yy::parser::location_type& loc);
	void comment(void);
%}

%%
"/*"		 	{ comment(); }
"//"[^\n]* 	 	{ /* consume //-comment */ }
"#"[^\n]*		{ /* consume pre-processor directives */ }

"auto" 			{ return AUTO; }
"_Bool"			{ return BOOL; }
"break"			{ return BREAK; }
"case"			{ return CASE; }
"char"			{ return CHAR; }
"_Complex"		{ return COMPLEX; }
"const"			{ return CONST; }
"continue"		{ return CONTINUE; }
"default"		{ return DEFAULT; }
"do"			{ return DO; }
"double"		{ return DOUBLE; }
"else"			{ return ELSE; }
"enum"			{ return ENUM; }
"extern"		{ return EXTERN; }
"float"			{ return FLOAT; }
"for"			{ return FOR; }
"goto"			{ return GOTO; }
"if"			{ return IF; }
"_Imaginary"	{ return IMAGINARY; }
"inline"		{ return INLINE; }
"int"			{ return INT; }
"long"			{ return LONG; }
"register"		{ return REGISTER; }
"restrict"		{ return RESTRICT; }
"return"		{ return RETURN; }
"short"			{ return SHORT; }
"signed"		{ return SIGNED; }
"sizeof"		{ return SIZEOF; }
"static"		{ return STATIC; }
"struct"		{ return STRUCT; }
"switch"		{ return SWITCH; }
"typedef"		{ return TYPEDEF; }
"union"			{ return UNION; }
"unsigned"		{ return UNSIGNED; }
"void"			{ return VOID; }
"volatile"		{ return VOLATILE; }
"while"			{ return WHILE; }

{ANYCHAR}({ANYCHAR}|{DIGIT})*		{ return IDENTIFIER; }

0[xX]{HEXCHAR}+{INTSUFFIX}?	{ return LITERAL; }
0[0-7]*{INTSUFFIX}?			{ return LITERAL; }
[1-9]{DIGIT}*{INTSUFFIX}?	{ return LITERAL; }
ANYCHAR?'(\\.|[^\\'\n])+' 	{ return LITERAL; }

{DIGIT}+{EXPONENT}{FLOATSUFFIX}?							{ return LITERAL; }
{DIGIT}*"."{DIGIT}+{EXPONENT}?{FLOATSUFFIX}?				{ return LITERAL; }
{DIGIT}+"."{DIGIT}*{EXPONENT}?{FLOATSUFFIX}?				{ return LITERAL; }
0[xX]{HEXCHAR}+{HEXEXPONENT}{FLOATSUFFIX}?					{ return LITERAL; }
0[xX]{HEXCHAR}*"."{HEXCHAR}+{HEXEXPONENT}{FLOATSUFFIX}?     { return LITERAL; }
0[xX]{HEXCHAR}+"."{HEXCHAR}*{HEXEXPONENT}{FLOATSUFFIX}?     { return LITERAL; }

\"(\\.|[^"\\])*\"	{ return STRING_LITERAL; }

";"				{ return SEMICOLON; }
","				{ return COMMA; }
":"				{ return COLON; }
"="				{ return ASSIGN_OP; }
"("				{ return LEFT_PAR; }
")"				{ return RIGHT_PAR; }
"."				{ return DOT; }
"&"				{ return AMP; }
"!"				{ return LOG_NOT_OP; }
"~"				{ return BIN_NOT_OP; }
"-"				{ return MINUS; }
"+"				{ return PLUS; }
"*"				{ return STAR; }
"/"				{ return SLASH; }
"%"				{ return MOD_OP; }
"<"				{ return G_OP; }
">"				{ return L_OP; }
"^"				{ return BIN_XOR_OP; }
"|"				{ return BIN_OR_OP; }
"?"				{ return TERNARY_OP; }
("{"|"<%")		{ return LEFT_CBRACKET; }
("}"|"%>")		{ return RIGHT_CBRACKET; }
("["|"<:")		{ return LEFT_BRACKET; }
("]"|":>")		{ return RIGHT_BRACKET; }
"..."			{ return ELLIPSIS; }
">>="			{ return RIGHT_ASSIGN; }
"<<="			{ return LEFT_ASSIGN; }
"+="			{ return ADD_ASSIGN; }
"-="			{ return SUB_ASSIGN; }
"*="			{ return MUL_ASSIGN; }
"/="			{ return DIV_ASSIGN; }
"%="			{ return MOD_ASSIGN; }
"&="			{ return AND_ASSIGN; }
"^="			{ return XOR_ASSIGN; }
"|="			{ return OR_ASSIGN; }
">>"			{ return RIGHT_OP; }
"<<"			{ return LEFT_OP; }
"++"			{ return INC_OP; }
"--"			{ return DEC_OP; }
"->"			{ return PTR_OP; }
"&&"			{ return AND_OP; }
"||"			{ return OR_OP; }
"<="			{ return LE_OP; }
">="			{ return GE_OP; }
"=="			{ return EQ_OP; }
"!="			{ return NE_OP; }

[ \t\v\n\f]		{}
%%

void comment(void)
{
	char c, prev = 0;

	while ((c = input()) != 0)      /* (EOF maps to 0) */
	{
		if (c == '/' && prev == '*')
			return;
		prev = c;
	}
	perror("Unterminated comment");
}

yy::parser::symbol_type make_NUMBER(const std::string &s, const yy::parser::location_type& loc)
{
	errno = 0;
	long n = strtol (s.c_str(), NULL, 10);
	if (! (INT_MIN <= n && n <= INT_MAX && errno != ERANGE))
		throw yy::parser::syntax_error (loc, "integer is out of range: " + s);
	return yy::parser::make_NUMBER ((int) n, loc);
}

void driver::scan_begin()
{
  	yy_flex_debug = trace_scanning;
  	if (file.empty () || file == "-")
    	yyin = stdin;
  	else if (!(yyin = fopen (file.c_str (), "r")))
	{
    	std::cerr << "cannot open " << file << ": " << strerror(errno) << '\n';
    	exit (EXIT_FAILURE);
    }
}

void driver::scan_end()
{
	fclose (yyin);
}
