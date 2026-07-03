# Last updated: 7/2/2026, 11:17:48 PM
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        mysol = Solution()
        answer =[]
        candidates.sort()
        mysol.backtrack(candidates, target, [], 0, 0, answer)
        return answer
        

    def backtrack(self, candidates, target, current, currsum, index, answer):
        
        # combination found; add to answer
        if (target == currsum):
            answer.append(current[:])
            return
            #reached the end of the candidates array without having a target
        if (index == len(candidates)):
            return
        #must undo because sum is going over target
        if (target < currsum):
            return

        

        currsum += candidates[index]
        current.append(candidates[index])
        self.backtrack(candidates, target, current, currsum, index+1, answer)
        currsum -= candidates[index]
        current.pop()

        #skip branch
    
        while(index < len(candidates) - 1 and candidates[index+1] == candidates[index]):
            index +=1


          
        
        self.backtrack(candidates, target, current, currsum, index +1, answer)


