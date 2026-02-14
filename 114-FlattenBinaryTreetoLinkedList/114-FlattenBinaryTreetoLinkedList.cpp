// Last updated: 2/13/2026, 10:25:25 PM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    void flatten(TreeNode* root) {
15        if(!root){
16            return;
17        }
18        if (root->left){
19            TreeNode *temp = root-> right;
20            root->right = root->left;
21            root->left = nullptr;
22            TreeNode* iterator = root->right;
23            while(iterator->right){
24                iterator = iterator-> right;
25            }
26            iterator->right = temp;
27            
28        }
29        flatten(root->right);
30        
31    }
32};