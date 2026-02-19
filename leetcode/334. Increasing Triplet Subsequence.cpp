// PROBLEM :

Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

Example 1:

Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.
  
Example 2:

Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.
  
Example 3:

Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: One of the valid triplet is (1, 4, 5), because nums[1] == 1 < nums[4] == 4 < nums[5] == 6.

//SOLUTION :

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        for(int n : nums) {
            if(n <= min1) {
                min1 = n;  // Update first minimum
            } else if(n <= min2) {
                min2 = n;  // Update second minimum
            } else {
                return true;  // Found a third number greater than both
            }
        }
        return false;  // No triplet found
    }
};

