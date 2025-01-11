/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if ((root-> val == p->val) || (root->val == q->val)){
            return root;
        }
        else if (ExistNode(root->left, p->val) && ExistNode(root->left, q->val)){
            return lowestCommonAncestor(root->left, p, q);
        }
        else if (ExistNode(root->right, p->val) && ExistNode(root->right, q->val)){
            return lowestCommonAncestor(root->right, p, q);
        }
        else{
        return root;
        }
    }

    bool ExistNode(TreeNode*root, int target){
    if (!root){
        return false;
    }
    if (root->val == target){
        return true;
    }
    return ExistNode(root->left, target) || ExistNode(root->right, target);
        }
};