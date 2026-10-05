# Last updated: 10/4/2026, 10:46:07 PM
1# Definition for a binary tree node.
2# class TreeNode:
3#     def __init__(self, val=0, left=None, right=None):
4#         self.val = val
5#         self.left = left
6#         self.right = right
7
8class Solution:
9    def levelOrder(self, root: TreeNode | None) -> list[list[int]]:
10        if not root:
11            return []
12        answer = []
13        rootlevelanswer = [root.val]
14        rootlevelnodes = deque([root])
15        answer.append(rootlevelanswer)
16        return self.addLeveltoAnswer(answer, rootlevelnodes)
17
18
19
20
21    def addLeveltoAnswer (self, answer, nodes):
22        if len(nodes) == 0:
23            return answer
24        newAnswer = []
25        newNodes = deque([])
26        while nodes:
27            node = nodes.popleft()
28            if node.left:
29                newAnswer.append(node.left.val)
30                newNodes.append(node.left)
31            if node.right:
32                newAnswer.append(node.right.val)
33                newNodes.append(node.right)
34            
35        if len(newAnswer) > 0:
36            answer.append(newAnswer)
37            
38        return self.addLeveltoAnswer(answer, newNodes)
39
40
41
42
43        