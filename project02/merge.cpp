// merge.cpp

#include "lsort.h"

#include <iostream>

// Prototypes

Node *msort(Node *head, CompareFunction compare);
void  split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, CompareFunction compare);

// Implementations

void merge_sort(List &l, bool numeric) {

	Node* head = l.head;

	if (numeric)
		l.head = msort(head, node_number_compare );
	else
		l.head = msort(head, node_string_compare );

}

Node *msort(Node *head, CompareFunction compare) {
	Node leftnode = {"", 0, nullptr};
	Node rightnode = {"", 0, nullptr};
	Node *left = &leftnode;
	Node *right = &rightnode;

	if ((head == NULL) || (head->next == NULL)) return(head);

	split(head, left, right);

	left = msort(left, compare);
	right = msort(right, compare);

	return merge(left, right, compare);

}

void split(Node *head, Node *&left, Node *&right) {

	struct Node* fast;
	struct Node* slow;

	if (head == NULL || head->next == NULL) {

		left = head;
		right = NULL;
	} else {
		slow = head;
		fast = head->next;


		while (fast != NULL) {
			fast = fast->next;
			if (fast != NULL) {
				slow = slow->next;
				fast = fast->next;
			}
		}

		right = slow->next;
		slow->next = nullptr;
		left = head;
	}

}

Node *merge(Node *left, Node *right, CompareFunction compare) {

    Node dummyHead = {"", 0, nullptr};
	Node *result, *dummyHeadptr;
    result = &dummyHead;
	dummyHeadptr = &dummyHead;

	while (left != NULL && right != NULL) {
		if (compare(left, right)) {
		 result->next = left;
		 left = left->next;
		} else {
		 result->next = right;
		 right = right->next;
		}
		result = result->next;
	}

    result->next = (left == NULL) ? right : left;
	return(dummyHeadptr->next);

}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
