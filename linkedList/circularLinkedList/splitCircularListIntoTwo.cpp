// A simple program to split the circular linked list into two.

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

void printData(Node ** head_ref) {

    Node * current = *head_ref;
    do {
        cout<<current -> data << endl;
        current = current -> next;
    }
    while(current != *head_ref);
}

void splitTwo(Node ** head_ref, Node ** head1, Node ** head2) {
    Node * current = *head_ref;

    Node * slow_ptr = current, * fast_ptr = current;

    while(fast_ptr -> next != *head_ref) {

        if(fast_ptr -> next -> next != *head_ref) {
            slow_ptr = slow_ptr -> next;
            fast_ptr = fast_ptr -> next -> next;
        } else {
            fast_ptr = fast_ptr -> next;
        }
    }
    // second half
    fast_ptr -> next = slow_ptr  -> next;
    *head2 = slow_ptr -> next;

    // first half
    *head1 = *head_ref;
    slow_ptr -> next = *head_ref;
}

int main() {
    Node * head = nullptr;
    Node * head1 = nullptr;
    Node * head2 = nullptr;

    pushElement(&head, 20);
    pushElement(&head, 4);
    pushElement(&head, 15);
    pushElement(&head, 10);
    pushElement(&head, 25);

    cout << "Original data" << endl;
    printData(&head);

    splitTwo(&head, &head1, &head2);

    cout << "First one" << endl;
    printData(&head1);

    cout << "Second one" << endl;
    printData(&head2);

    return 0;
}
