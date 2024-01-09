#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int size, int arr[])
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

void bubbleSort(int size, int arr[])
{
    int comparisons = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            comparisons++;

            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
        cout << "On Pass " << i + 1 << ": ";
        display(size, arr);
    }
    cout << endl;
    display(size, arr);
    cout << "Bubble Sort Comparisons: " << comparisons << endl;
}

void selectionSort(int size, int arr[])
{
    int comparisons = 0;
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            comparisons++;
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
        cout << "On Pass " << i + 1 << ": ";
        display(size, arr);
    }
    cout << "Selection Sort Comparisons: " << comparisons << endl;
}

void insertionSort(int size, int arr[])
{
    int comparisons = 0;
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            comparisons++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        cout << "On Pass " << i << ": ";
        display(size, arr);
    }
    cout << "Insertion Sort Comparisons: " << comparisons << endl;
}

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int LEFT[n1], RIGHT[n2];
    for (int i = 0; i < n1; i++)
    {
        LEFT[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        RIGHT[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (LEFT[i] <= RIGHT[j])
        {
            arr[k] = LEFT[i];
            i++;
        }
        else
        {
            arr[k] = RIGHT[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = LEFT[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = RIGHT[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int binarySearchRecursive(int arr[], int left, int right, int key, int &comparisons)
{
    if (right >= left)
    {
        int m = left + (right - left) / 2;
        comparisons++;
        if (arr[m] == key)
        {
            return m;
        }
        if (arr[m] > key)
        {
            return binarySearchRecursive(arr, left, m - 1, key, comparisons);
        }
        return binarySearchRecursive(arr, m + 1, right, key, comparisons);
    }
    return -1;
}

int binarySearchIterative(int arr[], int size, int key, int &comparisons)
{

    int right = size - 1;
    int left = 0;
    while (right >= left)
    {
        int m = left + (right - left) / 2;
        comparisons++;
        if (arr[m] == key)
        {
            return m;
        }
        if (arr[m] < key)
        {
            left = m + 1;
        }
        else
        {
            right = m - 1;
        }
    }
    return -1;
}
bool isSortedManually(int arr[], int size)
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

    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    while (1)
    {

        // Display the menu
        cout << "\nMenu:\n";
        cout << "1. Bubble Sort\n";
        cout << "2. Selection Sort\n";
        cout << "3. Insertion Sort\n";
        cout << "4. Merge Sort\n";
        cout << "5. Binary Search (Recursive)\n";
        cout << "6. Binary Search (Iterative)\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            bubbleSort(size, arr);
            break;
        case 2:
            selectionSort(size, arr);
            break;
        case 3:
            insertionSort(size, arr);
            display(size, arr);
            break;
        case 4:
            mergeSort(arr, 0, size - 1);
            display(size, arr);
            break;
        case 5:
        {
            int key;
            cout << "Enter the value to find: ";
            cin >> key;
            int comparisons = 0;
            if (isSortedManually(arr, size))
            {

                int result = binarySearchRecursive(arr, 0, size - 1, key, comparisons);
                if (result != -1)
                {
                    cout << "Element found at index " << result << endl;
                }
                else
                {
                    cout << "Element not found\n";
                }
                cout << "Comparisons: " << comparisons << endl;
                break;
            }
            else
            {
                cout << "Array is not sorted\n";
                continue;
            }
        }
        case 6:
        {
            int key;
            cout << "Enter the value to find: ";
            cin >> key;
            int comparisons = 0;
            if (isSortedManually(arr, size))
            {
                int result = binarySearchIterative(arr, size, key, comparisons);
                if (result != -1)
                {
                    cout << "Element found at index " << result << endl;
                }
                else
                {
                    cout << "Element not found\n";
                }
                cout << "Comparisons: " << comparisons << endl;
                break;
            }
            else
            {
                cout << "Array is not sorted\n";
                continue;
            }
        }
        default:
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
