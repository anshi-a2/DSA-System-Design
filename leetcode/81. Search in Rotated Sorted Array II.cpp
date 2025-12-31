// PROBLEM :

There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
  
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
  
Example 3:

Input: nums = [1], target = 0
Output: -1


// SOLUTION : 


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();

        // Initialize binary search pointers
        int start = 0;
        int end = n - 1;

        // Standard binary search loop
        while (start <= end) {
            // Calculate mid safely to avoid overflow
            int mid = start + (end - start) / 2;

            // If target found at mid, return true
            if (nums[mid] == target) {
                return true;
            }

            /*
             Case 1:
             nums[start] == nums[mid] == nums[end]
             This means duplicates are present and we CANNOT
             determine which side is sorted.
             So we shrink the search space from both ends.
            */
            if (nums[start] == nums[mid] && nums[mid] == nums[end]) {
                start++;
                end--;
            }

            /*
             Case 2:
             Left half is sorted
             nums[start] <= nums[mid] confirms sorted order
            */
            else if (nums[start] <= nums[mid]) {

                // Check if target lies in the sorted left half
                if (target >= nums[start] && target <= nums[mid]) {
                    end = mid - 1;   // Search left half
                } else {
                    start = mid + 1; // Search right half
                }
            }

            /*
             Case 3:
             Right half is sorted
            */
            else {

                // Check if target lies in the sorted right half
                if (target >= nums[mid] && target <= nums[end]) {
                    start = mid + 1; // Search right half
                } else {
                    end = mid - 1;   // Search left half
                }
            }
        }

        // Target not found
        return false;
    }
};
