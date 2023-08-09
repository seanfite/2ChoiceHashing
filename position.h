// Sean Fite
// Data Structure Assignment 6
// This class initializes positoins of the table and linked list 

struct Position
{
    int indexInTable; //position in the table.
    int indexInBin;   // position in the linked list.
    Position(int indexInTable, int indexInBin): indexInTable(indexInTable), indexInBin(indexInBin)
    {
        // this->indexInTable = indexInTable;
    }
    Position(): indexInTable(-1), indexInBin(-1)
    {
    
    }
};
