# Last updated: 2/14/2026, 3:47:47 PM
1# Definition for a binary tree node.
2class TreeNode:
3    def __init__(self, val=0, left=None, right=None):
4        self.val = val
5        self.left = left
6        self.right = right
7
8class Solution:
9    def flatten(self, root: TreeNode) -> None:
10        if not root:
11            return
12        
13        if root.left:
14            temp = root.right
15            root.right = root.left
16            root.left = None
17            
18            iterator = root.right
19            while iterator.right:
20                iterator = iterator.right
21            
22            iterator.right = temp
23        
24        self.flatten(root.right)
25