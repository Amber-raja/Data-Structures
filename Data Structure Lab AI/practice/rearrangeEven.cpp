#include <iostream>
using namespace std;

// Swap function to exchange the values of two variables
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to rearrange even numbers to the front of the array
void rearrangeEvenFirst(int* arr, int size) {
    int i = -1;
    for (int j = 0; j < size; ++j) {
        if (arr[j] % 2 == 0) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
}

int main() {
    int arr[] = {3, 6, 8, 5, 2, 7, 4};
    int size = 7;

    cout << "Original Array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    rearrangeEvenFirst(arr, size);

    cout << "Rearranged Array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
