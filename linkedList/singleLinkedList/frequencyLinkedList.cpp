// A simple program to count the frequency of a given number.
// First approach is simple to traverse the list and count the matching number.
// same approach with recursive is given below:

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

int frequenyFromList(Node ** head_ref, int N) {
    Node * current = * head_ref;

    static int freq = 0;

    if(current == nullptr)
        return freq;

    if(current -> data == N) {
        freq++;
    }

    return frequenyFromList(&(current-> next), N);
}

int main() {
    Node * head = nullptr;

    pushData(&head, 4);
    pushData(&head, 5);
    pushData(&head, 6);
    pushData(&head, 7);
    pushData(&head, 8);
    pushData(&head, 4);
    pushData(&head, 5);
    pushData(&head, 6);
    pushData(&head, 4);
    pushData(&head, 5);
    pushData(&head, 6);

    printList(&head);

    cout << "The frequency of element " << frequenyFromList(&head, 4);

    return 0;
}
