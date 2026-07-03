// Last updated: 7/2/2026, 11:16:07 PM
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
    int longestZigZag(TreeNode* root) {
        int answer = max(helper(root, true, -1), helper(root, false, -1));
        return answer;
    }

    int helper(TreeNode* current, bool isRight, int count){
        if (!current){
            return count;
        }

        if(isRight){
            count++;
            return max(helper(current->right, false, count), helper(current->left, true, 0));
        }

        else{
            count++;
            return max(helper(current->left, true, count), helper(current->right, false, 0));
        }
    }
};