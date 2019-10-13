%language "c++"

%code top {
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
            
            Node(vector<Node*> _children, Node* _parent) {
                children = _children;
                parent = _parent;
            }
            
            Node() {
                children = vector<Node*>(1);
                parent = NULL;
            }

            void print_tree() {
                cout << this << "_" << name;
                for (int i = 0; i < children.size(); i++) {
                    cout << " " << children[i] << "_" << children[i]->print();
                }
                cout << endl;
            }

            virtual string print() = 0;
    };

    class PrimaryExpressionNode : public Node {
        public:
            string print() {
                return("PrimaryExpressionNode");
            }

            PrimaryExpressionNode(Node* expr) {
                children = {expr};
            }
    };

    class IdentifierNode : public Node {
        public:
            string ident;

            string print() {
                return("IDENT(" + ident + ")");
            }

            IdentifierNode(string _ident) {
                ident = _ident;
            }
    };

    class NumericLiteralNode : public Node {
        public:
            string num;

            string print() {
                return("NUMLITERAL(" + num + ")");
            }

            NumericLiteralNode(string _num) {
                num = _num;
            }
    };

    class StrLiteralNode : public Node {
        public:
            string val;

            string print() {
                return("STRLITERAL(" + val + ")");
            }

            StrLiteralNode(string _val) {
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
                return(prefix + node->print() + suffix);
            }

            CastExpressionNode(Node* node) {
                CastExpressionNode::node = node;
                CastExpressionNode::typeName = "";
            }
            
            CastExpressionNode(string typeName, Node* node) {
                CastExpressionNode::node = node;
                CastExpressionNode::typeName = typeName;
            }
    };

    class BinaryExpressionNode : public Node {
        public:
            vector<string> ops;
            string _exprType;

            string print() {
                string res = _exprType + "(" + children[0]->print();
                for (int i = 0; i < ops.size(); i++) {
                    res += (" " + ops[i] + " ");
                    res += children[i + 1]->print();
                }
                res += ")";
                return res;
            }

            BinaryExpressionNode(Node* node) {
                children = vector<Node*>{node};
                ops = vector<string>();
            }

            BinaryExpressionNode(Node* node, Node* n2) {
                children = vector<Node*>{node,n2};
                ops = vector<string>();
            }
    };

    class OperatorNode : public Node {
        public:
            string _sign;

             string print() {
                return("OPERATOR(" + _sign + ")");
            } 

            OperatorNode(string sign) {
                _sign = sign;
            }
    };

    class KeywordNode : public Node {
        public:
            string _sign;

            string print() {
                return("Keyword(" + _sign + ")");
            } 

            KeywordNode(string sign) {
                _sign = sign;
            }
    };

    class PostfixExpressionNode : public Node {
        public:
            string print() {
                return("PostfixExpressionNode");
            }

            PostfixExpressionNode(Node* n1) {
                children = vector<Node*>{n1};
            }

            PostfixExpressionNode(Node* n1, Node* n2) {
                children = vector<Node*>{n1, n2};
            }
    };

    class ArgumentExpressionListNode: public Node {
        public:
            string print() {
                return("ArgumentExpressionList");
            }

            ArgumentExpressionListNode(Node* n1) {
                children = vector<Node*>{n1};
            }
    };

    class ExpressionNode: public Node {
        public:
            string print(){
                return("ExpressionNode");
            }

         ExpressionNode(Node* n1){
            children = vector<Node*>{n1};

        }
    };

    class UnaryExpressionNode : public Node{
        public:
            string print(){
                return("UnaryExpressionNode");
            }

          UnaryExpressionNode(Node* n1){
            children = vector<Node*>{n1};

        }
    };

    class  UnaryOperatorNode: public Node{
        public:
            string print(){
                return("UnaryOperatorNode");
            }

          UnaryOperatorNode(Node* n1){
            children = vector<Node*>{n1};

        }
    };

    


    class ConditionalExpressionNode: public Node{
        public:

            string print(){
                return("ConditionalExpressionNode");
            }
        ConditionalExpressionNode(Node* n1){
            children = vector<Node*>{n1};

        }
         ConditionalExpressionNode(Node* n1,Node* n2,Node* n3){
            children = vector<Node*>{n1,n2,n3};

        }
    };
    class AssignmentExpressionNode: public Node{
        public:

            string print(){
                return("AssignmentExpressionNode");
            }
        AssignmentExpressionNode(Node* n1){
            children = vector<Node*>{n1};

        }
        AssignmentExpressionNode(Node* n1,Node* n2,Node* n3){
            children = vector<Node*>{n1,n2,n3};

        }
    };
    class ConstantExpressionNode: public Node{
        public:
            string print(){
                return("ConstantExpressionNode");
            }

         ConstantExpressionNode(Node* n1){
            children = vector<Node*>{n1};

        }
    };

    class DeclarationNode: public Node{
            public:
            string print(){
                return("DeclarationNode");
            }

         DeclarationNode(Node* n1){
            children = vector<Node*>{n1};

        }
        DeclarationNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    };

    class DeclarationSpecifiersNode: public Node{
            public:
            string print(){
                return("DeclarationSpecifiersNode");
            }

         DeclarationSpecifiersNode(Node* n1){
            children = vector<Node*>{n1};

        }
        DeclarationSpecifiersNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    };

    class FunctionSpecifierNode:public Node{
            public:
            string print(){
                return("FunctionSpecifierNode");
            }

        FunctionSpecifierNode(Node* n1){
            children = vector<Node*>{n1};

        }
    };
    
    class TypeSpecifierNode:public Node{
            public:
            string print(){
                return("TypeSpecifierNode");
            }

        TypeSpecifierNode(Node* n1){
            children = vector<Node*>{n1};

        }
    };

    class StructOrUnionSpecifierNode: public Node{
            public:
            string print(){
                return("StructOrUnionSpecifierNode");
            }

        StructOrUnionSpecifierNode(Node* n1,Node* n2, Node* n3){
            children = vector<Node*>{n1,n2,n3};

        }
        StructOrUnionSpecifierNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    };

    class  StructDeclarationListNode: public Node{
            public:
            string print(){
                return("StructDeclarationListNode");
            }

        StructDeclarationListNode(Node* n1){
            children = vector<Node*>{n1};

        }
         StructDeclarationListNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    };

    class  StructDeclarationNode: public Node{
            public:
            string print(){
                return("StructDeclarationNode");
            }

        StructDeclarationNode(Node* n1){
            children = vector<Node*>{n1};

        }
         StructDeclarationNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    };

    class StructDeclaratorListNode: public Node{
            public:
            string print(){
                return("StructDeclaratorListNode");
            }

        StructDeclaratorListNode(Node* n1){
            children = vector<Node*>{n1};

        }
         StructDeclaratorListNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    };

        class StructDeclaratorNode: public Node{
            public:
            string print(){
                return("StructDeclaratorNode");
            }

        StructDeclaratorNode(Node* n1){
            children = vector<Node*>{n1};

        }
         StructDeclaratorNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    };


    class SpecifierQualifierListNode : public Node {
    public:
        string print() {
            return("SpecifierQualifierListNode");
        }

        SpecifierQualifierListNode(Node* n1) {
            children = vector<Node*>{n1};
        }

        SpecifierQualifierListNode(Node* n1,Node* n2) {
            children = vector<Node*>{n1, n2};
        }
    };

    class EnumSpecifierNode : public Node {
    public:
        string print() {
            return("EnumSpecifierNode");
        }

        EnumSpecifierNode(Node* n1, Node* n2, Node* n3) {
            children = vector<Node*>{n1, n2, n3};
        }

        EnumSpecifierNode(Node* n1, Node* n2) {
            children = vector<Node*>{n1, n2};
        }
    };

    class EnumeratorNode: public Node {
    public:
        string print() {
            return("EnumeratorNode");
        }

         EnumeratorNode(Node* n1){
            children = vector<Node*>{n1};

        }
        EnumeratorNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    };

    class TypeNameNode: public Node {
        public:
            string print(){
                return("TypeNameNode");
            }

         TypeNameNode(Node* n1){
            children = vector<Node*>{n1};

        }
        TypeNameNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    };

    class AbstractDeclaratorNode :  public Node {
        public:
            string print(){
                return("AbstractDeclaratorNode");
            }

        AbstractDeclaratorNode(Node* n1){
            children = vector<Node*>{n1};

        }
        AbstractDeclaratorNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    };

    class DirectAbstractDeclaratorNode : public Node {
        public:
            string print() {
                return("DirectAbstractDeclaratorNode");
            }

            DirectAbstractDeclaratorNode(Node* n1) {
                children = vector<Node*>{n1};
            }

            DirectAbstractDeclaratorNode(Node* n1,Node* n2) {
                children = vector<Node*>{n1, n2};
            }
    };

    class  EnumeratorListNode :public Node {
        public:
            string print(){
                return("EnumeratorListNode");
            }

        EnumeratorListNode(Node* n1){
            children = vector<Node*>{n1};

        }
    };

    class InitDeclaratorListNode: public Node{
            public:
            string print(){
                return("InitDeclaratorListNode");
            }

        InitDeclaratorListNode(Node* n1){
            children = vector<Node*>{n1};

        }
        InitDeclaratorListNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    };

    class StorageClassSpecifierNode: public Node{
        public:
            string print(){
                return("StorageClassSpecifierNode");
            }

         StorageClassSpecifierNode(Node* n1){
            children = vector<Node*>{n1};

        }
    };

    class InitDeclaratorNode :public Node{
        public:
            string print(){
                return("InitDeclaratorNode");
            }

        InitDeclaratorNode(Node* n1){
            children = vector<Node*>{n1};

        }
        InitDeclaratorNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    };

    class InitializerNode : public Node{
        public:
            string print(){
                return("InitializerNode");
            }

         InitializerNode(Node* n1){
            children = vector<Node*>{n1};

        }
    };

    class InitializerListNode : public Node{
        public:
            string print(){
                return("InitializerListNode");
            }

         InitializerListNode(Node* n1){
            children = vector<Node*>{n1};

        }
    };

    class DesignatorNode: public Node{
        public:
            string print(){
                return("DesignatorNode");
            }

         DesignatorNode(Node* n1){
            children = vector<Node*>{n1};

        }
    };

    class DesignatorListNode: public Node{
        public:
            string print(){
                return("DesignatorNode");
            }

         DesignatorListNode(Node* n1){
            children = vector<Node*>{n1};

        }
     DesignatorListNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    };

    class DesignationNode: public Node{
        public:
            string print(){
                return("DesignationNode");
            }

         DesignationNode(Node* n1){
            children = vector<Node*>{n1};

        }
    };

    class DeclaratorNode: public Node{
        public:
            string print(){
                return("DeclaratorNode");
            }

         DeclaratorNode(Node* n1){
            children = vector<Node*>{n1};

        }
        DeclaratorNode(Node* n1,Node* n2){
            children = vector<Node*>{n1, n2};

        }
    };

    class PointerNode : public Node
    {
        public:
            string print(){
                return("PointerNode");
            }

        PointerNode(Node* n1){
            children = vector<Node*>{n1};

        }
        PointerNode(Node* n1,Node* n2){
            children = vector<Node*>{n1, n2};

        }
        PointerNode(){
        }
    };

    class DirectDeclaratorListNode: public Node
    {
        public:
            string print(){
                return("DirectDeclaratorList");
            }

       DirectDeclaratorListNode(Node* n1){
            children = vector<Node*>{n1};

        }
       DirectDeclaratorListNode(Node* n1,Node* n2){
            children = vector<Node*>{n1, n2};

        }
       DirectDeclaratorListNode(){
        }
    };


    class TypeQualifierListNode :  public Node{
        public:
            string print(){
                return("TypeQualifieListNode");
            }

         TypeQualifierListNode(){

        }
    };

    class TypeQualifierNode : public Node{
        public:
            string print(){
                return("TypeQualifierNode");
            }

        TypeQualifierNode(Node* n1){
            children = vector<Node*>{n1};

        }
    };

    class ParameterClassList:public Node{
        public:
            string print(){
                return(" ParameterClassList");
            }

         ParameterClassList(Node* n2, Node* n1){
            children = vector<Node*>{n2,n1};

        }
        ParameterClassList(Node* n2){
            children = vector<Node*>{n2};

        }
    };

    class  ParameterListNode : public Node{
        public:
            string print(){
                return("ParameterListNode");
            }

       ParameterListNode(Node* n1){
            children = vector<Node*>{n1};

        }
    };

    class ParameterDeclarationNode : public Node{
        public:
            string print(){
                return("ParameterDeclarationList");
            }

       ParameterDeclarationNode(Node* n1){
            children = vector<Node*>{n1};

        }
       ParameterDeclarationNode(Node* n1,Node* n2){
            children = vector<Node*>{n1, n2};

        }

    };
}


