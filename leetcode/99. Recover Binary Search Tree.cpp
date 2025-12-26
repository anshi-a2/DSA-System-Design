// PROBELM :

You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

Example 1:

Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.


// SOLUTION :

class Solution {
public:
    // Pointer to keep track of previously visited node in inorder traversal
    TreeNode* prev = NULL;

    // Pointer to the first node that violates BST property
    TreeNode* first = NULL;

    // Pointer to the second node that violates BST property
    TreeNode* second = NULL;

    // Inorder traversal of BST
    // Inorder traversal of a BST should give sorted order
    void inorder(TreeNode* root) {
        // Base case
        if (root == NULL) return;

        // Traverse left subtree
        inorder(root->left);

        /*
         * If previous node exists and its value is greater than
         * current node's value, it means BST property is violated.
         */
        if (prev != NULL && prev->val > root->val) {

            /*
             * For the first violation:
             * - prev is the first incorrect node
             */
            if (first == NULL) {
                first = prev;
            }

            /*
             * For both first and second violation:
             * - current node is the second incorrect node
             */
            second = root;
        }

        // Update prev to current node
        prev = root;

        // Traverse right subtree
        inorder(root->right);
    }

    // Function to recover the BST by fixing swapped nodes
    void recoverTree(TreeNode* root) {
        // Find the two misplaced nodes using inorder traversal
        inorder(root);

        // Swap values of the two incorrect nodes
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
};




