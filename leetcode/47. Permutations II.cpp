// PROBLEM :

Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
  
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]


// SOLUTION :

class Solution {
private: 
    // Helper function to generate all unique permutations using backtracking
    void permuteUnique(vector<int>& nums,
                       vector<vector<int>>& output,
                       vector<int> temp,
                       vector<bool>& visited) {

        // Base case: if current permutation length equals input size,
        // we have formed a valid unique permutation
        if (temp.size() == nums.size()) {
            output.push_back(temp);
            return;
        }

        // Try placing each number at the current position
        for (int i = 0; i < nums.size(); i++) {

            // Skip if:
            // 1. Number is already used in current permutation
            // 2. Duplicate number is being used before its previous occurrence
            //    (to avoid generating duplicate permutations)
            if (visited[i] ||
                (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])) {
                continue;
            }

            // Mark current number as used
            visited[i] = true;
            temp.push_back(nums[i]);

            // Recurse to build the next position
            permuteUnique(nums, output, temp, visited);

            // Backtrack: remove last element and mark it unused
            temp.pop_back();
            visited[i] = false;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        // Sort the array so that duplicates are adjacent
        // This helps in skipping duplicate permutations
        sort(nums.begin(), nums.end());

        vector<vector<int>> output; // Stores all unique permutations
        vector<int> temp;           // Current permutation being built

        // visited[i] indicates whether nums[i] is already used in current permutation
        vector<bool> visited(nums.size(), false); 

        // Start backtracking
        permuteUnique(nums, output, temp, visited);

        return output;
    }
};
