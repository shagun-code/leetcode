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
        if (head == NULL || k == 0) return head;

        // Step 1: Find the length and tail of the list
        ListNode* tail = head;
        int len = 1;
        while (tail->next != NULL) {
            tail = tail->next;
            len++;
        }

        // Step 2: Handle cases where rotation is a multiple of length
        k = k % len;
        if (k == 0) return head;

        // Step 3: Make the list circular
        tail->next = head;

        // Step 4: Find the new tail (len - k)th node
        ListNode* newLastNode = findNthNode(head, len - k);

        // Step 5: Break the circle and set new head
        ListNode* newHead = newLastNode->next;
        newLastNode->next = NULL;

        return newHead;
    }

private:
    ListNode* findNthNode(ListNode* temp, int k) {
        int cnt = 1;
        while (temp != NULL) {
            if (cnt == k) return temp;
            cnt++;
            temp = temp->next;
        }
        return temp;
    }
};