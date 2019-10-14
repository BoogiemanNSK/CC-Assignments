%language "c++"

%code top {
    #include <vector>
    #include <string>
    #include <iostream> 
    #include "syntax.tab.cc"
    #include "stack.hh"

    using namespace std;

    class Node {
        private:
            string _name;
            string _value;
            vector<Node*> _children;

        public:
            Node(string name, vector<Node*> children) {
                _name = name;
                _value = "";
                _children = children;
            }

            Node(string name, string value) {
                _name = name;
                _value = value;
                _children = vector<Node*>();
            }

            // tab parameter is to show tree structure
            void printTree(int tab) {
                string valString = _value.size() > 0 ? "(" + _value + ")" : "";
                cout << _name + valString << endl;

                for (int i = 0; i < _children.size(); i++) {
                    for (int j = 0; j < tab; j++) { cout << "|\t"; }
                    _children[i]->printTree(tab + 1);
                }
            }
    };
}

// Tokens

// Keywords
%token  <std::string>  AUTO
%token  <std::string>  BOOL
%token  <std::string>  BREAK
%token  <std::string>  CASE
%token  <std::string>  CHAR
%token  <std::string>  COMPLEX
%token  <std::string>  CONST
%token  <std::string>  CONTINUE
%token  <std::string>  DEFAULT
%token  <std::string>  DO
%token  <std::string>  DOUBLE
%token  <std::string>  ELSE
%token  <std::string>  ENUM
%token  <std::string>  EXTERN
%token  <std::string>  FLOAT
%token  <std::string>  FOR
%token  <std::string>  GOTO
%token  <std::string>  IF
%token  <std::string>  IMAGINARY
%token  <std::string>  INLINE
%token  <std::string>  INT
%token  <std::string>  LONG
%token  <std::string>  REGISTER
%token  <std::string>  RESTRICT
%token  <std::string>  RETURN
%token  <std::string>  SHORT
%token  <std::string>  SIGNED
%token  <std::string>  SIZEOF
%token  <std::string>  STATIC
%token  <std::string>  STRUCT
%token  <std::string>  SWITCH
%token  <std::string>  TYPEDEF
%token  <std::string>  UNION
%token  <std::string>  UNSIGNED
%token  <std::string>  VOID
%token  <std::string>  VOLATILE
%token  <std::string>  WHILE

%token <std::string> IDENTIFIER

%token <std::string> LITERAL // Numeric literal

%token <std::string> STRING_LITERAL  // String literal

// Delimeters

%token  <std::string>  SEMICOLON ";"
%token  <std::string>  COMMA ","
%token  <std::string>  COLON ":"
%token  <std::string>  LEFT_PAR "("
%token  <std::string>  RIGHT_PAR ")"
%token  <std::string>  DOT "."
%token  <std::string>  LEFT_CBRACKET "{"
%token  <std::string>  RIGHT_CBRACKET "}"
%token  <std::string>  LEFT_BRACKET "["
%token  <std::string>  RIGHT_BRACKET "]"

// Operators

%token  <std::string>  ASSIGN_OP "="
%token  <std::string>  AMP "&"
%token  <std::string>  LOG_NOT_OP "!"
%token  <std::string>  BIN_NOT_OP "~"
%token  <std::string>  MINUS "-"
%token  <std::string>  PLUS "+"
%token  <std::string>  STAR "*"
%token  <std::string>  SLASH "/"
%token  <std::string>  MOD_OP "%"
%token  <std::string>  G_OP "<"
%token  <std::string>  L_OP ">"
%token  <std::string>  BIN_XOR_OP "^"
%token  <std::string>  BIN_OR_OP "|"
%token  <std::string>  TERNARY_OP "?"
%token  <std::string>  ELLIPSIS "..."
%token  <std::string>  RIGHT_ASSIGN ">>="
%token  <std::string>  LEFT_ASSIGN "<<="
%token  <std::string>  ADD_ASSIGN "+="
%token  <std::string>  SUB_ASSIGN "-="
%token  <std::string>  MUL_ASSIGN "*="
%token  <std::string>  DIV_ASSIGN "/="
%token  <std::string>  MOD_ASSIGN "%="
%token  <std::string>  AND_ASSIGN "&="
%token  <std::string>  XOR_ASSIGN "^="
%token  <std::string>  OR_ASSIGN "|="
%token  <std::string>  RIGHT_OP ">>"
%token  <std::string>  LEFT_OP "<<"
%token  <std::string>  INC_OP "++"
%token  <std::string>  DEC_OP "--"
%token  <std::string>  PTR_OP "->"
%token  <std::string>  AND_OP "&&"
%token  <std::string>  OR_OP "||"
%token  <std::string>  LE_OP "<="
%token  <std::string>  GE_OP ">="
%token  <std::string>  EQ_OP "=="
%token  <std::string>  NE_OP "!="

%start translation_unit

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
    IDENTIFIER
        { $$ = new Node("PRIMARY_EXPRESSION_NODE", vector<Node*>{ new Node("IDENTIFIER", $1) }); }

    | LITERAL 
        { $$ = new Node("PRIMARY_EXPRESSION_NODE", vector<Node*>{ new Node("LITERAL", $1) }); }

    | STRING_LITERAL
        { $$ = new Node("PRIMARY_EXPRESSION_NODE", vector<Node*>{ new Node("STRING_LITERAL", $1) }); }

    | LEFT_PAR expression RIGHT_PAR
        { $$ = new Node("PRIMARY_EXPRESSION_NODE", vector<Node*>{ $2 }); }
;


