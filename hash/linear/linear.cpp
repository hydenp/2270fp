#include <iostream>
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

    // start the number of collisions at zero
    // numOfcolision = 0;
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
        numOfcolision++;

        while(true) {
            idx++;

            // check if we've reach the end -> start at the beginning
            if(idx == tableSize) idx = 0;

            if(table[idx] == 0) {
                table[idx] = n;
                return true;
            }
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
int HashTable::getNumOfCollision() {
    return numOfcolision;
}

/*

// recursive helper?
node* search(node* tbl, int key, int start) {
    // check 
}

*/


// search for a give value
node* HashTable::searchItem(int key) {
    // first hash the key
    int idx = hashFunction(key);
    int dne = idx;

    // if empty, don't search
    if(table[idx] == 0) return 0;

    // find the node
    while(true) {
        
        if(table[idx]->key == key) return table[idx];

        // move to the next index
        idx++;

        // if the next index is zero, end the search
        // don't need this for implementation as we are guaranteed to find every value
        // if(table[idx] == 0) return 0;

        // if we're at the end, go back to the beginning
        if(idx == 40000) idx = 0;

        // if we have gone in a full circle, return 0;
        if(idx == dne) return 0;
    }
}