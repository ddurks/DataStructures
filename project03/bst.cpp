// bst.cpp: BST Map

#include "map.h"

#include <stdexcept>

// Prototypes ------------------------------------------------------------------

Node *newNode(const std::string &key, const std::string &value);
Node *insert_r(Node *node, const std::string &key, const std::string &value);
Node *search_r(Node *node, const std::string &key);
void    dump_r(Node *node, std::ostream &os, DumpFlag flag);

// Methods ---------------------------------------------------------------------

void BSTMap::insert(const std::string &key, const std::string &value) {
    if( root == nullptr ){
        root = newNode(key,value);
    }
    insert_r(root, key, value);
}

const Entry BSTMap::search(const std::string &key) {

    Node *result = search_r(root, key);
    if(result == nullptr){
        return NONE;
    }
    else{
        Entry element = std::make_pair(result->entry.first, result->entry.second);
        return element;
    }
}

void BSTMap::dump(std::ostream &os, DumpFlag flag) {
    dump_r(root, os, flag);
}

// Internal Functions ----------------------------------------------------------

Node * newNode(const std::string &key, const std::string &value){
    Node *nodeptr = new Node();
    Entry element = std:: make_pair(key, value);
    nodeptr->entry = element;
    nodeptr->left = nullptr;
    nodeptr->right = nullptr;
    return nodeptr;
}

Node *insert_r(Node *node, const std::string &key, const std::string &value) {
    if(node == nullptr){
        return newNode(key, value);
    }

    if(key < node->entry.first){
        node->left = insert_r(node->left, key, value);
    }
    else if(key > node->entry.first){
        node->right = insert_r(node->right, key, value);
    }
    else{
        node->entry.second = value;
        return node;
    }

    return node;
}

Node *search_r(Node *node, const std::string &key) {
    if(node == nullptr || node->entry.first == key)
        return node;

    if(node->entry.first < key){
        return search_r(node->right, key);
    }

    else return search_r(node->left, key);
}

void dump_r(Node *node, std::ostream &os, DumpFlag flag) {
    switch (flag){
        case DUMP_KEY:
            if(node != nullptr){
                dump_r(node->left, os, flag);
                cout << node->entry.first << endl;
                dump_r(node->right, os, flag);
            }
            break;
        case DUMP_VALUE:
            if(node != nullptr){
                dump_r(node->left, os, flag);
                cout << node->entry.second << endl;
                dump_r(node->right, os, flag);
            }
            break;
        case DUMP_KEY_VALUE:
            if(node != nullptr){
                dump_r(node->left, os, flag);
                cout << node->entry.first << "\t" << node->entry.second << endl;
                dump_r(node->right, os, flag);
            }
            break;
        case DUMP_VALUE_KEY:
            if(node != nullptr){
                dump_r(node->left, os, flag);
                cout << node->entry.second << "\t" << node->entry.first << endl;
                dump_r(node->right, os, flag);
            }
            break;
    }
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
