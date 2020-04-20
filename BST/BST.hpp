// BST Header definition
// Author: Hyden Polikoff
#include <iostream>

// #pragma once

struct Node{
    int data;

    // children pointers
    Node* left;
    Node* right;
};

class BST{
    private:
        // pointer to head of the tree
        Node* root;

        // helper methods
        void insert(Node* &T, int val);
        Node* search(Node* T, int key);
        void inOrder(Node* T);

    // public methods
    public:
        // default constructor to start root as 0
        BST();

        // key methods
        void insert(int val);
        Node* search(int key);

        // traversals to help with testing
        void inOrder();
};