#include <iostream>
#include "hash.hpp"

using namespace std;

HashTable::HashTable(int bsize) {
    // declare a new table of size bsize
    tableSize = bsize;

    node* *arr = new node*[tableSize];
    table = arr;

    // set all pointers to 0
    for(int i = 0; i < bsize; ++i) {
        table[i] = 0;
    }

}

node* HashTable::createNode(int key, node* nx) {
    // create new node and set values
    node* n = new node();
    n->key = key;
    n->next = nx;

    // return pointer to node
    return n;
}

bool HashTable::insertItem(int key) {
    int idx = hashFunction(key);
    node* n = createNode(key, 0);

    if(table[idx] == 0)
    {
        table[idx] = n;

        return true;
    }

    else 
    {
        numInsertColl++;

        node* temp = table[idx];
        table[idx] = n;
        n->next = temp;

        return true;
    }
}


unsigned int HashTable::hashFunction(int key) {
    return (key % tableSize);
}

void HashTable::printTable() {
    // print the current nodes
    for(int i = 0; i < tableSize; ++i) {
        // only print if node is not 0
        if(table[i] != 0x0)
        {
            cout << "[" << i << "] -> " << table[i]->key;

            node* temp = table[i]->next;

            while(temp != 0x0)
            {
                cout << " -> " << temp->key;
                temp = temp->next;
            }

            cout << endl;
        }
    }
}

int HashTable::getNumInsertCol() {
    return numInsertColl;
}

int HashTable::getNumSearchCol() {
    return numSearchColl;
}

node* HashTable::searchItem(int key) {
    int idx = hashFunction(key);

    if(table[idx] == 0)
    {
        return 0;
    }

    else
    {
        numSearchColl++;
        node* temp = table[idx];

        while(temp != 0)
        {
            if(temp->key == key)
            {
                return temp;
            }

            temp = temp->next;
        }
    }

    return 0;
}
