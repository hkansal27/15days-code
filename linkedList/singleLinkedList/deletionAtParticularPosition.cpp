// A sample program to delete a node of a single linked list at a particular position.

#include<iostream>

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

void deleteAtPosition(Node * ptr, int pos) {
    Node * prev;
    while (pos > 0 && ptr -> next != nullptr ) {
        prev = ptr;
        ptr = ptr -> next;
        pos--;
    }
    prev -> next = prev -> next -> next;
    free(prev -> next);
}


int main() {

     Node * head = nullptr;
     pushData(&head, 7);
     pushData(&head, 8);
     pushData(&head, 9);
     pushData(&head, 10);

    printData(head);

    deleteAtPosition(head, 2);

    printData(head);

    return 0;
}
