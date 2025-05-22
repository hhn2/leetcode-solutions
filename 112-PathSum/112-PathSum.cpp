// Last updated: 5/22/2025, 1:35:02 PM
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
using namespace std;

class Solution {
public:

    bool helper(TreeNode* root, int targetSum, int acc){

        if ((!root->right) && (!root->left)){
            if (root->val + acc == targetSum){
                return true;
            }
            return false;
        }
        else if (!root->right){
            return helper(root->left, targetSum, acc + root->val);
        }
        else if (!root->left){
            return helper(root->right, targetSum, acc + root->val);
        }
        else{
            return helper(root->left, targetSum, acc + root->val) + helper(root->right, targetSum, acc + root->val);
        }
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root){
            return false;
        }
        else if ((!root->left) && (!root->right)){
            if (root->val == targetSum){
                return true;
            }
            return false;

        }
        else if (!(root->left)){
            return helper(root->right, targetSum, root->val);
        }
        else if(!(root->right)){
            return helper(root->left, targetSum, root->val);
        }
        return helper(root, targetSum, 0);
    }
};