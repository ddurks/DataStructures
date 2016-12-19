// list.cpp

#include "lsort.h"

#include <memory>

List::List() : head(nullptr), size(0) {}

List::~List() {
    Node *next = nullptr;
    for (Node *curr = head; curr != nullptr; curr = next) {
        next = curr->next;
        delete curr;
    }
    size = 0;
}

void List::push_front(const std::string &s) {
	Node *enterNode = new Node();
	enterNode->string = s;
	enterNode->number = stoi(s);
	enterNode->next = head;
	head = enterNode;
    size++;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
