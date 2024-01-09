#include <iostream>
using namespace std;

void display(int H[], int size)
{
    cout << "\nHash Table: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << H[i] << " ";
    }
    cout << "\n-------------------------------------\n";
}
int count(int H[], int size)
{
    int length = 0;
    for (int i = 0; i < size; i++)
    {
        if (H[i] != -1)
        {
            length++;
        }
    }
    return length;
}
void initialize(int *&H, int size)
{
    for (int i = 0; i < size; i++)
    {
        H[i] = -1;
    }
}
int hashing(int key, int size)
{
    return key % size;
}
int probing(int H[], int key, int size)
{
    int index = hashing(key, size);
    int i = 0;
    while (H[(index + i) % size] != -1)
        i++;
    return (index + i) % size;
}

void rehash(int *&H, int &size)
{
    int oldSize = size;
    size *= 2;
    int *new_H = new int[size];
    initialize(new_H, size);

    for (int i = 0; i < oldSize; i++)
    {
        if (H[i] != -1)
        {
            int new_Index = hashing(H[i], size);
            if (new_H[new_Index] != -1)
            {
                new_Index = probing(new_H, H[i], size);
            }
            new_H[new_Index] = H[i];
        }
    }

    delete[] H;
    H = new_H;
}

void insert(int *&H, int &size, int key)
{
    if ((((double)count(H, size) / size) > 0.7) || (((double)count(H, size) / size) == 0.7))
    {
        rehash(H, size);
    }

    int index = hashing(key, size);
    if (H[index] != -1)
    {
        index = probing(H, key, size);
    }
    H[index] = key;
}

int main()
{
    // Hard Coded main function

    int size = 10; // initializing with size 10
    int *HT = new int[size];
    initialize(HT, size); // initializing the hash table with -1

    insert(HT, size, 12);
    display(HT, size);
    insert(HT, size, 25);
    display(HT, size);
    insert(HT, size, 35);
    display(HT, size);
    insert(HT, size, 26);
    display(HT, size);
    insert(HT, size, 3);
    display(HT, size);
    insert(HT, size, 4);
    display(HT, size);
    insert(HT, size, 6);
    display(HT, size);
    insert(HT, size, 9);
    display(HT, size);
    insert(HT, size, 2);
    display(HT, size);
    delete[] HT;

    return 0;
}