// A simple program to insert elements in the circular linked list.


#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node * next;
};

int pushElement(Node ** head_ref, int data ) {

    Node * temp = new Node();
    temp -> data = data;

    Node * current = *head_ref;

    if(current == nullptr) {
        *head_ref = temp;
        temp ->next = temp;
        return 0;
    }

    while(current -> next != *head_ref) {
        current = current -> next;
    }

    current -> next = temp;
    temp -> next = *head_ref;
    return 1;
}
// do while

void printData(Node ** head_ref) {

    Node * current = *head_ref;
    do {
        cout<<current -> data << endl;
        current = current -> next;
    }
    while(current != *head_ref);
}
/*
void printData(Node ** head_ref) {

    Node * current = *head_ref;
    while(current -> next != *head_ref) {
        cout<<current -> data << endl;
        current = current -> next;
    }
    cout<<current -> data << endl;
} */

int main() {
    Node * head = nullptr;

    pushElement(&head, 20);
    pushElement(&head, 4);
    pushElement(&head, 15);
    pushElement(&head, 10);

    printData(&head);

    return 0;
}
