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
            MultiplicativeExpressionNode(Node* node, Node* n2) {
                children = vector<Node*>{node,n2};
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
    class KeywordNode : public Node {
        public:
            string _sign;

            public string print() {
                return("Keyword(" + _sign + ")");
            } 

            KeywordNode(string sign) {
                _sign = sign;
            }
    }


    class PostfixExpressionNode : public Node{
        public:
            string print(){
                return("PostfixExpressionNode")
            }

        PostfixExpressionNode(Node* n1){
                                         children = vector<Node*>{n1};

                                     }
        PostfixExpressionNode(Node* n1, Node* n2){
                                         children = vector<Node*>{n1,n2};

                                     }
    }

    class ArgumentExpressionListNode: public Node{
        public:
            string print(){
                return("ArgumentExpressionList")
            }

         ArgumentExpressionList(Node* n1){
            children = vector<Node*>{n1};

        }
    }
    class ExpressionNode: public Node{
        public:
            string print(){
                return("ExpressionNode")
            }

         ExpressionNode(Node* n1){
            children = vector<Node*>{n1};

        }
    }
    class UnaryExpressionNode : public Node{
        public:
            string print(){
                return("UnaryExpressionNode")
            }

          UnaryExpressionNode(Node* n1){
            children = vector<Node*>{n1};

        }
    }

    class  UnaryOperatorNode: public Node{
        public:
            string print(){
                return("UnaryOperatorNode")
            }

          UnaryOperatorNode(Node* n1){
            children = vector<Node*>{n1};

        }
    }

    


    class ConditionalExpressionNode: public Node{
        public:

            string print(){
                return("ConditionalExpressionNode")
            }
        ConditionalExpressionNode(Node* n1){
            children = vector<Node*>{n1};

        }
         ConditionalExpressionNode(Node* n1,Node* n2,Node* n3){
            children = vector<Node*>{n1,n2,n3};

        }
    }
    class AssignmentExpressionNode: public Node{
        public:

            string print(){
                return("AssignmentExpressionNode")
            }
        AssignmentExpressionNode(Node* n1){
            children = vector<Node*>{n1};

        }
        AssignmentExpressionNode(Node* n1,Node* n2,Node* n3){
            children = vector<Node*>{n1,n2,n3};

        }
    }
    class ConstantExpressionNode: public Node{
        public:
            string print(){
                return("ConstantExpressionNode")
            }

         ConstantExpressionNode(Node* n1){
            children = vector<Node*>{n1};

        }
    }

    class DeclarationNode: public Node{
            public:
            string print(){
                return("DeclarationNode")
            }

         DeclarationNode(Node* n1){
            children = vector<Node*>{n1};

        }
        DeclarationNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    }

    class DeclarationSpecifiersNode: public Node{
            public:
            string print(){
                return("DeclarationSpecifiersNode")
            }

         DeclarationSpecifiersNode(Node* n1){
            children = vector<Node*>{n1};

        }
        DeclarationSpecifiersNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    }

    class FunctionSpecifierNode:public Node{
            public:
            string print(){
                return("FunctionSpecifierNode")
            }

        FunctionSpecifierNode(Node* n1){
            children = vector<Node*>{n1};

        }
    }
        class TypeSpecifierNode:public Node{
            public:
            string print(){
                return("TypeSpecifierNode")
            }

        TypeSpecifierNode(Node* n1){
            children = vector<Node*>{n1};

        }
    }
    class StructOrUnionSpecifierNode: public Node{
            public:
            string print(){
                return("StructOrUnionSpecifierNode")
            }

        StructOrUnionSpecifierNode(Node* n1,Node* n2, Node* n3){
            children = vector<Node*>{n1,n2,n3};

        }
        InitDeclaratorListNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    }

    class  StructDeclarationListNode: public Node{
            public:
            string print(){
                return("StructDeclarationListNode")
            }

        StructDeclarationListNode(Node* n1){
            children = vector<Node*>{n1};

        }
         StructDeclarationListNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    }
    class  StructDeclarationNode: public Node{
            public:
            string print(){
                return("StructDeclarationNode")
            }

        StructDeclarationNode(Node* n1){
            children = vector<Node*>{n1};

        }
         StructDeclarationNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    }

    class StructDeclaratorListNode: public Node{
            public:
            string print(){
                return("StructDeclaratorListNode")
            }

        StructDeclaratorListNode(Node* n1){
            children = vector<Node*>{n1};

        }
         StructDeclaratorListNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    }
        class StructDeclaratorNode: public Node{
            public:
            string print(){
                return("StructDeclaratorNode")
            }

        StructDeclaratorNode(Node* n1){
            children = vector<Node*>{n1};

        }
         StructDeclaratorNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    }
    class SpecifierQualifierListNode:ublic Node{
            public:
            string print(){
                return("SpecifierQualifierListNode")
            }

         SpecifierQualifierListNode(Node* n1){
            children = vector<Node*>{n1};

        }
         SpecifierQualifierListNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    }

    class EnumSpecifierNode :  public:
            string print(){
                return("EnumSpecifierNode")
            }

        EnumSpecifierNode(Node* n1, Node* n2, Node* n3){
            children = vector<Node*>{n1,n2,n3};

        }
         EnumSpecifierNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    }

    class EnumeratorNode: public:
            string print(){
                return("EnumeratorNode")
            }

         EnumeratorNode(Node* n1){
            children = vector<Node*>{n1};

        }
        EnumeratorNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    }
    class TypeNameNode: public:
            string print(){
                return("TypeNameNode")
            }

         TypeNameNode(Node* n1){
            children = vector<Node*>{n1};

        }
        TypeNameNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    }
    class AbstractDeclaratorNode :  public:
            string print(){
                return("AbstractDeclaratorNode")
            }

        AbstractDeclaratorNode(Node* n1){
            children = vector<Node*>{n1};

        }
        AbstractDeclaratorNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    }

    class  EnumeratorListNode :public:
            string print(){
                return("EnumeratorListNode")
            }

        EnumeratorListNode(Node* n1){
            children = vector<Node*>{n1};

        }}
    class InitDeclaratorListNodeNode: public Node{
            public:
            string print(){
                return("InitDeclaratorListNode")
            }

        InitDeclaratorListNode(Node* n1){
            children = vector<Node*>{n1};

        }
        InitDeclaratorListNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    }

    class StorageClassSpecifierNode: public Node{
        public:
            string print(){
                return("StorageClassSpecifierNode")
            }

         StorageClassSpecifierNode(Node* n1){
            children = vector<Node*>{n1};

        }
    }

    class InitDeclaratorNode :public Node{
        public:
            string print(){
                return("InitDeclaratorNode")
            }

        InitDeclaratorNode(Node* n1){
            children = vector<Node*>{n1};

        }
        InitDeclaratorNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    }

    class InitializerNode : public Node{
        public:
            string print(){
                return("InitializerNode")
            }

         InitializerNode(Node* n1){
            children = vector<Node*>{n1};

        }
    }
    class InitializerListNode : public Node{
        public:
            string print(){
                return("InitializerListNode")
            }

         InitializerListNode(Node* n1){
            children = vector<Node*>{n1};

        }
    }

    class DesignatorNode: public Node{
        public:
            string print(){
                return("DesignatorNode")
            }

         DesignatorNode(Node* n1){
            children = vector<Node*>{n1};

        }
    }
    class DesignatorListNode: public Node{
        public:
            string print(){
                return("DesignatorNode")
            }

         DesignatorListNode(Node* n1){
            children = vector<Node*>{n1};

        }
     DesignatorListNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    }
    class DesignationNode: public Node{
        public:
            string print(){
                return("DesignationNode")
            }

         DesignationNode(Node* n1){
            children = vector<Node*>{n1};

        }
    }
    class DeclaratorNode: public Node{
        public:
            string print(){
                return("DeclaratorNode")
            }

         DeclaratorNode(Node* n1){
            children = vector<Node*>{n1};

        }
        DeclaratorNode(Node* n1,Node* n2){
            children = vector<Node*>{n1, n2};

        }
    }

    class PointerNode : public Node
    {
        public:
            string print(){
                return("PointerNode")
            }

        PointerNode(Node* n1){
            children = vector<Node*>{n1};

        }
        PointerNode(Node* n1,Node* n2){
            children = vector<Node*>{n1, n2};

        }
        PointerNode(){
        }
    }
