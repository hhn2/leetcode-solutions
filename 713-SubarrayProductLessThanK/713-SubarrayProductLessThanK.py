# Last updated: 11/15/2026, 7:44:04 PM
class Solution:
    def numSubarrayProductLessThanK(self, nums: list[int], k: int) -> int:
        if k <= 1:
            return 0
        l, r = 0, 0
        currp = nums[0]
        total = 0
        if nums[0] < k:
            total += 1

        while r != len(nums) - 1:
            r += 1
            currp *= nums[r]
            while currp >= k:
                currp //= nums[l]
                l += 1
                
            total += r - l + 1
        
        return total


