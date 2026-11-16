# Last updated: 11/15/2026, 7:43:59 PM
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def insertIntoBST(self, root: TreeNode | None, val: int) -> TreeNode | None:
        if not root:
            return TreeNode(val)
        self.helper(root, val)
        return root

    def helper(self, node, val):
        if val > node.val:
            if node.right:
                return self.helper(node.right, val)
            else:
                node.right = TreeNode(val)
        elif val < node.val:
            if node.left:
                return self.helper(node.left, val)
            else:
                node.left = TreeNode(val)