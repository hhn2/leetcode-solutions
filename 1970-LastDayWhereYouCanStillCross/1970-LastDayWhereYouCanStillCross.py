# Last updated: 10/19/2026, 9:05:46 PM
1class Solution:
2    def latestDayToCross(self, row: int, col: int, cells: list[list[int]]) -> int:
3        #do binary search to find the lastest day to cross
4        #for the middle, do bfs to figure out if there is a possible path 
5        l = 0
6        r = len(cells) - 1
7        while (l < r):
8            m = (l + r) //2
9            if self.possible(row, col, cells, m):
10                l = m + 1
11            else: 
12                r = m
13            
14        return l
15
16    def possible(self, row, col, cells, day):
17        grid = [[0] * col for _ in range(row)]
18        flooded = [[0] * col for _ in range(row)]
19        for o in range(col):
20            
21            for i in range(0, day + 1):
22                flooded[cells[i][0]-1][cells[i][1]-1] = 1
23
24
25            if self.bfs(0, o, row, col, cells, flooded, grid):
26                return True
27    
28    def bfs(self, i, j, row, col, cells, flooded, grid):
29        #i is currrent row
30        #j is current column
31        #row is total num of rows
32        #col is total num of cols
33        if j < 0 or i < 0 or j >= col:
34            return False
35        if i == row :
36            return True
37        if grid[i][j] == 1:
38            return False
39        if flooded[i][j]:
40            return False
41        grid[i][j] = 1
42
43        return self.bfs(i, j+1, row, col, cells, flooded, grid) or self.bfs(i, j-1, row, col, cells,flooded, grid) or self.bfs(i - 1, j, row, col, cells, flooded, grid) or self.bfs(i + 1, j, row, col, cells, flooded, grid)
44