// A simple program to search an element whether it is present or not in the list.

#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node * next;
};

bool searchElement(Node ** head_ref, int num) {
    Node * current = * head_ref;

     while (current != nullptr)
    {
        if (current->data == num)
            return true;
        current = current->next;
    }
    return false;
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

int main() {
    Node * head = nullptr;

    pushData(&head, 4);
    pushData(&head, 5);
    pushData(&head, 6);
    pushData(&head, 7);

    cout<< searchElement(&head, 6)<< endl;

    return 0;
}
