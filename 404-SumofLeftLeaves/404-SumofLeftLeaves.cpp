// Last updated: 5/22/2025, 2:33:40 PM
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
 
    int sumOfLeftLeaves(TreeNode* root) {
        queue<pair<TreeNode*, bool>> q;
        int res = 0;
        q.push({root, false});

        while (q.empty() == false){
            auto tn = q.front();
                if (tn.first->left){
                    q.push({tn.first->left, true});
                }
                if (tn.first->right){
                    q.push({tn.first->right, false});
                }
                if (!(tn.first->left) && !(tn.first->right) && (tn.second == true)){
                    res += tn.first->val;
                }

                q.pop();

        }

        return res;
    }
};