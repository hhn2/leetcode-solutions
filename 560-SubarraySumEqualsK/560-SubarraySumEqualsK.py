# Last updated: 10/18/2026, 1:57:40 PM
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        numofsa = 0
        prefixsums={}
        prefixsums[0] = 1
        sumsofar = 0
        for i in range(0, len(nums)):
            sumsofar += nums[i] 
            target = sumsofar - k
            if target in prefixsums:
                numofsa += prefixsums[target]
            if sumsofar in prefixsums:
                prefixsums[sumsofar] += 1

            else:
                prefixsums[sumsofar] = 1
        
    
           
        return numofsa

