DIGIT			[0-9]
ANYCHAR			[a-zA-Z_]
HEXCHAR			[a-fA-F0-9]
EXPONENT		([Ee][+-]?{DIGIT}+)
HEXEXPONENT   	([Pp][+-]?{DIGIT}+)
FLOATSUFFIX		(f|F|l|L)
INTSUFFIX       ((u|U)|(u|U)?(l|L|ll|LL)|(l|L|ll|LL)(u|U))

%{
#include <stdio.h>

void count(void);
void comment(void);
void position(void);
%}

%%
"/*"		 	{ comment(); }
"//"[^\n]* 	 	{ /* consume //-comment */ }
"#"[^\n]*		{ /* consume pre-processor directives */ }

"auto" 			{ fprintf(yyout, "AUTO\n"); }
"_Bool"			{ fprintf(yyout, "BOOL\n"); }
"break"			{ fprintf(yyout, "BREAK\n"); }
"case"			{ fprintf(yyout, "CASE\n"); }
"char"			{ fprintf(yyout, "CHAR\n"); }
"_Complex"		{ fprintf(yyout, "COMPLEX\n"); }
"const"			{ fprintf(yyout, "CONST\n"); }
"continue"		{ fprintf(yyout, "CONTINUE\n"); }
"default"		{ fprintf(yyout, "DEFAULT\n"); }
"do"			{ fprintf(yyout, "DO\n"); }
"double"		{ fprintf(yyout, "DOUBLE\n"); }
"else"			{ fprintf(yyout, "ELSE\n"); }
"enum"			{ fprintf(yyout, "ENUM\n"); }
"extern"		{ fprintf(yyout, "EXTERN\n"); }
"float"			{ fprintf(yyout, "FLOAT\n"); }
"for"			{ fprintf(yyout, "FOR\n"); }
"goto"			{ fprintf(yyout, "GOTO\n"); }
"if"			{ fprintf(yyout, "IF\n"); }
"_Imaginary"	{ fprintf(yyout, "IMAGINARY\n"); }
"inline"		{ fprintf(yyout, "INLINE\n"); }
"int"			{ fprintf(yyout, "INT\n"); }
"long"			{ fprintf(yyout, "LONG\n"); }
"register"		{ fprintf(yyout, "REGISTER\n"); }
"restrict"		{ fprintf(yyout, "RESTRICT\n"); }
"return"		{ fprintf(yyout, "RETURN\n"); }
"short"			{ fprintf(yyout, "SHORT\n"); }
"signed"		{ fprintf(yyout, "SIGNED\n"); }
"sizeof"		{ fprintf(yyout, "SIZEOF\n"); }
"static"		{ fprintf(yyout, "STATIC\n"); }
"struct"		{ fprintf(yyout, "STRUCT\n"); }
"switch"		{ fprintf(yyout, "SWITCH\n"); }
"typedef"		{ fprintf(yyout, "TYPEDEF\n"); }
"union"			{ fprintf(yyout, "UNION\n"); }
"unsigned"		{ fprintf(yyout, "UNSIGNED\n"); }
"void"			{ fprintf(yyout, "VOID\n"); }
"volatile"		{ fprintf(yyout, "VOLATILE\n"); }
"while"			{ fprintf(yyout, "WHILE\n"); }

{ANYCHAR}({ANYCHAR}|{DIGIT})*		{ fprintf(yyout, "IDENTIFIER %s\n", yytext); }

0[xX]{HEXCHAR}+{INTSUFFIX}?	{ fprintf(yyout, "LITERAL %s\n", yytext); }
0[0-7]*{INTSUFFIX}?			{ fprintf(yyout, "LITERAL %s\n", yytext); }
[1-9]{DIGIT}*{INTSUFFIX}?	{ fprintf(yyout, "LITERAL %s\n", yytext); }
ANYCHAR?'(\\.|[^\\'\n])+' 	{ fprintf(yyout, "LITERAL %s\n", yytext); }

{DIGIT}+{EXPONENT}{FLOATSUFFIX}?							{ fprintf(yyout, "LITERAL %s\n", yytext); }
{DIGIT}*"."{DIGIT}+{EXPONENT}?{FLOATSUFFIX}?				{ fprintf(yyout, "LITERAL %s\n", yytext); }
{DIGIT}+"."{DIGIT}*{EXPONENT}?{FLOATSUFFIX}?				{ fprintf(yyout, "LITERAL %s\n", yytext); }
0[xX]{HEXCHAR}+{HEXEXPONENT}{FLOATSUFFIX}?					{ fprintf(yyout, "LITERAL %s\n", yytext); }
0[xX]{HEXCHAR}*"."{HEXCHAR}+{HEXEXPONENT}{FLOATSUFFIX}?     { fprintf(yyout, "LITERAL %s\n", yytext); }
0[xX]{HEXCHAR}+"."{HEXCHAR}*{HEXEXPONENT}{FLOATSUFFIX}?     { fprintf(yyout, "LITERAL %s\n", yytext); }

