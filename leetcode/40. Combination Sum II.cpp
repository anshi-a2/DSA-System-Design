// PROBLEM :

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
  
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]


// SOLUTION :

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Sort the array to:
        // 1. Easily skip duplicates
        // 2. Maintain combinations in non-decreasing order
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;   // Stores all valid combinations
        vector<int> comb;          // Current combination being built

        // Start DFS from index 0
        dfs(candidates, ans, comb, target, 0);
        return ans;
    }

    void dfs(vector<int> candidates, vector<vector<int>>& ans,
             vector<int>& comb, int target, int start) {

        // If target becomes negative, no valid combination possible
        if (target < 0) return;

        // If target becomes exactly 0, current combination is valid
        if (target == 0) {
            ans.push_back(comb);
            return; // Important: stop further exploration
        }

        // Try each candidate starting from 'start' index
        for (int i = start; i < candidates.size(); i++) {

            // Skip duplicates:
            // If the current element is same as previous one
            // and we're at the same recursive level, skip it
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // Choose the current element
            comb.push_back(candidates[i]);

            // Recurse with:
            // 1. Reduced target
            // 2. Next index (i + 1) because each number can be used once
            dfs(candidates, ans, comb, target - candidates[i], i + 1);

            // Backtrack: remove the last added element
            comb.pop_back();
        }
    }
};



