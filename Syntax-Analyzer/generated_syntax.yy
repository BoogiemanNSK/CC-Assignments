%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.4"
%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
  # include <string>
  # include "astNode.hpp"
  class driver;
}

// The parsing context.
%param { driver& drv }

%code {
# include "driver.hh"
}

%locations
%define parse.trace
%define parse.error verbose

// Tokens

// Keywords
%token AUTO
%token BOOL
%token BREAK
%token CASE
%token CHAR
%token COMPLEX
%token CONST
%token CONTINUE
%token DEFAULT
%token DO
%token DOUBLE
%token ELSE
%token ENUM
%token EXTERN
%token FLOAT
%token FOR
%token GOTO
%token IF
%token IMAGINARY
%token INLINE
%token INT
%token LONG
%token REGISTER
%token RESTRICT
%token RETURN
%token SHORT
%token SIGNED
%token SIZEOF
%token STATIC
%token STRUCT
%token SWITCH
%token TYPEDEF
%token UNION
%token UNSIGNED
%token VOID
%token VOLATILE
%token WHILE

%token <std::string> IDENTIFIER

%token <std::string> LITERAL // Numeric literal

%token <std::string> STRING_LITERAL  // String literal

// // Delimeters
// %token ;
// %token ,
// %token :
// %token (
// %token )
// %token .
// %token {
// %token }
// %token [
// %token ]

// // Operators
// %token =
// %token ?
// %token -
// %token +
// %token *
// %token /
// %token %
// %token <
// %token >
// %token ^
// %token &
// %token !
// %token ~
// %token |

// Delimeters

%token  SEMICOLON ";"
%token  COMMA ","
%token  COLON ":"
%token  LEFT_PAR "("
%token  RIGHT_PAR ")"
%token  DOT "."
%token  LEFT_CBRACKET "{"
%token  RIGHT_CBRACKET "}"
%token  LEFT_BRACKET "["
%token  RIGHT_BRACKET "]"

// Operators

%token  ASSIGN_OP "="
%token  AMP "&"
%token  LOG_NOT_OP "!"
%token  BIN_NOT_OP "~"
%token  MINUS "-"
%token  PLUS "+"
%token  STAR "*"
%token  SLASH "/"
%token  MOD_OP "%"
%token  G_OP "<"
%token  L_OP ">"
%token  BIN_XOR_OP "^"
%token  BIN_OR_OP "|"
%token  TERNARY_OP "?"


%token  ELLIPSIS "..."
%token  RIGHT_ASSIGN ">>="
%token  LEFT_ASSIGN "<<="
%token  ADD_ASSIGN "+="
%token  SUB_ASSIGN "-="
%token  MUL_ASSIGN "*="
%token  DIV_ASSIGN "/="
%token  MOD_ASSIGN "%="
%token  AND_ASSIGN "&="
%token  XOR_ASSIGN "^="
%token  OR_ASSIGN "|="
%token  RIGHT_OP ">>"
%token  LEFT_OP "<<"
%token  INC_OP "++"
%token  DEC_OP "--"
%token  PTR_OP "->"
%token  AND_OP "&&"
%token  OR_OP "||"
%token  LE_OP "<="
%token  GE_OP ">="
%token  EQ_OP "=="
%token  NE_OP "!="

%start translation_unit
// %start primary_expression

// Grammar
%%


%type <AstNodePtr> primary_expression;
%type <AstNodePtr> postfix_expression;
%type <AstNodePtr> argument_expression_list;
%type <AstNodePtr> unary_expression;
%type <AstNodePtr> unary_operator;
%type <AstNodePtr> cast_expression;
%type <AstNodePtr> multiplicative_expression;
%type <AstNodePtr> additive_expression;
%type <AstNodePtr> shift_expression;
%type <AstNodePtr> relational_expression;
%type <AstNodePtr> equality_expression;
%type <AstNodePtr> and_expression;
%type <AstNodePtr> exclusive_or_expression;
%type <AstNodePtr> inclusive_or_expression;
%type <AstNodePtr> logical_and_expression;
%type <AstNodePtr> logical_or_expression;
%type <AstNodePtr> conditional_expression;
%type <AstNodePtr> assignment_expression;
%type <AstNodePtr> assignment_operator;
%type <AstNodePtr> expression;
%type <AstNodePtr> constant_expression;
%type <AstNodePtr> declaration;
%type <AstNodePtr> declaration_specifiers; 
%type <AstNodePtr> storage_class_specifier;
%type <AstNodePtr> init_declarator_list;
%type <AstNodePtr> init_declarator;
%type <AstNodePtr> initializer;
%type <AstNodePtr> initializer_list;
%type <AstNodePtr> designation;
%type <AstNodePtr> designator_list;
%type <AstNodePtr> designator;
%type <AstNodePtr> declarator; 
%type <AstNodePtr> pointer;
%type <AstNodePtr> direct_declarator; 
%type <AstNodePtr> type_qualifier_list;
%type <AstNodePtr> type_qualifier;
%type <AstNodePtr> parameter_type_list; 
%type <AstNodePtr> parameter_list;
%type <AstNodePtr> parameter_declaration;
%type <AstNodePtr> function_specifier; 
%type <AstNodePtr> type_specifier;
%type <AstNodePtr> struct_or_union_specifier;
%type <AstNodePtr> struct_or_union;
%type <AstNodePtr> struct_declaration_list;
%type <AstNodePtr> struct_declaration;
%type <AstNodePtr> struct_declarator_list;
%type <AstNodePtr> struct_declarator;
%type <AstNodePtr> specifier_qualifier_list;
%type <AstNodePtr> enum_specifier; 
%type <AstNodePtr> enumerator_list;
%type <AstNodePtr> enumerator; 
%type <AstNodePtr> type_name;
%type <AstNodePtr> abstract_declarator;
%type <AstNodePtr> direct_abstract_declarator;
%type <AstNodePtr> statement;
%type <AstNodePtr> labeled_statement;
%type <AstNodePtr> compound_statement;
%type <AstNodePtr> block_item_list;
%type <AstNodePtr> block_item;
%type <AstNodePtr> expression_statement;
%type <AstNodePtr> selection_statement;
%type <AstNodePtr> iteration_statement;
%type <AstNodePtr> jump_statement; 
%type <AstNodePtr> translation_unit;
%type <AstNodePtr> external_declaration;
%type <AstNodePtr> function_definition;
%type <AstNodePtr> declaration_list; 
%type <AstNodePtr> identifier_list;




