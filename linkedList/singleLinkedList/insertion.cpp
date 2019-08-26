// A simple C++ program for insertion and traversal of a single linked list.

#include <iostream>

using namespace std;


class Node {
public:
    int data;
    Node * next;
};

void printData(Node * ptr) {
    while(ptr != nullptr) {
        cout<< ptr -> data << endl;
        ptr = ptr -> next;
    }
}

int main() {

    Node * head = new Node();
    Node * first = new Node();
    Node * second = new Node();

    head -> data = 1;
    head -> next = first;

    first -> data = 2;
    first -> next = second;

    second -> data = 3;
    second -> next = NULL;

    printData(head);

    return 0;

}
