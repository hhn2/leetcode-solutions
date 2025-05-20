// Last updated: 5/20/2025, 12:20:34 AM
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
        ListNode mynode;
        ListNode* toreturn = &mynode;

        if ((!first) && (!second)){
            return nullptr;
        }

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



    ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    
    int interval = 1;
    while (interval < lists.size()) {
        for (int i = 0; i + interval < lists.size(); i += interval * 2) {
            lists[i] = mergetwo(lists[i], lists[i + interval]);
        }
        interval *= 2;
    }
    
    return lists[0];
}
};