primary_expression:
   IDENTIFIER {$$ = new AstNode(string("primary_expression"), { new AstNode(string("identifier_IDENTIFIER"), {}) });} 
|   LITERAL {$$ = new AstNode(string("primary_expression"), { new AstNode(string("literal_LITERAL"), {}) });} 
|   STRING_LITERAL {$$ = new AstNode(string("primary_expression"), { new AstNode(string("string_literal_STRING_LITERAL"), {}) });} 
|   LEFT_PAR expression RIGHT_PAR {$$ = new AstNode(string("primary_expression"), { new AstNode(string("delimeters_LEFT_PAR"), {}),$2,new AstNode(string("delimeters_RIGHT_PAR"), {}) });}
;

postfix_expression:
   primary_expression {$$ = new AstNode(string("postfix_expression"), { $1 });} 
|   postfix_expression LEFT_BRACKET expression RIGHT_BRACKET {$1->children.push_back($1);$1->children.push_back($3);$1->children.push_back(new AstNode(string("delimeters_RIGHT_BRACKET"), {}));$$ = $1;} 
|   postfix_expression LEFT_PAR argument_expression_list RIGHT_PAR {$1->children.push_back($1);$1->children.push_back($3);$1->children.push_back(new AstNode(string("delimeters_RIGHT_PAR"), {}));$$ = $1;} 
|   postfix_expression LEFT_PAR RIGHT_PAR {$1->children.push_back($1);$1->children.push_back(new AstNode(string("delimeters_RIGHT_PAR"), {}));$$ = $1;} 
|   postfix_expression DOT IDENTIFIER {$1->children.push_back($1);$1->children.push_back(new AstNode(string("identifier_IDENTIFIER"), {}));$$ = $1;} 
|   postfix_expression PTR_OP IDENTIFIER {$1->children.push_back($1);$1->children.push_back(new AstNode(string("identifier_IDENTIFIER"), {}));$$ = $1;} 
|   postfix_expression INC_OP {$1->children.push_back($1);$$ = $1;} 
|   postfix_expression DEC_OP {$1->children.push_back($1);$$ = $1;} 
|   LEFT_PAR type_name RIGHT_PAR LEFT_CBRACKET initializer_list RIGHT_CBRACKET {$$ = new AstNode(string("postfix_expression"), { new AstNode(string("delimeters_LEFT_PAR"), {}),$2,new AstNode(string("delimeters_RIGHT_PAR"), {}),new AstNode(string("delimeters_LEFT_CBRACKET"), {}),$5,new AstNode(string("delimeters_RIGHT_CBRACKET"), {}) });} 
|   LEFT_PAR type_name RIGHT_PAR LEFT_CBRACKET initializer_list COMMA RIGHT_CBRACKET {$$ = new AstNode(string("postfix_expression"), { new AstNode(string("delimeters_LEFT_PAR"), {}),$2,new AstNode(string("delimeters_RIGHT_PAR"), {}),new AstNode(string("delimeters_LEFT_CBRACKET"), {}),$5,new AstNode(string("delimeters_COMMA"), {}),new AstNode(string("delimeters_RIGHT_CBRACKET"), {}) });}
;

argument_expression_list:
   IDENTIFIER {$$ = new AstNode(string("argument_expression_list"), { new AstNode(string("identifier_IDENTIFIER"), {}) });} 
|   IDENTIFIER COMMA argument_expression_list {$3->children.push_back(new AstNode(string("identifier_IDENTIFIER"), {}));$3->children.push_back(new AstNode(string("delimeters_COMMA"), {}));$3->children.push_back($3);$$ = $3;}
;

unary_expression:
   postfix_expression {$$ = new AstNode(string("unary_expression"), { $1 });} 
|   INC_OP unary_expression {$2->children.push_back(new AstNode(string("operators_INC_OP"), {}));$2->children.push_back($2);$$ = $2;} 
|   DEC_OP unary_expression {$2->children.push_back(new AstNode(string("operators_DEC_OP"), {}));$2->children.push_back($2);$$ = $2;} 
|   unary_operator cast_expression {$$ = new AstNode(string("unary_expression"), { $1,$2 });} 
|   SIZEOF unary_expression {$2->children.push_back(new AstNode(string("keywords_SIZEOF"), {}));$2->children.push_back($2);$$ = $2;} 
|   SIZEOF LEFT_PAR type_name RIGHT_PAR {$$ = new AstNode(string("unary_expression"), { new AstNode(string("keywords_SIZEOF"), {}),new AstNode(string("delimeters_LEFT_PAR"), {}),$3,new AstNode(string("delimeters_RIGHT_PAR"), {}) });}
;

unary_operator:
   AMP {$$ = new AstNode(string("unary_operator"), { new AstNode(string("operators_AMP"), {}) });} 
|   STAR {$$ = new AstNode(string("unary_operator"), { new AstNode(string("operators_STAR"), {}) });} 
|   PLUS {$$ = new AstNode(string("unary_operator"), { new AstNode(string("operators_PLUS"), {}) });} 
|   MINUS {$$ = new AstNode(string("unary_operator"), { new AstNode(string("operators_MINUS"), {}) });} 
|   BIN_NOT_OP {$$ = new AstNode(string("unary_operator"), { new AstNode(string("operators_BIN_NOT_OP"), {}) });} 
|   LOG_NOT_OP {$$ = new AstNode(string("unary_operator"), { new AstNode(string("operators_LOG_NOT_OP"), {}) });}
;

cast_expression:
   unary_expression {$$ = new AstNode(string("cast_expression"), { $1 });} 
