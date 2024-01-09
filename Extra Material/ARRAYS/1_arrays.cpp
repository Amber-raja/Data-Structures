#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

class Array
{
private:
    int *arr;
    int *curr;
    int capacity;
    int length;

public:
    Array(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        curr = arr;
        length = 0;
    }

    int getLength()
    {
        return length;
    }
    void insert(int pos, int value)
    {
        if (length == capacity)
        {
            cout << "Array is Full" << endl;
            return;
        }

        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid Postion" << endl;
            return;
        }

        curr = arr + length - 1;

        for (int i = length; i >= pos; i--)
        {

            *(curr + 1) = *curr;
            curr--;
        }
        *(curr + 1) = value;
        length++;
    }

    void remove(int pos)
    {
        if (length == 0)
        {
            cout << "Array is Empty" << endl;
            return;
        }
        if (pos < 1 || pos > length)
        {
            cout << "Invalid Postion" << endl;
            return;
        }
        curr = arr;

        for (int i = 0; i < pos; i++)
        {
            curr++;
        }

        // curr = arr + pos - 1;

        for (int i = pos; i < length; i++)
        {
            *curr = *(curr + i);
            curr++;
        }
        length--;
    }

    void print()
    {
        for (int i = 0; i < length; i++)
        {
            cout << *(arr + i) << " ";
        }
        cout << endl;
    }

    ~Array()
    {
        delete[] arr;
    }

    
};

int main()
{
    Array l1(5);
    l1.insert(1, 5);
    l1.insert(2, 10);
    l1.insert(3, 15);
    l1.insert(4, 20);
    l1.insert(1, 50);

    l1.print();
    cout << l1.getLength() << endl;
    l1.remove(1);
    l1.print();
    cout << l1.getLength() << endl;

    return 0;
}