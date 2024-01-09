
#include <iostream>

using namespace std;

class HashTable {
private:
    int capacity;
    int size;
    int *keys;
    int *values;
    void rehash() {
        int new_capacity = capacity * 2;
        int* new_keys = new int[new_capacity];
        int* new_values = new int[new_capacity];

        for (int i = 0; i < new_capacity; i++) {
            new_keys[i] = -1;
            new_values[i] = -1;
        }

        for (int i = 0; i < capacity; i++) {
            if (keys[i] != -1) {
                int index = keys[i] % new_capacity;
                while (new_keys[index] != -1) {
                    index = (index + 1) % new_capacity;
                }
                new_keys[index] = keys[i];
                new_values[index] = values[i];
            }
        }

        delete[] keys;
        delete[] values;

        keys = new_keys;
        values = new_values;
        capacity = new_capacity;
    }

public:
   HashTable(int capacity) {
    this->capacity = capacity;
    this->size = 0;  

    keys = new int[capacity];
    values = new int[capacity];

    for (int i = 0; i < capacity; i++) {
        keys[i] = -1;
        values[i] = -1;
    }
}


    ~HashTable() {
         delete[] keys;
        delete[] values;
    }

    bool insert(int value) {
        if (size > capacity * 0.7) {
            rehash();
        }

        int index = value % capacity;
        int i = 0;
        while (keys[index] != -1) {
            index = (index + 1) % capacity;
            i++;
            if (i == capacity) {
                return false; 
            }
        }

        keys[index] = value;
        values[index] = value;
        size++;

        return true;
    }

    int search(int key) {
        int index = key % capacity;
        int i = 0;
        while (keys[index] != -1 && keys[index] != key) {
            index = (index + 1) % capacity;
            i++;
            if (i == capacity) {
                return -1; 
            }
        }

        if (keys[index] == key) {
            return values[index];
        } else {
            return -1; 
        }
    }
     void print() {
        cout << "HashTable Data:" << endl;
        for (int i = 0; i < capacity; i++) {
            if (keys[i] != -1) {
                cout << "Index: " << i << " Key: " << keys[i] << " Value: " << values[i] << endl;
            }
        }
     
    }

};

int main() {
    HashTable table(10);

    table.insert(10);
    table.insert(20);
    table.insert(30);
    table.insert(40);
    
   table.print();

    return 0;
}