// PROBLEM :

You are given an integer array nums and an integer k.
The frequency of an element x is the number of times it occurs in an array.
An array is called good if the frequency of each element in this array is less than or equal to k.
Return the length of the longest good subarray of nums.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [1,2,3,1,2,3,1,2], k = 2
Output: 6

// SOLUTION :

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, queue<int>> mp;
        int l=0;
        int n= nums.size();
        int ans =0;
        for(int r=0;r<n;r++) {
            mp[nums[r]].push(r);
            if(mp[nums[r]].size()>k){
                if(l<=mp[nums[r]].front()){
                    l=mp[nums[r]].front()+1;
                    
                }
                mp[nums[r]].pop();
                
            }
            ans=max(ans, r-l+1);
        }
        return ans;
        
    }
};
