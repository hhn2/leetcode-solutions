// Last updated: 5/22/2025, 5:32:24 PM
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // bool is true when even, and false when odd
        vector<vector<int>> v;
        if (!root){
            return v;
        }
        queue<TreeNode*> q;
        q.push(root);
        

        while (!q.empty()){
        int size = q.size();

        vector<int> sv;

        for (int i = 0; i < size; i++){
            auto hi = q.front();
            sv.push_back(hi->val);
            if(hi->left){
                q.push(hi->left);
            }
            if(hi->right){
                q.push(hi->right);
            }
            q.pop();
            }

        v.push_back(sv);


        }
       return v;
    }

    
};