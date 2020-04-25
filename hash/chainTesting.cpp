#include <iostream>
#include "hash.hpp"

using namespace std;

int main()
{
    // test 1
    cout << "Test 1..." << endl;
    HashTable ht1(5);
    int rand1[] = {20, 11, 12, 13, 15, 14, 30, 21};
    for(int i = 0; i < 8; ++i) {
        ht1.insertItem(rand1[i]);
    }
    ht1.printTable();
    cout << endl;

    // search for value that doesn't exist
    cout << "searching for 16, expecting NOT TO find it..." << endl;
    node* s1 = ht1.searchItem(16);
    if(s1 == 0) cout << "not found" << endl;
    else cout << "found: " << s1->key << endl;
    cout << endl;
    // searching  for value that does exist
    cout << "searching for 30, expecting TO find it..." << endl;
    node* s2 = ht1.searchItem(30);
    if(s2 == 0) cout << "not found" << endl;
    else cout << "found: " << s2->key << endl;

    cout << endl << "-------------------------------------------------------" << endl << endl;

    cout << "Test 2..." << endl;
    HashTable ht2(75);
    int rand2[] = {11, 200, 13, 300, 400 , 600, 9000, 25, 78, 40000, 245, 23, 235, 2344, 866};
    for(int i = 0; i < 15; ++i) {
        ht2.insertItem(rand2[i]);
    }
    ht2.printTable();

    return 0;
}