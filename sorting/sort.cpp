#include <iostream>
using namespace std;
#include <vector>

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

void printVector(vector<int> arr) {
    int n = arr.size();
   for (int i=0; i<n; i++) {
    cout << arr[i] << " ";
   } 
   cout << endl;
}

void sortColors(vector<int> nums) {
    //  BRUTE FORCE APPROACH - TC = O(nlogn), SC = O(1)
    // sort(nums.being(). nums.end());

    // OPTIMIZED APPROACH - BASED ON COUNTING SORT - O(n)
    // Store count of 0s, 1s, and 2s
    // Overwrite the array sequentially, 0s, 1s, and 2s
    // 2 passes over the array
    // int n= nums.size()
    // int count0s = 0, count1s = 0, count2s = 0;
    // for (int i=0; i<n; i++) { // O(n)
    //     if (nums[i] == 0) count0s++;
    //     else if (nums[i] == 1) count1s++;
    //     else count2s++;
    // }

    // // O(3n)
    // int idx = 0;
    // for (int i=0; i<count0s; i++) {
    //     nums[idx++] = 0;
    // }
    // for (int i=0; i<count1s; i++) {
    //     nums[idx++] = 1;
    // }
    // for (int i=0; i<count2s; i++) {
    //     nums[idx++] = 2;
    // }
    
    // MOST OPTIMAL APPROACH - TC = O(n) SC = O(1)
    // DUTCH NATIONAL FLAG ALGORITHM - Single pass
    // Objective is to arrange the numbers / interchange / swap, so that the array is sorted
    // We use 3 pointers: low, mid, high
    // We'll store 
    // 0s -> 0 to low-1
    // 1s -> low to mid-1
    // 2s -> high+1 to n-1 
    // Unsorted elements -> mid to high
    // eventually, we'll increase mid, and decrease hight, and a point will come when mid and high will be equal, and unsorted will be no more 
    
    int n = nums.size();
    int low = 0, mid = 0, high = n-1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            // arranging 0s and 1s in a continuous manner
            swap(nums[low++], nums[mid++]);
        } else if (nums[mid] == 1) {
            // arranging 1s in a continuous manner
            mid++;
        } else {
            // arranging 2s in a continuous manner
            swap(nums[mid], nums[high--]);
        }
    }

    printVector(nums);
}



int main() {
    vector<int> nums = {2,0,2,1,1,0};
    cout << "Unsorted array: ";
    printVector(nums);

    sortColors(nums);
    cout << "Sorted array: ";
    printVector(nums);


    // int arr[] = {5, 4, 12, 8, 4, 8, 2, 7, 2, 4, 5, 10};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // cout << "Unsorted array: ";
    // printArray(arr, n);
    // printVector(arr, n);
    // bubbleSort(arr, n);
    // selectionSort(arr, n);
    // insertionSort(arr, n);
    // sortArray(arr, n);
    // cout << "Sorted array: ";
    // printArray(arr, n);
    // printVector(arr, n);

    return 0;
}