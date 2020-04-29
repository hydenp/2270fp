// Hash Linear Probing Header definition
// Author: Hyden Polikoff

#ifndef HASH_HPP
#define HASH_HPP

#include <string>


using namespace std;

struct node
{
    int key;
    struct node* next;
};

class HashTable
{
    int tableSize;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    node* *table;
    int numInsertColl = 0;
    int numSearchColl = 0;
    node* createNode(int key, node* next);
    
public:
    HashTable(int bsize);  // Constructor

    // inserts a key into hash table
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();
    int getNumInsertCol();
    int getNumSearchCol();

    node* searchItem(int key);
};

#endif
