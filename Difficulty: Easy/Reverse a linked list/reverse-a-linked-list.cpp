
class Solution {
  public:
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* temp = head;
        Node* nextNode = nullptr; // Track the next node
        
        while (temp != nullptr) {
            nextNode = temp->next; // 1. Save the next node
            temp->next = prev;     // 2. Reverse the current node's pointer
            prev = temp;           // 3. Move prev one step forward
            temp = nextNode;       // 4. Move temp one step forward
        }
        
        return prev; // prev now points to the new head of the reversed list
    }
};