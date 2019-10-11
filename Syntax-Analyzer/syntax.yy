%language "c++"

%code top{
    #include <vector>
    #include <string>
    #include <iostream> 
    #include "syntax.tab.cc"
    #include "stack.hh"


    using namespace std;

    class Node {
        public:
            vector<Node*> children;
            Node* parent;
            string name;
            
            Node(vector<Node*> _children, Node* _parent){
                children = _children;
                parent = _parent;
            }
            
            Node(){
                children = vector<Node*>(1);
                parent = NULL;
            }

            void print_tree(){
                cout << name;
                for (int i = 0;i<children.size();i++){
                    cout << " " << children[i]->print();
                }
            }

            virtual string print() = 0;
    };

    class PrimaryExpressionNode : public Node {
        public:
            string print(){
                return("PrimaryExpressionNode");
            }

            PrimaryExpressionNode(Node* expr){
                children = {expr};
            }
    };

    
    class IdentifierNode : public Node{
        public:
            string ident;

            string print(){
                return("IDENT(" + ident + ")");
            };

            IdentifierNode(string _ident){
                ident = _ident;
            }
    };

    class NumericLiteralNode : public Node{
        public:
            string num;

            string print(){
                return("NUMLITERAL(" + num + ")");
            };

            NumericLiteralNode(string _num){
                num = _num;
            }
    };


    class StrLiteralNode : public Node{
        public:
            string val;

            string print(){
                return("STRLITERAL(" + val + ")");
            }

            StrLiteralNode(string _val){
                val = _val;
            }
    };
}

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

// %start translation_unit
%start primary_expression

// Grammar
%%

%type <Node*> primary_expression;
%type <Node*> postfix_expression;
%type <Node*> argument_expression_list;
%type <Node*> unary_expression;
%type <Node*> unary_operator;
%type <Node*> cast_expression;
%type <Node*> multiplicative_expression;
%type <Node*> additive_expression;
%type <Node*> shift_expression;
%type <Node*> relational_expression;
%type <Node*> equality_expression;
%type <Node*> and_expression;
%type <Node*> exclusive_or_expression;
%type <Node*> inclusive_or_expression;
%type <Node*> logical_and_expression;
%type <Node*> logical_or_expression;
%type <Node*> conditional_expression;
%type <Node*> assignment_expression;
%type <Node*> assignment_operator;
%type <Node*> expression;
%type <Node*> constant_expression;
%type <Node*> declaration;
%type <Node*> declaration_specifiers; 
%type <Node*> storage_class_specifier;
%type <Node*> init_declarator_list;
%type <Node*> init_declarator;
%type <Node*> initializer;
%type <Node*> initializer_list;
%type <Node*> designation;
%type <Node*> designator_list;
%type <Node*> designator;
%type <Node*> declarator; 
%type <Node*> pointer;
%type <Node*> direct_declarator; 
%type <Node*> type_qualifier_list;
%type <Node*> type_qualifier;
%type <Node*> parameter_type_list; 
%type <Node*> parameter_list;
%type <Node*> parameter_declaration;
%type <Node*> function_specifier; 
%type <Node*> type_specifier;
%type <Node*> struct_or_union_specifier;
%type <Node*> struct_or_union;
%type <Node*> struct_declaration_list;
%type <Node*> struct_declaration;
%type <Node*> struct_declarator_list;
%type <Node*> struct_declarator;
%type <Node*> specifier_qualifier_list;
%type <Node*> enum_specifier; 
%type <Node*> enumerator_list;
%type <Node*> enumerator; 
%type <Node*> type_name;
%type <Node*> abstract_declarator;
%type <Node*> direct_abstract_declarator;
%type <Node*> statement;
%type <Node*> labeled_statement;
%type <Node*> compound_statement;
%type <Node*> block_item_list;
%type <Node*> block_item;
%type <Node*> expression_statement;
%type <Node*> selection_statement;
%type <Node*> iteration_statement;
%type <Node*> jump_statement; 
%type <Node*> translation_unit;
%type <Node*> external_declaration;
%type <Node*> function_definition;
%type <Node*> declaration_list; 
%type <Node*> identifier_list;