postfix_expression:
    primary_expression
        { $$ = new Node("POSTFIX_EXPRESSION_NODE", vector<Node*>{ $1 }); }

    | postfix_expression LEFT_BRACKET expression RIGHT_BRACKET
        { $$ = new Node("POSTFIX_EXPRESSION_NODE", vector<Node*>{ $1, $3 }); }

    | postfix_expression LEFT_PAR argument_expression_list RIGHT_PAR
        { $$ = new Node("POSTFIX_EXPRESSION_NODE", vector<Node*>{ $1, $3 }); }

    | postfix_expression LEFT_PAR RIGHT_PAR
        { $$ = new Node("POSTFIX_EXPRESSION_NODE", vector<Node*>{ $1 }); }

    | postfix_expression DOT IDENTIFIER
        { $$ = new Node("POSTFIX_EXPRESSION_NODE", vector<Node*>{ $1, new Node("DOT", $2), new Node("IDENTIFIER", $3) }); }

    | postfix_expression PTR_OP IDENTIFIER
        { $$ = new Node("POSTFIX_EXPRESSION_NODE", vector<Node*>{ $1, new Node("PTR_OP", $2), new Node("IDENTIFIER", $3) }); }

    | postfix_expression INC_OP
        { $$ = new Node("POSTFIX_EXPRESSION_NODE", vector<Node*>{ $1, new Node("INC_OP", $2) }); }

    | postfix_expression DEC_OP
        { $$ = new Node("POSTFIX_EXPRESSION_NODE", vector<Node*>{ $1, new Node("DEC_OP", $2) }); }

    | LEFT_PAR type_name RIGHT_PAR LEFT_CBRACKET initializer_list RIGHT_CBRACKET
        { $$ = new Node("POSTFIX_EXPRESSION_NODE", vector<Node*>{ $2, $4 }); }

    | LEFT_PAR type_name RIGHT_PAR LEFT_CBRACKET initializer_list COMMA RIGHT_CBRACKET
        { $$ = new Node("POSTFIX_EXPRESSION_NODE", vector<Node*>{ $2, $4 }); }
;


argument_expression_list:
    IDENTIFIER
        { $$ = new Node("ARGUMENT_EXPRESSION_LIST", vector<Node*>{ new Node("IDENTIFIER", $1) }); }

    | IDENTIFIER COMMA argument_expression_list
        { $$ = new Node("ARGUMENT_EXPRESSION_LIST", vector<Node*>{ new Node("IDENTIFIER", $1) }); }
;


unary_expression:
    postfix_expression
        { $$ = new Node("UNARY_EXPRESSION_NODE", vector<Node*>{ $1 }); }

    | INC_OP unary_expression
        { $$ = new Node("UNARY_EXPRESSION_NODE", vector<Node*>{ new Node("INC_OP", $1), $2 }); }

    | DEC_OP unary_expression
        { $$ = new Node("UNARY_EXPRESSION_NODE", vector<Node*>{ new Node("DEC_OP", $1), $2 }); }

    | unary_operator cast_expression
        { $$ = new Node("UNARY_EXPRESSION_NODE", vector<Node*>{ $1, $2 }); }

    | SIZEOF unary_expression
        { $$ = new Node("UNARY_EXPRESSION_NODE", vector<Node*>{ new Node("SIZEOF", $1), $2 }); }

    | SIZEOF LEFT_PAR type_name RIGHT_PAR
        { $$ = new Node("UNARY_EXPRESSION_NODE", vector<Node*>{ new Node("SIZEOF", $1), $3 }); }
;


unary_operator:
    AMP
        { $$ = new Node("UNARY_OPERATOR_NODE", vector<Node*>{ new Node("AMP", $1) }); }

    | STAR
        { $$ = new Node("UNARY_OPERATOR_NODE", vector<Node*>{ new Node("STAR", $1) }); }

    | PLUS
        { $$ = new Node("UNARY_OPERATOR_NODE", vector<Node*>{ new Node("PLUS", $1) }); }
    
    | MINUS
        { $$ = new Node("UNARY_OPERATOR_NODE", vector<Node*>{ new Node("MINUS", $1) }); }

    | BIN_NOT_OP
        { $$ = new Node("UNARY_OPERATOR_NODE", vector<Node*>{ new Node("BIN_NOT_OP", $1) }); }
    
    | LOG_NOT_OP
        { $$ = new Node("UNARY_OPERATOR_NODE", vector<Node*>{ new Node("LOG_NOT_OP", $1) }); }
;


cast_expression:
    unary_expression
        { $$ = new Node("CAST_EXPRESSION_NODE", vector<Node*>{ $1 }); }

    | LEFT_PAR type_name RIGHT_PAR cast_expression
        { $$ = new Node("CAST_EXPRESSION_NODE", vector<Node*>{ $2, $4 }); }
;


multiplicative_expression:
    cast_expression
        { $$ = new Node("MULTIPLICATIVE_EXPRESSION_NODE", vector<Node*>{ $1 }); }

    | multiplicative_expression STAR cast_expression
        { $$ = new Node("MULTIPLICATIVE_EXPRESSION_NODE", vector<Node*>{ $1, new Node("STAR", $2), $3 }); }

    | multiplicative_expression SLASH cast_expression
        { $$ = new Node("MULTIPLICATIVE_EXPRESSION_NODE", vector<Node*>{ $1, new Node("SLASH", $2), $3 }); }

    | multiplicative_expression MOD_OP cast_expression
        { $$ = new Node("MULTIPLICATIVE_EXPRESSION_NODE", vector<Node*>{ $1, new Node("MOD_OP", $2), $3 }); }
;


additive_expression:
    multiplicative_expression
        { $$ = new Node("ADDITIVE_EXPRESSION_NODE", vector<Node*>{ $1 }); }

    | additive_expression PLUS multiplicative_expression
        { $$ = new Node("ADDITIVE_EXPRESSION_NODE", vector<Node*>{ $1, new Node("PLUS", $2), $3 }); }

    | additive_expression MINUS multiplicative_expression
        { $$ = new Node("ADDITIVE_EXPRESSION_NODE", vector<Node*>{ $1, new Node("MINUS", $2), $3 }); }
;


