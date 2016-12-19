// quick.cpp

#include "lsort.h"

#include <iostream>
using namespace std;

// Prototypes

Node *qsort(Node *head, CompareFunction compare);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, CompareFunction compare);
Node *concatenate(Node *left, Node *right);

// Implementations

void quick_sort(List &l, bool numeric) {
    Node *pivot = l.head;
    if(numeric){
        l.head = qsort(pivot, node_number_compare);
    }
    else{
        l.head = qsort(pivot, node_string_compare);
    }
}

Node *qsort(Node *head, CompareFunction compare) {
    Node leftnode = {"", 0, nullptr};
    Node rightnode = {"", 0, nullptr};
    Node *left = &leftnode;
    Node *right = &rightnode;

    if(head == nullptr || head->next == nullptr) return head;
    partition(head, head, left, right, compare);
    left = qsort(left, compare);
    right = qsort(right, compare);
    return concatenate(left, right);
}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, CompareFunction compare) {
    Node *curr = head, *lefthead = left, *righthead = right;

    curr = curr->next;
    while(curr != nullptr){
        if(compare(curr,pivot)){
            left->next = curr;
            left = left->next;
        }
        else{
            right->next = curr;
            right = right->next;
        }
        curr = curr->next;
    }
    left->next = pivot;
    left = left->next;
    left->next = nullptr;
    right->next = nullptr;
    left = lefthead->next;
    right = righthead->next;
}

Node *concatenate(Node *left, Node *right) {
    Node *curr = left, *head = left;
    while(curr->next != nullptr){
        curr = curr->next;
    }
    curr->next = right;
    return head;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
