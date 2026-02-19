# Last updated: 2/19/2026, 1:35:09 PM
class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        zero = 0 
        nonzero = 0 

        while nonzero < len(nums):
            if nums[nonzero] != 0:
              
                nums[zero], nums[nonzero] = nums[nonzero], nums[zero]
                zero += 1  
            nonzero += 1  
        
        return nums  