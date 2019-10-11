%{
    %language "c++"
%}

%code top{
    #include <vector>
    #include <string>
    #include <iostream>

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

    class CastExpressionNode : public Node {
        public:
            Node* node;
            string typeName;

            string print() {
                string prefix = typeName.size() > 0 ? typeName + "_CAST(" : "";
                string suffix = typeName.size() > 0 ? ")" : "";
                return(prefix + node.print() + suffix);
            }

            CastExpressionNode(Node* node) {
                CastExpressionNode::node = node;
                CastExpressionNode::typeName = "";
            }
            
            CastExpressionNode(string typeName, Node* node) {
                CastExpressionNode::node = node;
                CastExpressionNode::typeName = typeName;
            }
    }

    class BinaryExpressionNode : public Node {
        public:
            vector<string> ops;
            string _exprType;

            string print() {
                string res = _exprType + "(" children[0].preint();
                for (int i = 0; i < ops.size(); i++) {
                    res += (" " + ops[i] + " ");
                    res += children[i + 1];
                }
                res += ")";
                return res;
            }

            MultiplicativeExpressionNode(Node* node) {
                children = vector<Node*>{node};
                ops = vector<string>();
            }
    }

    class OperatorNode : public Node {
        public:
            string _sign;

            public string print() {
                return("OPERATOR(" + _sign + ")");
            } 

            OperatorNode(string sign) {
                _sign = sign;
            }
    }

    /*class EnumSpecNode : public Node {
        public:
            string _identifier;
            vector<>

            EnumSpecNode() {

            }
    }*/

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

%token IDENTIFIER

%token LITERAL // Numeric literal

%token STRING_LITERAL  // String literal

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

primary_expression:
      IDENTIFIER            { $$ = &PrimaryExpressionNode(&IdentifierNode("ab")); }
    | LITERAL               { $$ = &PrimaryExpressionNode(&NumericLiteralNode("1")); }
    | STRING_LITERAL        { $$ = &PrimaryExpressionNode(&StrLiteralNode("String")); }
    | '(' expression ')'    { $$ = &PrimaryExpressionNode(NULL); }
;

postfix_expression:
      primary_expression { $$ = new PostfixExpressionNode($1);}
    | postfix_expression '[' expression ']' {$1->children.push_back($3); $$ = $1 ;}
    | postfix_expression '(' argument_expression_list ')'
    | postfix_expression '(' ')'{$$ = $1;}
    | postfix_expression '.' IDENTIFIER
    | postfix_expression PTR_OP IDENTIFIER
    | postfix_expression INC_OP
    | postfix_expression DEC_OP
    | '(' type_name ')' '{' initializer_list '}'
    | '(' type_name ')' '{' initializer_list ',' '}'
;

argument_expression_list:
      IDENTIFIER    {$$ = vector<string>(){$1};}
    | IDENTIFIER ',' argument_expression_list   {$3.push_back($1);$$ = $3;}
;

unary_expression:
      postfix_expression { $$ =  }
    | INC_OP unary_expression { $$ =  }
    | DEC_OP unary_expression { $$ =  }
    | unary_operator cast_expression { $$ =  }
    | SIZEOF unary_expression { $$ =  }
    | SIZEOF '(' type_name ')' { $$ =  }
;

unary_operator:
      '&'  {$$ = $1;} 
    | '*'  {$$ = $1;} 
    | '+'  {$$ = $1;} 
    | '-'  {$$ = $1;} 
    | '˜'  {$$ = $1;} 
    | '!'  {$$ = $1;} 
;

cast_expression:
      unary_expression { $$ = new CastExpressionNode($1) }
    | '(' type_name ')' cast_expression { $$ = new CastExpressionNode($2, $4) }
;

multiplicative_expression:
      cast_expression { $$ = new BinaryExpressionNode($1) }
    | multiplicative_expression '*' cast_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
    | multiplicative_expression '/' cast_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
    | multiplicative_expression '%' cast_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
;

additive_expression:
      multiplicative_expression { $$ = new BinaryExpressionNode($1) }
    | additive_expression '+' multiplicative_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
    | additive_expression '-' multiplicative_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
;

shift_expression:
      additive_expression { $$ = new BinaryExpressionNode($1) }
    | shift_expression LEFT_OP additive_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
    | shift_expression RIGHT_OP additive_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
;

relational_expression:
      shift_expression { $$ = new BinaryExpressionNode($1) }
    | relational_expression '<' shift_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
    | relational_expression '>' shift_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
    | relational_expression LE_OP shift_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
    | relational_expression GE_OP shift_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
;

equality_expression:
      relational_expression { $$ = new BinaryExpressionNode($1) }
    | equality_expression EQ_OP relational_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
    | equality_expression NE_OP relational_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
;

and_expression:
      equality_expression { $$ = new BinaryExpressionNode($1) }
    | and_expression '&' equality_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
;

exclusive_or_expression:
      and_expression { $$ = new BinaryExpressionNode($1) }
    | exclusive_or_expression 'ˆ' and_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
;

inclusive_or_expression:
      exclusive_or_expression { $$ = new BinaryExpressionNode($1) }
    | inclusive_or_expression '|' exclusive_or_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
;

logical_and_expression:
      inclusive_or_expression { $$ = new BinaryExpressionNode($1) }
    | logical_and_expression AND_OP inclusive_or_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
;

logical_or_expression: 
      logical_and_expression { $$ = new BinaryExpressionNode($1) }
    | logical_or_expression OR_OP logical_and_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
;

conditional_expression:
      logical_or_expression { $$ = new ConditionalExpressionNode($1) }
    | logical_or_expression '?' expression ':' conditional_expression { $$ =  }
;

assignment_expression:
      conditional_expression { $$ = new AssignmentExpressionNode($1) }
    | unary_expression assignment_operator assignment_expression { $$ =  }
;

assignment_operator:
      '=' { $$ = new OperatorNode("=") } 
    | MUL_ASSIGN { $$ = new OperatorNode("*=") }
    | DIV_ASSIGN { $$ = new OperatorNode("/=") }
    | MOD_ASSIGN { $$ = new OperatorNode("%=") }
    | ADD_ASSIGN { $$ = new OperatorNode("+=") }
    | SUB_ASSIGN { $$ = new OperatorNode("-=") }
    | LEFT_ASSIGN { $$ = new OperatorNode("<=") }
    | RIGHT_ASSIGN { $$ = new OperatorNode(">=") }
    | AND_ASSIGN { $$ = new OperatorNode("&=") }
    | XOR_ASSIGN { $$ = new OperatorNode("^=") }
    | OR_ASSIGN { $$ = new OperatorNode("|=") }
;

expression:
      assignment_expression {$$ = new ExpressionNode($1);}
    | expression ',' assignment_expression {$1->children.push_back($3); $$ = $1 ;}
;

conditional_expression: 
    logical_or_expression {$$ = new ConditionalExpressionNode($1);}
	| logical_or_expression '?' expression ':' conditional_expression {$$ = new ConditionalExpressionNode($1, $3, $5); ;}
;

constant_expression:
    conditional_expression($$ = new ConstantExpressionNode($1);)
;

declaration:
    declaration_specifiers ';' {$$ = new DeclarationNode($1);}|
	declaration_specifiers init_declarator_list ';' { $$ = new DeclarationNode($1,$2);}
;

declaration_specifiers: 
    storage_class_specifier {$$ = new DeclarationSpecifierNode($1); }|
	storage_class_specifier declaration_specifiers {{$$ = new DeclarationSpecifierNode($1, $2);}|
	type_specifier {$$ = new DeclarationSpecifierNode($1); } |
	type_specifier declaration_specifiers { $$ = new DeclarationSpecifierNode($1,$2); }|
	type_qualifier {$$ = new TypeQualifierNode($1);} |
	type_qualifier declaration_specifiers { $$ = new DeclarationSpecifierNode($1,$2); } |
    function_specifier { $$ = new DeclarationSpecifierNode($1); } |
	function_specifier declaration_specifiers { $$ = new DeclarationSpecifierNode($1,$2); }
;
storage_class_specifier:
	EXTERN  { $$ = new StorageClassSpecifierNode("extern"); } |
	STATIC { $$ = new StorageClassSpecifierNode("static"); }  |
	AUTO { $$ = new StorageClassSpecifierNode("auto"); } |
	REGISTER { $$ = new StorageClassSpecifierNode("register"); } 
;
init_declarator_list:
	init_declarator{$$ = new InitDeclaratorListNode($1);} |   
	init_declarator_list ',' init_declarator{$1->children.push_back($3); $$ = $1 ;}
;

init_declarator:
	declarator {$$ = new  InitDeclaratorNode($1);}|
	declarator '=' initializer{$$ = new  InitDeclaratorNode($1, $3);}
;

initializer:
	assignment_expression {$$ = new  InitalizerNode($1);} |
	'{' initializer_list '}' {$$ = new  InitalizerNode($2);}|
	'{' initializer_list ',' '}' {$$ = new  InitalizerNode($2);}
;

initializer_list:
	initializer  {$$ = new  InitalizerListNode($1);}|
	designation initializer   {$$ = new  InitalizerListNode($1);} |
	initializer_list ',' initializer {$1->children.push_back($3); $$ = $1 ;} |
	initializer_list ',' designation initializer{$1->children.push_back($3); $$ = $1 ;}
;

designation:
	designator_list '=' {$$ = new DesignationNode($1);}
;

designator_list:
	designator {$$ = new DesignatorListNode($1);}|
	designator_list designator{$1->children.push_back($2); $$ = $1 ;}
;

designator:
	'[' constant_expression ']'  { $$ = new DesignatorNode($2);}|
	'.' IDENTIFIER{ $$ = new DesignatorNode(new IdentifierNode($2));}
;

declarator: 
    pointer direct_declarator {$$ = new DeclaratorNode($1,$2);}|
	direct_declarator {$$ = new DeclaratorNode($1);}
;

pointer:
	'*' {$$ = new PointerNode();}|
	'*' type_qualifier_list {$$ = new PointerNode($2);}|
	'*' pointer {$$ = new PointerNode($2);}|
	'*' type_qualifier_list pointer {$3->children.push_back($2); $$ = $3 ;}
;

direct_declarator: 
    IDENTIFIER {$$ = new DirectDeclaratorNode(new IdentifierNode($1));}|
	'(' declarator ')'{$$ = new DirectDeclaratorNode($2);} |
	direct_declarator '[' type_qualifier_list assignment_expression ']'{$1->children.push_back($3);$1->children.push_back($4); $$ = $1 ;} |
	direct_declarator '[' type_qualifier_list ']' {$1->children.push_back($3);$ $$ = $1 ;}|
	direct_declarator '[' assignment_expression ']' {$1->children.push_back($3);$ $$ = $1 ;}|
	direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'{$1->children.push_back("static"); $1->children.push_back($4);$1->children.push_back($5); $$ = $1 ;} |
	direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'{$1->children.push_back($3); $1->children.push_back("static");$1->children.push_back($5); $$ = $1 ;} |
	direct_declarator '[' type_qualifier_list '*' ']' {$1->children.push_back($3); $$ = $1 ;}|
	direct_declarator '[' '*' ']' {$$ = $1;} |
	direct_declarator '[' ']' {$$ = $1;}|
	direct_declarator '(' parameter_type_list ')' {$1->children.push_back($3); $$ = $1 ;}|
	direct_declarator '(' identifier_list ')' {$1->children.push_back($3); $$ = $1 ;}|
	direct_declarator '(' ')'{$$ = $1 ;}
;

type_qualifier_list:
    type_qualifier {$$ = new TypeQualifierListNode($1);} |
	type_qualifier_list type_qualifier{$1->children.push_back($2); $$ = $1 ;}
;

type_qualifier:
	CONST {$$ = new TypeQualifierNode('const');}|
	RESTRICT  {$$ = new TypeQualifierNode('restrict');}|
	VOLATILE {$$ = new TypeQualifierNode('volatile');}
;
parameter_type_list: 
    parameter_list {$$ = new ParameterTypeList($1);}|
	parameter_list ',' ELLIPSIS{$$ = new ParameterTypeList($1, 'elipsis');}
;

parameter_list:
	parameter_declaration ';' {$$ = new ParameterListNode($1);}|
	parameter_list ',' parameter_declaration{$1->children.push_back($3); $$ = $1 ;}
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