shift_expression:
    additive_expression
        { $$ = new Node("SHIFT_EXPRESSION_NODE", vector<Node*>{ $1 }); }

    | shift_expression LEFT_OP additive_expression
        { $$ = new Node("SHIFT_EXPRESSION_NODE", vector<Node*>{ $1, new Node("LEFT_OP", $2), $3 }); }

    | shift_expression RIGHT_OP additive_expression
        { $$ = new Node("SHIFT_EXPRESSION_NODE", vector<Node*>{ $1, new Node("RIGHT_OP", $2), $3 }); }
;


relational_expression:
    shift_expression
        { $$ = new Node("RELATIONAL_EXPRESSION_NODE", vector<Node*>{ $1 }); }

    | relational_expression L_OP shift_expression
        { $$ = new Node("RELATIONAL_EXPRESSION_NODE", vector<Node*>{ $1, new Node("L_OP", $2), $3 }); }

    | relational_expression G_OP shift_expression
        { $$ = new Node("RELATIONAL_EXPRESSION_NODE", vector<Node*>{ $1, new Node("G_OP", $2), $3 }); }

    | relational_expression LE_OP shift_expression
        { $$ = new Node("RELATIONAL_EXPRESSION_NODE", vector<Node*>{ $1, new Node("LE_OP", $2), $3 }); }

    | relational_expression GE_OP shift_expression
        { $$ = new Node("RELATIONAL_EXPRESSION_NODE", vector<Node*>{ $1, new Node("GE_OP", $2), $3 }); }
;


equality_expression:
    relational_expression
        { $$ = new Node("EQUALITY_EXPRESSION_NODE", vector<Node*>{ $1 }); }

    | equality_expression EQ_OP relational_expression
        { $$ = new Node("EQUALITY_EXPRESSION_NODE", vector<Node*>{ $1, new Node("EQ_OP", $2), $3 }); }

    | equality_expression NE_OP relational_expression
        { $$ = new Node("EQUALITY_EXPRESSION_NODE", vector<Node*>{ $1, new Node("NE_OP", $2), $3 }); }
;


and_expression:
    equality_expression
        { $$ = new Node("AND_EXPRESSION_NODE", vector<Node*>{ $1 }); }

    | and_expression AMP equality_expression
        { $$ = new Node("AND_EXPRESSION_NODE", vector<Node*>{ $1, new Node("AMP", $2), $3 }); }
;


exclusive_or_expression:
    and_expression
        { $$ = new Node("EXCLUSIVE_OR_EXPRESSION_NODE", vector<Node*>{ $1 }); }

    | exclusive_or_expression BIN_XOR_OP and_expression
        { $$ = new Node("EXCLUSIVE_OR_EXPRESSION_NODE", vector<Node*>{ $1, new Node("BIN_XOR_OP", $2), $3 }); }
;


inclusive_or_expression:
    exclusive_or_expression
        { $$ = new Node("INCLUSIVE_OR_EXPRESSION_NODE", vector<Node*>{ $1 }); }

    | inclusive_or_expression BIN_OR_OP exclusive_or_expression
        { $$ = new Node("INCLUSIVE_OR_EXPRESSION_NODE", vector<Node*>{ $1, new Node("BIN_OR_OP", $2), $3 }); }
;


logical_and_expression:
    inclusive_or_expression
        { $$ = new Node("LOGICAL_AND_EXPRESSION_NODE", vector<Node*>{ $1 }); }

    | logical_and_expression AND_OP inclusive_or_expression
        { $$ = new Node("LOGICAL_AND_EXPRESSION_NODE", vector<Node*>{ $1, new Node("AND_OP", $2), $3 }); }
;


logical_or_expression: 
    logical_and_expression
        { $$ = new Node("LOGICAL_OR_EXPRESSION_NODE", vector<Node*>{ $1 }); }

    | logical_or_expression OR_OP logical_and_expression
        { $$ = new Node("LOGICAL_OR_EXPRESSION_NODE", vector<Node*>{ $1, new Node("OR_OP", $2), $3 }); }
;


conditional_expression:
    logical_or_expression
        { $$ = new Node("CONDITIONAL_EXPRESSION_NODE", vector<Node*>{ $1 }); }

    | logical_or_expression TERNARY_OP expression COLON conditional_expression
        { $$ = new Node("CONDITIONAL_EXPRESSION_NODE", vector<Node*>{ $1, new Node("TERNARY_OP", $2), $3, $5 }); }
;


assignment_expression:
    conditional_expression
        { $$ = new Node("ASSIGNMENT_EXPRESSION_NODE", vector<Node*>{ $1 }); }

    | unary_expression assignment_operator assignment_expression
        { $$ = new Node("ASSIGNMENT_EXPRESSION_NODE", vector<Node*>{ $1, $2, $3 }); }
;


assignment_operator:
    ASSIGN_OP
        { $$ = new Node("ASSIGNMENT_OPERATOR_NODE", vector<Node*>{ new Node("ASSIGN_OP", $1) }); }

    | MUL_ASSIGN
        { $$ = new Node("ASSIGNMENT_OPERATOR_NODE", vector<Node*>{ new Node("MUL_ASSIGN", $1) }); }

    | DIV_ASSIGN
        { $$ = new Node("ASSIGNMENT_OPERATOR_NODE", vector<Node*>{ new Node("DIV_ASSIGN", $1) }); }

    | MOD_ASSIGN
        { $$ = new Node("ASSIGNMENT_OPERATOR_NODE", vector<Node*>{ new Node("MOD_ASSIGN", $1) }); }

    | ADD_ASSIGN
        { $$ = new Node("ASSIGNMENT_OPERATOR_NODE", vector<Node*>{ new Node("ADD_ASSIGN", $1) }); }

    | SUB_ASSIGN
        { $$ = new Node("ASSIGNMENT_OPERATOR_NODE", vector<Node*>{ new Node("SUB_ASSIGN", $1) }); }

    | LEFT_ASSIGN
        { $$ = new Node("ASSIGNMENT_OPERATOR_NODE", vector<Node*>{ new Node("LEFT_ASSIGN", $1) }); }

    | RIGHT_ASSIGN
        { $$ = new Node("ASSIGNMENT_OPERATOR_NODE", vector<Node*>{ new Node("RIGHT_ASSIGN", $1) }); }

    | AND_ASSIGN
        { $$ = new Node("ASSIGNMENT_OPERATOR_NODE", vector<Node*>{ new Node("AND_ASSIGN", $1) }); }

    | XOR_ASSIGN
        { $$ = new Node("ASSIGNMENT_OPERATOR_NODE", vector<Node*>{ new Node("XOR_ASSIGN", $1) }); }

    | OR_ASSIGN
        { $$ = new Node("ASSIGNMENT_OPERATOR_NODE", vector<Node*>{ new Node("OR_ASSIGN", $1) }); }
