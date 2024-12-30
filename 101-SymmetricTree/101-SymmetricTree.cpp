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
    bool isSymmetric(TreeNode* root) {
       return this->checker(root->left, root->right);
    }

    bool checker(TreeNode* left, TreeNode* right){

        if (!left && !right){
            return true;
        }
        if (left && right && left->val == right->val){
        return this->checker(left->right, right->left) && this->checker(left->left, right->right);
        }

        return false;
    }
};