#include <iostream>
#include <math.h>
#include "hash.hpp"

using namespace std;

// defualt constructor to create heap tabel of give size
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

// private method to create a new node for insertion
node* HashTable::createNode(int key, node* next) {
    // create new node and set values
    node* n = new node();
    n->key = key;
    n->next = next;

    // return pointer to node
    return n;
}

// insert a new node in the hashtable
bool HashTable::insertItem(int key) {
    // create hash and new node
    int idx = hashFunction(key);
    node* n = createNode(key, 0);

    // if no collision
    if(table[idx] == 0) {
        table[idx] = n;
        return true;
    }
    else {
        // if there is a collision, find the next open index
        numInsertColl++;
        int it = 1;

        while(true) {

            // find the next index a quadratic leap away
            int quad = idx + pow(it, 2);
            quad = quad % tableSize;

            if(table[quad] == 0) {
                table[quad] = n;
                return true;
            }

            // increment the iterator
            it++;
        }
    }
}


// return a value from 0 to 39,999
unsigned int HashTable::hashFunction(int key) {
    return (key % tableSize);
}

// function to print the table
void HashTable::printTable() {
    // print the current nodes
    for(int i = 0; i < tableSize; ++i) {
        // only print if node is not 0
        if(table[i] != 0)
            cout << "[" << i << "] -> " << table[i]->key << endl;
    }
}

// return the number of collisions
int HashTable::getNumInsertCol() {
    return numInsertColl;
}

// return number of search Collissions
int HashTable::getNumSearchCol() {
    return numSearchColl;
}


// search for a give value
node* HashTable::searchItem(int key) {
    // first hash the key
    int idx = hashFunction(key);


    // if empty, don't search
    if(table[idx] == 0) return 0;

    // check first instance of search
    if(table[idx]->key == key) return table[idx];

    numSearchColl++;

    // find the node
    int it = 1;
    while(true) {

        // calculate the next index to be probed
        int quad = idx + pow(it, 2);
        quad = quad % tableSize;

        // check the next index
        if(table[quad] != 0)
            if(table[quad]->key == key) return table[quad];

        // check if DNE - don't need for this as every value guaranteed to be found
        // if(table[quad] == 0) return 0;

        // increment the iterator
        it++;
    }
}