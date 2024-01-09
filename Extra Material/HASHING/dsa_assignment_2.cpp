#include <iostream>
using namespace std;

class HashTable
{
private:
    int *table;
    int capacity;
    void initialize()
    {
        for (int i = 0; i < capacity; i++)
        {
            table[i] = -1;
        }
    }

    int hash(int key)
    {
        return key % capacity;
    }
    int probing(int key)
    {
        int index = hash(key);
        int i = 0;
        while (table[(index + i) % capacity] != -1)
        {
            i++;
        }
        return (index + i) % capacity;
    }

    void rehash()
    {
        int oldCapacity = capacity;
        capacity *= 2;
        int *oldTable = table;
        table = new int[capacity];
        initialize();
        for (int i = 0; i < oldCapacity; i++)
        {
            if (oldTable[i] != -1)
            {
                int newIndex = probing(oldTable[i]);
                table[newIndex] = oldTable[i];
            }
        }

        delete[] oldTable;
    }

public:
    HashTable(int size) : capacity(size)
    {
        table = new int[capacity];
        initialize();
    }

    ~HashTable()
    {
        delete[] table;
    }

    void display()
    {
        cout << endl
             << "Hash Table" << endl;
        for (int i = 0; i < capacity; i++)
        {
            cout << table[i] << " ";
        }
        cout << endl;
    }

    int count()
    {
        int length = 0;
        for (int i = 0; i < capacity; i++)
        {
            if (table[i] != -1)
            {
                length++;
            }
        }
        return length;
    }

    void insert(int key)
    {
        double loadFactor = (double)count() / capacity;
        if (loadFactor >= 0.7)
        {
            rehash();
        }

        int index = hash(key);
        if (table[index] != -1)
        {
            index = probing(key);
        }
        table[index] = key;
    }
};

int main()
{
    HashTable ht(7);
    ht.insert(12);
    ht.display();
    ht.insert(25);
    ht.display();
    ht.insert(35);
    ht.display();
    ht.insert(26);
    ht.display();
    ht.insert(3);
    ht.display();
    ht.insert(4);
    ht.display();
    ht.insert(6);
    ht.display();
    ht.insert(9);
    ht.display();
    ht.insert(2);
    ht.display();
    ht.insert(14);
    ht.display();
    ht.insert(26);
    ht.display();
    ht.insert(11);
    ht.display();
    ht.insert(16);
    ht.display();

    return 0;
}
