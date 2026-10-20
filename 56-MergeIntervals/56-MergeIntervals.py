# Last updated: 10/20/2026, 6:57:09 PM
1class Solution:
2    def merge(self, intervals: list[list[int]]) -> list[list[int]]:
3        intervals.sort()
4        prevstart = intervals[0][0]
5        prevend = intervals[0][1]
6        answer = []
7        for i in range(1, len(intervals)):
8            if intervals[i][0] <= prevend:
9               if intervals[i][1] > prevend:
10                prevend = intervals[i][1]
11                continue
12            else:
13                answer.append([prevstart, prevend])
14                prevstart = intervals[i][0]
15                prevend = intervals[i][1]
16        if not answer or(answer[-1][0] != prevstart):
17            answer.append([prevstart,prevend])
18        return answer
19             
20                
21