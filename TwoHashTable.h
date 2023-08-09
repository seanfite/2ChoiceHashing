// Sean Fite
// Data Structure Assignment 6
// Header file for main hashtable function of program

#include "position.h"
#include "UPCEntry.h"
#include "LinkedList.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class TwoHashTable
{
public:
    TwoHashTable(string filename, int tableSize);
    Position search(UPCEntry &item);                        // if not found, return the default position with both indices set as -1
    float getStdDev();                                      // return std
    bool insert(UPCEntry &item);                            // returns true if successful, false otherwise.
    void print();                                           // output 
    int size;                                               // size tracker
    int *lengths;                                           // lengths pointer for size
    int TABLE_SIZE;                                         // initialize table size
    LinkedList<UPCEntry> *arr;                              // list initialization

private:
    float stddev(int *binLengths, int tableSize)            // std logic
    {
        float sum = 0;
        for (int i = 0; i < tableSize; i++)
            sum += binLengths[i];

        float avarage = sum / tableSize;

        float dev_sum = 0;
        for (int i = 0; i < tableSize; i++)
        {
            dev_sum = dev_sum + (binLengths[i] - avarage) * (binLengths[i] - avarage);
        }

        float variance = dev_sum / tableSize;
        return sqrt(variance);
    }
};
