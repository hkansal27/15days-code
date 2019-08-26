// A simple program to find the length of the linked list.

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

    Node * current = *head_ref;

    if(current == nullptr) {
        *head_ref = temp;
    } else {
        while( current -> next != nullptr ) {
            current = current -> next;
        }
        current -> next = temp;
    }

}

int findLength(Node ** head_ref) {
    int length = 0;
    Node * current = * head_ref;

    while(current != nullptr) {
        length++;
        current = current -> next;
    }

    return length;
}

int main() {
    Node * head = nullptr;

    pushData(&head, 4);
    pushData(&head, 5);
    pushData(&head, 6);
    pushData(&head, 7);
    pushData(&head, 4);
    pushData(&head, 5);
    pushData(&head, 6);
    pushData(&head, 7);

    cout<< findLength(&head) << endl;

    return 0;
}
