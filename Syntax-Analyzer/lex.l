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

"auto" 			{ position(); fprintf(yyout, "AUTO\n"); }
"_Bool"			{ position(); fprintf(yyout, "BOOL\n"); }
"break"			{ position(); fprintf(yyout, "BREAK\n"); }
"case"			{ position(); fprintf(yyout, "CASE\n"); }
"char"			{ position(); fprintf(yyout, "CHAR\n"); }
"_Complex"		{ position(); fprintf(yyout, "COMPLEX\n"); }
"const"			{ position(); fprintf(yyout, "CONST\n"); }
"continue"		{ position(); fprintf(yyout, "CONTINUE\n"); }
"default"		{ position(); fprintf(yyout, "DEFAULT\n"); }
"do"			{ position(); fprintf(yyout, "DO\n"); }
"double"		{ position(); fprintf(yyout, "DOUBLE\n"); }
"else"			{ position(); fprintf(yyout, "ELSE\n"); }
"enum"			{ position(); fprintf(yyout, "ENUM\n"); }
"extern"		{ position(); fprintf(yyout, "EXTERN\n"); }
"float"			{ position(); fprintf(yyout, "FLOAT\n"); }
"for"			{ position(); fprintf(yyout, "FOR\n"); }
"goto"			{ position(); fprintf(yyout, "GOTO\n"); }
"if"			{ position(); fprintf(yyout, "IF\n"); }
"_Imaginary"	{ position(); fprintf(yyout, "IMAGINARY\n"); }
"inline"		{ position(); fprintf(yyout, "INLINE\n"); }
"int"			{ position(); fprintf(yyout, "INT\n"); }
"long"			{ position(); fprintf(yyout, "LONG\n"); }
"register"		{ position(); fprintf(yyout, "REGISTER\n"); }
"restrict"		{ position(); fprintf(yyout, "RESTRICT\n"); }
"return"		{ position(); fprintf(yyout, "RETURN\n"); }
"short"			{ position(); fprintf(yyout, "SHORT\n"); }
"signed"		{ position(); fprintf(yyout, "SIGNED\n"); }
"sizeof"		{ position(); fprintf(yyout, "SIZEOF\n"); }
"static"		{ position(); fprintf(yyout, "STATIC\n"); }
"struct"		{ position(); fprintf(yyout, "STRUCT\n"); }
"switch"		{ position(); fprintf(yyout, "SWITCH\n"); }
"typedef"		{ position(); fprintf(yyout, "TYPEDEF\n"); }
"union"			{ position(); fprintf(yyout, "UNION\n"); }
"unsigned"		{ position(); fprintf(yyout, "UNSIGNED\n"); }
"void"			{ position(); fprintf(yyout, "VOID\n"); }
"volatile"		{ position(); fprintf(yyout, "VOLATILE\n"); }
"while"			{ position(); fprintf(yyout, "WHILE\n"); }

{ANYCHAR}({ANYCHAR}|{DIGIT})*		{ position(); fprintf(yyout, "IDENTIFIER %s\n", yytext); }

0[xX]{HEXCHAR}+{INTSUFFIX}?	{ position(); fprintf(yyout, "LITERAL %s\n", yytext); }
0[0-7]*{INTSUFFIX}?			{ position(); fprintf(yyout, "LITERAL %s\n", yytext); }
[1-9]{DIGIT}*{INTSUFFIX}?	{ position(); fprintf(yyout, "LITERAL %s\n", yytext); }
ANYCHAR?'(\\.|[^\\'\n])+' 	{ position(); fprintf(yyout, "LITERAL %s\n", yytext); }

