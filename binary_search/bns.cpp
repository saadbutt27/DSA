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

bool isValid (vector<int>arr, int n, int m, int maxAllowedPages) {
    int std = 1, pages = 0;
    // O(n)
    for (int i=0; i<n; i++) {

        if (arr[i] > maxAllowedPages) return false;

        if (pages + arr[i] <= maxAllowedPages) {
            pages += arr[i];
        } else {
            std++;
            pages = arr[i];
        }
    }

    return std <= m ? true : false;
}

int allocateBooks (vector<int>& pages, int m) {
    // n books, each has A[i] number of pages
    // allocate books to m number of students so that the max number of pages allocated to a student is aminimum
    // each book should be allocated to a student.
    // each student should be allocated at least one book.
    // allotment should be in a contiguous(sequential) order.

    // find min possible max pages
    // we can find min an max pages to a student
    // for pages = [2, 1, 3, 4]
    // min = 0 , max = sum[all_pages], we've to find our answer in the range of min and max
    // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 :: fo pages array
    // now we can apply binary search on this range
    // if we find mid of this ranges, it is 5
    // how do we know that 5 is  avalid or invalid allotment
    // here 5 is invalid because we are obliged to allocate pages in a contiguous manner and 2, and 3 are not contiguous in the array.
    // so now we conclude that the max allotment will be > 5, so we'll move to right
    // if we find  a valid answer which is max, but there is a possibility we can find min of max
    // hence if we find a valid answer (which fullfills all conditions), we will move to left

    // TC = O(n * logN)
    int n = pages.size();
    if (m > n) return -1;

    int sum = 0;

    for (int i=0; i<n; i++) { // O(n)
        sum += pages[i];
    }

    int start = 0, end = sum, ans = -1;

    while (start <= end) {  // O(log(range)) => O(logN)
        int mid = start + (end - start) / 2;

        if (isValid(pages, n, m, mid)) {
            // Move left, find another min
            ans = mid;
            end = mid - 1;
        } else {
            // Move right, find max
            start = mid + 1;
        }
    }

    return ans;
}


bool isPossible (vector<int>arr, int n, int m, int maxAllowedTime) {
    int painters = 1, time = 0;
    // O(n)
    for (int i=0; i<n; i++) {

        if (arr[i] > maxAllowedTime) return false;

        if (time + arr[i] <= maxAllowedTime) {
            time += arr[i];
        } else {
            painters++;
            time = arr[i];
        }
    }

    return painters <= m;
}
int minTimeToPaint(vector<int>& boards, int m) {
    // N boards of length, in an array, and M painters
    // each painter takes 1 unit of time to paint 1 unit of the board
    // find minimum time to paint all the boards, such thaht painter will only paint contiguos section of boards

    // n boards, each has A[i] number of units
    // allocate boards to m number of painters so that the max number of units allocated to a painter is a minimum

    // Find min and max time to paint the boards, so we have a range in ehich the time will be to paint all the boards
    // the max time will be when one painter will paint all the boards (sum of all board length)
    // the min time will be when n painters will paint n boards, the time taken will be the boards with max length
    // min = max(boards_length), max = sum(boards_length)

    int n = boards.size();
    if (m > n) return -1;

    int sum = 0, maxVal = INT_MIN;
    for (int i=0; i<n; i++) { // O(n)
        sum += boards[i];
        maxVal = max(maxVal, boards[i]);
    }

    int start = maxVal, end = sum, ans = -1;

    while (start <= end) { // log(sum) * log(n) => o(n * log(sum))
        int mid = start + (end - start) / 2;

        if (isPossible(boards, n, m, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1; 
        }
    }

    return ans;
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

    // vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    // cout << singleNonDuplicate(nums) << endl;

    // vector<int> pages = {15, 17, 20};
    // cout << allocateBooks(pages, 2) << endl;

    vector<int> boards = {40, 30, 10, 20};
    cout << minTimeToPaint(boards, 2) << endl;

    return 0;
}