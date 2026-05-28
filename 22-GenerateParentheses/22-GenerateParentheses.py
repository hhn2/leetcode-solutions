# Last updated: 5/28/2026, 2:38:40 PM
1class Solution:
2    def backtrack(self, current, balance, leftrem, rightrem, answer):
3        if(balance < 0):
4            return
5
6        if(balance == 0 and leftrem == 0 and rightrem == 0 ):
7            answer.append("".join(current))
8            return
9        
10        
11        if leftrem != 0:
12            current.append('(')
13            self.backtrack(current, balance +1, leftrem - 1, rightrem, answer)
14            current.pop()
15        if rightrem != 0:
16            current.append(')')
17            self.backtrack(current, balance -1, leftrem, rightrem -1, answer)
18            current.pop()
19    def generateParenthesis(self, n: int) -> List[str]:
20        #at each step we can either 
21        #add left parenthesis
22        #add right parenthesis
23        answer = []
24        mySol = Solution()
25        mySol.backtrack([], 0, n, n, answer)
26        return answer
27
28
29 
30        