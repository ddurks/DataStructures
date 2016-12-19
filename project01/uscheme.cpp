// uscheme.cpp

#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <unistd.h>

using namespace std;

// Globals ---------------------------------------------------------------------

bool BATCH = false;
bool DEBUG = false;

// Structures ------------------------------------------------------------------

struct Node {
    //Constructor with fallback values
    Node(string valueIn, Node *leftIn=nullptr, Node *rightIn=nullptr){
        value = valueIn;
        left = leftIn;
        right = rightIn;
    }
    //Destructor
    ~Node(){
        delete left;
        delete right;
    };

    string value;
    Node * left;
    Node * right;

    friend ostream &operator<<(ostream &os, const Node &n);
};

//overloaded node output operator
ostream &operator<<(ostream &os, const Node &n) {
    os << "(Node: value=" << n.value << ", ";
    if( n.left != nullptr ){
        cout << "left=" << *n.left;
    }
    if( n.right != nullptr){
        cout << "right=" << *n.right;
    }
    cout << ")";
    return os;
}

// Parser ----------------------------------------------------------------------

string parse_token(istream &s) {
    string token;
    string nexttoken;
    //checks tokens using peek first, accesses using get
    if( s.peek() == ' ' ){
        s.get();
    }
    if( s.peek() == '(' || s.peek() == ')' || s.peek() == '+' || s.peek() == '-' || s.peek() == '*' || s.peek() == '/'){
        token = s.get();
    }
    else if( s.peek() >= '0' && s.peek() <= '9' ){
        token = s.get();
        while( s.peek() >= '0' && s.peek() <= '9'){
            nexttoken = s.get();
            token.append(nexttoken);
        }
    }
    return token;
}

//full expression parser
Node *parse_expression(istream &s) {
    Node *left= nullptr;
    Node *right= nullptr;

    string token = parse_token(s);

    if( token == "" || token == ")" ){
        return nullptr;
    }
    if( token == "(" ){
        token = parse_token(s);
        left = parse_expression(s);
        if( left ){
            right = parse_expression(s);
        }
        if( right ){
            parse_token(s);
        }
    }
    return new Node(token, left, right);
}

// Interpreter -----------------------------------------------------------------
// recursive evaluation function
void evaluate_r(const Node *n, stack<int> &s) {
    int a, b, result;
    if(n->left != nullptr){
        if( n->left->value[0] <= '0' || n->left->value[0] >= '9' ){
            evaluate_r(n->left, s);
        }
        else{
            s.push(stoi(n->left->value));
        }
    }

    if(n->right != nullptr){
        if( n->right->value[0] <= '0' || n->right->value[0] >= '9' ){
            evaluate_r(n->right, s);
        }
        else{
            s.push(stoi(n->right->value));
        }
    }
    if( n->value[0] >= '0' && n->value[0] <= '9'){
        s.push(stoi(n->value));
    }
    if( n->value == "+" ){
        a = s.top();
        s.pop();
        b = s.top();
        s.pop();
        result = a + b;
        s.push(result);
    }
    else if( n->value == "-" ){
        a = s.top();
        s.pop();
        b = s.top();
        s.pop();
        result = b - a;
        s.push(result);
    }
    else if( n->value == "*" ){
        a = s.top();
        s.pop();
        b = s.top();
        s.pop();
        result = a * b;
        s.push(result);
    }
    else if( n->value == "/" ){
        a = s.top();
        s.pop();
        b = s.top();
        s.pop();
        result = b / a;
        s.push(result);
    }

}

int evaluate(const Node *n) {
    stack<int> answer;
    evaluate_r(n, answer);
    return answer.top();
}

// Main execution --------------------------------------------------------------

int main(int argc, char *argv[]) {
    string line;
    int c;

    while ((c = getopt(argc, argv, "bdh")) != -1) {
        switch (c) {
            case 'b': BATCH = true; break;
            case 'd': DEBUG = true; break;
            default:
                cerr << "usage: " << argv[0] << endl;
                cerr << "    -b Batch mode (disable prompt)"   << endl;
                cerr << "    -d Debug mode (display messages)" << endl;
                return 1;
        }
    }

    while (!cin.eof()) {
        if (!BATCH) {
            cout << ">>> ";
            cout.flush();
        }

        if (!getline(cin, line)) {
            break;
        }

        if (DEBUG) { cout << "LINE: " << line << endl; }

        stringstream s(line);
        Node *n = parse_expression(s);
        if (DEBUG) { cout << "TREE: " << *n << endl; }

        cout << evaluate(n) << endl;

        delete n;
    }

    return 0;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
