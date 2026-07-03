# Last updated: 7/2/2026, 11:16:06 PM
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        return max(self.helper(root, True, -1), self.helper(root, False, -1))

    def helper(self, current, isRight, count):
        if(not current):
            return count;
        if(isRight):
            count += 1
            return max(self.helper(current.right, False, count), self.helper(current.left, True, 0))
        else:
            count += 1
            return max(self.helper(current.left, True, count), self.helper(current.right, False, 0))
        


        