# Last updated: 10/4/2026, 10:54:11 PM
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def flatten(self, root: TreeNode) -> None:
        if not root:
            return
        
        if root.left:
            temp = root.right
            root.right = root.left
            root.left = None
            
            iterator = root.right
            while iterator.right:
                iterator = iterator.right
            
            iterator.right = temp
        
        self.flatten(root.right)
