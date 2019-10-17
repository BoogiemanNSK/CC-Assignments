DIGIT			[0-9]
ANYCHAR			[a-zA-Z_]
HEXCHAR			[a-fA-F0-9]
EXPONENT		([Ee][+-]?{DIGIT}+)
HEXEXPONENT   	([Pp][+-]?{DIGIT}+)
FLOATSUFFIX		(f|F|l|L)
INTSUFFIX       ((u|U)|(u|U)?(l|L|ll|LL)|(l|L|ll|LL)(u|U))

%{ /* -*- C++ -*- */
#include <stdio.h>

# include <cerrno>
# include <climits>
# include <cstdlib>
# include <cstring> // strerror
# include <string>
# include "driver.hh"
# include "parser.hh"
// # include "astNode.hpp"
%}

%option noyywrap nounput noinput batch debug

%{
void count(void);
void comment(void);
void position(void);
// A number symbol corresponding to the value in S.
yy::parser::symbol_type
make_LITERAL (const std::string &s, const yy::parser::location_type& loc);
yy::parser::symbol_type
make_IDENTIFIER (const std::string &s, const yy::parser::location_type& loc);
yy::parser::symbol_type
make_STRING_LITERAL (const std::string &s, const yy::parser::location_type& loc);
%}


%{
  // Code run each time a pattern is matched.
  # define YY_USER_ACTION  loc.columns (yyleng);
%}

%{
  // A handy shortcut to the location held by the driver.
  yy::location& loc = drv.location;
  // Code run each time yylex is called.
  loc.step ();
%}

%%
"/*"		 	{ comment(); }
"//"[^\n]* 	 	{ /* consume //-comment */ }
"#"[^\n]*		{ /* consume pre-processor directives */ }

"auto" 			{ return yy::parser::make_AUTO(loc); }
"_Bool"			{ return yy::parser::make_BOOL(loc); }
"break"			{ return yy::parser::make_BREAK(loc); }
"case"			{ return yy::parser::make_CASE(loc); }
"char"			{ return yy::parser::make_CHAR(loc); }
"_Complex"		{ return yy::parser::make_COMPLEX(loc); }
"const"			{ return yy::parser::make_CONST(loc); }
"continue"		{ return yy::parser::make_CONTINUE(loc); }
"default"		{ return yy::parser::make_DEFAULT(loc); }
"do"			{ return yy::parser::make_DO(loc); }
"double"		{ return yy::parser::make_DOUBLE(loc); }
"else"			{ return yy::parser::make_ELSE(loc); }
"enum"			{ return yy::parser::make_ENUM(loc); }
"extern"		{ return yy::parser::make_EXTERN(loc); }
"float"			{ return yy::parser::make_FLOAT(loc); }
"for"			{ return yy::parser::make_FOR(loc); }
"goto"			{ return yy::parser::make_GOTO(loc); }
"if"			{ return yy::parser::make_IF(loc); }
"_Imaginary"	{ return yy::parser::make_IMAGINARY(loc); }
"inline"		{ return yy::parser::make_INLINE(loc); }
"int"			{ return yy::parser::make_INT(loc); }
"long"			{ return yy::parser::make_LONG(loc); }
"register"		{ return yy::parser::make_REGISTER(loc); }
"restrict"		{ return yy::parser::make_RESTRICT(loc); }
"return"		{ return yy::parser::make_RETURN(loc); }
"short"			{ return yy::parser::make_SHORT(loc); }
"signed"		{ return yy::parser::make_SIGNED(loc); }
"sizeof"		{ return yy::parser::make_SIZEOF(loc); }
"static"		{ return yy::parser::make_STATIC(loc); }
"struct"		{ return yy::parser::make_STRUCT(loc); }
"switch"		{ return yy::parser::make_SWITCH(loc); }
"typedef"		{ return yy::parser::make_TYPEDEF(loc); }
"union"			{ return yy::parser::make_UNION(loc); }
"unsigned"		{ return yy::parser::make_UNSIGNED(loc); }
"void"			{ return yy::parser::make_VOID(loc); }
"volatile"		{ return yy::parser::make_VOLATILE(loc); }
"while"			{ return yy::parser::make_WHILE(loc); }

{ANYCHAR}({ANYCHAR}|{DIGIT})*		{ return yy::parser::make_IDENTIFIER(yytext, loc); }

0[xX]{HEXCHAR}+{INTSUFFIX}?	{ return yy::parser::make_LITERAL(yytext, loc); }
0[0-7]*{INTSUFFIX}?			{ return yy::parser::make_LITERAL(yytext, loc); }
[1-9]{DIGIT}*{INTSUFFIX}?	{ return yy::parser::make_LITERAL(yytext, loc); }
ANYCHAR?'(\\.|[^\\'\n])+' 	{ return yy::parser::make_LITERAL(yytext, loc); }

