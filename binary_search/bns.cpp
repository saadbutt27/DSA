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

int search(vector<int>& nums, int target) {
    // TC = O(logn)
    // SC = O(1)

    // For a rotated sorted array, either our left half will be sorted, or the right half but not both.
    // Hence we can use binary search on the sorted part of the array.
    // For left half, we can check if A[st] <= target <= A[mid-1], is true, we can search left, else right.
    // For right half, we can check if A[mid+1] <= target <= A[end], is true, we can search right, else left.
    // For a rotated sorted array, howcan we check if the left half is sorted or the right half?
    // We can check if A[st] < A[mid], the left half is sorted, else right half is sorted.

    // Modified form of Binary search

    int start = 0, end = nums.size()-1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if(nums[mid] == target) {
            return mid;
        }

        if (nums[start] <= nums[mid]) {
            // Left half is sorted
            if (nums[start] <= target && target <= nums[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } else {
            // Right half is sorted
            if (nums[mid] <= target && target <= nums[end]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }

    return -1;
}

int peakIndexInMountainArray(vector<int>& arr) {
    // TC = O(logn)
    int start = 1, end = arr.size()-2;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]) {
            return mid;
        } else if (arr[mid-1] < arr[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return -1;
}

int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return nums[0];

    int start = 0, end = n-1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        // Corner cases
        if(mid == 0 && nums[0] != nums[1]) return nums[mid];
        if(mid == n-1 && nums[n-1] != nums[n-2]) return nums[mid];

        if (nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];

        if (mid % 2 == 0) {
            if (nums[mid] == nums[mid-1]) {
                // Left half has duplicates and a unique element
                end = mid - 1;
            } else {
                // Right half has duplicates and a unique element
                start = mid + 1;
            }
        } else {
            if (nums[mid] == nums[mid-1]) {
                // Left half has duplicates and a unique element
                start = mid + 1;
            } else {
                // Right half has duplicates and a unique element
                end = mid - 1;
            }
        }
    }

    return -1; 
}

int main() {

    // vector<int> arr = {15, 24, 84, 100, 123};
    // cout << binarySearch(arr, 2) << endl;
    // cout << recursiveBinarySearch(arr, 0, arr.size()-1, 100) << endl;
    // cout << recursiveBinarySearch(arr, 0, arr.size()-1, 84) << endl;
    // cout << binarySearch(arr, 15) << endl;

    // vector<int> nums = {3, 4, 5, 6, 7, 0, 1, 2};
    // cout << search(nums, 0) << endl;

    // vector<int> nums = {0, 3, 8, 9, 5, 2};
    // cout << peakIndexInMountainArray(nums) << endl;

    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << singleNonDuplicate(nums) << endl;

    return 0;
}