#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;

    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    } 
}

void sumAndProduct(int arr[], int size) {
    int sum = 0, product = 1;
    for (int i=0; i<size; i++) {
        sum += arr[i];
        product *= arr[i];
    }
    cout << "Sum = " << sum << endl;
    cout << "Product = " << product << endl;

}

void swapMinMax(int arr[], int size) {
    int min = INT_MAX;
    int max = INT_MIN;

    int maxIndex = -1;
    int minIndex = -1;

    for (int i=0; i<size; i++) {
        if (arr[i] < min) {
            min = arr[i];
            minIndex = i;
        }
        if(arr[i] > max) {
            max = arr[i];
            maxIndex = i;
        }
    }

    arr[minIndex] = arr[minIndex] + arr[maxIndex];
    arr[maxIndex] = arr[minIndex] - arr[maxIndex];
    arr[minIndex] = arr[minIndex] - arr[maxIndex];
}

void uniqueInArray(int arr[], int size) {
    for (int i=0; i < size; i++) {
        bool isUnique = true;
        for (int j=0; j < size; j++) {
            if (i != j && arr[i] == arr[j]) {
                isUnique = false;
                break;
            }
        }

        if(isUnique) {
            cout << arr[i] << " ";
        }
    }
    cout << "are unique elements in the array." << endl;
}

void intersectionOfArrays(int arr1[], int size1, int arr2[], int size2) {
    // for (int i=0; i < size1; i++) {
    //     for (int j=0; j < size2; j++) {
    //         if (arr1[i] == arr2[j]) {
    //             cout << arr1[i] << " ";
    //         }
    //     }
    // }

     bool printed[size1] = {false};  // To track if a value in arr1 has been printed

    // Iterate through the first array
    for (int i = 0; i < size1; i++) {
        bool found = false;
        
        // Check if the element in arr1 is present in arr2
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                found = true;
                break;  // Exit the inner loop once a match is found
            }
        }

        // Check if the element was found and hasn't been printed before
        if (found && !printed[i]) {
            cout << arr1[i] << " ";
            printed[i] = true;  // Mark this element as printed
        }
    }
    cout << " are intersetion of two arrays." << endl;
}

int main() {
    int arr[] = {1,2,3,1,2,3,4};
    int size = sizeof(arr) / sizeof(int);
    // int target = 10;

    // cout << "Element " << target << " found at index " << linearSearch(arr, size, target) << endl;

    // reverseArray(arr, size);
    // cout << "Revered array: ";
    // for (int i=0; i<size; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // sumAndProduct(arr, size);

    // swapMinMax(arr, size);
    // cout << "Swapped array: ";
    // for (int i=0; i<size; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    
    // uniqueInArray(arr, size);

    int arr1[] = {1,2,3,4,5};
    int size1 = sizeof(arr1) / sizeof(int);
    int arr2[] = {6,7,3,1,1};
    int size2 = sizeof(arr2) / sizeof(int);

    for (int i=0; i<size1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    for (int i=0; i<size2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    intersectionOfArrays(arr1, size1, arr2, size2);
    return 0;
}