|   LEFT_PAR type_name RIGHT_PAR cast_expression {$4->children.push_back(new AstNode(string("delimeters_LEFT_PAR"), {}));$4->children.push_back($2);$4->children.push_back(new AstNode(string("delimeters_RIGHT_PAR"), {}));$4->children.push_back($4);$$ = $4;}
;

multiplicative_expression:
   cast_expression {$$ = new AstNode(string("multiplicative_expression"), { $1 });} 
|   multiplicative_expression STAR cast_expression {$1->children.push_back($1);$1->children.push_back($3);$$ = $1;} 
|   multiplicative_expression SLASH cast_expression {$1->children.push_back($1);$1->children.push_back($3);$$ = $1;} 
|   multiplicative_expression MOD_OP cast_expression {$1->children.push_back($1);$1->children.push_back($3);$$ = $1;}
;

additive_expression:
   multiplicative_expression {$$ = new AstNode(string("additive_expression"), { $1 });} 
|   additive_expression PLUS multiplicative_expression {$1->children.push_back($1);$1->children.push_back($3);$$ = $1;} 
|   additive_expression MINUS multiplicative_expression {$1->children.push_back($1);$1->children.push_back($3);$$ = $1;}
;

shift_expression:
   additive_expression {$$ = new AstNode(string("shift_expression"), { $1 });} 
|   shift_expression LEFT_OP additive_expression {$1->children.push_back($1);$1->children.push_back($3);$$ = $1;} 
|   shift_expression RIGHT_OP additive_expression {$1->children.push_back($1);$1->children.push_back($3);$$ = $1;}
;

relational_expression:
   shift_expression {$$ = new AstNode(string("relational_expression"), { $1 });} 
|   relational_expression L_OP shift_expression {$1->children.push_back($1);$1->children.push_back($3);$$ = $1;} 
|   relational_expression G_OP shift_expression {$1->children.push_back($1);$1->children.push_back($3);$$ = $1;} 
|   relational_expression LE_OP shift_expression {$1->children.push_back($1);$1->children.push_back($3);$$ = $1;} 
|   relational_expression GE_OP shift_expression {$1->children.push_back($1);$1->children.push_back($3);$$ = $1;}
;

equality_expression:
   relational_expression {$$ = new AstNode(string("equality_expression"), { $1 });} 
|   equality_expression EQ_OP relational_expression {$1->children.push_back($1);$1->children.push_back($3);$$ = $1;} 
|   equality_expression NE_OP relational_expression {$1->children.push_back($1);$1->children.push_back($3);$$ = $1;}
;

and_expression:
   equality_expression {$$ = new AstNode(string("and_expression"), { $1 });} 
|   and_expression AMP equality_expression {$1->children.push_back($1);$1->children.push_back($3);$$ = $1;}
;

exclusive_or_expression:
   and_expression {$$ = new AstNode(string("exclusive_or_expression"), { $1 });} 
|   exclusive_or_expression BIN_XOR_OP and_expression {$1->children.push_back($1);$1->children.push_back($3);$$ = $1;}
;

inclusive_or_expression:
   exclusive_or_expression {$$ = new AstNode(string("inclusive_or_expression"), { $1 });} 
|   inclusive_or_expression BIN_OR_OP exclusive_or_expression {$1->children.push_back($1);$1->children.push_back($3);$$ = $1;}
;

logical_and_expression:
   inclusive_or_expression {$$ = new AstNode(string("logical_and_expression"), { $1 });} 
|   logical_and_expression AND_OP inclusive_or_expression {$1->children.push_back($1);$1->children.push_back($3);$$ = $1;}
;

logical_or_expression:
   logical_and_expression {$$ = new AstNode(string("logical_or_expression"), { $1 });} 
|   logical_or_expression OR_OP logical_and_expression {$1->children.push_back($1);$1->children.push_back($3);$$ = $1;}
;

conditional_expression:
   logical_or_expression {$$ = new AstNode(string("conditional_expression"), { $1 });} 
|   logical_or_expression TERNARY_OP expression COLON conditional_expression {$5->children.push_back($1);$5->children.push_back(new AstNode(string("operators_TERNARY_OP"), {}));$5->children.push_back($3);$5->children.push_back(new AstNode(string("delimeters_COLON"), {}));$5->children.push_back($5);$$ = $5;}
;

assignment_expression:
   conditional_expression {$$ = new AstNode(string("assignment_expression"), { $1 });} 
|   unary_expression assignment_operator assignment_expression {$3->children.push_back($1);$3->children.push_back($2);$3->children.push_back($3);$$ = $3;}
;

assignment_operator:
   ASSIGN_OP {$$ = new AstNode(string("assignment_operator"), { new AstNode(string("operators_ASSIGN_OP"), {}) });} 
|   MUL_ASSIGN {$$ = new AstNode(string("assignment_operator"), { new AstNode(string("operators_MUL_ASSIGN"), {}) });} 
|   DIV_ASSIGN {$$ = new AstNode(string("assignment_operator"), { new AstNode(string("operators_DIV_ASSIGN"), {}) });} 
|   MOD_ASSIGN {$$ = new AstNode(string("assignment_operator"), { new AstNode(string("operators_MOD_ASSIGN"), {}) });} 
|   ADD_ASSIGN {$$ = new AstNode(string("assignment_operator"), { new AstNode(string("operators_ADD_ASSIGN"), {}) });} 
|   SUB_ASSIGN {$$ = new AstNode(string("assignment_operator"), { new AstNode(string("operators_SUB_ASSIGN"), {}) });} 
|   LEFT_ASSIGN {$$ = new AstNode(string("assignment_operator"), { new AstNode(string("operators_LEFT_ASSIGN"), {}) });} 
|   RIGHT_ASSIGN {$$ = new AstNode(string("assignment_operator"), { new AstNode(string("operators_RIGHT_ASSIGN"), {}) });} 
|   AND_ASSIGN {$$ = new AstNode(string("assignment_operator"), { new AstNode(string("operators_AND_ASSIGN"), {}) });} 
|   XOR_ASSIGN {$$ = new AstNode(string("assignment_operator"), { new AstNode(string("operators_XOR_ASSIGN"), {}) });} 
|   OR_ASSIGN {$$ = new AstNode(string("assignment_operator"), { new AstNode(string("operators_OR_ASSIGN"), {}) });}
;

