#include <iostream>
using namespace std;
#include "vector"
#include "algorithm"
#include <unordered_map>
#include <unordered_set>
#include <set>

void printVector(vector<int> nums) {
    for (int i=0; i<nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void print2DVector(vector<vector<int>> mat) {
    for (int i=0; i<mat.size(); i++) {
        for (int j=0; j<mat[i].size(); j++) {
            cout << mat[i][j] << " "; 
        }
        cout << endl;
    }
}

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

vector<int> productExceptSelf(vector<int>& nums) {
    // 238. Product of array except itself
    int n = nums.size();
    vector<int> ans(n, 1);

    // BRUTE FORCE APPROACH - O(n^@)
    // for(int i=0; i<nums.size(); i++){
    //     for (int j=0; j<nums.size(); j++) {
    //         if (i != j) {
    //             ans[i] *= nums[j];
    //         }
    //     }
    // }

    // OPTIMAL APPROACH - TC: O(n), SC: O(n)
    // prefix: left product, siffix: right product
    // for any index i in an array, prefic is the product of left-side element of the i-th element and suffix is the 
    // right-side product of the i-th number

    // Prefix of all elements - O(n)
    // vector<int> prefix(n, 1);
    // for (int i=1; i<n; i++) {
    //     prefix[i] = prefix[i-1] * nums[i-1];
    // }
    // // Suffix of all elements - O(n)
    // vector<int> suffix(n, 1);
    // for (int i=n-2; i>=0; i--) {
    //     suffix[i] = suffix[i+1] * nums[i+1];
    // }

    // // answer claculation - O(n)
    // for (int i=0; i<n; i++) {
    //     ans[i] = prefix[i] * suffix[i];
    // }

    // OPTIMAL APPROACH - TC: O(n), SC: O(1)
    // prefix: left product, siffix: right product
    // for any index i in an array, prefix is the product of left-side element of the i-th element and suffix is the 
    // right-side product of the i-th number
    // In this approach we won't store prefix or suffix, we will use it directly in our calculations.

    // Prefix of all elements - O(n)
    for (int i=1; i<n; i++) {
        ans[i] = ans[i-1] * nums[i-1];
    }
    // Suffix of all elements - O(n)
    int suffix = 1;
    for (int i=n-2; i>=0; i--) {
        suffix *= nums[i+1];
        ans[i] *= suffix;
    }

    return ans;
}

vector<int> twoSum(vector<int> numbers, int target) {
    vector<int> ans(2, -1);
    // BRUTE FORCE APPROACH - Find all pairs sum - TC = O(n^2) 
    // BETTER APPROACH - Sort and two pointer approach - TC = O(nlogn) 
    // sort(numbers.begin(), numbers.end());
    // int st = 0, end = numbers.size()-1;
    // while (st < end) {
    //     int sum = numbers[st] + numbers[end];
    //     if (sum == target) {
    //         ans[0] = st;
    //         ans[1] = end;
    //         break;
    //     }
    //     else if (sum > target) end--;
    //     else st++;
    // }

    // OPTIMIZED APPROACH - Use Hashing - TC = O(n) 
    unordered_map<int, int> um;
    for (int i=0; i<numbers.size(); i++) {
        int first = numbers[i];
        int sec = target - first;
        if (um.find(sec) != um.end()) {
            ans[0] = i;
            ans[1] = um[sec];
            break;
        } 
        um[first] = i;
    }

    return ans;
}

int findDuplicate(vector<int>& nums) {
    // TC = O(n), SC = O(n)
    // unordered_set<int> s;

    // for(int val : nums) {
    //     if (s.find(val) != s.end())
    //         return val;

    //     s.insert(val);
    // }
    // return -1;

    // TC = O(n), SC = O(1)
    // Use slow and fast pointer approach
    int slow = nums[0], fast = nums[0];
    
    do {
        cout << "slow = " << slow << "\nend = " << fast << endl;
        slow = nums[slow]; // +1
        fast = nums[nums[fast]]; // +2
    } while (slow != fast);

    slow = nums[0];
    while (slow != fast) {
        cout << "\nslow = " << slow << "\nend = " << fast << endl;
        slow = nums[slow]; // +1
        fast = nums[fast]; // +1
    }

    return slow;

    // sort(nums.begin(), nums.end());
    // int rep = nums[0];
    // for(int i=1; i<nums.size(); ++i) {
    //     if(nums[i] == rep) return nums[i];
    //     rep = nums[i];
    // }

    // return -1;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    // BRUTE FORCE - TC = O(n^3 * log(unique_triplets)). SC = O(unique_triplets)
    // Find all triplets in the array, and shortlist the unique ones whose sum equals to 0, and all three numbers should not be the same
    // vector<vector<int>> result;
    // set<vector<int>> uniqueTriplets;
    // int n = nums.size();
    // for (int i=0; i<n; i++) {
    //     for (int j=i+1; j<n; j++) {
    //         for (int k=j+1; k<n; k++) {
    //             if (nums[i]+nums[j]+nums[k] == 0) {
    //                 vector<int> triplet = {nums[i], nums[j], nums[k]};
    //                 sort(triplet.begin(), triplet.end());

    //                 if (uniqueTriplets.find(triplet) == uniqueTriplets.end()) {
    //                     uniqueTriplets.insert(triplet);
    //                     result.push_back(triplet);
    //                 }
    //             }
    //         }
    //     }
    // }
    
    // HASHING APPROACH - TC = O(n^2 * log(unique_triplets)). SC = O(unique_triplets + n)
    // set<vector<int>> uniqueTriplets;
    // int n = nums.size();

    // for (int i=0; i<n; i++) {
    //     int target = -nums[i];
    //     set<int> s;

    //     for (int j=i+1; j<n; j++) {
    //         int third = target - nums[j];

    //         if (s.find(third) != s.end()) {
    //             vector<int> triplet = {nums[i], nums[j], third};
    //             sort(triplet.begin(), triplet.end());
    //             uniqueTriplets.insert(triplet);
    //         }
    //         s.insert(nums[j]); 
    
    //     }
    // }

    // vector<vector<int>>result(uniqueTriplets.begin(), uniqueTriplets.end());
    // return result;

    // 2-POINTER APPROACH - TC = O(nlogn + n^2) = O(n^2), SC = O(uniqueTriplets)
    int n = nums.size();
    sort(nums.begin(), nums.end()); // O(nlogn)
    vector<vector<int>> result;

    for (int i=0; i<n; i++) {

        if (i>0 && nums[i] == nums[i-1]) continue;

        int j = i+1, k = n-1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0) {
                j++;
            } else if (sum > 0) {
                k--;
            } else {
                result.push_back({nums[i], nums[j], nums[k]});
                j++, k--;
                
                while (j<k && nums[j] == nums[j-1]) j++;
            }
        }
    }
    return result;
}

 vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // 2-POINTER APPROACH - TC = O(nlogn + n^3) = O(n^2), SC = O(uniqueGroups)
        vector<vector<int>> result;
        int n = nums.size();

        sort(nums.begin(), nums.end()); // O(nlogn)

        for (int i=0; i<n; i++) {
            if (i>0 && nums[i] == nums[i-1]) continue;

            for (int j=i+1; j<n;) {
                int p = j+1, q = n-1;

                while (p < q) {
                    long long sum = (long long)nums[i] + (long long)nums[j]
                                     + (long long)nums[p] + (long long)nums[q];

                    if (sum < target) {
                        p++;
                    } else if (sum > target) {
                        q--;
                    } else {
                        result.push_back({nums[i], nums[j], nums[p], nums[q]});
                        p++, q--;
                        
                        while (p < q && nums[p] == nums[p-1]) p++;
                    }
                }
                
                j++;
                while (j < n && nums[j] == nums[j-1]) j++;
            }
        }

        return result;
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

    // vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    // cout << maxArea(height) << endl;

    // vector<int> nums = {1, 2, 3, 4};
    // vector<int> ans = productExceptSelf(nums);
    // for (int i=0; i<ans.size(); i++) {
    //     cout << ans[i] << " ";
    // }
    // cout << endl;
    // vector<int> nums = {3, 2, 4};
    // vector<int> ans = twoSum(nums, 6);
    // printVector(ans);

    // vector<int> nums = {3, 1, 2, 4, 3};
    // printVector(nums);
    // cout << findDuplicate(nums) << endl;

    // vector<int> nums = {-1, 0, 1, 2, -1, -4};
    // printVector(nums);
    // vector<vector<int>> threeSumAns = threeSum(nums);
    // print2DVector(threeSumAns);

    vector<int> nums = {-2, -1, -2, 1, 1, 2, 2};
    printVector(nums);
    vector<vector<int>> fourSumAns = fourSum(nums, 0);
    print2DVector(fourSumAns);
    
    return 0;
}