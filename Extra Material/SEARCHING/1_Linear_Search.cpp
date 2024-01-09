#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

int linearSearch(int *arr, int size, int value)
{
    int camparison = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {11, 22, 23, 15, 15, 19};
    int size = sizeof(arr) / sizeof(int);
    int pos = linearSearch(arr, size, 191);
    cout << pos << endl;

    return 0;
}