%define api.value.type union

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
    | LEFT_PAR expression RIGHT_PAR    { $$ = new PrimaryExpressionNode(NULL); }
;

postfix_expression:
      primary_expression { $$ = new PostfixExpressionNode($1);}
    | postfix_expression LEFT_BRACKET expression RIGHT_BRACKET {$1->children.push_back($3); $$ = $1 ;}
    | postfix_expression LEFT_PAR argument_expression_list RIGHT_PAR
    | postfix_expression LEFT_PAR RIGHT_PAR{$$ = $1;}
    | postfix_expression DOT IDENTIFIER {$1->children.push_back(new IdentifierNode($3)); $$ = $1 ;}
    | postfix_expression PTR_OP IDENTIFIER {$1 -> children.push_pack(new OperatorNode( $2 ));$1->children.push_back(new IdentifierNode($3)); $$=$1;}
    | postfix_expression INC_OP {$1 -> children.push_pack(new OperatorNode($2)); $$=$1;}
    | postfix_expression DEC_OP {$1 -> children.push_pack(new OperatorNode($2)); $$=$1;}
    | LEFT_PAR type_name RIGHT_PAR LEFT_CBRACKET initializer_list RIGHT_CBRACKET { $$ = new PostfixExpressionNode($2,$5);}
    | LEFT_PAR type_name RIGHT_PAR LEFT_CBRACKET initializer_list COMMA RIGHT_CBRACKET {$$= new PostfixExpressionNode($2,$5);}
