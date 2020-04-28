#include "linkedList.hpp"

// just testing my functions :)
int main()
{
    LinkedList ll;

    ll.insert(0,13);
    Node* left = ll.search(13);
    ll.insert(left, 14);
    Node* left2 = ll.search(14);
    ll.insert(left2, 15);
    Node* left3 = ll.search(15);
    ll.insert(left3, 16);

    ll.displayList();

    ll.insert(0,100);

    ll.displayList();

    exit(0); // code seg faults with out this statement, did some research and found out this is because the stack has been corrupted, This statement allows us to avoid the seg fault
    
    return 0;
}