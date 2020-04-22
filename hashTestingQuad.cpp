#include <iostream>
#include "hash.hpp"

using namespace std;

int main() {

    // test 1
    cout << "Test 1, table sized 5 with 3 values..." << endl;
    HashTable ht1(5);
    int rand1[] = {11, 12, 13, 15};
    for(int i = 0; i < 4; ++i) {
        ht1.insertItem(rand1[i]);
    }
    ht1.printTable();
    cout << endl;
    // search for value that doesn't exist
    cout << "searching for 14, expecting NOT TO find it..." << endl;
    node* s1 = ht1.searchItem(14);
    if(s1 == 0) cout << "not found" << endl;
    else cout << "found: " << s1->key << endl;
    cout << endl;
    // searching  for value that does exist
    cout << "searching for 11, expecting TO find it..." << endl;
    node* s2 = ht1.searchItem(11);
    if(s2 == 0) cout << "not found" << endl;
    else cout << "found: " << s2->key << endl;

    cout << endl << "-------------------------------------------------------" << endl << endl;

    // test 2
    cout << "Test 2, table sized 75 with 8 values..." << endl;

    HashTable ht2(75);
    int rand2[] = {15, 15, 15, 15, 300, 400 , 600, 9000, 25, 78, 40000, 245, 23, 235, 2344, 866};
    for(int i = 0; i < 15; ++i) {
        ht2.insertItem(rand2[i]);
    }
    ht2.printTable();
    // search for value that doesn't exist
    cout << "searching for 555, expecting NOT TO find it..." << endl;
    node* s3 = ht2.searchItem(555);
    if(s3 == 0) cout << "not found" << endl;
    else cout << "found: " << s3->key << endl;
    cout << endl;
    // searching  for value that does exist
    cout << "searching for 78, expecting TO find it..." << endl;
    node* s4 = ht2.searchItem(78);
    if(s4 == 0) cout << "not found" << endl;
    else cout << "found: " << s4->key << endl;

    cout << endl;

    return 0;
}