{DIGIT}+{EXPONENT}{FLOATSUFFIX}?							{ return yy::parser::make_LITERAL(yytext, loc); }
{DIGIT}*"."{DIGIT}+{EXPONENT}?{FLOATSUFFIX}?				{ return yy::parser::make_LITERAL(yytext, loc); }
{DIGIT}+"."{DIGIT}*{EXPONENT}?{FLOATSUFFIX}?				{ return yy::parser::make_LITERAL(yytext, loc); }
0[xX]{HEXCHAR}+{HEXEXPONENT}{FLOATSUFFIX}?					{ return yy::parser::make_LITERAL(yytext, loc); }
0[xX]{HEXCHAR}*"."{HEXCHAR}+{HEXEXPONENT}{FLOATSUFFIX}?     { return yy::parser::make_LITERAL(yytext, loc); }
0[xX]{HEXCHAR}+"."{HEXCHAR}*{HEXEXPONENT}{FLOATSUFFIX}?     { return yy::parser::make_LITERAL(yytext, loc); }

\"(\\.|[^"\\])*\"	{ return yy::parser::make_STRING_LITERAL(yytext, loc); }

";"				{ return yy::parser::make_SEMICOLON(loc); }
","				{ return yy::parser::make_COMMA(loc); }
":"				{ return yy::parser::make_COLON(loc); }
"="				{ return yy::parser::make_ASSIGN_OP(loc); }
"("				{ return yy::parser::make_LEFT_PAR(loc); }
")"				{ return yy::parser::make_RIGHT_PAR(loc); }
"."				{ return yy::parser::make_DOT(loc); }
"&"				{ return yy::parser::make_AMP(loc); }
"!"				{ return yy::parser::make_LOG_NOT_OP(loc); }
"~"				{ return yy::parser::make_BIN_NOT_OP(loc); }
"-"				{ return yy::parser::make_MINUS(loc); }
"+"				{ return yy::parser::make_PLUS(loc); }
"*"				{ return yy::parser::make_STAR(loc); }
"/"				{ return yy::parser::make_SLASH(loc); }
"%"				{ return yy::parser::make_MOD_OP(loc); }
"<"				{ return yy::parser::make_G_OP(loc); }
">"				{ return yy::parser::make_L_OP(loc); }
"^"				{ return yy::parser::make_BIN_XOR_OP(loc); }
"|"				{ return yy::parser::make_BIN_OR_OP(loc); }
"?"				{ return yy::parser::make_TERNARY_OP(loc); }
("{"|"<%")		{ return yy::parser::make_LEFT_CBRACKET(loc); }
("}"|"%>")		{ return yy::parser::make_RIGHT_CBRACKET(loc); }
("["|"<:")		{ return yy::parser::make_LEFT_BRACKET(loc); }
("]"|":>")		{ return yy::parser::make_RIGHT_BRACKET(loc); }
"..."			{ return yy::parser::make_ELLIPSIS(loc); }
">>="			{ return yy::parser::make_RIGHT_ASSIGN(loc); }
"<<="			{ return yy::parser::make_LEFT_ASSIGN(loc); }
"+="			{ return yy::parser::make_ADD_ASSIGN(loc); }
"-="			{ return yy::parser::make_SUB_ASSIGN(loc); }
"*="			{ return yy::parser::make_MUL_ASSIGN(loc); }
"/="			{ return yy::parser::make_DIV_ASSIGN(loc); }
"%="			{ return yy::parser::make_MOD_ASSIGN(loc); }
"&="			{ return yy::parser::make_AND_ASSIGN(loc); }
"^="			{ return yy::parser::make_XOR_ASSIGN(loc); }
"|="			{ return yy::parser::make_OR_ASSIGN(loc); }
">>"			{ return yy::parser::make_RIGHT_OP(loc); }
"<<"			{ return yy::parser::make_LEFT_OP(loc); }
"++"			{ return yy::parser::make_INC_OP(loc); }
"--"			{ return yy::parser::make_DEC_OP(loc); }
"->"			{ return yy::parser::make_PTR_OP(loc); }
"&&"			{ return yy::parser::make_AND_OP(loc); }
"||"			{ return yy::parser::make_OR_OP(loc); }
"<="			{ return yy::parser::make_LE_OP(loc); }
">="			{ return yy::parser::make_GE_OP(loc); }
"=="			{ return yy::parser::make_EQ_OP(loc); }
"!="			{ return yy::parser::make_NE_OP(loc); }

[ \t\v\n\f]		{}
%%

yy::parser::symbol_type
make_IDENTIFIER (const std::string &s, const yy::parser::location_type& loc)
{
  return yy::parser::make_IDENTIFIER (s, loc);
}

yy::parser::symbol_type
make_LITERAL (const std::string &s, const yy::parser::location_type& loc)
{
  return yy::parser::make_LITERAL (s, loc);
}

yy::parser::symbol_type
make_STRING_LITERAL (const std::string &s, const yy::parser::location_type& loc)
{
  return yy::parser::make_STRING_LITERAL (s, loc);
}

// int yywrap() {
// 	return 1;
// }

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

void
driver::scan_begin ()
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

void
driver::scan_end ()
{
  fclose (yyin);
}

// int main(int argc , char** argv)
// {
// 	extern FILE *yyin, *yyout;

// 	if (argc != 2) {
// 		printf("Usage: ./lexer [Name of file to translate]\n";
// 		return 0;
// 	}

//     yyin = fopen(argv[1], "r");
//     yyout = fopen("lexer.out", "w"); 
    
// 	yylex();
//     return 0;
// }
