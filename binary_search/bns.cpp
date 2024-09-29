#include <iostream>
using namespace std;
#include <vector>

int binarySearch(vector<int>& arr, int target) {
    // TC = O(logn)
    // SC = O(1)
    int start = 0, end = arr.size()-1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (target > arr[mid]) {
            start = mid + 1;
        } else if (target < arr[mid]) {
            end = mid - 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int recursiveBinarySearch(vector<int>& arr, int start, int end, int target) {
    // TC = O(logn)
    // SC = O(logn)
    if(start <= end) {
        int mid = start + (end - start) / 2;

        if (target > arr[mid]) {
            return recursiveBinarySearch(arr, mid + 1, end, target);
        } else if (target < arr[mid]) {
            return recursiveBinarySearch(arr, start, mid - 1, target);
        } else {
            return mid;
        }
    }

    return -1;
}

int main() {

    vector<int> arr = {15, 24, 84, 100, 123};
    cout << binarySearch(arr, 2) << endl;
    cout << recursiveBinarySearch(arr, 0, arr.size()-1, 100) << endl;
    cout << recursiveBinarySearch(arr, 0, arr.size()-1, 84) << endl;
    cout << binarySearch(arr, 15) << endl;


    
    return 0;
}