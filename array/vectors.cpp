#include <iostream>
using namespace std;
#include "vector"
#include "algorithm"

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

vector<int> pairSum(vector<int> nums, int target) {
    vector<int> ans;

    // BRUTE FORCE APPROACH - O(n^2)
    // for (int i=0; i<nums.size(); i++) {
    //     for (int j=i+1; j<nums.size(); j++) {
    //         if (nums[i] + nums[j] == target) {
    //             ans.push_back(i);
    //             ans.push_back(j);
    //             return ans;
    //         }
    //     }
    // }

    // OPTIMIZED APPROACH - O(n)
    // Since the array in parameter is sorted, so we can think of an optimized approach.
    // If we sum starting elements, the sum will be lesser, and if we sum ending elements, the summ will be bigger.
    // We can use two-pointer approach, one at start and one at end.
    // We will sum start and end element iteratively
    // 1. If the sum is > target, we have to reduce it, and we can do it by moving to the next lesser element which is
    // just before the ending element.
    // 2. If the sum is < target, we have to increase it, and we can do it by moving to the next bigger element which is
    // just after the starting element.
    // 3. If the sum == target, then we have found, we can return the indices.

    int start = 0, end = nums.size() - 1;
    while (start < end) {
        if (nums[start] + nums[end] > target) {
            end--;
        } else if (nums[start] + nums[end] < target) {
            start++;
        } else {
            ans.push_back(start);
            ans.push_back(end);
            return ans;
        }
    }

    return ans;
}

int majorityElement(vector<int> nums) {
    // Majority elements exists floor n/2 times in the array.
    int n = nums.size();
    // BRUTE FORCE APPROACH - O(n^2)
    // for (int val: nums) {
    //     int freq = 0;
    //     for (int el: nums) {
    //         if (val == el) {
    //             freq++;
    //         }
    //     }
    //     if (freq > n/2) {
    //         return val;
    //     }
    // }

    // SLIGHTLY OPTIMIZED APPROACH - O(nlgn + n) = O(nlgn)
    // sort(nums.begin(), nums.end()); // O(nlogn)
    // int freq = 1, ans = nums[0]; 
    // for (int i=1; i<n; i++) {
    //     if (nums[i] == nums[i-1]) {
    //         freq++;
    //     } else {
    //         freq = 1;
    //         ans = nums[i];
    //     }
    //     if (freq > n/2) {
    //         return ans;
    //     }
    // }

    // MOORE'S VOTING ALGORITHM - O(n)
    // Intuition: If there's a majority element whose frequency is > n/2, then if we start tracking frequency for all 
    // elements from the start, then the majoity element's frquency will be greater always.
    // here the frequency is equivalent to power, the frequency of majorith element will be that much that if we 
    // decrease it, at the end, the power will be grater for the majority element.
    int freq = 0, ans = nums[0]; 
    for (int i=0; i<n; i++) {
        if (freq == 0) {
            ans = nums[i];
        }

        if (ans == nums[i]) {
            freq++;
        } else {
            freq--;
        }
    }

    int count = 0;
    for (int val: nums) {
        if (val == ans) {
            count++;
        }
    }

    if (count > n/2) return ans;
    else return -1;
}

int maxProfit(vector<int>& prices) {
    // O(n)
    int mp = 0, bestBuy = prices[0];

    for (int i=1; i<prices.size(); i++) {
        if (prices[i] > bestBuy) {
            mp = max(mp, prices[i] - bestBuy);
        }
        bestBuy = min(bestBuy, prices[i]);
    } 

    return mp;
}

int maxArea(vector<int>& height) {
    // 11. Container with most water
    int maxWater = 0;
    // BRUTE FORCE APPROACH - O(n^2)
    // for (int i=0; i<height.size(); i++) {
    //     for (int j=i+1; j<height.size(); j++) {
    //         int w = j-i;
    //         int ht = min(height[i], height[j]);
    //         int currentWater = w * ht;
    //         maxWater = max(maxWater, currentWater);
    //     }
    // }

    // TWO POINTER APPROACH - O(n)
    int left = 0, right = height.size()-1;
    while (left < right) {
            int w = right-left;
            int ht = min(height[left], height[right]);
            int currentWater = w * ht;
            maxWater = max(maxWater, currentWater);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
    }

    return maxWater;
}

int main() {
    // vector<int> nums = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    // cout << singleNumber(nums) << endl;
    // cout << linearSearch(nums, 2) << endl;

    // for (int x: nums){
    //     cout << x << " ";
    // }
    // }
    // cout << endl;

    // reverseVector(nums);

    // for (int x: nums){
    //     cout << x << " ";
    // }
    // cout << endl;

    // cout << maxSubarraySum(nums) << endl;
    // vector<int> ans = pairSum(nums, 26);
    // cout << ans[0] << ", " << ans[1] <<  endl;

    // cout << majorityElement(nums) << endl;

    // cout << maxProfit(nums) << endl;

    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(height) << endl;

    return 0;
}