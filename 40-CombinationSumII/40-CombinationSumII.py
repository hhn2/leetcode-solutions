# Last updated: 5/28/2026, 4:09:15 PM
1class Solution:
2    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
3        mysol = Solution()
4        answer =[]
5        candidates.sort()
6        mysol.backtrack(candidates, target, [], 0, 0, answer)
7        return answer
8        
9
10    def backtrack(self, candidates, target, current, currsum, index, answer):
11        
12        # combination found; add to answer
13        if (target == currsum):
14            answer.append(current[:])
15            return
16            #reached the end of the candidates array without having a target
17        if (index == len(candidates)):
18            return
19        #must undo because sum is going over target
20        if (target < currsum):
21            return
22
23        
24
25        currsum += candidates[index]
26        current.append(candidates[index])
27        self.backtrack(candidates, target, current, currsum, index+1, answer)
28        currsum -= candidates[index]
29        current.pop()
30
31        #skip branch
32    
33        while(index < len(candidates) - 1 and candidates[index+1] == candidates[index]):
34            index +=1
35
36
37          
38        
39        self.backtrack(candidates, target, current, currsum, index +1, answer)
40
41
42