expression:
   assignment_expression {$$ = new AstNode(string("expression"), { $1 });} 
|   expression COMMA assignment_expression {$1->children.push_back($1);$1->children.push_back($3);$$ = $1;}
;

constant_expression:
   conditional_expression {$$ = new AstNode(string("constant_expression"), { $1 });}
;

declaration:
   declaration_specifiers SEMICOLON {$$ = new AstNode(string("declaration"), { $1,new AstNode(string("delimeters_SEMICOLON"), {}) });} 
|   declaration_specifiers init_declarator_list SEMICOLON {$$ = new AstNode(string("declaration"), { $1,$2,new AstNode(string("delimeters_SEMICOLON"), {}) });}
;

declaration_specifiers:
   storage_class_specifier {$$ = new AstNode(string("declaration_specifiers"), { $1 });} 
|   storage_class_specifier declaration_specifiers {$2->children.push_back($1);$2->children.push_back($2);$$ = $2;} 
|   type_specifier {$$ = new AstNode(string("declaration_specifiers"), { $1 });} 
|   type_specifier declaration_specifiers {$2->children.push_back($1);$2->children.push_back($2);$$ = $2;} 
|   type_qualifier {$$ = new AstNode(string("declaration_specifiers"), { $1 });} 
|   type_qualifier declaration_specifiers {$2->children.push_back($1);$2->children.push_back($2);$$ = $2;} 
|   function_specifier {$$ = new AstNode(string("declaration_specifiers"), { $1 });} 
|   function_specifier declaration_specifiers {$2->children.push_back($1);$2->children.push_back($2);$$ = $2;}
;

storage_class_specifier:
   EXTERN {$$ = new AstNode(string("storage_class_specifier"), { new AstNode(string("keywords_EXTERN"), {}) });} 
|   STATIC {$$ = new AstNode(string("storage_class_specifier"), { new AstNode(string("keywords_STATIC"), {}) });} 
|   AUTO {$$ = new AstNode(string("storage_class_specifier"), { new AstNode(string("keywords_AUTO"), {}) });} 
|   REGISTER {$$ = new AstNode(string("storage_class_specifier"), { new AstNode(string("keywords_REGISTER"), {}) });}
;

init_declarator_list:
   init_declarator {$$ = new AstNode(string("init_declarator_list"), { $1 });} 
|   init_declarator_list COMMA init_declarator {$1->children.push_back($1);$1->children.push_back($3);$$ = $1;}
;

init_declarator:
   declarator {$$ = new AstNode(string("init_declarator"), { $1 });} 
|   declarator ASSIGN_OP initializer {$$ = new AstNode(string("init_declarator"), { $1,new AstNode(string("operators_ASSIGN_OP"), {}),$3 });}
;

initializer:
   assignment_expression {$$ = new AstNode(string("initializer"), { $1 });} 
|   LEFT_CBRACKET initializer_list RIGHT_CBRACKET {$$ = new AstNode(string("initializer"), { new AstNode(string("delimeters_LEFT_CBRACKET"), {}),$2,new AstNode(string("delimeters_RIGHT_CBRACKET"), {}) });} 
|   LEFT_CBRACKET initializer_list COMMA RIGHT_CBRACKET {$$ = new AstNode(string("initializer"), { new AstNode(string("delimeters_LEFT_CBRACKET"), {}),$2,new AstNode(string("delimeters_COMMA"), {}),new AstNode(string("delimeters_RIGHT_CBRACKET"), {}) });}
;

initializer_list:
   initializer {$$ = new AstNode(string("initializer_list"), { $1 });} 
|   designation initializer {$$ = new AstNode(string("initializer_list"), { $1,$2 });} 
|   initializer_list COMMA initializer {$1->children.push_back($1);$1->children.push_back($3);$$ = $1;} 
|   initializer_list COMMA designation initializer {$1->children.push_back($1);$1->children.push_back($3);$1->children.push_back($4);$$ = $1;}
;

designation:
   designator_list ASSIGN_OP {$$ = new AstNode(string("designation"), { $1,new AstNode(string("operators_ASSIGN_OP"), {}) });}
;

designator_list:
   designator {$$ = new AstNode(string("designator_list"), { $1 });} 
|   designator_list designator {$1->children.push_back($1);$$ = $1;}
;

designator:
   LEFT_BRACKET constant_expression RIGHT_BRACKET {$$ = new AstNode(string("designator"), { new AstNode(string("delimeters_LEFT_BRACKET"), {}),$2,new AstNode(string("delimeters_RIGHT_BRACKET"), {}) });} 
|   DOT IDENTIFIER {$$ = new AstNode(string("designator"), { new AstNode(string("delimeters_DOT"), {}),new AstNode(string("identifier_IDENTIFIER"), {}) });}
;

declarator:
   pointer direct_declarator {$$ = new AstNode(string("declarator"), { $1,$2 });} 
|   direct_declarator {$$ = new AstNode(string("declarator"), { $1 });}
;

pointer:
   STAR {$$ = new AstNode(string("pointer"), { new AstNode(string("operators_STAR"), {}) });} 
|   STAR type_qualifier_list {$$ = new AstNode(string("pointer"), { new AstNode(string("operators_STAR"), {}),$2 });} 
|   STAR pointer {$2->children.push_back(new AstNode(string("operators_STAR"), {}));$2->children.push_back($2);$$ = $2;} 
|   STAR type_qualifier_list pointer {$3->children.push_back(new AstNode(string("operators_STAR"), {}));$3->children.push_back($2);$3->children.push_back($3);$$ = $3;}
;

direct_declarator:
   IDENTIFIER {$$ = new AstNode(string("direct_declarator"), { new AstNode(string("identifier_IDENTIFIER"), {}) });} 
