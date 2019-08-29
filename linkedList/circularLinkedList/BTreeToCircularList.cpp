// A simple program to convert the binary tree to circular double linked list.
// have to later give a chance once done with the tree.


#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node * left, * right;
};

Node * createNode(int data) {
    Node * new_node = new Node();
    new_node -> data = data;
    new_node -> right = nullptr;
    new_node -> left = nullptr;

    return new_node;
}

void printData(Node ** head_ref) {
    Node * current = * head_ref;

    do {
        cout << current -> data << endl;
        current = current -> right;
    } while ( current  != *head_ref);
}

Node * concanate ( Node ** left_href, Node ** right_href) {

    if(*left_href == nullptr)
        return *right_href;
    if(*right_href == nullptr) {
        return *left_href;
    }


    // Store the last Node of left List
    Node *leftLast = (*left_href)->left;

    // Store the last Node of right List
    Node *rightLast = (*right_href) ->left;

    // Connect the last node of Left List
    // with the first Node of the right List
    leftLast->right = *right_href;
    (*right_href)->left = leftLast;

    // Left of first node points to
    // the last node in the list
    (*left_href)->left = rightLast;

    // Right of last node refers to the first
    // node of the List
    (rightLast)->right = *left_href;

    return *left_href;
}

Node *bTreeToCList(Node * root) {

    if(root == nullptr)
        return nullptr;

    Node * left = bTreeToCList(root -> left);
    Node * right = bTreeToCList(root -> right);

    root -> left = root;
    root -> right = root;

    Node * temp = concanate(&left, & root);

    return concanate(&temp, &right);
}

int main() {
    Node *root = createNode(10);
    root->left = createNode(12);
    root->right = createNode(15);
    root->left->left = createNode(25);
    root->left->right = createNode(30);
    root->right->left = createNode(36);

    Node *head = bTreeToCList(root);
    printData(&head);

    return 0;

}
