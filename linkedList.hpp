#include <iostream>

using namespace std;

struct Node{
    int key; // value of the current node
    Node * next; // address of the next node

    Node() {next = 0;} // default constructor
    Node(int k, Node* n) {key = k; next = n;} // specific constructor
};

class LinkedList{

    private:
        Node* head; //pointer to the first node in the Linked List

    public: 
        LinkedList(); //constructor
        ~LinkedList(); //destructor
        void insert(Node * left, int key); //function that inserts a node after "left" node
        Node* search(int key); //function that returns a node pointer to the node with "key"
        void displayList(); //function that prints the Linked List in order
};



