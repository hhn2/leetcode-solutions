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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        return leaves(root1) == leaves(root2);
    }

    std::vector<int> leaves(TreeNode* root) {
        std::vector<int> res;
        collectLeaves(root, res);
        return res;
    }

    void collectLeaves(TreeNode* node, std::vector<int>& res) {
        if (!node) {
            return;
        }
        if (!node->left && !node->right) { 
            res.push_back(node->val);
            return;
        }
        collectLeaves(node->left, res); 
        collectLeaves(node->right, res); 
    }
};
