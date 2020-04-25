#include <iostream>
#include <fstream>
#include <chrono> 
#include <cstdlib>
#include <vector>

using namespace std;
using namespace std::chrono;

int main() {

    // array holding values read from file
    int vals[40000];

    // arrays holding insert and search times
    double insert[400];
    double search[400];

    // open stream to read file
    ifstream read;
    read.open("dataSetA.csv");

    // seed random number generator and vector to store stearches
    srand(time(0));
    vector<int> s;


    // read in all the values to vals array
    string num;
    int i = 0;
    while(getline(read, num, ',')) {
        vals[i] = stoi(num);
    }

    // insert values 100 at a time and measure the average time for each
    for(int i = 0; i < 400; ++i) {

        // start the clock
        auto startI = high_resolution_clock::now();

        // insert the nest 100 elements
        for(int j = (i * 100); j < (j + 100); ++j) {
            // insert 
        }

        // stop the clock and calculate difference
        auto stopI = high_resolution_clock::now();
        auto durationI = duration_cast<microseconds>(stopI - startI);
        // convert time to a double
        double timeI = durationI.count();

        // divide the valude by 100 and add to the insert times
        timeI = timeI / 100.0;
        insert[i] = timeI;

        // find a 100 random numbers within the inserted data to search for
        // put them in the search vector
        for(int k = 0; k < 100; ++k) {
            int ri = rand() % (i * 100);
            s.push_back(vals[ri]);
        }

        // search for each of the hundred randomly selected values
        // start the clock
        auto startS = high_resolution_clock::now();
        for(int l = 0; l < 100; ++l) {
            // search for the values for example
            // bst.insert(s[l]);
        }
        // stop the clock and calculate difference
        auto stopS = high_resolution_clock::now();
        auto durationS = duration_cast<microseconds>(stopS - startS);
        // convert time to a double
        double timeS = durationS.count();

        // divide the valude by 100 and add to the insert times
        timeS = timeS / 100.0;
        search[i] = timeS;
        // clear search values
        s.clear();
    }


    // write results to output csv

    // write insert times;
    ofstream writeI;
    writeI.open("insertionTimes.csv");
    for(int i = 0; i < 400; ++i) {
        writeI << insert[i] << endl;
    }
    writeI.close();

    // write search times;
    ofstream writeS;
    writeS.open("searchTimes.csv");
    for(int i = 0; i < 400; ++i) {
        writeS << search[i] << endl;
    }
    writeS.close();


    return 0;
}