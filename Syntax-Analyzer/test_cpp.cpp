
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

int main(){
     Node* res = &PrimaryExpressionNode(&IdentNode);
}