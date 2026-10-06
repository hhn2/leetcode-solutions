# Last updated: 10/5/2026, 10:58:21 PM
1class Solution:
2    def uniquePaths(self, m: int, n: int) -> int:
3        
4        #can be solved with dp
5        #let c(i, j) represent the num of paths from i,j to m-1,n-1
6        #base case: c(m-1, n-1) = 1 we are already at the answer; one way to get to it
7        #answer: c(0,0) where we start
8        #recursion: c(i, j) = c(i+1, j) + c(i, j+1)
9        return self.dp(m, n, 0, 0, [[None] * n for _ in range(m)])
10        
11    def dp(self, m, n, currm, currn, mymap ):
12        if mymap[currm][currn] is not None:
13            return mymap[currm][currn]
14        if currm == m - 1 and currn == n - 1:
15            return 1
16        elif currm == m - 1:
17            mymap[currm][currn] = self.dp(m, n, currm, currn + 1, mymap)
18            return self.dp(m, n, currm, currn + 1, mymap)
19
20        elif currn == n - 1:
21            mymap[currm][currn] = self.dp(m, n, currm + 1, currn, mymap)
22            return self.dp(m, n, currm + 1, currn, mymap)
23        
24        mymap[currm][currn]=self.dp(m, n, currm + 1, currn, mymap) + self.dp(m, n, currm, currn+1, mymap)
25        return self.dp(m, n, currm + 1, currn, mymap) + self.dp(m, n, currm, currn+1, mymap)
26
27