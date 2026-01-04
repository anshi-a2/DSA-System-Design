// PROBLEM :

Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
  
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
  
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.


// SOLUTION :

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        nums.erase(remove_if(nums.begin(), nums.end(), [](int n) { return n <= 0; }), nums.end());

        sort(nums.begin(), nums.end());

        int target = 1;
        for (int n : nums) {
            if (n == target) {
                target++;
            } else if (n > target) {
                return target;
            }
        }
        
        return target;        
    }
};



// SOLUTION 02 :

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // Sort the array so that positive numbers are in increasing order
        sort(nums.begin(), nums.end());

        // 'target' represents the smallest positive number we are looking for
        int target = 1;

        // Traverse through the sorted array
        for (int n : nums) {

            // If current number is positive and matches the expected target,
            // move target to the next positive integer
            if (n > 0 && n == target) {
                target++;
            }
            // If current number is greater than target,
            // it means target is missing in the array
            else if (n > target) {
                return target;
            }
            // Ignore:
            // - negative numbers
            // - zero
            // - duplicates
            // - numbers smaller than target
        }

        // If all numbers from 1 to target-1 are present,
        // then target itself is the first missing positive
        return target;
    }
};
