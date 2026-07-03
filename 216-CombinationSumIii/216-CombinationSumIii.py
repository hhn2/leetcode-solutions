# Last updated: 7/2/2026, 11:16:37 PM
class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        mySol = Solution()
        answer = []
        mySol.backtrack([], 0, answer, 1, k, n)
        return answer

    def backtrack(self, current, currsum, answer, index, k, n):
        if currsum == n and len(current) == k:
            answer.append(current[:]) # need to fix this
            return
        
        if len(current) > k:
            return

        if index == 10:
            return

        currsum += index
        current.append(index)
        self.backtrack(current, currsum, answer, index + 1, k, n)
        currsum -= index
        current.pop()

        
        self.backtrack(current, currsum, answer, index + 1, k, n)
       


