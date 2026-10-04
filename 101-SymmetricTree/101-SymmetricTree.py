# Last updated: 10/4/2026, 5:06:53 PM
1# Definition for a binary tree node.
2# class TreeNode:
3#     def __init__(self, val=0, left=None, right=None):
4#         self.val = val
5#         self.left = left
6#         self.right = right
7class Solution:
8    def isSymmetric(self, root: TreeNode | None) -> bool:
9        if not root:
10            return True
11
12        return self.isSame(root.left, root.right)
13
14
15    def isSame(self, lnode, rnode):
16        if not lnode and not rnode:
17            return True
18
19        if not lnode or not rnode:
20            return False
21
22        if lnode.val != rnode.val:
23            return False
24        
25        return self.isSame(lnode.left, rnode.right) and self.isSame(lnode.right, rnode.left)
26
27