|   LEFT_PAR declarator RIGHT_PAR {$$ = new AstNode(string("direct_declarator"), { new AstNode(string("delimeters_LEFT_PAR"), {}),$2,new AstNode(string("delimeters_RIGHT_PAR"), {}) });} 
|   direct_declarator LEFT_BRACKET type_qualifier_list assignment_expression RIGHT_BRACKET {$1->children.push_back($1);$1->children.push_back($3);$1->children.push_back($4);$1->children.push_back(new AstNode(string("delimeters_RIGHT_BRACKET"), {}));$$ = $1;} 
|   direct_declarator LEFT_BRACKET type_qualifier_list RIGHT_BRACKET {$1->children.push_back($1);$1->children.push_back($3);$1->children.push_back(new AstNode(string("delimeters_RIGHT_BRACKET"), {}));$$ = $1;} 
|   direct_declarator LEFT_BRACKET assignment_expression RIGHT_BRACKET {$1->children.push_back($1);$1->children.push_back($3);$1->children.push_back(new AstNode(string("delimeters_RIGHT_BRACKET"), {}));$$ = $1;} 
|   direct_declarator LEFT_BRACKET STATIC type_qualifier_list assignment_expression RIGHT_BRACKET {$1->children.push_back($1);$1->children.push_back(new AstNode(string("keywords_STATIC"), {}));$1->children.push_back($4);$1->children.push_back($5);$1->children.push_back(new AstNode(string("delimeters_RIGHT_BRACKET"), {}));$$ = $1;} 
|   direct_declarator LEFT_BRACKET type_qualifier_list STATIC assignment_expression RIGHT_BRACKET {$1->children.push_back($1);$1->children.push_back($3);$1->children.push_back(new AstNode(string("keywords_STATIC"), {}));$1->children.push_back($5);$1->children.push_back(new AstNode(string("delimeters_RIGHT_BRACKET"), {}));$$ = $1;} 
|   direct_declarator LEFT_BRACKET type_qualifier_list STAR RIGHT_BRACKET {$1->children.push_back($1);$1->children.push_back($3);$1->children.push_back(new AstNode(string("operators_STAR"), {}));$1->children.push_back(new AstNode(string("delimeters_RIGHT_BRACKET"), {}));$$ = $1;} 
|   direct_declarator LEFT_BRACKET STAR RIGHT_BRACKET {$1->children.push_back($1);$1->children.push_back(new AstNode(string("operators_STAR"), {}));$1->children.push_back(new AstNode(string("delimeters_RIGHT_BRACKET"), {}));$$ = $1;} 
|   direct_declarator LEFT_BRACKET RIGHT_BRACKET {$1->children.push_back($1);$1->children.push_back(new AstNode(string("delimeters_RIGHT_BRACKET"), {}));$$ = $1;} 
|   direct_declarator LEFT_PAR parameter_type_list RIGHT_PAR {$1->children.push_back($1);$1->children.push_back($3);$1->children.push_back(new AstNode(string("delimeters_RIGHT_PAR"), {}));$$ = $1;} 
|   direct_declarator LEFT_PAR identifier_list RIGHT_PAR {$1->children.push_back($1);$1->children.push_back($3);$1->children.push_back(new AstNode(string("delimeters_RIGHT_PAR"), {}));$$ = $1;} 
|   direct_declarator LEFT_PAR RIGHT_PAR {$1->children.push_back($1);$1->children.push_back(new AstNode(string("delimeters_RIGHT_PAR"), {}));$$ = $1;}
;

type_qualifier_list:
   type_qualifier {$$ = new AstNode(string("type_qualifier_list"), { $1 });} 
|   type_qualifier_list type_qualifier {$1->children.push_back($1);$$ = $1;}
;

type_qualifier:
   CONST {$$ = new AstNode(string("type_qualifier"), { new AstNode(string("keywords_CONST"), {}) });} 
|   RESTRICT {$$ = new AstNode(string("type_qualifier"), { new AstNode(string("keywords_RESTRICT"), {}) });} 
|   VOLATILE {$$ = new AstNode(string("type_qualifier"), { new AstNode(string("keywords_VOLATILE"), {}) });}
;

parameter_type_list:
   parameter_list {$$ = new AstNode(string("parameter_type_list"), { $1 });} 
|   parameter_list COMMA ELLIPSIS {$$ = new AstNode(string("parameter_type_list"), { $1,new AstNode(string("delimeters_COMMA"), {}),new AstNode(string("operators_ELLIPSIS"), {}) });}
;

parameter_list:
   parameter_declaration SEMICOLON {$$ = new AstNode(string("parameter_list"), { $1,new AstNode(string("delimeters_SEMICOLON"), {}) });} 
|   parameter_list COMMA parameter_declaration {$1->children.push_back($1);$1->children.push_back($3);$$ = $1;}
;

parameter_declaration:
   declaration_specifiers declarator {$$ = new AstNode(string("parameter_declaration"), { $1,$2 });} 
|   declaration_specifiers abstract_declarator {$$ = new AstNode(string("parameter_declaration"), { $1,$2 });} 
|   declaration_specifiers {$$ = new AstNode(string("parameter_declaration"), { $1 });}
;

function_specifier:
   INLINE {$$ = new AstNode(string("function_specifier"), { new AstNode(string("keywords_INLINE"), {}) });}
;

type_specifier:
   VOID {$$ = new AstNode(string("type_specifier"), { new AstNode(string("keywords_VOID"), {}) });} 
