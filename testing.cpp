#include <iostream>
#include "BST.hpp"

using namespace std;

int main() {

    // testing 1
    cout << "Test 1: insertion" << endl;
    BST b1;
    int arr1[] = {5, 3, 4, 2, 7, 9, 8, 12, 1};
    for(int i = 0; i < 9; ++i) { 
        b1.insert(arr1[i]);
    }
    // insertion testing
    cout << "Expected: 1 2 3 4 5 7 8 9 12" << endl;
    cout << "Got:    : ";
    b1.inOrder();

    cout << endl << "---------" << endl;
    // --------------------------------------------------

    // test 2
    cout << "Test 2: insertion and search" << endl;
    BST b2;
    int arr2[] = {12, 4, 7, 20, 3, 9, 1, 25};
    for(int i = 0; i < 8; ++i) {
        b2.insert(arr2[i]);
    }
    // insertion testing
    cout << "Expected: 1 3 4 7 9 12 20 25" << endl;
    cout << "Got:    : ";
    b2.inOrder();

    // searching when data should be found
    bool s1 = true;
    if(b2.search(7) == 0) s1 = false;
    cout << "Searching for 7..." << endl;
    cout << "expected: FOUND!" << endl;
    cout << "got     : ";
    if(!s1) cout << "no dice" << endl;
    else cout << "FOUND!" << endl << endl;

    // searching when data does not exist
    bool s2 = true;
    if(b2.search(2) == 0) s1 = false;
    cout << "Searching for 2..." << endl;
    cout << "expected: no dice" << endl;
    cout << "got     : ";
    if(!s1) cout << "no dice" << endl;
    else cout << "FOUND!" << endl;



    return 0;
}