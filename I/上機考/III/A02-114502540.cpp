#include <iostream>
#include <algorithm>

using namespace std;

int* resizeArray(int* arr, int oldSize, int newSize, int startingIndex, int endingIndex);

void printArray(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i];
        if (i < size - 1) {
            cout << " ";
        }
    }
}

int main() {
    int oldSize, newSize, startingIndex, endingIndex;

    if (!(cin >> oldSize)) return 0;

    int* originalArray = nullptr;
    if (oldSize > 0) {
        originalArray = new int[oldSize];
        for (int i = 0; i < oldSize; ++i) {
            cin >> originalArray[i];
        }
    }

    cin >> newSize;
    cin >> startingIndex >> endingIndex;
    
    int* newArray = resizeArray(originalArray, oldSize, newSize, startingIndex, endingIndex);

    printArray(newArray, newSize);

    delete[] newArray;

    return 0;
}



int* resizeArray(int* arr, int oldSize, int newSize, int startingIndex, int endingIndex)
{
    //todo
    int* outputArray = new int[newSize]();
    int i = 0;
    for (int j = startingIndex; j <= endingIndex; ++i, ++j) outputArray[i] = arr[j];
    if(newSize > endingIndex - startingIndex+1) for (; i < newSize; ++i) outputArray[i] = 0;
    delete[] arr;

    return outputArray;
}