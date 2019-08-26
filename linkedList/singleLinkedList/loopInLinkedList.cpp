// A simple program to check whether there is a loop in the linked list.
// Floyd’s Cycle-Finding Algorithm Implementation

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

bool loopDetection(Node ** head_href) {
    Node * current = * head_href;
    Node * slow_ptr, * fast_href;

    slow_ptr = current, fast_href = current;

    while(fast_href -> next != nullptr) {
        slow_ptr = slow_ptr->next;
        if(fast_href -> next -> next != nullptr) {
            fast_href = fast_href -> next -> next;
        } else {
            return false;
        }

        if(slow_ptr == fast_href) {
            return true;
        }
    }
}

int main() {
    Node * head = nullptr;

    pushData(&head, 20);
    pushData(&head, 4);
    pushData(&head, 15);
    pushData(&head, 10);

    /* Create a loop for testing */
    head->next->next->next->next = head;

    cout << "The frequency of element " << loopDetection(&head);

    return 0;
}
