# Last updated: 5/28/2026, 9:52:40 PM
1class Solution:
2    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
3        mySol = Solution()
4        answer = []
5        mySol.backtrack([], 0, answer, 1, k, n)
6        return answer
7
8    def backtrack(self, current, currsum, answer, index, k, n):
9        if currsum == n and len(current) == k:
10            answer.append(current[:]) # need to fix this
11            return
12        
13        if len(current) > k:
14            return
15
16        if index == 10:
17            return
18
19        currsum += index
20        current.append(index)
21        self.backtrack(current, currsum, answer, index + 1, k, n)
22        currsum -= index
23        current.pop()
24
25        
26        self.backtrack(current, currsum, answer, index + 1, k, n)
27       
28
29
30