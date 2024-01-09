#include <iostream>
using namespace std;

class List
{
    int *arr;
    int *curr;
    int capacity;
    int length;

public:
    List(int c)
    {
        capacity = c;
        arr = new int[c];
        curr = arr;
        length = 0;
    }
    ~List()
    {
        delete[] arr;
    }

    void next()
    {
        curr++;
    }

    void back()
    {
        curr--;
    }

    void start()
    {
        curr = arr;
    }

    void tail()
    {
        curr = arr + length - 1;
    }

    void insert(int val, int pos)
    {
        if (capacity == length)
        {
            cout << "FULL";
            return;
        }

        if (pos < 1 || pos > length + 1)
        {
            cout << "INVALID";
            return;
        }
        tail();

        for (int i = length; i >= pos; i--)
        {
            *(curr + 1) = *curr;
            back();
        }
        *(curr + 1) = val;
        length++;
    }

    void print()
    {
        start();
        for (int i = 1; i <= length; i++)
        {
            cout << *curr << " ";
            next();
        }
        cout << endl;
    }

    void rearrangeList()
    {
        int even = 0;
        int odd = 1;

        while (even < length && odd < length)
        {
            while (even < length && arr[even] % 2 == 0)
                even += 2;

            while (odd < length && arr[odd] % 2 != 0)
                odd += 2;

            if (even < length && odd < length)
            {

                int temp = arr[even];
                arr[even] = arr[odd];
                arr[odd] = temp;
            }
        }
    }
};

int main()
{
    List l1(9);
    l1.insert(5, 1);
    l1.insert(2, 2);
    l1.insert(9, 3);

    l1.insert(4, 4);
    l1.insert(7, 5);
    l1.insert(6, 6);
    l1.insert(1, 7);
    l1.insert(3, 8);
    l1.insert(8, 9);

    l1.rearrangeList();
    l1.print();

    return 0;
}