;

argument_expression_list:
      IDENTIFIER{$$ = new ArgumentExpressionList(new IdentifierNode($1));}
    | IDENTIFIER COMMA argument_expression_list {$3->children.push_back(new IdentifierNode($1)); $$=$3;}
;

unary_expression:
      postfix_expression {$$ = new UnaryExpressionNode(new PostfixExpressionNode($1));}
    | INC_OP unary_expression {$2 -> children.push_pack(new OperatorNode($1)); $$=$2;}
    | DEC_OP unary_expression {$2 -> children.push_pack((new OperatorNode($1)); $$=$2;}
    | unary_operator cast_expression {$1 ->children.push_back(new CastExpressionNode($2)); $$ = $1;}
    | SIZEOF unary_expression {$2 -> children.push_pack(new OperatorNode($1)); $$=$2;}
    | SIZEOF LEFT_PAR type_name RIGHT_PAR {$$ = new UnaryExpressionNode("(new OperatorNode($1)", $3);}
;

unary_operator:
      AMP{$$ = new UnaryOperatorNode(new OperatorNode($1);}
    | STAR{$$ = new UnaryOperatorNode(new OperatorNode($1);}
    | PLUS{$$ = new UnaryOperatorNode(new OperatorNode($1);}
    | MINUS{$$ = new UnaryOperatorNode(new OperatorNode($1);}
    | BIN_NOT_OP{$$ = new UnaryOperatorNode(new OperatorNode($1);}
    | LOG_NOT_OP{$$ = new UnaryOperatorNode(new OperatorNode($1);}
;

cast_expression:
      unary_expression { $$ = new CastExpressionNode($1) }
    | LEFT_PAR type_name RIGHT_PAR cast_expression { $$ = new CastExpressionNode($2, $4); }
;

multiplicative_expression:
      cast_expression { $$ = new BinaryExpressionNode($1); }
    | multiplicative_expression STAR cast_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
    | multiplicative_expression SLASH cast_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
    | multiplicative_expression MOD_OP cast_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
;

additive_expression:
      multiplicative_expression { $$ = new BinaryExpressionNode($1); }
    | additive_expression PLUS multiplicative_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
    | additive_expression MINUS multiplicative_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
;

shift_expression:
      additive_expression { $$ = new BinaryExpressionNode($1); }
    | shift_expression LEFT_OP additive_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
    | shift_expression RIGHT_OP additive_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
;

relational_expression:
      shift_expression { $$ = new BinaryExpressionNode($1) ;}
    | relational_expression L_OP shift_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
    | relational_expression G_OP shift_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
    | relational_expression LE_OP shift_expression { $$ = $1->children.push_back($3); $$ = $1->children.push_back(new OperatorNode($2)); $1->ops.push_back($2); }
    | relational_expression GE_OP shift_expression { $$ = $1->children.push_back($3); $$ = $1->children.push_back(new OperatorNode($2));$1->ops.push_back($2); }
;

equality_expression:
      relational_expression { $$ = new BinaryExpressionNode($1) ;}
    | equality_expression EQ_OP relational_expression { $$ = $1->children.push_back($3); $$ = $1->children.push_back(new OperatorNode($2)); $1->ops.push_back($2); }
    | equality_expression NE_OP relational_expression { $$ = $1->children.push_back($3); $$ = $1->children.push_back(new OperatorNode($2)); $1->ops.push_back($2); }
;

and_expression:
      equality_expression { $$ = new BinaryExpressionNode($1) ;}
    | and_expression AMP equality_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
;

exclusive_or_expression:
      and_expression { $$ = new BinaryExpressionNode($1); }
    | exclusive_or_expression BIN_XOR_OP and_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
;

inclusive_or_expression:
      exclusive_or_expression { $$ = new BinaryExpressionNode($1) ;}
    | inclusive_or_expression BIN_OR_OP exclusive_or_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
;

logical_and_expression:
      inclusive_or_expression { $$ = new BinaryExpressionNode($1); }
    | logical_and_expression AND_OP inclusive_or_expression { $$ = $1->children.push_back($3);$$ = $1->children.push_back(new OperatorNode($2)); $1->ops.push_back($2); }
;

logical_or_expression: 
      logical_and_expression { $$ = new BinaryExpressionNode($1) ;}
    | logical_or_expression OR_OP logical_and_expression { $$ = $1->children.push_back($3); $$ = $1->children.push_back(new OperatorNode($2));$1->ops.push_back($2); }
;

conditional_expression:
      logical_or_expression { $$ = new ConditionalExpressionNode($1); }
    | logical_or_expression TERNARY_OP expression COLON conditional_expression { $$ = new ConditionalExpressionNode($1,$3,$5); }
;

assignment_expression:
      conditional_expression { $$ = new AssignmentExpressionNode($1); }
    | unary_expression assignment_operator assignment_expression { $$ = AssignmentExpressionNode($1,$2,$3); }
;

assignment_operator:
      ASSIGN_OP { $$ = new OperatorNode("=") } 
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
    | expression COMMA assignment_expression {$1->children.push_back($3); $$ = $1 ;}
;


constant_expression:
    conditional_expression {$$ = new ConstantExpressionNode($1);}
;

declaration:
    declaration_specifiers SEMICOLON {$$ = new DeclarationNode($1);}|
	declaration_specifiers init_declarator_list SEMICOLON { $$ = new DeclarationNode($1,$2);}
;

declaration_specifiers: 
    storage_class_specifier {$$ = new DeclarationSpecifierNode($1); }|
	storage_class_specifier declaration_specifiers {$$ = new DeclarationSpecifierNode($1, $2);}|
	type_specifier {$$ = new DeclarationSpecifierNode($1); } |
	type_specifier declaration_specifiers { $$ = new DeclarationSpecifierNode($1,$2); }|
	type_qualifier {$$ = new TypeQualifierNode($1);} |
	type_qualifier declaration_specifiers { $$ = new DeclarationSpecifierNode($1,$2); } |
    function_specifier { $$ = new DeclarationSpecifierNode($1); } |
	function_specifier declaration_specifiers { $$ = new DeclarationSpecifierNode($1,$2); }
;
storage_class_specifier:
	EXTERN  { $$ = new StorageClassSpecifierNode(new KeywordNode($1)); } |
	STATIC { $$ = new StorageClassSpecifierNode(new KeywordNode($1)); }  |
	AUTO { $$ = new StorageClassSpecifierNode(new KeywordNode($1)); } |
	REGISTER { $$ = new StorageClassSpecifierNode(new KeywordNode($1)); } 
;

init_declarator_list:
	init_declarator{$$ = new InitDeclaratorListNode($1);} |   
	init_declarator_list COMMA init_declarator{$1->children.push_back($3); $$ = $1 ;}
;

init_declarator:
	declarator {$$ = new  InitDeclaratorNode($1);}|
	declarator ASSIGN_OP initializer {$$ = new  InitDeclaratorNode($1, $3);}
;

initializer:
	assignment_expression {$$ = new  InitalizerNode($1);} |
	LEFT_CBRACKET initializer_list RIGHT_CBRACKET {$$ = new  InitalizerNode($2);}|
	LEFT_CBRACKET initializer_list COMMA RIGHT_CBRACKET {$$ = new  InitalizerNode($2);}
;

initializer_list:
	initializer  {$$ = new  InitalizerListNode($1);}|
	designation initializer   {$$ = new  InitalizerListNode($1);} |
	initializer_list COMMA initializer {$1->children.push_back($3); $$ = $1 ;} |
	initializer_list COMMA designation initializer{$1->children.push_back($3); $$ = $1 ;}
;

designation:
	designator_list ASSIGN_OP {$$ = new DesignationNode($1);}
;

designator_list:
	designator {$$ = new DesignatorListNode($1);}|
	designator_list designator{$1->children.push_back($2); $$ = $1 ;}
;

designator:
	LEFT_BRACKET constant_expression RIGHT_BRACKET  { $$ = new DesignatorNode($2);}|
	DOT IDENTIFIER{ $$ = new DesignatorNode(new IdentifierNode($2));}
;

declarator: 
    pointer direct_declarator {$$ = new DeclaratorNode($1,$2);}|
	direct_declarator {$$ = new DeclaratorNode($1);}
;

pointer:
	STAR {$$ = new PointerNode();}|
	STAR type_qualifier_list {$$ = new PointerNode($2);}|
	STAR pointer {$$ = new PointerNode($2);}|
	STAR type_qualifier_list pointer {$3->children.push_back($2); $$ = $3 ;}
;

direct_declarator: 
    IDENTIFIER {$$ = new DirectDeclaratorNode(new IdentifierNode($1));}|
	LEFT_PAR declarator RIGHT_PAR{$$ = new DirectDeclaratorNode($2);} |
	direct_declarator LEFT_BRACKET type_qualifier_list assignment_expression RIGHT_BRACKET{$1->children.push_back($3);$1->children.push_back($4); $$ = $1 ;} |
	direct_declarator LEFT_BRACKET type_qualifier_list RIGHT_BRACKET {$1->children.push_back($3); $$ = $1 ;}|
	direct_declarator LEFT_BRACKET assignment_expression RIGHT_BRACKET {$1->children.push_back($3); $$ = $1 ;}|
	direct_declarator LEFT_BRACKET STATIC type_qualifier_list assignment_expression RIGHT_BRACKET{$1->children.push_back("static"); $1->children.push_back($4);$1->children.push_back($5); $$ = $1 ;} |
	direct_declarator LEFT_BRACKET type_qualifier_list STATIC assignment_expression RIGHT_BRACKET{$1->children.push_back($3); $1->children.push_back("static");$1->children.push_back($5); $$ = $1 ;} |
	direct_declarator LEFT_BRACKET type_qualifier_list STAR RIGHT_BRACKET {$1->children.push_back($3); $$ = $1 ;}|
	direct_declarator LEFT_BRACKET STAR RIGHT_BRACKET {$$ = $1;} |
	direct_declarator LEFT_BRACKET RIGHT_BRACKET {$$ = $1;}|
	direct_declarator LEFT_PAR parameter_type_list RIGHT_PAR {$1->children.push_back($3); $$ = $1 ;}|
	direct_declarator LEFT_PAR identifier_list RIGHT_PAR {$1->children.push_back($3); $$ = $1 ;}|
	direct_declarator LEFT_PAR RIGHT_PAR{$$ = $1 ;}
;

type_qualifier_list:
    type_qualifier {$$ = new TypeQualifierListNode($1);} |
	type_qualifier_list type_qualifier{$1->children.push_back($2); $$ = $1 ;}
;

type_qualifier:
	CONST {$$ = new TypeQualifierNode(new KeywordNode($1));}|
	RESTRICT  {$$ = new TypeQualifierNode(new KeywordNode($1));}|
	VOLATILE {$$ = new TypeQualifierNode(new KeywordNode($1));}
;
parameter_type_list: 
    parameter_list {$$ = new ParameterTypeList($1);}|
	parameter_list COMMA ELLIPSIS{$$ = new ParameterTypeList($1, new KeywordNode($3));}
;

parameter_list:
	parameter_declaration SEMICOLON {$$ = new ParameterListNode($1);}|
	parameter_list COMMA parameter_declaration{$1->children.push_back($3); $$ = $1 ;}
;

parameter_declaration:
	declaration_specifiers declarator {$$ = new ParameterDeclarationNode($1);}|
	declaration_specifiers abstract_declarator {$$ = new ParameterDeclarationNode($1,$2);} |
	declaration_specifiers{$$ = new ParameterDeclarationNode($1);}
;
function_specifier: 
    INLINE{$$ = new FunctionSpecifierNode($1);}
;
type_specifier:
	VOID {$$ = new TypeSpecifierNode($1);}|
	CHAR{$$ = new TypeSpecifierNode($1);} |
	SHORT {$$ = new TypeSpecifierNode($1);}|
	INT {$$ = new TypeSpecifierNode($1);}|
	LONG{$$ = new TypeSpecifierNode($1);} |
	FLOAT{$$ = new TypeSpecifierNode($1);} |
	DOUBLE{$$ = new TypeSpecifierNode($1);} |
	SIGNED {$$ = new TypeSpecifierNode($1);}|
	UNSIGNED {$$ = new TypeSpecifierNode($1);}|
	BOOL{$$ = new TypeSpecifierNode($1);} |
	COMPLEX {$$ = new TypeSpecifierNode($1);}|
	IMAGINARY {$$ = new TypeSpecifierNode($1);}|
	struct_or_union_specifier {$$ = new TypeSpecifierNode($1);} |
	enum_specifier{$$ = new TypeSpecifierNode($1);} |
	type_name{$$ = new TypeSpecifierNode($1);}
;

struct_or_union_specifier:
	struct_or_union IDENTIFIER LEFT_CBRACKET struct_declaration_list RIGHT_CBRACKET {$$ = new StructOrUnionSpecifierNode($1, new IdentifierNode($2),$4);}|
	struct_or_union LEFT_CBRACKET struct_declaration_list RIGHT_CBRACKET {$$ = new StructOrUnionSpecifierNode($1, $3);}|
	struct_or_union IDENTIFIER {$$ = new StructOrUnionSpecifierNode($1, new IdentifierNode($2));}
;

struct_or_union:
	STRUCT {$$ = new KeywordNode($1);}|
	UNION{$$ = new KeywordNode($1);}
;

struct_declaration_list:
	struct_declaration{$$ = new StructDeclarationListNode($1);}|
	struct_declaration_list struct_declaration {$1->children.push_back($2); $$ = $1 ;}
;

struct_declaration:
	specifier_qualifier_list struct_declarator_list SEMICOLON{$$ = new StructDeclarationNode($1,$2);}
;

struct_declarator_list:
	struct_declarator {$$ = new StructDeclaratorListNode($1);}|
	struct_declarator_list COMMA struct_declarator {$1->children.push_back($2); $$ = $1 ;}
;

struct_declarator:
	declarator{ $$ = new StructDeclaratorNode($1);} |
	COLON constant_expression { $$ = new StructDeclaratorNode($2);}|
	declarator COLON constant_expression{{ $$ = new StructDeclaratorNode($1,$3);}}
;

specifier_qualifier_list:
	type_specifier specifier_qualifier_list {$2->children.push_back($1); $$ = $2 ;} |
	type_specifier{$$ = new SpecifierQualifierListNode($1);}|
	type_qualifier specifier_qualifier_list {$2->children.push_back($1); $$ = $2 ;}|
	type_qualifier{$$ = new SpecifierQualifierListNode($1);}
;


enum_specifier: 
    ENUM LEFT_CBRACKET enumerator_list RIGHT_CBRACKET {$$ = new EnumSpecifierNode(new KeywordNode($1), $3);}|
	ENUM IDENTIFIER LEFT_CBRACKET enumerator_list RIGHT_CBRACKET  {$$ = new EnumSpecifierNode(new KeywordNode($1),new IdentifierNode($2), $3);}|
	ENUM LEFT_CBRACKET enumerator_list COMMA RIGHT_CBRACKET  {$$ = new EnumSpecifierNode(new KeywordNode($1), $3);}|
	ENUM IDENTIFIER LEFT_CBRACKET enumerator_list COMMA RIGHT_CBRACKET {$$ = new EnumSpecifierNode(new KeywordNode($1),new IdentifierNode($2), $3);} |
	ENUM IDENTIFIER {$$ = new EnumSpecifierNode(new KeywordNode($1),new IdentifierNode($2));}
;

enumerator_list:
	enumerator {$$ = new EnumeratorListNode($1);}|
	enumerator_list COMMA enumerator{{$1->children.push_back($3); $$ = $1 ;}}
;

enumerator: 
    IDENTIFIER {$$ = new EnumeratorNode(new IdentifierNode($1));}|
	IDENTIFIER ASSIGN_OP constant_expression{$$ = new EnumeratorNode(new IdentifierNode($1),$3);}
;

type_name:
	specifier_qualifier_list {$$ = new TypeNameNode($1);}| 
    specifier_qualifier_list abstract_declarator{$$ = new TypeNameNode($1,$2);}
;

abstract_declarator:
	pointer {$$ = new AbstractDeclaratorNode($1);} |
	direct_abstract_declarator {$$ = new AbstractDeclaratorNode($1);}|
	pointer direct_abstract_declarator {$$ = new AbstractDeclaratorNode($1,$2);}
;

direct_abstract_declarator:
	LEFT_PAR abstract_declarator RIGHT_PAR { $$ = new DirectAbstractDeclaratorNode($2); } |
	LEFT_BRACKET RIGHT_BRACKET { $$ = new DirectAbstractDeclaratorNode(); }|
	LEFT_BRACKET assignment_expression RIGHT_BRACKET { $$ = new DirectAbstractDeclaratorNode($2); } |
	direct_abstract_declarator LEFT_BRACKET RIGHT_BRACKET { $1->children.push_back(new DirectAbstractDeclaratorNode()); } |
	direct_abstract_declarator LEFT_BRACKET assignment_expression RIGHT_BRACKET { $1->children.push_back(new DirectAbstractDeclaratorNode($3)); } |
	LEFT_BRACKET STAR RIGHT_BRACKET { $$ = new DirectAbstractDeclaratorNode(); } |
	direct_abstract_declarator LEFT_BRACKET STAR RIGHT_BRACKET { $1->children.push_back(new DirectAbstractDeclaratorNode()); } |
	LEFT_PAR RIGHT_PAR { $$ = new DirectAbstractDeclaratorNode(); } |
	LEFT_PAR parameter_type_list RIGHT_PAR { $$ = new DirectAbstractDeclaratorNode($2); } |
	direct_abstract_declarator LEFT_PAR RIGHT_PAR { $1->children.push_back(new DirectAbstractDeclaratorNode()); } |
	direct_abstract_declarator LEFT_PAR parameter_type_list RIGHT_PAR { $1->children.push_back(new DirectAbstractDeclaratorNode($3)); }
;

statement:
	labeled_statement { $$ = new StatementNode($1); } |
	compound_statement { $$ = new StatementNode($1); } |
	expression_statement { $$ = new StatementNode($1); } |
	selection_statement { $$ = new StatementNode($1); } | 
	iteration_statement { $$ = new StatementNode($1); } |
	jump_statement { $$ = new StatementNode($1); }
;

labeled_statement:
	IDENTIFIER COLON statement { $$ = new LabeledStatementNode($3); } |
	CASE constant_expression COLON statement { $$ = new LabeledStatementNode($2, $4); } |
	DEFAULT COLON statement { $$ = new LabeledStatementNode($3); }
;

compound_statement:
	LEFT_CBRACKET RIGHT_CBRACKET { $$ = new CompoundStatementNode(); } |
	LEFT_CBRACKET block_item_list RIGHT_CBRACKET { $$ = new CompoundStatementNode($2); }
;

block_item_list:
	block_item { $$ = new BlockItemList($1); } |
	block_item_list block_item { $1->children.push_back($2); $$ = $1; }
;

block_item:
	declaration { $$ = new BlockItemNode($1); } |
	statement { $$ = new BlockItemNode($1); }
;

expression_statement:
	SEMICOLON { $$ = new ExpressionStatementNode(); } |
	expression SEMICOLON { $$ = new ExpressionStatementNode($1); }
;

selection_statement:
	IF LEFT_PAR expression RIGHT_PAR statement { $$ = new SelectionStatementNode($3, $5); } |
    IF LEFT_PAR expression RIGHT_PAR statement ELSE statement { $$ = new SelectionStatementNode($3, $5, $7); } |
	SWITCH LEFT_PAR expression RIGHT_PAR statement { $$ = new SelectionStatementNode($3, $5); }
;

iteration_statement:
	WHILE LEFT_PAR expression RIGHT_PAR statement { $$ = new IterationStatementNode($3, $5); } |
	DO statement WHILE LEFT_PAR expression RIGHT_PAR SEMICOLON { $$ = new IterationStatementNode($2, $5); } |
	FOR LEFT_PAR expression_statement expression_statement RIGHT_PAR statement { $$ = new IterationStatementNode($3, $4, $6); } |
	FOR LEFT_PAR expression_statement expression_statement expression RIGHT_PAR statement { $$ = new IterationStatementNode($3, $4, $5, $6); } |
	FOR LEFT_PAR declaration expression_statement RIGHT_PAR statement { $$ = new IterationStatementNode($3, $4, $6); } |
	FOR LEFT_PAR declaration expression_statement expression RIGHT_PAR statement { $$ = new IterationStatementNode($3, $4, $5, $6); }
;

jump_statement: 
	GOTO IDENTIFIER SEMICOLON { $$ = new JumpStatementNode($2); } |
	CONTINUE SEMICOLON { $$ = new JumpStatementNode(); } |
	BREAK SEMICOLON { $$ = new JumpStatementNode(); } | 
	RETURN SEMICOLON { $$ = new JumpStatementNode(); } |
    RETURN expression SEMICOLON { $$ = new JumpStatementNode($2); }
;

translation_unit:
	external_declaration { $$ = new TranslationUnitNode($1); } |
	translation_unit external_declaration { $1->children.push_back($2); $$ = $1; }
;

external_declaration:
	function_definition { $$ = new ExternalDeclarationNode($1); } |
	declaration { $$ = new ExternalDeclarationNode($1); }
;

function_definition:
	declaration_specifiers declarator declaration_list compound_statement { $$ = new FunctionDeclarationNode($1, $2, $3, $4); } |
	declaration_specifiers declarator compound_statement { $$ = new FunctionDeclarationNode($1, $2, $3); }
;

declaration_list: 
    declaration { $$ = new DeclarationList($1); }
  | declaration_list declaration { $1->children.push_back($2); $$ = $1; }
;

identifier_list:
    IDENTIFIER { $$ = new IdentifierList($1); }
  | identifier_list COMMA IDENTIFIER { $1->children.push_back($3); $$ = $1; }
;

%%

// Epilogue

namespace yy

int main ()
{
  yy::parser parse;
  return parse ();
}