;


expression:
    assignment_expression
        { $$ = new Node("EXPRESSION_NODE", vector<Node*>{ $1 }); }

    | expression COMMA assignment_expression
        { $$ = new Node("EXPRESSION_NODE", vector<Node*>{ $1, $2 }); }
;


constant_expression:
    conditional_expression
        { $$ = new Node("CONSTANT_EXPRESSION_NODE", vector<Node*>{ $1 }); }
;


declaration:
	declaration_specifiers SEMICOLON
        { $$ = new Node("DECLARATION_NODE", vector<Node*>{ $1 }); }

	| declaration_specifiers init_declarator_list SEMICOLON
        { $$ = new Node("DECLARATION_NODE", vector<Node*>{ $1, $2 }); }
;


declaration_specifiers: 
    storage_class_specifier
        { $$ = new Node("DECLARATION_SPECIFIERS_NODE", vector<Node*>{ $1 }); }

	| storage_class_specifier declaration_specifiers
        { $$ = new Node("DECLARATION_SPECIFIERS_NODE", vector<Node*>{ $1, $2 }); }

	| type_specifier
        { $$ = new Node("DECLARATION_SPECIFIERS_NODE", vector<Node*>{ $1 }); }

	| type_specifier declaration_specifiers
        { $$ = new Node("DECLARATION_SPECIFIERS_NODE", vector<Node*>{ $1, $2 }); }

	| type_qualifier
        { $$ = new Node("DECLARATION_SPECIFIERS_NODE", vector<Node*>{ $1 }); }

	| type_qualifier declaration_specifiers
        { $$ = new Node("DECLARATION_SPECIFIERS_NODE", vector<Node*>{ $1, $2 }); }

	| function_specifier
        { $$ = new Node("DECLARATION_SPECIFIERS_NODE", vector<Node*>{ $1 }); }

	| function_specifier declaration_specifiers
        { $$ = new Node("DECLARATION_SPECIFIERS_NODE", vector<Node*>{ $1, $2 }); }
;


storage_class_specifier:
	EXTERN
        { $$ = new Node("STORAGE_CLASS_SPECIFIER_NODE", vector<Node*>{ new Node("EXTERN", $1) }); }

	| STATIC
        { $$ = new Node("STORAGE_CLASS_SPECIFIER_NODE", vector<Node*>{ new Node("STATIC", $1) }); }

	| AUTO
        { $$ = new Node("STORAGE_CLASS_SPECIFIER_NODE", vector<Node*>{ new Node("AUTO", $1) }); }

	| REGISTER
        { $$ = new Node("STORAGE_CLASS_SPECIFIER_NODE", vector<Node*>{ new Node("REGISTER", $1) }); }
;


init_declarator_list:
	init_declarator
        { $$ = new Node("INIT_DECLARATOR_LIST_NODE", vector<Node*>{ $1 }); }

	| init_declarator_list COMMA init_declarator
        { $$ = new Node("INIT_DECLARATOR_LIST_NODE", vector<Node*>{ $1, $3 }); }
;


init_declarator:
	declarator
        { $$ = new Node("INIT_DECLARATOR_NODE", vector<Node*>{ $1 }); }

	| declarator ASSIGN_OP initializer
        { $$ = new Node("INIT_DECLARATOR_NODE", vector<Node*>{ $1, new Node("ASSIGN_OP", $2), $3 }); }
;


initializer:
	assignment_expression
        { $$ = new Node("INITIALIZER_NODE", vector<Node*>{ $1 }); }

	| LEFT_CBRACKET initializer_list RIGHT_CBRACKET
        { $$ = new Node("INITIALIZER_NODE", vector<Node*>{ $2 }); }

	| LEFT_CBRACKET initializer_list COMMA RIGHT_CBRACKET
        { $$ = new Node("INITIALIZER_NODE", vector<Node*>{ $2 }); }
;


initializer_list:
	initializer
        { $$ = new Node("INITIALIZER_LIST_NODE", vector<Node*>{ $1 }); }

	| designation initializer
        { $$ = new Node("INITIALIZER_LIST_NODE", vector<Node*>{ $1, $2 }); }

	| initializer_list COMMA initializer
        { $$ = new Node("INITIALIZER_LIST_NODE", vector<Node*>{ $1, $3 }); }

	| initializer_list COMMA designation initializer
        { $$ = new Node("INITIALIZER_LIST_NODE", vector<Node*>{ $1, $3, $4 }); }
;


designation:
	designator_list ASSIGN_OP
        { $$ = new Node("DESIGNATION_NODE", vector<Node*>{ $1, new Node("ASSIGN_OP", $2) }); }
;


designator_list:
	designator
        { $$ = new Node("DESIGNATOR_LIST_NODE", vector<Node*>{ $1 }); }

	| designator_list designator
        { $$ = new Node("DESIGNATOR_LIST_NODE", vector<Node*>{ $1, $2 }); }
;


