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
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        std::deque<TreeNode*> queue;
        queue.push_back(root);
        int depth = 1; 

        while (!queue.empty()) {
            int levelSize = queue.size(); 
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* currentNode = queue.front();
                queue.pop_front();

                if (!currentNode->left && !currentNode->right) {
                    return depth; 
                }

                if (currentNode->left) {
                    queue.push_back(currentNode->left);
                }
                if (currentNode->right) {
                    queue.push_back(currentNode->right);
                }
            }
            depth++; 
        }

        return 0; 
    }
};