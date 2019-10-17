#include <vector>
#include <string>
#include <iostream> 
#include <sstream>

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

int main(){
    AstNode* d = new AstNode("D", {});
    AstNode* a = new AstNode("A", {d});
    AstNode* b = new AstNode("B");
    AstNode* c = new AstNode("C", {});
    (c->children).push_back(a);
    (c->children).push_back(b);
    c->print_tree();
}