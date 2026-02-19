// Last updated: 2/19/2026, 1:34:47 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   
    int helper(TreeNode*left, TreeNode*right, int x, int y){

        if (!left && !right){
            return 0;
        }

        if (!left){
            if (right->val == x || right->val == y){
                return 1;
            }
            else{
                return 0;
            }
        }
        else if (!right){
            if (left->val == x || left->val == y){
                return 1;
            }
            else{
                return 0;
            }
        }
        if ((left->val == x && right->val == y)||(left->val == x && right->val == y)){
            return -1;
        }
        else if (left->val == x || left->val == y ||right->val == x || right -> val == y){
            return 1;
        }
        else{
            return 0;
        }
    }
    bool isCousins(TreeNode* root, int x, int y) {
    
    if (!root ){
        return false;
    }

    int total;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()){
        int howmany = q.size();
        for (int i = 0; i < howmany; i++){
        TreeNode* interested = q.front();
        total += helper(interested->left, interested->right, x, y);
        if (interested->left){
            q.push(interested->left);
        }
        if (interested->right){
            q.push(interested->right);
        }
        q.pop();
        }
    

    if (total == -1){ // found them as siblings
        return false;
    }

    if (total == 2){ //found the two as cousins
        return true;
    }

    if (total == 1 ){ //found just one; the other doesn't exist or it is not in this level.
        return false;
    }

    else{
        total = 0;
    }

    }

    //should not reach this
    return false;

    }

     
};