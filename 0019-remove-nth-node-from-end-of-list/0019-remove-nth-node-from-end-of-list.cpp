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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to simplify edge case handling
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // Move fast pointer n+1 steps ahead
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }

        // Move both pointers until fast reaches the end
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // Delete the target node
        ListNode* delNode = slow->next;
        slow->next = delNode->next;
        delete delNode;

        // Return the new head
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};