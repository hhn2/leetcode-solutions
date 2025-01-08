class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
![upvote.jpeg](https://assets.leetcode.com/users/images/5c670c29-1619-4a4e-b76e-ba81c14936d5_1736176931.753991.jpeg)
