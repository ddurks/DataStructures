// Challenge 07: Linked List Deduplication
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <unordered_set>

using namespace std;

// Structures

template <typename T>
class List {
    protected:
        struct Node {
            T     data;
            Node *next;
        };

        typedef Node * iterator;

        Node  *head;
        size_t length;

    public:
        List() : head(nullptr), length(0) {}
        iterator front() { return head; };

        ~List();
        List(const List<T> &other);
        List<T>& operator=(List<T> other);
        void swap(List<T> &other);

        size_t size() const { return length; }
        T& at(const size_t i);
        void push_back(const T &data);
        void erase(iterator it);
        void print();
        void clear();
        void deduplicate();
};


template <typename T>
List<T>::~List() {
    Node *next = nullptr;

    for (Node *curr = head; curr != nullptr; curr = next) {
        next = curr->next;
        delete curr;
    }
}

template <typename T>
List<T>::List(const List<T> &other) : head(nullptr), length(0) {
    for (Node *curr = other.head; curr != nullptr; curr = curr->next) {
        push_back(curr->data);
    }
}

template <typename T>
List<T>& List<T>::operator=(List<T> other) {
    swap(other);
    return *this;
}

template <typename T>
void List<T>::swap(List<T> &other) {
    std::swap(head, other.head);
    std::swap(length, other.length);
}

template <typename T>
T& List<T>::at(const size_t i) {
    Node *node = head;
    size_t   n = 0;

    while (n < i && node != nullptr) {
        node = node->next;
        n++;
    }

    if (node) {
        return node->data;
    } else {
        throw std::out_of_range("invalid list index");
    }
}

template <typename T>
void List<T>::push_back(const T& data) {
    if (head == nullptr) {
        head = new Node{data, nullptr};
    } else {
        Node *curr = head;
        Node *tail = head;

        while (curr) {
            tail = curr;
            curr = curr->next;
        }

        tail->next = new Node{data, nullptr};
    }
    length++;
}

template <typename T>
void List<T>::erase(iterator it) {
    if (it == nullptr) {
	throw std::out_of_range("invalid iterator");
    }

    if (head == it) {
	head = head->next;
	delete it;
    } else {
	Node *node = head;

	while (node != nullptr && node->next != it) {
	    node = node->next;
	}

	if (node == nullptr) {
	    throw std::out_of_range("invalid iterator");
	}

	node->next = it->next;
	delete it;
    }

    length--;
}

template<typename T>
void List<T>::print(){
    Node *curr = head;
    int first = 1;
    while(curr != nullptr){
        if(!first) cout << " ";
        cout << curr->data;
        curr = curr->next;
        first = 0;
    }
}

template<typename T>
void List<T>::clear(){
    Node *del = head;

    while(del != nullptr){
        head = head->next;
        delete del;
        del = head;
    }

    head = nullptr;
}

template<typename T>
void List<T>::deduplicate(){
    unordered_set<int> values;

    if(head->next == nullptr) return;

    Node * prev = head;
    Node * curr = head->next;
    values.insert(head->data);
    while(curr != nullptr){
        if(values.find(curr->data) == values.end()){
            values.insert(curr->data);
            curr = curr->next;
        }
        else{
            prev = curr;
            curr = curr->next;
            erase(prev);
        }
    }

}

// Main Execution

int main(int argc, char *argv[]) {
    int numNodes, temp;
    List<int> numbers;
    while(!cin.eof()){
        cin >> numNodes;

        if(numNodes == 0) break;

        for(int i = 0; i < numNodes; i++){
            cin >> temp;
            numbers.push_back(temp);
        }

        numbers.deduplicate();
        numbers.print();
        cout << endl;

        numbers.clear();
        numNodes = 0;
    }
    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
