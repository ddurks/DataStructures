// qsort.cpp

#include "lsort.h"

#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

void qsort_sort(List &l, bool numeric) {

    vector<Node*> copy;
	Node *curr;
	curr = l.head;

	//fill copy vector with linked list values
	for (int count = 0; count < l.size; count++) {
		copy.push_back(curr);
		curr = curr->next;
	}

	//perform stl sort
	if (numeric)
		qsort( copy.data(), copy.size(), sizeof(Node*), void_number_compare );
	else
		qsort( copy.data(), copy.size(), sizeof(Node*), void_string_compare );

	//Re link list
	for(int i = 0; i < l.size-1; i++){
        copy[i]->next = copy[i+1];
	}
	copy[l.size-1]->next = nullptr;
	l.head = copy[0];

}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
