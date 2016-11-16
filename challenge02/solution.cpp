// David Durkin
// Data Structures
// Challenge 02: Adding List-Based Integers
// Adding integers as linked lists when each digit is a seperate node

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

//List struct, I used a struct to ensure all members were public by default
template <typename T>
struct List{
    //Node struct for list members
    struct Node {
        T     data;
        Node *next;
    };

    //iterator, head node, and length members
    typedef Node * iterator;
    Node *head;
    size_t length;

    //Constructor
    List() : head(nullptr), length(0) {}

    //Destructor
    ~List(){
        Node *next = nullptr;

        // Need next otherwise invalid reads (use valgrind)
        for (Node *curr = head; curr != nullptr; curr = next) {
            next = curr->next;
            delete curr;
        }
    }

    //Copy Constructor
    List(const List<T>& other)
        : head(nullptr), length(0) {
        for (Node *curr = other.head; curr != nullptr; curr = curr->next) {
            push_back(curr->data);
        }
    }

    //Assignment operator
    List<T> &operator=(List<T> &other){
        swap(other);
        return *this;
    }

    //Swap function for assignment operator
    void swap(List<T> &other){
        std::swap(head, other.head);
        std::swap(length, other.length);
    }

    //Size function
    size_t size() const{
        size_t size = 0;

        for (Node *node = head; node != nullptr; node = node->next) {
            size++;
        }
        return size;
    }

    //specific node access function
    T& at(const size_t i){
        Node *node = head;
        size_t   n = 0;
        while (n < i && node != nullptr) {
            node = node->next;
            n++;
        }
        if (node != nullptr) {
            return node->data;
        } else {
            throw std::out_of_range("invalid list index");
        }
    }

    //insert function
    void insert(iterator it, const T &data){

        if (head == nullptr && it == nullptr) {
            head = new Node{data, nullptr};
            return;
        }
        if (it == nullptr) {
            throw std::out_of_range("invalid iterator");
        }
        it->next = new Node{data, it->next};
    }

    //push_back function
    void push_back(const T &data){

        if (head == nullptr) {
            head = new Node{data, nullptr};
            return;
        }

        Node *curr = head;
        Node *tail = head;

        while (curr) {
            tail = curr;
            curr = curr->next;
        }

        tail->next = new Node{data, nullptr};
    }

    //End insert function
    void insertAtEnd(const T &data){
        Node *temp = new Node;
        temp->data = data;
        temp->next = nullptr;

        if(head == nullptr){
            head = temp;
            return;
        }
        else{
            Node *last = head;
            while(last->next){
                last = last->next;
            }
            last->next = temp;
        }
    }

    //erase function
    void erase(iterator it){
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
    }

    //clear function to reset lists
    void clear(){
        Node *current = head;
        while( current != nullptr ) {
            Node *next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    //addition function implemented as a friend in order to use Node struct
    friend void add(List<int>& sumList, List<int>& one, List<int>& two){
        Node *node1 = one.head; Node *node2 = two.head;

        int sum = 0, carry = 0;
        while(node1 != nullptr || node2 != nullptr)
        {
            if(node1)
                sum += node1->data;
            if(node2)
                sum += node2->data;
            sum += carry;

            carry = 0;
            sumList.insertAtEnd(sum%10);
            if(sum > 9 && node1->next == nullptr && node2->next == nullptr)
                sumList.insertAtEnd(1);
            else if (sum > 9)
                carry = 1;
            sum = 0;
            if (node1){
                node1 = node1->next;
            }
            if (node2){
                node2 = node2->next;
            }
        }
    }
};

//Main execution
int main(int argc, char *argv[]) {

    string line, s1, s2;

    while(getline(cin, line)){
        List<int> one, two, sum;
        istringstream iss(line);

        iss >> s1 >> s2;

        for(int i = (s1.size()-1); i >= 0; i--){
            one.push_back(s1[i]-'0');
        }
        for(int i = (s2.size()-1); i >= 0; i--){
            two.push_back(s2[i]-'0');
        }

        one.at(0);
        two.at(0);

        add(sum, one, two);

        for(int i = (sum.size()-1); i >= 0; i--){
            cout << sum.at(i);
        }
        cout << endl;

        one.clear();
        two.clear();
        sum.clear();
    }

    return 0;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
