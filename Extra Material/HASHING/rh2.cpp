#include <iostream>
using namespace std;

void displayHashTable(int, int *);
int count(int, int *);
int HashFucntion(int, int);
void filling(int, int *&);
int linearProbing(int, int *, int);
void rehashHashTable(int &, int *&);
void insert(int &, int *&, int);

int main()
{

    int size = 8;
    int *hashTable = new int[size];
    filling(size, hashTable);

    insert(size, hashTable, 16);

    insert(size, hashTable, 5);
    insert(size, hashTable, 10);
    insert(size, hashTable, 15);
    insert(size, hashTable, 20);
    displayHashTable(size, hashTable);
    insert(size, hashTable, 25);
    insert(size, hashTable, 30);
    displayHashTable(size, hashTable);

    delete[] hashTable;
    return 0;
}

int HashFucntion(int tableSize, int key)
{
    return key % tableSize;
}

void filling(int size, int *&H)
{
    for (int i = 0; i < size; i++)
    {
        H[i] = -1;
    }
}

void displayHashTable(int tableSize, int *hashTable)
{
    int index = 0;
    while (index < tableSize)
    {
        cout << *(hashTable + index) << " ";
        index++;
    }
    cout << endl;
}

int linearProbing(int tableSize, int *hashTable, int key)
{
    int index = HashFucntion(tableSize, key);
    int offset = 0;

    while (*(hashTable + (index + offset) % tableSize) != -1)
    {
        offset++;
    }
    return (index + offset) % tableSize;
}

void insert(int &tableSize, int *&hashTable, int key)
{
    float percentage = 0.7;
    if ((((double)count(tableSize, hashTable) / tableSize) > percentage) || (((double)count(tableSize, hashTable) / tableSize) == percentage))
    {
        rehashHashTable(tableSize, hashTable);
    }

    int index = HashFucntion(tableSize, key);
    if (*(hashTable + index) != -1)
    {
        index = linearProbing(tableSize, hashTable, key);
    }
    *(hashTable + index) = key;
}

int count(int tableSize, int *hashTable)
{
    int length = 0;
    for (int i = 0; i < tableSize; i++)
    {
        if (*(hashTable + i) != -1)
        {
            length++;
        }
    }
    return length;
}

void rehashHashTable(int &tableSize, int *&hashTable)
{
    int oldSize = tableSize;
    tableSize *= 2;
    int *newHash = new int[tableSize];
    filling(tableSize, newHash);

    for (int i = 0; i < oldSize; i++)
    {
        if (hashTable[i] != -1)
        {
            int newIndex = HashFucntion(tableSize, *(hashTable + i));
            if (*(newHash + newIndex) != -1)
            {

                newIndex = linearProbing(tableSize, newHash, *(hashTable + i));
            }
            *(newHash + newIndex) = *(hashTable + i);
        }
    }
    delete[] hashTable;
    hashTable = newHash;
}
