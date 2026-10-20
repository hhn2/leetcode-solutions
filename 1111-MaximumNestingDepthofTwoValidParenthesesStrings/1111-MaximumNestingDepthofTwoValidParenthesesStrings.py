# Last updated: 10/20/2026, 7:55:25 PM
1class Solution:
2    def maxDepthAfterSplit(self, seq: str) -> list[int]:
3        currdepth = 0
4        answer = [-1] * len(seq)
5        for i, c in enumerate(seq):
6            if c == '(':
7                currdepth += 1
8                answer[i] = currdepth % 2
9            if c == ')':
10                answer[i] = currdepth % 2
11                currdepth -= 1
12        return answer
13           