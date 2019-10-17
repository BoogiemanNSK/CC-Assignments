import re

INPUT_FILE = "temp_syntax.yy"

tokens_defs = {
    "keywords" : [
        "AUTO",
        "BOOL",
        "BREAK",
        "CASE",
        "CHAR",
        "COMPLEX",
        "CONST",
        "CONTINUE",
        "DEFAULT",
        "DO",
        "DOUBLE",
        "ELSE",
        "ENUM",
        "EXTERN",
        "FLOAT",
        "FOR",
        "GOTO",
        "IF",
        "IMAGINARY",
        "INLINE",
        "INT",
        "LONG",
        "REGISTER",
        "RESTRICT",
        "RETURN",
        "SHORT",
        "SIGNED",
        "SIZEOF",
        "STATIC",
        "STRUCT",
        "SWITCH",
        "TYPEDEF",
        "UNION",
        "UNSIGNED",
        "VOID",
        "VOLATILE",
        "WHILE",
    ],

    "identifier" : [
        "IDENTIFIER",
    ],

    "literal" : [
        "LITERAL"
    ],

    "string_literal" : [
        "STRING_LITERAL"
    ],

    "delimeters" : [
        "SEMICOLON",
        "COMMA",
        "COLON",
        "LEFT_PAR",
        "RIGHT_PAR",
        "DOT",
        "LEFT_CBRACKET",
        "RIGHT_CBRACKET",
        "LEFT_BRACKET",
        "RIGHT_BRACKET",
    ],

    "operators" : [
        "ASSIGN_OP",
        "AMP",
        "LOG_NOT_OP",
        "BIN_NOT_OP",
        "MINUS",
        "PLUS",
        "STAR",
        "SLASH",
        "MOD_OP",
        "G_OP",
        "L_OP",
        "BIN_XOR_OP",
        "BIN_OR_OP",
        "TERNARY_OP",
        "ELLIPSIS",
        "RIGHT_ASSIGN",
        "LEFT_ASSIGN",
        "ADD_ASSIGN",
        "SUB_ASSIGN",
        "MUL_ASSIGN",
        "DIV_ASSIGN",
        "MOD_ASSIGN",
        "AND_ASSIGN",
        "XOR_ASSIGN",
        "OR_ASSIGN",
        "RIGHT_OP",
        "LEFT_OP",
        "INC_OP",
        "DEC_OP",
        "PTR_OP",
        "AND_OP",
        "OR_OP",
        "LE_OP",
        "GE_OP",
        "EQ_OP",
        "NE_OP",
    ],
}

