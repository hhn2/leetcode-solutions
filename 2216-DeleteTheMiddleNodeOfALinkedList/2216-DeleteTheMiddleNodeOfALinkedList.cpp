// Last updated: 2/19/2026, 1:34:38 PM
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
    ListNode* deleteMiddle(ListNode* head) {
        if (!head->next){
            return NULL;
        }

        if (!head->next->next){
            head->next = NULL;
            return head;
        }

        ListNode* before = head;
        ListNode* middle = head->next;
        ListNode* after = head->next->next;

        int n = 3;

        ListNode* ln = after;
        while (ln->next){
            n++;

            if ( n % 2 == 0 ){
                before = middle;
                middle = after;
                after = after->next;
            }
            ln = ln-> next;
        }

        before->next = after;
        return head;
        
    }

};

