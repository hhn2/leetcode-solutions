# Last updated: 5/29/2026, 2:42:18 AM
1class Solution:
2    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
3        intervals.sort(key=lambda x: x[0])
4        answer = []
5        recent = 0
6        for interval in intervals:
7            if not answer or interval[0] > answer[-1][1]:
8                answer.append(interval)
9            else:
10
11                answer[-1][1] = max(answer[-1][1], interval[1])
12
13        return answer