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
    // Helper to get the k-th node from current node
    ListNode* getKthNode(ListNode* temp, int k) {
        k -= 1;
        while (temp != NULL && k > 0) {
            temp = temp->next;
            k--;
        }
        return temp;
    }

    // Helper to reverse a linked list segment
    void reverseLinkedList(ListNode* start, ListNode* end) {
        ListNode* prev = NULL;
        ListNode* curr = start;
        ListNode* stop = end->next;

        while (curr != stop) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;

        while (temp != NULL) {
            ListNode* kthNode = getKthNode(temp, k);
            if (kthNode == NULL) {
                if (prevLast) prevLast->next = temp;
                break;
            }

            ListNode* nextNode = kthNode->next;

            // Reverse the current k-group
            reverseLinkedList(temp, kthNode);

            if (temp == head) {
                head = kthNode;
            } else {
                prevLast->next = kthNode;
            }

            prevLast = temp;
            temp = nextNode;
        }

        return head;
    }
};