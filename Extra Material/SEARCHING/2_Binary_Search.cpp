#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

int recursiveBinarySearch(int *arr, int left, int right, int value)
{
    if (left <= right)
    {
        int mid = (left + right) / 2;

        if (value == arr[mid])
        {
            return mid;
        }
        else if (value > arr[mid])
        {
            return recursiveBinarySearch(arr, mid + 1, right, value);
        }
        else
        {
            return recursiveBinarySearch(arr, left, mid - 1, value);
        }
    }
    return -1;
}

//  Iterative Solution
int iterativeBinarySearch(int *arr, int left, int right, int value)
{

    while (left <= right)
    {

        int mid = left + (left + right) / 2;

        if (value == arr[mid])
        {
            return mid;
        }
        else if (value > arr[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

bool isSorted(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            return false;
        }
    }

    return true;
}

int main()
{

    int arr[] = {11, 21, 40, 50};
    int size = sizeof(arr) / sizeof(int);

    int left = 0;
    int right = size;

    if (isSorted(arr, size))
    {
        int pos = recursiveBinarySearch(arr, left, right, 11);
        if (pos != -1)
        {
            cout << "Element found at index " << pos << endl;
        }
        else
        {
            cout << "Element not found" << endl;
        }
    }

    else
    {
        cout << "Array is Not sorted" << endl;
    }

    return 0;
}