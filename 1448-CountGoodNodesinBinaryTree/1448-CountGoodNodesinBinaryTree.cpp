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
    int goodNodes(TreeNode* root) {
        if (!root){
            return 0;
        }
        
        return 1 + countGN(root->left,root->val) + countGN(root->right, root->val);

        }

    int countGN(TreeNode* node, int max){
        if (!node){
            return 0;

        }
        if (node->val >= max){
            return 1 + countGN(node->left, node->val) + countGN(node->right, node->val);
        }
        
            return countGN(node->left, max) + countGN(node->right, max);
        
    }

};