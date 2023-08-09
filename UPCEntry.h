// Sean Fite
// Data Structure Assignmnet 6
// This header file sets up hash1 and hash2

#ifndef UPC_ENTRY
#define UPC_ENTRY
#include <string>
#include <iostream>
using namespace std;

struct UPCEntry
{
    long long upc;                  // upc data pulled from file
    string desc;                    // string data pulled from file
    UPCEntry();                     // defualt constructor 
    UPCEntry(string line);          // constructor passing in line

    int hash1(int tableSize)
    {
        return upc % tableSize;
    }

    int hash2(int tableSize)
    {
        return abs(desc[0] + 27 * desc[1] + 729 * desc[2]) % tableSize;
    }

    friend ostream& operator << (ostream& out, const UPCEntry& UPC)         // ostream function for linked list
    {
        out << UPC.desc << "[" << UPC.upc << "]";
        return out;
    }

    bool operator==(const UPCEntry& upc_entry)                              // comparison function for upc data
    {
        if(upc_entry.upc == upc)
        {
            return upc_entry.desc == desc;
        } 
        return false;
    }
};
#endif