designator:
	LEFT_BRACKET constant_expression RIGHT_BRACKET
        { $$ = new Node("DESIGNATOR_NODE", vector<Node*>{ $2 }); }

	| DOT IDENTIFIER
        { $$ = new Node("DESIGNATOR_NODE", vector<Node*>{ new Node("IDENTIFIER", $2) }); }
;


declarator: 
    pointer direct_declarator
        { $$ = new Node("DECLARATOR_NODE", vector<Node*>{ $1, $2 }); }

	| direct_declarator
        { $$ = new Node("DECLARATOR_NODE", vector<Node*>{ $1 }); }
;


pointer:
	STAR
        { $$ = new Node("POINTER_NODE", vector<Node*>{ new Node("STAR", $1) }); }

	| STAR type_qualifier_list
        { $$ = new Node("POINTER_NODE", vector<Node*>{ new Node("STAR", $1), $2 }); }

	| STAR pointer
        { $$ = new Node("POINTER_NODE", vector<Node*>{ new Node("STAR", $1), $2 }); }

	| STAR type_qualifier_list pointer
        { $$ = new Node("POINTER_NODE", vector<Node*>{ new Node("STAR", $1), $2, $3 }); }
;


direct_declarator: 
    IDENTIFIER
        { $$ = new Node("DIRECT_DECLARATOR_NODE", vector<Node*>{ new Node("IDENTIFIER", $1) }); }

	| LEFT_PAR declarator RIGHT_PAR
        { $$ = new Node("DIRECT_DECLARATOR_NODE", vector<Node*>{ $2 }); }

	| direct_declarator LEFT_BRACKET type_qualifier_list assignment_expression RIGHT_BRACKET
        { $$ = new Node("DIRECT_DECLARATOR_NODE", vector<Node*>{ $1, $3, $4 }); }

	| direct_declarator LEFT_BRACKET type_qualifier_list RIGHT_BRACKET
        { $$ = new Node("DIRECT_DECLARATOR_NODE", vector<Node*>{ $1, $3 }); }

	| direct_declarator LEFT_BRACKET assignment_expression RIGHT_BRACKET
        { $$ = new Node("DIRECT_DECLARATOR_NODE", vector<Node*>{ $1, $3 }); }

	| direct_declarator LEFT_BRACKET STATIC type_qualifier_list assignment_expression RIGHT_BRACKET
        { $$ = new Node("DIRECT_DECLARATOR_NODE", vector<Node*>{ $1, new Node("STATIC", $3), $4, $5 }); }

	| direct_declarator LEFT_BRACKET type_qualifier_list STATIC assignment_expression RIGHT_BRACKET
        { $$ = new Node("DIRECT_DECLARATOR_NODE", vector<Node*>{ $1, $3, new Node("STATIC", $4), $5 }); }

	| direct_declarator LEFT_BRACKET type_qualifier_list STAR RIGHT_BRACKET
        { $$ = new Node("DIRECT_DECLARATOR_NODE", vector<Node*>{ $1, $3, new Node("STAR", $4) }); }

	| direct_declarator LEFT_BRACKET STAR RIGHT_BRACKET
        { $$ = new Node("DIRECT_DECLARATOR_NODE", vector<Node*>{ $1, new Node("STAR", $3) }); }

	| direct_declarator LEFT_BRACKET RIGHT_BRACKET
        { $$ = new Node("DIRECT_DECLARATOR_NODE", vector<Node*>{ $1 }); }

	| direct_declarator LEFT_PAR parameter_type_list RIGHT_PAR
        { $$ = new Node("DIRECT_DECLARATOR_NODE", vector<Node*>{ $1, $3 }); }

	| direct_declarator LEFT_PAR identifier_list RIGHT_PAR
        { $$ = new Node("DIRECT_DECLARATOR_NODE", vector<Node*>{ $1, $3 }); }

	| direct_declarator LEFT_PAR RIGHT_PAR
        { $$ = new Node("DIRECT_DECLARATOR_NODE", vector<Node*>{ $1 }); }
;


type_qualifier_list:
    type_qualifier
        { $$ = new Node("TYPE_QUALIFIER_LIST_NODE", vector<Node*>{ $1 }); }

	| type_qualifier_list type_qualifier
        { $$ = new Node("TYPE_QUALIFIER_LIST_NODE", vector<Node*>{ $1, $2 }); }
;


type_qualifier:
	CONST
        { $$ = new Node("TYPE_QUALIFIER_NODE", vector<Node*>{ new Node("CONST", $1) }); }

	| RESTRICT
        { $$ = new Node("TYPE_QUALIFIER_NODE", vector<Node*>{ new Node("RESTRICT", $1) }); }

	| VOLATILE
        { $$ = new Node("TYPE_QUALIFIER_NODE", vector<Node*>{ new Node("VOLATILE", $1) }); }
;


parameter_type_list: 
    parameter_list
        { $$ = new Node("PARAMETER_TYPE_LIST_NODE", vector<Node*>{ $1 }); }

	| parameter_list COMMA ELLIPSIS
        { $$ = new Node("PARAMETER_TYPE_LIST_NODE", vector<Node*>{ $1, new Node("ELLIPSIS", $3) }); }
;


parameter_list:
	parameter_declaration SEMICOLON
        { $$ = new Node("PARAMETER_LIST_NODE", vector<Node*>{ $1 }); }

	| parameter_list COMMA parameter_declaration
        { $$ = new Node("PARAMETER_LIST_NODE", vector<Node*>{ $1, $3 }); }
;


parameter_declaration:
	declaration_specifiers declarator
        { $$ = new Node("PARAMETER_DECLARATION_NODE", vector<Node*>{ $1, $2 }); }

	| declaration_specifiers abstract_declarator
        { $$ = new Node("PARAMETER_DECLARATION_NODE", vector<Node*>{ $1, $2 }); }

	| declaration_specifiers
        { $$ = new Node("PARAMETER_DECLARATION_NODE", vector<Node*>{ $1 }); }
;


function_specifier: 
    INLINE
        { $$ = new Node("TYPE_QUALIFIER_NODE", vector<Node*>{ new Node("INLINE", $1) }); }
