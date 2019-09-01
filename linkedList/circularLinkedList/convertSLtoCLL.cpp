// A sample program to convert a single linked list to circular linked list


#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node * next;
};

void singleListToCircularList(Node ** head_ref) {
    Node * current = *head_ref;

    while(current -> next != nullptr) {
        current = current -> next;
    }
    current -> next = *head_ref;
}

Node * createNode(int data) {
    Node * temp = new Node();
    temp -> data = data;
    temp -> next = nullptr;

    return temp;
}

void pushElement(Node ** head_ref, int data) {
    Node * temp = createNode(data);

    Node * current = *head_ref;

    if(current == nullptr) {
        *head_ref = temp;
    } else {
        while(current -> next != nullptr) {
            current = current -> next;
        }
        current -> next = temp;
    }
}



void printCircularList(Node ** head_ref) {
    Node * current = *head_ref;

    do {
        cout << current -> data << endl;
        current = current -> next;
    } while (current != *head_ref);
}



int main() {

    Node * head = nullptr;
    pushElement(&head, 2);
    pushElement(&head, 12);
    pushElement(&head, 22);
    pushElement(&head, 32);
    pushElement(&head, 52);
    pushElement(&head, 62);
    pushElement(&head, 72);

    singleListToCircularList(&head);

    printCircularList(&head);

    return 0;
}
