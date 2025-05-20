// Last updated: 5/20/2025, 12:16:16 AM
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

    ListNode* mergetwo(ListNode* first, ListNode* second){
        ListNode* toreturn = new ListNode;
        if ((first) || (second)){
        ListNode* current1 = first;
        ListNode* current2 = second;
        ListNode* currentret = toreturn;
      


        while (true){
            if ((!current1) && (!current2)){
                break;
            }
            else if (!current1){
                currentret->next = current2;
                break;
            }
            else if (!current2){
                currentret->next = current1;
                break;
            }
            else if ((current2->val <= current1-> val)){
                currentret->next = current2;
                current2 = current2->next;
                currentret = currentret->next;
            }
            else if ((current1->val < current2-> val)){
                currentret->next = current1;
                current1 = current1->next;
                currentret = currentret->next;
            }
          
        }
        return toreturn->next;
        }

        return nullptr;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size()== 0 ){
            return nullptr;
        }
        if (lists.size() == 1){
            return lists[0];
        }
        ListNode* todelete = lists[1];
        ListNode* replacement = mergetwo(lists[0], lists[1]);
        lists.erase(lists.begin() + 1);
        lists[0] = replacement;
        return mergeKLists(lists);
    }
};