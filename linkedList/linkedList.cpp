#include "linkedList.hpp"

// constructor
LinkedList::LinkedList()
{
    head = 0;
}

// destructor
LinkedList::~LinkedList()
{
    // for loop that deletes each node in the linked list
    for(Node* curr = head; curr != 0; curr = curr->next)
    {
        delete curr;
        curr = 0;
    }

    head = 0;
}

// insert function to put in new nodes
void LinkedList::insert(Node * left, int key)
{
    Node* temp = new Node(key, 0);

    if(left == 0) // if the node is to be inserted as the head in the function
    {
        temp->next = head;
        head = temp;
    }

    else
    {
        temp->next = left->next;
        left->next = temp;
    }
    return; 
}

// search function to find a node
Node* LinkedList::search(int key)
{
    for(Node* temp = head; temp != 0; temp = temp->next)
    {
        if(temp->key == key)
        {
            return temp;
        }
    }

    return 0;
}

// display function to print the linked list in order
void LinkedList::displayList()
{
    cout << "[ ";

    for(Node* temp = head; temp != 0; temp = temp->next)
    {
        if(temp->next != 0)
        {
            cout << temp->key << " -> ";
        }

        else
        {
            cout << temp->key << " ";
        }
        
    }

    cout << "]" << endl;

    return;
}