\"(\\.|[^"\\])*\"	{ fprintf(yyout, "STRING_LITERAL %s\n", yytext); }

";"				{ fprintf(yyout, "SEMICOLON\n"); }
","				{ fprintf(yyout, "COMMA\n"); }
":"				{ fprintf(yyout, "COLON\n"); }
"="				{ fprintf(yyout, "ASSIGN_OP\n"); }
"("				{ fprintf(yyout, "LEFT_PAR\n"); }
")"				{ fprintf(yyout, "RIGHT_PAR\n"); }
"."				{ fprintf(yyout, "DOT\n"); }
"&"				{ fprintf(yyout, "AMP\n"); }
"!"				{ fprintf(yyout, "LOG_NOT_OP\n"); }
"~"				{ fprintf(yyout, "BIN_NOT_OP\n"); }
"-"				{ fprintf(yyout, "MINUS\n"); }
"+"				{ fprintf(yyout, "PLUS\n"); }
"*"				{ fprintf(yyout, "STAR\n"); }
"/"				{ fprintf(yyout, "BACK_SLASH\n"); }
"%"				{ fprintf(yyout, "MOD_OP\n"); }
"<"				{ fprintf(yyout, "G_OP\n"); }
">"				{ fprintf(yyout, "L_OP\n"); }
"^"				{ fprintf(yyout, "BIN_XOR_OP\n"); }
"|"				{ fprintf(yyout, "BIN_OR_OP\n"); }
"?"				{ fprintf(yyout, "TERNARY_OP\n"); }
("{"|"<%")		{ fprintf(yyout, "LEFT_CBRACKET\n"); }
("}"|"%>")		{ fprintf(yyout, "RIGHT_CBRACKET\n"); }
("["|"<:")		{ fprintf(yyout, "LEFT_BRACKET\n"); }
("]"|":>")		{ fprintf(yyout, "RIGHT_BRACKET\n"); }
"..."			{ fprintf(yyout, "ELLIPSIS\n"); }
">>="			{ fprintf(yyout, "RIGHT_ASSIGN\n"); }
"<<="			{ fprintf(yyout, "LEFT_ASSIGN\n"); }
"+="			{ fprintf(yyout, "ADD_ASSIGN\n"); }
"-="			{ fprintf(yyout, "SUB_ASSIGN\n"); }
"*="			{ fprintf(yyout, "MUL_ASSIGN\n"); }
"/="			{ fprintf(yyout, "DIV_ASSIGN\n"); }
"%="			{ fprintf(yyout, "MOD_ASSIGN\n"); }
"&="			{ fprintf(yyout, "AND_ASSIGN\n"); }
"^="			{ fprintf(yyout, "XOR_ASSIGN\n"); }
"|="			{ fprintf(yyout, "OR_ASSIGN\n"); }
">>"			{ fprintf(yyout, "RIGHT_OP\n"); }
"<<"			{ fprintf(yyout, "LEFT_OP\n"); }
"++"			{ fprintf(yyout, "INC_OP\n"); }
"--"			{ fprintf(yyout, "DEC_OP\n"); }
"->"			{ fprintf(yyout, "PTR_OP\n"); }
"&&"			{ fprintf(yyout, "AND_OP\n"); }
"||"			{ fprintf(yyout, "OR_OP\n"); }
"<="			{ fprintf(yyout, "LE_OP\n"); }
">="			{ fprintf(yyout, "GE_OP\n"); }
"=="			{ fprintf(yyout, "EQ_OP\n"); }
"!="			{ fprintf(yyout, "NE_OP\n"); }

[ \t\v\n\f]		{}
%%

int yywrap() {
	return 1;
}

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

int main(int argc , char** argv)
{
	extern FILE *yyin, *yyout;

	if (argc != 2) {
		printf("Usage: ./lexer [Name of file to translate]\n");
		return 0;
	}

    yyin = fopen(argv[1], "r");
    yyout = fopen("lexer.out", "w"); 
    
	yylex();
    return 0;
}
