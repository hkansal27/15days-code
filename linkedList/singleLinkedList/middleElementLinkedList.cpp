// A sample program to find the middle element of the single linked list.
// one simple approach is to first find the length of the linked list then again traversal to find the middle element.
// second algo is implemented below:

#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node * next;
};

void pushData(Node ** head_ref, int data ) {
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
    while (current != nullptr) {
        cout << current -> data << endl;
        current = current -> next;
    }
}


int findMiddle(Node ** head_ref) {
    Node * slow_ptr, * fast_ptr;

    slow_ptr = *head_ref;
    fast_ptr = *head_ref;

    while(fast_ptr -> next != nullptr) {
        slow_ptr = slow_ptr->next;
        if(fast_ptr -> next -> next != nullptr) {
            fast_ptr = fast_ptr -> next -> next;
        } else {
            fast_ptr = fast_ptr -> next;
        }
    }

    return slow_ptr -> data;
}

int main() {
    Node * head = nullptr;

    pushData(&head, 4);
    pushData(&head, 5);
    pushData(&head, 6);
    pushData(&head, 7);
    pushData(&head, 8);
    pushData(&head, 6);

    printList(&head);

    cout << "The middle node data is " << findMiddle(&head);

    return 0;
}