;


type_specifier:
	VOID
        { $$ = new Node("TYPE_SPECIFIER_NODE", vector<Node*>{ new Node("VOID", $1) }); }

	| CHAR
        { $$ = new Node("TYPE_SPECIFIER_NODE", vector<Node*>{ new Node("CHAR", $1) }); }

	| SHORT
        { $$ = new Node("TYPE_SPECIFIER_NODE", vector<Node*>{ new Node("SHORT", $1) }); }

	| INT
        { $$ = new Node("TYPE_SPECIFIER_NODE", vector<Node*>{ new Node("INT", $1) }); }

	| LONG
        { $$ = new Node("TYPE_SPECIFIER_NODE", vector<Node*>{ new Node("LONG", $1) }); }

	| FLOAT
        { $$ = new Node("TYPE_SPECIFIER_NODE", vector<Node*>{ new Node("FLOAT", $1) }); }

	| DOUBLE
        { $$ = new Node("TYPE_SPECIFIER_NODE", vector<Node*>{ new Node("DOUBLE", $1) }); }

	| SIGNED
        { $$ = new Node("TYPE_SPECIFIER_NODE", vector<Node*>{ new Node("SIGNED", $1) }); }

	| UNSIGNED
        { $$ = new Node("TYPE_SPECIFIER_NODE", vector<Node*>{ new Node("UNSIGNED", $1) }); }

	| BOOL
        { $$ = new Node("TYPE_SPECIFIER_NODE", vector<Node*>{ new Node("BOOL", $1) }); }

	| COMPLEX
        { $$ = new Node("TYPE_SPECIFIER_NODE", vector<Node*>{ new Node("COMPLEX", $1) }); }

	| IMAGINARY
        { $$ = new Node("TYPE_SPECIFIER_NODE", vector<Node*>{ new Node("IMAGINARY", $1) }); }

	| struct_or_union_specifier
        { $$ = new Node("TYPE_SPECIFIER_NODE", vector<Node*>{ $1 }); }

	| enum_specifier
        { $$ = new Node("TYPE_SPECIFIER_NODE", vector<Node*>{ $1 }); }

	| type_name
        { $$ = new Node("TYPE_SPECIFIER_NODE", vector<Node*>{ $1 }); }
;


struct_or_union_specifier:
	struct_or_union IDENTIFIER LEFT_CBRACKET struct_declaration_list RIGHT_CBRACKET
        { $$ = new Node("STRUCT_OR_UNION_SPECIFIER_NODE", vector<Node*>{ $1, new Node("IDENTIFIER", $2), $4 }); }

	| struct_or_union LEFT_CBRACKET struct_declaration_list RIGHT_CBRACKET
        { $$ = new Node("STRUCT_OR_UNION_SPECIFIER_NODE", vector<Node*>{ $1, $3 }); }

	| struct_or_union IDENTIFIER
        { $$ = new Node("STRUCT_OR_UNION_SPECIFIER_NODE", vector<Node*>{ $1, new Node("IDENTIFIER", $2) }); }
;


struct_or_union:
	STRUCT
        { $$ = new Node("STRUCT_OR_UNION_NODE", vector<Node*>{ new Node("STRUCT", $1) }); }

	| UNION
        { $$ = new Node("STRUCT_OR_UNION_NODE", vector<Node*>{ new Node("UNION", $1) }); }
;


struct_declaration_list:
	struct_declaration
        { $$ = new Node("STRUCT_DECLARATION_LIST_NODE", vector<Node*>{ $1 }); }

	| struct_declaration_list struct_declaration
        { $$ = new Node("STRUCT_DECLARATION_LIST_NODE", vector<Node*>{ $1, $2 }); }
;


struct_declaration:
	specifier_qualifier_list struct_declarator_list SEMICOLON
        { $$ = new Node("STRUCT_DECLARATION_NODE", vector<Node*>{ $1, $2 }); }
;


struct_declarator_list:
	struct_declarator
        { $$ = new Node("STRUCT_DECLARATOR_LIST_NODE", vector<Node*>{ $1 }); }

	| struct_declarator_list COMMA struct_declarator
        { $$ = new Node("STRUCT_DECLARATOR_LIST_NODE", vector<Node*>{ $1, $3 }); }
;


struct_declarator:
	declarator
        { $$ = new Node("STRUCT_DECLARATOR_NODE", vector<Node*>{ $1 }); }

	| COLON constant_expression
        { $$ = new Node("STRUCT_DECLARATOR_NODE", vector<Node*>{ $2 }); }

	| declarator COLON constant_expression
        { $$ = new Node("STRUCT_DECLARATOR_NODE", vector<Node*>{ $1, $3 }); }
;


specifier_qualifier_list:
	type_specifier specifier_qualifier_list
        { $$ = new Node("SPECIFIER_QUALIFIER_LIST_NODE", vector<Node*>{ $1, $2 }); }

	| type_specifier
        { $$ = new Node("SPECIFIER_QUALIFIER_LIST_NODE", vector<Node*>{ $1 }); }

	| type_qualifier specifier_qualifier_list
        { $$ = new Node("SPECIFIER_QUALIFIER_LIST_NODE", vector<Node*>{ $1, $2 }); }

	| type_qualifier
        { $$ = new Node("SPECIFIER_QUALIFIER_LIST_NODE", vector<Node*>{ $1 }); }
;


