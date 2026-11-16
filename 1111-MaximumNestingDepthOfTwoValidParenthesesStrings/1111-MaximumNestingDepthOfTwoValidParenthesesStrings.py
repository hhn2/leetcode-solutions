# Last updated: 11/15/2026, 7:43:52 PM
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> list[int]:
        currdepth = 0
        answer = [-1] * len(seq)
        for i, c in enumerate(seq):
            if c == '(':
                currdepth += 1
                answer[i] = currdepth % 2
            if c == ')':
                answer[i] = currdepth % 2
                currdepth -= 1
        return answer
           