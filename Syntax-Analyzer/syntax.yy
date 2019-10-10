%{
    %language "c++"
%}

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

%token IDENTIFIER

LITERAL // Integer literal

STRING_LITERAL  // String literal

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

%token ELLIPSIS
%token RIGHT_ASSIGN
%token LEFT_ASSIGN
%token ADD_ASSIGN
%token SUB_ASSIGN
%token MUL_ASSIGN
%token DIV_ASSIGN
%token MOD_ASSIGN
%token AND_ASSIGN
%token XOR_ASSIGN
%token OR_ASSIGN
%token RIGHT_OP
%token LEFT_OP
%token INC_OP
%token DEC_OP
%token PTR_OP
%token AND_OP
%token OR_OP
%token LE_OP
%token GE_OP
%token EQ_OP
%token NE_OP

%start PrimaryExpression

// Grammar
%%

PrimaryExpression:
    IDENTIFIER |
    LITERAL |
    STRING_LITERAL |
    '(' Expression ')'
;

declaration:
    declaration_specifiers ';'|
	declaration_specifiers init_declarator_list ';'
;

declaration_specifiers: 
    storage_class_specifier |
	storage_class_specifier declaration_specifiers |
	type_specifier |
	type_specifier declaration_specifiers |
	type_qualifier |
	type_qualifier declaration_specifiers |
    function_specifier |
	function_specifier declaration_specifiers
;
storage_class_specifier:
	EXTERN |
	STATIC |
	AUTO |
	REGISTER |
;
init_declarator_list:
	init_declarator |
	init_declarator_list ',' init_declarator
;

init_declarator:
	declarator|
	declarator '=' initializer
;

initializer:
	assignment_expression |
	'{' initializer_list '}' |
	'{' initializer_list ',' '}' 
;

initializer_list:
	initializer |
	designation initializer |
	initializer_list ',' initializer |
	initializer_list ',' designation initializer
;

designation:
	designator_list '='
;

designator_list:
	designator |
	designator_list designator
;

designator:
	'[' constant_expression ']' |
	'.' IDENTIFIER
;

declarator: 
    pointer direct_declarator |
	direct_declarator
;

pointer:
	'*' |
	'*' type_qualifier_list |
	'*' pointer |
	'*' type_qualifier_list pointer 
;

direct_declarator: 
    IDENTIFIER |
	'(' declarator ')' |
	direct_declarator '[' type_qualifier_list assignment_expression ']' |
	direct_declarator '[' type_qualifier_list ']' |
	direct_declarator '[' assignment_expression ']' |
	direct_declarator '[' STATIC type_qualifier_list assignment_expression ']' |
	direct_declarator '[' type_qualifier_list STATIC assignment_expression ']' |
	direct_declarator '[' type_qualifier_list '*' ']' |
	direct_declarator '[' '*' ']' |
	direct_declarator '[' ']' |
	direct_declarator '(' parameter_type_list ')' |
	direct_declarator '(' identifier_list ')' |
	direct_declarator '(' ')'
;

type_qualifier_list:
    type_qualifier |
	type_qualifier_list type_qualifier
;

type_qualifier:
	CONST |
	RESTRICT |
	VOLATILE
;
parameter_type_list: 
    parameter_list |
	parameter_list ',' ELLIPSIS
;

parameter_list:
	parameter_declaration;|
	parameter_list ',' parameter_declaration
;

parameter_declaration:
	declaration_specifiers declarator |
	declaration_specifiers abstract_declarator |
	declaration_specifiers
;
function_specifier: 
    INLINE
;
type_specifier:
	VOID |
	CHAR |
	SHORT |
	INT |
	LONG |
	FLOAT |
	DOUBLE |
	SIGNED |
	UNSIGNED |
	BOOL |
	COMPLEX |
	IMAGINARY |
	struct_or_union_specifier |
	enum_specifier |
	TYPE_NAME
;

struct_or_union_specifier:
	struct_or_union IDENTIFIER '{' struct_declaration_list '}' |
	struct_or_union '{' struct_declaration_list '}' |
	struct_or_union IDENTIFIER
;

struct_or_union:
	STRUCT|
	UNION
;

struct_declaration_list:
	struct_declaration|
	struct_declaration_list struct_declaration
;

struct_declaration:
	specifier_qualifier_list struct_declarator_list ';'
;

struct_declarator_list:
	struct_declarator |
	struct_declarator_list ',' struct_declarator
;

struct_declarator:
	declarator |
	':' constant_expression |
	declarator ':' constant_expression
;

specifier_qualifier_list:
	type_specifier specifier_qualifier_list |
	type_specifier |
	type_qualifier specifier_qualifier_list |
	type_qualifier
;


enum_specifier: 
    ENUM '{' enumerator_list '}' |
	ENUM IDENTIFIER '{' enumerator_list '}' |
	ENUM '{' enumerator_list ',' '}' |
	ENUM IDENTIFIER '{' enumerator_list ',' '}' |
	ENUM IDENTIFIER
;

enumerator_list:
	enumerator |
	enumerator_list ',' enumerator
;

enumerator: 
    IDENTIFIER |
	IDENTIFIER '=' constant_expression
;

type_name:
	specifier_qualifier_list | 
    specifier_qualifier_list abstract_declarator
;

abstract_declarator:
	pointer |
	direct_abstract_declarator |
	pointer direct_abstract_declarator
;

direct_abstract_declarator:
	'(' abstract_declarator ')' |
	'[' ']' |
	'[' assignment_expression ']' |
	direct_abstract_declarator '[' ']' |
	direct_abstract_declarator '[' assignment_expression ']' |
	'[' '*' ']' |
	direct_abstract_declarator '[' '*' ']' |
	'(' ')' |
	'(' parameter_type_list ')' |
	direct_abstract_declarator '(' ')' |
	direct_abstract_declarator '(' parameter_type_list ')' 
;

statement:
	labeled_statement |
	compound_statement |
	expression_statement |
	selection_statement | 
	iteration_statement |
	jump_statement
;

labeled_statement:
	IDENTIFIER ':' statement |
	CASE constant_expression ':' statement |
	DEFAULT ':' statement |
;

compound_statement:
	'{' '}' |
	'{' block_item_list '}'
;

block_item_list:
	block_item |
	block_item_list block_item
;

block_item:
	declaration |
	statement
;

expression_statement:
	';'|
	expression ';'
;

selection_statement:
	IF '(' expression ')' statement |
    IF '(' expression ')' statement ELSE statement |
	SWITCH '(' expression ')' statement
;

iteration_statement:
	WHILE '(' expression ')' statement |
	DO statement WHILE '(' expression ')' ';' |
	FOR '(' expression_statement expression_statement ')' statement |
	FOR '(' expression_statement expression_statement expression ')' statement |
	FOR '(' declaration expression_statement ')' statement |
	FOR '(' declaration expression_statement expression ')' statement 
;

jump_statement: 
	GOTO IDENTIFIER ';' |
	CONTINUE ';' |
	BREAK ';' | 
	RETURN ';' |
    RETURN expression ';'
;

translation_unit:
	external_declaration |
	translation_unit external_declaration
;

external_declaration:
	function_definition |
	declaration
;

function_definition:
	declaration_specifiers declarator declaration_list compound_statement|
	declaration_specifiers declarator compound_statement
;




%%

// Epilogue