enum_specifier: 
    ENUM LEFT_CBRACKET enumerator_list RIGHT_CBRACKET
        { $$ = new Node("ENUM_SPECIFIER_NODE", vector<Node*>{ new Node("ENUM", $1), $3 }); }

	| ENUM IDENTIFIER LEFT_CBRACKET enumerator_list RIGHT_CBRACKET
        { $$ = new Node("ENUM_SPECIFIER_NODE", vector<Node*>{ new Node("ENUM", $1), new Node("IDENTIFIER", $2), $4 }); }

	| LEFT_CBRACKET enumerator_list COMMA RIGHT_CBRACKET
        { $$ = new Node("ENUM_SPECIFIER_NODE", vector<Node*>{ $2 }); }

	| ENUM IDENTIFIER LEFT_CBRACKET enumerator_list COMMA RIGHT_CBRACKET
        { $$ = new Node("ENUM_SPECIFIER_NODE", vector<Node*>{ new Node("ENUM", $1), new Node("IDENTIFIER", $2), $4 }); }

	| ENUM IDENTIFIER
        { $$ = new Node("ENUM_SPECIFIER_NODE", vector<Node*>{ new Node("ENUM", $1), new Node("IDENTIFIER", $2) }); }
;


enumerator_list:
	enumerator
        { $$ = new Node("ENUMERATOR_LIST_NODE", vector<Node*>{ $1 }); }

	| enumerator_list COMMA enumerator
        { $$ = new Node("ENUMERATOR_LIST_NODE", vector<Node*>{ $1, $3 }); }
;


enumerator: 
    IDENTIFIER
        { $$ = new Node("ENUMERATOR_NODE", vector<Node*>{ $1 }); }

	| IDENTIFIER ASSIGN_OP constant_expression
        { $$ = new Node("ENUMERATOR_NODE", vector<Node*>{ new Node("IDENTIFIER", $1), new Node("ASSIGN_OP", $2), $3 }); }
;


type_name:
	specifier_qualifier_list
        { $$ = new Node("TYPE_NAME_NODE", vector<Node*>{ $1 }); }

	| specifier_qualifier_list abstract_declarator
        { $$ = new Node("TYPE_NAME_NODE", vector<Node*>{ $1, $2 }); }
;


abstract_declarator:
	pointer
        { $$ = new Node("ABSTRACT_DECLARATOR_NODE", vector<Node*>{ $1 }); }

	| direct_abstract_declarator
        { $$ = new Node("ABSTRACT_DECLARATOR_NODE", vector<Node*>{ $1 }); }

	| pointer direct_abstract_declarator
        { $$ = new Node("ABSTRACT_DECLARATOR_NODE", vector<Node*>{ $1, $2 }); }
;


direct_abstract_declarator:
	LEFT_PAR abstract_declarator RIGHT_PAR
        { $$ = new Node("DIRECT_ABSTRACT_DECLARATOR_NODE", vector<Node*>{ $2 }); }

	| LEFT_BRACKET RIGHT_BRACKET
        { $$ = new Node("DIRECT_ABSTRACT_DECLARATOR_NODE", vector<Node*>{}); }

	| LEFT_BRACKET assignment_expression RIGHT_BRACKET
        { $$ = new Node("DIRECT_ABSTRACT_DECLARATOR_NODE", vector<Node*>{ $2 }); }

	| direct_abstract_declarator LEFT_BRACKET RIGHT_BRACKET
        { $$ = new Node("DIRECT_ABSTRACT_DECLARATOR_NODE", vector<Node*>{ $1 }); }

	| direct_abstract_declarator LEFT_BRACKET assignment_expression RIGHT_BRACKET
        { $$ = new Node("DIRECT_ABSTRACT_DECLARATOR_NODE", vector<Node*>{ $1, $3 }); }

	| LEFT_BRACKET STAR RIGHT_BRACKET
        { $$ = new Node("DIRECT_ABSTRACT_DECLARATOR_NODE", vector<Node*>{ new Node("STAR", $2) }); }

	| direct_abstract_declarator LEFT_BRACKET STAR RIGHT_BRACKET
        { $$ = new Node("DIRECT_ABSTRACT_DECLARATOR_NODE", vector<Node*>{ $1, new Node("STAR", $3) }); }

	| LEFT_PAR RIGHT_PAR
        { $$ = new Node("DIRECT_ABSTRACT_DECLARATOR_NODE", vector<Node*>{}); }

	| LEFT_PAR parameter_type_list RIGHT_PAR
        { $$ = new Node("DIRECT_ABSTRACT_DECLARATOR_NODE", vector<Node*>{ $2 }); }

	| direct_abstract_declarator LEFT_PAR RIGHT_PAR
        { $$ = new Node("DIRECT_ABSTRACT_DECLARATOR_NODE", vector<Node*>{ $1 }); }

	| direct_abstract_declarator LEFT_PAR parameter_type_list RIGHT_PAR
        { $$ = new Node("DIRECT_ABSTRACT_DECLARATOR_NODE", vector<Node*>{ $1, $3 }); }
;


statement:
	labeled_statement
        { $$ = new Node("STATEMENT_NODE", vector<Node*>{ $1 }); }

	| compound_statement
        { $$ = new Node("STATEMENT_NODE", vector<Node*>{ $1 }); }

	| expression_statement
        { $$ = new Node("STATEMENT_NODE", vector<Node*>{ $1 }); }

	| selection_statement
        { $$ = new Node("STATEMENT_NODE", vector<Node*>{ $1 }); }

	| iteration_statement
        { $$ = new Node("STATEMENT_NODE", vector<Node*>{ $1 }); }

	| jump_statement
        { $$ = new Node("STATEMENT_NODE", vector<Node*>{ $1 }); }
;


labeled_statement:
	IDENTIFIER COLON statement
        { $$ = new Node("LABELED_STATEMENT_NODE", vector<Node*>{ new Node("IDENTIFIER", $1), $3 }); }

	| CASE constant_expression COLON statement
        { $$ = new Node("LABELED_STATEMENT_NODE", vector<Node*>{ new Node("CASER", $1), $2, $4 }); }

	| DEFAULT COLON statement
        { $$ = new Node("LABELED_STATEMENT_NODE", vector<Node*>{ new Node("DEFAULT", $1), $3 }); }
;