|   CHAR {$$ = new AstNode(string("type_specifier"), { new AstNode(string("keywords_CHAR"), {}) });} 
|   SHORT {$$ = new AstNode(string("type_specifier"), { new AstNode(string("keywords_SHORT"), {}) });} 
|   INT {$$ = new AstNode(string("type_specifier"), { new AstNode(string("keywords_INT"), {}) });} 
|   LONG {$$ = new AstNode(string("type_specifier"), { new AstNode(string("keywords_LONG"), {}) });} 
|   FLOAT {$$ = new AstNode(string("type_specifier"), { new AstNode(string("keywords_FLOAT"), {}) });} 
|   DOUBLE {$$ = new AstNode(string("type_specifier"), { new AstNode(string("keywords_DOUBLE"), {}) });} 
|   SIGNED {$$ = new AstNode(string("type_specifier"), { new AstNode(string("keywords_SIGNED"), {}) });} 
|   UNSIGNED {$$ = new AstNode(string("type_specifier"), { new AstNode(string("keywords_UNSIGNED"), {}) });} 
|   BOOL {$$ = new AstNode(string("type_specifier"), { new AstNode(string("keywords_BOOL"), {}) });} 
|   COMPLEX {$$ = new AstNode(string("type_specifier"), { new AstNode(string("keywords_COMPLEX"), {}) });} 
|   IMAGINARY {$$ = new AstNode(string("type_specifier"), { new AstNode(string("keywords_IMAGINARY"), {}) });} 
|   struct_or_union_specifier {$$ = new AstNode(string("type_specifier"), { $1 });} 
|   enum_specifier {$$ = new AstNode(string("type_specifier"), { $1 });} 
|   type_name {$$ = new AstNode(string("type_specifier"), { $1 });}
;

struct_or_union_specifier:
   struct_or_union IDENTIFIER LEFT_CBRACKET struct_declaration_list RIGHT_CBRACKET {$$ = new AstNode(string("struct_or_union_specifier"), { $1,new AstNode(string("identifier_IDENTIFIER"), {}),new AstNode(string("delimeters_LEFT_CBRACKET"), {}),$4,new AstNode(string("delimeters_RIGHT_CBRACKET"), {}) });} 
|   struct_or_union LEFT_CBRACKET struct_declaration_list RIGHT_CBRACKET {$$ = new AstNode(string("struct_or_union_specifier"), { $1,new AstNode(string("delimeters_LEFT_CBRACKET"), {}),$3,new AstNode(string("delimeters_RIGHT_CBRACKET"), {}) });} 
|   struct_or_union IDENTIFIER {$$ = new AstNode(string("struct_or_union_specifier"), { $1,new AstNode(string("identifier_IDENTIFIER"), {}) });}
;

struct_or_union:
   STRUCT {$$ = new AstNode(string("struct_or_union"), { new AstNode(string("keywords_STRUCT"), {}) });} 
|   UNION {$$ = new AstNode(string("struct_or_union"), { new AstNode(string("keywords_UNION"), {}) });}
;

struct_declaration_list:
   struct_declaration {$$ = new AstNode(string("struct_declaration_list"), { $1 });} 
|   struct_declaration_list struct_declaration {$1->children.push_back($1);$$ = $1;}
;

struct_declaration:
   specifier_qualifier_list struct_declarator_list SEMICOLON {$$ = new AstNode(string("struct_declaration"), { $1,$2,new AstNode(string("delimeters_SEMICOLON"), {}) });}
;

struct_declarator_list:
   struct_declarator {$$ = new AstNode(string("struct_declarator_list"), { $1 });} 
|   struct_declarator_list COMMA struct_declarator {$1->children.push_back($1);$1->children.push_back($3);$$ = $1;}
;

struct_declarator:
   declarator {$$ = new AstNode(string("struct_declarator"), { $1 });} 
|   COLON constant_expression {$$ = new AstNode(string("struct_declarator"), { new AstNode(string("delimeters_COLON"), {}),$2 });} 
|   declarator COLON constant_expression {$$ = new AstNode(string("struct_declarator"), { $1,new AstNode(string("delimeters_COLON"), {}),$3 });}
;

specifier_qualifier_list:
   type_specifier specifier_qualifier_list {$2->children.push_back($1);$2->children.push_back($2);$$ = $2;} 
|   type_specifier {$$ = new AstNode(string("specifier_qualifier_list"), { $1 });} 
|   type_qualifier specifier_qualifier_list {$2->children.push_back($1);$2->children.push_back($2);$$ = $2;} 
|   type_qualifier {$$ = new AstNode(string("specifier_qualifier_list"), { $1 });}
;

enum_specifier:
   ENUM LEFT_CBRACKET enumerator_list RIGHT_CBRACKET {$$ = new AstNode(string("enum_specifier"), { new AstNode(string("keywords_ENUM"), {}),new AstNode(string("delimeters_LEFT_CBRACKET"), {}),$3,new AstNode(string("delimeters_RIGHT_CBRACKET"), {}) });} 
|   ENUM IDENTIFIER LEFT_CBRACKET enumerator_list RIGHT_CBRACKET {$$ = new AstNode(string("enum_specifier"), { new AstNode(string("keywords_ENUM"), {}),new AstNode(string("identifier_IDENTIFIER"), {}),new AstNode(string("delimeters_LEFT_CBRACKET"), {}),$4,new AstNode(string("delimeters_RIGHT_CBRACKET"), {}) });} 
|   ENUM LEFT_CBRACKET enumerator_list COMMA RIGHT_CBRACKET {$$ = new AstNode(string("enum_specifier"), { new AstNode(string("keywords_ENUM"), {}),new AstNode(string("delimeters_LEFT_CBRACKET"), {}),$3,new AstNode(string("delimeters_COMMA"), {}),new AstNode(string("delimeters_RIGHT_CBRACKET"), {}) });} 
|   ENUM IDENTIFIER LEFT_CBRACKET enumerator_list COMMA RIGHT_CBRACKET {$$ = new AstNode(string("enum_specifier"), { new AstNode(string("keywords_ENUM"), {}),new AstNode(string("identifier_IDENTIFIER"), {}),new AstNode(string("delimeters_LEFT_CBRACKET"), {}),$4,new AstNode(string("delimeters_COMMA"), {}),new AstNode(string("delimeters_RIGHT_CBRACKET"), {}) });} 
|   ENUM IDENTIFIER {$$ = new AstNode(string("enum_specifier"), { new AstNode(string("keywords_ENUM"), {}),new AstNode(string("identifier_IDENTIFIER"), {}) });}
;

enumerator_list:
   enumerator {$$ = new AstNode(string("enumerator_list"), { $1 });} 
|   enumerator_list COMMA enumerator {$1->children.push_back($1);$1->children.push_back($3);$$ = $1;}
;

enumerator:
   IDENTIFIER {$$ = new AstNode(string("enumerator"), { new AstNode(string("identifier_IDENTIFIER"), {}) });} 
