# Last updated: 2/26/2026, 11:06:53 AM
1# Definition for a binary tree node.
2# class TreeNode:
3#     def __init__(self, val=0, left=None, right=None):
4#         self.val = val
5#         self.left = left
6#         self.right = right
7class Solution:
8    def longestZigZag(self, root: Optional[TreeNode]) -> int:
9        return max(self.helper(root, True, -1), self.helper(root, False, -1))
10
11    def helper(self, current, isRight, count):
12        if(not current):
13            return count;
14        if(isRight):
15            count += 1
16            return max(self.helper(current.right, False, count), self.helper(current.left, True, 0))
17        else:
18            count += 1
19            return max(self.helper(current.left, True, count), self.helper(current.right, False, 0))
20        
21
22
23        