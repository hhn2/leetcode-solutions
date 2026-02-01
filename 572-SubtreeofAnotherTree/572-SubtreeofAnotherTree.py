# Last updated: 1/31/2026, 7:47:24 PM
1# Definition for a binary tree node.
2# class TreeNode:
3#     def __init__(self, val=0, left=None, right=None):
4#         self.val = val
5#         self.left = left
6#         self.right = right
7class Solution:
8    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
9    
10        # If both trees are empty
11        if root is None and subRoot is None:
12            return True
13
14        # If only one is empty
15        if root is None or subRoot is None:
16            return False
17
18        # If values match, check same-tree OR continue searching
19        if root.val == subRoot.val:
20            return (
21                self.isSameTree(root, subRoot)
22                or self.isSubtree(root.left, subRoot)
23                or self.isSubtree(root.right, subRoot)
24            )
25        else:
26            # Values don't match, keep searching in subtrees
27            return (
28                self.isSubtree(root.left, subRoot)
29                or self.isSubtree(root.right, subRoot)
30            )
31
32    def isSameTree(self, root1: TreeNode, root2: TreeNode) -> bool:
33        # Both empty → same
34        if root1 is None and root2 is None:
35            return True
36
37        # One empty → not same
38        if root1 is None or root2 is None:
39            return False
40
41        # Different values → not same
42        if root1.val != root2.val:
43            return False
44
45        # Check left and right subtrees
46        return (
47            self.isSameTree(root1.left, root2.left)
48            and self.isSameTree(root1.right, root2.right)
49        )
50