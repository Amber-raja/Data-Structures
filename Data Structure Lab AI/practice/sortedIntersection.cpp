#include <iostream>
// #include <algorithm> 
using namespace std;// for min function

int* sortedIntersect(int* arr1, int* arr2, int size1, int size2, int& sizeIntersection) {
    int* intersection = new int[min(size1, size2)];
    sizeIntersection = 0;
    int i = size1 - 1, j = size2 - 1;
    while (i >= 0 && j >= 0) {
        if (arr1[i] == arr2[j]) {
            intersection[sizeIntersection++] = arr1[i];
            --i; --j;
        } else if (arr1[i] > arr2[j]) {
            --i;
        } else {
            --j;
        }
    }
    // reverse(intersection, intersection + sizeIntersection); // Reverse the array to get it in ascending order
    return intersection;
}

int main() {
    int arr1[] = {2, 3,4, 6, 9};
    int arr2[] = {0, 1, 2,3};
    int size1 = 5;
    int size2 = 4;

    int sizeIntersection = 0;
    int* intersection = sortedIntersect(arr1, arr2, size1, size2, sizeIntersection);

    cout << "Intersection: ";
    for (int i = 0; i < sizeIntersection; ++i) {
        cout << intersection[i] << " ";
    }
    cout << endl;

    // Deallocate the dynamically allocated memory
    delete[] intersection;

    return 0;
}
