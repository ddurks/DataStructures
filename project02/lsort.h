// lsort.h

#pragma once

#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

// Structures ------------------------------------------------------------------

struct Node {
    std::string string;
    int         number;
    Node       *next;
};

struct List {
    Node       *head;
    size_t      size;

    List();
    ~List();

    void push_front(const std::string &s);
};

// Type definitions ------------------------------------------------------------

typedef enum {
    MODE_STL,
    MODE_QSORT,
    MODE_MERGE,
    MODE_QUICK
} Mode;

typedef bool(*CompareFunction)(const Node *, const Node*);

// Functions -------------------------------------------------------------------

bool node_number_compare(const Node *a, const Node *b);
bool node_string_compare(const Node *a, const Node *b);
int  void_number_compare(const void *a, const void *b);
int  void_string_compare(const void *a, const void *b);
void dump_node(Node *n);

void stl_sort(List &l, bool numeric);
void qsort_sort(List &l, bool numeric);
void merge_sort(List &l, bool numeric);
void quick_sort(List &l, bool numeric);

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
