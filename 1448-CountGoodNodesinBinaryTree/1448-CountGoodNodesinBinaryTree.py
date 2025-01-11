# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        if not root:
            return 0
        return 1 + self.countGN(root.left, root.val) + self.countGN(root.right, root.val)

    def countGN(self, node: TreeNode, max_val: int) -> int:
        if not node:
            return 0
        if node.val >= max_val:
            return 1 + self.countGN(node.left, node.val) + self.countGN(node.right, node.val)
        return self.countGN(node.left, max_val) + self.countGN(node.right, max_val)