file_prefix = """%language "c++"

%code top {
   #include <vector>
   #include <string>
   #include <iostream> 
   #include <sstream>
   // #include "bis_out.hpp"
   // #include "stack.hh"

   using namespace std;

   class AstNode {
      public:
         vector<AstNode*> children;
         string name;
         
         AstNode(string _name, vector<AstNode*> _children) {
               children = _children;
               name = _name;
         }

         AstNode(string _name){
               children = vector<AstNode*>();
               name = _name;
         }
         
         void print_tree() {
               cout << this->get_ident();
               for (int i = 0; i < children.size(); i++) {
                  cout << " " << children[i]->get_ident();
               }
               cout << endl;
               for (int i = 0; i < children.size(); i++) {
                  children[i] -> print_tree();
               }
         }

         string get_ident() {
               ostringstream buffer;
               buffer << this << "_" << name;
               string res = string(buffer.str());
               return(res);
         }

   };

   typedef AstNode* AstNodePtr;
}


%define api.value.type variant

// Tokens

// Keywords
%token  <string>  AUTO
%token  <string>  BOOL
%token  <string>  BREAK
%token  <string>  CASE
%token  <string>  CHAR
%token  <string>  COMPLEX
%token  <string>  CONST
%token  <string>  CONTINUE
%token  <string>  DEFAULT
%token  <string>  DO
%token  <string>  DOUBLE
%token  <string>  ELSE
%token  <string>  ENUM
%token  <string>  EXTERN
%token  <string>  FLOAT
%token  <string>  FOR
%token  <string>  GOTO
%token  <string>  IF
%token  <string>  IMAGINARY
%token  <string>  INLINE
%token  <string>  INT
%token  <string>  LONG
%token  <string>  REGISTER
%token  <string>  RESTRICT
%token  <string>  RETURN
%token  <string>  SHORT
%token  <string>  SIGNED
%token  <string>  SIZEOF
%token  <string>  STATIC
%token  <string>  STRUCT
%token  <string>  SWITCH
%token  <string>  TYPEDEF
%token  <string>  UNION
%token  <string>  UNSIGNED
%token  <string>  VOID
%token  <string>  VOLATILE
%token  <string>  WHILE

%token <string> IDENTIFIER

%token <string> LITERAL // Numeric literal

%token <string> STRING_LITERAL  // String literal

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

%token  <string>  SEMICOLON ";"
%token  <string>  COMMA ","
%token  <string>  COLON ":"
%token  <string>  LEFT_PAR "("
%token  <string>  RIGHT_PAR ")"
%token  <string>  DOT "."
%token  <string>  LEFT_CBRACKET "{"
%token  <string>  RIGHT_CBRACKET "}"
%token  <string>  LEFT_BRACKET "["
%token  <string>  RIGHT_BRACKET "]"

// Operators

%token  <string>  ASSIGN_OP "="
%token  <string>  AMP "&"
%token  <string>  LOG_NOT_OP "!"
%token  <string>  BIN_NOT_OP "~"
%token  <string>  MINUS "-"
%token  <string>  PLUS "+"
%token  <string>  STAR "*"
%token  <string>  SLASH "/"
%token  <string>  MOD_OP "%"
%token  <string>  G_OP "<"
%token  <string>  L_OP ">"
%token  <string>  BIN_XOR_OP "^"
%token  <string>  BIN_OR_OP "|"
%token  <string>  TERNARY_OP "?"


%token  <string>  ELLIPSIS "..."
%token  <string>  RIGHT_ASSIGN ">>="
%token  <string>  LEFT_ASSIGN "<<="
%token  <string>  ADD_ASSIGN "+="
%token  <string>  SUB_ASSIGN "-="
%token  <string>  MUL_ASSIGN "*="
%token  <string>  DIV_ASSIGN "/="
%token  <string>  MOD_ASSIGN "%="
%token  <string>  AND_ASSIGN "&="
%token  <string>  XOR_ASSIGN "^="
%token  <string>  OR_ASSIGN "|="
%token  <string>  RIGHT_OP ">>"
%token  <string>  LEFT_OP "<<"
%token  <string>  INC_OP "++"
%token  <string>  DEC_OP "--"
%token  <string>  PTR_OP "->"
%token  <string>  AND_OP "&&"
%token  <string>  OR_OP "||"
%token  <string>  LE_OP "<="
%token  <string>  GE_OP ">="
%token  <string>  EQ_OP "=="
%token  <string>  NE_OP "!="

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


"""

file_postfix = """
%%

// Epilogue

namespace yy{

    int main ()
        {
            yy::parser parse;
            return parse.parse ();
        }

};
"""


if __name__ == "__main__":
    input_syntax = ""

    with open(INPUT_FILE, "r") as f:
        input_syntax = f.read()
    
    # Removing existing actions
    input_syntax = re.sub(r"({.*?})", "", input_syntax)

    # Find token to type map
    tokens = {}
    for token_type, tokens_list in tokens_defs.items():
        for name in tokens_list:
            tokens[name] = token_type

    # Need to find iteratively grammar and add semantic actions
    # First, separate grammars and its defenitions from each other
    grammars_strs = re.findall(r"\s*?([\w|_]*?):((\s|\S)*?);", input_syntax)

    # Derive specific rules
    grammars = []
    for g_str in grammars_strs:
        name = g_str[0].strip()
        rules = g_str[1]
        grammars.append((name, [s.strip() for s in rules.split("|")]))
    
    # Generate semantic actions
    res = []
    for g_name, g_rules in grammars:
        rules = []
        for rule in g_rules:
            names = rule.strip().split()
            action = ""

            # Generating action for the rule
            # Find if it is recursive one
            rec_idx = -1
            if g_name in names:
                rec_idx = names.index(g_name) + 1
            
            constructor_arg = []
            for idx, ident in enumerate(names):
                if idx == rec_idx:
                    continue
                if ident in tokens.keys():
                    constructor_arg.append("new AstNode(string(\"{}_{}\"), {{}})".format(tokens[ident], ident))
                else:
                    constructor_arg.append("${}".format(idx + 1))
            
            if rec_idx == -1:
                action = "$$ = new AstNode(string(\"{}\"), {{ {} }});".format(g_name, ",".join(constructor_arg))
            else:
                for child in constructor_arg:
                    action = action + "${}->children.push_back({});".format(rec_idx, child)
                action += "$$ = ${};".format(rec_idx)
            
            action = "{" + action + "}"

            rules.append((names, action))
            

        res.append((g_name, rules))

    # Printing the result
    print(file_prefix + "\n")
    for g_name, g_rules in res:
        print("{}:".format(g_name))
        for rule, action in g_rules[:-1]:
            print("   {} {} \n|".format(" ".join(rule), action), end="")
        print("   {} {}\n;".format(" ".join(g_rules[-1][0]), g_rules[-1][1]))
        print("")
    print(file_postfix + "\n")
