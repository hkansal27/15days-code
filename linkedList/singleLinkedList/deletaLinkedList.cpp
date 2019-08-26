// A sample program to delete the single linked list nodes one by one.

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

void deleteNodes(Node ** head_ref) {
   Node * current, * next;
   current = *head_ref;
   while(current != nullptr) {
        next = current->next;
        free(current);
        current = next;
   }
   *head_ref = nullptr;
}

int main() {

     Node * head = nullptr;
     pushData(&head, 7);
     pushData(&head, 8);
     pushData(&head, 9);
     pushData(&head, 10);

    printData(head);

    deleteNodes(&head );

    printData(head);

    return 0;
}
