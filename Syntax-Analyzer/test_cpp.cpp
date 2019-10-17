
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