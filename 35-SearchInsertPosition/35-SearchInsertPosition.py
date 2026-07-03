# Last updated: 7/2/2026, 11:17:50 PM
class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        left, right = 0, len(nums)-1

        while left <= right:
            mid = (left + right) /2

            if target == nums[mid]:
                return mid

            elif target > nums[mid]:
                left = mid + 1

            else:
                right = mid - 1
            
        return left