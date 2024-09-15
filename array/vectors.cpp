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

int main() {
    vector<int> nums = {4, 1, 2, 1, 2};

    cout << singleNumber(nums) << endl;
    cout << linearSearch(nums, 2) << endl;

    for (int x: nums){
        cout << x << " ";
    }
    cout << endl;

    reverseVector(nums);

    for (int x: nums){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}