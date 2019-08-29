// A simple program to insert the data in a sorted order in the linked list.

#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node * next;
};

void sortedPushElement(Node ** head_ref, int data ) {

    Node * temp = new Node();
    temp -> data = data;

    Node * current = *head_ref;

    if(current == nullptr) {
        *head_ref = temp;
        temp -> next = temp;
    }  else if (current->data >= temp->data)  {
        while(current->next != *head_ref)
        current = current->next;
        current->next = temp;
        temp->next = *head_ref;
        *head_ref = temp;
    }  else {
        while(current -> next != *head_ref && current -> next -> data < temp->data) {
            current = current -> next;
        }
        temp -> next = current -> next;
        current -> next = temp;
    }

}

void printData(Node ** head_ref) {

    Node * current = *head_ref;

    do {
        cout << current -> data << endl;
        current = current -> next;
    }
    while(current != *head_ref);
}

int main() {
    int arr[] = {1, 17, 2, 0, 4, 83, 5};

    Node * head = nullptr;

    for(int i = 0; i < 5; i++) {
        sortedPushElement(&head, arr[i]);
        // printData(&head);
    }

    printData(&head);

    return 0;
}
