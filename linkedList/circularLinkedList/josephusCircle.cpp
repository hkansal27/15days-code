// A simple program to implement the josephus circle using circular linked list.


#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node * next;
};

Node * createNode(int data) {
    Node * new_node = new Node();
    new_node -> data = data;
    new_node -> next = nullptr;
}

int getJosephusCircle(int N, int M) {

    // first create a circular linked list of N size
    Node * head = createNode(1);
    Node * prev = head;

    for(int i = 2; i <= N; i++) {
        prev -> next = createNode(i);
        prev = prev -> next;
    }

    prev -> next = head;


    Node * temp = head, * temp2 = head;

    while(temp -> next != head) {
        int count = 1;
        while (count != (M)) {
            temp2 = temp;
            temp = temp -> next;
            count ++;
        }
        temp2 -> next = temp -> next;
        temp = temp2 -> next;
        free(temp2);
    }
    return temp -> data;
}


int main() {

    cout << "Josephus Index is" << getJosephusCircle(5, 3) << endl;

    return 0;
}
