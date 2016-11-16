// Challenge 06: Lowest Common Ancestor

#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
using namespace std;

struct Node{
    int value;
    Node *left;
    Node *right;
    ~Node(){
        delete left;
        delete right;
    }
};

Node * newNode(int in){
    Node *nodeptr = new Node();
    nodeptr->value = in;
    nodeptr->left = nullptr;
    nodeptr->right = nullptr;
    return nodeptr;
}

void insert(Node *root, Node *new_node){
    if (new_node->value < root->value){
        if (root->left == nullptr){
            root->left = new_node;
        }
        else{
            insert(root->left, new_node);
        }
    }

    if (new_node->value > root->value){
        if (root->right == nullptr){
            root->right = new_node;
        }
        else{
            insert(root->right, new_node);
        }
    }
}

int findLCA(Node * root, int uno, int dos){
    if(root == nullptr) return 0;

    if(root->value > uno && root->value > dos){
        return findLCA(root->left, uno, dos);
    }

    if(root->value < uno && root->value < dos){
        return findLCA(root->right, uno, dos);
    }

    return root->value;
}

// Main Execution
int main(int argc, char *argv[]) {
    bool first_pass = false;
    string line, numNodesString;
    vector<int> tree;
    Node * root = nullptr;
    Node * tempNode = nullptr;
    int numNodes, numLCAs, temp, one, two;
    while(!cin.eof()){
        cin >> numNodes;
        if(numNodes == -1) break;
        if(first_pass){
            cout << endl;
        }
        cin >> temp;
        root = newNode(temp);
        for(int i = 1; i < numNodes; i++){
            cin >> temp;
            tempNode = newNode(temp);
            insert(root, tempNode);
        }
        cin >> numLCAs;
        for(int i = 0; i < numLCAs; i++){
            cin >> one;
            cin >> two;
            cout << findLCA(root, one, two) << endl;
        }
        tree.clear();
        first_pass = true;
        delete root;
    }

    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
