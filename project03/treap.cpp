// treap.cpp: Treap Map

#include "map.h"

#include <climits>
#include <random>

// Prototypes ------------------------------------------------------------------

static Node *insert_r(Node *node, const std::string &key, const std::string &value);
extern Node *search_r(Node *node, const std::string &key);
extern void dump_r_treap(Node *node, std::ostream &os, DumpFlag flag);
static Node *rotate_right(Node *p);
static Node *rotate_left(Node *p);
Node * newTreapNode(const std::string &key, const std::string &value);
static int get_random();


// Methods ---------------------------------------------------------------------

void TreapMap::insert(const std::string &key, const std::string &value) {
    if( root == nullptr ){
        root = newTreapNode(key,value);
    }
    root = insert_r(root, key, value);
}

const Entry TreapMap::search(const std::string &key) {
    Node *result = search_r(root, key);
    if(result == nullptr){
        return NONE;
    }
    else{
        Entry element = std::make_pair(result->entry.first, result->entry.second);
        return element;
    }
}

void TreapMap::dump(std::ostream &os, DumpFlag flag) {
    dump_r_treap(root, os, flag);
}

// Internal Functions ----------------------------------------------------------

Node * newTreapNode(const std::string &key, const std::string &value){
    Node *nodeptr = new Node();
    Entry element = std:: make_pair(key, value);
    nodeptr->entry = element;
    nodeptr->priority = get_random();
    nodeptr->left = nullptr;
    nodeptr->right = nullptr;
    return nodeptr;
}

Node *insert_r(Node *node, const std::string &key, const std::string &value) {
    if( node == nullptr){
        Node *result = newTreapNode(key,value);
        return result;
    }

    if( key < node->entry.first){
        node->left = insert_r( node->left, key, value);

        if(node->left->priority > node->priority){
            node = rotate_right(node);
        }
    } else if ( key > node->entry.first ) {
        node->right = insert_r(node->right, key, value);

        if(node->right->priority > node->priority){
            node = rotate_left(node);
        }
    } else {
        node->entry.second = value;
        return node;
    }

    return node;
}

Node *rotate_right(Node *p) {
    Node *q = p->left,  *T2 = q->right;

    q->right = p;
    p->left = T2;

    return q;

}

Node *rotate_left(Node *p) {
    Node *q = p->right,  *T2 = q->left;

    q->left = p;
    p->right = T2;

    return q;
}

int get_random() {
    std::random_device               rd;
    std::default_random_engine       g(rd());
    std::uniform_int_distribution<>  d(1, INT_MAX);
    return d(g);
}

extern void dump_r_treap(Node *node, std::ostream &os, DumpFlag flag){
    switch (flag){
        case DUMP_KEY:
            if (node != nullptr){
                dump_r_treap(node->left, os, flag);
                cout << node->entry.first << endl;
                dump_r_treap(node->right, os, flag);
            }
            break;
        case DUMP_VALUE:
            if (node != nullptr){
                dump_r_treap(node->left, os, flag);
                cout << node->entry.second << endl;
                dump_r_treap(node->right, os, flag);
            }
            break;
        case DUMP_KEY_VALUE:
            if (node != nullptr){
                dump_r_treap(node->left, os, flag);
                cout << node->entry.first << "\t" << node->entry.second << endl;
                dump_r_treap(node->right, os, flag);
            }
            break;
        case DUMP_VALUE_KEY:
            if (node != nullptr){
                dump_r_treap(node->left, os, flag);
                cout << node->entry.second << "\t" << node->entry.first << endl;
                dump_r_treap(node->right, os, flag);
            }
            break;
    }
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
