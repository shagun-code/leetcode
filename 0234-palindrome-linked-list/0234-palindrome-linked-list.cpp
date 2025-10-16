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
    // Helper function to reverse a linked list
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;

        // Step 1: Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half
        ListNode* secondHalfStart = reverseLinkedList(slow->next);

        // Step 3: Compare both halves
        ListNode* firstHalfStart = head;
        ListNode* secondHalfCopy = secondHalfStart; // to restore later if needed
        bool isPalin = true;
        while (secondHalfStart != nullptr) {
            if (firstHalfStart->val != secondHalfStart->val) {
                isPalin = false;
                break;
            }
            firstHalfStart = firstHalfStart->next;
            secondHalfStart = secondHalfStart->next;
        }

        // Step 4 (optional): Restore the list
        slow->next = reverseLinkedList(secondHalfCopy);

        return isPalin;
    }
};