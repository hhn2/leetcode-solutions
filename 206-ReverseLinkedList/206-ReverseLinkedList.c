// Last updated: 7/2/2026, 11:16:41 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    struct ListNode *daum = NULL;

    while (curr != NULL){
        daum = curr->next;
        curr->next = prev;
        prev = curr;
        curr= daum;
    }
    return prev;
}