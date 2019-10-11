
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
                return("PrimaryExpressionNode")
            }

            PrimaryExpressionNode(){

            }
    }

    
    class IdentifierNode : public Node{
        public:
            string ident;

            string print(){
                return("IDENT(" + ident + ")");
            }

            IdentifierNode(string _ident){
                ident = _ident
            }
    }

    class PostfixExpressionNode : public Node{
        public:
            string print(){
                return("PostfixExpressionNode")
            }

        PostfixExpressionNode(){

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
                StorageClassSpecifierNode(string n1){
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
class DirectDeclaratorList: public Node
    {
        public:
            string print(){
                return("DirectDeclaratorList")
            }

       DirectDeclaratorList(Node* n1){
            children = vector<Node*>{n1};

        }
       DirectDeclaratorList(Node* n1,Node* n2){
            children = vector<Node*>{n1, n2};

        }
       DirectDeclaratorList(){
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

        TypeQualifierNode(string n1){
            children = vector<Node*>{n1};

        }
    }

    class ParameterClassList:public Node{
        public:
            string print(){
                return(" ParameterClassList")
            }

         ParameterClassList(Node* n2, string n1){
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
    %token LITERAL // Numeric literal

    %token STRING_LITERAL  // String literal