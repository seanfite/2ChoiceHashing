// Sean Fite
// Data Structure Assignment 6
// This implementation file processes the file input into the correct format

#include "UPCEntry.h"
#include <iostream>

using namespace::std;

UPCEntry:: UPCEntry()                                                      // default constructor 
{
}
UPCEntry:: UPCEntry(string line)                                          // constructor passing in string from file
{
    int sbp = line.find_first_not_of("0123456789"); 
    string upc_num = line.substr(0, sbp);       
    this->upc = stoll(upc_num, nullptr, 10);    
    this->desc = line.substr(sbp + 1);
    if(this->desc[0] == '"')
    {
        this->desc = this->desc.substr(1);
    }
    if(this->desc[this->desc.size() - 1] == '"')                         // to handle quotations
    {
        this->desc = this->desc.substr(0, this->desc.size() - 1);
    }
    this->desc.erase(remove(this->desc.begin(), this->desc.end(), '\\'), this->desc.end());  // to handle backslash
    size_t start_pos = 0;
    while((start_pos = this->desc.find("\"\"", start_pos)) != std::string::npos) {
        this->desc.replace(start_pos, 2, "\"");
        start_pos += 1; // Handles case where 'to' is a substring of 'from'
    }
}
