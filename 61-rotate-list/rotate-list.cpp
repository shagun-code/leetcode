class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // 1. Base case: empty list or single-node list
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }

        // 2. Find the length of the list and locate the tail node
        int length = 1;
        ListNode* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
            length++;
        }

        // 3. Optimize rotations using modulo
        k = k % length;
        if (k == 0) {
            return head;
        }

        // 4. Make the linked list circular
        tail->next = head;

        // 5. Traverse to the new tail node (length - k - 1 steps)
        int stepsToNewTail = length - k;
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }

        // 6. Set the new head and break the circle
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};