// A simple program to implement the circular queue.
// Operations on Circular Queue:

// 1. Front:Get the front item from queue.
// 2. Rear: Get the last item from queue.
// 3. enQueue(value) This function is used to insert an element into the circular queue. In a circular queue, the new element is always inserted at Rear position.
// 4. deQueue() This function is used to delete an element from the circular queue. In a queue, the element is always deleted from front position.


#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node * link;
};

Node * createNode(int data) {
    Node * temp = new Node();
    temp -> data = data;
    temp -> link = nullptr;

    return temp;
}

class Queue {
public:
    Node * rearElement;
    Node * frontElement;
};


void enQueue(Queue ** q_ref, int data) {

    Queue * q = *q_ref;

    Node * temp =  createNode(data);

    if(q -> frontElement == nullptr) {
        q -> frontElement = temp;
    } else {
        temp -> link = q -> rearElement;
    }
    q -> rearElement = temp;
    q -> rearElement -> link = q -> frontElement;
}

int deQueue(Queue ** q_ref) {
    Queue * q = *q_ref;
    if (q->frontElement == nullptr)
    {
        return INT_MIN;
    }

    int value; // Value to be dequeued
    if (q->frontElement == q->rearElement)
    {
        value = q->frontElement->data;
        free(q->frontElement);
        q->frontElement = nullptr;
        q->rearElement = nullptr;
    }
    else {
        Node * temp = q -> frontElement;
        value = temp->data;
        q->frontElement = q->frontElement->link;
        q->rearElement->link= q->frontElement;
        free(temp);
    }
    return value ;
}

void displayQueue(Queue ** q_ref) {
    Node * temp = (*q_ref) -> frontElement;

    do {
        cout << temp -> data << endl;
        temp = temp -> link;
    } while(temp != (*q_ref) -> frontElement);
}

int main() {

   // Create a queue and initialize front and rear
    Queue *q = new Queue();
    q->frontElement = q->rearElement = nullptr;

    // Inserting elements in Circular Queue
    enQueue(&q, 14);
    enQueue(&q, 22);
    enQueue(&q, 6);

    cout << "enqueue successful" << endl;

    // Display elements present in Circular Queue
    displayQueue(&q);

    // Deleting elements from Circular Queue
    cout << "\nDeleted value = %d" << deQueue(&q);
    cout << "\nDeleted value = %d" << deQueue(&q);

    // Remaining elements in Circular Queue
    displayQueue(&q);

    enQueue(&q, 9);
    enQueue(&q, 20);
    displayQueue(&q);

    return 0;

}
