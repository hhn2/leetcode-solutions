# Last updated: 2/19/2026, 1:35:09 PM
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Codec:

    def serialize(self, root: TreeNode) -> str:
        result = []
        self._dfs_serialize(root, result)
        return "".join(result)

    def _dfs_serialize(self, node: TreeNode, result: list) -> None:
        if not node:
            result.append("n,")
            return
        
        result.append(str(node.val) + ",")
        self._dfs_serialize(node.left, result)
        self._dfs_serialize(node.right, result)

    def deserialize(self, data: str) -> TreeNode:
        self.index = 0
        return self._dfs_deserialize(data)

    def _dfs_deserialize(self, data: str) -> TreeNode:
        # Null marker
        if data[self.index] == 'n':
            self.index += 2  # skip "n,"
            return None

        # Parse integer value
        sign = 1
        if data[self.index] == '-':
            sign = -1
            self.index += 1

        num = 0
        while data[self.index] != ',':
            num = num * 10 + (ord(data[self.index]) - ord('0'))
            self.index += 1

        self.index += 1  # skip comma

        node = TreeNode(sign * num)
        node.left = self._dfs_deserialize(data)
        node.right = self._dfs_deserialize(data)
        return node

        

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))