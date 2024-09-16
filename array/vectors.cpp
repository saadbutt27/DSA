#include <iostream>
using namespace std;
#include "vector"

int singleNumber(vector<int>& nums) {
    // Leetcode problem # 136. Single Number
    int ans = 0;
    for (int x: nums){
        ans ^= x;
    }
    return ans;
}

int linearSearch(vector<int>& nums, int target) {
    for (int i=0; i<nums.size(); i++) {
        if (nums[i] == target) {
            return i;
        }
    }
    return -1;
}

void reverseVector(vector<int>& nums) {
    int start = 0;
    int end = nums.size() - 1;

    while (start < end) {
        nums[start] = nums[start] + nums[end];
        nums[end] = nums[start] - nums[end];
        nums[start] = nums[start] - nums[end];

        start++;
        end--;
    }
}

// BRUTE FORCE APPROACH - O(n^3)
int maxSubarraySum1(vector<int> nums) {
    int maxSum = INT_MIN;
    for (int start = 0; start < nums.size(); start++) {
        for (int end = start; end < nums.size(); end++) {
            int currSum = 0;
            for (int i = start; i <= end; i++) {
                currSum += nums[i];
            }
            maxSum = max(currSum, maxSum);
        }
    }
    return maxSum;
}

// OPTIMIZATION IN BRUTE FORCE APPROACH - O(n^2)
int maxSubarraySum2(vector<int> nums) {
    int maxSum = INT_MIN;
    for (int start = 0; start < nums.size(); start++) {
        int currSum = 0;
        for (int end = start; end < nums.size(); end++) {
            currSum += nums[end];
            maxSum = max(currSum, maxSum);
        }
    }
    return maxSum;
}

// OPTIMIZED APPROACH USING KADANE'S ALGORITHM - O(n)
// KADANE's INTUITION
// 1. If the current element is greater than the sum of the current element and the previous
// +ve + +ve = +ve
// small -ve + big +ve = +ve
// small +ve + big -ve = -ve
// If we have any subarray's sum being +ve / a small -ve, then we do not want to add big -ve number.
// For any +ve number, adding -ve number will decrease it and we won't have maximum subarray sum with it.
// If our subarray's sum is 0, reset it to 0
int maxSubarraySum(vector<int> nums) {
    int currSum = 0, maxSum = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
        currSum += nums[i];
        maxSum = max(currSum, maxSum);
        // edge case, we will assign the currSum to maxSum and then reset currSum, because, if we put this condition
        // in loop's start, it will make maxSum to 0 whenever currSum becomes -ve
        if(currSum < 0)
            currSum = 0;
    }
    return maxSum;
}

int main() {
    vector<int> nums = {3, -4, 5, 4, -1, 7, -8};

    // cout << singleNumber(nums) << endl;
    // cout << linearSearch(nums, 2) << endl;

    // for (int x: nums){
    //     cout << x << " ";
    // }
    // cout << endl;

    // reverseVector(nums);

    // for (int x: nums){
    //     cout << x << " ";
    // }
    // cout << endl;

    cout << maxSubarraySum(nums) << endl;
    return 0;
}