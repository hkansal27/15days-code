// A simple program to print the data of Nth Node of a single linked list.

#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node * next;
};

void pushData(Node ** head_ref, int data) {
    Node * temp = new Node();
    temp -> data = data;
    temp -> next = nullptr;

    Node * current = * head_ref;

    if(current == nullptr) {
        *head_ref = temp;
    } else {
        while(current -> next != nullptr) {
            current = current -> next;
        }
        current -> next = temp;
    }
}

int printN_Node(Node ** head_ref, int N) {
    Node * current = * head_ref;
    int index = 0;
    while ( current != nullptr) {
        if(index == N) {
            cout << current -> data << endl;
            return 1;
        }
        index++;
        current = current -> next;
    }

    return 0;
}

void printList(Node ** head_ref) {
    Node * current = * head_ref;

    while(current != nullptr) {
        cout<< current-> data<< endl;
        current = current -> next;
    }
}

int main() {
    Node * head = nullptr;

    pushData(&head, 4);
    pushData(&head, 5);
    pushData(&head, 6);
    pushData(&head, 7);
    pushData(&head, 8);

    printList(&head);

    cout << "The 4th node data is " << printN_Node(&head, 3);

    return 0;
}

