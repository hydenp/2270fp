// BST Header implementation
// Author: Hyden Polikoff
#include "BST.hpp"
#include <iostream>

using namespace std;

// Default constructor to start root at 0
BST::BST() {
    root = 0;
}


// --------------------------------------------
// recursive helper to insert
void BST::insert(Node* &T, int val) {
    // insert when reached leaf
    if(T == 0) {
        // create new node and set vals
        Node* n = new Node();
        n->data = val;
        n->right = 0;
        n->left = 0;

        // point to new node
        T = n;
        return;
    }
    // search left and right
    if(T->data < val) insert(T->right, val);
    else insert(T->left, val);
}

// public insert method
void BST::insert(int val) {
    insert(root, val);
}


// --------------------------------------------
// recursive helper to search
Node* BST::search(Node* T, int key) {
    // if the node does not exist, return 0
    if(T == 0) return T;
    // if at the matching node, return the node
    else if(T->data == key) return T;
    // if the val is greater, search right
    else if(T->data < key) return search(T->right, key);
    // else go left
    else return search(T->left, key);
}


// public search method
Node* BST::search(int key) {
    return search(root, key);
}


// --------------------------------------------
// recursive helper for inOrder
void BST::inOrder(Node* T) {
    if(T == 0) return;
    inOrder(T->left);
    cout << T->data << " ";
    inOrder(T->right);
}


// public inOrder method
void BST::inOrder() {
    inOrder(root);
    cout << endl;
}