compound_statement:
	LEFT_CBRACKET RIGHT_CBRACKET
        { $$ = new Node("COMPOUND_STATEMENT_NODE", vector<Node*>{}); }

	| LEFT_CBRACKET block_item_list RIGHT_CBRACKET
        { $$ = new Node("COMPOUND_STATEMENT_NODE", vector<Node*>{ $2 }); }
;


block_item_list:
	block_item
        { $$ = new Node("BLOCK_ITEM_LIST_NODE", vector<Node*>{ $1 }); }

	| block_item_list block_item
        { $$ = new Node("BLOCK_ITEM_LIST_NODE", vector<Node*>{ $1, $2 }); }
;


block_item:
	declaration
        { $$ = new Node("BLOCK_ITEM_NODE", vector<Node*>{ $1 }); }

	| statement
        { $$ = new Node("BLOCK_ITEM_NODE", vector<Node*>{ $1 }); }
;


expression_statement:
	SEMICOLON
        { $$ = new Node("EXPRESSION_STATEMENT_NODE", vector<Node*>{}); }

	| expression SEMICOLON
        { $$ = new Node("EXPRESSION_STATEMENT_NODE", vector<Node*>{ $1 }); }
;


selection_statement:
	IF LEFT_PAR expression RIGHT_PAR statement
        { $$ = new Node("SELECTION_STATEMENT_NODE", vector<Node*>{ new Node("IF", $1), $3, $5 }); }

	| IF LEFT_PAR expression RIGHT_PAR statement ELSE statement
        { $$ = new Node("SELECTION_STATEMENT_NODE", vector<Node*>{ new Node("IF", $1), $3, $5, new Node("ELSE", $6), $7 }); }

	| SWITCH LEFT_PAR expression RIGHT_PAR statement
        { $$ = new Node("SELECTION_STATEMENT_NODE", vector<Node*>{ new Node("SWITCH", $1), $3, $5 }); }
;


iteration_statement:
	WHILE LEFT_PAR expression RIGHT_PAR statement
        { $$ = new Node("ITERATION_STATEMENT_NODE", vector<Node*>{ new Node("WHILE", $1), $3, $5 }); }

	| DO statement WHILE LEFT_PAR expression RIGHT_PAR SEMICOLON
        { $$ = new Node("ITERATION_STATEMENT_NODE", vector<Node*>{ new Node("DO", $1), $2, new Node("WHILE", $3), $5 }); }

	| FOR LEFT_PAR expression_statement expression_statement RIGHT_PAR statement
        { $$ = new Node("ITERATION_STATEMENT_NODE", vector<Node*>{ new Node("FOR", $1), $3, $4, $6 }); }

	| FOR LEFT_PAR expression_statement expression_statement expression RIGHT_PAR statement
        { $$ = new Node("ITERATION_STATEMENT_NODE", vector<Node*>{ new Node("FOR", $1), $3, $4, $5, $7 }); }

	| FOR LEFT_PAR declaration expression_statement RIGHT_PAR statement
        { $$ = new Node("ITERATION_STATEMENT_NODE", vector<Node*>{ new Node("FOR", $1), $3, $4, $6 }); }

	| FOR LEFT_PAR declaration expression_statement expression RIGHT_PAR statement
        { $$ = new Node("ITERATION_STATEMENT_NODE", vector<Node*>{ new Node("FOR", $1), $3, $4, $5, $7 }); }
;


jump_statement: 
	GOTO IDENTIFIER SEMICOLON
        { $$ = new Node("JUMP_STATEMENT_NODE", vector<Node*>{ new Node("GOTO", $1), new Node("IDENTIFIER", $2) }); }

	| CONTINUE SEMICOLON
        { $$ = new Node("JUMP_STATEMENT_NODE", vector<Node*>{ new Node("CONTINUE", $1) }); }

	| BREAK SEMICOLON
        { $$ = new Node("JUMP_STATEMENT_NODE", vector<Node*>{ new Node("BREAK", $1) }); }

	| RETURN SEMICOLON
        { $$ = new Node("JUMP_STATEMENT_NODE", vector<Node*>{ new Node("RETURN", $1) }); }

	| RETURN expression SEMICOLON
        { $$ = new Node("JUMP_STATEMENT_NODE", vector<Node*>{ new Node("RETURN", $1), $2 }); }
;


translation_unit:
	external_declaration
        { $$ = new Node("TRANSLATION_UNIT_NODE", vector<Node*>{ $1 }); }

	| translation_unit external_declaration
        { $$ = new Node("TRANSLATION_UNIT_NODE", vector<Node*>{ $1, $2 }); }
;


external_declaration:
	function_definition
        { $$ = new Node("EXTERNAL_DECLARATION_NODE", vector<Node*>{ $1 }); }

	| declaration
        { $$ = new Node("EXTERNAL_DECLARATION_NODE", vector<Node*>{ $1 }); }
;


function_definition:
	declaration_specifiers declarator declaration_list compound_statement
        { $$ = new Node("FUNCTION_DEFINITION_NODE", vector<Node*>{ $1, $2, $3, $4 }); }

	| declaration_specifiers declarator compound_statement
        { $$ = new Node("FUNCTION_DEFINITION_NODE", vector<Node*>{ $1, $2, $3 }); }
;


declaration_list: 
    declaration
        { $$ = new Node("DECLARATION_LIST_NODE", vector<Node*>{ $1 }); }

	| declaration_list declaration
        { $$ = new Node("DECLARATION_LIST_NODE", vector<Node*>{ $1, $2 }); }
;


identifier_list:
	IDENTIFIER
        { $$ = new Node("IDENTIFIER_LIST_NODE", vector<Node*>{ new Node("IDENTIFIER", $1) }); }

	| identifier_list COMMA IDENTIFIER
        { $$ = new Node("IDENTIFIER_LIST_NODE", vector<Node*>{ $1, new Node("IDENTIFIER", $3) }); }
;


%%

// Epilogue

namespace yy

int main () {
    yy::parser parse;
    return parse ();
}