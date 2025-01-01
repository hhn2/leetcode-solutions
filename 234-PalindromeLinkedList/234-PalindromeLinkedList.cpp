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
    bool isPalindrome(ListNode* head) {
        std::deque<int> myDeque;
        for (ListNode* i = head; i != nullptr; i = i->next){
            myDeque.push_back(i->val);
        }
        while(true){
            if(myDeque.size() == 1 || myDeque.size() == 0){
                return true;
            }
            if (myDeque.back() == myDeque.front() ){
                myDeque.pop_front();
                myDeque.pop_back();
            }
            else{
                return false;
            }
        }

        return 0;
    }
};