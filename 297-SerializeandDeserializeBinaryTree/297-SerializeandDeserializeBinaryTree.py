# Last updated: 2/14/2026, 4:11:27 PM
1# Definition for a binary tree node.
2# class TreeNode(object):
3#     def __init__(self, x):
4#         self.val = x
5#         self.left = None
6#         self.right = None
7
8
9class Codec:
10
11    def serialize(self, root: TreeNode) -> str:
12        result = []
13        self._dfs_serialize(root, result)
14        return "".join(result)
15
16    def _dfs_serialize(self, node: TreeNode, result: list) -> None:
17        if not node:
18            result.append("n,")
19            return
20        
21        result.append(str(node.val) + ",")
22        self._dfs_serialize(node.left, result)
23        self._dfs_serialize(node.right, result)
24
25    def deserialize(self, data: str) -> TreeNode:
26        self.index = 0
27        return self._dfs_deserialize(data)
28
29    def _dfs_deserialize(self, data: str) -> TreeNode:
30        # Null marker
31        if data[self.index] == 'n':
32            self.index += 2  # skip "n,"
33            return None
34
35        # Parse integer value
36        sign = 1
37        if data[self.index] == '-':
38            sign = -1
39            self.index += 1
40
41        num = 0
42        while data[self.index] != ',':
43            num = num * 10 + (ord(data[self.index]) - ord('0'))
44            self.index += 1
45
46        self.index += 1  # skip comma
47
48        node = TreeNode(sign * num)
49        node.left = self._dfs_deserialize(data)
50        node.right = self._dfs_deserialize(data)
51        return node
52
53        
54
55# Your Codec object will be instantiated and called as such:
56# ser = Codec()
57# deser = Codec()
58# ans = deser.deserialize(ser.serialize(root))