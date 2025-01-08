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
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        if (nums.empty()) {
            return nullptr;
        }
        int n = nums.size();
        int median = n/2;
        TreeNode* head = new TreeNode(nums[median]);

        vector<int> v1(nums.begin(), nums.begin() + median);
        vector<int> v2(nums.begin() + median + 1, nums.end());
        head->left = sortedArrayToBST(v1);
        head->right = sortedArrayToBST(v2);
        return head;
    }
};