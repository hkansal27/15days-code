// A simple program to count the nodes of a circular linked list.

#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node * next;
};

void pushElement(Node ** head_ref, int data) {

    Node * current = *head_ref;

    Node * temp = new Node();
    temp -> data = data;
    temp -> next = nullptr;

    if(current == nullptr) {
        temp -> next = temp;
        *head_ref = temp;
    } else {
        while(current -> next != *head_ref) {
            current = current -> next;
        }
        current -> next = temp;
        temp -> next = *head_ref;
    }
}

int countNodes(Node ** head_href) {
    Node * current = * head_href;

    int a = 0;

    if(current == nullptr)
        return 0;

    do {
        a++;
        current = current -> next;
    } while (current != *head_href);

    return a;
}

int main() {
    Node * head = nullptr;

    pushElement(&head, 20);
    pushElement(&head, 4);
    pushElement(&head, 15);
    pushElement(&head, 10);
    pushElement(&head, 25);
    pushElement(&head, 15);
    pushElement(&head, 10);
    pushElement(&head, 25);

    cout << "Total nodes in the circular linked list: " << countNodes(&head) << endl;

    return 0;
}
