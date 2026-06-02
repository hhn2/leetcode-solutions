# Last updated: 6/2/2026, 4:31:02 PM
1"""
2# Definition for a Node.
3class Node:
4    def __init__(self, val = 0, neighbors = None):
5        self.val = val
6        self.neighbors = neighbors if neighbors is not None else []
7"""
8
9from typing import Optional
10class Solution:
11    
12    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
13        self.seen={}
14        def dfs(curr_node):
15            if not curr_node:
16                return None
17            
18            if curr_node.val in self.seen:
19                return self.seen[curr_node.val]
20            
21            # Clone the node
22            clone = Node(curr_node.val)
23            self.seen[curr_node.val] = clone
24            
25            # Recursively clone neighbors
26            for neighbor in curr_node.neighbors:
27                clone.neighbors.append(dfs(neighbor))
28                
29            return clone
30        
31        return dfs(node)