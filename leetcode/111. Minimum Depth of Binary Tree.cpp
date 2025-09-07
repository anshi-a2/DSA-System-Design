// PROBELM :

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 2
Example 2:

Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
 

Constraints:

The number of nodes in the tree is in the range [0, 105].


// SOLUTION :


class Solution {
public:
    int minDepth(TreeNode* root) {

        if(!root) return 0;
        int l = minDepth(root->left);
        int r= minDepth(root->right);
        if( l==0 || r==0)return 1+ max(l,r); //if one subtree is missing, take another path
        return 1+ min(l,r );
        
    }
};
