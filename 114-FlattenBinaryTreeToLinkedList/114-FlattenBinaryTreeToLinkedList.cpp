// Last updated: 10/4/2026, 10:54:14 PM
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
    void flatten(TreeNode* root) {
        if(!root){
            return;
        }
        if (root->left){
            TreeNode *temp = root-> right;
            root->right = root->left;
            root->left = nullptr;
            TreeNode* iterator = root->right;
            while(iterator->right){
                iterator = iterator-> right;
            }
            iterator->right = temp;
            
        }
        flatten(root->right);
        
    }
};