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