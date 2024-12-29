# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        st = []  
        current = root
        count = 0
        
        while st or current:
            while current:
                st.append(current)
                current = current.left
            
            current = st.pop()
            count += 1
            if count == k:
                return current.val
            
            current = current.right
        
        return 0


        