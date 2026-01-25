// PROBLEM :


Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 

Example 1:

Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
  
Example 2:

Input: root = []
Output: []
  
Example 3:

Input: root = [0]
Output: [0]



// SOLUTION :


class Solution {
public:
    
    TreeNode* rightmost(TreeNode* root){
        if (root->right==NULL) return root;
        return rightmost(root->right);
    }
    
    void flatten(TreeNode* root) {
        if (root==NULL) return;
        TreeNode* nextright;
        TreeNode* rightMOST;
        
        while (root){
            
            if (root->left){
                rightMOST = rightmost(root->left);
                nextright = root->right;
                root->right = root->left;
                root->left=NULL;
                rightMOST->right=nextright;
            }
            root=root->right;
        }
    }
};


// SOLUTION 02 : Recursive (Reverse Postorder)

class Solution {
    TreeNode* prev = nullptr;

public:
    void flatten(TreeNode* root) {
        if (!root) return;

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};


// What does “Reverse Postorder” mean here?
// Normal traversals:
// Preorder: root → left → right
// Postorder: left → right → root
// 👉 Reverse postorder used here:
// right → left → root


// Core Idea (Very Important)

// We maintain a pointer:
// TreeNode* prev = nullptr;
// Think of prev as:
// “the node that should come after the current node in the flattened list”
// So when we process a node:
// Its right should point to prev
// Its left must be NULL
// Then we update prev = current node




