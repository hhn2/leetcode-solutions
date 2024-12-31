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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* currNode = head;
        if (!head){
            return nullptr;
        }
        if (!head->next){
            if(head->val == val){
                return nullptr;
            }
            else{
                return head;
            }
        }
        ListNode* nextNode = currNode->next;
        ListNode* prevNode = nullptr;

        while (currNode){
            if (currNode->val == val){
                if(prevNode){
                prevNode->next = nextNode;
                }
                else{
                    head = nextNode;
                }
                currNode = nextNode;
                if(nextNode){
                nextNode = currNode->next;
                }
            }
            else{
                prevNode = currNode;
                currNode = nextNode;
                if (nextNode){
                nextNode = currNode->next;
                }
            }

        }
        return head;
    }
};