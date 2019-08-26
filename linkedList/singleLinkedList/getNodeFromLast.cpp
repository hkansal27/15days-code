// A simple program to find the the nth node from the linked list from end.
// one simple algo is to find the length of the linked list and then find the respective (len - N + 1)th node from the start. Other one is to find recursively.

#include<iostream>

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

void printList(Node ** head_ref) {
    Node * current = * head_ref;

    while(current != nullptr) {
        cout<< current-> data<< endl;
        current = current -> next;
    }
}


int printNthNodeFromEnd(Node ** head_ref, int N) {
    static int i = 0;
    Node * current = *head_ref;
    if(current == nullptr)
        return 0;
    printNthNodeFromEnd(&(current -> next), N);

    if(++i == N) {
        cout<< current -> data << endl;
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

    cout << "The 1th node data from end is " << printNthNodeFromEnd(&head, 3);

    return 0;
}