class DirectDeclaratorListNode: public Node
    {
        public:
            string print(){
                return("DirectDeclaratorList")
            }

       DirectDeclaratorListNode(Node* n1){
            children = vector<Node*>{n1};

        }
       DirectDeclaratorListNode(Node* n1,Node* n2){
            children = vector<Node*>{n1, n2};

        }
       DirectDeclaratorListNode(){
        }
    }


    class TypeQualifierListNode :  public Node{
        public:
            string print(){
                return("TypeQualifieListNode")
            }

         TypeQualifierListNode(){

        }
    }

    class TypeQualifierNode : public Node{
        public:
            string print(){
                return("TypeQualifierNode")
            }

        TypeQualifierNode(Node* n1){
            children = vector<Node*>{n1};

        }
    }

    class ParameterClassList:public Node{
        public:
            string print(){
                return(" ParameterClassList")
            }

         ParameterClassList(Node* n2, Node* n1){
            children = vector<Node*>{n2,n1};

        }
        ParameterClassList(Node* n2){
            children = vector<Node*>{n2};

        }
    }

    class  ParameterListNode : public Node{
        public:
            string print(){
                return("ParameterListNode")
            }

       ParameterListNode(Node* n1){
            children = vector<Node*>{n1};

        }
    }
    class ParameterDeclarationNode : public Node{
        public:
            string print(){
                return("ParameterDeclarationList")
            }

       ParameterDeclarationNode(Node* n1){
            children = vector<Node*>{n1};

        }
       ParameterDeclarationNode(Node* n1,Node* n2){
            children = vector<Node*>{n1, n2};

        }

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
      primary_expression { $$ = new PostfixExpressionNode($1);}
    | postfix_expression '[' expression ']' {$1->children.push_back($3); $$ = $1 ;}
    | postfix_expression '(' argument_expression_list ')'
    | postfix_expression '(' ')'{$$ = $1;}
    | postfix_expression '.' IDENTIFIER {$1->children.push_back(new IdentifierNode($3)); $$ = $1 ;}
    | postfix_expression PTR_OP IDENTIFIERP{$1 -> children.push_pack(new OperatorNode($2));$1->children.push_back(new IdentifierNode($3)); $$=$1;}
    | postfix_expression INC_OP{$1 -> children.push_pack(new OperatorNode($2));$1->children.push_back(new IdentifierNode($3)); $$=$1;}
    | postfix_expression DEC_OP{$1 -> children.push_pack(new OperatorNode($2));$1->children.push_back(new IdentifierNode($3)); $$=$1;}
    | '(' type_name ')' '{' initializer_list '}'{ $$ = new PostfixExpressionNode($2,$5);}
    | '(' type_name ')' '{' initializer_list ',' '}'{$$= new PostfixExpressionNode($2,$5);}
;

argument_expression_list:
      IDENTIFIER($$ = new ArgumentExpressionList(new IdentifierNode($1);))
    | IDENTIFIER ',' argument_expression_list {$3->children.push_back(new IdentifierNode($1)); $$=$3;}
;

unary_expression:
      postfix_expression {$$ = new UnaryExpressionNode(new PostfixExpressionNode($1));}
    | INC_OP unary_expression {$2 -> children.push_pack(new OperatorNode($1)); $$=$2;}
    | DEC_OP unary_expression {$2 -> children.push_pack((new OperatorNode($1)); $$=$2;}
    | unary_operator cast_expression {$1 ->children.push_back(new CastExpressionNode($2)); $$ = $1;}
    | SIZEOF unary_expression {$2 -> children.push_pack(new OperatorNode($1)); $$=$2;}
    | SIZEOF '(' type_name ')' {$$ = new UnaryExpressionNode("(new OperatorNode($1)", $3);}
;

unary_operator:
      '&'{$$ = new UnaryOperatorNode(new OperatorNode($1);}
    | '*'{$$ = new UnaryOperatorNode(new OperatorNode($1);}
    | '+'{$$ = new UnaryOperatorNode(new OperatorNode($1);}
    | '-'{$$ = new UnaryOperatorNode(new OperatorNode($1);}
    | '˜'{$$ = new UnaryOperatorNode(new OperatorNode($1);}
    | '!'{$$ = new UnaryOperatorNode(new OperatorNode($1);}
;

cast_expression:
      unary_expression { $$ = new CastExpressionNode($1) }
    | '(' type_name ')' cast_expression { $$ = new CastExpressionNode($2, $4); }
;

multiplicative_expression:
      cast_expression { $$ = new BinaryExpressionNode($1); }
    | multiplicative_expression '*' cast_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
    | multiplicative_expression '/' cast_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
    | multiplicative_expression '%' cast_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
;

additive_expression:
      multiplicative_expression { $$ = new BinaryExpressionNode($1); }
    | additive_expression '+' multiplicative_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
    | additive_expression '-' multiplicative_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
;

shift_expression:
      additive_expression { $$ = new BinaryExpressionNode($1); }
    | shift_expression LEFT_OP additive_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
    | shift_expression RIGHT_OP additive_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
;

relational_expression:
      shift_expression { $$ = new BinaryExpressionNode($1) ;}
    | relational_expression '<' shift_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
    | relational_expression '>' shift_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
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
    | and_expression '&' equality_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
;

exclusive_or_expression:
      and_expression { $$ = new BinaryExpressionNode($1); }
    | exclusive_or_expression 'ˆ' and_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
;

inclusive_or_expression:
      exclusive_or_expression { $$ = new BinaryExpressionNode($1) ;}
    | inclusive_or_expression '|' exclusive_or_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
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
    | logical_or_expression '?' expression ':' conditional_expression { $$ = new ConditionalExpressionNode($1,$3,$5); }
;

assignment_expression:
      conditional_expression { $$ = new AssignmentExpressionNode($1); }
    | unary_expression assignment_operator assignment_expression { $$ = AssignmentExpressionNode($1,$2,$3); }
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
	EXTERN  { $$ = new StorageClassSpecifierNode(new KeywordNode($1)); } |
	STATIC { $$ = new StorageClassSpecifierNode(new KeywordNode($1)); }  |
	AUTO { $$ = new StorageClassSpecifierNode(new KeywordNode($1)); } |
	REGISTER { $$ = new StorageClassSpecifierNode(new KeywordNode($1)); } 
;

init_declarator_list:
	init_declarator{$$ = new InitDeclaratorListNode($1);} |   
	init_declarator_list ',' init_declarator{$1->children.push_back($3); $$ = $1 ;}
;

init_declarator:
	declarator {$$ = new  InitDeclaratorNode($1);}|
	declarator '=' initializer {$$ = new  InitDeclaratorNode($1, $3);}
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
	CONST {$$ = new TypeQualifierNode(new KeywordNode($1));}|
	RESTRICT  {$$ = new TypeQualifierNode(new KeywordNode($1));}|
	VOLATILE {$$ = new TypeQualifierNode(new KeywordNode($1));}
;
parameter_type_list: 
    parameter_list {$$ = new ParameterTypeList($1);}|
	parameter_list ',' ELLIPSIS{$$ = new ParameterTypeList($1, new KeywordNode($3));}
;

parameter_list:
	parameter_declaration ';' {$$ = new ParameterListNode($1);}|
	parameter_list ',' parameter_declaration{$1->children.push_back($3); $$ = $1 ;}
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
	struct_or_union IDENTIFIER '{' struct_declaration_list '}' {$$ = new StructOrUnionSpecifierNode($1, new IdentifierNode($2),$4);}|
	struct_or_union '{' struct_declaration_list '}' {$$ = new StructOrUnionSpecifierNode($1, $3);}|
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
	specifier_qualifier_list struct_declarator_list ';'{$$ = new StructDeclarationNode($1,$2);}
;

struct_declarator_list:
	struct_declarator {$$ = new StructDeclaratorListNode($1);}|
	struct_declarator_list ',' struct_declarator {$1->children.push_back($2); $$ = $1 ;}
;

struct_declarator:
	declarator{ $$ = new StructDeclaratorNode($1);} |
	':' constant_expression { $$ = new StructDeclaratorNode($2);}|
	declarator ':' constant_expression{{ $$ = new StructDeclaratorNode($1,$3);}}
;

specifier_qualifier_list:
	type_specifier specifier_qualifier_list {$2->children.push_back($1); $$ = $2 ;} |
	type_specifier{$$ = new SpecifierQualifierListNode($1);}|
	type_qualifier specifier_qualifier_list {$2->children.push_back($1); $$ = $2 ;}|
	type_qualifier{$$ = new SpecifierQualifierListNode($1);}
;


enum_specifier: 
    ENUM '{' enumerator_list '}' {$$ = new EnumSpecifierNode(new KeywordNode($1), $3);}|
	ENUM IDENTIFIER '{' enumerator_list '}'  {$$ = new EnumSpecifierNode(new KeywordNode($1),new IdentifierNode($2), $3);}|
	ENUM '{' enumerator_list ',' '}'  {$$ = new EnumSpecifierNode(new KeywordNode($1), $3);}|
	ENUM IDENTIFIER '{' enumerator_list ',' '}' {$$ = new EnumSpecifierNode(new KeywordNode($1),new IdentifierNode($2), $3);} |
	ENUM IDENTIFIER {$$ = new EnumSpecifierNode(new KeywordNode($1),new IdentifierNode($2));}
;

enumerator_list:
	enumerator {$$ = new EnumeratorListNode($1);}|
	enumerator_list ',' enumerator{{$1->children.push_back($3); $$ = $1 ;}}
;

enumerator: 
    IDENTIFIER {$$ = new EnumeratorNode(new IdentifierNode($1));}|
	IDENTIFIER '=' constant_expression{$$ = new EnumeratorNode(new IdentifierNode($1),$3);}
;

type_name:
	specifier_qualifier_list {$$ = new TypeNameNode($1);}| 
    specifier_qualifier_list abstract_declarator{$$ = new TypeNameNode($1,$2);}
;

abstract_declarator:
	pointer{$$ = new AbstractDeclaratorNode($1);} |
	direct_abstract_declarator {$$ = new AbstractDeclaratorNode($1);}|
	pointer direct_abstract_declarator  {$$ = new AbstractDeclaratorNode($1,$2);}
;

direct_abstract_declarator:
	'(' abstract_declarator ')'{$$ = new DirectAbstractDeclaratorNode($2);} |
	'[' ']' {$$ = new DirectAbstractDeclaratorNode();}|
	'[' assignment_expression ']' {$$ = new DirectAbstractDeclaratorNode($2);} |
	direct_abstract_declarator '[' ']'  |
	direct_abstract_declarator '[' assignment_expression ']'|
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