{DIGIT}+{EXPONENT}{FLOATSUFFIX}?							{ position(); fprintf(yyout, "LITERAL %s\n", yytext); }
{DIGIT}*"."{DIGIT}+{EXPONENT}?{FLOATSUFFIX}?				{ position(); fprintf(yyout, "LITERAL %s\n", yytext); }
{DIGIT}+"."{DIGIT}*{EXPONENT}?{FLOATSUFFIX}?				{ position(); fprintf(yyout, "LITERAL %s\n", yytext); }
0[xX]{HEXCHAR}+{HEXEXPONENT}{FLOATSUFFIX}?					{ position(); fprintf(yyout, "LITERAL %s\n", yytext); }
0[xX]{HEXCHAR}*"."{HEXCHAR}+{HEXEXPONENT}{FLOATSUFFIX}?     { position(); fprintf(yyout, "LITERAL %s\n", yytext); }
0[xX]{HEXCHAR}+"."{HEXCHAR}*{HEXEXPONENT}{FLOATSUFFIX}?     { position(); fprintf(yyout, "LITERAL %s\n", yytext); }

ANYCHAR?\"(\\.|[^\\"\n])*\" { position(); fprintf(yyout, "STRING_LITERAL %s\n", yytext); }

";"|","|":"|"="|"("|")"|"."|"&"|"!"|"~"|"-"|"+"|"*"|"/"|"%"|"<"|">"|"^"|"|"|"?"	{ position(); fprintf(yyout, yytext); }
("{"|"<%")		{ position(); fprintf(yyout, "{\n"); }
("}"|"%>")		{ position(); fprintf(yyout, "}\n"); }
("["|"<:")		{ position(); fprintf(yyout, "[\n"); }
("]"|":>")		{ position(); fprintf(yyout, "]\n"); }
"..."			{ position(); fprintf(yyout, "ELLIPSIS\n"); }
">>="			{ position(); fprintf(yyout, "RIGHT_ASSIGN\n"); }
"<<="			{ position(); fprintf(yyout, "LEFT_ASSIGN\n"); }
"+="			{ position(); fprintf(yyout, "ADD_ASSIGN\n"); }
"-="			{ position(); fprintf(yyout, "SUB_ASSIGN\n"); }
"*="			{ position(); fprintf(yyout, "MUL_ASSIGN\n"); }
"/="			{ position(); fprintf(yyout, "DIV_ASSIGN\n"); }
"%="			{ position(); fprintf(yyout, "MOD_ASSIGN\n"); }
"&="			{ position(); fprintf(yyout, "AND_ASSIGN\n"); }
"^="			{ position(); fprintf(yyout, "XOR_ASSIGN\n"); }
"|="			{ position(); fprintf(yyout, "OR_ASSIGN\n"); }
">>"			{ position(); fprintf(yyout, "RIGHT_OP\n"); }
"<<"			{ position(); fprintf(yyout, "LEFT_OP\n"); }
"++"			{ position(); fprintf(yyout, "INC_OP\n"); }
"--"			{ position(); fprintf(yyout, "DEC_OP\n"); }
"->"			{ position(); fprintf(yyout, "PTR_OP\n"); }
"&&"			{ position(); fprintf(yyout, "AND_OP\n"); }
"||"			{ position(); fprintf(yyout, "OR_OP\n"); }
"<="			{ position(); fprintf(yyout, "LE_OP\n"); }
">="			{ position(); fprintf(yyout, "GE_OP\n"); }
"=="			{ position(); fprintf(yyout, "EQ_OP\n"); }
"!="			{ position(); fprintf(yyout, "NE_OP\n"); }

[ \t\v\n\f]		{ position(); }
%%

int column = 0;

int yywrap() {
	return 1;
}

void position(void)
{
	int i;

	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			column = 0;
		else if (yytext[i] == '\t')
			column += 8 - (column % 8);
		else
			column++;

	ECHO;
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
	perror("unterminated comment");
}

int main( int argc , char** argv)
{
	extern FILE *yyin, *yyout;
    yyin = fopen("lexInput.c", "r");
    yyout = fopen("lexOutput.txt", "w"); 
    yylex();
    return 0;
}
