class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        
        max_all = float('-inf')
        max_local = 0

        for i in range(len(nums)):
            max_local += nums[i]
            if max_local > max_all:
                max_all = max_local 
             # if there is a subarray with a negative sum, set the max_local to zero 
            if max_local < 0:
                max_local = 0
        return max_all


       