#include <limits>
#include "CountMinSketch.h"
#include "HashFunctions.h"
#include <iostream>

void CountMinSketch::increment(const string & s) {
    unsigned int m = 0;
    // iterate through hash functions
    for (unsigned int k = 0; k < this->K; k++) {
        // bitlength index (col)
        m = hash_functions[k](s) % this->M;;
        // increment cell of hash function
        count[k][m]++;
    }
}

unsigned int CountMinSketch::estimate(const string & s) {
    // track min of counts in indices for given string
    unsigned int cnt = 0;
    unsigned int min = 0;

    unsigned int m = 0;
    // set increment of count matric for element s
    // k is the hash value we are on
    for (unsigned int k = 0; k < this->K; k++) {
        // bitlength index (col)
        m = hash_functions[k](s) % this->M;
        // get current count from cell
        min = this->count[k][m];
        // cout << "cnt: " << cnt << endl;
        if (cnt > min) {
            min = cnt;
        }
    }
    // return min of coordinates, how many times elements has been seen at most
    return min;
}
