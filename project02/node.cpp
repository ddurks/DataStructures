// node.cpp

#include "lsort.h"

#include <iostream>
#include <string>

using namespace std;

bool node_number_compare(const Node *a, const Node *b) {
    if( a->number < b->number ) return true;
    else return false;
}

bool node_string_compare(const Node *a, const Node *b) {
    if( a->string.compare(b->string) <0 ) return true;
    else return false;
}

int void_number_compare(const void *a, const void *b) {
    int one = (*(Node**)a)->number;
    int two = (*(Node**)b)->number;
    return (one-two);
}

int void_string_compare(const void *a, const void *b) {
    string one = (*(Node**)a)->string;
    string two = (*(Node**)b)->string;
    return one.compare(two);
}

void dump_node(Node *n) {
    cout << "Node value: " << n->number << " Node string: " << n->string << endl;
    if(n->next == nullptr) return;
    else dump_node(n->next);
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
