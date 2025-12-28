// PROBLEM :


Given the head of a linked list, rotate the list to the right by k places.

Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
  
Example 2:

Input: head = [0,1,2], k = 4
Output: [2,0,1]



// SOLUTION :


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        // If list is empty, no rotation needed
        if (!head) return head;

        int l = 1;                     // Length of the linked list
        ListNode* dummy = head;        // Pointer to traverse the list

        // Find length of the list and reach the last node
        while (dummy->next) {
            l += 1;
            dummy = dummy->next;
        }

        // Reduce k to avoid unnecessary rotations
        k = k % l;

        // If k is 0, list remains unchanged
        if (k == 0) return head;

        ListNode* curr = head;

        /*
         * Move curr to the (l - k - 1)th node
         * This node will become the new tail after rotation
         */
        for (int i = 0; i < l - k - 1; i++) {
            curr = curr->next;
        }

        // New head will be the next node
        ListNode* newHead = curr->next;

        // Break the list
        curr->next = NULL;

        // Connect last node to the old head
        dummy->next = head;

        // Return new head
        return newHead;
    }
};
