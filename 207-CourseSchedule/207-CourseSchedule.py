# Last updated: 6/2/2026, 6:38:43 PM
1class Solution:
2    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
3        graph = {}
4        for course, prereq in prerequisites:
5            if prereq in graph:
6                graph[prereq].append(course)
7
8            else:
9                graph[prereq] = [course]
10
11        status = [0] * numCourses
12        #0 is unvisited, 1 is visiting, 2 is done visiting
13
14        def dfs(course):
15            if status[course] == 2:
16                return False
17            if status[course] == 1:
18                return True
19            
20            status[course] = 1
21
22            for neighbor in graph.get(course, []):
23                if dfs(neighbor):
24                    return True
25            
26
27
28            status[course] = 2
29            return False
30
31        for i in range(numCourses):
32            if status[i] == 0:
33                if dfs(i): 
34                    return False
35                    
36        return True
37            
38
39        