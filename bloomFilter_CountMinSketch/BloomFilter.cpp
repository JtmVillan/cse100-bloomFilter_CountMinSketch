#include "BloomFilter.h"
#include "HashFunctions.h"
#include <iostream>

void BloomFilter::insert(const string & s) {

    // iterate through hash function
    for (unsigned int i = 0; i < this->K; i++) {
        this->bits[(hash_functions[i](s) % this->M)] = true;
    }
}

bool BloomFilter::contains(const string & s) {


    // iterate through hash function
    for (unsigned int i = 0; i < this->K; i++) {
        if (!bits[(hash_functions[i](s) % this->M)]) {
            return false;
        }
    }
    return true;
}
