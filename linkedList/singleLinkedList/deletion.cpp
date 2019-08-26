// A simple cpp program for deletion a particular data from a single linked list.

#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node * next;
};

void printData(Node * ptr) {
    while (ptr != nullptr) {
        cout<<ptr -> data << endl;
        ptr = ptr -> next;
    }
}

int deleteNode(int data, Node * ptr) {
    if(ptr == nullptr) {
        return 0;
    } else {
        while( ptr -> next -> data != data) {
            ptr = ptr -> next;
        }
        ptr -> next = ptr -> next -> next;
        free(ptr-> next);
        return 1;
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

void pushEfficiently(Node** head_ref, int new_data)
{
    Node * new_node = new Node();
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}


int main() {
    Node * head = new Node();
    // pushData(&head, 1);
    // pushData(&head, 2);
    // pushData(&head, 3);
    // pushData(&head, 4);

    pushEfficiently(&head, 1);
    pushEfficiently(&head, 2);
    pushEfficiently(&head, 3);
    pushEfficiently(&head, 4);

    printData(head);

    deleteNode(2, head);

    printData(head);

    return 0;
}
