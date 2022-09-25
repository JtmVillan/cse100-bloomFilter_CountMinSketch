/*
 * Name: CSE 100 Staff
 * Email: cs100sp22@ucsd.edu
 *
 * Sources Used: None.
 *
 * This file provides some test cases for PA5.
 */

#include "BloomFilter.h"
#include "CountMinSketch.h"
using namespace std;

/* Macro to explicity print tests that are run along with colorized result. */
#define TEST(EX) (void)((fprintf(stdout, "(%s:%d) %s:", __FILE__, __LINE__,\
                 #EX)) && ((EX && fprintf(stdout, "\t\x1b[32mPASSED\x1b[0m\n"))\
                 || (fprintf(stdout, "\t\x1b[31mFAILED\x1b[0m\n")) ))

/**
 * Sanity test on the bloom filter.
 */
void testBloomFilter() {
    BloomFilter bf(5,10000000);
    bf.insert("mango");
    TEST(bf.contains("mango") == true);
}

/**
 * Sanity test on the count min sketch.
 */
void testCountMinSketch() {
    CountMinSketch cms(5,10000000);
    cms.increment("apple");
    TEST(cms.estimate("apple") >= 1);
}

/**
 * Test the Set implementations
 */
int main() {
    testBloomFilter();
    testCountMinSketch();
}
