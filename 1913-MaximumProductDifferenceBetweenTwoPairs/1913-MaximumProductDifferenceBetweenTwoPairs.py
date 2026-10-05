# Last updated: 10/4/2026, 10:51:31 PM
class Solution(object):
    def maxProductDifference(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        max1 = nums.pop(nums.index(max(nums)))
        max2 = nums.pop(nums.index(max(nums)))

        min1 = nums.pop(nums.index(min(nums)))
        min2 = nums.pop(nums.index(min(nums)))

        return ((max1 * max2) - (min1 * min2))