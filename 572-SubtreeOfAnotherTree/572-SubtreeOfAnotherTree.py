# Last updated: 2/19/2026, 1:34:59 PM
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
    
        # If both trees are empty
        if root is None and subRoot is None:
            return True

        # If only one is empty
        if root is None or subRoot is None:
            return False

        # If values match, check same-tree OR continue searching
        if root.val == subRoot.val:
            return (
                self.isSameTree(root, subRoot)
                or self.isSubtree(root.left, subRoot)
                or self.isSubtree(root.right, subRoot)
            )
        else:
            # Values don't match, keep searching in subtrees
            return (
                self.isSubtree(root.left, subRoot)
                or self.isSubtree(root.right, subRoot)
            )

    def isSameTree(self, root1: TreeNode, root2: TreeNode) -> bool:
        # Both empty → same
        if root1 is None and root2 is None:
            return True

        # One empty → not same
        if root1 is None or root2 is None:
            return False

        # Different values → not same
        if root1.val != root2.val:
            return False

        # Check left and right subtrees
        return (
            self.isSameTree(root1.left, root2.left)
            and self.isSameTree(root1.right, root2.right)
        )
