# Last updated: 2/19/2026, 1:34:46 PM
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        ## Recursion base conditions
        if not stones:
            return 0
        elif len(stones) == 1:
            return stones[0]


        yindex = stones.index(max(stones))
    
        yvalue = stones.pop(yindex)

        xindex = stones.index(max(stones))

        xvalue = stones.pop(xindex)

        if xvalue != yvalue:
            stones.append(yvalue - xvalue)

        return self.lastStoneWeight(stones)
        