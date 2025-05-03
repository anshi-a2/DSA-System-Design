// PROBLEM :


Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

Example 1:

Input: root = [3,1,4,null,2], k = 1
Output: 1
  
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3


// SOLUTION :


/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int count=0;
    public int kthSmallest(TreeNode root, int k) {

        TreeNode ans =helper(root , k);
        if(ans==null)
        return 0;
        
        return ans.val;

    }

    private TreeNode helper(TreeNode root, int k){

        if(root==null)
        return null;

        TreeNode left=helper(root.left , k);
        if(left!=null)
        return left;

        count++;
        if(count == k)
        return root;

        return helper(root.right , k);
    }
}



 