|   IDENTIFIER ASSIGN_OP constant_expression {$$ = new AstNode(string("enumerator"), { new AstNode(string("identifier_IDENTIFIER"), {}),new AstNode(string("operators_ASSIGN_OP"), {}),$3 });}
;

type_name:
   specifier_qualifier_list {$$ = new AstNode(string("type_name"), { $1 });} 
|   specifier_qualifier_list abstract_declarator {$$ = new AstNode(string("type_name"), { $1,$2 });}
;

abstract_declarator:
   pointer {$$ = new AstNode(string("abstract_declarator"), { $1 });} 
|   direct_abstract_declarator {$$ = new AstNode(string("abstract_declarator"), { $1 });} 
|   pointer direct_abstract_declarator {$$ = new AstNode(string("abstract_declarator"), { $1,$2 });}
;

direct_abstract_declarator:
   LEFT_PAR abstract_declarator RIGHT_PAR {$$ = new AstNode(string("direct_abstract_declarator"), { new AstNode(string("delimeters_LEFT_PAR"), {}),$2,new AstNode(string("delimeters_RIGHT_PAR"), {}) });} 
|   LEFT_BRACKET RIGHT_BRACKET {$$ = new AstNode(string("direct_abstract_declarator"), { new AstNode(string("delimeters_LEFT_BRACKET"), {}),new AstNode(string("delimeters_RIGHT_BRACKET"), {}) });} 
|   LEFT_BRACKET assignment_expression RIGHT_BRACKET {$$ = new AstNode(string("direct_abstract_declarator"), { new AstNode(string("delimeters_LEFT_BRACKET"), {}),$2,new AstNode(string("delimeters_RIGHT_BRACKET"), {}) });} 
|   direct_abstract_declarator LEFT_BRACKET RIGHT_BRACKET {$1->children.push_back($1);$1->children.push_back(new AstNode(string("delimeters_RIGHT_BRACKET"), {}));$$ = $1;} 
|   direct_abstract_declarator LEFT_BRACKET assignment_expression RIGHT_BRACKET {$1->children.push_back($1);$1->children.push_back($3);$1->children.push_back(new AstNode(string("delimeters_RIGHT_BRACKET"), {}));$$ = $1;} 
|   LEFT_BRACKET STAR RIGHT_BRACKET {$$ = new AstNode(string("direct_abstract_declarator"), { new AstNode(string("delimeters_LEFT_BRACKET"), {}),new AstNode(string("operators_STAR"), {}),new AstNode(string("delimeters_RIGHT_BRACKET"), {}) });} 
|   direct_abstract_declarator LEFT_BRACKET STAR RIGHT_BRACKET {$1->children.push_back($1);$1->children.push_back(new AstNode(string("operators_STAR"), {}));$1->children.push_back(new AstNode(string("delimeters_RIGHT_BRACKET"), {}));$$ = $1;} 
|   LEFT_PAR RIGHT_PAR {$$ = new AstNode(string("direct_abstract_declarator"), { new AstNode(string("delimeters_LEFT_PAR"), {}),new AstNode(string("delimeters_RIGHT_PAR"), {}) });} 
|   LEFT_PAR parameter_type_list RIGHT_PAR {$$ = new AstNode(string("direct_abstract_declarator"), { new AstNode(string("delimeters_LEFT_PAR"), {}),$2,new AstNode(string("delimeters_RIGHT_PAR"), {}) });} 
|   direct_abstract_declarator LEFT_PAR RIGHT_PAR {$1->children.push_back($1);$1->children.push_back(new AstNode(string("delimeters_RIGHT_PAR"), {}));$$ = $1;} 
|   direct_abstract_declarator LEFT_PAR parameter_type_list RIGHT_PAR {$1->children.push_back($1);$1->children.push_back($3);$1->children.push_back(new AstNode(string("delimeters_RIGHT_PAR"), {}));$$ = $1;}
;

statement:
   labeled_statement {$$ = new AstNode(string("statement"), { $1 });} 
|   compound_statement {$$ = new AstNode(string("statement"), { $1 });} 
|   expression_statement {$$ = new AstNode(string("statement"), { $1 });} 
|   selection_statement {$$ = new AstNode(string("statement"), { $1 });} 
|   iteration_statement {$$ = new AstNode(string("statement"), { $1 });} 
|   jump_statement {$$ = new AstNode(string("statement"), { $1 });}
;

labeled_statement:
   IDENTIFIER COLON statement {$$ = new AstNode(string("labeled_statement"), { new AstNode(string("identifier_IDENTIFIER"), {}),new AstNode(string("delimeters_COLON"), {}),$3 });} 
|   CASE constant_expression COLON statement {$$ = new AstNode(string("labeled_statement"), { new AstNode(string("keywords_CASE"), {}),$2,new AstNode(string("delimeters_COLON"), {}),$4 });} 
|   DEFAULT COLON statement {$$ = new AstNode(string("labeled_statement"), { new AstNode(string("keywords_DEFAULT"), {}),new AstNode(string("delimeters_COLON"), {}),$3 });}
;

compound_statement:
   LEFT_CBRACKET RIGHT_CBRACKET {$$ = new AstNode(string("compound_statement"), { new AstNode(string("delimeters_LEFT_CBRACKET"), {}),new AstNode(string("delimeters_RIGHT_CBRACKET"), {}) });} 
|   LEFT_CBRACKET block_item_list RIGHT_CBRACKET {$$ = new AstNode(string("compound_statement"), { new AstNode(string("delimeters_LEFT_CBRACKET"), {}),$2,new AstNode(string("delimeters_RIGHT_CBRACKET"), {}) });}
;

block_item_list:
   block_item {$$ = new AstNode(string("block_item_list"), { $1 });} 
|   block_item_list block_item {$1->children.push_back($1);$$ = $1;}
;

block_item:
   declaration {$$ = new AstNode(string("block_item"), { $1 });} 
|   statement {$$ = new AstNode(string("block_item"), { $1 });}
;

expression_statement:
   SEMICOLON {$$ = new AstNode(string("expression_statement"), { new AstNode(string("delimeters_SEMICOLON"), {}) });} 
