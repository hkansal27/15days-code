// A simple to check whether a passed linked list is circular or not.

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

void pushElement(Node ** head_ref, int data) {

    Node * new_node = new Node();
    new_node -> data = data;
    new_node -> next = *head_ref;

    Node * current = * head_ref;

    if(current == nullptr) {
        *head_ref = new_node;
        new_node -> next = new_node;
    } else {
        while (current -> next != *head_ref) {
            current = current -> next;
        }
        current -> next = new_node;
    }
}

void printData(Node ** head_ref) {
    Node * current = * head_ref;

    do {
        cout<< current -> data << endl;
        current = current -> next;
    } while (current != *head_ref);
}

bool checkListCircularity(Node ** head_ref) {
    Node * current = * head_ref;

    do {
        if(current == nullptr) {
            return false;
        }
        current = current -> next;
    } while (current != *head_ref || current == nullptr);

    return true;
}

int main() {
    int arr[] = {1, 17, 2, 0, 4, 83, 5};

    Node * head = nullptr;

    for(int i = 0; i < 7; i++) {
        pushElement(&head, arr[i]);
    }

    cout << "Is list is circular:" << checkListCircularity(&head) << endl;

    return 0;
}


