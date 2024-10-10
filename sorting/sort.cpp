#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    // TC: O(n^2)
    for (int i=0; i<n-1; i++) {
        bool isSwap = false;
        for (int j=0; j<n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                isSwap = true;
            }
        }

        if (!isSwap) return;
    }
}

void selectionSort(int arr[], int n) {
    // TC: O(n^2)
    for (int i=0; i<n-1; i++) {
        int minIdx = i;
        for (int j=i+1; j<n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        swap(arr[i], arr[minIdx]);
    }
}

void insertionSort(int arr[], int n) {
    // TC = O(n^2)
    for(int i=1; i<n; i++) {
        int curr = arr[i];
        int prev = i-1;

        while (prev >= 0 && arr[prev] > curr) {
            arr[prev+1] = arr[prev--];
        }

        arr[prev+1] = curr;
    }
}

void printArray(int arr[], int n) {
   for (int i=0; i<n; i++) {
    cout << arr[i] << " ";
   } 
   cout << endl;
}

int main() {
    int arr[] = {5, 4, 12, 8, 4, 8, 2, 7, 2, 4, 5, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Unsorted array: ";
    printArray(arr, n);
    // bubbleSort(arr, n);
    // selectionSort(arr, n);
    insertionSort(arr, n);
    cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}