|   expression SEMICOLON {$$ = new AstNode(string("expression_statement"), { $1,new AstNode(string("delimeters_SEMICOLON"), {}) });}
;

selection_statement:
   IF LEFT_PAR expression RIGHT_PAR statement {$$ = new AstNode(string("selection_statement"), { new AstNode(string("keywords_IF"), {}),new AstNode(string("delimeters_LEFT_PAR"), {}),$3,new AstNode(string("delimeters_RIGHT_PAR"), {}),$5 });} 
|   IF LEFT_PAR expression RIGHT_PAR statement ELSE statement {$$ = new AstNode(string("selection_statement"), { new AstNode(string("keywords_IF"), {}),new AstNode(string("delimeters_LEFT_PAR"), {}),$3,new AstNode(string("delimeters_RIGHT_PAR"), {}),$5,new AstNode(string("keywords_ELSE"), {}),$7 });} 
|   SWITCH LEFT_PAR expression RIGHT_PAR statement {$$ = new AstNode(string("selection_statement"), { new AstNode(string("keywords_SWITCH"), {}),new AstNode(string("delimeters_LEFT_PAR"), {}),$3,new AstNode(string("delimeters_RIGHT_PAR"), {}),$5 });}
;

iteration_statement:
   WHILE LEFT_PAR expression RIGHT_PAR statement {$$ = new AstNode(string("iteration_statement"), { new AstNode(string("keywords_WHILE"), {}),new AstNode(string("delimeters_LEFT_PAR"), {}),$3,new AstNode(string("delimeters_RIGHT_PAR"), {}),$5 });} 
|   DO statement WHILE LEFT_PAR expression RIGHT_PAR SEMICOLON {$$ = new AstNode(string("iteration_statement"), { new AstNode(string("keywords_DO"), {}),$2,new AstNode(string("keywords_WHILE"), {}),new AstNode(string("delimeters_LEFT_PAR"), {}),$5,new AstNode(string("delimeters_RIGHT_PAR"), {}),new AstNode(string("delimeters_SEMICOLON"), {}) });} 
|   FOR LEFT_PAR expression_statement expression_statement RIGHT_PAR statement {$$ = new AstNode(string("iteration_statement"), { new AstNode(string("keywords_FOR"), {}),new AstNode(string("delimeters_LEFT_PAR"), {}),$3,$4,new AstNode(string("delimeters_RIGHT_PAR"), {}),$6 });} 
|   FOR LEFT_PAR expression_statement expression_statement expression RIGHT_PAR statement {$$ = new AstNode(string("iteration_statement"), { new AstNode(string("keywords_FOR"), {}),new AstNode(string("delimeters_LEFT_PAR"), {}),$3,$4,$5,new AstNode(string("delimeters_RIGHT_PAR"), {}),$7 });} 
|   FOR LEFT_PAR declaration expression_statement RIGHT_PAR statement {$$ = new AstNode(string("iteration_statement"), { new AstNode(string("keywords_FOR"), {}),new AstNode(string("delimeters_LEFT_PAR"), {}),$3,$4,new AstNode(string("delimeters_RIGHT_PAR"), {}),$6 });} 
|   FOR LEFT_PAR declaration expression_statement expression RIGHT_PAR statement {$$ = new AstNode(string("iteration_statement"), { new AstNode(string("keywords_FOR"), {}),new AstNode(string("delimeters_LEFT_PAR"), {}),$3,$4,$5,new AstNode(string("delimeters_RIGHT_PAR"), {}),$7 });}
;

jump_statement:
   GOTO IDENTIFIER SEMICOLON {$$ = new AstNode(string("jump_statement"), { new AstNode(string("keywords_GOTO"), {}),new AstNode(string("identifier_IDENTIFIER"), {}),new AstNode(string("delimeters_SEMICOLON"), {}) });} 
|   CONTINUE SEMICOLON {$$ = new AstNode(string("jump_statement"), { new AstNode(string("keywords_CONTINUE"), {}),new AstNode(string("delimeters_SEMICOLON"), {}) });} 
|   BREAK SEMICOLON {$$ = new AstNode(string("jump_statement"), { new AstNode(string("keywords_BREAK"), {}),new AstNode(string("delimeters_SEMICOLON"), {}) });} 
|   RETURN SEMICOLON {$$ = new AstNode(string("jump_statement"), { new AstNode(string("keywords_RETURN"), {}),new AstNode(string("delimeters_SEMICOLON"), {}) });} 
|   RETURN expression SEMICOLON {$$ = new AstNode(string("jump_statement"), { new AstNode(string("keywords_RETURN"), {}),$2,new AstNode(string("delimeters_SEMICOLON"), {}) });}
;

translation_unit:
   external_declaration {$$ = new AstNode(string("translation_unit"), { $1 });} 
|   translation_unit external_declaration {$1->children.push_back($1);$$ = $1;}
;

external_declaration:
   function_definition {$$ = new AstNode(string("external_declaration"), { $1 });} 
|   declaration {$$ = new AstNode(string("external_declaration"), { $1 });}
;

function_definition:
   declaration_specifiers declarator declaration_list compound_statement {$$ = new AstNode(string("function_definition"), { $1,$2,$3,$4 });} 
|   declaration_specifiers declarator compound_statement {$$ = new AstNode(string("function_definition"), { $1,$2,$3 });}
;

declaration_list:
   declaration {$$ = new AstNode(string("declaration_list"), { $1 });} 
|   declaration_list declaration {$1->children.push_back($1);$$ = $1;}
;

identifier_list:
   IDENTIFIER {$$ = new AstNode(string("identifier_list"), { new AstNode(string("identifier_IDENTIFIER"), {}) });} 
|   identifier_list COMMA IDENTIFIER {$1->children.push_back($1);$1->children.push_back(new AstNode(string("identifier_IDENTIFIER"), {}));$$ = $1;}
;


%%

// Epilogue

// namespace yy{

//     int main ()
//         {
//             yy::parser parse;
//             return parse.parse ();
//         }

// };


