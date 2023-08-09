// Sean Fite
// Data Structure Assigment 6
// This cpp file constructs an array from a file and inserts into a hashtable

#include "TwoHashTable.h"
using namespace::std;

TwoHashTable::TwoHashTable(string filename, int tableSize)          // default constructor reading in file
{
    TABLE_SIZE = tableSize;
	arr = new LinkedList<UPCEntry>[tableSize];
    fstream newfile;
	newfile.open(filename, ios::in);
	if (!newfile.is_open())
	{
		cout << "Bad open on file " << filename << endl;
		exit(1);
	}
	string tp;
	getline(newfile, tp);                                           // read first line
    while (getline(newfile, tp))									
	{
		UPCEntry entry (tp);
        insert(entry);                                              // insert into array
	}
	newfile.close();

}

bool TwoHashTable::insert(UPCEntry &item)                       // insert function using two choice hashing
{
    int h1 = item.hash1(TABLE_SIZE);
    int h2 = item.hash2(TABLE_SIZE);                   
    int h1_size = arr[h1].size();
    int h2_size = arr[h2].size();
    if(h1_size <= h2_size)
    {
        arr[h1].insert(item);
    }
    else
    {
        arr[h2].insert(item);
    }
    return true;
}
    
Position TwoHashTable::search(UPCEntry &item)                // search function using linkedlist position and position function
{
    int h1 = item.hash1(TABLE_SIZE);
    int location = arr[h1].position(item); 
    if(location >= 0)
    {
        return Position(h1, location);
    }
    int h2 = item.hash2(TABLE_SIZE);
    location = arr[h2].position(item); 
    if(location >= 0)
    {
        return Position(h2, location);
    }
    return Position();
    
}

float TwoHashTable::getStdDev()                             // returning std of the file array
{
    int * lengths = new int[TABLE_SIZE];                    
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        lengths[i] = arr[i].size();
    }
    return stddev(lengths, TABLE_SIZE );
}

void TwoHashTable::print()                                  // display function for testing
{
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        if(arr[i].size() != 0)
        {
            cout << setw(10) << i;
            arr[i].print();
        }
        cout << endl;
    }
}