primary_expression:
      IDENTIFIER            { $$ = new PrimaryExpressionNode(new IdentifierNode("ab")); }
    | LITERAL               { $$ = new PrimaryExpressionNode(new NumericLiteralNode("1")); }
    | STRING_LITERAL        { $$ = new PrimaryExpressionNode(new StrLiteralNode("String")); }
    | '(' expression ')'    { $$ = new PrimaryExpressionNode(NULL); }
;

postfix_expression:
      primary_expression
    | postfix_expression '[' expression ']'
    | postfix_expression '(' argument_expression_list ')'
    | postfix_expression '(' ')'
    | postfix_expression '.' IDENTIFIER
    | postfix_expression PTR_OP IDENTIFIER
    | postfix_expression INC_OP
    | postfix_expression DEC_OP
    | '(' type_name ')' '{' initializer_list '}'
    | '(' type_name ')' '{' initializer_list ',' '}'
;

argument_expression_list:
      IDENTIFIER
    | IDENTIFIER ',' argument_expression_list 
;

unary_expression:
      postfix_expression 
    | INC_OP unary_expression 
    | DEC_OP unary_expression 
    | unary_operator cast_expression 
    | SIZEOF unary_expression 
    | SIZEOF '(' type_name ')' 
;

unary_operator:
      '&'
    | '*'
    | '+'
    | '-'
    | '˜'
    | '!'
;

cast_expression:
      unary_expression
    | '(' type_name ')' cast_expression
;

multiplicative_expression:
      cast_expression
    | multiplicative_expression '*' cast_expression
    | multiplicative_expression '/' cast_expression
    | multiplicative_expression '%' cast_expression
;

additive_expression:
      multiplicative_expression
    | additive_expression '+' multiplicative_expression
    | additive_expression '-' multiplicative_expression
;

shift_expression:
      additive_expression
    | shift_expression LEFT_OP additive_expression
    | shift_expression RIGHT_OP additive_expression
;

relational_expression:
      shift_expression
    | relational_expression '<' shift_expression
    | relational_expression '>' shift_expression
    | relational_expression LE_OP shift_expression
    | relational_expression GE_OP shift_expression
;

equality_expression:
      relational_expression
    | equality_expression EQ_OP relational_expression
    | equality_expression NE_OP relational_expression
;

and_expression:
      equality_expression
    | and_expression '&' equality_expression
;

exclusive_or_expression:
      and_expression
    | exclusive_or_expression 'ˆ' and_expression
;

inclusive_or_expression:
      exclusive_or_expression
    | inclusive_or_expression '|' exclusive_or_expression
;

logical_and_expression:
      inclusive_or_expression
    | logical_and_expression AND_OP inclusive_or_expression
;

logical_or_expression:
      logical_and_expression
    | logical_or_expression OR_OP logical_and_expression
;

conditional_expression:
      logical_or_expression
    | logical_or_expression '?' expression ':' conditional_expression
;

assignment_expression:
      conditional_expression
    | unary_expression assignment_operator assignment_expression
;

assignment_operator:
      '=' | MUL_ASSIGN | DIV_ASSIGN | MOD_ASSIGN | ADD_ASSIGN | SUB_ASSIGN 
    | LEFT_ASSIGN | RIGHT_ASSIGN | AND_ASSIGN | XOR_ASSIGN | OR_ASSIGN
;

expression:
      assignment_expression
    | expression ',' assignment_expression
;

conditional_expression:
    conditional_expression
;

constant_expression:
    conditional_expression
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
	type_name
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

declaration_list: 
    declaration
  | declaration_list declaration
;

identifier_list:
    IDENTIFIER
  | identifier_list ',' IDENTIFIER
;

%%

// Epilogue

namespace yy

int main ()
{
  yy::parser parse;
  return parse ();
}