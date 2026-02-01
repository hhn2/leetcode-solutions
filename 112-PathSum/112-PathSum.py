# Last updated: 1/31/2026, 7:40:18 PM
1# Definition for a binary tree node.
2# class TreeNode:
3#     def __init__(self, val=0, left=None, right=None):
4#         self.val = val
5#         self.left = left
6#         self.right = right
7class Solution:
8   
9    def helper(self, root: TreeNode, targetSum: int, acc: int) -> bool:
10        # If this is a leaf node
11        if root.left is None and root.right is None:
12            return root.val + acc == targetSum
13
14        # If only left child exists
15        elif root.right is None:
16            return self.helper(root.left, targetSum, acc + root.val)
17
18        # If only right child exists
19        elif root.left is None:
20            return self.helper(root.right, targetSum, acc + root.val)
21
22        # If both children exist
23        else:
24            return (
25                self.helper(root.left, targetSum, acc + root.val)
26                or self.helper(root.right, targetSum, acc + root.val)
27            )
28
29    def hasPathSum(self, root: TreeNode, targetSum: int) -> bool:
30        if root is None:
31            return False
32
33        # Single-node tree
34        if root.left is None and root.right is None:
35            return root.val == targetSum
36
37        # Only right subtree
38        elif root.left is None:
39            return self.helper(root.right, targetSum, root.val)
40
41        # Only left subtree
42        elif root.right is None:
43            return self.helper(root.left, targetSum, root.val)
44
45        # Both children exist
46        return self.helper(root, targetSum, 0)
47