// Last updated: 7/2/2026, 11:17:34 PM
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return head; // Empty list
        }
        
        ListNode* current = head;
        while (current->next != nullptr) {
            if (current->val == current->next->val) {
                // Remove duplicate
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp; // Free memory
            } else {
                current = current->next; // Move to the next node
            }
        }
        
        return head;
    }
};
