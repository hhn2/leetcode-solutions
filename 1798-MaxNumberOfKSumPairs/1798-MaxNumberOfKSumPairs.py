# Last updated: 2/19/2026, 1:34:41 PM
class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        numsSorted = nums.sort()
        left = 0
        right = len(nums) - 1
        count = 0
        while left < right:
            if nums[left] + nums[right] == k:
                count += 1
                left += 1
                right -= 1
            elif nums[left] + nums[right] > k:
                right -= 1
            elif nums[left] + nums[right] < k:
                left += 1

        return count