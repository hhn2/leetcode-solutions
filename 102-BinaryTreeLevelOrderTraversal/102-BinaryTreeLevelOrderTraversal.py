# Last updated: 10/4/2026, 10:54:21 PM
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: TreeNode | None) -> list[list[int]]:
        if not root:
            return []
        answer = []
        rootlevelanswer = [root.val]
        rootlevelnodes = deque([root])
        answer.append(rootlevelanswer)
        return self.addLeveltoAnswer(answer, rootlevelnodes)




    def addLeveltoAnswer (self, answer, nodes):
        if len(nodes) == 0:
            return answer
        newAnswer = []
        newNodes = deque([])
        while nodes:
            node = nodes.popleft()
            if node.left:
                newAnswer.append(node.left.val)
                newNodes.append(node.left)
            if node.right:
                newAnswer.append(node.right.val)
                newNodes.append(node.right)
            
        if len(newAnswer) > 0:
            answer.append(newAnswer)
            
        return self.addLeveltoAnswer(answer, newNodes)




        